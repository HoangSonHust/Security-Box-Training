#include <stdio.h>
#include <stdlib.h>
 void tachso(int InputNumber){

    
    int Array[3];
	int temp;
    for(int n=0 ; n <3; n++){
       Array[n] = InputNumber%10;
        InputNumber = InputNumber/10;
        printf("Numbers in array: %d \n",  Array[n] );
        printf("The number is divided: %d \n" ,InputNumber);
    }
    printf("value in array  %d %d %d \n " ,Array[0], Array[1] , Array[2]);
  /*	for(int i=0; i<2; i++){
     for(int j=i+1; j<3; j++){
         if(mang[j]<mang[i]){
            temp = mang[j];
            mang [j] = mang[i];
            mang[i] = temp;
         }
   }
  }*/
  // dung de sap xep (thuat toan noi bot)
  	for(int i=0; i<2; i++){
    	for(int j=0; j<2; j++){
        	if(Array[j]>Array[j+1]){
            temp = Array[j];
            Array [j] = Array[j+1];
            Array[j+1] = temp;
          	}
       	}   
   	}
  	for (int k =2; k>=0; k--){
   		printf("%d ",Array[k]);
	   }
}

int bt1() {

   int InputNumber;
   printf("Input the mumber that has 3 number: ");
   scanf("%d",&InputNumber);
   if(99< InputNumber && InputNumber <1000){
        printf("You Input: %d \n" ,InputNumber);
        tachso(InputNumber);
   }
   else
     printf("Input the mumber that has 3 numbe only!!!!1 ");
   return 0;
   }



main(){
	printf("BTT1_1 \n");
        bt1();


}






