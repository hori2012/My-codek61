//Dinh nghia ham
void Nhap(int a[],int n){
	printf("\nNhap cac he so cua da thuc bac %d: ",n);
    for(int i=n;i>=0;i--){
    	printf("\n\tHe so a[%d] :",i);
      	scanf("%d",&a[i]);
	  }
}
void Xuat(int a[],int n){
	printf ("\nDa thuc co dang: ");
	for(int i=n;i>=0;i--){
		if(i!=0)
	      printf("%dx^%d + ",a[i],i);
	     else printf("%d",a[0]); 
  }
}
int Tinh(int a[],int n,int b){
	int s=0;
	for(int i=n;i>=0;i--){
	    s=s+(a[i]*pow(b,i));
	}
	return s;
}
int Tong(int a,int b){
	int s=0;
	s=a+b;
	return s;
}
int Hieu(int a,int b){
	int s=0;
	s=a-b;
	return s;
}
float Thuong(float a,float b){
	int s=0;
	//if(b=0) printf("\nMath error!!!!");
	s=a/b;
	return s;
}
int Tich(int a,int b){
	int s=0;
	s=a*b;
	return s;
}
void Daoham(int a[],int n){
	for(int i=n;i>=1;i--){
		if(i!=1)
		printf("%dx^%d + ",a[i]*i,i-1);
		else printf("%d",a[i]);
   }
}
