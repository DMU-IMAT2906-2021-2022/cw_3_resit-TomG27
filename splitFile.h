#pragma once
#include <iostream>
#include <fstream>//Used for file split (A combination of ofstream and ifstream: creates, reads, and writes to files)
#include <future>//Used for async
#include <mutex>//Used for locks
#include <sstream>//Used for file split
#include <thread>//Used for thread work
#include <string>


class SplitFile
{


public:


	bool retrieveFile(std::string fileRead, std::string fileWrite); //boolean to see if its true or false to read the file and write to a new file

	std::vector<std::vector<std::string>> sWords;// this vector will be used to hold the different strings for the files

};

