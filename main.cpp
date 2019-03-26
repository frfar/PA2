#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdint.h>
#include <ftw.h>
#include <unistd.h>
#include <iostream>
#include <sys/stat.h>
 #include <string.h>
//changes made
using namespace std;

void dispVersion(){
	cout << "The current version is 1.2\n";
}

int sizeOfEveryFile =0;
int plnFilecnt=0;
	int direcnt= 0;
int filecnt(const char *filenam, const struct stat* statptr, int flag){
	//int plnFilecnt=0;
	//int direcnt= 0;
	
	if(flag == FTW_F){
		plnFilecnt+=1;
		sizeOfEveryFile+= statptr->st_size;
		
	}
	else if(flag == FTW_D){
		direcnt++;
		
	}
	else{
		//perror("A denied permission occured\n");
		//cout << "the argument was denied permission\n";
		
	}
	return 0;
}

int main(int argc, char *argv[])
{
	
	int flagg=0;
	int ftwValue;
	//printf("hello world\n");
	dispVersion();
	if(argc>1){
		char* dirPath= argv[1];
		ftwValue = ftw(dirPath, filecnt, 1024);
	}
	
	cout << plnFilecnt << " is the number of plain files in directory " << argv[1] << endl << direcnt<< " is the number of directories in " <<  argv[1] << endl << sizeOfEveryFile << " is the size in bytes of files in "<< argv[1] << endl;
	/*
	
	int aflag=0;
	int bflag= 0;
	char *Cvalue= NULL;
	int index;
	int c;
	 opterr=0;
	 
	 while((c = getopt (argc, argv, "abc:")) != -1)
		 switch (c)
		 {
			 case 'a':
				aflag =1;
				break;
			 case 'b':	
				bflag =1;
				break;
			 case 'c':
				Cvalue = optarg;
				break;
			 case '?':
				if (optopt == 'c')
					cout << optopt <<" requires an argument\n";
				else if(isprint (optopt))
					cout << "unknown " << optopt << endl;
				else
					cout << "unknown option" << optopt;
					return 1;
				default:
					abort();
		 }
		 
		 printf("aflag = %d, bflag= %d,Cvalue = %s\n", aflag, bflag, Cvalue);
		 
		 for ( index = optind; index < argc; index++){
			 printf ( "non-option argument %s\n", argv[index]);
		 }
		  * */
	 
	return 0;
}
