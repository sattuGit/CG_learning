#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int main(){
	cout<<"JaiShriRam\n";
	FILE *infile,*outfile;
	infile = fopen("C_lang.jpeg","rb");
	if(infile==NULL){
		cout<<"ERROR wile opeing the file \n";
		return 0;
	}
	outfile = fopen("C_lang_encrypt.jpeg","wb");
		if(outfile==NULL){
			cout<<"ERROR wile opeing the file \n";
			return 0;
	}

		fseek(infile,0L,SEEK_END);
		unsigned long   sz = ftell(infile);
		cout<<sz<<endl;
		fseek(infile,0,SEEK_SET);

		unsigned char evenBuff[8], oddBuff[8];
		size_t tmp;
		unsigned long counter=0;
		while(fread(evenBuff, sizeof(evenBuff),1,infile)){
			++counter;
			if(fread(oddBuff, sizeof(oddBuff),1,infile)){
				cout<<" | Counter "<<counter;
				fwrite(oddBuff, 1, sizeof(oddBuff), outfile);
				fwrite(evenBuff, 1, sizeof(evenBuff), outfile);
			}else{
				cout<<" | Counter "<<counter;
				fwrite(evenBuff, 1, sizeof(evenBuff), outfile);
			}
		}
		fclose(infile);
		fclose(outfile);

	return 0;
}
