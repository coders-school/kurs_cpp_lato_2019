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
        right = number % 100;
        left = (number - right) / 10;
    }

    //Copy constructor
    LongInt(const LongInt& other) = default;

    //Destructor
    ~LongInt() = default;

    //Method
    std::string toString() const
    {
        std::string leftStr = left == 0 
            ? ""
            : std::to_string(left);

        return leftStr + std::to_string(right);
    }

    //Operator
    void operator+=(const LongInt& r)
    {
        left += r.left;
        right += r.right;
        left += right / 100;
        right = right % 100;
    }

    void operator-=(const LongInt& r)
    {
        left -= r.left;
        right -= r.right;
        left -= right / 100;
        right = right % 100;
    }

    LongInt operator+(const LongInt& r)
    {
        LongInt result = *this;
        result += r;
        return result;
    }

    LongInt operator-(const LongInt& r)
    {
        LongInt result = *this;
        result -= r;
        return result;
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

    void setLeft(const int& l)
    {
        left = l;
    }

    void setRight(const int& r)
    {
        right = r;
    }
};

std::ostream& operator<<(std::ostream& os, const LongInt& li)
{
    os << li.toString();
    return os;
}

std::istream& operator>>(std::istream& is, LongInt& li)
{
    int l {};
    int r {};
    
    std::cout << "Enter left part: ";

    is >> l;

    li.setLeft(l);

    std::cout << "\nEnter right part: ";

    is >> r;

    li.setRight(r);

    return is;
}

int main()
{
    LongInt li0("0");
    LongInt li10("10");
    LongInt li3001("3001");
    LongInt li3002("3002");

    std::cout << li0 << " " << li10 << " " << li3001 << "\n";

    li3002 -= li3001;

    std::cout << li3002 << "\n";
    std::cout << (LongInt("3002") - li3001) << "\n";
}