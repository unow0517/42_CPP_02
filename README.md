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
	const Fixed	ret(*this);

	this->value++;
	return (ret);
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


