#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>

struct LongInt
{
    //Constructor with default keyword let us to create object without specific variables inside (see variable val3, val4)
    LongInt() = default;

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
	if (right < 10 && right > -10)
	{
	    if (left != 0)
	    {
		if (right > 0)
		{
                    return std::to_string(left*10) + std::to_string(right);
		}
		else
		{
		    return std::to_string(left*10) + std::to_string(right * -1);
		}
	    }
	    else
	    {
		return std::to_string(right);
	    }
	}
	else
	{
	    if (left != 0)
	    {
		if (right > 0)
		{
	    	    return std::to_string(left) + std::to_string(right);
		}
		else
		{
		    return std::to_string(left) + std::to_string(right * -1);
		}
	    }
	    else
	    {
		return std::to_string(right);
	    }
	}
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
    void operator-=(const LongInt& r)
    {

	if (r.left > 0)
	{
	    if (left > 0)
	    {
	    	right -= r.right;
	    	left -= r.left;
	    }
	    else
	    {
		right -= r.right;
		left -= r.left;
		left += right / 100;
		right = right % 100;
	    }
	}
	else
	{
	    right += (r.right*-1);
	    left += (r.left * -1);
            left += right / 100;
	    right = right % 100;

	}

	if (right < 0 && left > 0)
	{
	    right += 100;
	    left -= 1;
	}
	else
	{
	    if (right < 0)
	    {
		right *= -1;	   
	    }
	}
    }

    //Operator +
    LongInt operator+(const LongInt& other)
    {
	LongInt another;
	another.left = left + other.left;
	another.right = right + other.right;
	another.left += another.right / 100;
	another.right = another.right % 100;
	return another;
    }

    //Operator -
    LongInt operator-(const LongInt& other)
    {
	LongInt another;

	if (other.left > 0)
	{
	    if (left > 0)
	    {
	    	another.right = right - other.right;
	    	another.left = left - other.left;
	    }
	    else
	    {
		another.right = right - other.right;
		another.left = left - other.left;
		another.left = another.left + another.right / 100;
		another.right =  another.right % 100;
	    }
	}
	else
	{
	    another.right = right + (other.right*-1);
	    another.left = left + (other.left * -1);
            another.left = another.left + another.right / 100;
	    another.right = another.right % 100;

	}

	if (another.right < 0 && another.left > 0)
	{
	    another.right += 100;
	    another.left -= 1;
	}
	else
	{
	    if (another.right < 0)
	    {
		another.right *= -1;	   
	    }
	}

	return another;
    }

    
    //Operator <<
    friend std::ostream& operator<<(std::ostream& output, const LongInt& other)
    {
	output << other.left << other.right;
	return output;
    }
   
   //Operator >>
   friend std::istream& operator>>(std::istream& input,  LongInt& other)
   {
	std::cout << std::endl << "Give me left parametr: ";
	input >>  other.left;
	std::cout << "Give me right parametr: ";
	input >> other.right;

        if (other.right < 0)
        {
	    other.left += ( other.right * -1) / 100;
	    other.right = ( other.right * -1) % 100;
        }
	else
	{
	    other.left += other.right / 100;
	    other.right = other.right % 100;
	}


	return input;
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
    LongInt val1(1, 70);
    LongInt val2("5980");
    LongInt val3;
    LongInt val4;
    LongInt val5(0, 10);
    LongInt val6(0, 0);
    LongInt val7(30, 1);

    LongInt valTest1(12, 4);
    LongInt valTest2(8,2);
    LongInt valTest3(7, -9);
    LongInt valX(0,99);
    LongInt valY(1,1);
    LongInt val90(-30, -1);

    std::cout<<"test for val6(0, 0) -> "<< val6.toString() << std::endl;
    std::cout<<"test for val5(0, 10) -> "<< val5.toString() << std::endl;
    std::cout<<"test for val7(30, 1) -> "<< val7.toString() << std::endl;
    std::cout<<"test for valTest1(12, 4) -> "<< valTest1.toString() << std::endl;
    std::cout<<"test for valTest2(8, 2) -> "<< valTest2.toString() << std::endl;
    std::cout<<"test for valTest3(7, -9) -> " << valTest3.toString() << std::endl;

    std::cout<<"test for val90(-30, -1)" <<val90.toString() << std::endl;
    std::cout<<std::endl;

    LongInt val10("-340");
    LongInt val11("5690");
    std::cout<<"Operator -= : " << val10.toString() << " -= " << val11.toString() <<" = ";
    val10 -= val11;
    std::cout<< val10.toString() << std::endl << std::endl;

    std::cout<<"Operator -= : " << val1.toString() << " -= " << val2.toString() <<" = ";
    val1 -= val2;
    std::cout<< val1.toString() << std::endl << std::endl;

    std::cout<<"Operator -= : " << valTest1.toString() << " -= " << valTest2.toString() <<" = ";
    valTest1 -= valTest2;
    std::cout<< valTest1.toString() << std::endl << std::endl;

    LongInt val95("340");
    LongInt val96("5690");
    std::cout<<"Operator - : " << val95.toString() << " - " << val96.toString() <<" = ";
    val3 = val95 - val96;
    std::cout<< val3.toString() << std::endl << std::endl;

    std::cout<<"Operator + : " << valX.toString() << " + " << valY.toString() <<" = ";
    val3 = valX + valY;
    std::cout<< val3.toString() << std::endl << std::endl;

    std::cout<<"Operator << : ";
    std::cout<< val2.toString() << std::endl << std::endl;

    std::cout<<"Operator >> : ";
    std::cin >> val4;
    std::cout<< val4.toString() << std::endl << std::endl;
}


/*Comments
test for val6(0, 0) -> 0
test for val5(0, 10) -> 10
test for val7(30, 1) -> 3001
test for valTest1(12, 4) -> 1204
test for valTest2(8, 2) -> 802
test for valTest3(7, -9) -> 709
test for val90(-30, -1)-3001

Operator -= : -340 -= 5690 = -6030

Operator -= : 170 -= 5980 = -5810

Operator -= : 1204 -= 802 = 402

Operator - : 340 - 5690 = Delete -5350
-5350

Operator + : 99 + 101 = Delete 200
200

Operator << : 5980

Operator >> : 
Give me left parametr: 1
Give me right parametr: 2
102

Delete 5690
Delete 340
Delete 5690
Delete -6030
Delete -3001
Delete 101
Delete 99
Delete 709
Delete 802
Delete 402
Delete 3001
Delete 0
Delete 10
Delete 102
Delete 200
Delete 5980
Delete -5810
*/
