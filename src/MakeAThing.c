#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

typedef char string[16];
typedef struct{
    char name[16];
    int age;
    float gpa;
    bool fulltime;
}Student;
int random(int min, int max);

void Calc(char op, float n1, float n2){
    if (op == '+') {
        printf("you result is %.1f!", n1 + n2);
    }
    else if (op == '*') {
        printf("you result is %.1f!", n1 * n2);
    }
    else if (op == '/') {
        printf("you result is %.1f!", n1 / n2);
    }
    else if (op == '-') {
        printf("you result is %.1f!", n1 - n2);
    }
}

int main(){
    
    // this is a comment.
    // the statement above me is a comment.
    /*
        this is a loooooong comment
    */
   /*

        Rules of thumb:
            1. Each C scripts need atleast a main function named 'main'
            2. all statements in C ends with a ';'.
            3. for handling singular characters, use '', for an array of characters, use "".
            4. Variables that have been set outside of a function will be a global variable.
            5. C is case-sensitive

        #include:
            #include <>: includes a library (header),
            <stdio.h>: basic input-output header,
            <stdbool.h>: imports the 'bool' variable,
            <string.h>: imports standard string methods;
            <math.h>: imports standard math methods;
            <windows.h>: imports standard windows methods;
            <time.h>: imports standard time methods;
            <stdlib.h>: imports the method of smt i forgot;

        functions:
             ↓ can be void for nill
            variable_returned function_name(parameters) {
                your code here;            
            }
            NOTE: All C scripts needs to have a main function inside of it named "main" (needs to be lowercase)!!!!

            return value; : will return a value when the function called will finish (IT NEEDS TO BE AT THE END OF THE FUNCTION), its also highly suggested that
            in the main function, you return 0 at the end of it.

            variable_returned function_name(parameters); : prototype function, can be set before the main function so the
            main function can call a function that is set after the main one;

        If statements:
            if (condition) {
                run code here;
            }
            else if (other_condition) {
                run code here;
            }
            else {
                run code here;
            }
            The conditions needs to be true for the code inside the if statement to work.

            short hand if statements:
                (condition) ? value_if_true : value_if_false;

        Switch: 
            alternative to if statements,
            switch(variable) {
                case 1:
                    does thing that happens when variable is equal to 1
                    break; <---- to break out of the switch
                case 2:
                    does thing that happens when variable is equal to 2
                    break; <---- to break out of the switch
                default:
                    does thing that happens when neither of the previous cases is equal to the variable
                    (doesnt need a break)
            }

        Relational Operators:
            ==: equal to,
            !=: not equal to,
            >: greater than,
            <: lesser than,
            >=: greater or equal to,
            <=: lesser or equal to,
            &&: AND,
            ||: OR,
            !condition: NOT;

        Variables:
            Numbers and others:
                int: non-decimal value (4 bytes),
                float: decimal or non-decimal value (4 bytes),
                double: like a float, but can store more values (8 bytes),
                bool (needs external header 'stdbool.h'): can store a true or false value (the true value can be 1 and the false value can be 0, 1 byte);
                const: comes before the variable type (ex: const float pi = 3.14;), makes the variable not be able to be overwritten;
            Text:
                char: singular character, (1 byte),
                char varname[]: array of characters (the number of bytes will be equal to the number you put inside the brackets, can be left empty); 
            Extras:
                const: comes before the variable type (ex: const float pi = 3.14;), makes the variable not be able to be overwritten;
                arrays: a variable that can hold more than one value (ex: int list[] = {6, 7, 4, 1}, the "[]" next to the variables name turn the variable into an array);
                    #to get the number of elements inside an array, you can do 'sizeof(array) / sizeof(array[0])',
                    #to have a clear cache of an unasigned array, you set the value of the array to {0},
                    2 dimensional arrays: arrays that can store other arrays, (ex: int numbers[][3] = {{1,2,3}, {4,5,6}, {7,8,9}}; the max number of array in the beginning MUST be set!!!);
                typedef: creates a variable type to simplify complex types by using typedef new_type_name type (ex: typdef string char[16]);
                enums: a created data-type that consist of named integer constants (ex: enum Day{MONDAY=6, TUESDAY=7, WEDNESDAY=4}; enum Day today = TUESDAY (today is now equal to to TUESDAY (7)));


        
        Print:
            printf(""); : outputs a text in the terminal
                \n: jumps a line;
                \0: string terminator;

        User Input:
            scanf("format_specifier", &variable): will take user input and set the result in the variable choosen, (DOESNT SUPPORT SPACES)
            scanf( "format_specifier", &variable): does the same as above, but clears the input buffer beforehand; (DOESNT SUPPORT SPACES)
                getchar(): alternative to above;
            fgets(variable, string_size, stdin): does the same as scanf, but can support spaces :))));

        Format Specifiers:
                %d: parameter for integers,
                %f: parameter for floats (can round up decimals, for example 6.700 printed using %.1f will result to 6.7),
                %lf: parameter for doubles, can also round up like the float parameter,
                %c: parameter for a character,
                %s: parameter for a character table (aka strings, aka 'char varname[];'),
                %d: parameter for booleans (it will result 1 if the bool is true, 0 if not);

        arithmetic operators:
                =: equals,
                +: addition,
                -: subtraction,
                *: multiplication,
                /: division
                %: remainder (modulus),
                var--: will remove 1 from a variable,
                var++: will add 1 to a variable;

        mathematics methods (all requires the standard math library):
                sqrt(number): gives the square root of a specified number,
                pow(number, number2): returns a number to the power of a specified number (number2),
                round(number): rounds a specified number;
                ceil(number): rounds to the highest number;
                floor(number): rounds to the lowest number;
                abs(negative_number): return a negative number into a positive;
                log(number): return the natural logarithm of the number;
                sin(number): return the sine of the number;
                cos(number): return the cosine of the number;
                tan(number): return the tangent of the number;

        while loop:
            function that continue the code inside it while the condition remains true,
            while(condition == true) {
                run code until the condition is false,
            }

            you can also do:
            do{
                run code once before the while loop
            }while(condition == true) --checks the condition then decide to loop the code or not.
                
        for loop:
            repeats a code a certain amount of time,
            for(initialization; condition; update){
                run code
            }
            
            break; will exit out of a for loop, (works for while loop too),
            continue; will skip the current cycle of a for loop, (works for while loop too);

        Sleep: (requires the standard windows or unix library)
            makes the program wait a certain amount of time before continuing,
            Sleep(time); (the time is in miliseconds)

        Structures: an array wich we can store, create or modify certain elements inside of it, (ex: typedef struct{char name[16]; int age; float gpa; bool fulltime}Student)
            Student student1 = {"bob", 19, 3.6, false};

        String funkyness:
                sizeof(varname): gets the length of a character array;
                strlen(varname): gets the length of a character array (requires de string library);
                varname[int] = "character": change a specific character inside of an array of characters, (character 1 = 0, character 2 = 1...);
                strcpy(destination, string): will safely copy a string to a destination including the null-terminator;
                (really usefull for structures since its the only way to change a string inside of the array)
   */
    Student student1 = {"bob", 19, 3.6, false};
    strcpy(student1.name, "bill");
    student1.age = 67;
    printf("%s \n", student1.name);
    float n1;
    float n2;
    char op;
    bool run = false;
    char WRun;
    printf("%d \n", random(41, 67));

    for(int i = 3; i > 0; i--){
        Sleep(1000);
        printf("%d \n", i);
    }

    while(!run) {
        printf("Wanna start? (Y, N): \n");
        scanf(" %c", &WRun);
        if (WRun == 'Y' || WRun == 'y') { 
            run = true;
        }
    }

    printf("lets do math! input first number: ");
    scanf("%f", &n1);
    printf("let put second number: ");
    scanf(" %f", &n2);
    printf("give operator (*, +, -, /): ");
    scanf(" %c", &op);

    Calc(op, n1, n2);

    return 0;
}

int random(int min, int max) {
    srand(time(0));
    int r = (rand() % (max - min + 1)) + min;
    return r;
}