#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>


    /**< this program is  used to calculate the following */
    /** Network ID
     *  First IP
     *  Last IP
     *  Broadcast ID
     *
     */

void setcolor(unsigned short color)
{
    HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}

    int oc1;//fist octet
    int oc2;//second octet
    int oc3;//third octet
    int oc4;//forth octet
    int sc1;//1 octet
    int sc2;//2 octet
    int sc3;//3 octet
    int sc4;//4 octet
    char dot;

    int ahost(int clhost)
{   int value;
    value=16777214;

    int result;
        result=value-clhost;
    return(result);
}

int classA()
{
    setcolor(3);
    int netid3;//network id for octet 3
    int netid4;//......  .. .. ...... 4
    int nresultz;//..... .. .. .....  2
    int bsresult;
    int brdresult;//broadcast results
    int lpresult;
    int fpresult;
     int rhost;
     int raddhost;//result of the add 2
    int rsqrthost;// result of the sqrt
    int rsub; //sbnet minus that value
    int rsun;// number of subnets
    int ask;
    int hostresult;//host results
    printf("you have chosen class A \n");
    printf("Enter your IP Address \n");
    scanf("%d",&oc1);
    scanf("%c",&dot);
    scanf("%d",&oc2);
    scanf("%c",&dot);// reading the dots and the numbers together
    scanf("%d",&oc3);
    scanf("%c",&dot);
    scanf("%d",&oc4);
    printf("IP ADDRESS : %d%c%d%c%d%c%d \n",oc1,dot,oc2,dot,oc3,dot,oc4);
    printf("\n");
    printf("Enter your subnet mask \n");
    scanf("%d",&sc1);
    scanf("%c",&dot);
    scanf("%d",&sc2);
    scanf("%c",&dot);// reading the dots and the numbers together
    scanf("%d",&sc3);
    scanf("%c",&dot);
    scanf("%d",&sc4);
    printf("SUBNET  MASK :%d%c%d%c%d%c%d \n",sc1,dot,sc2,dot,sc3,dot,sc4);
printf("------------------------------RESULTZ-------------------------------------\n");

  rhost=ahost(sc2);
    raddhost=rhost+2;
    printf(" MAX NUMBER OF HOSTS :%d \n",raddhost);
   rsqrthost= sqrt(raddhost);
    printf("BITS PER HOST : %d \n",rsqrthost);
    rsub=8-rsqrthost;
    printf("BITS PER SUBNET: %d \n",rsub);
    printf("MAX NUMBER OF SUBNETS: %c \n",rsun);

    bsresult=bsize(sc2);//broad cast result function
    printf("BLOCK SIZE    : %d \n",bsresult);
    netid3=netcal(sc3,oc3);
    netid4=netcal(sc4,oc4);
  nresultz=netcal(sc2,oc2);
  {
      printf("NETWORK ID    : %d%c%d%c%d%c%d \n",oc1,dot,nresultz,dot,netid3,dot,netid4);
  }
  brdresult=brodcast(nresultz,bsresult);
  {
       printf("BROADCAST ID: %d%c%d%c%d%c%d \n",oc1,dot,brdresult,dot,netid3,dot,netid4);
  }
  fpresult=firstip(nresultz);
  {
      printf("FIRST IP ADDRESS : %d%c%d%c%d%c%d \n ",oc1,dot,fpresult,dot,netid3,dot,netid4);
  }
  lpresult=lastip(brdresult);
  {
      printf("LAST IP ADDRESS : %d%c%d%c%d%c%d \n",oc1,dot,lpresult,dot,netid3,dot,netid4);
  }
    if(oc1==110) printf("PRIVATE \n");
    else printf("       PUBLIC NETWORK \n");
    return 0;
}

int bhost(int clhost)
{   int value;
    value=65534;

    int result;
        result=value-clhost;
    return(result);
}

int classB()
{
    setcolor(3);
    int netresult;
    int bsresult;
    int nresultz;
    int brdresult;
    int lpresult;
    int fpresult;
     int rhost;
     int raddhost;//result of the add 2
    int rsqrthost;// result of the sqrt
    int rsub; //sbnet minus that value
    int rsun;// number of subnets
    int ask;
    int hostresult;//host results
    printf("you have chosen class B \n");
     printf("Enter your IP Address\n");
    scanf("%d",&oc1);
    scanf("%c",&dot);
    scanf("%d",&oc2);
    scanf("%c",&dot);
    scanf("%d",&oc3);// reading the dots and the numbers together
    scanf("%c",&dot);
    scanf("%d",&oc4);
    printf("IP ADDRESS : %d%c%d%c%d%c%d \n",oc1,dot,oc2,dot,oc3,dot,oc4);
    printf("\n");
    printf("Enter your subnet mask\n");
    scanf("%d",&sc1);
    scanf("%c",&dot);// reading the dots and the numbers together
    scanf("%d",&sc2);
    scanf("%c",&dot);
    scanf("%d",&sc3);
    scanf("%c",&dot);
    scanf("%d",&sc4);
    printf("SUBNET  MASK :%d%c%d%c%d%c%d \n",sc1,dot,sc2,dot,sc3,dot,sc4);
     printf("------------------------------RESULTZ-------------------------------------\n");

     rhost=bhost(sc3);
    raddhost=rhost+2;
    printf(" MAX NUMBER OF HOSTS :%d \n",raddhost);
   rsqrthost= sqrt(raddhost);
    printf("BITS PER HOSTS : %d \n",rsqrthost);
    rsub=8-rsqrthost;

    printf("BITS PER SUBNETS : %d \n",rsub);
    printf("MAX NUMBER OF SUBNETS : %c \n",rsun);

    bsresult=bsize(sc3);//broad cast result function
    printf("BLOCK SIZE    : %d \n",bsresult);

   netresult=netcal(sc4,oc4);
  nresultz=netcal(sc3,oc3);
  {
      printf("NETWORK ID    : %d%c%d%c%d%c%d \n",oc1,dot,oc2,dot,nresultz,netresult);
  }
  brdresult=brodcast(nresultz,bsresult);
  {
       printf("BROADCAST ID: %d%c%d%c%d%c%d \n",oc1,dot,oc2,dot,brdresult,dot,netresult);
  }

  fpresult=firstip(nresultz);
  {
      printf("FIRST IP ADDRESS : %d%c%d%c%d%c%d \n ",oc1,dot,oc2,dot,oc3,fpresult,dot,netresult);
  }

  lpresult=lastip(brdresult);
  {
      printf("LAST IP ADDRESS : %d%c%d%c%d%c%d \n",oc1,dot,oc2,dot,lpresult,dot,netresult);
  }
    if(oc1==172);
    if (oc2==16) printf("PRIVATE \n");
    else printf("      PUBLIC NETWORK \n");
    exit(3);
}
int chost(int clhost)
{   int value;
    value=254;

    int result;
        result=value-clhost;
    return(result);
}

int classC()
{
    setcolor(3);
    int nresultz;
    int bsresult;
    int brdresult;
    int lpresult;
    int fpresult;
    int rhost;
     int raddhost;//result of the add 2
    int rsqrthost;// result of the sqrt
    int rsub; //sbnet minus that value
    int rsun;// number of subnets
    int ask;
    int hostresult;//host results
    printf("you have chosen class C \n");
    printf("Enter your IP Address\n");
    scanf("%d",&oc1);
    scanf("%c",&dot);
    scanf("%d",&oc2);// reading the dots and the numbers together
    scanf("%c",&dot);
    scanf("%d",&oc3);
    scanf("%c",&dot);
    scanf("%d",&oc4);
    printf("IP ADDRESS : %d%c%d%c%d%c%d \n",oc1,dot,oc2,dot,oc3,dot,oc4);
    printf("\n");
    printf("Enter your subnet mask\n");
    scanf("%d",&sc1);
    scanf("%c",&dot);
    scanf("%d",&sc2);
    scanf("%c",&dot);// reading the dots and the numbers together
    scanf("%d",&sc3);
    scanf("%c",&dot);
    scanf("%d",&sc4);
    printf("SUBNET  MASK :%d%c%d%c%d%c%d \n",sc1,dot,sc2,dot,sc3,dot,sc4);
    printf("------------------------------RESULTZ-------------------------------------\n");

rhost=chost(sc4);
    raddhost=rhost+2;
    printf(" MAX NUMBER OF HOSTS :%d \n",raddhost);
   rsqrthost= sqrt(raddhost);
    printf("BITS PER HOSTS    : %d \n",rsqrthost);
    rsub=8-rsqrthost;
    printf("BITS PER SUBNETS    : %d \n",rsub);
    printf("MAX NUMBER OF SUBNETS  : %c \n",rsun);

    bsresult=bsize(sc4);//broad cast result function
    printf("BLOCK SIZE    : %d \n",bsresult);

    nresultz=netcal(sc4,oc4);
  {
      printf("NETWORK ID    : %d%c%d%c%d%c%d \n",oc1,dot,oc2,dot,oc3,dot,nresultz);
  }

  brdresult=brodcast(nresultz,bsresult);
  {
       printf("BROADCAST ID: %d%c%d%c%d%c%d \n",oc1,dot,oc2,dot,oc3,dot,brdresult);
  }
    fpresult=firstip(nresultz);
  {
      printf("FIRST IP ADDRESS : %d%c%d%c%d%c%d \n ",oc1,dot,oc2,dot,oc3,dot,fpresult);
  }

  lpresult=lastip(brdresult);
  {
      printf("LAST IP ADDRESS : %d%c%d%c%d%c%d \n",oc1,dot,oc2,dot,oc3,dot,lpresult);
  }
    int hostt;
    hostt=subhost(sc4);

    if(oc1==192) printf("PRIVATE \n");
    else printf("      PUBLIC NETWORK \n");
    return 0;
}

int netcal(int x,int y)
{
    int result;
    result=x&y;
    return(result);
}
int hostcal(int b)
{
    return(b);
}
int bsize(int x)//function for calculating blocksize
{   int result;
    result=256-x;
    return(result);
}
int brodcast(int netd,int bs) //function for calculating broadcast id
{
    int result;
    result=netd+bs-1;
    return(result);
}
int firstip(int netd)// first ip address function
{
    int result;
    result=netd+1;
    return(result);
}
int lastip(int broadcast)//last ip address function
{
    int result;
    result=broadcast-1;
    return(result);
}
int subhost(int octet)//un done function
{
    int binary;
    int ot=128;
    int j=0;
    int arrt[8] ={128,64,32,16,8,4,2,1};
    int arr[8];
    int i;
    for(i=0;i<8;i++)
    {
        if((octet-ot)<0)
        {
            arr[j]=0;
        }
        else
        {
            j=0;
            arr[j]=1;
            j++;
            ot+=arrt[i];
        }

        {
            j++;
            if(octet-ot<0)
            {
                arr[j]=0;
            }
            else
            {
                arr[j]=0;
                ot+=arrt[i];
            }
        }
    }
    for(i=0;i++;i<8)
    {
        binary+=arr[i];
    }
return(binary);
}
void exat()
{
    exit(1);
}

int main()
{


    int oc1;
    int oc2;
    int oc3;
    int oc4;
    char classc;
    setcolor(9);
    printf("Enter Class code e.g ___A____B____C____ or ___E__ to EXIT\n");
    scanf("%c",&classc);
    switch(classc)
   {
    case 'A':
        classA();
        break;
    case 'B':                       
        classB();
        break;
    case 'C':
        classC();
        break;
    case 'E':
        exat();// the exit function
        break;
        default: printf("subnet generator Ver.1.0 \n");
    }
    exit(12);
}
