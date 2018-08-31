/*Vi?t 2 hàm tìm UCLN và BCNN c?a 2 s? nguyên duong*/

#include<stdio.h>
#include<math.h>
#include <string.h> 

UCLN(int Number1, int Number2)
{
	int temp;
	while((temp = (Number1%Number2))!=0){
		Number1 = Number2;
		Number2= temp;
		
	}
	
	printf("UCLN: %d \n", Number2);
}

BCLN(int Number1, int Number2){
	// cach lam la: dau tien check xem so lon hon co chia het cho so nhor hon ko, neu cos thi UCNN laf so lon
	//neu ko thif cong so lon hon voi chinh no roi thuc hien nhu buoc 1
	
	int Max, Min, loop=1;
	
	if(Number1>Number2)
    {
    	Max= Number1;
		Min= Number2;	
	}
	else 
		Max =Number2;
		Min= Number1;
while (Max%Min!=0){
	
	Max++;
	
	
	
}
printf("BCNN: %d",Max );
}

main(){
	printf("BTT1_7: Find UCLN AND BCNN \n");
	int Number1;
	int Number2;
	printf("Input NUMBER 1 \n ");
	scanf("%d", &Number1);
	printf("Input NUMBER 2 \n ");
	scanf("%d", &Number2);
	printf("2 Number: %d and %d \n", Number1, Number2);
	UCLN(Number1, Number2);
	BCLN(Number1, Number2);
}


