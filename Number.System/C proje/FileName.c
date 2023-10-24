#include <stdio.h>//
#include <math.h>
#include <stdlib.h>
#include <time.h>
int Octal_to_binary(int octal_sayi) {
    int i = 0;
    int binary = 0;
    int temp[1000];

    while (octal_sayi != 0) {
        temp[i] = octal_sayi % 10;
        octal_sayi /= 10;
        i++;
    }

    i--;

    int place = 1;
    while (i >= 0) {
        int octal_basamak = temp[i];
        int binary_basamak = 0;
        int base = 1;

        while (octal_basamak > 0) {
            binary_basamak += (octal_basamak % 2) * base;
            octal_basamak /= 2;
            base *= 10;
        }

        binary += binary_basamak * place;
        place *= 1000;

        i--;
    }

    return binary;
}
int Binary_to_Octal(long long int binary) {
    int octal = 0, decimal = 0, base = 1;

    while (binary > 0) {
        int last_basamak = binary % 10;
        decimal += last_basamak * base;
        binary /= 10;
        base *= 2;
    }

    base = 1;
    while (decimal > 0) {
        int last_basamak = decimal % 8;
        octal += last_basamak * base;
        decimal /= 8;
        base *= 10;
    }

    return octal;
}
int Binary_to_decimal(long long int girilen_sayi) {
    int son_basamak, tutma_sayi, decimal, toplama = 0;
    int n = 0;


    tutma_sayi = girilen_sayi;

    while (tutma_sayi != 0) {

        son_basamak = tutma_sayi % 10;
        tutma_sayi -= son_basamak;
        tutma_sayi /= 10;
        toplama += son_basamak * (int)pow(2, n);
        n++;
    }
    decimal = toplama;
    return decimal;


}
int* Decimal_to_binary(int n) {
    static int binary[32];
    int index = 0;

    if (n == 0) {
        printf("Binary: 0\n");
        return binary;
    }

    while (n > 0) {
        binary[index] = n % 2;
        n /= 2;
        index++;
    }

    
    
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
    for (int i = 0; i < 32; i++) {
        binary[i] = 0;
    }

    return binary;
}
char* Octal_to_Hexadecimal(int octal) {
   
    int decimal = 0;
    int base = 1;
    while (octal > 0) {
        int last_digit = octal % 10;
        decimal += last_digit * base;
        octal /= 10;
        base *= 8;
    }

   
    char hexadecimal[32];
    int index = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[index] = remainder + '0';
        }
        else {
            hexadecimal[index] = remainder - 10 + 'A';
        }
        decimal /= 16;
        index++;
    }
    hexadecimal[index] = '\0';

 
    int start = 0;
    int end = index - 1;
    while (start < end) {
        char temp = hexadecimal[start];
        hexadecimal[start] = hexadecimal[end];
        hexadecimal[end] = temp;
        start++;
        end--;
    }

    return hexadecimal;
}
int Hexadecimal_to_Decimal(const char* hexadecimal) {
    int decimal = 0;
    int base = 1;
    int hex_length = strlen(hexadecimal);

    for (int i = hex_length - 1; i >= 0; i--) {
        int digit;
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            digit = hexadecimal[i] - '0';
        }
        else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            digit = hexadecimal[i] - 'A' + 10;
        }
        else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f') {
            digit = hexadecimal[i] - 'a' + 10;
        }
        else {
           
            printf("ERROR %c\n", hexadecimal[i]);
            return -1;
        }

        decimal += digit * base;
        base *= 16;
    }

    return decimal;
}
char* Binary_to_Hexadecimal(long long int binary) {
    char hexadecimal[32];
    int index = 0;
    char hex_digits[] = "0123456789ABCDEF";

    char temp_binary[64];
    int temp_index = 0;

  
    while (binary > 0) {
        temp_binary[temp_index] = (char)((binary % 10) + '0');
        binary /= 10;
        temp_index++;
    }

    int bits = 0;
    int value = 0;
    for (int i = temp_index - 1; i >= 0; i--) {
        value += (temp_binary[i] - '0') << bits;
        bits++;
        if (bits == 4 || i == 0) {
            hexadecimal[index] = hex_digits[value];
            index++;
            bits = 0;
            value = 0;
        }
    }

   
    hexadecimal[index] = '\0';
    int start = 0;
    int end = index - 1;
    while (start < end) {
        char temp = hexadecimal[start];
        hexadecimal[start] = hexadecimal[end];
        hexadecimal[end] = temp;
        start++;
        end--;
    }

    return strdup(hexadecimal);
}
long long int Hexadecimal_to_Binary(const char* hexadecimal) {
    long long int binary = 0;
    long long int base = 1;
    int hex_length = strlen(hexadecimal);

   
    for (int i = hex_length - 1; i >= 0; i--) {
        int digit; 

       
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            digit = hexadecimal[i] - '0';
        }
        else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            digit = hexadecimal[i] - 'A' + 10;
        }
        else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f') {
            digit = hexadecimal[i] - 'a' + 10;
        }
        else {
            
            printf("ERROR: %c\n", hexadecimal[i]);
            return -1;
        }

       
        for (int j = 3; j >= 0; j--) {
            binary += ((digit >> j) & 1) * base;
            base *= 10;
        }
    }

    return binary;
}



int main() {
    long long int girilen_sayi;
    int giris_sayi;
    while (1) {
        printf_s("Hello, welcome to the Number Conversions Calculator, what operation did you want to do? \n \n \n \n");
        printf_s("1)Binary to Octal | 2) Binary to Decimal | 3) Binary to Hexadecimal \n \n \n4) Octal to Binary | 5) Octal to Decimal | 6) Octal to Hexadeximal \n \n \n7) Dceimal to Binary | 8) Decimal to Octal | 9) Decimal to Hexadecimal \n \n \n10) Hexidecimal to Binary | 11) Hexidecimal to Octal | 12) Hexidecimal to Decimal \n\n\n ");
        printf_s("                                           FOR EXIT -1\n\n\n\n");

        printf("------------------------------------------->  ");
        scanf_s("%d", &giris_sayi);

        if (giris_sayi == -1) {
            system("cls");
            printf("                                                            SEE YA SOON");
            Sleep(2000);
            system("cls");
            break;
        }

        if (giris_sayi == 4) {
            system("cls");
            printf_s("You Chose Octal to binary \n (X)8=(Y)2\nX= ");
            scanf_s("%lld", &girilen_sayi);
            system("cls");
            int binaryResult = Octal_to_binary(girilen_sayi);
            printf("Y=  % d\n", binaryResult);

        }

        if (giris_sayi == 1) {
            system("cls");
            printf_s("You Chose Binary to octal \n (X)2=(Y)8\nX= ");
            scanf_s("%lld", &girilen_sayi);
            system("cls");
            int binary_octal = Binary_to_Octal(girilen_sayi);
            printf("Y= %d\n", binary_octal);
        }

        if (giris_sayi == 2) {
            system("cls");
            printf_s("You Chose Binary to Decimal \n (X)2=(Y)10\nX= ");
            scanf_s("%lld", &girilen_sayi);
            system("cls");
            int binary_decimal = Binary_to_decimal(girilen_sayi);
            printf("Y = %d\n", binary_decimal);

        }

        if (giris_sayi == 3) {
            system("cls");
            printf("You Chose Binary to Hexadecimal \n (X)2 = (Y)16\nX (Binary): ");
            scanf_s("%lld", &girilen_sayi);

            char* hexadecimal_result = Binary_to_Hexadecimal(girilen_sayi);

            printf("\nY = %s\n", hexadecimal_result);
            free(hexadecimal_result); // * Bellek sýzýntýsýný önlemek için dinamik olarak ayrýlan belleði serbest býrakýldý *
        }

        if (giris_sayi == 7) {
            system("cls");
            printf_s("You Chose Decimal to Binary \n (X)10=(Y)2\nX= ");
            scanf_s("%lld", &girilen_sayi);
            system("cls");
            int decimal_binary = Decimal_to_binary(girilen_sayi);
            printf("Y = %d\n", decimal_binary);

        }

        if (giris_sayi == 6) {
            system("cls");
            printf_s("You Chose Octal to Hexadecimal \n (X)8=(Y)16\nX= ");
            scanf_s("%lld", &girilen_sayi);
            system("cls");
            char* hexadecimal_result = Octal_to_Hexadecimal(girilen_sayi);
            printf("Y = %s\n", hexadecimal_result);
        }

        if (giris_sayi == 12) {
            system("cls");
            char hexadecimal_input[32];
            printf("You Chose Hexadecimal to Decimal \n (X)16 = (Y)10\nX (Hexadecimal): ");
            scanf_s("%s", hexadecimal_input);

            int decimal_result = Hexadecimal_to_Decimal(hexadecimal_input);

            if (decimal_result != -1) {
                printf("\nY = %d\n", decimal_result);
            }
        }

        if (giris_sayi == 10) {
            system("cls");
            char hexadecimal_input[32];
            printf("You Chose Hexadecimal to Binary \n (X)16 = (Y)2\nX (Hexadecimal): ");
            scanf_s("%s", hexadecimal_input);

            long long int binary_result = Hexadecimal_to_Binary(hexadecimal_input);

            if (binary_result != -1) {
                printf("\nY = %lld", binary_result);
            }
        }

        if (giris_sayi == 8 || giris_sayi == 5 || giris_sayi == 9 || giris_sayi == 11) {
            system("cls");
            printf("\n                       I'M SORRY RIGHT NOW YOU CANNOT CALCULATE THEM. I HOPE IT WILL BE AVAILABLE IN V2.0\n");
           
        }

        

        printf("\n                                            program will be start in 2 seconds....");
        for (int i = 2; i > 0; i--) {
            printf("\n                                                               %d", i);
            Sleep(2000);

        }
        system("cls");









    }
    return 0;

}