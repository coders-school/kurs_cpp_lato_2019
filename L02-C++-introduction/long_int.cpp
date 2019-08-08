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
    std::string toString()
    {
	if(left)
	    {
       		 if(right<10)
	    	     {
	                 return std::to_string(left) + "0" + std::to_string(right);
		     }
		 else
			return std::to_string(left) + std::to_string(right);		 
	
	    } 
         else 
	     return std::to_string(right);	 
			     
    }

    //Operator
    void operator+=(const LongInt& r)
    {
        left += r.left;
        right += r.right;
        left += right / 100;
        right = right % 100;
    }
    void operator-=(const LongInt& r)
    {
        left -= r.left;
        right -= r.right;
        left -= right / 100;
        right = std::abs(right % 100);
    }

    LongInt operator+(const LongInt& r)
    {
        int sumLeft;
	int sumRight;
	sumLeft = this->left + r.left;
        sumRight = this->right + r.right;
        sumLeft += sumRight / 100;
        sumRight = sumRight % 100;

        return LongInt(sumLeft, sumRight);
    }

    LongInt operator-(const LongInt& r)
    {
        int diffLeft;
	int diffRight;

	if(right < r.right)
	    {	    if(this->left - r.left > 0)
		    {
                	diffLeft = this->left - r.left-1;
		    }
		    if(diffLeft < 0)
		        {
			    ++diffLeft;
			}
        	diffRight = this->right - r.right;
       		diffLeft -= diffRight / 100;
       		diffRight = std::abs(diffRight % 100);
	    }
	else
	    {
		diffLeft = this->left - r.left;
        	diffRight = this->right - r.right;
        	diffLeft -= diffRight / 100;
		diffRight = std::abs(diffRight % 100);
	    }

        return LongInt(diffLeft, diffRight);
    }


    //Copy operator
    LongInt& operator=(const LongInt& other)=default;

    //Members
    int left;
    int right;
};

int main()
{
    LongInt val1(1,70);
    LongInt val2("2831");
    LongInt val3("0");

    std::cout << val1.toString() << std::endl;
    std::cout << val2.toString() << std::endl;

    val3+=val2;
    std::cout << val3.toString() << std::endl;

    LongInt val10("2501");
    LongInt val11("401");
    LongInt val20 = val10 + val11;
    LongInt val30 = val10 - val11;

    std::cout << val20.toString() << std::endl;
    std::cout << val30.toString() << std::endl;

    LongInt val100("1");
    LongInt val101("401");
    LongInt val200 = val100 + val101;
    LongInt val300 = val100 - val101;

    std::cout << val200.toString() << std::endl;
    std::cout << val300.toString() << std::endl;


}
