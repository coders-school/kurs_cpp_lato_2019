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
    LongInt(const LongInt &other)
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
    const std::string toString()
    {

        if (left)
        {
            if (right < 10 && right != 0)
            {
                return std::to_string(left) + "0" + std::to_string(right);
            }
            else if (right == 0)
            {
                return std::to_string(left) + "0";
            }
            else
            {
                return std::to_string(left) + std::to_string(right);
            }
        }
        else
        {
            return std::to_string(right);
        }
    }

    //Operator
    void operator+=(const LongInt &r)
    {
        left += r.left;
        right += r.right;
        left += right / 100;
        right = right % 100;
    }

    //Copy operator
    LongInt &operator=(const LongInt &other)
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
    LongInt val3(30, 01);
    LongInt val4("0");
    LongInt val5(1, 0);

    val1 += val2;
 
    std::cout << val1.toString() << std::endl;
    std::cout << val3.toString() << std::endl;
    std::cout << val4.toString() << std::endl;
    std::cout << val5.toString() << std::endl;
}