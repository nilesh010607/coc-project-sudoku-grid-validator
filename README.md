# coc-project-sudoku-grid-validator
This C program implements a robust validator for a standard 9x9 Sudoku puzzle solution. The primary goal of the program is to confirm if a given grid is a mathematically correct and solved Sudoku puzzle.
The validation is performed by checking the three fundamental Sudoku rules across the entire 9x9 grid:
Row Constraint: Every row must contain the numbers 1 through 9 exactly once.
Column Constraint: Every column must contain the numbers 1 through 9 exactly once.
Sub-grid (Box) Constraint: Every one of the nine 3x3 sub-grids must contain the numbers 1 through 9 exactly once.
The program currently uses a hard-coded, known-valid Sudoku grid for testing. Upon execution, it prints a clear message indicating whether the provided solution is VALID or INVALID.
Concepts Used
This project demonstrates proficiency in the following C and Mathematical concepts:C Programming Concepts:Arrays: Use of a two-dimensional array (int grid[9][9]) to represent the Sudoku board, and one-dimensional arrays (int seen[10]) as hash/frequency trackers within the validation functions.Functions: Modular design is achieved by separating core logic into specialized functions: check_rows(), check_columns(), check_subgrids(), and the main execution point in main().Loops: Extensive use of nested for loops to iterate over all 81 cells of the grid and the nine 3x3 sub-grids.Control Flow & Conditional Logic: Use of if/else and early return 0 statements for efficient validation and error checking (e.g., detecting duplicates or out-of-range values).Data Type Handling: Proper use of the int type for storing numbers and boolean-like return values (1 for success, 0 for failure).
Mathematical Concepts:
Range Checking: Verification that all values in the grid are within the required set \{1, 2, ..., 9\}.Grid Indexing: Logical indexing and arithmetic are used, particularly in check_subgrids(), to correctly identify the starting coordinates of each 3x3 box (e.g., using boxRow += 3 and boxCol += 3).
To compile the source file (project2.c) using the GCC compiler: 
gcc project2.c -o sudoku_validator
