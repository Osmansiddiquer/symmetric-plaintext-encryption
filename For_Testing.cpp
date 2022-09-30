#include <iostream>
#include <string>

using namespace std;
int main()
{
	string STRING_IN;
	string STRING_OUT = "";
	string key;

	long long seed;
    long long b= 84;
    long long a = 54;
    long long m = 3214143;
	long long random;
	char choice;

	cout<<"E or D: ";
	cin>>choice;
	if(choice !='E' && choice != 'D')
	{
		cout<<"You bad!";
		return 0;
	}
	cin.ignore(256, '\n');
	cout<<"Enter STRING_IN: ";
	getline(cin, STRING_IN,'\n');

	cout<<"Enter key: ";
	getline(cin, key, '\n');

	int kl = key.length();
	random = (long long)((float)((a*random*random+b)%m)/(float)(m)*(float)kl);
	int l = STRING_IN.length();
	int dec;

	seed = key.at(0);

	for(int i=0; i<l; i++)
	{
		random = (long long)((float)((a*random*random+b)%m)/(float)(m)*(float)kl);
		int shift_number = int(key.at(random));
		dec = int(STRING_IN.at(i));
		if(dec!=32)
		{
			if(choice == 'E')
			{
				dec -= shift_number;
				if(dec<32)
					dec = 126+(dec-32);
				shift_number%=8;
			}
			else
			{	
				dec += shift_number;
				if(dec>126)
					dec = 32+(dec-126);
				shift_number%=8;
			}                    
		}
		STRING_OUT.push_back(char(dec));
	}  
	cout<<STRING_OUT<<endl;
	return 0;
}