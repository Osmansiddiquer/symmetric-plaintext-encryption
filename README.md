# symmetric-plaintext-encryption
*Starting as FoP assignment*
## OVERVIEW
ENCRYPTION and DECRYPTION of strings using ceaser's cipher. Features include:<br>

* Password support instead of a single shift number.
* Implemenetation of pseudo-random generation using LCG(modified) to further enhance security by randomizing password before using it for encryption (NOT suitable for cybersecurity applications).
* Extremely difficult to break without knowledge of the following:
	
	- Algorithm along with exact parameters used, or Password.
	- Input Text samples.
	- Output Text Samples.
	- Relatively low complexity.
		
- Choice for encryption and decryption.
- Symmetric: same key is used for encrypting and decrypting the message.
- Does NOT add multiple layers of encryption due to the fact that same amount of effort would be needed to break the encryption if multiple ceaser's ciphers are added.
- Whitespace space is also included in the cipher.
	
## USAGE:
> - Select a choice for encrpyting OR decrypting a message
> - Enter the string you want to be processed
> - Enter your key (Create a new key if encrypting)
