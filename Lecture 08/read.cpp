#include <stdio.h>
#include <string.h>

int main(){
	char c[20];
	int MAX=20;
	FILE *fp, *ofp;
	fp=fopen("test.txt","r");
	ofp=fopen("output.txt","w");
	fread(c,sizeof(char),20,fp);
	printf("%s",c);
	fwrite(c,sizeof(char),20,ofp);
	fprintf(ofp,"\n");
	fwrite(c,sizeof(char),strlen(c)-1,ofp); 
	fclose(fp);
	fclose(ofp);
	return 0;
} 
