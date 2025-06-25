
# Project Push Swap

## Project from 42 school defended at Hive Helsinki

The push swap project is a simple yet highly structured algorithmic challenge.

You have 2 set of integers values, 2 stacks and a set of instructions to 
manipulate both stacks.

The goal is to write a program that calculate and display the shortest 
sequence of instructions to sort the given integers in ascending order.

### The Rules

- 2 stacks: `a` and `b`. 
- The `a` stack contain a random number of unique signed integers. 
- The stack `b` is empty.


#### The movements

- `sa(swap a)`: Swap the first 2 elements at the top of stack `a`.
Do nothing if there is only one element or none.
- `sb(swap b)`: Swap the first 2 elements at the top of stack `b`.
Do nothing if there is only one element or none.
- `ss`: `sa` and `sb` at the same time.
- `pa(push a)`: Take the first element at the top of `b` and put it at the top
of `a`. Do nothing if `b` is empty.
- `pb(push b)`: Take the first element at the top of `a` and put it at the top
of `b`. Do nothing if `a` is empty.
- `ra(rotate a)`: Shift up all elements of stack `a` by 1.
The first element becomes the last one.
- `rb(rotate b)`: Shift up all elements of stack `b` by 1.
The first element becomes the last one.
- `rr`: `ra` and `rb` at the same time.
- `rra(reverse rotate a)`: Shift down all elemnts of stack `a` by 1.
The last element becomes the first one.
- `rrb(reverse rotate b)`: Shift down all elemnts of stack `b` by 1.
The last element becomes the first one.
- `rrr`: `rra` and `rrb` at the same time. 

### The Benchmark 
Max validation(100)
- Sort 100 random numbers in fewer than 700 operations.
- Sort 500 random numbers in no more than 5500 operations.

Min validation (80%)
- Sort 100 random numbers in under 1100 operations and 500 numbers in 8500 operations.
- Sort 100 random numbers in under 700 operations and 500 numbers in 11500 operations.
- Sort 100 random numbers in under 1300 operations and 500 numbers in 5500 operations.

### The Functions 
### The Logic 
### The Bonus
