#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

class HugeInt{
	friend ostream &operator<<(ostream &out, const HugeInt &huge){
		if(huge.num!=0) out<<huge.num;
		//out<<huge.str;  //bug:�L�k�L�X�r�� 
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
	HugeInt(string input){ //���ন��ư}�C 
		for(int i=0;i<21;i++){			
			arr[i]=input[i]-48;
		}
	}
	HugeInt operator+(HugeInt &huge){
		return num+huge.num;
	}
	HugeInt operator-(HugeInt &huge){
		int i=20;
		while(huge.num>0){ //�q�Ӧ�ƶ}�l�� 
			int temp=huge.num%10; 
			huge.num=huge.num/10;
			if(temp>arr[i]){ //������� 
				arr[i-1]--;
				arr[i]+=10;
			}			
			arr[i]=arr[i]-temp; 
			i--;	
		}		
		for(int i=0;i<21;i++){ //��^�r���}�C 
			ch[i]=arr[i]+48;
		}
		str.assign(ch); //�ন�r�� 
		cout<<str; //�b���r��i���`��X 
		return str; //�Ǧ^�ɦ��G��bug
		
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
	HugeInt z("314159265358979323846"); //�W�L�̤j�i�x�s�d�� 
	HugeInt result;
	cin>>x;
	result=x+y;
	cout<<x<<"+"<<y<<"="<<result<<endl;
	
	result=z-x;
	cout<<result<<endl;
}

