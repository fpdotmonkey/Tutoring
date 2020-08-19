# C and Pointers

If you've written code in C before, you've probably seen a bit of code that looks like this.  

```c
#include <stdio.h>

void quotient_and_remainder(int dividend, int divisor,
                            int *quotient, int *remainder) {
    *quotient = dividend / divisor;
    *remainder = dividend % divisor;
}

void print_apples_per_person(int number_of_apples, int number_of_people) {
    int apples_per_person = 0;
    int apples_left_over = 0;

    quotient_and_remainder(number_of_apples, number_of_people,
                           &apples_per_person, &apples_left_over);

    printf("There are %i apples for each person with %i left over\n",
           apples_per_person,
           apples_left_over);
}

int main(int argc, char **argv) {
    int number_of_apples = 11;
    int number_of_people = 4;

    print_apples_per_person(number_of_apples, number_of_people);
}
```

Why on earth does `&apples_per_person` have an `&`?  And why does `quotient_and_remainder` take `*quotient` as an argument instead of just `quotient`?

Setting that aside for a moment, imagine COVID is over and you're back in class with your friends.  You see a funny picture on your phone and you want to share it with your friend.  You could share it two ways; you could DM it to them, or you could physically pass your phone over.  Either way, your friend sees it and decides it could be improved by added a mustache to one of the people in the picture.  If you DM'ed your friend the picture, you will never see how funny the mustache is unless your friend shows you.  On the other hand, if you handed them your phone, you will see the mustache if you look at the picture again.

What happened between you and your friend when you gave them your phone is a lot like what's going in `quotient_and_remainder`.  The arguments `int dividend` and `int divisor` are both saying to "DM" the function those arguments; you don't need to see what the function is doing to them.  But by adding a `*`, like in `int *quotient` or `int *remainder`, the function is saying to pass it *your* copy of `quotient` and `remainder` (you can also write it `int* quotient` where the `*` is next to the type).

When you pass an argument in the "DM" sense, it's called *pass by value* because you're passing only a copy of the variable, not the instance you have.  When you include a `*` so that the function gets your copy, this is called *pass by pointer*.  The name *pointer* comes from the fact that you're technically not passing your copy of variable itself, but where it's located.  That it, you're *pointing* to where the variable is located.

Using this technique of passing by pointer is very similar to passing by value; you just need to add a marker indicating to the compiler that you're passing by pointer.  In a function argument, you just add a `*` before your argument name, for example `void f(int *x)`.  Then when you call that function, you need to tell the it where your copy of `x` is located, which is called it *address*.  How addresses work is a story for another time, but in short, it's a number saying where in your computer's RAM your variable is located.  You get the address for a variable by adding `&` as a prefix.  So you can call the function like this.

```c
int x = 0;
f(&x);
```

Passing by pointer is useful mostly in two cases (though there are certainly other applications).  One is when you want to have a function that returns multiple numbers (this is what was done for `quotient_and_remainder`).  Instead of using the `return` keyword, you can pass in the variables you want to take on the value of the "returns" by pointer, and by running the function, their value will change.

The other more advanced use case is pass large objects by pointer.  This lets you use a single instance of a large object for many functions.  If you had many instances of the large object, you could run out of computer memory, severely hampering the performance of your application.  You'll learn more about this application when you learn about `struct`s.

If you'd like to review this topic, my notes are available [here](https://github.com/fpdotmonkey/Tutoring/blob/master/pass_by_pointer/c_and_pointers.md) alongside the example from the beginning, which you can run following the instructions [here](https://github.com/fpdotmonkey/Tutoring/blob/master/pass_by_pointer/README.md).
