#include <stdio.h>
#include <stdbool.h>
#include "clientAPI.h"
#include "snakeAPI.h"
#include "arena.h"

void init_cell(Cell* cell) {
    for (int i = 0; i < 4; i++) {
        cell->borders[i] = 0;
    }
    cell->center=0;
}

Arena* get_arena(int* sizeX, int* sizeY, int* nbWalls, int *walls) {
    // Allocate memory for the arena
    Arena *arena = (Arena*) malloc(sizeof(Arena));
    if (arena == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    arena->sizex = *sizeX;
    arena->sizey = *sizeY;

    // Allocate memory for the grid
    arena->grid = (Cell**) malloc(arena->sizex * sizeof(Cell*));
    if (arena->grid == NULL) {
        fprintf(stderr, "Memory allocation for grid failed\n");
        free(arena);
        return NULL;
    }

    for (int i = 0; i < arena->sizex; i++) {
        arena->grid[i] = (Cell*) malloc(arena->sizey * sizeof(Cell));
        if (arena->grid[i] == NULL) {
            fprintf(stderr, "Memory allocation for grid row failed\n");
            for (int j = 0; j < i; j++) {
                free(arena->grid[j]);
            }
            free(arena->grid);
            free(arena);
            return NULL;
        }
    }
    // Initialize cells and set borders
    for (int i = 0; i < arena->sizex; i++) {
        for (int j = 0; j < arena->sizey; j++) {
            init_cell(&arena->grid[i][j]);

            // Set borders around the edges of the arena
            if (i == 0) arena->grid[i][j].borders[3] = 1; // WEST border
            if (i == (arena->sizex -1)) arena->grid[i][j].borders[1] = 1; // EAST border
            if (j == 0) arena->grid[i][j].borders[0] = 1; // NORTH border
            if (j == (arena->sizey -1)) arena->grid[i][j].borders[2] = 1; // SOUTH border

            // Set coordinates of each Cell
            arena->grid[i][j].x = i;
            arena->grid[i][j].y = j;
        }
    }

    // Place walls according to the walls array
    for (int i = 0; i < 4 * (*nbWalls); i += 4) {
        if (walls[i+1] == walls[i+3]) {
            if(walls[i+1]==walls[i+3] +1){
                arena->grid[walls[i]][walls[i+1]].borders[1] = 1;
                arena->grid[walls[i+2]][walls[i+3]].borders[3] = 1;
            }
            else {
                arena->grid[walls[i]][walls[i+1]].borders[3] = 1;
                arena->grid[walls[i+2]][walls[i+3]].borders[1] = 1;
            }
        }
               
        if (walls[i] == walls[i+2]) {
            if(walls[i]==walls[i+2] +1){
                arena->grid[walls[i]][walls[i+1]].borders[2] = 1;
                arena->grid[walls[i+2]][walls[i+3]].borders[0] = 1;
            }
            else {
                arena->grid[walls[i]][walls[i+1]].borders[0] = 1;
                arena->grid[walls[i+2]][walls[i+3]].borders[2] = 1;
            }
        }
        
    }

    return arena;
}

void print_arena(Arena* arena) {
    printf("x=%d y=%d\n", arena->sizex, arena->sizey);
       // Print top border
    printf(" ");
    for (int j = 0; j < arena->sizey; j++) {
        printf("._");
    }
    printf(".\n");

    for (int i = 0; i < arena->sizex; i++) {
        // Print left border and cell contents
        for (int j = 0; j < arena->sizey; j++) {
            if (j == 0) {
                printf("|");
            }
            printf(arena->grid[i][j].borders[2] ? "_" : " ");
            printf(arena->grid[i][j].borders[1] ? "|" : ".");
        }
        printf("|\n");
    }
    printf(" ");
    for (int j = 0; j < arena->sizey; j++) {
        printf("._");
    }
    printf(".\n");
    printf("x=%d, y-%d\n", arena->sizex, arena->sizey);
    for (int i = 0; i < arena->sizex ; i++) {
        // Print left border and cell contents
        for (int j = 0; j < arena->sizey; j++) {
            printf("coord: (%d, %d) : ", arena->grid[i][j].x, arena->grid[i][j].y);
            printf("[%d, %d, %d, %d] : %d\n", arena->grid[i][j].borders[0], arena->grid[i][j].borders[1], arena->grid[i][j].borders[2], arena->grid[i][j].borders[3], arena->grid[i][j].center);
        }
    }
}
void free_arena(Arena *arena) {
    if (arena != NULL) {
        for (int i = 0; i < arena->sizex; i++) {
            free(arena->grid[i]);
        }
        free(arena->grid);
        free(arena);
    }
}
