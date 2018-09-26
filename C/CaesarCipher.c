/*
requirements : string and integer key from 0-25
caesar cipher only encrypts the alphabets other numberic and symbols leave as it is

*/
#include<stdio.h>
#include<malloc.h>
typedef unsigned char UC;

void caesar(UC* str,int key){
if(str==NULL|| key>26 || key<0)
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

void decrypt(UC* str){
	if(str==NULL)
		return;
	UC *temp=str;
	UC ch;
for(int i=0;i<26;i++){
		str=temp;
		printf("Using %d:  ",i );
	while(*str!='\0'){
		if((*str>='a'&&*str<='z')){
				ch=*str;
			ch=ch-i;
			if(ch<'a'){
				ch=ch+26;
			}//inner if
		
		}//if
		else if((*str>='A'&&*str<='Z')){
					ch=*str;
				ch=ch-i;
				if(ch<'A'){
					ch=ch+26;
				}//inner if
		}
		
		//if character is not alphabet then keep as it is
		else{
			ch=*str;
		}

		printf("%c",ch );

		str++;
	}//while
	printf("\n");
	

}//for

}//decrypt


int main(){
	char* str;

	str=(char*)malloc(sizeof(char)*100);

	printf("Enter the string\n");
	scanf("%[^\n]s",str);
	int key=0;
	printf("Enter the key:\n");
	scanf("%d",&key);

	caesar(str,key);
printf("\nencrypted:\n");
	printf("%s\n",str );

printf("\nDecrypted:\n");

	decrypt(str);
	

printf("\n");
	return 0;
}
