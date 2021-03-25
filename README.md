# My-codek61
~~~~~~~hori~~~~~~~~
//Bai Tap Lon
#include<stdio.h>
#include<conio.h>
#include<string.h>
struct employee_st{
	char Name[30];
	char Province[30];
	int Year;
};
typedef struct employee_st EL;
void Nhap1(EL &nv){
	fflush(stdin);
	printf("\nNhap ten nhan vien:");
	gets(nv.Name);
	printf("\nNhap tinh o cua nhan vien:");
	gets(nv.Province);
	printf("\nNhap nam sinh nhan vien:");
	scanf("%d",&nv.Year);
}
void Input(EL employeeList[] , int &n ){
	printf("\nNhap so luong nhan vien :");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("\nNhap thong tin nhan vien %d",i+1);
		Nhap1(employeeList[i]);
	}
}
void Output(EL employeeList[],int n){
	printf("\nThong tin cua nhan vien la:");
	printf("\nHoten\t\tTinh\t\tNamSinh");
	for(int i=0;i<n;i++){
		printf("\n%s\t\t%s\t\t%d",employeeList[i].Name,employeeList[i].Province,employeeList[i].Year);
	}
}
void Sort(EL employeeList[],int n){
	EL temp;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++)
		if(strcmp(employeeList[i].Province,employeeList[j].Province)<0){
			temp=employeeList[i];
			employeeList[i]=employeeList[j];
			employeeList[j]=temp;
		}
	}
}
int main(){
	int n;
	EL employeeList[50];
	Input(employeeList,n);
	Sort(employeeList,n);
	Output(employeeList,n);
	
}
