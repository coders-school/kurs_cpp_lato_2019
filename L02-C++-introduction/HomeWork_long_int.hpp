#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>

struct LongInt
{
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
    LongInt(const LongInt& other) = default;

    //Destructor
    ~LongInt()
    {
     //   std::cout << "Delete " << toString() << std::endl;
    }

    //Method
    std::string toString() const
    {
        if( left == 0 && right >= 0) {
            return std::to_string(right);
        }

        if(left != 0 && right < 10 && right >= 0) {
            std::string zero = "0";
            return std::to_string(left) + zero + std::to_string(right);
        }

        return std::to_string(left) + std::to_string(right);
    }

    //Operator
    LongInt& operator+=(const LongInt& r)
    {
        left += r.left;
        right += r.right;
        left += right / 100;
        right = right % 100;

        return *this;
    }

    LongInt operator+(const LongInt& r)
    {
        LongInt value(left, right);
        value += r;

        return value;
    }

    //Operator-=
    LongInt& operator-=(const LongInt& r)
    {
        if(left < r.left || (left == r.left && right < r.right) ) {
            std::cout << "this value can't be calculated" << std::endl;
            return *this;
        }
        bool isSmaller = right < r.right;

        left -= r.left;
        right -= r.right;

        if(isSmaller) {
            right += 100;
            --left;
        }
        return *this;
    }

    LongInt operator-(const LongInt& r)
    {
        if(left < r.left || (left == r.left && right < r.right) ) {
            std::cout << "this value can't be calculated" << std::endl;
            return LongInt(0, 0);
        }

        LongInt value(left, right);
        value -= r;

        return value;
    }

    //Copy operator
    LongInt& operator=(const LongInt& other) = default;

    friend std::ostream& operator<< ( std::ostream& output, const LongInt& l)
    {
        output << l.toString();
        return output;
    }

    friend std::istream& operator>> ( std::istream& input, LongInt& l)
    {
        input >> l.left >> l.right;
        return input;
    }

    //Members
    int left;
    int right;
};

void cinCoutTest()
{
    LongInt test;
    std::cout << "Enter the values" << std::endl;
    std::cin >> test;

    std::cout << "your values are" << test;
};

void SubtractionOperator()
{
    LongInt value(10, 10);
    LongInt value2(9, 90);
    LongInt value3(9, 99);

    LongInt value4 = value - value2;
    assert(!value4.toString().compare("20"));
    
    LongInt value5 = value2 - value;
    assert(!value5.toString().compare("0"));

    LongInt value6 = value2 - value3;
    assert(!value6.toString().compare("0"));
}

void SumOperatorTest()
{
    LongInt value(10, 70);
    LongInt value2(00, 80);

    LongInt value3 = value + value2;
    value += value3;

    assert(!value3.toString().compare("1150"));
    assert(!value.toString().compare("2220"));    
};

void toStringTestTest()
{
    LongInt value(0, 0);
    assert(!value.toString().compare("0"));

    value = LongInt(1, 0);
    assert(!value.toString().compare("100"));

    value = LongInt(10, 20);
    LongInt value2(9, 90);

    value -= value2;
    assert(!value.toString().compare("30"));

};



void LongIntRunner()
{
    SubtractionOperator();
    SumOperatorTest();
    toStringTestTest();
};