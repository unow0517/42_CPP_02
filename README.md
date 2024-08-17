# 42_CPP_02
classes in Orthodox Canonical Form? -> The classes must have Default Constructor, Copy Constructor, Copy Assignment Constructor, Destructor.

make a class which saves a number in [Fixed Point Numbers](https://web.archive.org/web/20231224143018/https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html) type.
It seems like 16 bits are used to store the number in this project(8bits for integer, 8bits for fractional part), because integer to store the number of fractional bits are always 8.

c++ can compare `10` and `42.42`, but we still do this practice to learn about fixed point numbers.

## What I Learn
### Fixed Point Numbers
A way of representing fractal numbers with a fixed number of digits after the decimal point.
### Overloading 
```c++
// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to add three integers
int add(int a, int b, int c) {
    return a + b + c;
}

// Function to add two doubles
double add(double a, double b) {
    return a + b;
}
```
"overload" refers to a feature that allows you to define **multiple functions or operators with the same name but different parameters**. 


### `const` in function
```c++
int Fixed::getRawBits( void ) const
{
	return fpval;
}
```
The const after getRawBits( void ) means that getRawBits will not modify any member variables of the Fixed class and is safe to call on const instances of Fixed.

### `this`
```c++
void Fixed::setRawBits( int const raw)
{
	this->fpval = raw;
}
```

```c++
void Fixed::setRawBits( int const raw)
{
	fpval = raw;
}
```

`this` is not neccessary to have in the member function in class, but it removes ambuiguity.<br/>

### How `Int` and `Float` are saved in the class here.
In *ex01*, we save value `10` and `42.42`. the numbers should be bitwise shift by the value of fractional bits.

10<sub>10</sub> << 8 = 1010<sub>2</sub> << 8 = 1010 0000 0000 = 2560<sub>10</sub>

42.42<sub>10</sub> << 8 = ... 42.42 x 256  = 10878.72<sub>10</sub> -> round off -> 10879

those values will be saved in the class, and with `toInt` and `toFloat` the values will be re-converted to decimal version.


### Static member function in a class
static member function belongs to a class not to an object. it can be called without an object is made.

### Changing value even with `const`?

```c++
const Fixed	Fixed::operator++(int)
{
	const Fixed	ret(*this); //copy this object 

	this->value++; //increase this value
	return (ret); //return copied object
}
```

in the code above, the object `ret` is `const`ed, not to the member of the object `ret`.

to 'constify' all the member, do below:

```c++
const Fixed	Fixed::operator++(int) const
{
	const Fixed	ret(*this);

	this->value++; // this throws error, because of last const keyword in function name
	return (ret);
}
```

The int parameter is part of the **C++ language design to distinguish post-increment from pre-increment**. The pre-increment operator does not need such a parameter, and adding one would cause ambiguity in the function signatures, conflicting with the intended use of post-increment. Hence, in C++, you cannot use an int parameter for pre-increment.

### lvalue vs rvalue 

```c++
int x = 5;     // Here, `x` is an lvalue and `5` is an rvalue.
x = 10;        // `x` is an lvalue; `10` is an rvalue.
int* ptr = &x; // `&x` is an lvalue (address of x) and `ptr` is an lvalue.

int y = x + 2; // `x + 2` is an rvalue; `y` is an lvalue.
```
* lvalue : An lvalue refers to an object that occupies some identifiable location in memory (i.e., it has an address). Lvalues are typically variables or objects that you can take the address of.
* rvalue : An rvalue is a temporary value that does not have a persistent memory address. Rvalues are often literals or results of operations that do not refer to a specific location in memory.

Lvalues can be assigned to, rvalues cannot. You can take the address of an lvalue (e.g., using &x), but not of an rvalue.

### &
still confusing, so putting together again.

**1.Address-of Operator**
```c++
int x = 10;
int* ptr = &x;  // &x gets the address of the lvalue `x`.
```
ptr = address of x, *ptr = 10.

**2.Reference Declaration**

```c++
int x = 10;
int& ref = x;  // `ref' IS AN REFERENCE TO INTEGER, AND THE INTEGER IS `x`.
```
ref = 10, address of ref = address of x (lvalue reference)


```c++
int&& rref = 10;  // `rref` is an rvalue reference to the temporary `10`.
```
rref = 10; rref is an rvalue reference that can bind to temporary values or expressions. (rvalue reference)

**3.
