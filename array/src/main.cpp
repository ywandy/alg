#include <iostream>
#include <vector>
#include <cstring>
#include <2-DimensionalArray.h>
#include <ListNodeAlg.h>
#include <FibonacciArray.h>
#include <cmath>
using namespace std;

/*
 * 全排列算法
 * **/
char *buf[256];
int num_pos = 0;

void view_all_str(char *bf[],int count){
	for(int loop=0;loop<count;loop++){
		cout<<bf[loop]<<endl;
	}
}


void str_swap(char str[],int pos1,int pos2){
	char tmp = str[pos1];
	str[pos1] = str[pos2];
	str[pos2] = tmp;
}

void Permutation(char str[],int from,int to){
	if(to==0)
		return;
	if(from==to){
		for(int i=0;i<num_pos;i++){
			buf[num_pos] = new char[5];
			if(strcmp(str,buf[i])!=0){
				buf[num_pos] = new char[5];
				strcpy(buf[num_pos],str);
				num_pos++;
			}
		}
		//cout<<str<<endl;
	}
	for(int loop=from;loop<=to;loop++){
		str_swap(str,loop,from);
		Permutation(str,from+1,to);
		str_swap(str,loop,from);
	}
}

void unit_test_Permutation(){
	char test[5] = "ABAB";
	Permutation(test,0,3);
	view_all_str(buf,num_pos);
}
/****全排列算法********/


/****求二进制的1的个数****/

int BitCount(unsigned int n)//这个是错误的解法
{
    unsigned int c =0 ; // 计数器
    while (n >0)
    {
        if((n &1) ==1) // 当前位是1
            ++c ; // 计数器加1
        n >>=1 ; // 移位
    }
    return c ;
}

int  NumberOf1(int n) {
	int flag = 1;
	int count = 0;
	while(flag!=0){
		if(n&flag)
		   count++;
		flag = flag<<1; //利用左移而不是错解的右移

		}
	return count;
}


//顺时针旋转矩阵
void swap(int &x,int &y){
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

void print_2Array(vector<vector<int> > array){
	for(int i=0;i<(int)array.size();i++){
		for(int j=0;j<(int)array[0].size();j++){
			printf("%4d",array[i][j]);
		}
		printf("\n");
	}
}

void Rotat_left_90(vector<vector<int> > &array){
	for(int i=0;i<(int)array.size();i++){
		for(int j=i;j<(int)array[0].size();j++){
			swap(array[i][j],array[j][i]);
		}
	}
	for(int j=0;j<(int)array[0].size();j++){//列
		for(int i=0;i<(int)array.size()/2;i++){
			swap(array[i][j],array[array.size()-1-i][j]);
		}
	}
}

void Rotat_Right_90(vector<vector<int> > &array){
	for(int j=0;j<(int)array[0].size();j++){//列
		for(int i=0;i<(int)array.size()/2;i++){
			swap(array[i][j],array[array.size()-1-i][j]);
		}
	}
	for(int i=0;i<(int)array.size();i++){
		for(int j=i;j<(int)array[0].size();j++){
			swap(array[i][j],array[j][i]);
		}
	}
}

void CutLine(vector<vector<int> > &array,int line){
	for(int j=0;j<(int)array[0].size();j++){//列
		array[line-1][j] = -1;
	}
}

void ReBuild(vector<vector<int> > &array){
	vector<int> tmp;
	int ind=0;
	for(int i=0;i<(int)array.size();i++){
		for(int j=0;j<(int)array[0].size();j++){
			if(array[i][j]!=-1){
				tmp.push_back(array[i][j]);
			}
		}
	}
	//printf("%d",tmp.size());
	array.resize(sqrt(tmp.size()));
	array[0].resize(sqrt(tmp.size()));
	for(int i=0;i<sqrt(tmp.size());i++){
		for(int j=0;j<sqrt(tmp.size());j++){
			array[i][j]=tmp[ind];
			ind++;
		}
	}
}

void unit_test_rotatArray(){
	vector<vector<int> > matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	printf("旋转前的矩阵\n");
	print_2Array(matrix);
	CutLine(matrix,1);
	printf("切掉第一行\n");
	print_2Array(matrix);
	Rotat_left_90(matrix);
	printf("旋转后的矩阵\n");
	print_2Array(matrix);

	CutLine(matrix,1);
		printf("切掉第一行\n");
		print_2Array(matrix);
		Rotat_left_90(matrix);
		printf("旋转后的矩阵\n");
		print_2Array(matrix);

		CutLine(matrix,1);
			printf("切掉第一行\n");
			print_2Array(matrix);
			Rotat_left_90(matrix);
			printf("旋转后的矩阵\n");
			print_2Array(matrix);


				CutLine(matrix,1);
				printf("切掉第一行\n");
				print_2Array(matrix);
				Rotat_left_90(matrix);
				printf("旋转后的矩阵\n");
				print_2Array(matrix);

				printf("转换\n");
				ReBuild(matrix);
				print_2Array(matrix);

				CutLine(matrix,1);
				printf("切掉第一行\n");
				print_2Array(matrix);
				Rotat_left_90(matrix);
				printf("旋转后的矩阵\n");
				print_2Array(matrix);

				CutLine(matrix,1);
								printf("切掉第一行\n");
								print_2Array(matrix);
								Rotat_left_90(matrix);
								printf("旋转后的矩阵\n");
								print_2Array(matrix);

								CutLine(matrix,1);
												printf("切掉第一行\n");
												print_2Array(matrix);
												Rotat_left_90(matrix);
												printf("旋转后的矩阵\n");
												print_2Array(matrix);
}




int main(){
  std::cout << "hello world" << '\n';
  //unit_test_deleteDuplication();
  //unit_test_Permutation();
  //unit_test_Fibonacci();
  unit_test_rotatArray();
  return 0;
}
