
///////////////////////////////////////////////////////////////////////////////////////////////////////
//Name:
//Modified: 10-2-2017
//Author: Nilesh Payghan
//Input:
//output:
//Description:
////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
Description:
This program is used to hack the encrypted message which is created by the transposition matrix
which decrypts the code and check out the correct output by viewing the all outputs 
check the correct english and words and that is key which is actually used while encrypting the acutal program

*/
//#include<iostream>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
//////////////////////////////////////////////////////////////////////////////////////

void changeString(char** arr,char* str,int row,int key){
	if(arr==NULL || str==NULL){
		return;
	}
	char ch;
	
	//changing the contents of the original string
	for(int i=0;i<key;i++){
		for(int j=0;j<row;j++){
			if(arr[j][i]!='\0' && *str!='\0'){
				ch=arr[j][i];
				*str=ch;
				str++;
				//count++;
				
			}
		}
	}	
}

//////////////////////////////////////////////////////////////////////////////////////////////////
void transposition(char* str,int key){
	if( str==NULL || key<=0){
		return;
	}
	char* temp=str;
	int length=strlen(str);
	if(length<=0)
		return;
	//arrange the correct rows
	int row=length/key;
	if(row*key!=length){
		row+=1;
	}

	char **arr;
	//allocate memory for arr
	arr=(char**)malloc(sizeof(char*)*row);
	for(int i=0;i<row;i++){
		arr[i]=(char*)malloc(sizeof(char)*key);
	}


	//create the string in boxes of key
	while(*str!='\0'){
		for(int i=0;i<row;i++){
			for(int j=0;j<key;j++){
				//copy the data till end of the string
				arr[i][j]=*str;
				if(*str!='\0'){
					str++;
				}
				else{
					arr[i][j]='\0';
				}
			}//inner
		}//outer
	}//while

/*
printf("\nencrypted message\n");
	//just print the 2d created array with proper indentation
	for(int i=0;i<row;i++){
		
			printf("%s",arr[i] );
		
		printf("\n");
	}
*/
	//put the string address at begin
	str=temp;
	changeString(arr,str,row,key);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void decrypttrans(const char* str,int key){
	if(str==NULL){
		return;
	}
	const char*temp=str;
	char* dest;
	
	int length=strlen(str);
	//create the dest with new string message
	//printf("length: %d\n",length );
	dest=(char*)malloc(sizeof(char)*length+1);
	char*temp2=dest;
	//printf("dest initialization\n");

///////////
	//try the every possible key to generate the output

	int col=length/key;
	if((col*key)!=length){
		col=col+1;
	}
	int row=key;
	//allocate the memory for the array to store the encrypted data
	char** arr;
	arr=(char**)malloc(sizeof(char*)*row);
	for(int i=0;i<row;i++){
		arr[i]=(char*)malloc(sizeof(char)*col);
	}

//fill the remaning boxex in the array
	int totalbox=col*key;
	int remainbox=totalbox-length;

	for(int i=row-1;i>=0 && remainbox>0;i--,remainbox--){
		arr[i][col-1]='~';
	}


	//fill the encrypted data into the array
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(*str!='\0'&&arr[i][j]!='~'){
				arr[i][j]=*str;
				str++;
			}
			else{
				arr[i][j]='\0';
			}
		}//inner
	}//outer


	//copy the data from the array to the original string and decrypt it
	str=temp;

	for(int i=0;i<col;i++){
		for(int j=0;j<row;j++){

			if(arr[j][i]!='\0'){
				*dest=arr[j][i];
				dest++;
			}
		}
	}
	dest=temp2;

		printf("Using key %d: ", key );
	//display the decrypted message
	while(*dest!='\0'){
		printf("%c", *dest);
		dest++;
	}
dest=dest-length+1;


/*

	//display the Encrypted data which is filled into the array
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%c\t",arr[i][j] );
		}
		printf("\n");
	}
*/

}//decryttrans
////////////////////////////////////////////////////////////////////////////////////////////
int main(){

	char* str;
	str=(char*)malloc(sizeof(char)*100);
	int key=18;
	
	printf("Enter String\n");
	scanf("%[^\n]s",str);

	char* temp=str;
	
	//ecrypt the original message
	transposition(str,key);

printf("\nEncrypted Final output in main:\n");
	while(*temp!='\0'){
		printf("%c",(*temp) );
		temp++;
	}
	temp=str;
	printf("\n------------------------------Decrypted Message------------------------\n");
	int length=strlen(str);
	//printf("%d\n",length );
for(int i=2;i<length;i++){
	printf("\n");
	decrypttrans(str,i);
}

	/*
	while(*temp!='\0'){
		printf("%c",(*temp) );
		temp++;
	}/*/
	printf("\n");

	return 0;
}//main
