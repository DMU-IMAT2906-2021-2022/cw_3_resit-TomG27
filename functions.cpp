#include "functions.h"


void Functions::numberChange(int iNumber)
{
	//critical section
	const std::lock_guard<std::mutex> lock(mtConvert);
	iNumber = iNumber + randomNumber;
	std::cout << "Your new number is: " << iNumber << std::endl;
}


void Functions::stringLength(std::string sInputString)
{
	mtBasic.lock();//If the thread is the first thread here, it can lock the mutex behind it


	int lengthOfString = sInputString.length();//Sets the value of lengthOfString to the number of chars in the string provided by the user.
	std::cout << "\n\nThe length of your string is: " << lengthOfString << "." << std::endl;


	mtBasic.unlock();//Once the thread has done it's task, it unlocks the mutex, ready for another thread to enter.


}



void Functions::mutexTime()
{
	auto currentTime = std::chrono::steady_clock::now();//starting clock at the time the function starts 
	if (mtTime.try_lock_until(currentTime + std::chrono::seconds(15))) {//the thread will keep trying the lock for 15 seconds until the timer is finished.
		std::cout << "The timer did not expire before the thread was locked." << std::endl;
		mtTime.unlock(); //the mutex unlocks the thread after the trhead was locked
	}
	else {
		std::cout << "\n\nTimer has expired." << std::endl;
	}
}


