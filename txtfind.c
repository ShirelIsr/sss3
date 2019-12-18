#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "txtfind.h"

int getLine(char s[])
{
    char c = getc(stdin);
    int i = 0;
    while ((i < LINE) && (c != '\n') && (c != EOF))
    {
        s[i] = c;
        c = getc(stdin);
        i++;
    }
    s[i] = c;
    return i;
}

int getWord(char w[])
{
    char c = getc(stdin);
    int i = 0;
    while ((i < WORD) && (c != '\n') && (c != ' ') && (c != '\t') && (c != EOF))
    {
        w[i] = c;
        c = getc(stdin);
        i++;
    }
    w[i] = '\0';
    return i;
}

int substring(char *str1, char *str2)
{
    int M = strlen(str2);
    int N = strlen(str1);
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        /* For current index i, check for 
        pattern match */
        for (j = 0; j < M; j++)
            if (str2[i + j] != str1[j])
                break;

        if (j == M)
            return 1;
    }
    return 0;
}

int similar(char *s, char *t, int n)
{
    int i = 0, j = 0, counter = 0;
    int sSize = strlen(s);
    int tSize = strlen(t);
    if ((sSize - tSize) != n)
        return 0;
    while (i < sSize && j < tSize)
    {
        if (*(s + i) == *(t + j))
        {
            i++;
            j++;
        }
        else
        {
            i++;
            counter++;
        }
    }
    if (counter > n)
        return 0;
    if (counter == n && i < sSize)
        return 0;
    return 1;
}

void print_lines(char *str)
{
    int flag = 1;
    while (flag)
    {
        char line[LINE]={'\0'};
        flag = getLine(line);
        for(int i=0;i<LINE;i++)
        {
            int j = 0;
            char w[WORD] = {'\0'};
            while ((j < WORD) && (line[i] != '\n') && (line[i] != ' ') && (line[i] != '\t'))
            {
                w[j] = line[i];
                i++;
                j++;
            }
             w[j]='\0';
            if (similar(w, str, 1) || similar(w, str, 0))
            {
              printf("%s", line);
                break;
            }
        }
    }
;}

void print_similar_words(char *str)
{
    int flag = 1;
    while (flag)
    {
        char w[WORD];
        flag = getWord(w);
        if (similar(w, str, 1) || similar(w, str, 0))
        {
            printf("%s \n", w);
        }
    }
}
