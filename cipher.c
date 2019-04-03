#include <stdio.h>



/***********************************************************
This function takes an array and two integers to decrypt using 
the rotation cipher. 
The array holds the message to be decrypted.
	The array at this stage will already be transformed from chars to ASCII
One Int holds the 'key' for the encryption.
One Int holds the length of the array.
************************************************************/
int rotEnc(int *text, int key);



int rotDec(/*inputs*/);
 


int subEnc(/*inputs*/);



int subDec(/*inputs*/);



int a2c(/*inputs*/);




int main(){
	printf("Initialising\n");
	//take stdin of the text
	//sent to function to encode in ascii
	//send ascii to appropriate cipher funct
	//int ascii = 65; //spells 'A' in ASCII
	//int key = 1;
	printf("%d\n", rotEnc(65, 1));
	
}

int rotEnc(int *text, int key){
	
	int i;
	
	//this for loop will loop for every value of the array 'text[]'
	for(i = 0; text[i] != 0; ++i){
		text[i] = val;
		if((val <= 'a') && (val >= 'z')){
			val = val + key;
			if(val > 'z'){
				val = val - 'z' + 'a' - 1;
			}
			val = text[i];
		}
		
	}
	
	
	
	
}
