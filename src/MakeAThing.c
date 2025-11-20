#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

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

        #include:
            #include <>: includes a library (header),
            <stdio.h>: basic input-output header,
            <stdbool.h>: imports the 'bool' variable,
            <string.h>: imports standard string methods;
            <math.h>: imports standard math methods

        functions:
             ↓ can be void for nill
            variable_returned function_name(parameters) {
                your code here;            
            }
            NOTE: All C scripts needs to have a main function inside of it named "main" (needs to be lowercase)!!!!

            return value; : will return a value when the function called will finish (IT NEEDS TO BE AT THE END OF THE FUNCTION), its also highly suggested that
            in the main function, you return 0 at the end of it.

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
                    sizeof(varname): gets the length of a character array;
                    strlen(varname): gets the length of a character array (requires de string library);
                    varname[int] = "character": change a specific character inside of an array of characters, (character 1 = 0, character 2 = 1...);    
        
        Print:
            printf(""); : outputs a text in the terminal
                \n: jumps a line;
                \0: removes the jump of line;

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

        mathematics methods (requires the standard math library):
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
                

   */
    float n1;
    float n2;
    char op;
    printf("lets do math! input first number: ");
    scanf("%f", &n1);
    printf("let put second number: ");
    scanf(" %f", &n2);
    printf("give operator (*, +, -, /): ");
    scanf(" %c", &op);

    Calc(op, n1, n2);

    return 0;
}