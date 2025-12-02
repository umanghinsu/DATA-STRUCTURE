#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *intp = (int *)malloc(sizeof(int));
    char *charp = (char *)malloc(sizeof(char));
    float *floatp = (float *)malloc(sizeof(float));

    if(intp && charp && floatp)
    {
        *intp = 9;
        *charp = 'u';
        *floatp = 1.2;

        printf("%d\n",*intp);
        printf("%c\n",*charp);
        printf("%.2f\n",*floatp);

        free(intp);
        free(charp);
        free(floatp);
    }
    else
    {
        printf("memory alloacation is fail");
    }
}