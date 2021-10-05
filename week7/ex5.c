#include <stdio.h>
int main() {
char **s;
char foo[] = "Hello World";
//i should to allocate memory to my array of string to assign an element to the first place.
s = malloc(sizeof(foo));
*s = foo; //same as s[0]= foo
printf("s is %s\n",s);
s[0] = foo;
printf("s[0] is %s\n",s[0]);
return(0);
}
