#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct movie{
	char film_ismi[256];
	char yonetmen[256];
	int yil;
	char tur[256];
};

int main(){
	
	struct movie filmler[100];
	int film_count = 0;
	
    FILE* file = fopen("movies.csv", "r");
    char line[1024];
    char *input_name, *input_director, *input_yil, *input_tur;

    while (fgets(line, sizeof(line), file)) {
    	
		input_name = strtok(line, ";");
		
		input_director = strtok(NULL, ";");

		input_yil = strtok(NULL, ";");
		
		input_tur = strtok(NULL, ";");
		
		strcpy(filmler[film_count].film_ismi, input_name);
		strcpy(filmler[film_count].yonetmen, input_director);
		filmler[film_count].yil = atoi(input_yil);
		strcpy(filmler[film_count].tur, input_tur);
		film_count++;
    }

    char command[128];
    int command_error = 0;
    while(1){
    	if(command_error == 1){
    		printf("Please enter a valid command: ");
		} else {
			printf("Please enter a command: ");
		}
    	scanf("%s", command);
    	if(strcmp(command, "print") == 0 || strcmp(command, "update") == 0 || strcmp(command, "search") == 0 || strcmp(command, "exit") == 0){
    		command_error = 0;
    		if(strcmp(command, "print") == 0){
    			int i;
    			for(i = 0; i < film_count; i++){
    				printf("%d. %s, %s, %d, %s", (i+1), filmler[i].film_ismi, filmler[i].yonetmen, filmler[i].yil, filmler[i].tur);
				}
			} else if(strcmp(command, "update") == 0){
				printf("ID: ");
				int id;
				scanf("%d", &id);
				printf("New info: ");
				char update_line[256];
				char *update_name, *update_director, *update_yil, *update_tur;
				fflush (stdin);
				fgets(update_line, 256, stdin); 
				
				update_name = strtok(update_line, ",");
				update_director = strtok(NULL, ",");
				update_yil = strtok(NULL, ",");
				update_tur = strtok(NULL, ",");

				if(!(strcmp(update_name, " ") == 0 || strcmp(update_name, "") == 0)){ // this means it will change
					strcpy(filmler[id-1].film_ismi, update_name); 
				}
				if(!(strcmp(update_director, " ") == 0 || strcmp(update_director, "") == 0)){ // this means it will change
					strcpy(filmler[id-1].yonetmen, update_director); 
				}
				if(!(strcmp(update_yil, " ") == 0 || strcmp(update_yil, "") == 0)){ // this means it will change
					filmler[id-1].yil = atoi(update_yil);
				}
				if(!(strcmp(update_tur, " ") == 0 || strcmp(update_tur, "") == 0)){ // this means it will change
					strcpy(filmler[id-1].tur, update_tur); 
				}
				FILE *fp;

   				fp = fopen("movies.csv", "w+");
   				int i;
   				for(i = 0; i < film_count; i++){
   					fprintf(fp, "%s;%s;%d;%s\n", filmler[i].film_ismi, filmler[i].yonetmen, filmler[i].yil, filmler[i].tur);
				}
				fclose(fp);
				
			} else if(strcmp(command, "search") == 0){
				printf("Search condition: ");
				char search_line[512];
				fflush (stdin);
				fgets(search_line, 512, stdin);
				char *search_field, *search_operator, *search_value;
				
				search_field = strtok(search_line, " ");
				search_operator = strtok(NULL, " ");
				search_value = strtok(NULL, " ");
				
				if(strcmp(search_field, "genre") == 0){
					if(strcmp(search_operator, "==") == 0 || strcmp(search_operator, "!=") == 0){
						if(strcmp(search_operator, "==") == 0){ // == 
							int i;
							for(i = 0; i < film_count; i++){
								if(strcmp(filmler[i].tur,search_value)==0){
									printf("%d. %s, %s, %d, %s", (i+1), filmler[i].film_ismi, filmler[i].yonetmen, filmler[i].yil, filmler[i].tur);
								}
							}
						} else if(strcmp(search_operator, "!=") == 0){ // != 
							int i;
							for(i = 0; i < film_count; i++){
								if(!strcmp(filmler[i].tur,search_value)==0){
									printf("%d. %s, %s, %d, %s", (i+1), filmler[i].film_ismi, filmler[i].yonetmen, filmler[i].yil, filmler[i].tur);
								}
							}
						}
					} else{ // iki operator de deðilse
						printf("Not a valid operator for year...\n");
					}
				} else if(strcmp(search_field, "year") == 0){
					if(strcmp(search_operator, "==") == 0 || strcmp(search_operator, "!=") == 0 || strcmp(search_operator, "<") == 0 || strcmp(search_operator, ">") == 0){
						if(strcmp(search_operator, "==") == 0){
							int i;
							for(i = 0; i < film_count; i++){
								if(filmler[i].yil == atoi(search_value)){
									printf("%d. %s, %s, %d, %s", (i+1), filmler[i].film_ismi, filmler[i].yonetmen, filmler[i].yil, filmler[i].tur);
								}
							}
						} else if(strcmp(search_operator, "!=") == 0){
							int i;
							for(i = 0; i < film_count; i++){
								if(filmler[i].yil != atoi(search_value)){
									printf("%d. %s, %s, %d, %s", (i+1), filmler[i].film_ismi, filmler[i].yonetmen, filmler[i].yil, filmler[i].tur);
								}
							}
						} else if(strcmp(search_operator, "<") == 0){
							int i;
							for(i = 0; i < film_count; i++){
								if(filmler[i].yil < atoi(search_value)){
									printf("%d. %s, %s, %d, %s", (i+1), filmler[i].film_ismi, filmler[i].yonetmen, filmler[i].yil, filmler[i].tur);
								}
							}
						} else if(strcmp(search_operator, ">") == 0){
							int i;
							for(i = 0; i < film_count; i++){
								if(filmler[i].yil > atoi(search_value)){
									printf("%d. %s, %s, %d, %s", (i+1), filmler[i].film_ismi, filmler[i].yonetmen, filmler[i].yil, filmler[i].tur);
								}
							}
						}
					} else{
						printf("Not a valid operator for genre...\n");
					}
				} else{
					printf("Not valid search value...\n");
				}
				
			} else if(strcmp(command, "exit") == 0){
				break;
			}
		} else{
			command_error = 1;
		}
    	
	}

    fclose(file);

	return 0;
}
