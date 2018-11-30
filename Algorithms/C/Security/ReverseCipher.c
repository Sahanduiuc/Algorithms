///////////////////////////////////////////////////////////////////////////////////////////////////////
//Name: ReverseCipher
//Modified: 8-2-2017
//Author: Nilesh Payghan
//Input: string
//output: reversed string
//Description:
////////////////////////////////////////////////////////////////////////////////////////////////////////


//Reverse cipher just reverse the message in place itself
//so it will easily to decrypt the message
#include<stdio.h>
#include<malloc.h>

void reverse(char* str){
	if(str==NULL){
		return;
	}
	char ch;
	char* end=str;
	while(*end!='\0'){
		end++;
	}

	end--;
	while(str<end){
		ch=*str;
		*str=*end;
		*end=ch;
		str++;
		end--;
	}
}

int main(){

	char *str;

	str=(char*)malloc(sizeof(char)*100);
	
	printf("Enter the string\n");
	scanf("%[^\n]s",str);
	
	reverse(str);
	
	printf("\nEncrypted message\n");
	printf("%s\n",str );
	
	printf("\nDecypted message:\n");
	reverse(str);
	printf("%s\n",str );
	printf("\n");

	return 0;
}
