/*
Ryan Chalhoub
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *getDateAndTime();//Declaring dateandtime 
int getInteger();//Declaring getInteger
char file[32];//Declaring file
char opt[2];//Declaring options for saving
char binString[128];//Declaring binary string array
char hexString[128];//Declaring hex array
char octString[128];//Declaring octal array
void decimalToBinary(int decValue, char binString[]);//Declaring d-to-binary
void decimalToHex(int decValue, char hexString[]);//Dec d-to-hex
void decimalToOct(int decValue, char octString[]);//Dec d-to-octal

int main(){//main function
    char name[16];//declaring and giving name 16 in memory space 
    int i = 0;//initializing i for while loop so program keeps looping
    while (i==0){//keeps looping until x is entered
    printf("Enter your name: ");
    fgets(name,16,stdin);
    int decValue = getInteger();//assigning value to decValue for conversions
    if(decValue == -1){//condition for x to exit program
        return -1;
    }
    printf("\nName: %s",name);
    printf ("Today's date and time : %s",getDateAndTime());
    printf("\nDecimal:%d\n", decValue);
    decimalToBinary(decValue, binString);
    decimalToOct(decValue, octString);
    decimalToHex(decValue, hexString);
    printf("Save to a file? (y/n):");
    fgets(opt,2,stdin);
    if (opt[0] =='y'){
      //if the user says yes to saving the file
        printf("Enter file name:");
        scanf("%s",file);
        getchar();
        FILE *fileptr = fopen(file, "w");
        if(fileptr != NULL){
         //this is the stuff that will be printed into the file
            fprintf(fileptr,"Name: %s\n",name);
            fprintf(fileptr,"Today's date and time : %s",getDateAndTime());
            fprintf(fileptr, "Decimal: %d\n", decValue);
            fprintf(fileptr, "Binary: %s\n", binString);
            fprintf(fileptr, "Octal: %s\n",octString);
            fprintf(fileptr, "Hex: %s\n", hexString);
            fclose(fileptr);//once its done writing all this close the file
            printf("File Saved.\n");//after it closes the file tell the user its saved
    }
    }
    }
}

char *getDateAndTime(){//date and time function given by professor
  time_t t;
  time (&t);
  return ctime (&t);
}

int getInteger(){//Defining getInteger
    char user[16];//Declaring user and giving it 16 in memory space
    printf("Enter an Integer [1 – 1000000] or type x to exit:");
    fgets(user,16,stdin);
    if(strcmp(user,"x\n") == 0){//if user input is 'x'
        printf("Goodbye!\n");
        return -1;//Unsuccessful exit
    }
    while (atoi(user)<1 || atoi(user)>1000000){//If the number give is less than 1 or more than a million
        printf("Out of range!\n");
        printf("Enter an Integer [1 – 1000000] or type x to exit:");
        fgets(user,16,stdin);
        if(strcmp(user,"x\n") == 0){//I had to repeat what to do for x under the while loop
            printf("Goodbye!\n");
            return -1;//Unsuccessful exit
            }
    }
    return atoi(user);//return the value to main as an integer
}

void decimalToBinary(int decValue, char binString[]){//void so don't return anything to main
    char binStringback[128];//Declaring backwards string as the algorithm prints it backwards
    int count = 0;//initializing the count
    int v = 1;//initializing v 
    int j;//initializing j
    int quotient = decValue;//initializing quotient and assigning decValue to it
    printf("Binary: ");
    while(quotient != 0){//while quotient is not 0
        binStringback[v++] = quotient % 2;
        quotient = quotient / 2;
    }
    for(j = v - 1; j > 0; j--){//this will print the numbers in the correct order
        printf("%d", binStringback[j]);//printing them one by one
        binString[count++] = binStringback[j] + 48;
        //48 is the offset and each value is stored in binString 
        //in the correct order
    }
    printf("\n");
    //new line before the next thing is printed
}

void decimalToOct(int decValue, char octString[]){//also void
   //all of these declarations and initializing will be the same as the last
    int quotient = decValue;
    int o = 1;
    int j;
    int counter=0;
    char octStringBack[32];
    printf("Octal: ");
    while(quotient != 0){
        octStringBack[o++] = quotient % 8;
        quotient = quotient / 8;
    }
    for(j = o - 1; j > 0; j--){
        printf("%d",octStringBack[j]);
        octString[counter++] = octStringBack[j] + 48;
        //turns out octal has the same offset as binary
    }
    octString[counter] = '\0';//null bite
    printf("\n");
}

void decimalToHex(int decValue, char hexString[]){
   char hexStringback[128];
   int count = 0;
   long int quotient;
   int c=1,j,temp;
   quotient = decValue;
   while(quotient!=0){
      temp = quotient % 16;
      // Convert integer into character
      if( temp < 10){
         temp = temp + 48;
      }
      else
      temp = temp + 55;
      hexStringback[c++]= temp;
      quotient = quotient / 16;
   }
   printf("Hexadecimal: ");
   for(j = c -1 ; j> 0; j--){
      printf("%c",hexStringback[j]);//printing backwards
      hexString[count++] = hexStringback[j];//to print in the correct order
   }
hexString[count] = '\0';//null bite at the end
printf("\n");
printf("\n");//two new lines for the sake of format
}

