#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(char yC, char cC){
	if (yC == cC){
		return -1;
	}
	if(yC == 'r' && cC == 's'){
		return 1;
	}else if(yC == 's' && cC == 'r'){
		return 0;
	}
	if(yC == 's' && cC == 'p'){
                return 1;
        }else if(yC == 'p' && cC == 's'){
                return 0;
        }
	if(yC == 'p' && cC == 'r'){
                return 1;
        }else if(yC == 'r' && cC == 'p'){
                return 0;
        }
}

int main(){
	char yourChoice;
	char var[3] ={'r', 'p', 's'};
	srand(time(NULL));
	printf("Rules: r>s, s>p, p>r\n");
	flag: printf("Enter r(rock), p(paper) or s(scissors):");
	scanf("%1s", &yourChoice);
	while(yourChoice != 'r' && yourChoice != 'p' && yourChoice != 's'){
		goto flag;
	}
	int n = rand()%3;
	char compChoice = var[n];
	printf("Computer choice: %c\n", compChoice);
	int res = game(yourChoice, compChoice);
	switch(res){
		case -1:{
			printf("Draw\n");
			printf("One more time:");
			goto flag;
			break;
		}
		case 1:{
			printf("Victory\n");
			break;
		}
		case 0:{
			printf("Loss\n");
			break;
		}
	}
	return 0;
}
