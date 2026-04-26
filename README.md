_This project has been created as part of the 42 curriculum by gumagni._

# Description

Push_swap is a sorting algorithm project that implements a solution to sort a stack of integers using a limited set of operations. The goal is to sort a stack (stack A) in ascending order using two stacks (A and B) and a specific set of operations.

## Project Overview

- **Algorithm**: Turk, uses a greedy approach with cost analysis to determine the most efficient moves
- **Strategy**: Divides the problem into two phases:
  1. **Phase 1**: Push all elements from stack A to stack B, positioning them to enable efficient sorting
  2. **Phase 2**: Push elements back to stack A in sorted order

## Features

- Handles sorting for any number of integers
- Optimized for minimal operation count
- Supports sorting stacks of size 2, 3, 5, and larger
- Includes error handling for invalid inputs and duplicates

## Operations Available

| Operation | Description |
|-----------|-------------|
| `sa` / `sb` / `ss` | Swap the first two elements of stack a/b/both |
| `ra` / `rb` / `rr` | Rotate stack a/b/both (first element becomes last) |
| `rra` / `rrb` / `rrr` | Reverse rotate stack a/b/both (last element becomes first) |
| `pa` / `pb` | Push element from stack a to b or b to a |

# Instructions

## Compilation

```bash
make
```

This will generate the `push_swap` executable.

## Usage

```bash
./push_swap <numbers>
```

Or with space-separated arguments:

```bash
./push_swap "3 1 4 1 5"
```

## Examples

```bash
# Sort three numbers
./push_swap 3 2 1

# Sort five numbers
./push_swap 5 4 3 2 1

# Sort with space-separated input
./push_swap "10 5 8 3 1 6 9 2 7 4"
```

## Makefile Targets

| Target | Description |
|--------|-------------|
| `make` / `make all` | Compile the project |
| `make clean` | Remove object files |
| `make fclean` | Remove executable and object files |
| `make re` | Clean and recompile |

## Testing

To make the tester script executable:

```bash
chmod +x ./push_swap_test_linux.sh
```

Then run:

```bash
./push_swap_test_linux.sh
```

# Resources

## Algorithm References

- **Thuggonaut**: (https://www.youtube.com/watch?v=wRvipSG4Mmk) - Guide explaining the project and a valid solution
- **gemartin99**: (https://github.com/gemartin99/Push-Swap-Tester) - Tester
- **42 Intra**: [Subject PDF](https://cdn.intra.42.fr/pdf/pdf/96055/en.subject.pdf) - Official project specifications
- **Stack Sorting Algorithms**: General concepts on sorting with restricted operations, Turk

## Technical Documentation

- **Linked List Implementation**: Used for stack management with doubly-linked structure
- **Cost-based Selection**: Greedy algorithm that calculates operation costs for each element
- **Target Node Selection**: Algorithm to find optimal target positions for elements

# AI Usage

AI was used as a learning and debugging tool throughout this project:

- **Code Review**: AI-assisted in reviewing and understanding sorting algorithm patterns
- **Debugging**: Helped identify and fix edge cases in the sorting logic
- **Optimization**: Discussed strategies for reducing operation count
- **Concept Explanation**: Used to clarify algorithm concepts and data structure choices

*Note: All code was written and understood by the student, with AI serving as a supplementary tool for learning and verification.*