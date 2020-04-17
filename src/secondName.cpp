#include <iostream>
#include <fstream>
#include <string.h>
#include "fileBuff.h"

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

		unsigned char evenBuff[1], oddBuff[1];

		unsigned long counter=0;
		int nread;
		while(0 < (nread= fread(evenBuff, 1,sizeof(evenBuff),/*1,*/infile))){
			++counter;
			if(fread(oddBuff, 1,sizeof(oddBuff),/*1,*/infile)){
				cout<<"| Counter Even "<<counter << " "<<ftell(infile)<<" "<<nread;
				fwrite(oddBuff, 1, sizeof(oddBuff), outfile);
				fwrite(evenBuff, 1, sizeof(evenBuff), outfile);
			}else{
				cout<<"  | Counter Odd"<<counter << " "<<ftell(infile)<<" "<<nread;
				fwrite(evenBuff, 1, sizeof(evenBuff), outfile);
			}
			fflush(infile);
			fflush(outfile);
		}
		cout<<"NREAD"<<" "<<nread<<endl;
		fclose(infile);
		fclose(outfile);
		cout<<"----------------------------------------------------------------------------------------\n";

		infile = fopen("C_lang_encrypt.jpeg","rb");
		if(infile==NULL){
			cout<<"ERROR wile opeing the file \n";
			return 0;
		}
		outfile = fopen("C_langReturnBack.jpeg","wb");
			if(outfile==NULL){
				cout<<"ERROR wile opeing the file \n";
				return 0;
		}

			fseek(infile,0L,SEEK_END);
			sz = ftell(infile);
			cout<<sz<<endl;
			fseek(infile,0,SEEK_SET);

			//unsigned char evenBuff[8], oddBuff[8];

			counter=0;
			while(fread(evenBuff, 1,sizeof(evenBuff),/*1,*/infile)){
				++counter;
				if(fread(oddBuff, 1,sizeof(oddBuff),/*1,*/infile)){
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
