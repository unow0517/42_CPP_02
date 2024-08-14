# 42_CPP_02
classes in Orthodox Canonical Form? -> The classes must have Default Constructor, Copy Constructor, Copy Assignment Constructor, Destructor.

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

## `this`
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

`this` is not neccessary to have in the member function in class, but it removes ambuiguity.
