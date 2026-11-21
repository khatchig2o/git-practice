#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>



void AssignValue(char *playerOne, char *playerTwo){
    while(1){
        printf("Player 1 choose your marker X or O :");
        scanf("%c",playerOne);
        if( *playerOne != 'x' &&  *playerOne != 'X'  && *playerOne != 'o' && *playerOne != 'O'){
            printf("Please enter a valid marker.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
        }else{
            *playerOne = toupper(*playerOne);
            break;
        }
    }
    
    if( *playerOne == 'X'){
        *playerTwo = 'O';
    }else{
        *playerTwo = 'X';
    }
}

void InitalTable(char *board){
    for(int i = 0; i < 9; i++){
        if (i < 8 && i%3 == 2)
        {
            printf("%c  ",board[i]);
            
        }else if (i < 8 && i%3 != 2)
        {
            printf("%c | ",board[i]);
            
        }
        else{
            
            printf("%c  \n",board[i]);
        }
        if (i%3 == 2 && i < 7){
            printf("\n---+---+---\n");
        }
    }
}

void EditTable(char *board, int *input ,char currentplayer ,char *playerOne, char *playerTwo){
    char mark;
    if (currentplayer == 1){
        mark = *playerOne;
    }else{
        mark = *playerTwo;
    }
    while (1){
        printf("Its Player %d turn:", currentplayer);
        if(scanf("%d", input) != 1){
            printf("Input must be numbers and not charecters \n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
        }else{
            if(*input > 0 && *input < 10 && board[*input-1] != 'X' && board[*input-1] != 'O'  ){
                board[*input-1] = mark;
                break;
            }else{
                if (*input > 0 && *input < 10){
                    printf("the boxe chosen either already chosen before\n");
                }else{
                    printf("please choos a number 1 through 9 \n");
                }

            }   
        }
        
    }
    for(int i = 0; i < 9; i++){
        if (i < 8 && i%3 == 2)
        {
            printf("%c  ",board[i]);
            
        }else if (i < 8 && i%3 != 2)
        {
            printf("%c | ",board[i]);
            
        }
        else{
            
            printf("%c  \n",board[i]);
        }
        if (i%3 == 2 && i < 7){
            printf("\n---+---+---\n");
        }
    }
    
}

int Currentplayer(int *playerturn){
    if(*playerturn == 2){
        *playerturn = 1;
    }else{
        *playerturn = 2;
    }
    return *playerturn;
    
}

bool Winner(char *board){
    bool won = false;
    if (board[0] == board[4] && board[0] == board[8]){
        won = true;
    }
    if (board[2] == board[4] && board[2] == board[6]){
        won = true;
    }
    if (board[0] == board[3] && board[0] == board[6]){
        won = true;
    }
    if (board[1] == board[4] && board[1] == board[7]){
        won = true;
    }
    if (board[2] == board[5] && board[2] == board[8]){
        won = true;
    }
    for (int i=0; i<9; i++){
        if (i%3 == 0 && board[i] == board[i+1] && board[i] == board[i+2]){
        won = true;
        break;
        }
    }
    return won;
}

int main(){
    char playerOne;
    char playerTwo;
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    int input;
    int currentplayer;
    int playerturn = 2;

    printf("Welcome to Tic Tac Toe game hope your not betting money XD \n");
    AssignValue( &playerOne, &playerTwo);
    InitalTable(board);
    for (int i = 0; i < 9; i++){
        currentplayer = Currentplayer(&playerturn);
        EditTable(board, &input, currentplayer, &playerOne, &playerTwo);
        if ( Winner(board) == 1){
            printf("game over player %d wins\n",currentplayer);
            break;
        }

    } 
    return 0;
}