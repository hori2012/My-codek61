//phuong phap khu Gauss
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 10
int main(){
	float A[MAX][MAX], B[MAX], X[MAX];
	int n,i,j,k;
	float s;
	cout<<"Phuong phap GAUSS !!"<<endl;
	cout<<"=============="<<endl;
	cout<<"Nhap so luong an n: ";
	cin>>n;
	cout<<endl;
	cout<<"Nhap cac he so cua x ( ma tran A)"<<endl;
	for(int i=1; i<=n;i++){
		for(int j=1; j<=n;j++){
			cout<<"a["<<i<<"]"<<"["<<j<<"] = ";
			cin>>A[i][j];
			cout<<endl;
		}
	}
	cout<<"Ma tran A da nhap : "<<endl;
	for(int i=1; i<=n;i++){
		for (int j=1; j<=n;j++){
			cout<<"\t"<<A[i][j]<<"   ";
		}
		cout<<endl;
	}
	cout<<"Nhap cac he so tu do (ma tra B)"<<endl;
	for(int i=1;i<=n;i++){
		cout<<"b["<<i<<"] = ";
		cin>>B[i];
		cout<<endl; 
	}		
	cout<<"Ma tran B da nhap : "<<endl;
	for(int i=1;i<=n;i++){
		cout<<"\t"<<B[i]<<endl;
	}
	for (int k=1;k<=n-1;k++){
		for (i=k+1;i<=n;i++){ 
			B[i]=B[i]-B[k]*A[i][k]/A[k][k]; 
			for (j=k+1;j<=n;j++){
				A[i][j]=A[i][j]-A[k][j]*A[i][k]/A[k][k];
			}
 		}
	} 
	if(A[n][n]==0){
		if(B[n]==0)
			cout<<"He pt vo nghiem !"<<endl;
		else 
			cout<<"He pt co vo so nghiem !"<<endl;	
	}
	else{
		X[n]=B[n]/A[n][n];
		for(int i=n-1;i>=1;i--){
			s=0;
			for(int k=i+1;k<=n;k++){
				s=s+A[i][k]*X[k];
				X[i]=(B[i]-s)/A[i][i];
			}
		}
	}
	cout<<"nghiem cua ht pt "<<endl;
	for(int i=1;i<=n;i++){
		cout<<"x"<<i<<"= "<<X[i];
		cout<<endl;
	}
	return 0;
}
