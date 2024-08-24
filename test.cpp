#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ofstream ofs;
   ofs.open("1.txt", ios::out);
    ofs << "超级喜欢" << endl;
    return 0;

}