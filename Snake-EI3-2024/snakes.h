#ifndef SNAKES_H_NOT_DEFINED
#define SNAKES_H_NOT_DEFINED

#include "clientAPI.h"
#include "snakeAPI.h"
#include "arena.h"

//structures used to make the snakes
typedef struct POSITION POSITION;
typedef struct SNAKE SNAKE;

struct POSITION{
    int x;
    int y;
};

struct SNAKE{
    POSITION head;
    SNAKE *body;
    int size;
};

SNAKE* init_snake1(Arena* arena);
SNAKE* init_snake2(Arena* arena);
void free_snake(SNAKE* snake);

#endif

