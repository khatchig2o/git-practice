#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void game(){
    int number = (rand() % 100) + 1 ;
    int guess = 0;
    int attempts = 0; 
    const int max_attempts = 10;


    printf("welcome to the guessing game \n");
    printf("I have selected a number between 1 and 100 you have 10 guesses\n");
    while(attempts < max_attempts){
        // in this section we take user imput and also dispaly his attempts used out of the total attempts
        printf("Enter your guess [%d/%d] : " , attempts+1, max_attempts); // we use attemts + 1 so the first try will not be displayd as 0 as the user will be using the first attempt
        scanf("%d" ,&guess);
        attempts ++ ; 

        if (guess == number){
            printf("congratulations! You guessd the number in %d attempts.\n" , attempts);
            return;
        }else if (guess > number)
        {
            printf("too high!\n");
        }else{
            printf("too low!\n");
        }
    }
    printf("You ran out of attempts the correct number was %d , good luck next time \n" , number);
}

int main() {
    char palayagain;
    srand(time(0));
    do {
        game();
        while(1){
            printf("Do you want to play again? (y/n): ");
            scanf(" %c", &palayagain);
            if (palayagain == 'y' ||palayagain == 'Y' || palayagain == 'n' ||palayagain == 'N' ){
                break;
            }else{
                printf("please enter Y/y for yes or N/n for no any other charachters will not be accepted \n");
            }
        }
    } while (palayagain == 'y' || palayagain == 'Y');
    return 0;
}