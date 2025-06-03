#include <iostream>
#include <vector>

template <int nb>
struct Factorial {
    static auto const value = nb * Factorial<nb - 1>::value;
};

template <>
struct Factorial<0> {
    static const int value = 1;
};

template<typename typeX, typename typeY>
class Point {
    typeX _x;
    typeY _y;
public:
    Point(typeX x, typeY y) : _x(x), _y(y) {}

    void print() {
        std::cout << "coordinate (" << _x << ", " << _y << ")" << std::endl;
    }
};

template <typename squareT>
void printSquare(squareT value) {
    std::cout << "The square of " << value << " is " << value * value << std::endl;
}

template<>
void printSquare<char>(char value) {
    std::cout << "It's a char " << value << std::endl;
}

template <typename type, int size=2>
class Array {
    type _myArray[size];
public:
    void set(int index, type value) {
        if (index >= 0 && index < size)
            _myArray[index] = value;
    }

    type get(int index) {
        if (index >= 0 && index < size)
            return _myArray[index];
        return _myArray[0];
    }
};

template <typename sameT>
sameT min(sameT one, sameT two) {
    std::cout << "(with One = " << one << " and two = " << two << ")" << std::endl;
    return (one < two) ? one : two;
}

int main() {
    std::cout << "Exercise 1 : " << std::endl;
    std::cout << "The minus is " << min(7, 4) << std::endl;
    std::cout << "The minus is " << min(0.5, 4.5) << std::endl;
    std::cout << "The minus is " << min('a', 'b') << std::endl;

    std::cout << "Exercise 2 :" << std::endl;
    Array<int, 4> myIntA;
    Array<double> myDoubA;

    myIntA.set(3,3);
    std::cout << "Value at the index 3 is " << myIntA.get(3) << std::endl;

    myDoubA.set(0,1.6);
    std::cout << "Value at the index 0 is " << myDoubA.get(0);

    std::cout << "Exercise 3 :" << std::endl;
    printSquare(4);
    printSquare(3.5);
    printSquare('a');

    std::cout << "Exercise 4:" << std::endl;
    Point<int, int> classic(10, 20);
    classic.print();
    Point<double, int> mixedPoint(10.5, 20);
    mixedPoint.print();

    std::cout << "Exercise 5:" << std::endl;

    std::cout << "Factorial<0> = " << Factorial<0>::value << std::endl;
    std::cout << "Factorial<3> = " << Factorial<3>::value << std::endl;
    std::cout << "Factorial<5> = " << Factorial<5>::value << std::endl;
    return 0;
}
