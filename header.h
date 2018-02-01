#include<iostream>
using namespace std;

#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<math.h>
#include<sstream>
#include<time.h>
#include<bitset>
int i;
class PROGRAM
{
public :
    string inst, memloc;
    bool b;
};

class MEMORYUSED
{
    public:
            string loc, info;

};

char name[50];
string start="2000", pc, locctr, line, ins, cmd[5], deb="", A="00", B="00", C="00", D="00", E="00", H="00", L="00", M="00", END ;
PROGRAM p[100];
int memoindex=0, index=0, SF=0, ZF=0, PF=0, AF=0, CF=0;
MEMORYUSED memo[20];
