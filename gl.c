#include "main.h"
char *the_holy_getline() {
static char the_buffer[1000]; /*cin chars and store it*/
static int buffer_idx = 0; /* track buf's position */
static int num_chars = 0; /*char's nums*/

char* ll = NULL; /* the final line*/
int line_index = 0; /*track ll's position*/

while (1) {
if (buffer_idx == num_chars) {
	printf("before read\n");
num_chars = fread(the_buffer, sizeof(char), sizeof(char), stdin);
buffer_idx = 0;
printf("fread\n");

if (num_chars == 0)
break;
}


if (the_buffer[buffer_idx] == '\n') {
buffer_idx++;
printf("new line\n");
break;
}

ll = realloc(ll, (line_index + 1) * sizeof(char));
ll[line_index++] = the_buffer[buffer_idx++];
printf("loop\n");
}

if (line_index > 0) {
ll = realloc(ll, (line_index + 1) * sizeof(char));
ll[line_index] = '\0';
printf("last if\n");
}
printf("I am out!\n");

return ll;
}
