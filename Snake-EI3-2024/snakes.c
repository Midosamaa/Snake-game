
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

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
    snake1->turn = -1;
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
    snake2->turn = -1;
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
    } 
    else {
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
    (arena->grid[(*snake)->head.x][(*snake)->head.y-1 ].center != 1) ) {
        *snake=snake_move_north(arena, *snake);
        printf("MOVING NORTH\n");
        printf(" TURN %d\n", (*snake)->turn);
        return NORTH;
    }
    else if (arena->grid[(*snake)->head.x ][(*snake)->head.y].borders[1] != 1 && 
    (arena->grid[(*snake)->head.x+1 ][(*snake)->head.y].center != 1 )) {
        *snake=snake_move_east(arena, *snake);
        printf("MOVING EAST\n");
        printf(" TURN %d\n", (*snake)->turn);
        return EAST;
    }
    else if (arena->grid[(*snake)->head.x ][(*snake)->head.y].borders[3] != 1 && 
    (arena->grid[(*snake)->head.x-1 ][(*snake)->head.y].center != 1)) {
        *snake= snake_move_west(arena, *snake);
        printf("MOVING WEST\n");
        printf(" TURN %d\n", (*snake)->turn);
        return WEST;
    }
    else if (arena->grid[(*snake)->head.x][(*snake)->head.y ].borders[2] != 1 && 
    (arena->grid[(*snake)->head.x][(*snake)->head.y+1 ].center != 1)) {
        *snake= snake_move_south(arena, *snake);
        printf("MOVING SOUTH\n");
        printf(" TURN %d\n", (*snake)->turn);
        return SOUTH;
    }
    else {
        printf("IDKIDKIDKIDKIDKIDKIDKIDKIDK\n");
        printf("MOVING WEST\n");
        return WEST;
    }
}

// int is_within_bounds(Arena* arena, int x, int y) {
//     return x >0 && x < arena->sizex-1 && y > 0 && y < arena->sizey-1;
// }

// int will_collide_with_wall(Arena* arena, SNAKE* snake, t_move move) {
//     // Check if the next move will collide with a wall
//     return arena->grid[snake->head.x][snake->head.y].borders[move];
// }


// int will_collide_with_snake(Arena* arena, SNAKE* snake, t_move move) {

//     //we check for collision
//     if (move==NORTH && is_within_bounds(arena, snake->head.x, snake->head.y)
//         && snake->direction==SOUTH){
//         return arena->grid[snake->head.x][snake->head.y - 1].center;
//     }
//     else if (move==EAST && is_within_bounds(arena, snake->head.x, snake->head.y)
//         && snake->direction==WEST){
//         return arena->grid[(snake)->head.x + 1 ][(snake)->head.y].center;
//     }
//     else if (move==SOUTH && is_within_bounds(arena, snake->head.x, snake->head.y)
//         && snake->direction==NORTH){
//         return arena->grid[(snake)->head.x][(snake)->head.y + 1].center;
//     }
//     else if (move==WEST && is_within_bounds(arena, snake->head.x, snake->head.y)
//         && snake->direction==EAST){
//         return arena->grid[(snake)->head.x - 1 ][(snake)->head.y].center;
//     }
// }


// int calculate_score(Arena* arena, SNAKE* snake, t_move move) {
//     int score = 0 ;
    
//     // Check for collision with walls
//     if (will_collide_with_wall(arena, snake, move)) {
//         score -= 100; // Penalize collision with walls
//     }
    
//     // Check for collision with opponent's snake
//     if (will_collide_with_snake(arena, snake, move)) {
//         score -= 120; // Penalize collision with opponent's snake
//     }
    
//     return score;
// }

// t_move f_AI_move(Arena* arena, SNAKE** snake) {
//     t_move best_move = SOUTH; // Default move in case all moves have negative scores
//     int best_score = -200; // Initialize best score to the lowest possible value

//     // Evaluate each potential move
//     for (t_move move = NORTH; move <= WEST; move++) {
//         int score = calculate_score(arena, *snake, move);
//         printf("Move: %d, Score: %d\n", move, score); // Debug information
//         if (score > best_score) {
//             best_score = score;
//             best_move = move;
//         }
//     }

//     if(best_move==NORTH){
//         *snake=snake_move_north(arena, *snake);
//     }
//     else if(best_move==EAST){
//         *snake=snake_move_east(arena, *snake);
//     }
//     else if(best_move==SOUTH){
//         *snake=snake_move_south(arena, *snake);
//     }
//     else if(best_move==WEST){
//         *snake=snake_move_west(arena, *snake);
//     }
//     printf("Best Move: %d\n", best_move); // Debug information
//     return best_move; // Return the move with the highest score
// }

void mark_adj_cell(Arena* arena, int x, int y) {
    
    if (y > 0 && arena->grid[x][y-1].visited_down!=1) {
        arena->grid[x][y-1].visited_down=1;
        if(arena->grid[x][y].borders[0] != 1 && arena->grid[x][y-1].center != 1) {
            arena->grid[x][y-1].access = arena->grid[x][y].access + 1;
        }
    }
    if (x < arena->sizex - 1 &&  arena->grid[x+1][y].visited_left!=1) {
        arena->grid[x+1][y].visited_left=1;
        if (arena->grid[x][y].borders[1] != 1 && arena->grid[x+1][y].center != 1){
            arena->grid[x+1][y].access = arena->grid[x][y].access + 1;
        }
    }
    if (y < arena->sizey - 1 && arena->grid[x][y+1].visited_up!=1) {
        arena->grid[x][y+1].visited_up= 1;
        if (arena->grid[x][y].borders[2] != 1 && arena->grid[x][y+1].center != 1 ){
            arena->grid[x][y+1].access = arena->grid[x][y].access + 1;
        }
    }
    if (x > 0 &&  arena->grid[x-1][y].visited_right!=1) {
        arena->grid[x-1][y].visited_right = 1;
        if (arena->grid[x][y].borders[3] != 1 && arena->grid[x-1][y].center != 1 ){
            arena->grid[x-1][y].access = arena->grid[x][y].access + 1;
        }
    }
}

void longest_path(Arena* arena, int x, int y) {
    if (y > 0 && arena->grid[x][y-1].visited_down!=1) {
        mark_adj_cell(arena, x, y - 1);
        longest_path(arena, x, y - 1);
    }
    if (y < arena->sizey - 1 && arena->grid[x][y+1].visited_up!=1) {
        mark_adj_cell(arena, x, y + 1);
        longest_path(arena, x, y + 1);
    }
    if (x < arena->sizex - 1 && arena->grid[x+1][y].visited_left!=1) {
        mark_adj_cell(arena, x + 1, y);
        longest_path(arena, x + 1, y);
    }
    if (x > 0 && arena->grid[x-1][y].visited_right!=1) {
        mark_adj_cell(arena, x - 1, y);
        longest_path(arena, x - 1, y);
    }

}

t_move new_strat(Arena* arena, SNAKE** snake){
    if((*snake)->head.y>0){
        cell_access(arena, (*snake)->head.x, (*snake)->head.y-1, *snake);
    }
    if((*snake)->head.y<arena->sizey){
        cell_access(arena, (*snake)->head.x, (*snake)->head.y+1, *snake);
    }
    if((*snake)->head.x>0){
        cell_access(arena, (*snake)->head.x-1, (*snake)->head.y, *snake);
    }
    if((*snake)->head.x<arena->sizex){
        cell_access(arena, (*snake)->head.x+1, (*snake)->head.y, *snake);
    }

    
    if(
        arena->grid[(*snake)->head.x][(*snake)->head.y-1].access==max_access(arena,(*snake)->head.x, (*snake)->head.y)){

        *snake=snake_move_north(arena, *snake);
        printf("MOVING NORTH\n");
        printf(" TURN %d\n", (*snake)->turn);
        return NORTH;
    }
    else if(
        arena->grid[(*snake)->head.x+1][(*snake)->head.y].access==max_access(arena,(*snake)->head.x, (*snake)->head.y)
        ){
        *snake=snake_move_east(arena, *snake);
        printf("MOVING EAST\n");
        printf(" TURN %d\n", (*snake)->turn);
        return EAST;
    }
    else if(
        arena->grid[(*snake)->head.x][(*snake)->head.y+1].access==max_access(arena,(*snake)->head.x, (*snake)->head.y)){
        *snake= snake_move_south(arena, *snake);
        printf("MOVING SOUTH\n");
        printf(" TURN %d\n", (*snake)->turn);
        return SOUTH;
    }
    else if(
            arena->grid[(*snake)->head.x-1][(*snake)->head.y].access==max_access(arena,(*snake)->head.x, (*snake)->head.y)){
        *snake= snake_move_west(arena, *snake);
        printf("MOVING WEST\n");
        printf(" TURN %d\n", (*snake)->turn);
        return WEST;
    }
    
}

void cell_access(Arena*arena, int x, int y, SNAKE* snake){
    arena->grid[x][y].access=0;
    if(arena->grid[x][y].center==1){
        arena->grid[x][y].access=0;
    }
    if(x==snake->head.x && y-1==snake->head.y && (arena->grid[(snake)->head.x][(snake)->head.y ].borders[0] == 1) && 
        (arena->grid[(snake)->head.x][(snake)->head.y-1 ].center == 1)){
        arena->grid[x][y].access=0;
    }
    if(x==snake->head.x && y+1==snake->head.y && arena->grid[(snake)->head.x][(snake)->head.y ].borders[2] == 1 && 
        (arena->grid[(snake)->head.x][(snake)->head.y+1 ].center == 1)){
        arena->grid[x][y].access=0;
    }
     if(x==snake->head.x-1 && y==snake->head.y && arena->grid[(snake)->head.x ][(snake)->head.y].borders[3] == 1 && 
            (arena->grid[(snake)->head.x-1 ][(snake)->head.y].center == 1)){
        arena->grid[x][y].access=0;
    }
     if(x==snake->head.x+1 && y==snake->head.y && arena->grid[(snake)->head.x ][(snake)->head.y].borders[1] == 1 && 
            (arena->grid[(snake)->head.x+1 ][(snake)->head.y].center == 1 )){
        arena->grid[x][y].access=0;
    }
    else{
        if(y>0 && arena->grid[x][y].borders[0]==0 && arena->grid[x][y-1].center==0){
            arena->grid[x][y].access++;
        }  
        if(x<arena->sizex &&arena->grid[x][y].borders[1]==0 && arena->grid[x+1][y].center==0){
            arena->grid[x][y].access++;
        } 
        if(y<arena->sizey && arena->grid[x][y].borders[2]==0 && arena->grid[x][y+1].center==0){
            arena->grid[x][y].access++;
        } 
        if(x>0 && arena->grid[x][y].borders[3]==0 && arena->grid[x-1][y].center==0){
            arena->grid[x][y].access++;
        } 
    }
}


int max_4(int a, int b, int c, int d){
    int max=0;
    if (a>max){
        max=a;
    }
    if(b>max){
        max=b;
    }
    if (c>max){
        max=c;
    }
    if (d>max){
        max=d;
    }
    return max;
}

int max_access(Arena* arena, int x, int y){
    return(max_4(arena->grid[x][y-1].access, arena->grid[x+1][y].access, 
                arena->grid[x][y+1].access, arena->grid[x-1][y].access));
}

int is_in_bounds(Arena* arena, int x,int y){

}