
package cetus.analysis;
import cetus.hir.*;
import cetus.transforms.LoopNormalization;
import cetus.transforms.TransformPass;

import java.util.*;


public class SubscriptedSubscriptAnalysis extends AnalysisPass{

    private static final String tag = "[SubscriptedSubscriptAnalysis]";

    private static RangeExpression increment_expression = null;

    private static Expression Class3_PNN_term = null;

    private static Set<Symbol> Killed_symbols = new HashSet<>();

    private static Map<String, RangeDomain> Loop_agg_ranges = new HashMap<>();

    private static Map<Symbol, String> variable_property = new LinkedHashMap<>();

    private static Map<Symbol,Expression> Loop_agg_subscripts = new HashMap<>();

    public SubscriptedSubscriptAnalysis(Program program){
        super(program);
    }

    @Override
    public String getPassName() {
        return tag;
    }

    public void start() {

        LoopTools.addLoopName(program);
        DFIterator<Procedure> iter =
                new DFIterator<Procedure>(program, Procedure.class);
        iter.pruneOn(Procedure.class);
        iter.pruneOn(Declaration.class);
        while (iter.hasNext()) {
            Procedure procedure = iter.next();

            CFGraph ProcedureGraph = new CFGraph(procedure);

            wrapper(ProcedureGraph);

           
        }
    
    }


    /**
     * Following routine is the Driver algorithm for Subscripted Subscript Analysis
     * 1. It takes as input the control flow graph of the procedure and traverses it.
     * 2. As soon as a Loop statement is encountered, Phase 1 is triggered
     * 3. The modified ranges are stored in the range dictionaries corresponding to each 
     *    statement or node in the control flow graph.   
     * @param - Control Flow Graph of the subroutine
    */

private static void wrapper(CFGraph SubroutineGraph){

    SubroutineGraph.normalize();
    SubroutineGraph.topologicalSort(SubroutineGraph.getNodeWith("stmt", "ENTRY"));
    Map<String, RangeDomain> RangeValuesBeforeCurrentLoop = new HashMap<String, RangeDomain>();
    Integer visits = 0;
    
    ForLoop outermost_for_loop = null;
    RangeDomain aggregated_ranges = null;
  
    TreeMap<Integer, DFANode> work_list = new TreeMap<Integer, DFANode> ();

    DFANode entry = SubroutineGraph.getNodeWith("stmt", "ENTRY");
            if (entry.getData("ranges") == null)
                entry.putData("ranges", new RangeDomain());
            work_list.put((Integer) entry.getData("top-order"), entry);

    //Traverse the CFG successor by successor
    
    while(work_list.size() > 0){


         // Get the first node in topological order from the work list.
        Integer node_num = work_list.firstKey();
        DFANode node = work_list.remove(node_num);
         visits = node.getData("num-visits");     
        if (visits == null) {
            node.putData("num-visits", 1);
           
        } else {
            node.putData("num-visits", visits + 1);
        }

        if((Integer)node.getData("num-visits") > 1){

            node.putData("ranges", null);

            for(DFANode predecessor : node.getPreds()){

                if(predecessor.getData("symbol-exit") != null )
                    node.putData("ranges", predecessor.getData("ranges"));

            }
         
            for(DFANode successor : node.getSuccs()){
                
                if(successor.getData("num-visits") == null){
                    successor.putPredData(node, node.getData("ranges"));
                    work_list.put((Integer)successor.getData("top-order"), successor);
                    
                }
                
            }
            continue;

        }

    
        // Merge incoming states from predecessors.
        RangeDomain curr_ranges = null;
        for (DFANode pred : node.getPreds()) {
            RangeDomain pred_range_out = node.getPredData(pred);
            // Skip BOT-state predecessors that has not been visited.
                    
            if (pred_range_out == null) {
                continue;
            }
            if (curr_ranges == null) {
                curr_ranges = new RangeDomain(pred_range_out);
               
            } else {        
                curr_ranges.unionRanges(pred_range_out);
    
            }

        }

        
        /**
         * If a For loop is encountered, store the range values of variables before the loop,
         * initialize LVVs to lambda at the loop header node and then analyze the loop body.
         */

          
           if(node.getData("stmt") instanceof ForLoop){

                outermost_for_loop = (ForLoop)node.getData("stmt");

                //Perform the analysis for loops that do not contain subscripted susbcript pattern and
                //loops that do not contain any function calls
        
                    //Store the range dictionary of the node immediately before the loop header
                    RangeValuesBeforeCurrentLoop.put(LoopTools.getLoopName(outermost_for_loop), new RangeDomain(curr_ranges));
                    
                    DFIterator<ForLoop> forLoopIter = new DFIterator(outermost_for_loop, ForLoop.class);
                    LinkedList<Loop>Loops_in_Nest =  new LinkedList();

                
                    while(forLoopIter.hasNext()){

                        Loops_in_Nest.addFirst(forLoopIter.next());
                    }
            
                    for(int i = 0 ; i < Loops_in_Nest.size(); i++){

                        ForLoop innerloop = (ForLoop)Loops_in_Nest.get(i);
                    
                        CFGraph LoopControlFlowGraph = new CFGraph(innerloop);
                        LoopControlFlowGraph.normalize();

                        if(i > 0){
                            DFANode Collapsed_innerloopNode = CollapseLoopinCFG(LoopControlFlowGraph, (ForLoop)Loops_in_Nest.get(i-1), null);
                            //System.out.println("collap node: " + Collapsed_innerloopNode.getData("tag") + " , range: " + Collapsed_innerloopNode.getData("ranges") +"\n");
                        }

                        //System.out.println("=======================================================================\n");
                        //Phase 1 Called
                        SubSubAnalysis(innerloop, LoopControlFlowGraph ,
                                                    RangeValuesBeforeCurrentLoop.get(LoopTools.getLoopName(outermost_for_loop)));



                    }

                    node = CollapseLoopinCFG(SubroutineGraph, outermost_for_loop, node);
                
            
            }

    
        // Add initial values from declarations
        RangeAnalysis.enterScope(node, curr_ranges);
       
        RangeDomain prev_ranges = node.getData("ranges");

        // Detected changes trigger propagation
        if (prev_ranges == null || !prev_ranges.equals(curr_ranges)) {
    
            if (node != SubroutineGraph.getEntry()) {
                // Keep the IPA result for the entry node.
                node.putData("ranges", curr_ranges);
            }
   
            if(prev_ranges != null && !prev_ranges.equals(curr_ranges)){
               
                node.putData("ranges", prev_ranges);
 
             }
            RangeAnalysis.updateRanges(node);

            RangeAnalysis.exitScope(node);
    
            for (DFANode succ : node.getSuccs()) {
                // Do not add successors for infeasible paths
                
                if (succ.getPredData(node) != null) {
                   
                    work_list.put((Integer)succ.getData("top-order"), succ);
                
                }
            }  

        }

        if(node.getData("tag") != null && node.getData("tag").equals("FOREXIT")){
       
             node.putData("ranges", aggregated_ranges);
            //Update successors or ranges associated with the outgoing control flow edges
            for(DFANode successor : node.getSuccs()){

                successor.putPredData(node, node.getData("ranges"));

            }
           
        
        }

        // if(node.getData("ir") != null)
        // System.out.println("node: " + node.getData("ir") +" , range: " + node.getData("ranges") +"\n");
        // else
        // System.out.println("node: " + node.getData("tag") +" , range: " + node.getData("ranges") +"\n");
       

    }

    
}


    /**
     * Collapses a loop in the CFG. Collapsing refers to removing the nodes corresponding to the loop from the
     * input CFG. Outermost loops in a loop nest are collapsed w.r.t the subroutine flow graph. After collapsing, 
     * the loop nodes are replaced with a node with tag = The pragma loop name (unique annotation) and ranges equal 
     * to the aggregated loop ranges after subscripted subscript analysis.
     * @param input_CFG        - The input control flow graph
     * @param loop_to_collapse - The loop object that is to be collapsed
     * @param OutermostLoopNode - Node corresponding to the outermost loop in a nest
     * @return   - The collapsed node
     */
    private static DFANode CollapseLoopinCFG(CFGraph input_CFG, ForLoop loop_to_collapse, DFANode OutermostLoopNode){

        TreeMap<Integer, DFANode> nodes_list = new TreeMap<Integer, DFANode>();
    
        input_CFG.topologicalSort(input_CFG.getNodeWith("stmt", "ENTRY"));

        DFANode entry = input_CFG.getNodeWith("stmt", "ENTRY");
       

        if(OutermostLoopNode != null){
            nodes_list.put((Integer)OutermostLoopNode.getData("top-order"), OutermostLoopNode);
        }
        else
            nodes_list.put((Integer) entry.getData("top-order"), entry);
            

        List<DFANode> Nodes_to_Remove = new ArrayList<>();
        Set<DFANode> innerLoopPreds = null;
        Set<DFANode> innerLoopSuccs = null;
        Annotation innerloopannotation = null;

        Integer LoopNestDepth = LoopTools.calculateInnerLoopNest(loop_to_collapse).size();
        Integer NumberForExits = 0;
        
        //Traverse the CFG successor by successor and remove the nodes of the inner loop
        
        while(nodes_list.size() > 0){
    

            // Get the first node in topological order from the work list.
            Integer node_num = nodes_list.firstKey();
            DFANode node = nodes_list.remove(node_num);

            Integer visits = node.getData("num-visits"); 
            
            if (visits == null) {
                node.putData("num-visits", 1);
                
            } else {
                node.putData("num-visits", visits + 1);
            }

            if(node.getData("stmt") instanceof ForLoop){

                ForLoop innerloop = (ForLoop)node.getData("stmt");

                if(innerloop.equals(loop_to_collapse)){
                   
                    innerloopannotation = innerloop.getAnnotation(PragmaAnnotation.class, "name");
                    innerLoopPreds = node.getPreds();
                    Nodes_to_Remove.add(node);
                }
                
                
            }

            if(!Nodes_to_Remove.isEmpty() && !Nodes_to_Remove.contains(node)){
                Nodes_to_Remove.add(node);

            }

            if(node.getData("tag")!= null && node.getData("tag").equals("FOREXIT")){
                NumberForExits++;
                Nodes_to_Remove.add(node);

                if(NumberForExits == LoopNestDepth){
                    innerLoopSuccs = node.getSuccs();
                    break;
                }
            }
        

            if((Integer)node.getData("num-visits") > 1){            
                
                for(DFANode successor : node.getSuccs()){
                    
                    if(successor.getData("num-visits") == null){
                        successor.putPredData(node, node.getData("ranges"));
                        nodes_list.put((Integer)successor.getData("top-order"), successor);
                        
                    }
                    
                }
                continue;

            }
        
        
                for (DFANode succ : node.getSuccs()) {
                    
                    nodes_list.put((Integer)succ.getData("top-order"), succ);
                        
                }
                
            }


            input_CFG.removeNodes(Nodes_to_Remove);

            DFANode collap_node = new DFANode("tag", innerloopannotation);
            RangeDomain innerloop_aggRanges = Loop_agg_ranges.get(innerloopannotation.toString());
            collap_node.putData("ranges", innerloop_aggRanges);
            input_CFG.addNode(collap_node);
        
            for(DFANode pred: innerLoopPreds){
                input_CFG.addEdge(pred, collap_node);
                pred.putSuccData(collap_node, new RangeDomain());
                pred.putData("true", collap_node);
        
            }
        
            for(DFANode succ: innerLoopSuccs){
                input_CFG.addEdge(collap_node, succ);
                collap_node.putData("true", succ);
                //System.out.println("collap node: " + collap_node.getData("tag") +" , succ: " + succ.getData("ir") +"\n");
                succ.putPredData(collap_node, collap_node.getData("ranges"));
            }
            
            if(OutermostLoopNode == null){
                for(int j = 0; j < input_CFG.size(); j++){
                        
                    input_CFG.getNode(j).putData("num-visits", null);
                }
            }
        
            return collap_node;

    }

/**
 * Subscripted subscript analysis begins.
 * @param input_for_loop - The For loop to be analyzed
 * @param RangesBeforeLoop - Range values immediately before the loop
 * @return - The aggregated range expressions
 */


private static void SubSubAnalysis(ForLoop input_for_loop, CFGraph Loop_CFG, RangeDomain Prior_Ranges){


    Integer visits = 0;

    Map<Symbol, Expression> ArraySubscriptMap = new HashMap<Symbol,Expression>();
    Set<Symbol> LoopLVVs = null;
    Set<Symbol> Initial_syms = null;

    String LoopName = LoopTools.getLoopName(input_for_loop);
   
    TreeMap<Integer, DFANode> work_list = new TreeMap<Integer, DFANode>();
    
        Loop_CFG.topologicalSort(Loop_CFG.getNodeWith("stmt", "ENTRY"));

        DFANode entry = Loop_CFG.getNodeWith("stmt", "ENTRY");
        if (entry.getData("ranges") == null)
            entry.putData("ranges", Prior_Ranges);
        
        work_list.put((Integer) entry.getData("top-order"), entry);

        //Traverse the CFG successor by successor
        
    while(work_list.size() > 0){
        

            // Get the first node in topological order from the work list.
        Integer node_num = work_list.firstKey();
        DFANode node = work_list.remove(node_num);

        visits = node.getData("num-visits");     
        if (visits == null) {
            node.putData("num-visits", 1);
            
        } else {
            node.putData("num-visits", visits + 1);
        }


        if((Integer)node.getData("num-visits") > 1){

            node.putData("ranges", null);

            for(DFANode predecessor : node.getPreds()){

                if(predecessor.getData("symbol-exit") != null )
                    node.putData("ranges", predecessor.getData("ranges"));

            }

            
            for(DFANode successor : node.getSuccs()){
                
                if(successor.getData("num-visits") == null){
                    successor.putPredData(node, node.getData("ranges"));
                    work_list.put((Integer)successor.getData("top-order"), successor);
                    
                }
                
            }
            continue;

        }
    
        // Merge incoming states from predecessors.

        RangeDomain curr_ranges = null;
        for (DFANode pred : node.getPreds()) {
            RangeDomain pred_range_out = node.getPredData(pred);
            // Skip BOT-state predecessors that has not been visited.
           
            if (pred_range_out == null) {
                continue;
            }
            if (curr_ranges == null) {
                curr_ranges = new RangeDomain(pred_range_out);
                
            } else {        

                curr_ranges.unionRanges(pred_range_out);
    
            }

        }

        if(node.getData("ir") != null && 
                        node.getData("ir").toString().equals(input_for_loop.getCondition().toString() + ";") ){

            LoopLVVs = node.getData("loop-variants");               
        
                for(Symbol LVV : LoopLVVs){
                    //if an LVV is present in the range dictionary of the loop header node, initialize it to lambda     
                    VariableDeclarator vd = (VariableDeclarator)LVV;
                    IDExpression LVVexpr = vd.getID();       
                    curr_ranges.setRange(LVV, LVVexpr);
                
                }

            Initial_syms = curr_ranges.getSymbols();
        }
        
        // Add initial values from declarations
        RangeAnalysis.enterScope(node, curr_ranges);
        
        RangeDomain prev_ranges = node.getData("ranges");

        // Detected changes trigger propagation
        if (prev_ranges == null || !prev_ranges.equals(curr_ranges)) {
        
            if (node != Loop_CFG.getEntry()) {
                // Keep the IPA result for the entry node.
                node.putData("ranges", curr_ranges);
            }

            if( curr_ranges != null && prev_ranges != null && !prev_ranges.equals(curr_ranges)){

               curr_ranges.kill(Killed_symbols);
                
                for(Symbol sym : curr_ranges.getSymbols()){
                    Expression exp = prev_ranges.getRange(sym);
                    if(exp != null)
                    curr_ranges.setRange(sym, exp);

                }
                
                node.putData("ranges", curr_ranges);

            }

            Expression LHS = ArrayWriteAccess(node, Loop_CFG);
                //Adding the array alongwith its subscript to the appropriate map
                if(LHS !=null ){  
                    ArrayAccess LHS_array = (ArrayAccess)LHS;
                    ArraySubscriptMap.put( SymbolTools.getSymbolOf(LHS_array.getArrayName()), LHS_array.getIndices().get(0));
                }

            // Apply state changes due to the execution of the node.


            RangeAnalysis.updateRanges(node);

            RangeAnalysis.exitScope(node);
  
    
            for (DFANode succ : node.getSuccs()) {
                        
                // Do not add successors for infeasible paths
                if (succ.getPredData(node) != null) {
                    RangeDomain SuccRange =  succ.getPredData(node);
                    //Remove entry for Loop index in the range dictionaries of successors
                    //Loop index is a special case and will be considered separately.
                    SuccRange.removeRange(LoopTools.getLoopIndexSymbol(input_for_loop));
                    work_list.put((Integer)succ.getData("top-order"), succ);
                
                }
            }

        }

            //Phase 2 triggered after the final node in the loop is reached
            if(node.getData("tag") != null && node.getData("tag").equals("FOREXIT")){

                node.putData("array-subscripts", ArraySubscriptMap);
              
                RangeDomain Phase1Exprs = node.getData("ranges");
                Set<Symbol> Final_symbols = Phase1Exprs.getSymbols();
                Killed_symbols = symmetricDifference(Initial_syms, Final_symbols);

               // System.out.println("Subscripted-subscript analysis for Loop: " + LoopName + "\n" );  
                SubSubPhasetwo(node.getData("ranges") , LoopLVVs , input_for_loop , 
                                      Prior_Ranges , node.getData("array-subscripts"));                
                
                Annotation loop_ant = input_for_loop.getAnnotation(PragmaAnnotation.class, "name");
                
                //Collecting the aggregation information corresponding to each loop
                Loop_agg_ranges.put(loop_ant.toString(), node.getData("ranges"));

                //Update successors or ranges associated with the outgoing control flow edges
                for(DFANode successor : node.getSuccs()){

                    successor.putPredData(node, node.getData("ranges"));

                }

            }

       
        // if(node.getData("ir") != null)
        // System.out.println(" node: " + node.getData("ir") +" , range: " + node.getData("ranges") +"\n");
        // else
        // System.out.println(" node: " + node.getData("tag") +" , range: " + node.getData("ranges") +"\n");
   
        }

        
   
    }
    
    /**
     * Subscripted subscript analysis - Phase 2 begins
     * 1. In Phase 2, the range values from Phase 1 are analyzed and the relevant 
          properties are determined.
     * 2. The Loop index variable is treated as a special SSR or Class 1 variable with it's 
          property being strict monotonicity since the loops are normalized.
     * 3. For now we have two Maps - Mapping of the symbol to its aggregated range and
     *    Mapping of the symbol to a relevant property.
     * @param LoopRangeExpressions - The Phase 1 range expressions
     * @param LoopVariantVars      - The list of Loop variant variables
     * @param input_for_loop              - The loop being analyzed
     * @param RangeValsBeforeLoop  - Range dictionary of the statement immediately prior to the loop
     * @param ArraySubscripts      - Mappings of arrays to their subscript expressions
     * Note: This function might need to return a range dictionary
     */
    

    private static void SubSubPhasetwo(RangeDomain LoopRangeExpressions , Set<Symbol> LoopVariantVars, ForLoop input_for_loop,
                                            RangeDomain RangeValsBeforeLoop, Map<Symbol,Expression>ArraySubscripts)
    {

        Expression aggregate_lb = null;
        Expression aggregate_ub = null;
        Expression re = null;
        List<Symbol> SSR_variables = new ArrayList<Symbol>();
        Expression LoopIdx = LoopTools.getIndexVariable(input_for_loop);
        RangeExpression LoopIdxRange = getLoopIndexRange(input_for_loop, RangeValsBeforeLoop);

        Expression LoopIterationCount = Symbolic.add(Symbolic.subtract(LoopIdxRange.getUB() , LoopIdxRange.getLB()), new IntegerLiteral(1));
        Expression ValueBeforeLoop = null;

        
        Symbol LoopIndexSymbol = SymbolTools.getSymbolOf(LoopIdx);

        if(!LoopTools.isOutermostLoop(input_for_loop)){

            Expression LoopUBVal = RangeValsBeforeLoop.getRange(LoopIndexSymbol);
            LoopRangeExpressions.setRange(LoopIndexSymbol, LoopUBVal);

            RangeValsBeforeLoop = null;

        }
        

        // System.out.println("Phase 2 Analysis:\n");

        //Collect info about the loop index symbol - aggregate range and property
        LoopIdxRange = (RangeExpression)LoopRangeExpressions.substituteForwardRange(LoopIdxRange);
        LoopRangeExpressions.setRange(LoopIndexSymbol, LoopIdxRange);
        SSR_variables.add(LoopIndexSymbol);

        // System.out.println("LVV: " + LoopIndexSymbol + "(loop index) \nAggregate range: " + LoopRangeExpressions.getRange(LoopIndexSymbol) + 
        //                                                 "\nproperty: " + variable_property.get(LoopIndexSymbol) +"\n");
        

               for(Symbol sym : LoopRangeExpressions.getSymbols()){
                   if(sym.equals(LoopIndexSymbol))
                        continue;

                    if(LoopVariantVars.contains(sym)){
    
                        //Check if the symbol is the loop index variable
                       
                        Expression LVV_Value_expr = LoopRangeExpressions.getRange(sym);

                        if(LVV_Value_expr.equals(new StringLiteral("bot")))
                          continue;

                        //Identifying the recurrence class of the LVV
                      
                        String recurrence_class = identify_recurrence_class(sym, LVV_Value_expr , LoopIdx, 
                                                                                ArraySubscripts, SSR_variables,RangeValsBeforeLoop);

                        switch(recurrence_class){
                            case "Class 1":
                                SSR_variables.add(sym);
                                variable_property.put(sym, "MONOTONIC");
            
                                //increment expression has been determined in identify_recurrence_class()
                                aggregate_lb = Symbolic.multiply(increment_expression.getLB(), LoopIterationCount);
                                aggregate_ub = Symbolic.multiply(increment_expression.getUB(), LoopIterationCount);

                                //if the loop is outermost loop, add the value before the loop for scalars
                                if(LoopTools.isOutermostLoop(input_for_loop)){
                                    ValueBeforeLoop = RangeValsBeforeLoop.getRange(sym);
                                    aggregate_lb = Symbolic.add(aggregate_lb, ValueBeforeLoop);
                                    aggregate_ub = Symbolic.add(aggregate_ub , ValueBeforeLoop);
                                    //re = LoopRangeExpressions.substituteForwardRange(re);
                                }
                                else{
                                    RangeExpression range = (RangeExpression)LVV_Value_expr;
                                    aggregate_lb = Symbolic.add( aggregate_lb, range.getLB());
                                    aggregate_ub = Symbolic.add(aggregate_ub , range.getLB());

                                }

                                    re = new RangeExpression(aggregate_lb, aggregate_ub);
                                   
                                    LoopRangeExpressions.setRange(sym, re);
                                                                  
                                
                            break;
                            case "Class 2":
                                Symbol SSR_Var = SymbolTools.getSymbolOf(Find_SSR_Var(LVV_Value_expr, SSR_variables));
                                //check the property of the SSR variable
                                if(variable_property.get(SSR_Var).equals("STRICT_MONOTONIC"))
                                    variable_property.put(sym, "STRICT_MONOTONIC");
                                else
                                    variable_property.put(sym, "MONOTONIC");
                                 
                                //Subsitute the range expression of all variables in RHS and simplify
                                re = (RangeExpression)LoopRangeExpressions.substituteForwardRange(LVV_Value_expr);
                                if(LoopTools.isOutermostLoop(input_for_loop)){
                                    LoopRangeExpressions.setRange(sym, re);
                                }
                            break;
                            case "Class 3":
                                //Evaluate the PNN term
                               String property = eval_PNN(Class3_PNN_term);
                               variable_property.put(sym, property);
                               Expression infinite = new InfExpression(1);
                               //Conservative estimation of the aggregate value expressions
                               LoopRangeExpressions.setRange(sym, new RangeExpression(new IntegerLiteral(0), infinite));
                            break;
                            case "Unknown Class":
                            //If none of the classes are recognized and the value expression is not constant, the aggregated value is unknown
                               if(!is_constant(LVV_Value_expr))
                                    LoopRangeExpressions.setRange(sym, new StringLiteral("bot"));
                            break;
                            
                               
                        }

                        //For an array, aggregate the subscript expression if it's a simple subscript
                        if(!sym.getArraySpecifiers().isEmpty()){

                            Expression array_subscript = ArraySubscripts.get(sym);

                            RangeExpression agg_subscript = null;
                            if(is_simple_subscript(array_subscript,LoopIdx)){
                                agg_subscript =  (RangeExpression)LoopRangeExpressions.substituteForwardRange(array_subscript);
                                Loop_agg_subscripts.put(sym, agg_subscript);
                            }
     
                            // System.out.println("LVV: " + sym + "\nclass: " + recurrence_class  + "\nAggregate subscript: " + ArraySubscripts.get(sym) +
                            //                         "\nAggregate value range: " + LoopRangeExpressions.getRange(sym) + "\nproperty: " + variable_property.get(sym) +"\n");

                        }
                        // else
                        //     System.out.println("LVV: " + sym  +"\nclass: " + recurrence_class + 
                        //                             "\nAggregate value range: " + LoopRangeExpressions.getRange(sym) + "\nproperty: " + variable_property.get(sym) +"\n");

                        
                    }

               }
        
               LoopRangeExpressions.removeRange(LoopIndexSymbol);
          
        }
    

        /**
         * Determining the Recurrence class of the LVV.
         * 1. There are 3 recurrence classes that need to be identified:
         *    (a) Simple Scalar Recurrence (Class 1)
         *    (b) Scalar Recurrence Array Assignment (Class 2)
         *    (c) Array Recurrence (Class 3)
         *    (From the paper - "From the ICS paper - On the automatic parallelization of subscripted
         *                         subscript patterns using array property analysis")
         * @param LVV       - The input LVV
         * @param ValueExpr - Phase 1 range expression of the LVV
         * @param LoopIndex - The loop index variable
         * @param ArraySubscriptExprs - Mapping of arrays to their respective subscript expressions
         * @param List_SSR_Vars - List of SSR variables
         * @return          - The recurrence class
         * TODO : Support for array subscripts with loop invariant subscript expressions
         */
    
    private static String identify_recurrence_class(Symbol LVV, Expression ValueExpr, Expression LoopIndex,
                                                     Map<Symbol,Expression>ArraySubscriptExprs ,List<Symbol>List_SSR_Vars, RangeDomain RangesBeforeLoop)
    {

        
       //Check if the LVV is a scalar or an array. 
       //Scalars can have only Class 1 recurrence
        if(LVV.getArraySpecifiers().isEmpty()){

            VariableDeclarator vd = (VariableDeclarator)LVV;
            IDExpression idexpr = vd.getID();
            RangeExpression re = (RangeExpression)ValueExpr;
            Expression inc_expr_lb = Symbolic.subtract(re.getLB(), idexpr);
            Expression inc_expr_ub = Symbolic.subtract(re.getUB() , idexpr);
            increment_expression = new RangeExpression(inc_expr_lb, inc_expr_ub);
            //Check if the increment expression is Positive or Non-negative
           
            if(is_PNN(increment_expression))
                    return "Class 1";
            
            return "Unknown Class";
            
        }
        else{

            Expression SubscriptExp = ArraySubscriptExprs.get(LVV);
        
            Expression SSR_var = Find_SSR_Var(ValueExpr,  List_SSR_Vars);
            
            //An array can have class 2 recurrence if RHS is an SSR expression


            if( SSR_var != null && is_simple_subscript(SubscriptExp, LoopIndex)){

                Expression remainder = Symbolic.subtract(ValueExpr, SSR_var);

                if(!(remainder instanceof ArrayAccess) && is_PNN(remainder))
                    return "Class 2";
            }
            else if(SubscriptExp != null){
                VariableDeclarator array_vd = (VariableDeclarator)LVV;
                Expression array_idexpr = array_vd.getID().clone();
                IntegerLiteral ONE = new IntegerLiteral(1);
                ArrayAccess LHS_sub_one = new ArrayAccess(array_idexpr, Symbolic.subtract(SubscriptExp, ONE));

                if( ValueExpr.equals(LHS_sub_one) || ValueExpr.getChildren().contains(LHS_sub_one)
                    && is_simple_subscript(ArraySubscriptExprs.get(LVV) , LoopIndex)){
        
                        Expression remainder = Symbolic.subtract(ValueExpr, LHS_sub_one);

                        Expression remainder_range = RangesBeforeLoop.getRange(SymbolTools.getSymbolOf(remainder));

                        if(is_PNN(remainder_range)){
                            Class3_PNN_term = remainder_range;
                            return "Class 3";
                        }
                }

                
            }
            
            return "Unknown Class";

        }


    }

    //Returns the SSR variable in a value expression
    private static Expression Find_SSR_Var(Expression ValueExpression, List<Symbol> SSR_variables){

        DFIterator<Expression> iter = new DFIterator<Expression>(ValueExpression, Expression.class);

        while(iter.hasNext()){
            Expression expr = iter.next();
            if(expr instanceof ArrayAccess){
                break;
            }
            Symbol sym = SymbolTools.getSymbolOf(expr);
            if(SSR_variables.contains(sym))
                return expr;
        }

        return null;

    }

    //Returns the Range expression of the loop index variable of the input 'for' loop.

    private static RangeExpression getLoopIndexRange(ForLoop InputForLoop, RangeDomain ValuesBeforeLoopHeader){


        Expression LoopUpperbound = LoopTools.getUpperBoundExpression(InputForLoop);
        LoopUpperbound.setParent(null);

        Expression LoopLowerbound = LoopTools.getLowerBoundExpression(InputForLoop);
        LoopLowerbound.setParent(null);

        Expression stride = LoopTools.getIncrementExpression(InputForLoop);
        stride.setParent(null);

        if(ValuesBeforeLoopHeader!= null){
            LoopUpperbound = ValuesBeforeLoopHeader.substituteForwardRange(LoopUpperbound);
            LoopLowerbound = ValuesBeforeLoopHeader.substituteForwardRange(LoopLowerbound);
        }
        RangeExpression LoopIndexRange = new RangeExpression(LoopLowerbound,LoopUpperbound, stride);

        return LoopIndexRange;


    }

    
    /**
     * Returns true if a Range Expression is PNN i.e. both lower bound and 
     * upper bound are greater than or equal to zero.
     */
    private static Boolean is_PNN(Expression input_re){
       
        if(input_re instanceof RangeExpression){
            Expression inc_expr_lb = ((RangeExpression)input_re).getLB();
            Expression inc_expr_ub = ((RangeExpression)input_re).getUB();
        
            if(inc_expr_lb instanceof IntegerLiteral && inc_expr_ub instanceof IntegerLiteral){
                if( ((IntegerLiteral)inc_expr_lb).getValue() >= 0 && ((IntegerLiteral)inc_expr_ub).getValue() >= 0 )
                    return true;
            }
            else
                return false;
        }
        
        if(input_re instanceof IntegerLiteral && ((IntegerLiteral)input_re).getValue() >= 0)
            return true;
        
        return false;

    }
    
    /**
     * Returns a property after evaluating a PNN term. Primarily used to
     * evaluate for class 3 recurrences
     * @param epxr - The PNN term
     * @return - A property
     */
    private static String eval_PNN(Expression expr){

        if(expr instanceof RangeExpression){
            RangeExpression range = (RangeExpression)expr;
            Expression lb = range.getLB();
            if(((IntegerLiteral)lb).getValue() > 0)
                return "Strict_Monotonicity";
            else if(((IntegerLiteral)lb).getValue() >= 0)
                return "Monotonicity";
            else
                return null;
            
        }
        else{
            if(((IntegerLiteral)expr).getValue() > 0)
                return "Strict_Monotonicity";
            else if(((IntegerLiteral)expr).getValue() >= 0)
                return "Monotonicity";
            else
                return null;


        }

    }

    /**
     * To check if the value expression for an LVV is a constant expression
     * @param input_re - The input value expression
     * @return         - True if the value is constant, false otherwise
     */

    private static Boolean is_constant(Expression input_re){


        if(input_re instanceof RangeExpression){
            Expression inc_expr_lb = ((RangeExpression)input_re).getLB();
            Expression inc_expr_ub = ((RangeExpression)input_re).getUB();
            if( inc_expr_lb instanceof IntegerLiteral && inc_expr_ub instanceof IntegerLiteral)
                return true;
            else if( inc_expr_lb instanceof FloatLiteral && inc_expr_ub instanceof FloatLiteral)
                return true;
        }
        
        if(input_re instanceof IntegerLiteral)
            return true;
        else if(input_re instanceof FloatLiteral)
            return true;
        
        return false;

    }

    /**
     * Determines if a subscript expression is a simple subscript.
     * Simple subscripts are of the form - "i+k", where "i" is the loop
     * index variable and "k" is a constant.
     * @param SubscriptExpr - The subscript expression to be evaluated
     * @param LoopIndexVar  - Loop index variable
     * @return
     */

    private static boolean is_simple_subscript(Expression SubscriptExpr, Expression LoopIndexVar){

        if(SubscriptExpr == null)
            return false;

        if(SubscriptExpr.getChildren().contains(LoopIndexVar) || 
                                SubscriptExpr.equals(LoopIndexVar)){
            Expression remainder = Symbolic.subtract(SubscriptExpr, LoopIndexVar);

            if(is_constant(remainder))
                return true;
        }
       
       return false;

    }
    

    private static Expression ArrayWriteAccess(DFANode CurrentNode, CFGraph cfg){

        Object o = cfg.getIR(CurrentNode);
        if(o instanceof ExpressionStatement){
            o = ((ExpressionStatement)o).getExpression();
            if(o instanceof AssignmentExpression){
                AssignmentExpression assignment = (AssignmentExpression)o;
                if(assignment.getLHS() instanceof ArrayAccess)
                    return assignment.getLHS();
            }
        }

        return null;
    }

    private static Set<Symbol> symmetricDifference(Set<Symbol> a, Set<Symbol> b) {
        Set<Symbol> result = new HashSet<Symbol>(a);
        for (Symbol element : b) {
            // .add() returns false if element already exists
            if (!result.add(element)) {
                result.remove(element);
            }
        }
        return result;
    }


    public static Map<String, RangeDomain> getAggregateRanges(){
        return Loop_agg_ranges;
    }

    public static Map<Symbol, String> getVariableProperties(){
        return variable_property;
    }

    public static Map<Symbol, Expression> getAggregateSubscripts(){

        return Loop_agg_subscripts;

    }
 

}