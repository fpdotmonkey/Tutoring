# C and Pointers

Today we're going to learn about what a pointer is in C, how to use them, and when they're useful.

If you've gotten stuck on a C programming problem before and searched for an answer, you've maybe seen a bit of code like this.

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
Notice all the `&`s and `*`s.  What do they mean, what are they for, why does an argument say `*` when what gets inputted says `&`? 

Setting aside these questions for a minute, I want you to imagine with me that COVID is over and you're back in class with all your friends.  You see a funny picture on your phone and you want to share it with your friend Morgan.  You could share it two ways; you could DM it to them, or you could physically pass your phone over.  Either way, Morgan sees the picture and decides it could be improved by drawing a mustache onto one of the people in the picture.  If you DM'ed them the picture, you will never see how funny the mustache is unless Morgan shows you.  On the other hand, if you handed them your phone, you will see the mustache when you look at the picture again.

What happened between you and Morgan is very similar to what's going on in `quotient_and_remainder`.  The arguments `int dividend` and `int divisor` are both saying to "DM" to the function those arguments; you don't need to see what the function is doing to them.  But by adding a `*`, like in `int *quotient` or `int *remainder`, the function is saying to pass it *your* copy of `quotient` and `remainder`.

When you pass an argument in the "DM" sense, it's called *pass by value* because you're passing only a copy of the variable, not the instance you have.  When you include a `*` in the argument, the function gets your copy; this is called *pass by pointer*.  The name *pointer* comes from the fact that you're actually not passing your copy of variable itself, but the location of the variable on your computer.  That is, you're *pointing* to where the variable is located.

Executing this technique of passing by pointer is similar to passing by value; you just need to add a prefix indicating to the compiler that you're passing by pointer.  In a function argument, you add a `*` before your argument name, for example `void f(int *x)` (you can also write it `int* x` where the `*` is next to the type).  Then when you call that function, you give it where your copy of `x` is located, which is called its *address*.  How addresses work is a story for another time, but in short, it's a number saying where in your computer's RAM your variable is located.  You get the address for a variable by adding `&` as a prefix.  So you can call the function like this.

```c
void f(int *x) { /* do stuff */ }
int x = 0;
f(&x);  // &x is where x is located in memory
// x has changed
```

Passing by pointer is useful mostly in two cases (though there are certainly other applications).  One is when you want to have a function that returns multiple numbers (this is what was done for `quotient_and_remainder` where the quotient and the remainder from a division are returned).  Instead of using the `return` keyword, you can pass in the variables you want to take on returned value, and by running the function, their values will change.

The other more advanced use case is passing large objects by pointer.  This lets you use a single instance of a large object for many functions.  If you had many instances of the large object, you could run out of computer memory, severely hampering the performance of your application.  You'll learn more about this use case when you learn about `struct`s.

If you'd like to review this topic, my notes are available [here](https://github.com/fpdotmonkey/Tutoring/blob/master/pass_by_pointer/c_and_pointers.md) alongside the example from the beginning, which you can run following the instructions [here](https://github.com/fpdotmonkey/Tutoring/blob/master/pass_by_pointer/README.md).
