#include<stdio.h>
#include<stdlib.h>

int main () {

    int h1,m1,s1,h2,m2,s2;
    do
    {
    printf("\nEntrer deux instants dans le format HH:MM:SS: ");
    scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
    } while (m1>=60 || m2>=60 || s1>=60 || s2>=60 );
    
    

    if (h1>h2)
        printf("\nLe deuxieme instant vient avant le premier;");
    else if (h1<h2)
        printf("\nLe premier instant vient avant le deuxieme");
    else {
        if (m1>m2)
            printf("\nLe deuxieme instant vient avant le premier;");
        else if (m1<m2)
            printf("\nLe premier instant vient avant le deuxieme");
        else {
                if (s1>s2)
                    printf("\nLe deuxieme instant vient avant le premier;");
                else if (s1<s2)
                    printf("\nLe premier instant vient avant le deuxieme");
                else printf("\nIl s'agit du meme instant");
        }
    }
    return 0;
}