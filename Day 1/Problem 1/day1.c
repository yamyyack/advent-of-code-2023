#include <stdio.h>   
#include <string.h>

int main() {
   FILE *fptr;

   // Open a file in read mode
   fptr = fopen("Test.txt", "r");

   // Store the content of the file
   char myString[100];

   char calibration_number[3] = {'!', '!', '\0'};

   char number_array[10] = {'1','2','3','4','5','6','7','8','9', '\0'};
   char string_number_array[10][100] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "\0"};
   for (int i = 0; i < 10; i++) 
   {
      printf("%s\n", string_number_array[i]);

   }
   int number_count = strlen(number_array);
   int sum = 0;

   // Read the content and store it inside myString
  while(fgets(myString, 100, fptr)) {
   for(int i = 0; i <= strlen(myString); i++)
   {
      if(calibration_number[0] == '!')
      {
         for(int j = 0; j<number_count;j++)
         {

            if(myString[i] == number_array[j]){
               
               calibration_number[0] = myString[i];
               break;
            }
            if(strcmp(&myString[i], string_number_array[j])){
               printf("help : %s", &myString[i]);
               calibration_number[0] = number_array[i];
               break;
            }
         }
         
      }
      
      if(calibration_number[1] == '!')
      {
         //printf("\nmy strng length : %d and value of %s\n", strlen(myString), myString);
         for(int j = 0; j<number_count;j++)
         {
            if(myString[strlen(myString)-i] == number_array[j]){
               calibration_number[1] = myString[strlen(myString)-i];
               break;
            }
            if(strcmp(&myString[i], string_number_array[j])){
               
               calibration_number[0] = number_array[i];
               break;
            }
         }
         
      }
      

     
   }

   int temp;
   sscanf(calibration_number, "%d", &temp);
   sum += temp;
   printf("%s\n", calibration_number);
   calibration_number[0] = '!';
   calibration_number[1] = '!';
  }

  printf("%d", sum);



   // Close the file
   fclose(fptr);

   return 0;
}
