///////////////////////////////////////////////////////////////////////////////////////////////////////
//Name:
//Modified: 7-2-2017
//Author: Nilesh Payghan
//Input:
//output:
//Description:
////////////////////////////////////////////////////////////////////////////////////////////////////////


/*

rquirements : string and integer key from 0-25
caesar cipher only encrypts the alphabets other numberic and symbols leave as it is

*/
#include<stdio.h>
#include<malloc.h>
typedef unsigned char UC;

void caesar(UC* str,int key){
if(str==NULL|| key>26 || key<=0)
	return;
	UC* temp=str;
	while(*str!='\0'){
		
		if((*str>='a'&&*str<='z')){
		*str=*str+(UC)key;

		//printf("%d\n",(int)*str );
		//make the character as unsigned char because after the 127 it prints the negative value
		if(*str>'z'){
			*str=(*str)-26;
		}
	}
	else if((*str>='A'&&*str<='Z')){
		*str=*str+(UC)key;

		if(*str>'Z'){
			*str=(*str)-26;
		}
	}
		str++;
	}

}
////////////////////////////////////////////////////////////////////////

void decrypt(char* str,int key){
	if(str==NULL||key<=0||key>26)
		return;

	while(*str!='\0'){
		if((*str>='a'&&*str<='z')){
		*str=*str-key;
		if(*str<'a'){
			*str=*str+26;
		}
	}
	else if((*str>='A'&&*str<='Z')){
		*str=*str-key;
		if(*str<'A'){
			*str=*str+26;
		}

	}
		str++;
	}
}




int main(){
	char* str;
	int key=0;
	str=(char*)malloc(sizeof(char)*100);

	printf("Enter the string\n");
	scanf("%[^\n]s",str);
	
	printf("Enter the key:\n");
	scanf("%d",&key);

	char* temp=str;
	caesar(str,key);
	
	printf("\nencrypted:\n");
	while(*str!='\0'){
		printf("%c", (*str));
		str++;
	}

	printf("\nDecrypted:\n");
	decrypt(temp,key);
	while(*temp!='\0'){
		printf("%c",(*temp));
		temp++;
	}

	printf("\n");
	return 0;
}