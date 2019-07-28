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
        std::string temp {0};

        if (left == 0)
        {
            temp = std::to_string(right);
        }
        else if (right < 10)
        {
            temp = std::to_string(left) + "0" + std::to_string(right);
        }
        else
        {
            temp = std::to_string(left) + std::to_string(right);
        }

        return temp;
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

    val1 += val2;
    std::cout << val1.toString() << std::endl;

    LongInt val4("0");
    LongInt val5(0, 0);
    LongInt val6("10");
    LongInt val7(0, 10);
    LongInt val8("3001");
    LongInt val9(30, 1);

    std::cout << val4.toString() << std::endl; //00     if l==0 && r==0 print "0"
    std::cout << val5.toString() << std::endl;
    std::cout << val6.toString() << std::endl; //010    if left==0 -> not print left
    std::cout << val7.toString() << std::endl;
    std::cout << val8.toString() << std::endl; //301    if right<10 -> add 0 before right
    std::cout << val9.toString() << std::endl;

    return 0;

}