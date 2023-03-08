
#include <stdio.h>
int i,j;
int x[10][10];
void solution() 
{
    for ( i = 0; i <= 8; i++)
    { 
        for (j=0; j<=8; j++)
            printf("%d",x[i][j]);
        printf("\n");
    }
    printf("-------------------------------------------------------");
}

int check(int v, int r, int c)
{
    for (i=0; i<= r-1; i++)
        if (x[i][c] == v) return 0;
    for (i=0; i<= c-1; i++)
        if (x[r][i] == v) return 0;
    int I=r/3, J=c/3, m=r-3*I, n=c - 3*J;
    for (i=0; i<= m-1; i++)
        for (j=0; j<= 2; j++)
            if ( x[3*I+i][3*J + j] == v) return 0;
    for (i=0; i<= n- 1; i++)  
        if ( x[3*I+m][3*J + i] == v) return 0;
    return 1;
}

void TRY( int r, int c)
{
    int v;
    for (v=1; v<=9; v++) 
    {
        if (check(v,r,c) == 1) 
        {
            x[r][c] = v;
            if (r == 8 && c == 8) solution();
            else 
            {
                if (c==8) TRY(r+1,0);
                else TRY(r,c+1);
            }
        }
    }-
}

void main ()
{
    for ( i = 0; i <= 8; i++)
        for (j=0; j<=8; j++)
            scanf("%d",&x[i][j]);
    TRY(0,0);
}