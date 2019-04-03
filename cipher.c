#include <stdio.h>



/***********************************************************
This function takes an array and two integers to decrypt using 
the rotation cipher. 
The array holds the message to be decrypted.
	The array at this stage will already be transformed from chars to ASCII
One Int holds the 'key' for the encryption.
One Int holds the length of the array.
************************************************************/
int rotEnc(char *text, int key);



int rotDec(/*inputs*/);
 


int subEnc(/*inputs*/);



int subDec(/*inputs*/);



int a2c(/*inputs*/);




int main(){
	printf("Initialising\n");
	//take stdin of the text
	char code[100] = "hello";
	int key = 4;
	
	printf("%d\n", rotEnc(*code, key));
	
}

int rotEnc(char *text, int key){
	
	int i;
	int val;
	
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
