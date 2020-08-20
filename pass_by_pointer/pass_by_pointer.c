

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
