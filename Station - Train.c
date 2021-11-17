#include<stdio.h>


struct Station{
	int Number;
	int Capacity;
};

struct Track{
	int Number;
	int Lenght;
	int StStation;
	int EnStation;
};

void swap(struct Track* x, struct Track* y){
	struct Track temp = *x;
	*x = *y;
	*y = temp;
}

void selection_sort(struct Track tracks[100], int trackNum){
	int i,j,mintrackindex;
	for(i = 0; i < trackNum - 1; i++){
		mintrackindex = i;
		for(j = i+1; j < trackNum; j++){
			if(tracks[j].Lenght > tracks[mintrackindex].Lenght){
				mintrackindex = j;
			}
		}
		swap(&tracks[mintrackindex], &tracks[i]);
	}
}

int main(){
	
	struct Station stations[10];
	struct Track tracks[100];
	int stationNum = 0;
	int trackNum = 0;
	
	while(1){
		int choice;
		printf("1. Please enter 1 to add a new record of stations\n");
		printf("2. Please enter 2 to add a new record of tracks\n");
		printf("3. Please enter 3 to sort and print the tracks according to their lenghts in descending order. \n");
		printf("4. Please enter 4 to find and print the station that has the maximum number of connected tracks\n");
		printf("5. Please enter 5 to exit the program.\n");
		scanf("%d", &choice);
		if(choice == 1){
			printf("Enter new station number : ");
			int newstation;
			int newcapacity;
			scanf("%d", &newstation);
			printf("Enter new station capacity : ");
			scanf("%d", &newcapacity);
			stations[stationNum].Number =  newstation;
			stations[stationNum].Capacity = newcapacity;
			stationNum++;
			printf("Station added.\n");
		} else if(choice == 2){
			int tracknumber;
			int tracklenght;
			int trackstart;
			int trackend;
			printf("Enter new track number : ");
			scanf("%d", &tracknumber);
			printf("Enter new track lenght : ");
			scanf("%d", &tracklenght);
			printf("Enter new track start : ");
			scanf("%d", &trackstart);
			printf("Enter new track end : ");
			scanf("%d", &trackend);
			tracks[trackNum].Number = tracknumber;
			tracks[trackNum].Lenght = tracklenght;
			tracks[trackNum].StStation = trackstart;
			tracks[trackNum].EnStation = trackend;
			trackNum++;
			printf("Track added\n");
		} else if(choice == 3){
			printf("Sorting the tracks according to their lenghts in descending order...\n");
			selection_sort(tracks, trackNum);
			int i;
			for(i = 0; i < trackNum; i++){
				printf("Number : %d Lenght : %d Start Station : %d End Station : %d\n", tracks[i].Number, tracks[i].Lenght, tracks[i].StStation, tracks[i].EnStation);
			}
		} else if(choice == 4){
			printf("Finding the station that has the maximum number of connected tracks...\n");
			int i,j, maxtrack = 0, maxtrackstation = 0;
			for(i =0; i < stationNum; i++){
				int tracknum = 0;
				for(j = 0; j < trackNum; j++){
					if(tracks[j].StStation == stations[i].Number || tracks[j].EnStation == stations[i].Number){
						tracknum++;
					}
				}
				if(tracknum > maxtrack){
					maxtrack = tracknum;
					maxtrackstation = i;
				}
			}
			printf("The station with the maximum number of connected tracks is : Number :  %d, Capacity : %d\n", stations[maxtrackstation].Number, stations[maxtrackstation].Number);
			
		} else if(choice == 5){
			printf("Exiting...");
			break;
		} else{
			continue;
		}
	}
	
	return 0;
}
