#Implementation of malloc in C using array

- Used LinkedList to keep track of previously allocated space.
- When it looks for previously allocated space that is free now it checks if the size is equal to/greater than the requirements. It doesn't split the space. Will add that in the future.