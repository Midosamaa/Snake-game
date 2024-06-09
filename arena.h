#ifndef ARENA_H_NOT_DEFINED
#define ARENA_H_NOT_DEFINED

#include "clientAPI.h"
#include "snakeAPI.h"
#include "arena.h"

//structures used to make the arena
typedef struct Cell Cell;
typedef struct Arena Arena;

struct Cell{
    int borders[4]; // {0, 0, 0, 0};
    // NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3
    int x;
    int y;

    int center;
    int visited_up;
    int visited_left;
    int visited_down;
    int visited_right;
    int access;
};

struct Arena{
    int sizex;
    int sizey;
    Cell** grid;
};

//prototypes of the functions
void init_cell(Cell* cell);
Arena* get_arena(int* sizeX, int* sizeY, int* nbWalls, int *walls);
void print_arena(Arena* arena);
void free_arena(Arena *arena);

#endif