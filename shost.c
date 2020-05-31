#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
void setcolor(unsigned short color)
{
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hcon,color);

}
int con(int maxc)
{
    int restd;
    restd=256;
    int result;

    result=256-restd;
    return(result);
}

int main()
{
    int xr;
    xr=con(128);
    printf("nubmer of subnets :%d \n",xr);
}



