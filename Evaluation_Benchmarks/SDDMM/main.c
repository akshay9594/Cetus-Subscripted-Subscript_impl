/* 
 Subscripted subscript example from the Algebraic Multigrid kernel (Amgmk)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <omp.h>
#include <sys/time.h>
#include <math.h>
#include <assert.h>
#include "util.h"

#define N 30000

void sddmm_CPU_CSR(int* row_ptr, int* col_ind, double* nnz_val, double* W,
                     double* H, double* p,int n_rows ,int k, int nonzeros);

void Par_sddmm_CPU_CSR(int* par_row_ptr, int* col_ind, double* nnz_val, double* W,
                     double* H, double* p,int n_rows ,int k, int nonzeros);

int* row_val; 
int* col_val; 
double* nnz_val;

int* row;
//int* rowP;

int convertStrtoArr(char* str)
{
    // get length of string str
    int str_length = strlen(str);
  
    // create an array with size as string
    // length and initialize with 0
    int arr =0;
  
    int j = 0, i, sum = 0;
  
    // Traverse the string
    for (i = 0; str[i] != '\0'; i++) {
  
        // if str[i] is ', ' then split
        if (str[i] == ',')
            continue;
         if (str[i] == ' '){
            // Increment j to point to next
            // array location
            break;
        }
        else {
  
            // subtract str[i] by 48 to convert it to int
            // Generate number by multiplying 10 and adding
            // (int)(str[i])
            arr = arr * 10 + (str[i] - 48);
        }
    }
   
      return arr;
   
  
}

void sddmm_CPU_CSR(int* row_ptr, int* col_ind, double* nnz_val, double* W,
                     double* H, double* p,int n_rows ,int k, int nonzeros){
       // reduction(+:rmse)
    int i,r, ind,t,holder;
    double sm;

     holder =0;
     row_ptr[0]=0;
      for(i =0; i < nonzeros; i++){
        if(row_val[i] != r){
            row_ptr[holder++] = i;
           // rowP[holder] = i;
            r = row_val[i];
        }
    }

    //#pragma omp parallel for private(sm,r,ind,t)
    for (r = 0; r < n_rows; ++r){
        for (ind = row_ptr[r]; ind < row_ptr[r+1]; ++ind){
            sm=0;
            for (t = 0; t < k; ++t){
                sm += W[r * k + t] * H[col_ind[ind] * k + t];
               
            }
            p[ind] = sm * nnz_val[ind];     //Scaling of non-zero elements of the sparse matrix
           
        }                
    } 
}

// void Par_sddmm_CPU_CSR(int* par_row_ptr, int* col_ind, double* nnz_val, double* W,
//                      double* H, double* p,int n_rows ,int k, int nonzeros){
//        // reduction(+:rmse)
//     int i,r, ind,t,holder;
//     double sm;

//      holder =0;
//     par_row_ptr[0]=0;
//       for(i =0; i < nonzeros; i++){
//         if(row_val[i] != r){
//             par_row_ptr[holder++] = i;
//            // rowP[holder] = i;
//             r = row_val[i];
//         }
//     }

//     #pragma omp parallel for private(sm,r,ind,t)
//     for (r = 0; r < n_rows; ++r){
//         for (ind = par_row_ptr[r]; ind < par_row_ptr[r+1]; ++ind){
//             sm=0;
//             for (t = 0; t < k; ++t){
//                 sm += W[r * k + t] * H[col_ind[ind] * k + t];
               
//             }
//             p[ind] = sm * nnz_val[ind];     //Scaling of non-zero elements of the sparse matrix
           
//         }                
//     } 
// }

int main(int argc, char *argv[]){

     if(argc < 2){
   printf("Input missing arguments, you need to specify input list file\n");
  }

 char* file_path = argv[1];
  //std::string inputMatrix;
  int i,j,k, s_factor,holder,count;
  s_factor = 3200;
  count = 0;

    struct timeval start,end;//,startTT, endTT;

    FILE * fp;
    char * line = NULL;
    int num_rows, num_cols, nonzeros, colCnt, nnzCnt;
     int num_runs;
     num_runs = 1;

    size_t len;
    size_t read;

    colCnt=0;
    nnzCnt=0;
    len = 0;

    fp = fopen(file_path, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        if(line[0] == '%'){
            continue;
        }
         else{
            break;
         }
    }

   char delim[] = " ";

	char *ptr = strtok(line, delim);
   char* rowstr = NULL;
   rowstr = (char *)malloc(sizeof(line)); 
   char* temp_str;

   while(ptr != NULL)
	{
      if(count ==0){  
         memcpy(rowstr, ptr, sizeof(ptr));
         num_rows = convertStrtoArr(ptr);
      }
      else if(count == 1){
        num_cols = convertStrtoArr(ptr);
      }
      else if(count == 2){
         nonzeros = convertStrtoArr(ptr);
      }
      count++;
		ptr = strtok(NULL, delim);
	}

   row_val = (int*)malloc(sizeof(int)*(nonzeros));
   col_val = (int*)malloc(sizeof(int)*nonzeros);
   nnz_val = (double*)malloc(sizeof(double)*nonzeros);


   i=0;
   while ((read = getline(&line, &len, fp)) != -1) {
       char *ptr = strtok(line, delim);
       count = 0;
       while(ptr != NULL){
         if(count ==0){  
            row_val[i]= convertStrtoArr(ptr);
         }
         else if(count == 1){
            col_val[i] = convertStrtoArr(ptr);
         }
         else if(count == 2){
            nnz_val[i] =strtod(ptr, &temp_str);
         }
          count++; 
          ptr = strtok(NULL, delim);
         
      }
       i++; 
   }

   row = malloc(sizeof(int)*nonzeros);
   //rowP = malloc(sizeof(int)*nonzeros);

   double seconds, total_time,total_timeP;
    total_time=0.0;
    total_timeP=0.0;

    double* W =  (double*)malloc(sizeof(double)*num_rows*s_factor);
    double* H =  (double*)malloc(sizeof(double)*num_cols*s_factor);
    double* P =  (double*)malloc(sizeof(double)*nonzeros);
    double* ParallelP =  (double*)malloc(sizeof(double)*nonzeros);

    initialize(W,num_rows,s_factor);
    initialize(H,num_cols,s_factor);

    
    // while(idx<nonzeros){
    //     //row_holder[holder]=r;
    //     while(row_val[idx]==r && idx < nonzeros){
    //         idx++;             
    //     }
    //     // tot += nnz_row[r];
    //     holder++;
    //     row[holder]=idx;
    //     // cout << "rows " << r <<" "<< row_ptr[holder] << endl;
    //     r = row_val[idx];
    // }
    // row[holder+1]=idx;


   for(k=0; k < num_runs; k++){

      gettimeofday(&start,NULL);

      sddmm_CPU_CSR(row,col_val,nnz_val,W,H,P,num_rows,s_factor,nonzeros);

       gettimeofday(&end, NULL);

      seconds = (end.tv_sec + (double)end.tv_usec/1000000) - (start.tv_sec + (double)start.tv_usec/1000000); 

      total_time+= seconds;

    //   gettimeofday(&start,NULL);

    //   //  Parallel Run
    //   Par_sddmm_CPU_CSR(rowP,col_val,nnz_val,W,H,ParallelP,num_rows,s_factor,nonzeros);

    //   gettimeofday(&end, NULL);

    //   seconds = (end.tv_sec + (double)end.tv_usec/1000000) - (start.tv_sec + (double)start.tv_usec/1000000); 

    //   total_timeP+= seconds;

   }

//    int failed = 0;
//     for (int i = 0; i < nnzCnt; ++i) {
//       if(P[i]-ParallelP[i] > 10e-4) failed=1;
//     }

//     if(failed == 1){
//       printf("Verification failed!!!");
//       exit(0);
//     }

   printf("Input File Read successfully\n");
   
   printf("-->Avg time taken by the serial kernel for %d runs = %f s\n", num_runs,total_time/num_runs);
   //printf("-->Avg time taken by the Parallel kernel for %d runs = %f s\n", num_runs,total_timeP/num_runs);


    fclose(fp);
    if (line)
      free(line);
    exit(EXIT_SUCCESS);

   return 0;
}

