#include <iostream>
#include <limits> // for std::numeric_limits and etc
#include <array>

void displayMenu()
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
}

void displayResult(float temperature, const std::array<char, 2>& units, float result)
{
    std::cout << "\n\nResult: " << temperature << units[0] << " = " << result << units[1] << "\n";  
}

bool optionValid(int& option)
{
    std::cin >> option;
    if (std::cin.fail()) { // if the reading failed
        std::cin.clear(); // clears the state of error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discards the invalid option
        return false;
    }
    
    // verify if there are characters like 12.3 or 12abc
    char next = std::cin.peek();
    if (next != '\n' && next != EOF) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    
    return true;
}

void err()
{
    std::cout << "\n\tInvalid option! o.O";
}

void clearScreen()
{
    // ANSI sequence for Windows and Unix-like systems
    std::cout << "\033[2J\033[1;1H";
}

void pause()
{
    std::cout << "\nPress Enter to PROCEED...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

bool validTemperature(float& temperature)
{
    std::cout << "The temperature to convert: ";
    std::cin >> temperature;
    if (std::cin.fail()) { // if the reading failed
        std::cin.clear(); // clears the state of error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discards the invalid option
        return false;
    }
    
    // verify if there are characters like 12.3 or 12abc
    char next = std::cin.peek();
    if (next != '\n' && next != EOF) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    
    return true;
}

void convertTemperature(int option, float temperature)
{
    const float ABSOLUTE_ZERO = 273.15;
    float result;
    std::array<char, 2> units;
    
    switch(option)
    {
        case 1: // cel to fah
            units = {'C', 'F'};
            result = (temperature * 9.0f/5.0f) + 32;
            displayResult(temperature, units, result);
            break;
            
        case 2: // cel to kel
            units = {'C', 'K'};
            result = temperature + ABSOLUTE_ZERO;
            displayResult(temperature, units, result);
            break;
            
        case 3: // fah to cel
            units = {'F', 'C'};
            result = (temperature - 32) * 5.0f/9.0f;
            displayResult(temperature, units, result); 
            break;
    
        case 4: // fah to kel
            units = {'F', 'K'};
            result = ((temperature - 32) * (5.0f/9.0f)) + ABSOLUTE_ZERO;
            displayResult(temperature, units, result);
            break;
            
        case 5: // kel to cel
            if(temperature >= 0)
            {
                units = {'K', 'C'};
                result = temperature - ABSOLUTE_ZERO;
                displayResult(temperature, units, result);
            }
            else
            {
                std::cout << "Hey, Kelvin cannot be lower than 0, you know?!\n";
            }
            break;
            
        case 6: // kel to fah
            if(temperature >= 0)
            {
                units = {'K', 'F'};
                result = ((temperature - ABSOLUTE_ZERO) * (9.0f/5.0f)) + 32;
                displayResult(temperature, units, result);
            }
            else
            {
                std::cout << "Hey, Kelvin cannot be lower than 0, you know?!\n";
            }
            break;
        
        default:
            err();
            break;
    }
}

int main(void)
{
    int option; 
    float temperature;
    char repeat = 'y';
    
    while (repeat == 'y' || repeat == 'Y')
    {
        displayMenu();
        
        if (optionValid(option))
        {
            if (validTemperature(temperature))
            {
                convertTemperature(option, temperature);
            }
            else
            {
                option = 7; convertTemperature(option, temperature);
                //it will display "Invalid option! o.O".
            }
        }
        else
        {
            err();
        }
        
        std::cout << "\n\nDo you want to start over?(Y/n) ";
        std::cin >> repeat;
        if (repeat != 'y' && repeat != 'Y' && repeat != 'n' && repeat != 'N')
        {
            err();
            pause();
            repeat = 'y';
        }
        clearScreen();
    }
    
    return 0;
}
