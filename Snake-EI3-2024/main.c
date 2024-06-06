

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientAPI.h"
#include "snakeAPI.h"
#include "arena.h"
#include "snakes.h"

// #define DEBUG_KEY_PLAY
// #define DEBUG_ARENA

// #define DEBUG_SNAKE

t_move button_to_move(char*);

int main (){

    connectToServer("localhost", 1234, "midosama");
    char gamename[50];
    int sizex ;
    int sizey ;
    int nbwalls;
    
    waitForSnakeGame("TRAINING RANDOM_PLAYER", gamename, &sizex, &sizey, &nbwalls);
    int *walls = malloc(4*nbwalls*sizeof(int));
    int turn = getSnakeArena(walls);
    char button;
    t_move* opponent_move = malloc(sizeof(t_move));
    t_return_code ongoing=NORMAL_MOVE;

    

#ifdef DEBUG_KEY_PLAY
    printArena();
    if (!turn){
        printf("what s your move?\n");
        printf("use wasd to enter your direction\n");
        scanf("%c", &button);
        ongoing = sendMove(button_to_move(&button));
        printArena();
    }

    while(ongoing == NORMAL_MOVE){
       ongoing = getMove(opponent_move);
       if(ongoing == NORMAL_MOVE){
        t_move debugmove;
        printf("what s your move?\n");
        printf("use wasd to enter your direction\n");
        scanf(" %c", &button);
        debugmove=button_to_move(&button);
        printf("%d",(int)debugmove);
        ongoing = sendMove(debugmove);
        printArena();
       }
    }
#endif
#ifdef DEBUG_ARENA
    Arena *arena=get_arena(&sizex, &sizey, &nbwalls, walls);
    print_arena(arena);
    // printArena();

    SNAKE* snake1=init_snake1(arena);
    print_arena(arena);

    SNAKE* snake2=init_snake2(arena);
    print_arena(arena);


    free_snake(snake1);
    free_snake(snake2);
    free_arena(arena);
    free(opponent_move);
    free(walls);
    closeConnection();
    return 0;

#endif
#ifdef DEBUG_KEY_PLAY
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
#endif


}