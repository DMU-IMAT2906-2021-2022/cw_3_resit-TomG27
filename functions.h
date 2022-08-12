#pragma once
#include <iostream>
#include <mutex>


class Functions
{


private:


public:


	
	int randomNumber = rand() % 100 + 1; //this variable creates a random number between 0 and 100 to add to the number given by the user in the numberChange function


	// Mutexs + locks 
	std::mutex mtBasic;//!< A basic mutex that can be either locked or unlocked. mt represents multithreading
	std::timed_mutex mtTime;//!<  A timed mutex.
	std::mutex mtConvert;//!< Protects protectedValue.


	// Functions
	void numberChange(int value);//!< This function will us a basic mutex + lock guard. 
	void stringLength(std::string s_UsersString);//!< This function will be an example of basic mutex + lock.
	void mutexTime();//!< This function will use a timed mutex + try_lock_until.

};