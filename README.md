# Introduction & Review

## Learning Objectives:

You should utilize the following tools while implementing this lab:
 - Command Line Arguments
 - 1D Dynamic Arrays (Pointers)

## Here are the libraries you may want to include:
```
    #include <iostream>
    #include <stdlib.h> //Used for atoi
``` 
In this lab, you will create a simple program that allows the user to enter numbers into a dynamic array. The user can then ask the program to print out the largest number, the smallest number, the average of all the numbers, or exit the program.

The program needs to read the size of the array from the user as a command line argument. You should check that the user actually supplied a number before converting the input string to an integer. Continue to prompt the user for correct values if the number isn't a valid non-zero integer. One approach to handling the command line arguments is utilizing the "atoi()" function, which will convert a character taken from the command line into an integer. 

*Note: To use this function, make sure to include the standard library as shown in the libraries section at the top of the page.

```
// To use the atoi function, you'll want to do something like this:

n=atoi(argv[1]);

// Now check that it is a valid non-zero integer  
// ...
```

For example, if you run your program with these command line arguments

```
./prog 5
```

Your program should create a dynamic array of size 5 and then ask the user to enter in 5 numbers to fill in the array. Continue to prompt the user for correct values if the numbers entered aren't valid non-zero integers. 

Your program needs to be well modularized with functions, including main, with 10 or less lines of code. This means you will have a function for each of the requirements, starting with one that checks if the user entered number is a valid, non-zero integer:

```
bool is_valid_number(char *n)
```

and another function that creates the array for holding the integers of size n:

```
int* create_array(int n)
```

In addition, you need to have functions that find the minimum and maximum values in the array, as well as the average of all values in the array, and to delete your array from the heap:

```
int find_maximum(int* num_array, int size)
int find_minimum(int* num_array, int size)
int find_average(int* num_array, int size)
void delete_array(int* num_array)
```

 After your code is functioning, test it using the following approach. Once you are done, show your work to a TA for grading.

## Example Run:

```
./prog t 
You did not input a valid size.
Please enter an integer greater than 0 for the array: 5
Please enter a value for the array: 7
Please enter a value for the array: 22
Please enter a value for the array: 1
Please enter a value for the array: foo
You did not input a valid number.
Please enter a value for the array: 8
Please enter a value for the array: 100
What would you like to do next? 
Print the minimum value (1), print the maximum value (2),  print the average (3), quit (4).
1
The minimum value is 1.
What would you like to do next? 
Print the minimum value (1), print the maximum value (2), print the average (3), quit (4).
2
The maximum value is 100. 
What would you like to do next? 
Print the minimum value (1), print the maximum value (2), print the average (3), quit (4).
4
```

In order to get credit for the lab, you need to be checked off by the end of lab. You can earn a maximum of 10 points for lab work completed outside of lab time, but you must finish before the next lab. For extenuating circumstances, contact your lab TAs and the instructor.

Remember, you will not receive lab credit if you do not get checked off by the TA before leaving each lab. Once you have a zero on a lab, then it cannot be changed because we have no way of knowing if you were there or not!
