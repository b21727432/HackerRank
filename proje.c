#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include<math.h>

//  I'm using the nearest neighbor method, looking for the stores in the stores array, gezilenler  array where I add the visited nodes and send the starting point and send the target
int algorithm_for_shortest_path(float stores[7][7], int gezilenler[8], int start, int end){
	int gezme_sayisi = 0, i, j;
	gezilenler[gezme_sayisi++] = start; // first start point is added to gezilenler list
	for(i = 0; i < 7; i++){
		float min = 9999;
		int next;
		if(stores[start][end] != 0){ // if there is direct connection between them
				gezilenler[gezme_sayisi++] = end;
				break;
		}
		for(j = 0; j < 7; j++){
			if(stores[start][j] < min && stores[start][j] != 0 && daha_once_gidilmismi(gezilenler, j)){ // if it is a smaller value, if not 0 because 0 is itself or no connection, if it has been visited before it should not be added, if not before it should go there
				min = stores[start][j];
				next = j;
			}
		}
		gezilenler[gezme_sayisi++] = next; // we have found the closest neighbor, lets add it to gezilenler list
		start = next; // not iterate over start to find next destination
	}
	
	printf("Visited places : ");
	
	for(i = 0; i < gezme_sayisi; i++){ // display the nodes that are in the gezilenler
		printf("%d ", gezilenler[i]);
	}
	return gezme_sayisi;
}

// we have visited nodes in gezilenler, now lets compute the distance from start to end. to do this i am using gezme sayisi because it shows how many nodes are visited,
// i am iterating gezme sayisi - 1 times and adding the distance of visited nodes i and i + 1, and i am printing the result
void shortest_path_calculate_cost(int gezilenler[8], float stores[7][7], int gezme_sayisi){
	int i;
	float maliyet = 0;
	for(i = 0 ; i < gezme_sayisi - 1; i++){
		maliyet += stores[gezilenler[i]][gezilenler[i+1]];
	}
	printf("\nDistance of the tour : %f", maliyet);
}


// Has the point where the distance is found with this function been added before? if added, do not go to that node, if not, visit
int daha_once_gidilmismi(int gezilenler[8], int j){
	int i;
	for(i =0; i < 8; i++){
		// if added before return 0 so that if will fail 
		if(gezilenler[i] == j){
			return 0;
		}
	}
	return 1; // if not found return 1 so that if will pass
}

int main(){
	
	float stores[7][7]; // cinema 0, sport 1, rest 2, cafe 3, bowling 4, clothes 5, toy 6,
	int i, j;
	for(i = 0; i < 7; i++){
		for(j = 0; j < 7; j++){
			stores[i][j] = 0;
		}
	}
	// cinemanýn komsulari
	stores[0][1] = sqrt((256.6 - 120.5) * (256.6 - 120.5) - (92.3 - 5.5) * (92.3 - 5.5));
	stores[0][2] = sqrt((350.0 - 256.6) * (350.0 - 256.6) - (165.5 - 92.3) * (165.5 - 92.3));
	// sport center komsulari
	stores[1][0] = sqrt((256.6 - 120.5) * (256.6 - 120.5) - (92.3 - 5.5) * (92.3 - 5.5));
	stores[1][3] = sqrt((120.5 - 102.3) * (120.5 - 102.3) - (10.26 - 5.5) * (10.26 - 5.5));
	//rest komsulari
	stores[2][0] = sqrt((350.0 - 256.6) * (350.0 - 256.6) - (165.5 - 92.3) * (165.5 - 92.3));
	stores[2][3] = sqrt((350.0 - 102.3) * (350.0 - 102.3) - (165.5 - 10.26) * (165.5 - 10.26));
	// cafe komsularý
	stores[3][1] = sqrt((120.5 - 102.3) * (120.5 - 102.3) - (10.26 - 5.5) * (10.26 - 5.5));
	stores[3][2] = sqrt((350.0 - 102.3) * (350.0 - 102.3) - (165.5 - 10.26) * (165.5 - 10.26));
	stores[3][4] = sqrt(abs((102.3 - 40.8) * (102.3 - 40.8) - (72.35 - 10.26) * (72.35 - 10.26)));
	stores[3][5] = sqrt(abs((102.3 - 92.5) * (102.3 - 92.5) - (86.4 - 10.26) * (86.4 - 10.26)));
	stores[3][6] = sqrt(abs((102.3 - 90.5) * (102.3 - 90.5) - (302.1 - 10.26) * (302.1 - 10.26)));
	// bowling komsulari
	stores[4][3] = sqrt(abs((102.3 - 40.8) * (102.3 - 40.8) - (72.35 - 10.26) * (72.35 - 10.26)));
	stores[4][5] = sqrt(abs((92.5 - 40.8) * (92.5 - 40.8) - (86.4 - 72.35) * (86.4 - 72.35)));
	// clothes komsulari
	stores[5][3] = sqrt(abs((102.3 - 92.5) * (102.3 - 92.5) - (86.4 - 10.26) * (86.4 - 10.26)));
	stores[5][4] = sqrt(abs((92.5 - 40.8) * (92.5 - 40.8) - (86.4 - 72.35) * (86.4 - 72.35)));
	stores[5][6] = sqrt(abs((92.5 - 90.5) * (92.5 - 90.5) - (302.1 - 86.4) * (302.1 - 86.4)));
	// toy komsulari
	stores[6][3] = sqrt(abs((102.3 - 90.5) * (102.3 - 90.5) - (302.1 - 10.26) * (302.1 - 10.26)));
	stores[6][5] = sqrt(abs((92.5 - 90.5) * (92.5 - 90.5) - (302.1 - 86.4) * (302.1 - 86.4)));
	
	int start = 0;
	int end = 0;
	printf("1.Cinema: (256.6, 92.3)\n2.Sport Center: (120.5, 5.5)\n3.Restaurant: (350.0, 165.5)\n4.Cafe: (102.3, 10.26)\n5.Bowling: (40.8, 72.35)\n6.Clothes Store: (92.5, 86.4)\n7.Toy Store: (90.5, 302.1)");
	printf("\nEnter Starting Position(1,2,3,4,5,6,7)");
	scanf("%d", &start);
	printf("Enter Arrival Position(1,2,3,4,5,6,7)");
	scanf("%d", &end);
	printf("Baslangic : %d Bitis : %d\n", start - 1, end - 1);
	int gezilenler[8];
	
	int gezme_sayisi = algorithm_for_shortest_path(stores, gezilenler, start - 1, end - 1);
	
	shortest_path_calculate_cost(gezilenler, stores, gezme_sayisi);
	
}

/*ýn this homework we are exptected to use find shortest way between start and end point. To do this i have used nearest neighbor algorithm
because it is easy to implement and easy to understand, to do this i have used 2d array, i put the distance of each node to this array
if this element of array is not 0 it means there is a path between them. this can be used as adjacency matrix. In my algorithm if there is no direct path
between start and end point, then look for the neighbors, find the neighbor with the minimum distance and go to that neighbor, do the same process until we find the wanted arrival.
add the visited nodes to visited array, this way i can display the visited nodes and cost of distance at the end. */
