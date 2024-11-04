#include <stdio.h>
#include <stdlib.h>
static int z=50;

int*fu7()
{
    return &z;
}

/***************************************/
int sumbet(int*p1,int*p2)//to sum numbers between them
{
    int sum=0,i;
    for(i=(*p1+1); i<*p2; i++)
    {
        sum=sum+i;

    }
    return sum;

}
/*************************************************/
int findmax(int*p1,int*p2)// enter (no of itration, and first num )
{
    int i,max=0;

    for(i=0; i<*p1-1; i++)
    {
        printf("enter num fun\n");
        if(max<*p2)
            max=*p2;
        scanf("%d",p2);


    }
    return max;

}


/*************************************************/
int sumtot(int*p1,int*p2)// enter (no of itration, and first num )
{
    int i,sum=*p2;

    for(i=0; i<*p1-1; i++)
    {
        printf("enter num fun\n");
        scanf("%d",p2);
        sum=sum+*p2;
    }
    return sum;

}
/********************************/
int mult(int*p1,int*p2)
{
    int i,sum=0;
    for(i=0; i<*p1; i++)
    {
        sum=sum+*p2;
    }
    return sum;
}
/********************************/
int remin(int*p1,int*p2)
{
    if(*p1<*p2)
        return*p1;
    else
    {
        for(; *p1>=*p2;)
        {
            *p1=*p1-*p2;
        }
        return*p1;
    }
}
/********************************************/
int pow(int*p1,int*p2)
{
    int res=1;
    for(int i=0; i<*p2; i++)
    {
        res=res*(*p1);
    }
    return res;
}
/*******************************************/
int fact(int x)
{
    int i,res=1;
    for(i=1; i<=x; i++)
    {
        res=res*i;
    }
    return res;
}
/****************************************/
/*void isprime(int x)
{
    if(x==0||x==1)
    {
        printf("not prime\n");
        return;
    }

    for(int i=2; i<=(x/2); i++)
    {
        if(x%i==0)
        {
            printf("not prime\n");

            return;
        }
    }
    printf("prime\n");

}*/
/*******************************************/
void isperftsqu(int x)
{

}

/*********************************************/

/*****************************************************/
#include <stdio.h>
#include<stdlib.h>

int sumbet_even(int x)
{
   static int sum=0;
   static int count;
   if(x%2==0)
   {
       sum+=x;
       count=0;
   }
   else
   {
       count++;
       if(count==2)
       {
           printf("bye\n");
           return;
       }
   }
   return sum;
}
/*************************************************************************/
#include <stdio.h>
#include<stdlib.h>

int sumhol_num(int x)
{
    int sum,z=0,p=0;
    int rem,n;
    while(x)
    {
        rem=x%10;
        if(rem==1||rem==2||rem==3||rem==5||rem==7)
        {
          n=0;
        }
        else if(rem==4||rem==6||rem==9||rem==0)
        {
            z+=1;
        }
       else
        {
           p+=2;
        }

        x=x/10;
    }
      sum=n+p+z;

    return sum;
}

/*****************************************************************/
#include <stdio.h>

void numchar(int x, char c)
{
    if(x % 2 == 0)
    {
        printf("char is = %c\n", c);
    }
    else
    {
        if((c >= 'a') && (c <= 'z'))
        {
            printf("other form is %c\n", c - 'a' + 'A');
        }
        else
        {
            printf("other form is %c\n", c - 'A' + 'a');
        }
    }
}

/***************************************************************************/
#include <stdio.h>

void revnum(int x)
{
    int res;
    while(x)
    {
      int rem=x%10;
      res=(res*10)+rem;
      x=x/10;
    }
    printf("result is %d\n",res);

}


/*********************************************************************************/
#include <stdio.h>

int no_of_ones(int x)
{
    int i;
    while(x)
    {
        if(x&1)
        {
          i++;
        }
        else
        {

        }
        x=x>>1;
    }
    return i;

}


/********************************************************************************************/
#include <stdio.h>

void binary(unsigned char x)
{
    int i,flag=0;
    for(i=31;i>=0;i--)
    {
        if((x>>i)&1)
        {
          printf("1");
          flag=1;
        }
        else if(flag)
        {
          printf("0");
        }
        //x=x>>1;
    }
    return i;

}
int sum_bet_short(int x, int y)
{
    int r=y-x+1;
    int res=r*x+(r*(y-x))/2;
    return res;
}
/*******************************/
float fun32(int n)
{
    return 2.5*n;
}
char fun145(void)
{
  return 300;
}





