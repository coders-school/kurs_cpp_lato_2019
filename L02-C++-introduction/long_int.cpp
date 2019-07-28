#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <cassert>


struct LongInt
{
    //Constructor with default keyword let us to create object without specific variables inside (see variable val3, val4)
    LongInt() = default;

    LongInt(int left_new, int right_new)
    {
	left = left_new + right_new / 100;
	right = right_new % 100;
    }

    LongInt(const std::string& str)
    {
        int number = std::stoi(str);
        left = number / 100;
        right = number % 100;
	if (right < 0)
	{
		right *= -1;
	}
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
	if (abs(right) < 10)
	{	
	    if (left > 0 || left < 0)
	    {
	    	return std::to_string(left) + "0" + std::to_string(right);
	    }
	    else
	    {
		if (left == 0)
		{
		    return std::to_string(right);
		}
		else
		{
		    return std::to_string(left) + std::to_string(right);
		}
	    }
	}
	else
	{
	    if (left > 0 )
	    {
	    	return std::to_string(left) + std::to_string(right);
	    }
	    else
	    {
		if (left == 0)
		{
		    return std::to_string(right);
		}
		else
		{
		    return std::to_string(left) + std::to_string(right);
		}
	    }
	}
    }

    void operator+=(const LongInt& r)
    {
	if (left >= 0)
	{	
	    if (r.left >= 0)
	    {
	   	left += r.left;
		right += r.right;
		left += right / 100;
		right = right % 100;
	    }
	    else
	    {
		left += r.left;
		if (left < (r.left*-1))
		{
		    right = abs(r.right) + right;
		    if (right < 0)
		    {
		        right += 100;
		    }
		}
		else
		{
		    right -= r.right;
		    if (right < 0)
		    {
			right += 100;
			left -= 1;
		    }
		    left += right / 100;
		    right = right % 100;
		}
	    }
	}
	else
	{
	    if (r.left >= 0)
	    {
		if (left*-1 > r.left)
		{
		    left += r.left;
		    right = right*-1 + r.right;
		    if (right < 0)
		    {
			right += 100;
		    }
		    else
		    {
			left += 1;
		    }  
		}
		else
		{
		    left += r.left;
		    right = r.right - right;
		    if (right < 0)
		    {
			right += 100;
		    }
		    else
		    {
			right = right % 100;
		    }
		}
	    }
	    else
	    {
		left -= r.left;
		right = r.right - right;;
	    }
	}
    }

    void operator-=(const LongInt& r)
    {
	if (left >= 0)
	{
	    if (r.left >= 0)
	    {
		left += r.left;
		right = r.right - right;
		if (right < 0)
		{
		    right += 100;
		    left -= 1;
		}
		left -= right / 100;
	    }
	    else
	    {
		left -= r.left;
		right += r.right;
		left += right / 100;
	    }
	    right = right % 100;		
	}
	else
	{
	    left -= r.left ;
	    if (r.left > 0)
	    {
	    	right += r.right;
	    	left -= right / 100;
	    }
	    else
	    {
		if (abs(left) < r.left)
		{
		    right -= r.right;
	  	    if (right < 0)
		    {
		        right += 100;
		        left += 1;
		    }
		}
		else
		{
		    right = r.right - right;
		}		
		left += right / 100;
	    }
	    right = right % 100;
	}
    }

    LongInt operator+(const LongInt& other)
    {
	LongInt another;
	another.left = this->left;
	another.right = this->right;
	another +=  other;
	return another;
    }

    LongInt operator-(const LongInt& other)
    {
        LongInt another;
	another.left = this->left;
	another.right = this->right;
	another -= other;
        return another;
    }
    
    friend std::ostream& operator<<(std::ostream& output, LongInt& other)
    {
	return output<<other.toString();
    }
   
   friend LongInt& operator>>(std::istream& input,  LongInt& other)
   {
	std::cout << std::endl << "Give me left parametr: ";
	input >>  other.left;
	std::cout << "Give me right parametr: ";
	input >> other.right;

	LongInt temp(other.left, other.right);
	other = temp;

	return other;
   } 

    LongInt& operator=(const LongInt& other)
    {
        left = other.left;
        right = other.right;
        return *this;
    }

    int left;
    int right;
};


int main()
{
    LongInt val1(-1, 70);
    assert (val1.toString()=="-170");
    operator<<(std::cout, val1) << std::endl;
    LongInt val2("-5980");
    assert (val2.toString()=="-5980");
    operator<<(std::cout, val2) << std::endl;
    LongInt val3;
    LongInt val4;
    LongInt val5(0, 10);
    assert (val5.toString()=="10");
    LongInt val6(0, 0);
    assert (val6.toString()=="0");
    LongInt val7(30, 1);
    assert (val7.toString()=="3001");

    LongInt val8(12, 4);
    assert (val8.toString()=="1204");
    LongInt val9(8,2);
    assert (val9.toString()=="802");
    LongInt val10(0,99);
    assert (val10.toString()=="99");
    LongInt val11(-1,1);
    assert (val11.toString()=="-101");
    LongInt val12(-1, 1200);
    assert (val12.toString()=="1100");

    LongInt val13("-9340");
    LongInt val14("5670");
    LongInt val15("-340");
    LongInt val16("5390");
    LongInt val17("140");
    LongInt val18("-5690");
    LongInt val19("9340");
    LongInt val20("-5690");


    std::cout<< "Before: " << val10.toString() << " -=  " << val11.toString() << " =  ";
    val10 -= val11;
    operator<< (std::cout, val10) << std::endl;

    std::cout<< "Before: " << val13.toString() << " -=  " << val14.toString() << " =  ";
    val13 -= val14;
    operator<< (std::cout, val13) << std::endl;

    std::cout<< "Before: " << val15.toString() << " -=  " << val16.toString() << " =  ";
    val15 -= val16;
    operator<< (std::cout, val15) << std::endl;

    std::cout<< "Before: " << val17.toString() << " -=  " << val18.toString() << " =  ";
    val17 -= val18;
    operator<< (std::cout, val17) << std::endl;

    std::cout<< "Before: " << val19.toString() << " -=  " << val20.toString() << " =  ";
    val19 -= val20;
    operator<< (std::cout, val19) << std::endl;


    std::cout<< "Before: " << val10.toString() << " +  " << val11.toString() << " =  ";
    val10 = val10 + val11;
    operator<< (std::cout, val10) << std::endl;

    std::cout<< "Before: " << val10.toString() << " -  " << val11.toString() << " =  ";
    val10 = val10 - val11;
    operator<< (std::cout, val10) << std::endl;

    operator>>(std::cin, val3);
    operator<< (std::cout, val3) << std::endl;
}
