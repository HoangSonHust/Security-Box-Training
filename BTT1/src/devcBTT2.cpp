#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    main(){
    	printf("BTT1_2\n");
	int a=0, b=0;
	char String[255];
	printf("Input the String that you want to process: ");
	gets(String);
	


	int n=strlen(String);
	for(int i=0;i<n;i++){
	
		if('a' <=String[i]&& String[i]<='z'){
		
		  a++;
		}
		if('A'<=String[i]&& String[i]<='Z'){
			b++;
		}
		
		
	}
	printf("lowercase %d " , a);
	printf("uppercase %d ", b);
	
}
