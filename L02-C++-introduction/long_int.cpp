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
        left = number / 100;
        right = number % 100;
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
    std::string toString() const
    {
        if (left!=0) 
        {   
            if (right >=1 and right <=9) return std::to_string(left) + "0" + std::to_string(right);
            else return std::to_string(left) + std::to_string(right);
        } 
        else return std::to_string(right);
    }

    //Operator +=
    void operator+=(const LongInt& r)
    {
        left += r.left;
        right += r.right;
        left += right / 100;
        right = right % 100;
    }

    //Operator =
    LongInt& operator=(const LongInt& other)
    {
        left = other.left;
        right = other.right;
        return *this;
    }

     //Operator -=
    void operator-=(const LongInt& a)
    {   
//        cout << a.left << endl;
//        cout << a.right << endl;
        
        right -= a.right;
        if (right < 0)
        {
            right += 100;
            left = left - a.left - 1;
        }
        else 
            left -= a.left;
        cout << left << endl; 
        cout << right << endl; 
    }


    //Operator +
    LongInt operator+(const LongInt& one)
    {
        LongInt sum;
        sum.right = (right + one.right) % 100;
        sum.left = (right + one.right) / 100 + left + one.left;
        return sum;
    }

     //Operator -
    LongInt operator-(const LongInt& sec)
    {
        LongInt min;
        min.right = right - sec.right;
        if (min.right < 0)
        {
            min.right += 100;
            min.left = left - sec.left - 1;
        }
        else
            min.left = left - sec.left;

        return min;
    }

    friend ostream& operator<<(ostream &out, LongInt& p)
    {
        out << "My << overloading" << endl;
        return out << p.toString();
    }

    friend istream& operator>>(istream &inp, LongInt& s)
    { 
        LongInt obj;  
        inp >> obj.left >> obj.right;
        s.left = obj.left;
        s.right = obj.right;
        return inp;
    }
 

    //Members
    int left;
    int right;

};


int main()
{
    LongInt val1(1,70);
    LongInt val2("598");
    LongInt val3("3001");
    LongInt val4("0");
    LongInt val5("10");
    LongInt val6;
    LongInt val7;
    LongInt val8(30,10);
    LongInt val9(10,40);
    LongInt val10;
    LongInt val11;
    LongInt val12("80"); 


    val6 = val2 - val1;
    val3 -= val2;
    val7 = val1 + val2;
    val10 = val8 - val9;
    val12 += val5;

    std::cout << "598 - 170 = 428 here: " << val6.toString() << std::endl;
    std::cout << "3001 -= 598 gives 2403 here: " << val3.toString() << std::endl;
    std::cout << "170 + 598 = 768 here: " << val7.toString() << std::endl;
    std::cout << "val1: " << val1.toString() << std::endl;
    std::cout << "val8: " << val8.toString() << std::endl;
    std::cout << "3010 - 1040 = 1970 here: " << val10.toString() << std::endl;
    std::cout << "80 += 10 = 90 here: " << val12.toString() << std::endl;


    cout << "Insert new numbers to object - left and right: " << endl;
    cin >> val11;
    cout << "You inserted: " << val11 << endl;;

    return 0;

}
