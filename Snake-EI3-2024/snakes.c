
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "clientAPI.h"
#include "snakeAPI.h"
#include "arena.h"
#include "snakes.h"


t_move button_to_move(char *button){
    if(*button == 'w'){
        printf("QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQC IIII8B move 0\n");
        return (NORTH);
    }
    else if(*button == 'd'){
        printf("QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQC IIII8B move 1\n");
        return (EAST);
    }
    else if(*button == 's'){
        printf("QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQC IIII8B move 2\n");
        return (SOUTH);
    }
    else if(*button == 'a'){
        printf("QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQC IIII8B move 3\n");
        return (WEST);
    }

    else {
        printf("ADAKL7MARWASD\n");
    }
}

// Initialize snake1
SNAKE* init_snake1(Arena* arena){
    SNAKE* snake1 = (SNAKE*)malloc(sizeof(SNAKE));
    if (snake1 == NULL) {
        printf("Memory allocation failed for snake1\n");
        return NULL;
    }
    snake1->head.x = 2;
    snake1->head.y = arena->sizey / 2;
    snake1->body = NULL;
    snake1->turn = 1;
    snake1->size = 1;
    arena->grid[snake1->head.x][snake1->head.y].center = 1;
    return snake1;
}

// Initialize snake2
SNAKE* init_snake2(Arena* arena){
    SNAKE* snake2 = (SNAKE*)malloc(sizeof(SNAKE));
    if (snake2 == NULL) {
        printf("Memory allocation failed for snake2\n");
        return NULL;
    }
    snake2->head.x = arena->sizex - 3;
    snake2->head.y = arena->sizey / 2;
    snake2->body = NULL;
    snake2->turn = 1;
    snake2->size = 1;
    arena->grid[snake2->head.x][snake2->head.y].center = 1;
    return snake2;
}

// Free snake function
void free_snake(SNAKE* snake){
    SNAKE* current = snake;
    SNAKE* next;
    while (current != NULL) {
        next = current->body;
        free(current);
        current = next;
    }
}

// Arena* update_arena(Arena* arena, SNAKE* snake){
//     if (snake->body== NULL){
//         arena->grid[snake->head.x][snake->head.y].center=1;
//     }
//     else{
//         arena=update_arena(arena, snake->body);
//     }
//     return arena;
// }


SNAKE *snake_move_north(Arena *arena, SNAKE *snake) {
    // Allocate a new node for the new head
    SNAKE *new_snake = (SNAKE *)malloc(sizeof(SNAKE));
    if (new_snake == NULL) {
        printf("Memory allocation failed for new snake segment\n");
        return snake;
    }

    new_snake->head.x = snake->head.x;
    new_snake->head.y = snake->head.y - 1; // Move north
    new_snake->body = snake;
    new_snake->turn = snake->turn + 1;
    new_snake->size = snake->size;

    // Update the arena grid with the new head position
    arena->grid[new_snake->head.x][new_snake->head.y].center = 1;

    if (new_snake->turn % 10 == 0) {
        // Increase snake size every 10 turns
        new_snake->size += 1;
    } else {
        // Remove the tail segment from the arena and free the memory
        SNAKE *current = new_snake;
        SNAKE *previous = NULL;

        // Traverse to the last node
        while (current->body != NULL) {
            previous = current;
            current = current->body;
        }

        if (previous != NULL) {
            previous->body = NULL;
            // Update the arena grid to remove the tail segment
            arena->grid[current->head.x][current->head.y].center = 0;
            free(current);
        }
    }

    // Update the arena grid for the body segments
    SNAKE *temp = new_snake->body;
    while (temp != NULL) {
        arena->grid[temp->head.x][temp->head.y].center = 1;
        temp = temp->body;
    }

    return new_snake;
}

SNAKE* snake_move_east(Arena* arena, SNAKE* snake) {
    // Allocate a new node for the new head
    SNAKE* new_snake = (SNAKE*)malloc(sizeof(SNAKE));
    if (new_snake == NULL) {
        printf("Memory allocation failed for new snake segment\n");
        return snake;
    }

    new_snake->head.x = snake->head.x + 1;
    new_snake->head.y = snake->head.y;
    new_snake->body = snake;
    new_snake->turn = snake->turn + 1;
    new_snake->size = snake->size;

    // Update the arena grid with the new head position
    arena->grid[new_snake->head.x][new_snake->head.y].center = 1;

    if (new_snake->turn % 10 == 0) {
        // Increase snake size every 10 turns
        new_snake->size += 1;
    } else {
        // Remove the tail segment from the arena and free the memory
        SNAKE *current = new_snake;
        SNAKE *previous = NULL;

        // Traverse to the last node
        while (current->body != NULL) {
            previous = current;
            current = current->body;
        }

        if (previous != NULL) {
            previous->body = NULL;
            // Update the arena grid to remove the tail segment
            arena->grid[current->head.x][current->head.y].center = 0;
            free(current);
        }
    }

    // Update the arena grid for the body segments
    SNAKE *temp = new_snake->body;
    while (temp != NULL) {
        arena->grid[temp->head.x][temp->head.y].center = 1;
        temp = temp->body;
    }

    return new_snake;
}

SNAKE* snake_move_south(Arena* arena, SNAKE* snake) {
    SNAKE* new_snake = (SNAKE*)malloc(sizeof(SNAKE));
    if (new_snake == NULL) {
        printf("Memory allocation failed for new snake segment\n");
        return snake;
    }

    new_snake->head.x = snake->head.x;
    new_snake->head.y = snake->head.y + 1;
    new_snake->body = snake;
    new_snake->turn = snake->turn + 1;
    new_snake->size = snake->size;

    // Update the arena grid with the new head position
    arena->grid[new_snake->head.x][new_snake->head.y].center = 1;

    if (new_snake->turn % 10 == 0) {
        // Increase snake size every 10 turns
        new_snake->size += 1;
    } else {
        // Remove the tail segment from the arena and free the memory
        SNAKE *current = new_snake;
        SNAKE *previous = NULL;

        // Traverse to the last node
        while (current->body != NULL) {
            previous = current;
            current = current->body;
        }

        if (previous != NULL) {
            previous->body = NULL;
            // Update the arena grid to remove the tail segment
            arena->grid[current->head.x][current->head.y].center = 0;
            free(current);
        }
    }

    // Update the arena grid for the body segments
    SNAKE *temp = new_snake->body;
    while (temp != NULL) {
        arena->grid[temp->head.x][temp->head.y].center = 1;
        temp = temp->body;
    }

    return new_snake;
}

SNAKE* snake_move_west(Arena* arena, SNAKE* snake) {
    SNAKE* new_snake = (SNAKE*)malloc(sizeof(SNAKE));
    if (new_snake == NULL) {
        printf("Memory allocation failed for new snake segment\n");
        return snake;
    }

    new_snake->head.x = snake->head.x - 1;
    new_snake->head.y = snake->head.y;
    new_snake->body = snake;
    new_snake->turn = snake->turn + 1;
    new_snake->size = snake->size;

    // Update the arena grid with the new head position
    arena->grid[new_snake->head.x][new_snake->head.y].center = 1;

    if (new_snake->turn % 10 == 0) {
        // Increase snake size every 10 turns
        new_snake->size += 1;
    } else {
        // Remove the tail segment from the arena and free the memory
        SNAKE *current = new_snake;
        SNAKE *previous = NULL;

        // Traverse to the last node
        while (current->body != NULL) {
            previous = current;
            current = current->body;
        }

        if (previous != NULL) {
            previous->body = NULL;
            // Update the arena grid to remove the tail segment
            arena->grid[current->head.x][current->head.y].center = 0;
            free(current);
        }
    }

    // Update the arena grid for the body segments
    SNAKE *temp = new_snake->body;
    while (temp != NULL) {
        arena->grid[temp->head.x][temp->head.y].center = 1;
        temp = temp->body;
    }

    return new_snake;
}

// AI move function
t_move AI_move(Arena* arena, SNAKE** snake){
    if ((arena->grid[(*snake)->head.x][(*snake)->head.y ].borders[0] != 1) && 
         (arena->grid[(*snake)->head.x][(*snake)->head.y-1 ].center != 1 )) {
        *snake=snake_move_north(arena, *snake);
        return NORTH;
    }
    else if (arena->grid[(*snake)->head.x ][(*snake)->head.y].borders[1] != 1 && 
         arena->grid[(*snake)->head.x+1 ][(*snake)->head.y].center != 1 ) {
        *snake=snake_move_east(arena, *snake);
        return EAST;
    }
    else if (arena->grid[(*snake)->head.x][(*snake)->head.y ].borders[2] != 1 && 
     arena->grid[(*snake)->head.x][(*snake)->head.y+1 ].center != 1) {
        *snake= snake_move_south(arena, *snake);
        return SOUTH;
    }
    else if (arena->grid[(*snake)->head.x ][(*snake)->head.y].borders[3] != 1 && 
     arena->grid[(*snake)->head.x-1 ][(*snake)->head.y].center != 1) {
        *snake= snake_move_west(arena, *snake);
        return WEST;
    }
    else {
        printf("idk\n");
        return WEST;
    }
}