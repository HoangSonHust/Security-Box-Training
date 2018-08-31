#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
int CountContext = 0;
int InputData(); 
void ReplaceWord(char *ArrayWordByWord);
void Replace(char *ArrayWordByWord);
FILE *fw;
char fileNameW[30];	
int main() {
	strcpy(fileNameW, "C:/Users/hoang/OneDrive/Máy tính/output.txt");
	fw=fopen(fileNameW,"w");
	InputData();
	system("pause");
	getchar();
	return 0;
}
void FindWordInLine(char *ArrayWordByWord){
	CountContext++;
	char *meo= ArrayWordByWord;
	printf(">Enter the key Word: ");
	char InputWord[20];
	memset(InputWord,0,sizeof(InputWord));
	char Buff[20]; //la mang de luu cac chu duoc lay ra tu ArrayWordByWord 
    memset(Buff,0,sizeof(Buff));
	int CountWord=0, // so luong cac tu  
	    Column=1, // vi tri cot trong dong
	    Row=1, // dong thu 
	    Count=0, //so lan xuat hien tu khoa
		Count1=0, // vi tri cua ki tu trong mang ArrayWordByWord
		Count2=0, // vi tri cua ki tu trong mang Buff
		Count3=0, //so phan tu tron mang Row
		Count4=0; // so phan tu trong mang Col
	int	RowArray[1000]; // mang dung de luu hang co ki tu dang tim
	int	Col[1000]; // mang de luu vi tri cot torng dong 
	 memset(RowArray,0,sizeof(RowArray));
	  memset(Col,0,sizeof(Col));
	//ta se cho chay tu dau cho de gan cac ki vao Buff.
	gets(InputWord);
	while( Count1<strlen(ArrayWordByWord)){
		// trong truong hop ko gap dau cach hoac ki tu dac biet thi tiep tuc gan
		while((ArrayWordByWord[Count1]!=' ')&& (ArrayWordByWord[Count1]!=',')&& (ArrayWordByWord[Count1]!='.')&& (ArrayWordByWord[Count1]!='!') && (ArrayWordByWord[Count1]!='?')){
			Buff[Count2]= ArrayWordByWord[Count1];
			Count1++;
		    Count2++;
			Column++;	
		}	
		if(strcmp(Buff, InputWord)==0){
			RowArray[Count3]= Row;
			Col[Count4]=Column- strlen(Buff); // gan gia tri ki tu dau trong chu
			Count3++;
			Count4++;
		   // cout<< Count1;
			Count1++;
			Count++;
			printf(">        ln: %d and col: %d \n",Row, Column- strlen(Buff) );
			Column++;
		}
		if((ArrayWordByWord[Count1]==' ')|| (ArrayWordByWord[Count1]==',')|| (ArrayWordByWord[Count1]=='.')||(ArrayWordByWord[Count1]=='!')|| (ArrayWordByWord[Count1]=='?')){
			Column++;
			Count1++;
			Count2=0;
			/*
			co memset de xoa het nhung cai ki tu da ton tai trong mang
			*/
			memset(Buff,0,sizeof(Buff)); 
			}
			//neu xuong dong 
		if(ArrayWordByWord[Count1]=='\n'){
			Count1++;//vd tai vi tri count1=n la \n thi vi tri ki tu dau dong tiep se la count1++
			Row++;// dong se tang len
			Column=1;// cho vi tri ki tu trong dong tror ve 1
			Count2=0;//cho mang Buff ve nhu ban dau de gan tiep
	     	memset(Buff,0,sizeof(Buff)); 
		}
	
	}
		fprintf(fw,"Context %d: search keyword\n", CountContext);
		fprintf(fw,"Keyword: %s\n", InputWord);
		fprintf(fw,"Total position(s): %d\n", Count);
		for(int c=0; c<Count; c++){
				fprintf(fw,"          Ln %d, Col %d\n", RowArray[c],Col[c] );
		}
		printf(">Total appeared time: %d \n",Count);
		int Choose;
		printf(">Please choose the features:\n");
	
		printf("----------------------------------\n");
		printf("          1. Search\n"); 
		printf("          2. Replace\n");
		printf("          3. Exit\n");
		printf("----------------------------------\n");
		printf(">");
		cin>>Choose;
		fflush(stdin);
		if(Choose==1){
			FindWordInLine(meo);
		}
		if(Choose==2){
			Replace(meo);	
		}
		if(Choose==3){
			fclose(fw);
		}
	
}
void ReplaceWord(char *ArrayWordByWord){
	CountContext++;
	printf("Context: %d\n",CountContext);
	char *meo= ArrayWordByWord;
	printf(">Enter the Word: \n");
	char InputWord[20];
	memset(InputWord,0,sizeof(InputWord));
	gets(InputWord);
	char Buff[20]; //la mang de luu cac chu duoc lay ra tu ArrayWordByWord 
    memset(Buff,0,sizeof(Buff));
    printf(">Enter the new Word: \n");
    char InputNewWord[20];
	memset(InputNewWord,0,sizeof(InputNewWord));
	gets(InputNewWord);
	int CountWord=0, // so luong cac tu  
	    Column=1, // vi tri cot trong dong
	    Row=1, // dong thu 
	    Count=0,
		Count1=0, // vi tri cua ki tu trong mang ArrayWordByWord
		Count2=0, // vi tri cua ki tu trong mang  Buff
		Count3=0, //so phan tu tron mang Row
		Count4=0; // so phan tu trong mang Col
	int	RowArray[1000]; // mang dung de luu hang co ki tu dang tim
	int	Col[1000]; // mang de luu vi tri cot torng dong 
	//ta se cho chay tu dau cho de gan cac ki vao Buff.
	std::string str=ArrayWordByWord;
	while( Count1<str.length()){
		// trong truong hop ko gap dau cach hoac ki tu dac biet thi tiep tuc gan
		while((str[Count1]!=' ')&& (str[Count1]!=',')&& (str[Count1]!='.')&& (str[Count1]!='!') && (str[Count1]!='?')){
			Buff[Count2]= str[Count1];
			Count1++;
		    Count2++;
			Column++;	
		}	
		if(strcmp(Buff, InputWord)==0){
			str.replace(Count1-strlen(InputWord),strlen(InputWord),InputNewWord);
	//	printf("%d \n", Count1);
		
			RowArray[Count3]= Row;
			Col[Count4]=Column- strlen(Buff); // gan gia tri ki tu dau trong chu
			Count3++;
			Count4++;
			printf(">        ln: %d and col: %d \n",Row, Column- strlen(Buff) );
				Column++;
				Count1++;
				Count++;
		}
		if((str[Count1]==' ')|| (str[Count1]==',')|| (str[Count1]=='.')||(str[Count1]=='!')|| (str[Count1]=='?')){
			Column++;
			Count1++;
			Count2=0;
			/*
			co memset de xoa het nhung cai ki tu da ton tai trong mang
			*/
			memset(Buff,0,sizeof(Buff)); 
			
			}
			//neu xuong dong 
		if(str[Count1]=='\n'){
			Count1++;//vd tai vi tri count1=n la \n thi vi tri ki tu dau dong tiep se la count1++
			Row++;// dong se tang len
			Column=1;// cho vi tri ki tu trong dong tror ve 1
			Count2=0;//cho mang Buff ve nhu ban dau de gan tiep
	     	memset(Buff,0,sizeof(Buff)); 
		}
	
	}
		fprintf(fw,"Context %d: replace by new keyword \n", CountContext);
		fprintf(fw,"Keyword: %s \n", InputWord);
		fprintf(fw,"New keyword: %s \n", InputNewWord);
		fprintf(fw,"Total position(s): %d\n", Count);
		for(int c=0; c<Count; c++){
				fprintf(fw,"          Ln %d, Col %d\n", RowArray[c],Col[c] );
		}	
		printf(">Total appeared time: %d \n",Count);
		int Choose;
		printf(">Please choose the features:\n");
	
		printf("----------------------------------\n");
		printf("          1. Search\n"); 
		printf("          2. Replace\n");
		printf("          3. Exit\n");
		printf("----------------------------------\n");
		printf(">");
		cin>>Choose;
		fflush(stdin);
		if(Choose==1){
			FindWordInLine(meo);
		}
		if(Choose==2){
			Replace(meo);	
		}
		if(Choose==3){
			fclose(fw);
		}
}
void Replace(char *ArrayWordByWord){

	ReplaceWord(ArrayWordByWord);	
}	
/*
dung de dem so dong trong van ban
*/
int CountLine(char *ArrayWordByWord){

	int CountNumLine=0;
	int a=0;
	for(a; a< strlen(ArrayWordByWord); a++ ){
		if(ArrayWordByWord[a]=='\n'){
			CountNumLine++;
		}
	}
//	printf("so dong la: %d \n", CountNumLine);
	return CountNumLine;
}
int InputData() {
	char URL[100];
	printf("> Enter file: ");
	
	scanf("%s", URL);
	fprintf(fw,"          Input file: %s \n", URL);
	//cap phat dong
	char *ArrayWordByWord = (char *)calloc(1000, sizeof(char));
	// loai bo ki tu dac biet
	memset(ArrayWordByWord, 0, strlen(ArrayWordByWord));
	FILE *fp;
	int StringInput;
	int n = 0;
//	fp = fopen("C:/Users/hoang/source/repos/BTT2_2/input.txt", "r");
	fp = fopen(URL, "r");
	if (fp == NULL)
	{
		perror("No valid file!!");	
		return -1;
	}
	do
	{
		StringInput = fgetc(fp);
		if (StringInput == EOF)
		{
			break;
		}
		ArrayWordByWord[n] = (char)StringInput;
		
		if(ArrayWordByWord[n]>='A' &&ArrayWordByWord[n]<='Z'){
			ArrayWordByWord[n]=ArrayWordByWord[n]+32;
		
		}
			n++;
		
	} while (1);
	printf("%s",ArrayWordByWord);
		printf(">valid file, please choose the features:\n");
		printf("----------------------------------\n");
		printf("          1. Search\n"); 
		printf("          2. Replace\n");
		printf("          3. Exit\n");
		printf("----------------------------------\n");
		int Choose=0;
		printf(">");
		cin>>Choose;
		fflush(stdin);
		if(Choose==1){
			FindWordInLine(ArrayWordByWord);
		}
		if(Choose==2){
			Replace(ArrayWordByWord);	
		}
		if(Choose==3){
			fclose(fw);
		}
      ArrayWordByWord;

	fclose(fp);
	//fclose(fw);
}



