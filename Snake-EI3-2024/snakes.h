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
    int turn;
    int size;
};

t_move button_to_move(char*);
SNAKE* init_snake1(Arena* arena);
SNAKE* init_snake2(Arena* arena);
void free_snake(SNAKE* snake);

Arena* update_arena(Arena* arena, SNAKE* snake);

SNAKE* snake_move_north(Arena* arena, SNAKE* snake);
SNAKE* snake_move_east(Arena* arena, SNAKE* snake);
SNAKE* snake_move_south(Arena* arena, SNAKE* snake);
SNAKE* snake_move_west(Arena* arena, SNAKE* snake);

t_move AI_move(Arena* arena, SNAKE** snake);

#endif

