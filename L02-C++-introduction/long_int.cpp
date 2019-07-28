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

    //default constructor
    LongInt() = default;
    
    //Copy constructor
    LongInt(const LongInt& other) = default;

    //Destructor
    ~LongInt()
    {
      //  std::cout << "Delete " << toString() << std::endl;
    }

    //Method
    std::string toString()
    {
        std::string temp {0};

        if (left == 0)
        {
            temp = std::to_string(right);
        }
        else if (right < 10)
        {
            temp = std::to_string(left) + "0" + std::to_string(right);
        }
        else
        {
            temp = std::to_string(left) + std::to_string(right);
        }

        return temp;
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

    LongInt operator+(const LongInt& r)
    {
        LongInt ret;
        ret.right = this->right + r.right;
        ret.left = this->left + r.left;
        ret.left += ret.right / 100;
        ret.right = ret.right % 100;
        return ret;
    }

    LongInt operator-(const LongInt& r)
    {
        LongInt ret;
        
        if ((this->right < r.right) && (this->left > 0))
        {
            this->left--;
            this->right += 100;
        }        
        ret.right = this->right - r.right;
        ret.left = this->left - r.left;
        return ret;
    }

    void operator-=(const LongInt& r)
    {
            
        if ((right < r.right) && (left > 0))
        {
            left--;
            right += 100;
        }        
        right = right - r.right;
        left = left - r.left;
    }

    friend std::ostream &operator<< (std::ostream &output, const LongInt &r) 
    {
        LongInt temp(r); 
        output << temp.toString();
        return output;          
    }

    friend std::istream &operator>> (std::istream  &input, LongInt &r) 
    { 
        int number;
        input >> number;

        r.left = number / 100;
        r.right = number % 100;
        return input;            
    }

    //Members
    int left;
    int right;
};

int main()
{
    LongInt val1(1, 70);
    LongInt val2("5980");

    val1 += val2;
    std::cout << val1.toString() << std::endl;

    LongInt val4("0");
    LongInt val5(0, 0);
    LongInt val6("10");
    LongInt val7(0, 10);
    LongInt val8("3001");
    LongInt val9(30, 1);

    // std::cout << val4.toString() << std::endl;
    // std::cout << val5.toString() << std::endl;
    // std::cout << val6.toString() << std::endl;
    // std::cout << val7.toString() << std::endl;
    // std::cout << val8.toString() << std::endl;
    // std::cout << val9.toString() << std::endl;

    LongInt val3(val2);
    std::cout << val3.toString() << std::endl;

    LongInt val10 = val2 + val6; //5990
    std::cout << val10.toString() << std::endl;

    val1 = val9 - val7;
    std::cout << val1.toString() << std::endl;  //2991
    val1 = val5 - val7;
    std::cout << val1.toString() << std::endl;  //-10
    val1 = val2 - val6;
    std::cout << val1.toString() << std::endl;  //5970

    val1 = val6 - val8;
    std::cout << val1.toString() << std::endl;  //left substract doesn't work properly (should be 2991, but is -3009) -> to be fixed

    val9 -= val7;
    std::cout << val9 << std::endl;  //2991
    val5 -= val7;
    std::cout << val5 << std::endl;  //-10
    val2 -= val6;
    std::cout << val2 << std::endl;  //5970

    std::cout << "Please type a number" << std::endl;
    std::cin >> val2;
    std::cout << "Your number: " << val2 << std::endl;  //5970



    return 0;
}