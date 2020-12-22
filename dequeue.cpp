#include<iostream>
using namespace std;
struct dequeue()
{
	int a[100];
	int f,r;
	void frontpush(int);
	void frontpop();
	void rearpush();
	void rearpop();
}