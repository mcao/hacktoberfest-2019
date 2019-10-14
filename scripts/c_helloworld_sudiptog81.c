/** 
 * LANGUAGE: C
 * ENV: GCC 8.1.0
 * AUTHOR: Sudipto Ghosh
 * GITHUB: https://github.com/sudiptog81
 */

#include <stdio.h>
#include <stdlib.h>

char *greet(char *name)
{
    char *result = malloc(255 * sizeof(char));
    sprintf(result, "%s, it's time to contribute!\n", name);
    return result;
}

int main()
{
    printf("Hello World!\n");
    char *res = greet("Fellow GitHub User");
    printf("%s", res);
    free(res);
    return 0;
}