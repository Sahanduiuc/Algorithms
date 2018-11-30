
///////////////////////////////////////////////////////////////////////////////////////////////////////
//Name:
//Modified: 9-2-2017
//Author: Nilesh Payghan
//Input:
//output:
//Description:
////////////////////////////////////////////////////////////////////////////////////////////////////////


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
	//printf("In changeString\n");
	//char *dest;
	//dest=(char*)malloc(sizeof(char)*21);


//int count=0;

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
	/*
	*dest='\0';
	dest=dest-count;
	//printf("%d\n",count );
	while(*dest!='\0'){
		printf("%c",(*dest) );
		dest++;
		str++;
	}
	*/
	
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


printf("\nencrypted message\n");
	//just print the 2d created array with proper indentation
	for(int i=0;i<row;i++){
		for(int j=0;j<key;j++){
			printf("%c\t",arr[i][j] );
		}
		printf("\n");
	}

	//put the string address at begin
	str=temp;
	//printf("row: %d\n",row);
	//printf("key:%d\n",key );
	changeString(arr,str,row,key);

}
////////////////////////////////////////////////////////////////////////////////////////////
void decrypttrans(char* str,int key){
	if(str==NULL){
		return;
	}
	char*temp=str;
	int length=strlen(str);
	//printf("length: %d\n",length );

	int col=length/key;
	if((col*key)!=length){
		col=col+1;
	}
	int row=key;
	//allocate the memory for the array
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
				*str=arr[j][i];
				str++;
			}
		}
	}


	//display the Encrypted data which is filled into the array
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%c\t",arr[i][j] );
		}
		printf("\n");
	}


}//decryttrans

int main(){

	char* str;
	str=(char*)malloc(sizeof(char)*100);
	int key=0;
	
	printf("Enter String\n");
	scanf("%[^\n]s",str);

	char* temp=str;
	
	printf("Enter the key\n");
	scanf("%d",&key);

	transposition(str,key);

printf("\nEncrypted Final output in main:\n");
	while(*temp!='\0'){
		printf("%c",(*temp) );
		temp++;
	}
	temp=str;
	printf("\nDecrypted Message\n");
	decrypttrans(str,key);
	while(*temp!='\0'){
		printf("%c",(*temp) );
		temp	++;
	}
	printf("\n");
	return 0;
}