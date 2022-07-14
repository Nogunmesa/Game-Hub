#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

//Tic-Tac-Toe 
char arr[3][3] = {};
//stores chosen letter of 1st or 2nd player
char first_user;
char second_user;
//(accidentaly used char instead of int so when i strcmp i have to use 10)// *nvm getline takes a char*
//the location of the square
char* first_location;
size_t num = 9;

//Print colored text to the terminal and same for the others
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"
#define MAX_LENGTH 100


void white() { printf(WHT); }
void yellow() { printf(YEL); }
void green() { printf(GRN); }
void reset() { printf(RESET); }
void red() { printf(RED); }

//populates the 2d array with number from 1-9
void populate_coordinate(){
    int count = 49; //the dec that correspondes with ch '1'
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            char c1 = count;
            arr[i][j] = c1;
            count++;
        }
    }
}

// prompst user for what letter represents them
// stores that letter in first_user or second_user
void ask_user(){
    printf("Player 1, select your letter\n");
    red();
    first_user = getchar();
    getchar();
    reset();
    printf("Player 2, select your letter\n");
    yellow();
    second_user = getchar();
    getchar();
    reset();
    printf("\n");
}

//checks what number the user inputs and stores it in the array that corresponds with that number
int ask_coordinate(int i){
    printf("User %d, pick a square\n", i);
    getline(&first_location, &num, stdin);
    if ((strcmp (first_location, "1")) == 10){
        if (i == 1){
        arr[0][0] = first_user;
        } else{
        arr[0][0] = second_user;
        }

    }else if ((strcmp (first_location, "2")) == 10){
        if (i == 1){
        arr[0][1] = first_user;
        } else{
        arr[0][1] = second_user;
        }
    }else if ((strcmp (first_location, "3")) == 10){
        if(i == 1){
        arr[0][2] = first_user;
        }else{
        arr[0][2] = second_user;
        }
    }else if ((strcmp (first_location, "4")) == 10){
        if(i == 1){
        arr[1][0] = first_user;
        }else{
        arr[1][0] = second_user;
        }
    }else if ((strcmp (first_location, "5")) == 10){
        if(i == 1){
        arr[1][1] = first_user;
        }else{
        arr[1][1] = second_user;
        }
    }else if ((strcmp (first_location, "6")) == 10){
        if(i == 1){
        arr[1][2] = first_user;
        }else{
        arr[1][2] = second_user;
        }
    }else if ((strcmp (first_location, "7")) == 10){
        if(i == 1){
        arr[2][0] = first_user;
        }else{
        arr[2][0] = second_user;
        }
    }else if ((strcmp (first_location, "8")) == 10){
        if (i == 1){
        arr[2][1] = first_user;
        }else{
        arr[2][1] = second_user;
        }
    }else if ((strcmp (first_location, "9")) == 10){
        if (i == 1){
        arr[2][2] = first_user;
        }else{
        arr[2][2] = second_user;
        }
    }else{
        printf("Please pick from square 1-9 and make sure square is lowercase\n");
        i--;
    }
}
//stops game when there are three in a row or if all of the tic-tac-toe is filled
int stop_game(){
    if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2]){
        return 1;
    }else if (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2]){
        return 1;
    }else if (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2]){
        return 1;
    }else if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0]){
        return 1;
    }else if (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1]){
        return 1;
        
    }else if (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2]){
        return 1;
    }else if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]){
        return 1;
    }else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]){
        return 1;
    }else if (arr[0][0] != '1' && arr[0][1] != '2' && arr[0][2] != '3' && arr[1][0] != '4' && arr[1][1] != '5' && arr[1][2] != '6' && arr[2][0] != '7' && arr[2][1] != '8' && arr[2][2] != '9'){
        return -1;
    }
     
}

void print_report(){
    green();
    printf("   |   |    \n");
    printf(" %c | %c | %c\n", arr[0][0],arr[0][1],arr[0][2]);
    printf("___|___|___\n");
    printf("   |   |  \n");
    printf(" %c | %c | %c\n", arr[1][0],arr[1][1],arr[1][2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c\n", arr[2][0],arr[2][1],arr[2][2]);
    printf("   |   |   \n");
    reset();
    printf("\n\n");
}

void new_print_report(){
     for(int i = 0; i < 3; i++){
         printf("   |   |    \n");
        for(int j = 0; j < 3; j++){
            if(isdigit(arr[i][j])){
                if(arr[i][j]!= arr[0][2] && arr[i][j] != arr[1][2] && arr[i][j]!= arr[2][2]){
                printf(" %c |", arr[i][j]);
            }else{
                printf(" %c", arr[i][j]);
            }
            }else{
                if(arr[i][j] == first_user){
                red();
                }else{
                    green();
                }
                if(j == 2){
                printf(" %c", arr[i][j]);
                reset();
            }else{
                printf(" %c ", arr[i][j]);
                reset();
                printf("|");
            }
            }
        }
        printf("\n");
        if(i == 2){
            printf("   |   |   \n");
        }else{
        printf("___|___|___\n");
        }
}
printf("\n");
}

int main(){
    printf("Welcome to Nifemi's Tic-Tac-Toe\n Here are the rules:\n  1.)2 players only\n  2.)The game ends when one user gets 3 in a row\n  3.)The number corresponds with the location and most importantly have fun\n");
  populate_coordinate();
  green();
   new_print_report();
   reset();
    ask_user();
    while(stop_game() != 1){
        for(int i = 1; i < 3; i++){
    ask_coordinate(i);
    new_print_report();
    if(stop_game() == 1){
        printf("Congrats user %d!!!!!\n", i);
        return 1;
    }else if(stop_game() == -1){
        printf("You're all losers\n");
        return 1;
    }
    }
    }
    return 0;
}