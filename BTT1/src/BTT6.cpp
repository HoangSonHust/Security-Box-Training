#include<stdio.h>
#include<math.h>
#include <string.h> 


DeleteCharacter(int Point, char String[] ){
        
		for(;Point<strlen(String); Point++){
			String[Point]= String[Point+1];
			String[strlen(String)]='\0';
		 
		}
	}
		
AddWhileSpace(int Point, char String[]){
		for(;Point<strlen(String); Point++){
			String[Point+1]= String[Point];
			String[strlen(String)+1]='\0';
		 
		}
		}
		
	


Input(){
	
	char String[255];
	printf("Input String \n")	;

	gets(String);	
  //  int	LengthString = strlen(String);
 
    // xoa khoang trang dau chuoi
    int HeadWhiteSpacePoint=0;
    	while(String[HeadWhiteSpacePoint]==32){  
    		DeleteCharacter(HeadWhiteSpacePoint, String);
    }
    //xoa khoang trang trung nhau
	int Point=0;
	
	for(Point; Point<strlen(String); Point++){
		if(String[Point]==32 && String[Point+1]==32){// neu vi tri a và vi tri a+1 co khoang trang thì  xoa vi tri a
				DeleteCharacter(Point, String);
				Point--; // vi khi xoa xong ki tu a+1 se nhay ve vi tri a va Point++ thi xet luon tai vi tri a+1 
		}
		
    	if(String[Point]==32 && String[Point+1]==','){// vi tri Point có dau phay thi xoa khoang trang o vi tri Point
    
    			DeleteCharacter(Point, String);
			}
		if(String[Point]==32 && String[Point+1]=='.'){// vi tri Point có dau cham thi xoa khoang trang o vi tri Point
    
    			DeleteCharacter(Point, String);
    		}
    		//them dau cach dang sau dau cham
    	if(String[Point]=='.' && String[Point+1]!=' '){
    		AddWhileSpace(Point+1, String);
		}//them dau cach dang sau dau ,
			if(String[Point]==',' && String[Point+1]!=' '){
    		AddWhileSpace(Point+1, String);
		}
			// chuyen chu thuong o dau dòng thanh chu hoa
		if(Point==0 && String[Point]>='a' && String[Point]<='z'){
			String[Point]= String[Point]-32;
		}// chuyen chu thuong thanh chu hoa
    	if(Point!=0 && String[Point]>='A' && String[Point]<='Z'){
			String[Point]= String[Point]+32;
		}
    }
    
    int TailWhiteSpacePoint= strlen(String);
    while(String[TailWhiteSpacePoint]==32){  
    		DeleteCharacter(TailWhiteSpacePoint, String);

	}
    // xoa dau cach truoc dau phay
   
  /*   for(Point; Point <strlen(String); Point++){
    	printf("ssfmeo");
    	if(String[Point]==32 && String[Point+1]==','){// vi tri Point có dau phay thi xoa khoang trang o vi tri Point
    //	printf("meo");
    			DeleteCharacter(Point, String);
    	
			}
    }*/
    
	for(int a=0; a<strlen(String); a++){
		printf("%c", String[a]);
	}
}

main(){
	printf("BTT1_6: CHUAN HOA CHUOI -.-\n");


	Input();
}
