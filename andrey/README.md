# push_swap
This program sorts data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed I had to manipulate various
types of algorithms and choose the most appropriate solution for an optimized
data sorting.

### At the beginning:
The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.

The stack b is empty.
### The goal is to sort in ascending order numbers into stack a. To do so I had the following operations at my disposal:
sa (swap a): Swap the first 2 elements at the top of stack a.

sb (swap b): Swap the first 2 elements at the top of stack b.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.

pb (push b): Take the first element at the top of a and put it at the top of b.

ra (rotate a): Shift up all elements of stack a by 1.

rb (rotate b): Shift up all elements of stack b by 1.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.

rrb (reverse rotate b): Shift down all elements of stack b by 1.

rrr : rra and rrb at the same time.

## Installation

<!-- start:code block -->
#### Clone this repository
git clone https://github.com/aklimchu/push_swap.git

cd push_swap

<!-- end:code block -->

## Running the tests

<!-- start:code block -->
#### Create the library with Makefile
make

#### Test the function with your own arguments
$>ARG="4 67 3 87 23"; ./push_swap $ARG

#### Clean the object files and library file
make fclean

<!-- end:code block -->

## License
This project is licensed under the GNU GENERAL PUBLIC LICENSE - see the LICENSE.md file for details
