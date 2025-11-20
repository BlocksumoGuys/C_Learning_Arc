#include <stdio.h>

void bday(int* age){
    (*age)++;
}

int main() {
    int age = 25;
    int *pAge = &age;
    bday(pAge);
    printf("you are %d years old", age);
    return 0;
}