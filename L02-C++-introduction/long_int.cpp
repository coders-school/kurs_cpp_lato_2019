#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>

struct LongInt
{

    //  Constructor
      LongInt(int left, int right) : left(left), right(right)
      {
      }

    // Default constructor
     LongInt() = default;

     //Constructor
    LongInt(std::string str)
    {
        int number = std::stoi(str);
        left = number / 100;
        right = number % 100;
    }

    //Copy constructor
    LongInt(const LongInt& other)=default;


    //Destructor
    ~LongInt()
    {
        std::cout << "Delete " << toString() << std::endl;
    }


    //Method
    std::string toString()
    {
            if(left==0)   return std::to_string(right);
            else if(left>0 && right<10)   return std::to_string(left) + "0"+  std::to_string(right);
            else return std::to_string(left) + std::to_string(right);
    }



    //Operator
    void operator+=(const LongInt& r)
    {
        left += r.left;
        right += r.right;
        left += right / 100;
        right = right % 100;
    }


    //Operator
    void operator-=(const LongInt& r)
    {
        if (left>=r.left)
        {
                left -= r.left;
                right -= r.right;
                if(right<0 && left!=0) {left-=1; right+=100;}

        }

        else
        {
            int x=left, y=right;
            left=r.left;
            right=r.right;

            left -= x;
            right -= y;
            if(right<0) {left-=1; right+=100;}

            left*=(-1);

        }
     }

 //Operator
    LongInt operator+(const LongInt &other)
    {
        LongInt example(0,0);

        example.left = left + other.left;
        example.right = right + other.right;
        example.left += example.right / 100;
        example.right = example.right % 100;

        return example;
    }


    //Operator
    LongInt operator-(const LongInt &other )
    {
        LongInt example(0,0);


        if (left>=other.left)
        {
               example.left = left - other.left;
               example.right = right - other.right;
               if(example.right<0 && example.left!=0) {example.left-=1; example.right+=100;}
        }


        else
        {
            LongInt example1(other.left,other.right);
            LongInt example2(left,right);

            example.left = example1.left - example2.left;
            example.right = example1.right - example2.right;

           if(example.right<0) {example.left-=1; example.right+=100;}

           example.left*=(-1);

        }
        return example;
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
std::ostream & operator<< (std::ostream &out, const LongInt &i)
{
    out << i.left;
    out << i.right;
    return out;
}

std::istream & operator>> (std::istream &in,  LongInt &i)
{
    std::cout << "Enter first (left) number ";
    in >> i.left;
    std::cout << "Enter second (right) number ";
    in >> i.right;
    return in;
}


int main()
{
    LongInt val0{};
      std::cout << "val0 = "<<val0.toString() << std::endl;
    LongInt val1(1, 70);
    LongInt val2("5980");

    val0=val1;

    std::cout <<"val0 = "<< val0.toString() << std::endl;
    std::cout << "val1 = "<<val1.toString() << std::endl;

    val1 += val2;
    std::cout << "val1 (po dzialaniu) = "<<val1.toString() << std::endl;
}
