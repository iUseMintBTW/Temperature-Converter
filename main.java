import java.util.Scanner;

class main
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        int option;
        String repeat = "y";

        while (repeat.equalsIgnoreCase("y")) {
            System.out.println("\n\t =========================");
            System.out.println("\n\t| 1) Celsius to Fahrenheit |");
            System.out.println("\n\t| 2) Celsius to Kelvin     |");
            System.out.println("\n\t| 3) Fahrenheit to Celsius |");
            System.out.println("\n\t| 4) Fahrenheit to Kelvin  |");
            System.out.println("\n\t| 5) Kelvin to Celsius     |");
            System.out.println("\n\t| 6) Kelvin to Fahrenheit  |");
            System.out.println("\n\t =========================");

            System.out.print("\n\nYour option: ");
            option = scan.nextInt();

            ConvertEquations(option);

            System.out.print("\n\nDo you want to start over?(Y/n) ");
            repeat = scan.next();
            
            System.out.print("\033[H\033[2J");
            System.out.flush();
        }
    }

    public static void ConvertEquations(int option)
    {
        Scanner scanf = new Scanner(System.in);
        float AbsoluteZero = 273.15f;
        float temperature, result;
        switch(option)
        {
            case 1: // cel to fah
            
                System.out.println("The temperature to convert: ");
                temperature = scanf.nextFloat();
                result = (temperature * 9/5) + 32;

                System.out.println("\n\nResult: " + result + "C = " + temperature + "F\n");  

                break;
            
            case 2: // cel do kel
        
                System.out.println("The temperature to convert: ");
                temperature = scanf.nextFloat();
			    result = temperature + AbsoluteZero;

			    System.out.println("\n\nResult: " + result + "C = " + temperature + "K\n"); 

			    break;
            
            case 3: // fah to cel
        
                System.out.println("The temperature to convert: ");
                temperature = scanf.nextFloat();
                result = (temperature - 32) * 5/9;

                System.out.println("\n\nResult: " + result + "F = " + temperature + "C\n"); 
            
                break;

            case 4: // fah to kel
        
                System.out.println("The temperature to convert: ");
                temperature = scanf.nextFloat();
                result = ((temperature - 32) * (5/9)) + AbsoluteZero;

                System.out.println("\n\nResult: " + result + "F = " + temperature + "K\n"); 
                break;
            
            case 5: // kel to cel
        
                System.out.println("The temperature to convert: ");
                temperature = scanf.nextFloat();

                if(temperature >= 0)
                {
                    result = temperature - AbsoluteZero;
                    System.out.println("\n\nResult: " + result + "K = " + temperature + "C\n"); 
                }
                else
                {
                    System.out.println("Hey, Kelvin cannot be lower than 0, you know?!\n");
                    break;
                }
                break;
            
            case 6: // kel to fah
        
                System.out.println("The temperature to convert: ");
                temperature = scanf.nextFloat();

                if(temperature >= 0)
                {
                    result = ((temperature - AbsoluteZero) * (9/5)) + 32;
                    System.out.println("\n\nResult: " + result + "K = " + temperature + "F\n"); 
                }
                else
                {
                    System.out.println("Hey, Kelvin cannot be lower than 0, you know?!\n");
                }
                break;
        
            default:
                System.out.println("Invalid option");
                break;
        }
    }
}
