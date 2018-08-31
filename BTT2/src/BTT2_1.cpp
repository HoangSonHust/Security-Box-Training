#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
void Check3(char *StringCharater);


void InputFile() {
	//cap phat dong
	char *ArrayWordByWord = (char *)calloc(1000, sizeof(char));
	// loai bo ki tu dac biet
	memset(ArrayWordByWord, 0, strlen(ArrayWordByWord));
	FILE *fp;
	int StringInput;
	int n = 0;
//	fp = fopen("C:/Users/hoang/source/repos/BTT2_2/input.txt", "r");
	fp = fopen("C:/Users/hoang/OneDrive/M�y t�nh/Security Box Training/BTT2/BTT2_1/BTT2_1.txt", "r");
	if (fp == NULL)
	{
		perror("No valid file!!");	
		
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
	}while (1);
	Check3(ArrayWordByWord);
	fclose(fp);
/*	std::ifstream fileInput("C:/Users/hoang/OneDrive/M�y t�nh/Security Box Training/BTT2/BTT2_1/BTT2_1.txt");
	if (fileInput.fail())
		std::cout << "Failed to open this file!" << std::endl;
	if (!fileInput.fail())
		std::cout << "Pass to open this file!" << std::endl;
	while (!fileInput.eof())
	{

		char *n;
		fileInput >> n;
		std::cout << n ;
		Check3(n);
	}
	std::cout << std::endl;

	fileInput.close();
*/
}



void Check3(char *StringCharater) {
	int OpenA = 0;
	int CloseA = 0;
	int OpenB = 0;
	int CloseB = 0;
	int OpenC = 0;
	int CloseC = 0;
	int ResultOpenA=0;
	int ResultOpenB=0;
	int ResultOpenC=0;
	int ResultCloseA=0;
	int ResultCloseB=0;
	int ResultCloseC=0;
	
	int LengthOfStringCharater = strlen(StringCharater);
	int i;
	// đếm số lượng kí tự trong chuỗi
	for (i = 0; i <= LengthOfStringCharater - 1; i++) {
		if (StringCharater[i] == '(') {
			OpenA++;
		}
		if (StringCharater[i] == '{') {
			OpenB++;
		}
		if (StringCharater[i] == '[') {
			OpenC++;
		}
		if (StringCharater[i] == ')') {
			CloseA++;
		}
		if (StringCharater[i] == '}') {
			CloseB++;
		}
		if (StringCharater[i] == ']') {
			CloseC++;
		}

		// của ()



		// trong trường hợp bình thường thì Open luôn lớn hoặc bằng close(
		//nếu open > close thì 
		if (OpenA > CloseA) {
			OpenA = OpenA - CloseA;
			CloseA = 0;
			//ResultCloseA = 0;
		}
		//nếu Open = Close thì cho hai đứa bằng nhau
		if (OpenA == CloseA) {
			OpenA = 0;
			CloseA = 0;
			
		}
		//ngược lại là nếu bắt đầu có sự sai thì ta sẽ đến else (nghĩa là Close >Open hay lượng dấu ")" > lượng dấu "(" )
		if (OpenA < CloseA) {
			// nếu đến vị trí sai thì cho giá trị "i" đang là vị trí trong mảng và ta sẽ xác định được là vị trí nào bắt đầu thừa ")" và đó sẽ là vị trí ")" thừa ra
			
				ResultOpenA ++;
				CloseA= 0;			
			
			printf("ket qua nhung vi tri thua ) la: %d \n", i);
		}


		//của {}

		if (OpenB > CloseB) {
			OpenB = OpenB - CloseB;
			CloseB = 0;
			//ResultCloseA = 0;
		}
		//nếu Open = Close thì cho hai đứa bằng nhau
		if (OpenB == CloseB) {
			OpenB = 0;
			CloseB = 0;
			
		}
		//ngược lại là nếu bắt đầu có sự sai thì ta sẽ đến else (nghĩa là Close >Open hay lượng dấu ")" > lượng dấu "(" )
		if (OpenB < CloseB) {
			// nếu đến vị trí sai thì cho giá trị "i" đang là vị trí trong mảng và ta sẽ xác định được là vị trí nào bắt đầu thừa ")" và đó sẽ là vị trí ")" thừa ra
			
				ResultOpenB++;
				CloseB = 0;
			
			printf("ket qua nhung vi tri thua } la: %d \n", i);
		}


		// của []


		if (OpenC > CloseC) {
			OpenC = OpenC - CloseC;
			CloseC = 0;
			//ResultCloseA = 0;
		}
		//nếu Open = Close thì cho hai đứa bằng nhau
		if (OpenC == CloseC) {
			OpenC = 0;
			CloseC = 0;
			
		}
		//ngược lại là nếu bắt đầu có sự sai thì ta sẽ đến else (nghĩa là Close >Open hay lượng dấu ")" > lượng dấu "(" )
		if (OpenC < CloseC) {
			// nếu đến vị trí sai thì cho giá trị "i" đang là vị trí trong mảng và ta sẽ xác định được là vị trí nào bắt đầu thừa ")" và đó sẽ là vị trí ")" thừa ra
			
				ResultOpenC++;
				CloseC = 0;
			
			printf("ket qua nhung vi tri thua ] la: %d \n", i);
		}
		


	}

	
/*	printf("dau:( %d \n", OpenA);
	printf("dau:) %d \n", CloseA);
	printf("dau:{ %d \n", OpenB);
	printf("dau:} %d \n", CloseB);
	printf("dau:[ %d \n", OpenC);
	printf("dau:] %d \n", CloseC);
	*/
	//them về phái bên phải
	int a = LengthOfStringCharater;
	for (a; a < LengthOfStringCharater + OpenA; a++) {
		printf(") %d \n", a);
		
	}
	LengthOfStringCharater = LengthOfStringCharater + a;
	int b = LengthOfStringCharater;
	for (; b < LengthOfStringCharater + OpenB; b++) {
		printf("}%d \n", b);
	}
	LengthOfStringCharater = LengthOfStringCharater + b;
	int c = LengthOfStringCharater + b;
	for ( ; c < LengthOfStringCharater + OpenC ; c++) {
		printf("] %d \n", c);
	}
	LengthOfStringCharater = LengthOfStringCharater + c;
	// thêm về phía bên trái
	int themtrai = -1;
	int aa = themtrai;
	printf("%d\n", ResultOpenA);
	printf("%d\n", ResultOpenB);
	printf("%d\n", ResultOpenC);

	for ( ; aa > -1 - ResultOpenA; aa--) {
		printf("( %d \n", aa);
	}
	themtrai = -1 - ResultOpenA;
	int bb = themtrai;
	for (; bb > themtrai - ResultOpenB; bb--) {
		printf("{ %d \n", bb);
	}
	themtrai = themtrai - ResultOpenB;
	int cc = themtrai;
	for (; cc >themtrai-ResultOpenC; cc--) {
		printf("[ %d \n", cc);
	}

	

}



void CheckCharater3() {
	char StringCharater[300];
	printf("moi nhap chuoi ban muon nhap: \n");
	cin >> StringCharater;
	printf("chuoi ban moi nhap:%s \n", StringCharater);
	printf("---------------------------------------------------------\n");
	Check3(StringCharater);
}



int main() {

	printf("ban muon dung cach nay? \n");
//	int CachSo;
//	cin >> CachSo;
	// cach nay dung Array
//	printf("cach so: %d \n", CachSo);
	//CheckCharater3();
	InputFile();

	int a[200];
	int b = 0;
	b = sizeof(a);
	//printf("%d", b);
	system("pause");
	getchar();
	return 0;
}
