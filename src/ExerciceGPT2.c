#include <stdio.h>
#include <stdlib.h>

typedef struct Enemy {
    int hp;
    float x;
    void (*update)(struct Enemy*); // function pointer for behavior
} Enemy;

void Patrol(Enemy* e);
void Attack(Enemy* e);
void Die(Enemy* e);

int main(){
    Enemy *e = malloc(sizeof(Enemy));
    if (e == NULL){
        return 1;
    }
    e->hp = 3;
    e->x = 0;
    Patrol(e);
    e->update(e);
    e->update(e);
    Attack(e);
    for (int i=1; i<=5; i++){
        e->update(e);
    }
    if (e->update == NULL){
        printf("The enemy is CONFIRMED DEAD!");
    }
    free(e);
    return 0;
}

void Patrol(Enemy* e){
    e->x++;
    e->update = Patrol;
    printf("Patrolling: x=%f \n", e->x);
}

void Attack(Enemy* e){
    e->hp--;
    if (e->hp <= 0) {
        e->update = Die;
    }
    else {
        printf("Attacking: hp=%d \n", e->hp);
        e->update = Attack;
    }
}

void Die(Enemy* e){
    printf("Enemy is dead! \n");
    e->update = NULL;
}



