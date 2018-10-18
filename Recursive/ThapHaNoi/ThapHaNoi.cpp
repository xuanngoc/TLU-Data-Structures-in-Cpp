#include <iostream>
using namespace std;


void ThapHaNoi(int N, char c1, char c2, char c3)
{
    if (N == 1)
    {
        cout<<c1<<" -- > "<<c3<<endl;
    }    
    else
    {
        ThapHaNoi(N-1, c1, c3, c2);
        ThapHaNoi(1, c1, c2, c3);
        ThapHaNoi(N-1, c2, c1, c3);
    }
}

int main()
{
    int N;
    cout<<"Nhap so tang: ";
    cin >>N;
    ThapHaNoi(N, '1', '2', '3');

    return 0;
}