#ifndef TIME
#define TIME
#include<chrono>
#include<iostream>
#include<fstream>

class Time
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> pradzia_,pabaiga_;
	std::chrono::duration<double> skirtumas_;
public:
	void Start_clock();
	void Stop_clock();
	void Get_time(std::ofstream&, int&);
};
#endif