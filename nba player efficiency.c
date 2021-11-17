#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

struct Player{
	int number;
	char name[20];
	char surname[20];
	int points;
	int rebounds;
	int blocks;
	double efficiency;
};

void find_mvp(struct Player players[], int n){
	int i;
	double maxEfficiency = 0;
	int mvp = 0;
	for(i = 0; i < n; i++){
		if(players[i].efficiency > maxEfficiency){
			maxEfficiency = players[i].efficiency;
			mvp = i;
		}
	}
	
	printf("\n\nThe MVP of the team is: %s %c.", players[mvp].surname, players[mvp].name[0]);	
}

int main(){
	
	int n;
	printf("How many players?:");
	scanf("%d", &n);
	getchar();
	printf("\n");
	
	struct Player players[n];
	int i, j;
	for(i = 0; i < n; i++){
		printf("Enter Player %d info:", i+1);
		char line[100];
		char * split;
		scanf("%[^\n]%*c", line);
		split = strtok(line, " ");
		players[i].number = atoi(split);
		split = strtok(NULL, " ");
		for(j = 0; split[j]; j++){
			if(j == 0){
				split[j] = toupper(split[j]);
			} else{
				split[j] = tolower(split[j]);
			}
		}
		strcpy(players[i].name, split);
		split = strtok(NULL, " ");
		for(j = 0; split[j]; j++){
			if(j == 0){
				split[j] = toupper(split[j]);
			} else{
				split[j] = tolower(split[j]);
			}
		}
		strcpy(players[i].surname, split);
		split = strtok(NULL, " ");
		players[i].points = atoi(split);
		split = strtok(NULL, " ");
		players[i].rebounds = atoi(split);
		split = strtok(NULL, " ");
		players[i].blocks = atoi(split);
		players[i].efficiency = players[i].points * 50.0 / 100.0 + players[i].rebounds * 30.0 / 100.0 + players[i].blocks * 20.0 / 100.0;
	}
	
	printf("\n\nThe efficiency scores of players:\n");
	for(i = 0; i < n; i++){
		printf("#%d %s, %c. %.2lf\n", players[i].number, players[i].surname, players[i].name[0], players[i].efficiency);
	}
	
	find_mvp(players, n);
	
	return 0;
}
