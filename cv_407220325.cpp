#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main (){//int argc, char *argv[]){
	FILE *fin, *fout;

	//the variable which will be input or output
	char argv[3][100];
    scanf("%s %s",argv[1],argv[2]);
     
	if ((fin = fopen(argv[1], "r+b")) == NULL){
        printf("Open file Erorr...\n");
        return(0);
    }	
     
    
	fout = fopen(argv[2],"w+b"); 	
	char ch;
	int offset; 	
	while((ch=getc(fin))!=EOF){

        if(ch>='0' && ch<='9') {
		fprintf(fout, "%c",ch);  }
		else if(ch>='a' && ch<='z'){
		offset = 'A'-'a';
		fprintf(fout, "%c",ch+offset);}
		else if(ch>='A' && ch<='Z'){
		offset = 'a'-'A';
		fprintf(fout, "%c",ch+offset);}
		else{
		fprintf(fout, "%c",ch);	
		}
    }
    

    fclose(fin);
    fclose(fout);


	printf("finish");
	return 0;
}
