#include <cstdint>
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

struct LongInt
{
    //Constructor
    LongInt(int left, int right) : left(left), right(right)
    {
    }

    //Constructor
    explicit LongInt(const std::string& str)
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
    string toString() const
    {
        if (left)
            if (right <10)
                return std::to_string(left) + "0" + std::to_string(right);
            else
                return std::to_string(left) + std::to_string(right);
        else
            return std::to_string(right);
    }

    //Operator +=
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
        left -= r.left;
        right -= r.right;
        left -= right / 100;
        right = right % 100;
    }

    LongInt operator+(const LongInt& r) {
        int tempLeft, tempRight;
        tempLeft = this->left + r.left;
        tempRight = this->right + r.right;
        tempLeft += tempRight / 100;
        tempRight = tempRight % 100;

        return LongInt(tempLeft, tempRight);
    }

    LongInt operator-(const LongInt& r) {
        int tempLeft, tempRight;
        tempLeft = this->left - r.left;
        tempRight = this->right - r.right;
        tempLeft -= tempRight / 100;
        tempRight = tempRight % 100;

        return LongInt(tempLeft, tempRight);
    }

    //Copy operator
    LongInt& operator=(const LongInt& other)
    = default;

    //Members
    int left;
    int right;
};

ostream& operator<<(ostream &os, const LongInt& p)
{

    return os<< p.toString();
}

istream& operator>>(istream &input, LongInt& p)
{
    input >> p.left;
    input >> p.right;
    return input;
}

void testLongInt() {
    // case 0
    LongInt testVal1a("0");
    LongInt testVal1b(0, 0);

    assert(testVal1a.toString() == "0");
    assert(testVal1b.toString() == "0");

    // case 10
    LongInt testVal2a("10");
    LongInt testVal2b(0,10);

    assert(testVal2a.toString() == "10");
    assert(testVal2b.toString() == "10");

    // case 3001
    LongInt testVal3a("3001");
    LongInt testVal3b(30, 01);

    assert(testVal3a.toString() == "3001");
    assert(testVal3b.toString() == "3001");

    // case -1
    LongInt testVal4a("-1");
    LongInt testVal4b(0, -1);

    assert(testVal4a.toString() == "-1");
    assert(testVal4b.toString() == "-1");

    // case -100
    LongInt testVal5a("-100");
    LongInt testVal5b(0, -100);
    LongInt testVal5c(-1, 0);

    assert(testVal5a.toString() == "-100");
    assert(testVal5b.toString() == "-100");
    assert(testVal5c.toString() == "-100");

    // case a+=b
    LongInt testVal6a(1, 70);
    LongInt testVal6b("5980");
    testVal6b += testVal6a;

    assert(testVal6a.toString() == "170");
    assert(testVal6b.toString() == "6150");

    // case a-=b
    LongInt testVal7a("170");
    LongInt testVal7b(59, 80);
    testVal7b -= testVal7a;

    assert(testVal7a.toString() == "170");
    assert(testVal7b.toString() == "5810");

    // case a-=b
    LongInt testVal8a("1110");
    LongInt testVal8b(11, 00);
    testVal8b -= testVal8a;

    assert(testVal8a.toString() == "1110");
    assert(testVal8b.toString() == "-10");

    // case a+b
    LongInt testVal9a("1110");
    LongInt testVal9b(11, 00);
    LongInt testVal9c = testVal9a + testVal9b;

    cout << testVal9c.toString() << endl;

    assert(testVal9a.toString() == "1110");
    assert(testVal9b.toString() == "1100");
    assert(testVal9c.toString() == "2210");

    // case a+b
    LongInt testVal10a("1717");
    LongInt testVal10b(11, 11);
    LongInt testVal10c = testVal10a - testVal10b;

    cout << testVal10c.toString() << endl;

    assert(testVal10a.toString() == "1717");
    assert(testVal10b.toString() == "1111");
    assert(testVal10c.toString() == "606");

    ostringstream testOutput;

    testOutput << testVal10a;

    assert(testOutput.str() == "1717");

    LongInt testVal11a("0");

    istringstream testInput("100 10");

    testInput >> testVal11a;

    assert(testVal11a.toString() == "10010");
}

int main()
{
    testLongInt();
    
    cout << "Tests OK" << endl;
}