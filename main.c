/*
* @file main.c
* @description Big Number
* @assignment Project 2
* @date 23.01.2022
* @author Muhammed Yahya Avar muhammed.avar@stu.fsm.edu.tr
*/
#include <stdio.h>
#include <stdlib.h>
#include "islemler.h"

int main()
{
    uint8_t *num1, *num2, *result;
    int lnum1, lnum2, lres;
    int input;

    while (1)
    {
        puts("==================Buyuk sayilar ile matematiksel islemler=================");
        puts("[1]-> Dosyadan sayilari oku");
        puts("[2]-> Okunan sayilari ekrana yaz");
        puts("[3]-> Sayilari Topla");
        puts("[4]-> Sonucu Yazdir");
        puts("[5]-> Cikis");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            num1 = readNum("sayi1.txt");
            num2 = readNum("sayi2.txt");
            lnum1 = numLength("sayi1.txt");
            lnum2 = numLength("sayi2.txt");
            break;
        case 2:
            puts("First Number:");
            writeNum(num1, lnum1);
            puts("");
            puts("Second Number:");
            writeNum(num2, lnum2);
            puts("");
            break;
        case 3:
            result = add(num1, num2, lnum1, lnum2);
            break;
        case 4:
            puts("Sum of Two Numbers:");
            lres = sumLength(lnum1, lnum2);
            writeSum("sonuclar.txt", result, lres);
            break;
        case 5:
            free(num1);
            free(num2);
            free(result);
            return 0;
            break;
        default:
            puts("Wrong Input!");
            break;
        }
    }

}