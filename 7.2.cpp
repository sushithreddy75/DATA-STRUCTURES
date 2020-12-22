#include<iostream>
using namespace std;
void swap(char*,char*);
void permute(int,string);
int main()
{
	cout<<"enter string: ";
	string s;
	cin>>s;
	cout<<"permutations\n";
	permute(0,s);
	return 0;
}
void permute(int i,string s)
{
	if(s[i]=='\0')
		cout<<s<<endl;
	for(int j=i;s[j]!='\0';j++)
	{
		swap(&s[i],&s[j]);
		permute(i+1,s);
		swap(&s[i],&s[j]);
	}
}
void swap(char *x,char *y)
{
	char t=*x;
	*x=*y;
	*y=t;
}