#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Game check41
int n[26] = {0};

int check8(int n[], int i)
{
    int y=8,r=7,g=3,y1=8,r1=7,g1=3,p=-1,num=0,k,j;
    for (j = 1; j <= i; j++)
    {
        if (n[j]==p||p==-1)
        {
            p=n[j];
            if(y1!=0)
                y1--;
            if(r1!=0)
                r1--;
            if(g1!=0)
                g1--;
        }
        else
        {
            switch(n[j])
            {
            case 0:
                y+=(r-r1+g-g1);
                r=r1;
                g=g1;
                break;
            case 1:
                r+=(y-y1+g-g1);
                g=g1;
                y=y1;
                break;
            case 2:
                g+=(y-y1+r-r1);
                y=y1;
                r=r1;
                break;
            }
            y1=y;
            r1=r;
            g1=g;
            p=-1;
        }
    }
    if (r==6&&y==6&&g==6)
        return 1;
    return 0;
}

int check9(int n[], int i)
{
    int y=8,r=7,g=3,y1=8,r1=7,g1=3,p=-1,num=0,k,j;
    for (j = 1; j <= i; j++)
    {
        if (n[j]==p||p==-1)
        {
            p=n[j];
            if(y1!=0)
                y1--;
            if(r1!=0)
                r1--;
            if(g1!=0)
                g1--;
        }
        else
        {
            switch(n[j])
            {
            case 0:
                y+=(r-r1+g-g1);
                r=r1;
                g=g1;
                break;
            case 1:
                r+=(y-y1+g-g1);
                g=g1;
                y=y1;
                break;
            case 2:
                g+=(y-y1+r-r1);
                y=y1;
                r=r1;
                break;
            }
            y1=y;
            r1=r;
            g1=g;
            p=-1;
        }
    }
    if (r==9&&y==2&&g==7)
        return 1;
    return 0;
}

int check35(int n[], int i)
{
    int x=3,y=3,m,t,p=3,sum=0,k,j;
    int a[7][7]= {0};
    a[2][1]=1;
    a[3][2]=1;
    a[2][5]=1;
    a[5][4]=1;
    a[3][5]=2;
    for (j = 1; j <= i; j++)
    {
        switch (n[j])
        {
        case 0:
            p=p%3+2;
            break;
        case 1:
            t=-x+p;
            m=y-3;
            x=p+m;
            y=3+t;
            if (y<0||x>6||y>6||x<0)
                return 0;
            if (a[x][y]==2)
                y--;
            a[x][y]=0;
            break;
        case 2:
            p=(p-1)%3+2;
            break;
        }
    }
    for (j=0; j<=6; j++)
    {
        for (k=0; k<=6; k++)
        {
            sum+=a[j][k];
        }
    }
    if (sum==2)
        return 1;
    return 0;
}

void switchabc(int *q, int*w, int*e)
{
    int t;
    if(*w>*e)
    {
        t= *w;
        *w = *e;
        *e = t;
    }
    if (*w<*q)
    {
        t = *w;
        *w = *q;
        *q = t;
    }
    if(*w>*e)
    {
        t= *w;
        *w = *e;
        *e = t;
    }
}

int check41(int n[], int i)
{
    int j,light[3][3]= {0,0,0,0,0,0,1,0,0},t,k,sum=0;
    for (j = 1; j <= i; j++)
    {
        switch (n[j])
        {
        case 0:
            t=light[0][2];
            light[0][2]=light[0][1];
            light[0][1]=light[0][0];
            light[0][0]=t;
            break;
        case 1:
            t=light[2][2];
            light[2][2]=light[1][1];
            light[1][1]=light[0][0];
            light[0][0]=t;
            t=light[2][1];
            light[2][1]=light[1][0];
            light[1][0]=t;
            t=light[1][2];
            light[1][2]=light[0][1];
            light[0][1]=t;
            break;
        case 2:
            light[1][0]=1-light[1][0];
            light[2][0]=1-light[2][0];
            light[0][0]=1-light[0][0];
            break;
        }
    }
    for (t=0; t<=2; t++)
    {
        for (k=0; k<=2; k++)
        {
            sum=sum+light[t][k];
        }
    }
    if (sum==9)
        return 1;
    return 0;
}


int check42(int n[], int i)
{
    int j,light[3][3]= {0,0,0,0,0,0,0,0,0},t,k,sum=0;
    for (j = 1; j <= i; j++)
    {
        switch (n[j])
        {
        case 0:
            t=light[2][2];
            light[2][2]=light[1][2];
            light[1][2]=light[0][2];
            light[0][2]=t;
            t=light[2][1];
            light[2][1]=light[1][1];
            light[1][1]=light[0][1];
            light[0][1]=t;
            break;
        case 1:
            light[0][2]=1-light[0][2];
            light[1][1]=1-light[1][1];
            light[2][0]=1-light[2][0];
            break;
        case 2:
            t=light[0][0];
            light[0][0]=light[0][1];
            light[0][1]=light[0][2];
            light[0][2]=t;
            t=light[1][0];
            light[1][0]=light[1][1];
            light[1][1]=light[1][2];
            light[1][2]=t;
            break;
        }
    }
    for (t=0; t<=2; t++)
    {
        for (k=0; k<=2; k++)
        {
            sum=sum+light[t][k];
        };
    }
    if (sum==9)
        return 1;
    return 0;
}



int check15(int n[], int i)
{
    int j, a = 3, b = 4, c = 5, mode = 1;
    for (j = 1; j <= i; j++)
    {
        switch (n[j])
        {
        case 0:
            if (mode == 0)
            {
                c = (c+5)%7+1;
                a = (a+5)%7+1;
                b = (b+5)%7+1;
            }
            else
            {
                switchabc(&a,&b,&c);
                if (a == 1)
                {
                    if (b == 2)
                    {
                        if (c!= 3)
                            c = (c+5)%7+1;
                    }
                    else
                    {
                        c = (c+5)%7+1;
                        b = (b+5)%7+1;
                    }
                }
                else
                {
                    c = (c+5)%7+1;
                    a = (a+5)%7+1;
                    b = (b+5)%7+1;
                }
            }

            break;
        case 1:
            mode = 1 - mode;
            break;
        case 2:
            if (mode == 0)
            {
                a = (a % 7)+1;
                b = (b % 7)+1;
                c = (c % 7)+1;
            }
            else
            {
                switchabc(&a,&b,&c);
                if (c == 7)
                {
                    if (b == 6)
                    {
                        if (a != 5)
                            a = (a % 7)+1;
                    }
                    else
                    {
                        a = (a % 7)+1;
                        b = (b % 7)+1;
                    }
                }
                else
                {
                    a = (a % 7)+1;
                    b = (b % 7)+1;
                    c = (c % 7)+1;
                }
            }
            break;
        }
    }
    switchabc(&a,&b,&c);
    if (a == 1 && b == 4 && c == 6)
        return 1;
    return 0;
}
int check60(int n[], int i)
{
    int q = -4, w = 0, e = 4, a = 16, s = -21, d = 5, j;
    for (j = 1; j <= i; j++)
    {
        switch (n[j])
        {
        case 0:
            a -= 2;
            s += 2;
            d--;
            w++;
            e--;
            q++;
            break;
        case 1:
            w -= 3;
            a++;
            s++;
            d++;
            break;
        case 2:
            q--;
            w++;
            s--;
            e++;
            break;
        }
    }
    if (a == 0 && s == 0 && d == 0 && q == 0 && w == 0 && e == 0)
        return 1;
    return 0;
}

int check17(int n[], int i)
{
    int j, k, l, a = 5, b = 5, c = 5;
    for (j = 1; j <= i; j++)
    {
        switch (n[j])
        {
        case 0:
            a = (a + 1) % 10;
            b = (b + 1) % 10;
            break;
        case 1:
            b = 9 - b;
            break;
        case 2:
            b = (b + 9) % 10;
            c = (c + 9) % 10;
            break;
        }
    }
    if (a + b + c == 0)
        return 1;
    return 0;
}

int main()
{
    //printf("qqq");

    int i, j, k, l, N, max, flag = 0;
    for (i = 1; i < 16; i++)
    {
        max = (int)(pow(3, i) + 0.00001);
        for (k = 0; k < max; k++)
        {
            N = k;
            if (k==39483&&i==10)
                printf("rrrrr");
            for (j = 0; j <= 25; j++)
                n[j] = 0;
            for (j = i - 1; j >= 0; j--)
            {

                n[j + 1] = (int)(N / pow(3, j));
                N = N % (int)(pow(3, j));
            }
            if (Game(n, i))
            {
                printf("%d steps are enough,here's the answer:", i);
                for (l = 1; l <= i; l++)
                {
                    printf("%2d", n[l] + 1);
                    if(l%5==0)
                        printf(" ");
                }

                printf("\n");
                flag = 1;
                return 0;
            }
        }
        if (flag == 0)
            printf("Until %d has been tried,no answer!!!!\n", i);
    }
    if (flag == 0)
        printf("NO ANSWER!!!!\n");
    return 0;
}
