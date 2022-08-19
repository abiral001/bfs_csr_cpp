# Breadth first search using CSR reference using https://github.com/asherliu/graph_project_start

## Steps to reproduce:

 ### 1. Create a dummy graph txt file as in ./tuple_text_to_binary_csr_mem/beg_file.txt
 ### 2. Run <i> ./tuple_text_to_bin ./beg_file.txt 1 0 1 </i> to generate csr, vertex info and weight info bin files
 ### 3. Add these files in ./example folder
 ### 4. Run ./main ./example/beg.bin ./example/csr.bin ./example/weight.bin
 ## 5. The final output is at the end of console log.

## New files added / altered from main repo:
 
 ### 1. main.cpp -> Implemented BFS (altered)
 ### 2. queue.h -> Implemented queue for BFS (new) 