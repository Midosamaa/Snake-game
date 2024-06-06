
#include <stdio.h>
#include <stdbool.h>
#include "clientAPI.h"
#include "snakeAPI.h"
#include "arena.h"
#include "snakes.h"




SNAKE* init_snake1(Arena* arena){
    SNAKE* snake1= malloc(sizeof(SNAKE*));
    snake1->head.x=2;
    snake1->head.y=arena->sizey/2;
    snake1->body=NULL;
    snake1->size=1;
    for (int i=0; i<4; i++){
        arena->grid[snake1->head.x][snake1->head.y].center=1;
    }
    return snake1;
}

SNAKE* init_snake2(Arena* arena){
    SNAKE* snake2= malloc(sizeof(SNAKE*));
    snake2->head.x=arena->sizex-3;
    snake2->head.y=arena->sizey/2;
    snake2->body=NULL;
    snake2->size=1;
    for (int i=0; i<4; i++){
        arena->grid[snake2->head.x][snake2->head.y].center=1;

    }
    return snake2;
}

void free_snake(SNAKE* snake){
    if(snake->body==NULL){
        free(snake);
    }
    else {
        free_snake(snake->body);
    }
}

Arena* update_arena(Arena* arena, SNAKE* snake){
    if (snake->body== NULL){
        arena->grid[snake->head.x][snake->head.y].center=1;
    }
    else{
        update_arena(arena, snake->body);
    }
    return arena;
}

* snake_move_north(Arena* arena, SNAKE* snake){

}



