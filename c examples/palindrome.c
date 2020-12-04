#include <stdio.h> 
#include <string.h> 
#include <stdbool.h> 

int is_palindrome(int start, int end, char *str)
{
    if (str[start] != str[end])
        return 0;
    else if (start == end)
        return 1;
    else
        return is_palindrome(++start, --end, str);

    return 0;

}


int main()
{
    int size;
	printf("Enter size of String.\n");
    scanf("%d\n", &size);
    
    if(size <= 0){
    	printf("Error with size");
		return 0;
	}
    
    char str[size];
    printf("Enter your string to check if it is palindrome");
    fgets( str, sizeof( str ), stdin );
    puts(str);
    printf("%s dsasaddaadas", str);
    
    
    
    return 0;
    
}
