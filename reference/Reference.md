# Reference

## what is reference?

Reference is a safer way to use pointer.
It is better to use reference when there is no direct operaiton like +, - on pointer.

- Refernece is an alias to an already existing variable.
- A reference can not be NULL.
- A refernece must be initialized when it is created.
- Once a reference is initialized, it cannot be changed to point another object.

    int number1 = 10;
    int number2 = 20;
    int& ref = number1;
    ref = number2; 
    cout << number1 << "," << ref << ", " << number2 << endl; //20, 20, 20 

- When code converted to an assmbly-language, there are no differneces between pointer and reference. Reference is based on a language level support that limit some possibilities from pointer.