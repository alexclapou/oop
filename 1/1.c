#include <stdio.h>
#include <string.h>

int main()
{
    int compare_result;
    char text[100];

    scanf("%s", text);
    while(1)
    {
        compare_result = strcmp(text, "exit");
        if(compare_result == 0)
            return 0;
        printf("%s", text);
        printf("%c", '\n');
        scanf("%s", text);
    }
    scanf("%s", text);
    return 0;
}
/*
 #include <stdio.h>
 #include <string.h>

 int main()
 {
     int a;
     char text[100];

     scanf("%s", text);
     printf("%s", text);
     return 0;
 }
*/
