#ifndef SNAKES_H_NOT_DEFINED
#define SNAKES_H_NOT_DEFINED

#include "clientAPI.h"
#include "snakeAPI.h"
#include "arena.h"
#include "snakes.h"

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
    t_move direction;
};

t_move button_to_move(char*);
SNAKE* init_snake1(Arena* arena);
SNAKE* init_snake2(Arena* arena);
void free_snake(SNAKE* snake);



SNAKE* snake_move_north(Arena* arena, SNAKE* snake);
SNAKE* snake_move_east(Arena* arena, SNAKE* snake);
SNAKE* snake_move_south(Arena* arena, SNAKE* snake);
SNAKE* snake_move_west(Arena* arena, SNAKE* snake);

t_move AI_move(Arena* arena, SNAKE** snake);


t_move f_AI_move(Arena* arena, SNAKE** snake);


int is_within_bounds(Arena* arena, int x, int y);
int calculate_score(Arena* arena, SNAKE* snake, t_move move);
int will_collide_with_snake(Arena* arena, SNAKE* snake, t_move move);
int will_collide_with_wall(Arena* arena, SNAKE* snake, t_move move);

int max_4(int a, int b, int c, int d);
int max_access(Arena* arena, int x, int y);
t_move new_strat(Arena* arena, SNAKE** snake);
void longest_path(Arena* arena, int x, int y);
void mark_adj_cell(Arena*arena, int x, int y);
void cell_access(Arena*arena, int x, int y, SNAKE* snake);
#endif


