
#include "iostream"
#define SQUARE(x) x * x

int main() {
    int num = 5;
    int result = SQUARE(num + 1);  

    std::cout<<"\n The result of square of " << (num+1) << " is: "<< result<<"\n" ; 
    
    return 0;
}




