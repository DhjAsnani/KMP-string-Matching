                    /****************************************KMP STRING SEARCHING****************************************/
                    							/* by Dheeraj Asnani
                    							       @dhjasnani
                    							asnani.dheeraj@yahoo.com*/
                    							/* please mail if you have any queries or you find 
                    							        anything incorrect
														Happy Coding*/

#include <iostream>
#include <string.h>
#include <string>
using namespace std;

#define MAX 100000 //max Pattern/Text length

int prefix[MAX]; //declaring prefix array

void initialisePrefixArray(char A[])
{
	memset(prefix,0,sizeof(prefix)); //initialising prefix array to 0
	int j=0,k=0,i;
	prefix[0]=0;
	for(int i = 1; A[i] != '\0';)
	{
		if(A[i]==A[j])
		{
			
			prefix[i] = prefix[i-1] + 1;
			i++;													// O(n)
			j++;
		}
		else
		{
			if(j-1>=0)
			{
				j=prefix[j-1];
				if(A[i]==A[j])
				{
					prefix[i]=prefix[j]+1;
					i++;
				}
			}
			else 
			{
				prefix[i]=0;
				i++;
				j=0;
			}
		}
			
	}
}

int main()
{
	char T[MAX]; //text
	char P[MAX]; //pattern
	cout<<"ENTER TEXT:\t";
	cin>>T;
	cout<<"ENTER PATTERN:\t";
	cin>>P;
	int i,j;
	for(i=0,j=0;T[i]!='\0';)
	{
		if(T[i]==P[j])
		{																//O(m)
			
			i++;
			j++;
		}
		else
		{
			i=i-prefix[j-1]+1;
		}
		if(j==strlen(P))  //break when length become equals to pattern length
		{
			cout<<"Pattern found"<<endl;
			break;
		}
	
	}
	return 0;												//O(m+n)
}











