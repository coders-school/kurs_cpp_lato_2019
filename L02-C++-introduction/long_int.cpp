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
//    {
//        left = other.left;
//        right = other.right;
//    }

    //Destructor
    ~LongInt()
    {
        std::cout << "Delete " << toString() << std::endl;
    }

    //Method
    std::string toString()
    {

        // naprawa bug'a
        if (left==0)
            return std::to_string(right);
        else if (right<10)
            return std::to_string(left)+"0"+std::to_string(right);
        else
            return std::to_string(left) + std::to_string(right);
    }

    //Operators
    void operator+=(const LongInt& r)
    {
        left += r.left;
        right += r.right;
        left += right / 100;
        right = right % 100;
    }
    void operator+(const LongInt& r)
    {
        left = r.left + left;
        right = r.right + right;
        left = left + (right / 100);
        right = right % 100;
    }
    void operator-=(const LongInt& r)
    {
        if (r.left>left)
        {
            left -=r.left;
            if (r.right>right)
            {
                right = r.right-right;
            }
            else
            {
                left++;
                right= r.right+100-right;
            }
            left -= right / 100;
            right = right % 100;
        }
        else if (r.left<left)
        {
            left -=r.left;
            if (r.right>right)
            {
                left--;
                right+=100;
                right -= r.right;
        }
            else
                right -= r.right;
                left -= right / 100;
                right = right % 100;
        }
        else
        {
            left = left - r.left;
            if (r.right>right)
            {
                right -= r.right;
            }
            else
            {
                left++;
                right= r.right+100-right;
            }
            left = left - (right / 100);
            right = right % 100;
       }
    }
    void operator-(const LongInt& r)
    {
        if (r.left>left)
        {
            left = left - r.left;
            if (r.right>right)
            {
                right = r.right-right;
            }
            else
            {
                left++;
                right= r.right+100-right;
            }
            left = left - (right / 100);
            right = right % 100;
        }
        else if (r.left<left)
        {
            left = left - r.left;
            if (r.right>right)
            {
                left--;
                right+=100;
                right = left - r.right;
            }
            else
                right = right - r.right;
            left = left - (right / 100);
            right = right % 100;
        }
        else
        {
            left = left - r.left;
            if (r.right>right)
            {
                right -= r.right;
            }
            else
                {
                left++;
                right= r.right+100-right;
                }
            left = left - (right / 100);
            right = right % 100;
       }
}
    //Copy operator
    LongInt& operator=(const LongInt& other)
    {
        left = other.left;
        right = other.right;
        return *this;
    }
    //Insertion operator
    friend std::ostream &operator<<(std::ostream &out,const LongInt &rhs)
    {
        out<<rhs.left<<rhs.right<<std::endl;
             return out;
    }
    //Extraction opearator
    friend std::istream &operator>>(std::istream &in, LongInt &rhs)
    {
        in>>rhs.left;
        in>>rhs.right;
        return in;
    }


    //Members
    int left;
    int right;
};

int main()
{
    LongInt val1(1, 70);
    LongInt val2("5980");
    LongInt val3("0");
    LongInt val4("10");
    LongInt val5("3001");
    LongInt val6("1101");
    LongInt val7("1165");
    LongInt val8("2313");
    LongInt val99;
    val1+=val2;
    val3+val4;
    val6-=val7;
    val7-val8;

    std::cout << "Val1: "<< val1.toString() << std::endl;
    std::cout << "Val2: "<< val2.toString() << std::endl;
    std::cout << "Val3: "<< val3.toString() << std::endl;
    std::cout << "Val4: "<< val4.toString() << std::endl;
    std::cout << "Val5: "<< val5.toString() << std::endl;
    std::cout << "Val6: "<< val6.toString() << std::endl;
    std::cout << "Val7: "<< val7.toString() << std::endl;
    std::cout << "Val8: "<< val8.toString() << std::endl;
    std::cout<<val1<<std::endl;
    std::cin>>val99;
    std::cout<<"You entered: "<<val99<<std::endl;

    return 0;
}
