//https://acm.timus.ru/problem.aspx?space=1&num=1607
#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	while(a<=c){
		a+=b;
		if(a>=c){
			cout<<(c);
			exit(0);
		}
		c-=d;
	}
	cout<<a;
}
