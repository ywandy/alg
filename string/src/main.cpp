#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void ReplaceString(char *str,int length){
	int i,space_count;
	i = space_count = 0;
	for(i=0;i<length;i++){
		if(str[i]==' ')
			space_count++;
	}
	char *new_str,*old_str,*p;
	new_str = (char *)malloc((length+(space_count*2))*sizeof(char));
	old_str = str;
	p = new_str;
	for(i=0;i<length;i++){
		if(*old_str!=' '){
			*p=*old_str;
			p++;
			old_str++;
		}
		else if(*old_str==' '){
			*(p+0)='%';
			*(p+1)='2';
			*(p+2)='0';
			p+=3;
			old_str++;
		}
	}
	strcpy(str,new_str);
}


int main(){
  char teststr[] = "hello world my love";
  ReplaceString(teststr, sizeof(teststr));
  cout<<teststr<<endl;
  return 0;
}
