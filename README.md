
# Matrix Operations in C

A simple command-line program written in C that performs basic matrix operations: addition, multiplication, and transposition.

## Features

- **Matrix Addition** — Add two matrices of the same dimensions
- **Matrix Multiplication** — Multiply two compatible matrices (columns of A must equal rows of B)
- **Matrix Transpose** — Compute the transpose of a single matrix
- Supports matrices up to **10 × 10**
- Input validation for dimensions and menu choices

## Files

| File | Description |
|------|-------------|
| `task2_matrix_operations.c` | Main source file containing all logic |

## Getting Started

### Prerequisites

- A C compiler such as `gcc` or `clang`

### Compilation

```bash
gcc -o matrix_operations task2_matrix_operations.c
```

### Running

```bash
./matrix_operations
```

## Usage

When you run the program, you will be prompted to choose an operation:

```
=== Matrix Operations ===
1. Addition
2. Multiplication
3. Transpose of a matrix
Choose operation:
```

### Example — Matrix Addition

```
Choose operation: 1
Enter rows and columns (1-10): 2 2
Enter elements of A (2 x 2):
A[1][1]: 1
A[1][2]: 2
...
A + B =
    3    5
    7    9
```

### Example — Matrix Multiplication

- You will be prompted for the dimensions of **Matrix A** and **Matrix B** separately.
- The number of columns in A must equal the number of rows in B.

### Example — Transpose

- You will be prompted for a single matrix.
- The program prints its transpose.

## Constraints

| Parameter | Limit |
|-----------|-------|
| Max rows | 10 |
| Max columns | 10 |
| Element type | Integer |

## License

This project is open source and available under the [MIT License](LICENSE).
README.md
Displaying README.md.
