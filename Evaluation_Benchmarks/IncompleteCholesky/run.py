

import subprocess, sys


print("Testing the incomplete Cholesky Factorization Benchmark")


test_files = 'IncompleteCholesky_m7.c'


test_result = subprocess.call(['gcc', '-fopenmp' ,'-o', 'icm7', test_files, '-lm'])#stdout=subprocess.DEVNULL,stderr=subprocess.STDOUT)
 

if(test_result != 0):
    print("Compilation failed!!")

else:
    print("Compilation Succeeded...")

input = 'bmwcra_1.mtx'

print("Testing with input file: bmwcra_1.mtx")

test_result = subprocess.call(['./icm7', 'input/'+input])#stdout=subprocess.DEVNULL,stderr=subprocess.STDOUT)