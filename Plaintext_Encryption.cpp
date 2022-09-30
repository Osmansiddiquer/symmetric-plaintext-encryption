/*ENCRYPTION and DECRYPTION of strings using ceaser's cipher. Features include:
	*Password support instead of a single shift number
	*Implemenetation of pseudo-random generation using LCG(modified) to further enhance security 
	by randomizing password before using it for encryption (NOT suitable for cybersecurity applications)
	*Extremely difficult to break without knowledge of the following:
		-> algorithm along with exact parameters used or password
		-> Input Text samples
		-> Output Text Samples
		-> Relatively low complexity
	*Choice for encryption and decryption
	*Symmetric: same key is used for encrypting and decrypting the message
	*Does NOT add multiple layers of encryption due to the fact that same amount of effort 
	would be needed to break the encryption if multiple ceaser's ciphers are added.
	*whitespace space is also included in the cipher
*/
 //Has been tested to work with g++ compiler in VS code, and Dev C++

#include <iostream>
#include <string>
#define b 84		//
#define A 54		// parameters for random number generation
#define m 32141433  //
using namespace std;
int main()
{
	string STRING_IN;
	string STRING_OUT = "";
	string key;

	long long n;
	char choice;

	cout<<"Do you wish to encrypt(E) or decrypt(D): ";//take choice for encryption or decryption
	cin>>choice;
	//checking
	if(choice !='E' && choice != 'D')
	{
		cout<<"Invalid choice";
		return 0;
	}

	cin.ignore(256, '\n'); //to ignore \n from previous cin usage as it tends to 
						   //leave the garbage(in this case \n) to the stream
	cout<<"Enter Input String: ";	//take input string
	getline(cin, STRING_IN,'\n');

	cout<<"Enter key: ";	//take key to encrypt/decrypt with
	getline(cin, key, '\n');

	//calculating string and key lengths
	int kl = key.length();
	int l = STRING_IN.length();

	//sets initial value of random variable (in this case is also the seed) as ascii value of first char of key
	n = int(key.at(0)); 

	for(int i=0; i<l; i++)
	{
		n = (long long)((float)((A*n*n+b)%m)/(float)(m)*(float)kl); //calculates random number n in ragne of [0, kl) 
		int shift_number = int(key.at(n)); //calulates shift_number as ascii value of n_th character of the key 
		int dec = int(STRING_IN.at(i)); //calculates ascii decimal value of i_th character in Input String
		
		if(choice == 'E') //ceaser's cipher implementation
		{
			dec -= shift_number;
			if(dec<32)
				dec = 126+(dec-32);
			shift_number%=8;
		}
		else //decryption
		{	
			dec += shift_number;
			if(dec>126)
				dec = 32+(dec-126);
			shift_number%=8;
		}
		STRING_OUT.push_back(char(dec)); //appending new character to Output String
	}  
	cout<<"Output String: "<<STRING_OUT<<endl;
	return 0;
}