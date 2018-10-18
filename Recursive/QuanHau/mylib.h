

void InBanCo(char bc[][100], int N)
{
    for(int i = 0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            cout<<bc[i][j]<<" ";
        cout<<endl;
    }
    cout<<"%%%%%%%%%%&&&&&&&&&&&&&&&&&&&&&&%\n";
}
bool XepDuocHau(int x, int y, char bc[][100], int N)
{
    for(int j = 0; j<=y; j++)
        if (bc[x-1][j-1] == 'H')
            return false;
    for(int i = x-1, j=y-1; i>=1, j>=1; i--, j--)
    {
        if (bc[i-1][j-1] == 'H')
            return false;
    }
    for(int i = x+1, j=y-1; i<=N, j>=1; i++, j--)
    {
        if (bc[i-1][j-1] == 'H')
            return false;
    }
    return true;
}
void XepHau(int c, char bc[][100], int N)
{
    if (c > N)
    {
        InBanCo(bc, N);
    }
    else
    {
        for(int i = 1; i<=N; i++)
        {
            if (XepDuocHau(i, c, bc, N))
            {
                bc[i-1][c-1] = 'H';
                XepHau(c+1, bc, N);
                bc[i-1][c-1] = '-';    
            }
        }
    }
}


















