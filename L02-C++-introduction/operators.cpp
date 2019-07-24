#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>

struct LongInt {
private:
  bool isLessThan100() const { return left == 0; }

  bool makeDecimalNumber0() const { return left != 0 && right < 10; }

public:
  // Constructor
  LongInt(int left, int right) : left(left), right(right) {}

  // Constructor
  LongInt(std::string str) {
    int number = std::stoi(str);
    left = number / 100;
    right = number % 100;
  }

  // Copy constructor
  LongInt(const LongInt &other) {
    left = other.left;
    right = other.right;
  }

  // Destructor
  ~LongInt() {}// std::cout << "Delete " << toString() << std::endl; }

  // Method
  std::string toString() {
    if (isLessThan100())
      return std::to_string(right);

    if (makeDecimalNumber0())
      return std::to_string(left) + "0" + std::to_string(right);

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

    //Operator
    void operator-=(const LongInt& r)
    {
        left -= r.left;
        right -= r.right;
        if (right < 0)
        {
            right += 100;
            left--;
        }
    }

    //Operator
    LongInt operator-(const LongInt& r)
    {
        LongInt retVal = *this;
        retVal -= r;      
        return retVal;
    }

    //Operator
    LongInt operator+(const LongInt& r)
    {
        LongInt retVal = *this;
        retVal += r;      
        return retVal;
    }

    //Copy operator
    LongInt& operator=(const LongInt& other)
    {
        left = other.left;
        right = other.right;
        return *this;
    }
  // Members
  int left;
  int right;
};

int main() {

    LongInt val1("368"), val2("1571"), val3("000000");

    val3 = val1 + val2;  // check add operator         1939
    std::cout << val3.toString() << std::endl;
  
    val3 = val2 - val1;  // check sub operator         1203
    std::cout << val3.toString() << std::endl;

    val2 -= val1;  // check suboverload operator       1203
    std::cout << val2.toString() << std::endl;

}