#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

class HugeInt{
	friend ostream &operator<<(ostream &out, const HugeInt &huge){
		if(huge.num!=0) out<<huge.num;
		//out<<huge.str;  //bug:無法印出字串 
		return out;
	}
	friend istream &operator>>(istream &in, HugeInt &huge){
		in>>huge.num;
		return in;	
	}
public:	
	HugeInt(){}
	HugeInt(int input){
		num=input;		
	}
	HugeInt(string input){ //先轉成整數陣列 
		for(int i=0;i<21;i++){			
			arr[i]=input[i]-48;
		}
	}
	HugeInt operator+(HugeInt &huge){
		return num+huge.num;
	}
	HugeInt operator-(HugeInt &huge){
		int i=20;
		while(huge.num>0){ //從個位數開始減 
			int temp=huge.num%10; 
			huge.num=huge.num/10;
			if(temp>arr[i]){ //不夠減時 
				arr[i-1]--;
				arr[i]+=10;
			}			
			arr[i]=arr[i]-temp; 
			i--;	
		}		
		for(int i=0;i<21;i++){ //轉回字元陣列 
			ch[i]=arr[i]+48;
		}
		str.assign(ch); //轉成字串 
		cout<<str; //在此字串可正常輸出 
		return str; //傳回時似乎有bug
		
	}
private:
	int num=0;
	int arr[21];
	char ch[21];
	string str;
};

int main()
{
	HugeInt x;
	HugeInt y(28825252);
	HugeInt z("314159265358979323846"); //超過最大可儲存範圍 
	HugeInt result;
	cin>>x;
	result=x+y;
	cout<<x<<"+"<<y<<"="<<result<<endl;
	
	result=z-x;
	cout<<result<<endl;
}

