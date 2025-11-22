#include <stdio.h>
#include <stdlib.h>

struct Vector2
{
    float x;
    float y;
}Vector2;

struct Vector2* createVector(float X, float Y){
    struct Vector2 *new;
    new->x = X;
    new->y = Y;
    new = malloc(4 * sizeof(float));
    return new;
}

void printVector(struct Vector2* obj){
    printf("x=%f, y=%f \n", obj->x, obj->y);
}

void move(struct Vector2 *obj, float dx, float dy){
    obj->x += dx;
    obj->y += dy;
}



int main(){
    struct Vector2* v = createVector(0, 0);
    move(v, 3, 4);
    printVector(v);
    move(v, -1, 2);
    printVector(v);
    free(v);
    return 0;
}


