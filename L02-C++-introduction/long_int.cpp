#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>
#include <sstream>

void testLongInt();
struct LongInt
{
    friend std::ostream &operator<<(std::ostream &out, const LongInt &c)
    {
        out << c.left << c.right;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, LongInt &c)
    {
        std::cout << "Enter Left Part ";
        in >> c.left;
        std::cout << "Enter Right Part ";
        in >> c.right;
        return in;
    }

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

    std::string toString() const
    {

        if (left)
        {
            if (right < 10)
            {
                return std::to_string(left) + "0" + std::to_string(right);
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

    void operator+=(const LongInt &r)
    {
        left += r.left;
        right += r.right;
        left += right / 100;
        right = right % 100;
    }
    void operator-=(const LongInt &r)
    {
     
        if(right < r.right)
        {
            right += 100;
            left -=1;
            left -= r.left;
            right -= r.right;
        }else{
        left -= r.left;
        right -= r.right;
        }

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
        tRight = right = r.right;
        if(tRight < 0)
        {
            tRight += 100;
            tLeft = left + r.left -1;
        }else
        {
            tLeft = left - r.left;
        }
        

        tLeft -= this->left - r.left;
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

    LongInt valStr("1110");
    LongInt val3(11, 00);
    LongInt test;
    LongInt test2;

    test = val3 + valStr;
    assert(test.toString() == "2210");
    val3 -= valStr;
    assert(val3.toString() == "-10");
    test2 = val3 - valStr;
    assert(test2.toString() == "-10");

}