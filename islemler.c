/*
* @file islemler.c
* @description Big Number
* @assignment Project 2
* @date 23.01.2022
* @author Muhammed Yahya Avar muhammed.avar@stu.fsm.edu.tr
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "islemler.h"

uint8_t *readNum(char *fileName)
{
    int i = 0;
    char *num;
    uint8_t *numU;
    num = (char *)malloc(numLength(fileName));
    numU = (uint8_t *)malloc(numLength(fileName));

    FILE *file;
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        puts("Couldn't Open File");
    }
    while ((*(num + i) = fgetc(file)) != EOF)
    {
        if (*(num + i) == '\n')
        {
            continue;
        }
        else
        {
            *(numU + i) = *(num + i);
            i++;
        }
    }
    fclose(file);
    free(num);
    *(numU + i) = '\0';
    return numU;
}

int numLength(char *fileName)
{
    int length = 0;
    char *num;
    num = (char *)malloc(sizeof(char));

    FILE *file;
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        puts("Couldn't Open File");
    }

    while ((*(num + length) = fgetc(file)) != EOF)
    {
        if (*(num + length) == '\n')
        {
            continue;
        }
        else
        {
            num = (char *)realloc(num, strlen(num) + sizeof(char));
            length++;
        }
    }
    fclose(file);
    free(num);

    return length;
}

void writeNum(uint8_t *num, int length)
{
    int i;
    for (i = 0; i <= length; i++)
    {
        printf("%c", *(num + i));
    }
}

void *reverse(uint8_t *num, int length)
{
    int i, j, temp;
    for (i = 0, j = length - 1; i < j; i++, j--)
    {

        temp = *(num + i);
        *(num + i) = *(num + j);
        *(num + j) = temp;
    }
}

int sumLength(int length1, int length2)
{
    int resLength;
    if (length1 <= length2)
        resLength = length2;
    else
        resLength = length1;

    return resLength;
}

int exchange(uint8_t *num)
{
    uint8_t *tmp1 = (uint8_t *)calloc(2, sizeof(uint8_t));
    int t;
    strncpy(tmp1, num, 1);
    t = atoi(tmp1);
    return t;
}

uint8_t *add(uint8_t *num1, uint8_t *num2, int length1, int length2)
{
    int a, b, c = 0, g, i = 0, d, j;
    reverse(num1, length1);
    reverse(num2, length2);

    if (length1 <= length2)
        g = length2;
    else
        g = length1;

    uint8_t *sum = (uint8_t *)malloc(g);
    while (i <= g)
    {
        j = i;
        a = 0;
        b = 0;
        if ((i + 1) <= length1)
            a = exchange(num1 + i);
        if ((j + 1) <= length2)
            b = exchange(num2 + j);
        if ((a + b + c) > 10)
        {
            d = ((a + b + c) % 10);
            *(sum + i) = d;
            c = 1;
        }
        else if ((a + b + c) < 10)
        {
            *(sum + i) = (a + b + c);
            c = 0;
        }
        if ((a + b + c) == 10)
        {
            *(sum + i) = 0;
            c = 1;
        }
        i++;
    }
    reverse(sum, g);
    return sum;
}

void writeSum(char *filename, uint8_t *sum, int length)
{

    int n;
    for (n = 0; n < length; n++)
    {
        printf("%d", *(sum + n));
    }

    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Couldn't Open File");
    }

    for (int i = 0; i < length; i++)
        fprintf(fp, "%d", *(sum + i));
    puts("");
    fclose(fp);
}