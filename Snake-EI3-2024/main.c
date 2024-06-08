
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "clientAPI.h"
#include "snakeAPI.h"
#include "arena.h"
#include "snakes.h"

// #define DEBUG_KEY_PLAY
// #define DEBUG_ARENA

// #define DEBUG_SNAKE
#define DEBUG_AI

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
    // t_move* ai_move = malloc(sizeof(t_move));
    t_return_code ongoing=NORMAL_MOVE;

        
#ifdef DEBUG_AI
    Arena *arena=get_arena(&sizex, &sizey, &nbwalls, walls);
    SNAKE* snake1=init_snake1(arena);
    SNAKE* snake2=init_snake2(arena);
    printArena();
    print_arena(arena);
    if (!turn){

        ongoing = sendMove(AI_move(arena, &snake1));
        // *ai_move=AI_move(arena, snake1);
        // printf("LKAUJDKSHCPFOAIWEHDMFPAOWIDHCNPQOWI%d\n", (int)*ai_move);
        printArena();
        print_arena(arena);
        // update_arena(arena, snake1);
// YOU NEED TO UPDATE THE ARENA MOTHERFUCKER ALSO YOU NEED TO GIVE A SNAKE TO THE OPPONENT SO THAT YOU CAN UPDATE THE ARENA PROPERLY, AND YOU LL NEED TO CHECK THE CASE OF HIS MOVE GOOD LUCK LITTLE FUCKER
        while(ongoing == NORMAL_MOVE){
            ongoing = getMove(opponent_move);

            if(*opponent_move==NORTH){
                snake2=snake_move_north(arena, snake2);
            }
            else if (*opponent_move==EAST){
                snake2=snake_move_east(arena, snake2);
            }
            else if (*opponent_move==SOUTH){
                snake2=snake_move_south(arena, snake2);
            }
            else if (*opponent_move==WEST){
                snake2=snake_move_west(arena, snake2);
            }
            // update_arena(arena, snake2);
            printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
            if(ongoing == NORMAL_MOVE){
                printf("BBBBBBBBBBBBBBBBBBBBBBBBBBB\n");
                ongoing = sendMove(AI_move(arena, &snake1));//this is the line causing the segmentation fault
                // *ai_move=AI_move(arena, snake1);
                // printf("LKAUJDKSHCPFOAIWEHDMFPAOWIDHCNPQOWI%d\n", (int)(*ai_move));
                // update_arena(arena, snake1);
                printf("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCC\n");
                printArena();
                print_arena(arena);
            }
        }   
    }
    else {

        while(ongoing == NORMAL_MOVE){
            ongoing = getMove(opponent_move);

            if(*opponent_move==NORTH){
                snake1=snake_move_north(arena, snake1);
            }
            else if (*opponent_move==EAST){
                snake1=snake_move_east(arena, snake1);
            }
            else if (*opponent_move==SOUTH){
                snake1=snake_move_south(arena, snake1);
            }
            else if (*opponent_move==WEST){
                snake1=snake_move_west(arena, snake1);
            }

            // update_arena(arena, snake1);
            printf("DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\n");
            if(ongoing == NORMAL_MOVE){
                printf("EEEEEEEEEEEEEEEEEEEEEEEEE\n");
                ongoing = sendMove(AI_move(arena, &snake2));//this is the line causing the segmentation fault
                // *ai_move=AI_move(arena, snake2);
                // printf("LKAUJDKSHCPFOAIWEHDMFPAOWIDHCNPQOWI%d\n", (int)*ai_move);
                // update_arena(arena, snake2);
                printf("FFFFFFFFFFFFFFFFFFFFFFF\n");
                printArena();
                print_arena(arena);
            }
        }
    }




#endif
    

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
    printf("QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQC IIII888 initial arena\n");
    print_arena(arena);
    // printArena();

    SNAKE* snake1=init_snake1(arena);
    SNAKE* snake2=init_snake2(arena);
    printf("QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQC IIII8B with the snakes\n");
    print_arena(arena);

    snake1 = snake_move_north(arena, &snake1);
    printf("QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQC IIII8B snake1 moving north\n");
    print_arena(arena);

    snake1 = snake_move_east(arena, &snake1);
    printf("QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQC IIII8B snake1 moving east\n");
    print_arena(arena);


#endif

    free_snake(snake1);
    free_snake(snake2);
    free_arena(arena);
    free(opponent_move);
    // free(ai_move);
    free(walls);
    closeConnection();
    return 0;
}



