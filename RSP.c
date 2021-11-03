#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void flush_input(void)
{
    char c;
    while (scanf("%c",&c) == 1 && c != '\n');
}

int main(){
    char choice;
    char mas[3] = {'r','s','p'};
    srand(time(NULL));
    int r = rand() % (3 - 1 + 1) + 1;
    printf("WELCOME TO OUR GAME 'ROCK, SCISSORS, PAPER'\n");
    printf("Some rules:\n1)You select rock, scissors or paper by entering r, s or p respectively;\n");
    printf("2)CPU also select rock, scissors or paper;\n");
    printf("3)The result depends on your choice and choice of computer.\n");
    printf("A little hint for you: rock beats scissors, but loses to paper;\nscissors lose to rock, but win paper;");
    printf("paper loses to scissors, but wins rock.\n");
    printf("That's all I wanted to tell you. Good luck, may the strongest win.\n");
    printf("Enter r,s or p: ");
    scanf("%c", &choice);
    while(choice != 'r' && choice != 's' && choice != 'p')
    {
        printf("Input error!!! Try again: ");
        flush_input();
        scanf("%c", &choice);
    }
    printf("Your choice: %c\n", choice);
    printf("CPU selection: %c\n", mas[r-1]);
    if(choice == mas[r-1])
    {
        printf("Draw\n");
    }
    else
    {
        switch(choice){
            case 'r':
                if(mas[r-1] == 's')
                {
                    printf("You win!\n");
                }
                else printf("You lose!\n");
                break;
            case 's':
                if(mas[r-1] == 'p')
                {
                    printf("You win!\n");
                }
                else printf("You lose!\n");
                break;
            case 'p':
                if(mas[r-1] == 'r')
                {
                    printf("You win!\n");
                }
                else printf("You lose!\n");
                break;
            default:
                printf("Error\n");
                break;
        }
    }
    return 0;
}
