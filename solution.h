#ifndef SOLUTION_H_INCLUDED
#define SOLUTION_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define nmax 10
extern const int size;



 extern int board_buline[nmax][nmax];
 extern int board_zone[nmax][nmax];

bool gasit( int a, int b, int i );
void generate_coord();
void generate_board_buline();

void create_board_zone();

void possible_solution(int pstart);
bool OK();

void afisare(int board[nmax][nmax]);

void solution(int &found);

void insert_buline(int nrbulina);
void generare_grupa1();

void generare_grupa2();


void generare_grupa4();


void generare_grupa(int nbul);

#endif // SOLUTION_H_INCLUDED
