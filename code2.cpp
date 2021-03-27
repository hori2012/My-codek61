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
	printf("\nHoten\t\t    Tinh\t\tNamSinh");
	for(int i=0;i<n;i++){
		printf("\n%-20s%-20s%-10d",employeeList[i].Name,employeeList[i].Province,employeeList[i].Year);
	}
}
void Output1(EL t){
	printf("\n%-20s%-20s%-10d",t.Name,t.Province,t.Year);
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
void Cout(EL employeeList[],int n){
	int dem=1;
	for(int i=0;i<n;i++){
		if(strcmp(employeeList[i].Province,employeeList[i+1].Province)==0){
			dem++;       
       }
        else{
        	printf("\n%s co %d nhan vien!",employeeList[i].Province,dem); 
        	dem==1;
		}
    }
}
void Search(EL employeeList[],int n){
	EL t;
	int dem=0;
	fflush(stdin);
	printf("\nNhap ten tinh can tim:");
	gets(t.Province);
	for(int i=0;i<n;i++){
		if(strcmp(employeeList[i].Province,employeeList[i+1].Province)==0) dem++;
	}
	if(dem!=0){
		printf("\nThong tin cua nhan vien thuoc tinh %s :",t.Province);
		printf("\nHoten\t\t    Tinh\t\tNamSinh");
		for(int i=0;i<n;i++){
			if(strcmp(employeeList[i].Province,employeeList[i+1].Province)==0) Output1(employeeList[i]);
		}
	}
	else printf("!!!Khong co nhan vien cua tinh %s",t.Province);	
}
void Menu(EL employeeList[],int &n){
	int t;
	int flat=1;
	while(flat!=0){
	printf("\t\t~~~~~~~MENU~~~~~~~~");
	printf("\n1.NHap du lieu cua tung nhan vien");
	printf("\n2,Sap xep, thong ke va hien thi thon tin chi tiet cua tung nhan vien theo tinh (Z->A)");
	printf("\n3.Tim nhan vien theo tinh");
	printf("\n4.Ghi vao tap tin nhi phan employee.dat");
	printf("\n5.Nhan 0 de thoat!!!");
	printf("\n            ");
	printf("\nYour choice:");
	scanf("%d",&t);
	switch(t){
	case 1:
		Input(employeeList,n);
		break;
	case 2:
	    Sort(employeeList,n);
		break;
	case 3:
	     Search(employeeList,n);
		 break;
//	case 5:
	     	
	default: 
	        printf("\nThank for watching!!!!");	
	        flat=0;   	 		
	}
  }
}
int main(){
	int n;
	EL employeeList[50];
	Menu(employeeList,n);
	/*Input(employeeList,n);
	Sort(employeeList,n);
	//printf("\nThong tin cua nhan vien la:");
	Output(employeeList,n);
	Cout(employeeList,n);
	Search(employeeList,n);*/
	
}
