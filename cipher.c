#include <stdio.h>



/***********************************************************
This function encrypts a message with the rotation, or Caeser 
cipher.
Takes a string (message to encrypt), and also an int (key).
This function will print the encrypted message to stdout 
automatically
************************************************************/
void rotEnc(char *message, int key);


/***********************************************************
This function decrypts a message encrypted with the rotation, 
or Caeser cipher.
Takes a string (message to decrypt), and also an int (key).
This function will print the encrypted message to stdout 
automatically
************************************************************/
void rotDec(char *message, int key);
 

/***********************************************************
This function encrypts a message with the substitution 
cipher.
Takes a string (message to encrypt), and a second string (key).
This function will print the encrypted message to stdout 
automatically
************************************************************/
void subEnc(char *message, char *key);


/***********************************************************
This function decrypts a message encrypted with the substitution 
cipher.
Takes a string (message to decrypt), and a second string (key).
This function will print the encrypted message to stdout 
automatically
************************************************************/
void subDec(char *message, char *key);




int main(){
	int selection = 0;
	int keyI;
	char text[1000];
	char key[26];
	
	
	printf("Welcome to cipherProgramThing. Here are our algorithms:\n");
	printf("(1) Rotation cipher encryption\n"); 
	printf("(2) Rotation Cipher decryption with key\n"); 
	printf("(3) Rotation Cipher decryption without key\n"); 
	printf("(4) Substitution Cipher encryption\n");
	printf("(5) Substitution Cipher decryption with key\n");
	printf("(6) Substitution Cipher decryption without key\n");   
	printf("please select your algorithm by typing its associated number and pressing enter\n");
	
	//Will loop until until selection is changed from 0 i.e. when the user selects one of the above options
	while(selection == 0){
	scanf("%d", &selection); //here selection is taken from stdin which means that the loop will stop next time
	 
	//based on the number input for selecton user is sent to a case with corresponding number
	switch(selection){ //each case takes a text string and key of either int (case 1&2) or string (case 4&5) from stdin
			//this case will encrypt based off
			case 1:				
				printf("You selected: (1) Rotation cipher encryption\n"); 
				
				printf("please enter the Key:\n");
				scanf("%d", &keyI);
				
				printf("Please enter your text followed by a '~' then press enter:\n");
				scanf("%[^~]s",text); //the '[^~]' means that scanf will read stdin until it encounters a ~ character
									  //this means spaces can be read
				printf("Your encrypted text is:\n");				
				rotEnc(text, keyI); //sends message and key to function to be encrypted
				
				break;
			case 2:
				printf("You selected: (2) Rotation Cipher decryption with key\n"); 				
				printf("please enter the Key:\n");
				scanf("%d", &keyI);
					
				printf("Please enter your text followed by a '~' then press enter:\n");
				scanf("%[^~]s",text);
									
				printf("Your decrypted text is:\n");
				rotDec(text, keyI); //sends message and key to function to decrypt
					
				break;
			case 3:
				printf("You selected: (3) Rotation Cipher decryption without key\n"); 
					
				printf("Sorry this feature is still under construction,\n please select another algorithm\n");
				selection = 0; //resets selection so that the user can re enter a selection with the while loop
				break;
			case 4:
				printf("You selected: (4) Substitution Cipher encryption\n"); 
					
				printf("please enter the Key:\n");
				scanf("%s", key);//note the key variable is changed to accomodate for a string key not int
					
				printf("Please enter your text followed by a '~' then press enter:\n");
				scanf("%[^~]s",text);
					
				printf("Your encrypted text is:\n");
				subEnc(text, key);
					
				break;
			case 5:
				printf("You selected: (5) Substitution Cipher decryption with key\n"); 
					
				printf("please enter the Key:\n");
				scanf("%s", key); //note the key variable is changed to accomodate for a string key not int
					
				printf("Please enter your text followed by a '~' then press enter:\n");
				scanf("%[^~]s",text);
					
				printf("Your decrypted text is:\n");
				subDec(text, key); //sends message and key to subDec to encrypt
			
				break;
			case 6:
				printf("You selected: (6) Substitution Cipher decryption without key\n"); 
				
				printf("Sorry this feature is still under construction,\n please select another algorithm\n");
				selection = 0;
				break;
			//if the user selects a number not on the list then they are sent here (user proofing)
			default:
				printf("please enter a number that matches one of the above sections:");
				selection = 0;
				break;
		}
	}
}

void rotEnc(char *message, int key){
	
	int i;
	int val;
	
	//this for loop will loop for every value of the array 'text[]'
	for(i = 0; message[i] != 0; ++i){         //loops for every letter
		val = message[i]; 					//the letter is assigned to val
							             
		if((val >= 'a') && (val <= 'z')){  //if the letter is between a and z
			val = val + key;               //add the key to the letter ascii val
			
			if(val > 'z'){                 //if ascii val is larger than z when added
				val = val - 'z' + 'a' - 1; //swap it around to the start of alphabet
			}
			message[i] = val;                 //set the encryted letter to its place in the array
			}                                                            	
	}
	printf("%s\n", message); //after all looping print the final message	
}


void rotDec(char *message, int key){
	int i;
	int val;
	
	//this for loop will loop for every value of the array 'text[]'
	for(i = 0; message[i] != 0; ++i){         //loops for every letter
		val = message[i]; 					 //the letter is assigned to val
						             
		if((val >= 'a') && (val <= 'z')){  //if the letter is between a and z
			val = val - key;               //subtract the key to the letter ascii val
			
			if(val < 'a'){                 //if ascii val is less than a when decrypted
				val = val + 'z' - 'a' + 1; //swap it around to the end of alphabet
			}
			message[i] = val;                 //set the encryted letter to its place in the array 
			}                                                           	
	}
	printf("%s\n", message); //after all looping print the final message		
}

void subEnc(char *message, char *key){
	int i, i1;
	int val;
	int keyA;
	int alph;
	int enc;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

	for(i = 1; message[i] != 0; i++){  //loops for every letter of message
		
		val = message[i];   //sets the letter at that specific loop equal to val
		
		
		if(val != ' '){ //skips spaces in message
		for(i1 = 0; alphabet[i1] != 0; ++i1){ //loops for every letter of the alphabet
			alph = alphabet[i1];  //the letter of the alphabet is equal to alph
			
			if(val == alph)   //if the lettter in the message is equal to the letter in the alphabet 
				enc = i1;	  //set that spot in the alphabet as enc
			}
		
		keyA = key[enc];  //find that spot in the key seeing as the key is also 26 chars
		
		
		val = keyA; //set the value in the message equal to the new encrypted char
		
		message[i] = val; //put the new letter back in the array
		}
		}
	printf("%s\n", message); //print the encrypted message
}

void subDec(char *message, char *key){
	int i, i1;
	int val;
	int keyA;
	int alph;
	int enc;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

	for(i = 1; message[i] != 0; ++i){  //loops for every letter of message
		
		val = message[i]; //sets the letter at that specific loop equal to val
		if(val != ' '){ //skips spaces in message
		for(i1 = 0; key[i1] != 0; ++i1){ //loops for every letter of the key
			keyA = key[i1];		//the specific letter of the key is equal to keyA
			if(val == keyA)		//if the message letter is equal to the letter in the key
				enc = i1;		//record that spot in the key as enc
		}

		alph = alphabet[enc]; //at enc find the letter of the alphabet and set that equal to alph
		
		
		val = alph;  //save the new decrypted letter as val
		message[i] = val; //put that back in the array
	}
	}
	printf("%s\n", message); //print the new message
}
