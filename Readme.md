# Implementation of malloc in C using array

- Used LinkedList to keep track of previously allocated space.
- When the method looks for previously allocated space that is free now, it checks if the size is equal to or greater than the required size. It <b>doesn't</b> split the allocated space if it is greater. Will add that in the future.