#include <iostream>
#include <functional> //std::multiplies

int main()
{
    std::multiplies<int> mult;
    // std::cout << mult(4,2);
    
    std::function<int(int)> myMultFunction = std::bind(mult, std::placeholders::_1, 5);
    std::cout << myMultFunction(11) << '\n';

    std::function<int(int)> myLambdaMultFunction = [&mult](int n){return mult(n, 5);};
    std::cout << myLambdaMultFunction(11) << '\n';

    return 0;
}