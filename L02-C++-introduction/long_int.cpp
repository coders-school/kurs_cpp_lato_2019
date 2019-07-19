#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>

struct LongInt
{
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
        if(left==0)
           return std::to_string(right);
        else if(right<10)
            return std::to_string(left) + "0" + std::to_string(right);
        else
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

    //Operator -=
    void operator-=(const LongInt& r)
    {
        if(right<r.right)
        {
            right+=100;
            left -= 1;
            right -= r.right;
            left -= r.left;
        }
        else
        {
            right-=r.right;
            left-=r.left;
        }
    }

    //Copy operator
    LongInt& operator=(const LongInt& other) = default;

    //Members
    int left;
    int right;
};

int main()
{
    LongInt val1("170");
    LongInt val2("0");
    LongInt val3("10");
    LongInt val4("3001");
    LongInt val5(1,70);
    LongInt val6(0,0);
    LongInt val7(0,10);
    LongInt val8(30,1);

    val1 += val2;
    val8 -= val5;
    std::cout << val1.toString() << std::endl;
    std::cout << val2.toString() << std::endl;
    std::cout << val3.toString() << std::endl;
    std::cout << val4.toString() << std::endl;
    std::cout << val5.toString() << std::endl;
    std::cout << val6.toString() << std::endl;
    std::cout << val7.toString() << std::endl;
    std::cout << val8.toString() << std::endl;
}
