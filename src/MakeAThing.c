#include <stdio.h>
#include <stdbool.h>
int main(){
    
    // this is a comment.
    // the statement above me is a comment.
    /*
        this is a loooooong comment
    */
   /*
        #include:
            #include <>: includes a library (header),
            <stdio.h>: basic input-output header,
            <stdbool.h>: imports the 'bool' variable;

        functions:
            variable_returned function_name(parameters) {
                your code here;            
            }
            NOTE: All C scripts needs to have a main function inside of it named "main" (needs to be lowercase)!!!!

            return value; : will return a value when the function called will finish (IT NEEDS TO BE AT THE END OF THE FUNCTION), its also highly suggested that
            in the main function, you return 0 at the end of it.
        
        Variables:
            Numbers:
                int: non-decimal value (4 bytes),
                float: decimal or non-decimal value (4 bytes),
                double: like a float, but can store more values (8 bytes),
                bool (needs external header 'stdbool.h'): can store a true or false value (the true value can be 1 and the false value can be 0, 1 byte);
            Text:
                char: singular character, (1 byte),
                char varname[]: array of characters (the number of bytes will be equal to the number you put inside the brackets, can be left empty); 
                    sizeof(varname): gets the length of the character array;
        
        Print:
            printf(""); : outputs a text in the terminal
                \n: jumps a line;

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
                

   */
    int age = 67;
    float n = 6.7;
    
    printf("joke\n");
    printf("The statement above me is a joke. \n");
    printf("I am %d years old \n", age);
    printf("your grade is maybe like %.1f", n);
    return 0;
}