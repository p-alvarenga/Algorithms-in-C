## N-Queen Problem

The N-Queen problem was one of the first algorithms that truly challenged me. Through this problem, I realized that not every algorithm has an obvious solution—some require deep thought and careful design.

> [!WARNING] 
> This version of the system has not been thoroughly reviewed, so the code may not be in its optimal form.

### Project Structure

This project consists of three main files:

1. **`nqueen.c`**  
   - Measures the execution time of `solveNqueen()`.  
   - Defines the `printSolution()` function.  

2. **`solve-nqueen.h`**  
   - Implements the two core functions:  
     - `solveNqueen()`: Solves the N-Queen problem.  
     - `verifyPosition()`: Checks if a queen can be placed at a given position.  

3. **`verify_solution.h`**  
   - As `N` increases, solution verification becomes essential.  
   - This file provides a function to verify the correctness of the solution, ensuring the results are valid (especially since some outputs seemed unexpectedly fast).  

### Additional Notes

The `performance-analysis/` directory is currently under development and not actively used yet.
