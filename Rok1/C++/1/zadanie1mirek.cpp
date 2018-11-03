#include <cstdlib>
#include <iostream>
#include <climits>
#include <vector>
#include <stdexcept>
#include <sstream>
#include<cmath>
#include <cstdint>
#include<fstream>

using namespace std;
bool prime(long long n)
{
long long z;
	z=sqrt<long long>(n);
// if 
for(long long i=3;i<=z;i+=2)
{
	if(n%i==0)
		return 0;			
}
return 1;
}
vector <long long> podzial ( long long liczba ){
	
vector <long long> vect;
long long k=2;
//if(prime(liczba))
//	vect.push_back(liczba);
//else{
	
	
	
	while( liczba > 1 )
	            {	
	            	long long ile=0;
	            	long long z;
					z=sqrt<long long>(liczba);
					long long dodatek=liczba;	
	                while( liczba % k==0) 
	                {        
	                    vect.push_back(k);
						ile++;
	                    liczba /= k;
	                }
	                k++;
	                if(k>z && ile==0)
	                {
					
	                vect.push_back(dodatek);
	                break;
	            }
	            } 	
	//}
	return vect;	
}
void wypisz ( vector < long long > vect ){
    
    for(int i = 0; i < vect.size(); i++ )
    {
        if(i+1 == vect.size())
			{
			 cout << vect[i] << endl; 
			 }
         
        else { cout <<  vect[ i ]  << "*"; }      
    }        
}
bool check(string slowo)
{
	bool tab[256] = {0};
	tab['0']=true;
	

for(int i=0;i<slowo.size();i++)	
{
	
if(i==0)
	if((slowo[i]!='-')&&(slowo[i]!='0')&&(slowo[i]!='1')&&(slowo[i]!='2')&&(slowo[i]!='3')&&(slowo[i]!='4')&&(slowo[i]!='5')&&(slowo[i]!='6')&&(slowo[i]!='7')&&(slowo[i]!='8')&&(slowo[i]!='9'))
	return 0;
if(i!=0)
	if((slowo[i]!='0')&&(slowo[i]!='1')&&(slowo[i]!='2')&&(slowo[i]!='3')&&(slowo[i]!='4')&&(slowo[i]!='5')&&(slowo[i]!='6')&&(slowo[i]!='7')&&(slowo[i]!='8')&&(slowo[i]!='9'))	
	return 0;
}
if(slowo.size()>20)
return 0;
return 1;		
}


int main () {
	
	vector<string> wczyt;
	int ile=0;
	while (true)
	{
	string slowo;
	cout<<"Podaj liczbe"<<endl;
	cin>>slowo;
	if(check(slowo)==1)	
	{
		wczyt.push_back(slowo);
		ile++;
	}
	else if (slowo=="stop")
			 break;
	else
  		cout<<"Zly agrument"<<endl;
			
	}
	if(ile == 0){
		cerr << "Nie podales ani jednego poprawnego argumentu, podaj liczbe naturalne ktora w long longu";
	}
	 
	for(unsigned int  i=0;i<wczyt.size();i++)
	{	
			
		if(wczyt[i][0]!='-')
		{	
			unsigned long long a=stoull(wczyt[i]);
			
			if( a > LLONG_MIN || a < LLONG_MAX )
			{
				cout<<"Czynniki pierwsze : "<<a <<"  = ";
				vector <long long> vect = podzial ( a );
				wypisz ( vect );
			}
			else
				throw std::invalid_argument("Za mala/duza liczba.");
		}
		else
		{	
			if(wczyt[i]=="-9223372036854775808")
			{
				cout<<"Czynniki pierwsze  : "<<"-9223372036854775808"<<" = -1*";
				for(int i=0;i<64;i++  )
				cout<<"2 *";
				cout<<endl;
				
			}
			else{
			
			wczyt[i].erase(0,1);
			unsigned long long a=stoull(wczyt[i]);
			if( a > LLONG_MIN || a < LLONG_MAX )
			{
				cout<<"Czynniki pierwsze  : "<<a<<" = -1*";
				vector <long long> vect = podzial ( a );
				wypisz ( vect );	
			}
			else
				throw std::invalid_argument("Za mala/duza liczba.");
			}
		}
	cout<<endl;
	}
	cout<<endl;
	system("pause");	
    return 0;
}

