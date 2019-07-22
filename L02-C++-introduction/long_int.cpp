#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>

struct LongInt
{
    //Constructor
    LongInt(int left,int right) : left(left), right(right)		

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
   // {
   //   left = other.left;
   //  right = other.right;
   // }

  
    //Destructor
    ~LongInt()
    {
        std::cout << "Delete " << toString() << std::endl;
    }
    //Method
    std::string toString()
	  
   { 
	  char change_left[255];
	  char change_right[255];
	  std::sprintf(change_left, "%02d",left);
	  std::sprintf(change_right, "%02d",right);
	 return std::string(change_left) + std::string(change_right); 
	   //return std::to_string(right);
       // return std::to_string(left) +  std::to_string(right);
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
    LongInt operator -= (const LongInt& r2)
    {
	  right -= r2.right;
	  left -= r2.left;
	  left -=right /100;
	  right = right % 100;
	 
	  return *this; 
    }
    //Operator +
    LongInt operator + (const LongInt& ex_l)
    {
	    left =ex_l.left + left;
	    right = ex_l.right + right;
	   
	  
	   return *this;
    }
    //Operator -
	LongInt operator - (const LongInt& ex_l2)
	{
		left = left - ex_l2.left;
		right = right - ex_l2.right;

		return *this;
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


int main()
{
    LongInt val1(31,31);	
    LongInt val2("1111");
    LongInt val3(31,31);
    LongInt val4(11,11); 
    std:: cout << val1.toString() <<std::endl;
    std::cout << val2.toString() << std::endl;
    std::cout << val3.toString() << std::endl; 
    std::cout << val4.toString() << std::endl; 
   
    val3 = val3 - val4;

    val1 += val2;
   std::cout << val1.toString() << std::endl;
   // std::cout << val4.toString() << std::endl;
     
    //val3 -= val4;
    std::cout << val3.toString() << std::endl;
}
