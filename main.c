#include <stdio.h>

float convertTemperature(int option)
{
    float absoluteZero = 273.15;
    float temperature, result;
    switch(option)
    {
        case 1: // cel to fah
        
            printf("\n\nThe temperature to convert: ");
            scanf("%f", &temperature);
            
            result = (temperature * (9/5)) + 32;
            
            printf("\nResult: %2.fC = %2.fF", temperature, result);
            break;
        
        case 2: // cel to kel
        
            printf("The temperature to convert: ");
            scanf("%f", &temperature);
            
            result = temperature + absoluteZero;
            
            printf("\nResult: %2.fC = %2.fK", temperature, result);
            break;
        
        case 3: // fah to cel
        
            printf("The temperature to convert: ");
            scanf("%f", &temperature);
            
            result = (temperature - 32) * 5/9;
            
            printf("\nResult: %2.fF = %2.fC", temperature, result);
            break;
        
        case 4: // fah to kel
        
            printf("The temperature to convert: ");
            scanf("%f", &temperature);
            
            result =  ((temperature - 32) * (5/9)) + absoluteZero;
            
            printf("\nResult: %2.fF = %2.fK", temperature, result);
            break;
        
        case 5: // kel to fah
        
            printf("The temperature to convert: ");
            scanf("%f", &temperature);
            
            if(temperature >= 0)
            {
                
                result = temperature - absoluteZero;
                
                printf("\nResult: %2.fK = %2.fC", temperature, result);
            }
            else
            {
                printf("\nHey, Kelvin cannot be lower than 0, you know?!");
            }break;
        
        case 6: // kel to fah
        
            printf("The temperature to convert: ");
            scanf("%f", &temperature);
            
            if(temperature >= 0)
            {
                
                result =  ((temperature - absoluteZero) * (9/5)) + 32;
                
                printf("\nResult: %2.fK = %2.fF", temperature, result);
            }
            else
            {
                printf("\nHey, Kelvin cannot be lower than 0, you know?!");
            }break;
            
            default:
                printf("\nThat's not a valid option");
                break;
    }
}

int main()
{
    int option;
    char repeat = 'y';

    while (repeat == 'y' || repeat == 'Y')
    {
        printf("\n\t =========================");
        printf("\n\t| 1) Celsius to Fahrenheit |");
        printf("\n\t| 2) Celsius to Kelvin     |");
        printf("\n\t| 3) Fahrenheit to Celsius |");
        printf("\n\t| 4) Fahrenheit to Kelvin  |");
        printf("\n\t| 5) Kelvin to Celsius     |");
        printf("\n\t| 6) Kelvin to Fahrenheit  |");
        printf("\n\t =========================");

        printf("\n\nYour option: ");
        scanf("%d", &option);
        fflush(stdin);
        
        convertTemperature(option);
        
        printf("\n\nDo you want to start over?(Y/n) ");
        scanf(" %c", &repeat);
        system("clear");
    }

    return 0;
}
