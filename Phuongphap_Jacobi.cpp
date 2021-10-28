//Phuong Phap Jacobi
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int main(){
    double a[10][10],x[10],y[10];
    int i,j,n;
    char ch;
    cout<<"Enter n: ";
    cin>>n;
    for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++)
                {
                    cout<<"a"<<i<<j<<" = ";
                    cin>>a[i][j];
                }
            cout<<"b"<<i<<" = ";
            cin>>a[i][j];
            x[i] = y[i] = 0;
        }
    cout<<endl<<"The results are as follows...."<<endl<<
           "press 'enter' key to continue iterations &"
           " press 'q' to stop iterations...."<<endl;
    while(ch != 'q')
        {
            for(i = 1; i <= n; i++){
                    for(j = 1; j <= n; j++)
                        {
                            if(i == j) continue;
                            x[i] = x[i] - a[i][j]*y[j];
                        }
                    x[i] = x[i] + a[i][j];
                    x[i] = x[i]/a[i][i];
                }
            for(i = 1; i <= n; i++){
                    y[i] = x[i];
                    cout<<"x"<<i<<" = "<<x[i];
                    x[i] = 0;
                }
            ch = getch();
            cout<<endl;
        }
}
