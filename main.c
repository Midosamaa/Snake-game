
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientAPI.c"
#include "snakeAPI.c"
#include "structs.c"

#define DEBUG_STRUCT

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
#ifndef DEBUG_STRUCT
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

    Arena *arena=get_arena(&sizex, &sizey, &nbwalls, walls);
    print_arena(arena);
    printArena();

    free(opponent_move);
    free(walls);
    closeConnection();
    return 0;
}

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