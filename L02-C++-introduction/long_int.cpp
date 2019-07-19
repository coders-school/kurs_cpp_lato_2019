#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>

void testLongInt();
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

    LongInt() = default;

    //Default copy operator
    LongInt &operator=(const LongInt &other) = default;

    //Destructor
    ~LongInt()
    {
        std::cout << "Delete " << toString() << std::endl;
    }

    std::string toString()
    {

        if (left)
        {
            if (right < 10)
            {
                return std::to_string(left) + "0" + std::to_string(right);
            }
            else
            {
                return std::to_string(left) + "0";
            }
        }
        else
        {
            return std::to_string(right);
        }
    }

    void operator+=(const LongInt &r)
    {
        left += r.left;
        right += r.right;
        left += right / 100;
        right = right % 100;
    }
    void operator-=(const LongInt &r)
    {
        left -= r.left;
        right -= r.right;
        left -= right / 100;
        right = right % 100;
    }

    LongInt operator+(const LongInt &r)
    {
        int tLeft, tRight;

        tLeft = this->left + r.left;
        tRight = this->right + r.right;
        tLeft += tRight / 100;
        tRight = tRight % 100;

        return LongInt(tLeft, tRight);
    }

    LongInt operator-(const LongInt &r)
    {
        int tLeft, tRight;

        tLeft = this->left - r.left;
        tRight = this->right - r.right;
        tLeft -= tRight / 100;
        tRight = tRight % 100;

        return LongInt(tLeft, tRight);
    }

    //Members
    int left;
    int right;
};

int main()
{

    testLongInt();
}

void testLongInt()
{

    assert(LongInt(1, 7).toString() == "107");
    assert(LongInt(0, 10).toString() == "10");

    LongInt val1(1, 70);
    LongInt val2("5980");
    val1 += val2;
    assert(val1.toString() == "6150");
}