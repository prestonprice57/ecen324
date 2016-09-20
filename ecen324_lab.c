/***********************************************************************
* Program:
*    Lab C_lab, ECEN 324 Learning C Lab
*    Brother Jones, ECEN 324
* Author:
*    Preston Price
* Summary:
*    C++ program converted into C
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

/***********************************************************************
* Playing around with C
***********************************************************************/
int main (void)
{
   // Printing various items
 
   const char LETTER = 'A';
   printf("%d\n", 24);
   printf("%g\n", PI);
   printf("%c\n", LETTER);
 
   float payRate = 10.50;
   int hours = 40;
 
 	printf("Users pay rate: $%g\n", payRate);
 	printf(" Hours worked: %d\n", hours);
 	printf("    Gross Pay: $%g\n", hours*payRate);
 
   int number;
   fprintf(stderr, "Enter number: ");
   scanf("%d", &number);
   printf("Twice %d is %d\n", number, number*2);
 
   /*********************************************************************/
   /*********************** Output an Integer ***************************/
   /*********************************************************************/
   int anInt = 99;
   float aFloat = 43.2;
 
   // Output the integer with the default formatting.
   //
   printf("\n");
   printf("Integer: %d ###\n", anInt);
 
   // Output the integer in a fixed field width of 10.
   // The object will be right justified in the field.
   //
   printf("Integer: %10d ###\n", anInt);
 
   // Output the integer in a fixed field width of 10
   // and left justified in the field.
   //
   printf("Integer: %-10d ###\n\n", anInt);
 
   
   /*********************************************************************/
   /************************* Output a Float ****************************/
   /*********************************************************************/
 
   // Output the float with the default formatting.
   //
   printf("  Float: %g ###\n", aFloat);
 
   // Output the float in a fixed field width of 10.
   // The float object is left justified in the field because the negative number
   //
   printf("  Float: %-10g ###\n", aFloat);
 
   // Output the float right justified in a field width of 10 with  
   // a precision of 2 places after the decimal point for the float. 
   //
   printf("  Float: %10.2f ###\n", aFloat);
 
   // Output the float with 3 places of precision after the decimal point but
   // not giving a field width.
   //
   printf("  Float: %.3f ###\n", aFloat);
 
   // Output the float with 3 places of precision after the decimal point with
   // a field width of 10.  
   //
   printf("  Float: %10.3f ###\n", aFloat);
  
   // Output the float with 4 places of precision after the decimal point with 
   // a field width of 10 and left justify the number.
   //
   printf("  Float: %-10.4f ###\n\n", aFloat);
 
   /*********************************************************************
    *************** Create some code to output a table ******************
    *********************************************************************
 
    * The following table has a leading tab.
 
        Oct   Dec   Hex   Char
        ----------------------
        141   97    61    a
        142   98    62    b
        143   99    63    c
        144   100   64    d
        145   101   65    e
        146   102   66    f
        147   103   67    g
        150   104   68    h
        151   105   69    i
        152   106   6a    j
        153   107   6b    k
        154   108   6c    l
        155   109   6d    m
        156   110   6e    n
        157   111   6f    o
        160   112   70    p
        161   113   71    q
        162   114   72    r
        163   115   73    s
        164   116   74    t
        165   117   75    u
        166   118   76    v
        167   119   77    w
        170   120   78    x
        171   121   79    y
        172   122   7a    z
 
    *********************************************************************/
 
   printf("\tOct   Dec   Hex   Char\n");
   printf("\t----------------------\n");
   char ch = 'a';
   for (int i=0;i<26;i+=1) {
   	printf("\t%-5o %-5d %-5x %-5c\n", ch,ch,ch,ch);
   	ch+=1;
   }
   printf("\n");

   /*********************************************************************
    *************** Now play with pointers to finish up *****************
    *********************************************************************/
 
   int *p1;
   int *p2;
 
   p1 = malloc(sizeof(int));

   if (p1==0) {
   	printf("No memory!\n");
   	return 1;
   }

   *p1 = 42;
   p2 = p1;
   printf("*p1 == %d\n", *p1);
   printf("*p2 == %d\n", *p2);
 
   *p2 = 53;
   printf("*p1 == %d\n", *p1);
   printf("*p2 == %d\n", *p2);
 
   p1 = malloc(sizeof(int));

   if (p1==0) {
   	printf("No memory!\n");
   	return 1;
   }

   *p1 = 88;
   printf("*p1 == %d\n", *p1);
   printf("*p2 == %d\n", *p2);
 
 	printf("Hope you got the point of this example!\n");
 
   free(p1);
   free(p2);

   return 0;
}

