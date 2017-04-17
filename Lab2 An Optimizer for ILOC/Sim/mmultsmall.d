// addresses come from the mmult.sl file
// PARAMS Array 
   dis 4 20 20 20 
// INPUTS Array
   dis 120020  0  0  1 1  1 1  2  2  1  3  3 1 4  4  1 // A is identity matrix
       	       5  5  1 6  6 1  7  7  1  8  8 1 9  9  1
       	       10 10 1 11 11 1 12 12 1 13 13 1 14 14 1
	       15 15 1 16 16 1 17 17 1 18 18 1 19 19 1
               0  0  1 1  1 1  2  2  1  3  3 1 4  4  1  // B is identity matrix
       	       5  5  1 6  6 1  7  7  1  8  8 1 9  9  1
       	       10 10 1 11 11 1 12 12 1 13 13 1 14 14 1
	       15 15 1 16 16 1 17 17 1 18 18 1 19 19 1
// output should be a zero if C = I * I produces I
