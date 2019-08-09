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
    LongInt(const LongInt& other) = default;

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
		if(right <10 && right != 0)
		{
			return std::to_string(left) + "0" + std::to_string(right);
		}
		if(right == 0)
		{
			return std::to_string(left) + "0";
		}
		else return std::to_string(left) + std::to_string(right);

	}
	return  std::to_string(right);
    }

    //Operator
    void operator+=(const LongInt& r)
    {
        left += r.left;
        right += r.right;
        left += right / 100;
        right = right % 100;
    }

    //Copy operator
    LongInt& operator=(const LongInt& other)
    {
        left = other.left;
        right = other.right;
        return *this;
    }
    
    void operator-=(const LongInt &r)
    {
        left = left - r.left;
        right = right - r.right;
        left = left + right / 100;
        right = right % 100;
        if(right < 0) 
        {
            left = left - 1;
            right = 100 + right;
        }
    }   
    
    //Members
    int left;
    int right;
};


int main()
{
    LongInt val1(1, 70);
    LongInt val2("5980");
    LongInt val3(30, 01);
    LongInt val4("0");
    LongInt val5(0,10);
    LongInt val6(10,0);
    val1 += val2;
    std::cout << "val1: " << val1.toString() << std::endl;
    std::cout << "val3: " << val3.toString() << std::endl;
    std::cout << "val4: " << val4.toString() << std::endl;
    std::cout << "val5: " << val5.toString() << std::endl;
    std::cout << "val6: " << val6.toString() << std::endl;
    
    val1 -= val2;
    std::cout << "val -= val2 : " << val1.toString() << std::endl;
    
    val2 -= val1;
    std::cout << "val2 -= val1 : " << val2.toString() << std::endl;

    val6 -= val5;
    std::cout << "val6 -= val5: " << val6.toString() << std::endl;
}
