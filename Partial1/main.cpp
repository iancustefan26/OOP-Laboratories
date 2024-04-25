#include <iostream>
#include "PriorityQueue.h"

using namespace std;

int main()
{
    PriorityQueue p(6);
    (((((((p += 5) += 2) += 8) += 3) += 10) += 1) += 11) += 9;
    p.print();
    cout << "\nCount = " << (int)p << endl;
    while ((int)p) {
        cout << (p--) << ",";
    }
    cout << endl;
    (((p += 1) += 2) += 3) += 1;
    cout << "Sum = " << p("sum") << endl;
    cout << "Count = " << (int)p << endl;
    cout << "Min = " << p("min") << endl;
    cout << "Max = " << p("max") << endl;

}
