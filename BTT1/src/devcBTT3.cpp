#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void tinhtoantien(int SoDuongDi){
	int TongTien;
	printf("ham tinh toan tien %d\n" , SoDuongDi);

	if(0<=SoDuongDi && SoDuongDi<=1000 ){
		printf("meo1");
		TongTien=10000;
	}
		if(1000<SoDuongDi && SoDuongDi<=30000){
			printf("meo2");
		TongTien= 10000+ (1500/200)*(SoDuongDi-1000);
	} 
	


	if(SoDuongDi> 30000){
			printf("meo4");
			TongTien=227500+ (8000/1000)*(SoDuongDi-30000);
		
	}
	
	printf("Tong Tien la: %d" , TongTien);
	
}
nhapsoduong(){
	printf("moi nhap so m da di \n");
    int SoDuongDi;
	scanf("%d", & SoDuongDi);
	printf("so duong ban nhap la %d \n", SoDuongDi);
	tinhtoantien(SoDuongDi);
	
}

 main(){
 	printf("BTT1_3\n");
	nhapsoduong();
}
