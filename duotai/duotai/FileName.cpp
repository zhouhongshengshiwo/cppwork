#include<iostream>
using namespace std;
class cpu {
	virtual void calculate() = 0;
};
class VideoCard{
	virtual void display() = 0;
};
class Memory {
	virtual void storage() = 0;
};