//
//  main.cpp
//  Lab 1
//
//  Created by Nils Streedain on 9/27/21.
//

#include <iostream>
#include <stdlib.h> //Used for atoi

/// Determines if an input char is a valid int.
/// @param n Char to validate as an int.
bool is_valid_number(char *n) {
	return atoi(n) != 0;
}

/// Function to create an array using user input.
/// @param n Size of array to create.
int* create_array(int n) {
	int * array = new int[n];
	char * curr = new char[100];
	
	// Loops over the size of the array and adds values provided by the user.
	for (int i = 0; i < n; i++) {
		std::cout << "Please enter a value for the array: ";
		std::cin >> curr;
		
		// If the char provided by the user is invalid the user is asked for a new one.
		while (!is_valid_number(curr)) {
			std::cout << "You did not input a valid number.\nPlease enter a value for the array: ";
			std::cin >> curr;
		}
		
		// The valid int is added to the array.
		array[i] = atoi(curr);
	}
	
	// The completed array is returned.
	return array;
}

/// Finds the minimum integer in an int array.
/// @param num_array Array to find the min int from.
/// @param size Size of array provided.
int find_minimum(int* num_array, int size) {
	int currMin = num_array[0];
	
	for (int i = 1; i < size; i++)
		if (num_array[i] < currMin)
			currMin = num_array[i];
	
	return currMin;
}

/// Finds the maximum integer in an int array.
/// @param num_array Array to find the max int from.
/// @param size Size of array provided.
int find_maximum(int* num_array, int size) {
	int currMax = num_array[0];
	
	for (int i = 1; i < size; i++)
		if (num_array[i] > currMax)
			currMax = num_array[i];
	
	return currMax;
}

/// Finds the average integer in an int array.
/// @param num_array Array to find the average int from.
/// @param size Size of array provided.
int find_average(int* num_array, int size) {
	int total = 0;
	
	for (int i = 0; i < size; i++)
		total += num_array[i];
	
	return total/size;
}

/// Deletes the array provided as an argument.
/// @param num_array Array to delete.
void delete_array(int* num_array) {
	delete[] num_array;
}

/// Asked what function the user would like to perform on the input array and then performs the function and asks again until the user inputs '4' to quit.
/// @param num_array Array provided.
/// @param size Size of array provided.
void ask_what_to_do(int* num_array, int size) {
	bool quit = false;
	int choice;
	
	// Repeatedly asks the user what functions to preform on a given array until the user quits.
	while (!quit) {
		std::cout << "What would you like to do next?\nPrint the minimum value (1), print the maximum value (2),  print the average (3), quit (4)." << std::endl;
		std::cin >> choice;
		
		// Uses a switch statement to allow the user to select from various functions.
		switch (choice) {
			case 1:
				std::cout << "The minumum value is: " << find_minimum(num_array, size) << std::endl;
				break;
			case 2:
				std::cout << "The maximum value is: " << find_maximum(num_array, size) << std::endl;
				break;
			case 3:
				std::cout << "The average value is: " << find_average(num_array, size) << std::endl;
				break;
			case 4:
				delete_array(num_array);
				quit = true;
				break;
			default:
				break;
		}
	}
}

/// Uses runtime arguments and user input to generate an int array and perform various functions on said array.
/// @param argc Number of arguments.
/// @param argv Runtime arguments.
int main(int argc, const char * argv[]) {
	// Saves runtime argument 1 for later use.
	char* charSize = (char*)argv[1];
	
	// If the saved runtime argument is not a valid int, the user will be asked repeatedly to provide a new int.
	while (!is_valid_number(charSize)) {
		std::cout << "You did not input a valid size.\nPlease enter an integer greater than 0 for the array: " << std::endl;
		std::cin >> charSize;
	}
	
	// The now valid char containing an int will now be converted to an int.
	int size = atoi(argv[1]);
	
	// Creates an int array of length size using user input and then asks the user what functions to preform.
	ask_what_to_do(create_array(size), size);
	
	return 0;
}
