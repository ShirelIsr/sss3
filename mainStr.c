#include <stdio.h>
#include "txtfind.h"

int main()
{
    char word[WORD] = {'\0'};
    char index=getc(stdin);
    char op='\0';
    int i = 0;
    while (index != ' ')
    {
        word[i] = index;
        index = getc(stdin);
        i++;
    }
    word[i] = '\0';
    while((index != '\n') )
    {
        if(index =='a') op='a';
        if(index =='b') op='b';
         index=getc(stdin);
    }
    char first[1];
     i=getLine(first);
    //printf("%s ",word);
    //printf("%c \n",op);
    switch(op){
    case 'a':
        print_lines(word);
        break;
    case 'b':
        print_similar_words(word);
        break;
    default:
        printf("invalid input");
    }
    return 0;
}