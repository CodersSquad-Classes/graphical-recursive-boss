[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/f_6PzPyj)
# ds-graphical-recursive

Let's get creative. On this lab, you will be creating a recursive program that generates the base for a graphical recursive algorithm. Since we haven't seen any graphics library, you don't need to worry about the visualization, the professor will provide the mechanism ro visualize your data.

From the _Essential Algorithms: A Practical Approach to Computer Algorithms_ book, in [Chapter 9: Recursion](https://learning.oreilly.com/library/view/essential-algorithms-a/9781118612101/17_chapter09.html#c09-5), implement one of the following 3 graphical recursive algorithms

- Koch Curves
- Hilbert Curve
- Sierpiński Curve

# Implementation Requirements

- Each algorithm has its own parameters, make sure you document them in the [following section](#how-to-compile--run-you-program)
- Parameters must be sent through the command line. Example below:
    ```
    ./your-program <param1> <param2> ... 
    ```
- The output of your program will be a list of line segments in a file called `lines.txt`. The `lines.txt` file must follow the following format. Each pair represents a point in a 2D plane
    ```
    (1,2)(33,3)
    (3,5)(3,43)
    (2,1)(3,3)
    ```
- There's a 1024x1024 canvas, make sure that your generated points are inside that limited space. 
- The progressor will provide the mechanism to visualize your data, just make sure you generate the proper `lines.txt` file




# How to compile & run you program

Evidence 1.3.1 - Graphical Recursive Algorithms  
Author: Luis Andrés Casillas (A01645008)  
Date: 08/09/2025  

---

## Implemented Algorithm
This program implements the **Hilbert Curve**, one of the graphical recursive algorithms described in *Essential Algorithms: A Practical Approach to Computer Algorithms* (Chapter 9: Recursion).  

The Hilbert Curve is a space-filling fractal generated recursively by subdividing a square into quadrants and connecting them with smaller Hilbert Curves rotated appropriately.  

- **Parameter**: `depth` (recursion level, 1–10)  
- **Segments generated**: `4^depth - 1`  
- **Canvas**: 1024 × 1024, all coordinates are scaled and clamped to this range.  
- **Output**: A text file `lines.txt` containing all line segments. Each line is formatted as:  
(x1,y1)(x2,y2)

yaml
Copiar código

---

## How to Compile & Run

### Compile
On **Linux/Mac (bash)**:
```bash
g++ -O2 -std=c++17 graphical_recursive.cpp -o graphical_recursive
On Windows (PowerShell):

powershell
Copiar código
g++ -O2 -std=c++17 graphical_recursive.cpp -o graphical_recursive.exe
Run
Linux/Mac:

bash
Copiar código
./graphical_recursive hilbert <depth>
Windows (PowerShell):

powershell
Copiar código
.\graphical_recursive.exe hilbert <depth>
Replace <depth> with an integer between 1 and 10.

Example
Running with depth = 3:

powershell
Copiar código
.\graphical_recursive.exe hilbert 3
Output in console:

yaml
Copiar código
Algorithm: Hilbert, depth=3
Grid size: 8x8 points
Segments:  63 (expected 63)
Output:    lines.txt (1024x1024 canvas)
First lines in lines.txt:

scss
Copiar código
(0,0)(0,146)
(0,146)(146,146)
(146,146)(146,0)
...
Notes
The professor will provide the visualization mechanism; this program only produces the line segment data.

Coordinates are guaranteed to be within the [0,1023] range.

The program validates input and prints usage instructions if parameters are missing or invalid.

# Grading Policy

| **Rubric**                             | **Points** |
|----------------------------------------|------------|
| Successful Compilation                 | 25%        |
| Coding Practices                       | 5%         |
| Well formed `lines.txt` file           | 35%        |
| Proper Algorithm's graphics rendering  | 35%        |
| **Total**                              | 100%       |
