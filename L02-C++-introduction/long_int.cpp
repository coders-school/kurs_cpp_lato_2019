#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>

struct LongInt
{
    LongInt() = default;

    LongInt(int left, int right) : left(left), right(right)
    {
    }

    LongInt(std::string str)
    {
        int number = std::stoi(str);
        left = number / 100;
        right = number % 100;
    }

    LongInt(const LongInt& other)
    {
        left = other.left;
        right = other.right;
    }

    ~LongInt()
    {
        std::cout << "Delete " << toString() << std::endl;
    }

    std::string toString()
    {
        if(left==0)
           return std::to_string(right);
        else if(right<10)
            return std::to_string(left) + "0" + std::to_string(right);
        else
           return std::to_string(left) + std::to_string(right);
    }

    void operator+=(const LongInt& r)
    {
        left += r.left;
        right += r.right;
        left += right / 100;
        right = right % 100;
    }

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

    LongInt operator+(const LongInt& r)
    {
        LongInt result;
        result.left = left + r.left;
        result.right = right + r.right;
        result.left += result.right / 100;
        result.right = result.right % 100;
        return result;
    }

    LongInt operator-(const LongInt& r)
    {
        LongInt result;
        result.right = right - r.right;
        if(result.right<0)
        {
            result.right += 100;
            result.left = left - r.left - 1;
        }
        else
            result.left = left - r.left;

        return result;
    }

    LongInt& operator=(const LongInt& other) = default;

    int left;
    int right;
};

std::ostream& operator<<(std::ostream& out, const LongInt& number)
{
    out << "(" << number.left << "," << number.right << ")";
    return out;
}

std::istream& operator>>(std::istream& in, LongInt& number)
{
    std::cout << "Enter left part of number: ";
    in >>  number.left;
    std::cout << "Enter right part of number: ";
    in >> number.right;
    return in;
}

void test()
{
    LongInt val1("170");
    LongInt val2("0");
    LongInt val3("10");
    LongInt val4("3001");
    LongInt val5(1,70);
    LongInt val6(0,0);
    LongInt val7(0,10);
    LongInt val8(30,1);
    LongInt val9("456");
    LongInt val10("512");
    LongInt val11("701");
    LongInt val12("600");
    LongInt val13;
    LongInt val14;
    LongInt OurVal;

    val1 += val2;
    val4 -= val3;
    val13 = val6 + val7;
    val14 = val11 - val12;

    std::cout << val1.toString() << std::endl;
    std::cout << val2.toString() << std::endl;
    std::cout << val3.toString() << std::endl;
    std::cout << val4.toString() << std::endl;
    std::cout << val5.toString() << std::endl;
    std::cout << val6.toString() << std::endl;
    std::cout << val7.toString() << std::endl;
    std::cout << val8.toString() << std::endl;
    std::cout << val9.toString() << std::endl;
    std::cout << val10.toString() << std::endl;
    std::cout << val11.toString() << std::endl;
    std::cout << val12.toString() << std::endl;
    std::cout << val13.toString() << std::endl;
    std::cout << val14.toString() << std::endl;
    assert(LongInt(1, 7).toString() == "107");
    assert(LongInt(1,70).toString() == "170");
    std::cin >> OurVal;
    std::cout << OurVal;
}

int main()
{
    test();
}
