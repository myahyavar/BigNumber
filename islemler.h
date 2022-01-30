/*
* @file islemler.h
* @description Big Number
* @assignment Project 2
* @date 23.01.2022
* @author Muhammed Yahya Avar muhammed.avar@stu.fsm.edu.tr
*/
#include <stdint.h>

#define ISLEMLER_C
uint8_t *readNum(char *fileName);
int numLength(char *fileName);
void writeNum(uint8_t *num, int length);
void *reverse(uint8_t *num, int length);
int sumLength(int length1, int length2);
int exchange(uint8_t *num);
uint8_t *add(uint8_t *num1, uint8_t *num2, int length1, int length2);
void writeSum(char *filename, uint8_t *sum, int length); 