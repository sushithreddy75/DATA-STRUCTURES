#include<iostream>
using namespace std;
int main()
{
	int y;
	cout<<"ENTER YEAR: ";
	cin>>y;
	int d=((y-1900)+(y-1900)/4-(y-1900)/100+(y-1900)/400)%7;
	int g=(d+1)%7;
	string month[]={"JANUARY","FEBRUARY","MARCH","APRIL","MAY",
"JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
    string week[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    cout<<"\n\nCALENDER "<<y;
	for(int i=1;i<=12;i++)
	{
		cout<<"\n\n"<<month[i-1]<<"\n\n";
		int m;
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
			m=31;
		else if(i==2)
		{
			m=28;
			if((y%4==0 && y%100!=0)||y%400==0)
				m++;
		}
		else 
			m=30;
		for(int j=1;j<=7;j++)
		{
			cout<<week[j-1]<<"   ";
			int x=j-g;
			while(x<=m)
			{
				if(x<=0)
					cout<<"      ";
				else
				{
					cout<<x<<"    ";
					if(x<10)
						cout<<" ";
				}
				x+=7;
			}
			cout<<endl;
		}
		g+=m;
		g%=7;
	}
}