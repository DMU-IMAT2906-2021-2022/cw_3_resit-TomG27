#include "splitFile.h"



bool SplitFile::retrieveFile(std::string fileRead, std::string fileWrite)
{


	std::ifstream fileIn(fileRead);// Opens the file passed in..
	if (!fileIn) {
		std::cout << "Error: unable to open file: " << fileRead << "." << std::endl;// Error message if file cannot be opened with file name.
	}


	std::ofstream newFile;
	newFile.open(fileWrite, std::ofstream::out | std::ofstream::trunc);//ofstream out to output to file, trunc to get rid of any previou data in the new file.
	if (!newFile) {
		std::cout << "Error: unable to create new file" << fileWrite << "." << std::endl;// Error message if new file cannot be created with new name of file.
	}


	
	if (fileIn) { 
		std::string line;
		std::cout << "The file " << fileRead << " has opened and the file split started." << std::endl;//If the file is opened and the data is being split
		while (std::getline(fileIn, line))//Loop to go through each line of the input file.
		{
			std::stringstream s(line);//s is an instance of the stringstream class that the file is passed into so the strings can be treated as a stream(a flow of data into or out of a program.
			std::string word;


			sWords.push_back(std::vector<std::string>()); //pushes each line into a new vector within the vector or 


			while (getline(s, word, ',')) {
				sWords.front().push_back(word);
			}
		}
	}


	
	if (newFile.is_open()) {
		std::cout << "\n" << fileWrite << " has opened. Data copying has started." << std::endl;//if the new file has been opened correctly the data can be copied into it from the old one
		for (auto row : sWords) {
			for (auto field : row) {
				newFile << field << "," << std::endl;
			}
		}
	}


	std::cout << "\nData copy complete." << std::endl; //once the data copy is complete, this message is displayed
	return true;
}