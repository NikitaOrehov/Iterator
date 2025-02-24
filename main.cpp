#include <iostream>
#include <vector>
#include "IntArr.h"
#include "MyForwardList.h"

int main(){
    MyForwardList<int> f;
    f.AddNode(15);
    std::cout<<f<<"\n";
}