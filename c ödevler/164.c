#include <stdio.h>
#include <string.h>

int main()
{
    char line[256], linecopy[256];
    printf("Enter elements: ");
    fgets(line, 256, stdin);
	strcpy(linecopy, line);
	char *token, *token2;
	int count = 0;
	
	token = strtok(line, " ");
	
	while( token != NULL ) {
      token = strtok(NULL, " ");
      count++;
   }
	int arrayofnumbers[count];
	int secondcount = 0;
	
	token2 = strtok(linecopy, " ");
	
	while( token2 != NULL ) {
      arrayofnumbers[secondcount++] = atoi(token2);
      token2 = strtok(NULL, " ");
   }
   printf("There are %d numbers in the input you entered...\n", count);
   int i;
   printf("Elements in array :\n");
   for(i = 0; i < secondcount; i++){
   		printf("%d\n", arrayofnumbers[i]);
   }
    
    
    return 0;
}
