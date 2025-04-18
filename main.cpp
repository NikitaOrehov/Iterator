#include <iostream>
#include <vector>
#include "IntArr.h"
#include "MyForwardList.h"

int main(){
    MyForwardList<int> f;
    f.AddNode(15);
    f.AddNode(20);
    f.AddNode(15);
    f.AddNode(20);
    f.AddNode(4);
    f.AddNode(15);
    std::cout << f << "\n";
    int array[2]{ 15, 4 };
    f.DeleteElem(array, 2);
    std::cout << f << "\n";
}