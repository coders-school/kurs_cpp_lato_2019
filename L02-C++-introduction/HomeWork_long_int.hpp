#include <cstdint>
#include <iostream>
#include <string>
#include <cassert>

struct LongInt
{
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
    LongInt(const LongInt& other) = default;

    //Destructor
    ~LongInt()
    {
     //   std::cout << "Delete " << toString() << std::endl;
    }

    //Method
    std::string toString()
    {
        if(left == 0 && right == 0) {
            return "0";
        }
        if(left != 0 && right < 10 && right >= 0) {
            std::string zero = "0";
            return std::to_string(left) + zero + std::to_string(right);
        }
        if( left == 0) {
            return std::to_string(right);
        }
        if(right < 0) {
            return std::to_string(left) + std::to_string(-right);
        }
        return std::to_string(left) + std::to_string(right);
    }

    //Operator
    void operator+=(const LongInt& r)
    {
        left += r.left;
        right += r.right;
        left += right / 100;
        right = right % 100;
    }

    LongInt operator+(const LongInt& r)
    {
        int le = left + r.left;
        int ri = right + r.right;
        
        LongInt result( le + ri / 100, ri % 100 );
        return result;
    }

    //Operator-=
    void operator-=(const LongInt& r)
    {
        if(left < r.left || (left == r.right && right < r.right) ) {
            std::cout << "this value can't be calculated" << std::endl;
            return;
        }
        bool isSmaller = right < r.right;

        left -= r.left;
        right -= r.right;

        if(isSmaller) {
            right += 100;
            --left;
        }
    }

    LongInt operator-(const LongInt& r)
    {
        if(left < r.left || (left == r.right && right < r.right) ) {
            std::cout << "this value can't be calculated" << std::endl;
            return LongInt(0, 0);
        }
        bool isSmaller = right < r.right;

        int le = left - r.left;
        int ri = right - r.right;

        if(isSmaller) {
            ri += 100;
            --le;
        }

        return LongInt(le, ri);
    }

    //Copy operator
    LongInt& operator=(const LongInt& other)
    {
        left = other.left;
        right = other.right;
        return *this;
    }

    friend std::ostream& operator<< ( std::ostream& output, const LongInt& l)
    {
        output << "left: " << l.left << "right: " << l.right << std::endl;
        return output;
    }

    friend std::istream& operator>> ( std::istream& input, LongInt& l)
    {
        input >> l.left >> l.right;
        return input;
    }

    //Members
    int left;
    int right;
};

void cinCoutTest()
{
    LongInt test;
    std::cout << "Enter the values" << std::endl;
    std::cin >> test;

    std::cout << "your values are" << test;
}

void SubtractionOperatorInnerLoop(const int& val1_ts, const int& val1_dj, const int&  val1_counter)
{
    int ts = 99, dj = 99, counter = 9999;
    LongInt* val1;
    LongInt* val2;

    while (ts != -1)
    { 
        if(val1_counter - counter < 0) {
            break;
        }
        if(dj == -1) {
            --ts; dj = 99;
        }

        val1 = new LongInt(val1_ts, val1_dj);
        val2 = new LongInt(ts, dj);
        // *val1 -= *val2;
        LongInt val3 = *val1 - *val2;



        std::string excpected = std::to_string(val1_counter - counter);
        //std::string result = val1->toString();
        std::string result = val3.toString();

        delete val1;
        delete val2;

        if(!result.compare("100")) {
            std::cout << "Stop" << std::endl;
        }

        std::cout << "Expected value " << excpected << std::endl;
        std::cout << "result value " << result << std::endl;
        assert(!excpected.compare(result));

        --dj;
        --counter;
    }
} 

void SubtractionOperator()
{
    int  ts = 99, dj = 99, counter = 9999;

    while (ts != -1)
    {
        if(dj == -1) {
			--ts; dj = 99;
		}

        SubtractionOperatorInnerLoop(ts, dj, counter);

        --dj;
        --counter;
    }


}

void SumOperatorInnerLoop(const int& val1_st, const int& val1_jd, const int&  val1_counter)
{
    int val2_jd = 0, val2_st = 0, val2_counter = 0;
    LongInt* val1;
    LongInt* val2;

    while (val2_st != 100)
    {
        
        if(val2_counter + val1_counter > 9999) {
            break;
        }
        if(val2_jd == 100) {
            ++val2_st; val2_jd = 0;
        }

        val1 = new LongInt(val1_st, val1_jd);
        val2 = new LongInt(val2_st, val2_jd);
        LongInt val3 = *val1 + *val2;

        delete val1;
        delete val2;

        std::string excpected = std::to_string(val2_counter + val1_counter);
        std::string result = val3.toString();

        std::cout << "Expected value " << excpected << std::endl;
        std::cout << "result value " << result << std::endl;
        assert(!excpected.compare(result));

        ++val2_jd;
        ++val2_counter;
    }
}

void SumOperatorTest()
{
    int val1_jd = 10, val1_st = 50, val1_counter = 5010;

    while (val1_st != 100)
    {
        std::cout << "counter 1 is: " << val1_counter << std::endl;
        if(val1_jd == 100) {
			++val1_st; val1_jd = 0;
		}
        
        
        SumOperatorInnerLoop(val1_st, val1_jd, val1_counter);
        ++val1_jd;
        ++val1_counter;
    }
    
}

void toStringTestTest()
{
    int upperLimit = 100;

    int  ts = 0, dj = 0, counter = 0;
    LongInt* val1;
    while(ts != upperLimit)
	{
		if(dj == upperLimit) {
			++ts; dj = 0;
		}

		val1 = new LongInt(ts, dj);
		std:: string value = val1->toString();
		std::string intCounter = std::to_string(counter);

		//std::cout << "jd: " << jd << " st: " << st << std::endl;
		//std::cout << "value: " << value << " intCounter: " << intCounter << std::endl;
		assert(!value.compare(intCounter));
        delete val1;
        
		++dj;
		++counter;
	}
    delete val1;
}



void HomeWork2runner()
{
    //toStringTestTest();
    //SumOperatorTest();
    //SubtractionOperator();
    cinCoutTest();

/*
    LongInt* val1 = new LongInt(1, 70);
    LongInt* val2 = new LongInt("5980");
    *val1 += *val2;
    //std::cout << val1.toString() << std::endl;
	assert(!val1->toString().compare("6150"));
	delete val1; 
	delete val2;
	
	val1 = new LongInt(0, 0);
	val2 = new LongInt("0000");
	*val1 += *val2;
	assert(!val1->toString().compare("0"));
	delete val1; 
	delete val2;
 */
    //foo();
	//std::cout << "p1: " << "repaper" << std::endl;
	//std::cout << "isPalindrom: " << palindrom("repaper") << std::endl;

	//std::cout << "is palidrome: " << palindrom("ala") << std::endl;
	
    //toStringTest();
}