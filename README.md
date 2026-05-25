# Ordenação e Pesquisa em C
 
A command-line C program that demonstrates classic sorting and searching algorithms on integer arrays.
 
## Usage
 
```bash
gcc main.c ordenacao.c -o programa
./programa <n> <sw>
```
 
- `<n>` — number of elements in the array
- `<sw>` — `1` to generate random values, `0` to read values from stdin
**Example (random array of 10 elements):**
```bash
./programa 10 1
```
 
**Example (manual input of 5 elements):**
```bash
./programa 5 0
1 4 7 2 9
```
 
## Features
 
### Sorting Algorithms
| Algorithm | Order |
|---|---|
| Bubble Sort | Ascending / Descending |
| Selection Sort | Ascending / Descending |
| Insertion Sort | Ascending / Descending |
| Quick Sort (Lomuto Partition) | Ascending |
 
### Search Algorithms
- **Sequential (Linear) Search** — works on any array
- **Binary Search** — requires a sorted array (checked automatically)
## Files
 
| File | Description |
|---|---|
| `main.c` | Entry point and interactive menu logic |
| `ordenacao.h` | Header with type definitions and function declarations |
| `ordenacao.c` | Implementation of all sorting and searching algorithms |
 
## Requirements
 
- GCC, Clang or any C99-compatible compiler
- Standard C libraries: `stdio.h`, `stdlib.h`, `stdbool.h`
