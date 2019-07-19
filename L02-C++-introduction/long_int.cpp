#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

struct LongInt
{

    LongInt() {}

    //Constructor
    LongInt(int left, int right) : left(left), right(right)
    {
    }

    //Constructor
    LongInt(std::string str)
    {
        int number = std::stoi(str);
        left = number / 10;
        right = number % 10;
    }

    //Copy constructor
//    LongInt(const LongInt& other)
//    {
//        left = other.left;
//        right = other.right;
//    }

    LongInt(const LongInt& other) = default;

    //Destructor
    ~LongInt()
    {
//        std::cout << "Delete " << toString() << std::endl;
    }

    //Method
    std::string toString()
    {
        if (left!=0) return std::to_string(left) + std::to_string(right);
        else return std::to_string(right);
    }

    //Operator
    void operator+=(const LongInt& r)
    {
        left += r.left;
        right += r.right;
        left += right / 10;
        right = right % 10;
    }

    //Copy operator
    LongInt& operator=(const LongInt& other)
    {
        left = other.left;
        right = other.right;
        return *this;
    }

     //Operator -=
    void operator-=(const LongInt& a)
    {
        left -= a.left;
        right -= a.right;
        left -= right / 10;
        right = right % 10;
    }

    //Operator +
    LongInt& operator+(const LongInt& one)
    {
        left += one.left;
        right += one.right;
        left += right / 10;
        right = right % 10;
        return *this;
    }

     //Operator -
    LongInt& operator-(const LongInt& sec)
    {
        left -= sec.left;
        right -= sec.right;
        left -= right / 10;
        right = right % 10;
        return *this;
    }

    friend ostream& operator<<(ostream &out, LongInt& p)
    {
        out << "My << overloading" << endl;
        out << "(" << p.left << "," << p.right << ")" << endl;
        return out;
    }

    friend istream& operator>>(istream &inp, LongInt& s)
    {   
        inp >> s.left >> s.right;
        return inp;
    }
 


    //Members
    int left;
    int right;

};


int main()
{
    LongInt val1(1,70);
    LongInt val2("5980");
    LongInt val3("3001");
    LongInt val4("0");
    LongInt val5("10");
    LongInt val6;
    LongInt val7;
    LongInt val8("100");
    LongInt val9("200");
    LongInt val10("1");
    LongInt val11("2");

    val1 += val2;
    val6 = val8 + val9;
    val7 = val11 - val10;
    val5 -= val4;

    std::cout << "Val1: " << val1.toString() << std::endl;
    std::cout << "Val2: " << val3.toString() << std::endl;
    std::cout << "Val3: " << val4.toString() << std::endl;
    std::cout << "Val5: " << val5.toString() << std::endl;
    std::cout << "Val6: " << val6.toString() << std::endl;
    std::cout << "Val7: " << val7.toString() << std::endl;
    std::cout << "Val5: " << val5.toString() << std::endl;

    cout << val1 << endl;
    cout << "Insert new numbers to object" << endl;
    cin >> val7;
    cout << "You inserted" << val7;



    return 0;

}
