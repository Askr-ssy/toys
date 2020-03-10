#include<iostream>
#include<cstdio>
int main(void){
	using namespace std;
	int tem[100000]={0};
	int max=0;
	int n=0;
	int i=1;
	int a=0,b=0;
	unsigned int sum=0;
	
	cin>>n;
	tem[0]=n;
	for(int i=0;i<n;i++){
		int temp =0;
		cin>>temp;
		tem[temp]++; 
	}
	
	while(n!=1){
		
		for(;tem[i]==0;++i);
		if(tem[i]>1){
			a=b=i;
			tem[i]-=2;
		}
		else {
			a=i;
			tem[i]--;
			for(i++;tem[i]==0;++i);
			b=i;
			tem[i]--;
		}
		
			
	 	sum += a+b;
	 	tem[a+b]++;
	 	n--;
		
	}
	cout<<sum<<endl;
	
	return 0;
} 
