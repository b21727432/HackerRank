#include<stdio.h>
#include<string.h>
typedef struct {
	char movie_name[50];
	int releaseYear;
}MovieCollection;

typedef struct{
	
	char director[50];
	MovieCollection movies[5];
	
}Director;
void main(){
	
	Director x;
	strcpy(x.director, "Speilberg");
	strcpy(x.movies[0].movie_name, "E.T");
	x.movies[0].releaseYear = 1982;
	
	strcpy(x.movies[1].movie_name ,"Schindler’s List");
	x.movies[1].releaseYear = 1993;
	
	printf("%s %s %d %s %d", x.director,  x.movies[0].movie_name, x.movies[0].releaseYear, 	x.movies[1].movie_name, x.movies[1].releaseYear);
}

