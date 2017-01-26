#include <iostream>

using std::cout;
using std::endl;

extern bool slice(int);

bool useSlice()
    {
    int n = 100000;
    cout << "[Start Slice ]" << endl;
    return slice(n);
    }
