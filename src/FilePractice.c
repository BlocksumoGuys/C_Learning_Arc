#include <stdio.h>

int main() {
    FILE *file = fopen("out.txt", "r");
    //fprintf(file, "%s", "lololo happi");
    char buffer[1024] = {0};
    fgets(buffer, sizeof(buffer), file);
    printf("%s", buffer);
    fclose(file);
    return 0;
}