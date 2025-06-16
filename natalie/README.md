## **PUSH SWAP**

<p align="center" width="100%">
    <img width="33%" src="https://github.com/Arcane-Jill/images/blob/main/push_swapm.png">
</p>

Push Swap is a rank 2 projec at **Hive** Helsinki, which is a school in the 42 network. It was my introduction to the world of sorting algorithms, 
and while I was extremely frustrated at times, I did learn a great deal about how linked lists work and what a stack is or is not.

### **Description**

From the subject: *The Push swap project is a simple yet highly structured algorithmic challenge: you
need to sort data.
You have at your disposal a set of integer values, 2 stacks, and a set of instructions to
manipulate both stacks.
Your goal? Write a C program called push_swap that calculates and displays the
shortest sequence of Push_swap instructions needed to sort the given integers.
Easy?
We’ll see...*

There were a number of deceptive aspects to this project and as the implications revealed themselves it became clear that this is not simply a sorting algorithm.
1. Firstly, the idea that we have to work with "stacks" is deceptive. Only 2 operations are possible on a real stack: pop and push (peak as well, if you want to be pedantic)
    But we have more options here. We were working either with singly or doubly linked linked lists. A linked list is more flexible than a stack so we were also able to
    remove and add things to the "bottom" of the list.
2. In a normal sorting algorithm, parsing the list, comparing values, all the for loops etc, are all considered when deciding how "efficient" the algorithm is.
   For us, only the actual movement of the nodes in the list were counted. Which means we could check and recheck through the lists as much as we wanted, as long as the
   actual movement of nodes was small.

In the end, I really enjoyed this project, and learned so much.
