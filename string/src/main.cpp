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


void unit_test_ReplaceString(){
	char teststr[] = "hello world my love";
	ReplaceString(teststr, sizeof(teststr));
	cout<<teststr<<endl;
}


char FirstAppearone(char inpstr[],int length){
	int hashmap[2][256]={0};
	int index_small = length+1;
	for(int loop=0;loop<length;loop++){
		hashmap[1][(int)inpstr[loop]]++;
		hashmap[2][(int)inpstr[loop]]=loop;
	}
	for(int searchloop=0;searchloop<length;searchloop++){
		if(hashmap[1][(int)inpstr[searchloop]]==1){
			if(hashmap[2][(int)inpstr[searchloop]]<index_small)
					index_small=hashmap[2][(int)inpstr[searchloop]];
			}
	}

	return inpstr[index_small];
}

void unit_test_FirstAppearone(){
	char teststr[] = "hfdaihfahfoiwhwoiahfoiwafhoiafhafhiwahfoiahfoiawoifwaoihfoiahfwaihfoifhwaoihfoahfoahfoahgoihgoiwahgowaigwakfnkajgwajgwagwajgpwagowa8ig";
	cout<<"raw inp is:"<<teststr<<endl;
	cout<<"the index small:"<<FirstAppearone(teststr,sizeof(teststr))<<endl;
}
int main(){
	unit_test_FirstAppearone();
	return 0;
}
