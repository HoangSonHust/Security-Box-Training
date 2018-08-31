/*Vi?t chuong trình d?o xâu. Ð?u vào là 1 xâu kí t? b?t kì 
(nh?p t? bàn phím),
 in ra màn hình xâu dã d?o*/
 
#include<stdio.h>
#include<math.h>
#include <string.h> 



main(){
	printf("BTT1_8: BT DAO XAU \n");
	char String[1000];
	gets(String);
	
	int length= strlen(String);
	for(int n=length-1; n>=0; n--){
		
	printf("%c" ,String[n]);	
		
	}
	
	
	
}
