	#include "splitFile.h"
	#include <fstream>//Used for file split 
	#include <future>//Used for async
	#include <iostream>
	#include "functions.h"
	#include <mutex>//Used for locks
	#include <sstream>//Used for file split
	#include <string>
	#include <thread>//Used for thread work
	

	Functions * lfPtr = new Functions();
	std::string inputString;// A string from the user.
	int number;// An integer from the user.
	

	int main() {
	
		//Runs the retrieveFile function asynchronously.
		SplitFile callSplit;
		auto splitFuture = std::async(std::launch::async, &SplitFile::retrieveFile, &callSplit, "..\Lab book 3\\steam_games.csv", "new_Steam_Games_File.txt"); //async launches a new thread. the location of the csv file is also given
		

		//"new_Steam_Games_File.txt" is passed in as the name for the new file.
		//the futures produced by the asynchronously run function to be stored in "splitFuture".
		
	
		std::cout << "CW_3 Threading" << std::endl; //prints name of cw to screen

		std::cout << "Please enter a number: " << std::endl; //asks user to enter a number for the random number change function
		std::cin >> number;
	
		std::thread T1(&Functions::numberChange, lfPtr, inputString);//Calls the numberChange function.
		std::cout << "Now please enter a string: " << std::endl;
		std::cin >> inputString;
		std::thread T2(&Functions::stringLength, lfPtr, number);//Calls the stringLength function.
		std::thread T3(&Functions::mutexTime, lfPtr);//Calls the mutexTime function.
		
	

	

		//Using the join function to make the threads non-joinable and allow them to be destroyed safely. 
		T1.join();
		T2.join();
		T3.join();
		
	
		return 0;
	}


