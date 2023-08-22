#include <stdio.h>
#include <string.h> // Include the string.h header for strcpy function
#include <unistd.h>

#include <stdlib.h>
#include <sys/types.h>



#define MAX_COMAND_LENGTH 1024
#define MAX_PATH_LENGTH 1024

int main() 
{
char input_text[MAX_COMAND_LENGTH];
char *args[MAX_COMAND_LENGTH];
size_t n;

// path : 
char *path = "/bin";

while (1)
{
    /* code */
    printf("#ayoub~~:");
    //allocate some place memory for the use to input MAX8COMMAND
    input_text = (char *)malloc(n * sizeof(char));
    if(input_text == NULL)
    {
        perror("Memory error");
        return (EXIT_FAILURE);
    }
    //now lets read the uer input with getline function
    
}


}
