#include "my_string.hpp"


/*  This functions takes 1 input, a pointer to a char (likely array).  It then counts the number of characters until a NULL-character is found and returns the number of characters found. I didn't understand the "size_t" type so I just made it an int*/
int myStringLength(const char *str){
    int counter = 0;
    while(str[counter]!= '\0'){
        counter++;
    }
    return counter;
}

/* This function takes 2 inputs, pointer to characers (likely arrays).  It compares the characters in each and returns a negative value if the first char that doesn't mach has a lower value in str1 than in str2. Or it returns a positive value if the first char that doesn't mach has a higher value in str1 than in str2. Or it returns 0 if the strings match completely. */
int myStringCompare(const char * str1, const char * str2){
    int i = 0, p=0;
    while(p == 0){
        if (str1[i] > str2[i]){
            goto positive;
        }
        else if(str1[i] < str2[i]){
            goto negative;
        }
        else {
            if (str1[i] == '\0') {
                goto even;
            }
            if (str1[i] == str2[i]){
                i++;
                p=0;
            }
        }
    }
positive:
    return 1;
negative:
    return -1;
even:
    return 0;
}

/* This function takes 2 inputs, pointer to characers (likely arrays).  It copies the characters in the source to the destination until '\0' is found in the source. */
char * myStringCopy (char * destination, const char * source){
    int n = 0;
    
    do {
        destination[n] = source[n];
        n++;
    } while(source[n-1] != '\0');
    char * pt_string = destination;
    
    return pt_string;
}


/*  Concatenates the source string to the end of the destination string and end with a NULL symbol*/
char * myStringCat(char * destination, const char * source){
    int count = 0, i = 0, n = 0;
    
    while(i == 0){
        if (destination != '\0'){
            destination++;
        }
        if (destination[count] == '\0'){
            i = 1;
        }
    }
    
    do {
        destination[n] = source[n];
        n++;
    } while(source[n] != '\0');
    destination[n] = '\0';
    
    return destination;
}

