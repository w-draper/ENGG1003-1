#include <stdio.h>



/***********************************************************

************************************************************/
void rotEnc(char *message, int key);


/***********************************************************

************************************************************/
void rotDec(char *message, int key);
 

/***********************************************************

************************************************************/
void subEnc(char *message, char *key);


/***********************************************************

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
	
	while(selection == 0){
	scanf("%d", &selection);
	 
	if((selection > 0) && (selection <= 6)){
		switch(selection){
			case 1:
				printf("You selected: (1) Rotation cipher encryption\n"); 
				
				printf("please enter the Key:\n");
				scanf("%d", &keyI);
				
				printf("Please enter your text followed by a '~' then press enter:\n");
				scanf("%[^~]s",text);
				
				printf("Your encrypted text is:\n");
				rotEnc(text, keyI);
				break;
			case 2:
				printf("You selected: (2) Rotation Cipher decryption with key\n"); 
				
				printf("please enter the Key:\n");
				scanf("%d", &keyI);
				
				printf("Please enter your text followed by a '~' then press enter:\n");
				scanf("%[^~]s",text);
				
				printf("Your decrypted text is:\n");
				rotDec(text, keyI);
				break;
			case 3:
				printf("You selected: (3) Rotation Cipher decryption without key\n"); 
				
				printf("Sorry this feature is still under construction,\n please select another algorithm\n");
				selection = 0;
				break;
			case 4:
				printf("You selected: (4) Substitution Cipher encryption\n"); 
				
				printf("please enter the Key followed by a '~' then press enter:\n");
				scanf("%s", key);
				
				printf("Please enter your text followed by a '~' then press enter:\n");
				scanf("%[^~]s",text);
				
				printf("Your encrypted text is:\n");
				subEnc(text, key);
				break;
			case 5:
				printf("You selected: (5) Substitution Cipher decryption with key\n"); 
				
				printf("please enter the Key followed by a '~' then press enter:\n");
				scanf("%s", key);
				
				printf("Please enter your text followed by a '~' then press enter:\n");
				scanf("%[^~]s",text);
				
				printf("Your decrypted text is:\n");
				subDec(text, key);
				break;
			case 6:
				printf("You selected: (6) Substitution Cipher decryption without key\n"); 
				
				printf("Sorry this feature is still under construction,\n please select another algorithm\n");
				selection = 0;
				break;

		}
	}
	else
		printf("please enter a number that matches one of the above sections:");
	}


	
}

void rotEnc(char *message, int key){
	
	int i;
	int val;
	
	//this for loop will loop for every value of the array 'text[]'
	for(i = 0; message[i] != 0; ++i){         //loops for every letter
		val = message[i]; 
		//printf("%d\n", val);              //the letter is assigned to val
		if((val >= 'a') && (val <= 'z')){  //if the letter is between a and z
			val = val + key;               //add the key to the letter ascii val
			
			if(val > 'z'){                 //if ascii val is larger than z when added
				val = val - 'z' + 'a' - 1; //swap it around to the start of alphabet
			}
			message[i] = val;                 //set the encryted letter to its place in
			//printf("%c", val);
			}                              //array                              	
	}
	printf("%s\n", message);	
}


void rotDec(char *message, int key){
	int i;
	int val;
	
	//this for loop will loop for every value of the array 'text[]'
	for(i = 0; message[i] != 0; ++i){         //loops for every letter
		val = message[i]; 
		//printf("%d\n", val);              //the letter is assigned to val
		if((val >= 'a') && (val <= 'z')){  //if the letter is between a and z
			val = val - key;               //subtract the key to the letter ascii val
			
			if(val < 'a'){                 //if ascii val is less than a when decrypted
				val = val + 'z' - 'a' + 1; //swap it around to the end of alphabet
			}
			message[i] = val;                 //set the encryted letter to its place in
			//printf("%c", val);
			}                              //array                              	
	}
	printf("%s\n", message);	
}

void subEnc(char *message, char *key){
	int i, i1;
	int val;
	int keyA;
	int alph;
	int enc;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

	for(i = 0; message[i] != 0; ++i){
		
		val = message[i];
		
		for(i1 = 0; alphabet[i1] != 0; ++i1){
			alph = alphabet[i1];
			if(val == alph)
				enc = i1;
				
		}
		
		
		
		keyA = key[enc];
		
		
		val = keyA;
		message[i] = val;
	}
	printf("%s\n", message);
}

void subDec(char *message, char *key){
	int i, i1;
	int val;
	int keyA;
	int alph;
	int enc;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

	for(i = 0; message[i] != 0; ++i){
		
		val = message[i];
		
		for(i1 = 0; key[i1] != 0; ++i1){
			keyA = key[i1];
			if(val == keyA)
				enc = i1;
				
		}
		
		
		
		alph = alphabet[enc];
		
		
		val = alph;
		message[i] = val;
	}
	printf("%s\n", message);
}
