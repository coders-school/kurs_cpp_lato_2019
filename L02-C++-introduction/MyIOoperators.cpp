
#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>

struct LongInt
{
    //C
    LongInt()
    {
        left = 0;
        right = 0;
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
    std::string toString() const
    {
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

std::ostream& operator<<(std::ostream& out, const LongInt& tempLongInt)
{
    return out << tempLongInt.toString();
}

std::istream& operator>>(std::istream& in, LongInt& longInt)
{
    std::string inputString;
    in >> inputString;
    longInt = LongInt(inputString);
    return in;
}

int main()
{
    LongInt longInt1("0");
    std::cout << "Wpisz Liczbe: ";
    std::cin >> longInt1;
    std::cout << "Wpisana liczba to: " << longInt1 << std::endl;
    return 0;
}
