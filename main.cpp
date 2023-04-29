#include <iostream>

float convertTemperature(int option)
{
    const float ABSOLUTE_ZERO = 273.15;
    float temperature, result;
    switch(option)
    {
        case 1: // cel to fah
            
            std::cout << "The temperature to convert: ";
            std::cin >> temperature;
            result = (temperature * 9/5) + 32;

            std::cout << "\n\nResult: " << result << "C = " << temperature << "F\n";  

            break;
            
        case 2: // cel do kel
        
            std::cout << "The temperature to convert: ";
            std::cin >> temperature;
			result = temperature + ABSOLUTE_ZERO;

			std::cout << "\n\nResult: " << result << "C = " << temperature << "K\n"; 

			break;
            
        case 3: // fah to cel
        
            std::cout << "The temperature to convert: ";
            std::cin >> temperature;
            result = (temperature - 32) * 5/9;

            std::cout << "\n\nResult: " << result << "F = " << temperature << "C\n"; 
            
            break;

        case 4: // fah to kel
        
            std::cout << "The temperature to convert: ";
            std::cin >> temperature;
            result = ((temperature - 32) * (5/9)) + ABSOLUTE_ZERO;

            std::cout << "\n\nResult: " << result << "F = " << temperature << "K\n"; 
            break;
            
        case 5: // kel to cel
        
            std::cout << "The temperature to convert: ";
            std::cin >> temperature;

            if(temperature >= 0)
            {
                result = temperature - ABSOLUTE_ZERO;
                std::cout << "\n\nResult: " << result << "K = " << temperature << "C\n"; 
            }
            else
            {
                std::cout << "Hey, Kelvin cannot be lower than 0, you know?!\n";
                break;
            }
            break;
            
        case 6: // kel to fah
        
            std::cout << "The temperature to convert: ";
            std::cin >> temperature;

            if(temperature >= 0)
            {
                result = ((temperature - ABSOLUTE_ZERO) * (9/5)) + 32;
                std::cout << "\n\nResult: " << result << "K = " << temperature << "F\n"; 
            }
            else
            {
                std::cout << "Hey, Kelvin cannot be lower than 0, you know?!\n";
            }
            break;
        
        default:
            std::cout << "Invalid option";
            break;
    }
    return 0;
}

int main(void)
{
    int option;
    char repeat = 'y';

    while (repeat == 'y' || repeat == 'Y')
    {
        std::cout << "\n\t =========================";
        std::cout << "\n\t| 1) Celsius to Fahrenheit |";
        std::cout << "\n\t| 2) Celsius to Kelvin     |";
        std::cout << "\n\t| 3) Fahrenheit to Celsius |";
        std::cout << "\n\t| 4) Fahrenheit to Kelvin  |";
        std::cout << "\n\t| 5) Kelvin to Celsius     |";
        std::cout << "\n\t| 6) Kelvin to Fahrenheit  |";
        std::cout << "\n\t =========================";

        std::cout << "\n\nYour option: ";
        std::cin >> option;
        
        convertTemperature(option);
        
        std::cout << "\n\nDo you want to start over?(Y/n) ";
        std::cin >> repeat;
        system("clear");
    }
}
