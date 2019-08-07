#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>
#include <math.h>

struct LongInt
{
    //Constructor
    LongInt() = default;

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
        std::string long_int_string;
        std::string left_string = std::to_string(left);
        std::string right_string = std::to_string(abs(right));

        if(abs(left)) {
            if(right < 10) {
                long_int_string = left_string + '0' + right_string;
            } else {
                long_int_string =  left_string + right_string;
            }
        } else {
            long_int_string = right_string;
        }

        return long_int_string;
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
    LongInt val1(1, 70);
    LongInt val2("5980");
    LongInt v1(0, 0);
    LongInt v2(0, 10);
    LongInt v3(30, 1);
    LongInt v4(-30, -1);
    LongInt v5;


    val1 += val2;
    std::cout << val1.toString() << std::endl;
}