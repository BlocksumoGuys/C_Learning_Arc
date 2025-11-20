#include <stdio.h>
typedef enum{
    SUCCESS, FAILURE, PENDING
}Status;

void Connection(Status stat);

int main() {

    Connection(SUCCESS);
    return 0;
}

void Connection(Status stat) {
    switch (stat)
    {
    case SUCCESS:
        printf("Success!");
        break;
    case FAILURE:
        printf("Failure!");
        break;
    case PENDING:
        printf("In pending!");
        break;
    default:
        printf("ERROR!");
        break;
    }
}