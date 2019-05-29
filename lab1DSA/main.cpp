#include"ShortTest.h"
#include"ExtendedTest.h"
#include<iostream>
#include<chrono>
#include<thread>

using namespace std;

int main()
{
	testAll();
	testAllExtended();
	std::cout << "SIGk";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	return 0;
}