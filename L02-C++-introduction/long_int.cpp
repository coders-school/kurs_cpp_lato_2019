#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;
struct LongInt
{

    //Constructor
    LongInt(int left, int right) : left(left), right(right)
    {
        cout<<"wywolanie konstruktora: "<<endl;
        cout<<left<<" __ ";
        cout<<right <<endl;
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
    LongInt() = default;

    //Destructor
    ~LongInt()
    {

        std::cout << "Delete " << toString() << std::endl;
    }

    //Method
    std::string toString()
    {
        string l="",r="";
        if(left<10) l+="0";
        if(right<10) r+="0";
        return  l + std::to_string(left) + r + std::to_string(right);
    }

    //Operator
    void operator+=(const LongInt& r)
    {
        left += r.left;
        right += r.right;
        left += right / 100;
        right = right % 100;
    }
    LongInt& operator+(const LongInt & r)
    {
        (*this)+=r;
        return *this;
    }
    LongInt operator-=(const LongInt& r)
    {
      *this=*this-r;
       return *this;
    }

    //Copy operator
    LongInt& operator=( LongInt& other)
    {
        left = other.left;
        right = other.right;
        return *this;
    }

    LongInt& operator -(const LongInt& r)
    {
        int num1, num2;
        if(this->left<0)
            num1= this->left* (100) - this->right;
        else
             num1= this->left* (100) + this->right;
        if(r.left<0)
            num2= r.left* (100) - r.right;
        else
            num2= r.left* (100) + r.right;

        num1=num1-num2;
        cout<<num1<<endl;
        if(num1>0)
        {
            this->left = num1 / 100;
            this->right = -num1 % 100;
        }
        if(num1<=-100)
        {
            this->left = num1 / 100;
            this->right = -num1 % 100;
        }
        if(num1>-100 && num1<0)
        {
            this->left = 0;
            this->right = num1 % 100;
        }
        return *this;
    }
    //Members
    int left;
    int right;
};
std::ostream & operator << (std::ostream & e, LongInt & r)
{
    e<<" "<<r.left<<r.right;
    return e;
}


int main()
{

    LongInt val1("1200");
    LongInt val3;
    cout<<val1;
 //   LongInt val2(1,2);
   // val1=val1-val2;
   // cout<<val1.left<<val1.right<<endl;

  //  val1 = val2+val1;
    cout<<val1.left<<val1.right<<endl;
    //std::cout << val1.toString() << std::endl;
}
