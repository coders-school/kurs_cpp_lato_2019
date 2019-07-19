#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>

struct LongInt
{
private:    
    bool isLessThan100() const
    {
        return left == 0;
    }

    bool doesDecimalDigitEqual0() const
    {
        return left != 0 && right < 10;
    }

public:    
    //Constructor
    LongInt(int left, int right) : left(left), right(right)
    {
    }

    //Constructor
    LongInt(std::string str)
    {
        int number = std::stoi(str);
        left = number / 100;
        right = number % 100;
    }

    //Copy constructor
    LongInt(const LongInt& other)
    {
        left = other.left;
        right = other.right;
    }

    //Destructor
    ~LongInt()
    {
        std::cout << "Delete " << toString() << std::endl;
    }

    //Method
    std::string toString()
    {
        if(isLessThan100()) return
            std::to_string(right);
        
        if(doesDecimalDigitEqual0()) 
            return std::to_string(left) + "0" + std::to_string(right); 
         
        return std::to_string(left) + std::to_string(right);       
    }

    //Operator
    void operator+=(const LongInt& r)
    {
        left += r.left;
        right += r.right;
        left += right / 100;
        right = right % 100;
    }

    //Copy operator
    LongInt& operator=(const LongInt& other)
    {
        left = other.left;
        right = other.right;
        return *this;
    }

    //Members
    int left;
    int right;
};

int main()
{
    LongInt val1("0");
    LongInt val2("10");
    LongInt val3("3001");
    
    std::cout << val1.toString() << std::endl;
    std::cout << val2.toString() << std::endl;
    std::cout << val3.toString() << std::endl;   
}
