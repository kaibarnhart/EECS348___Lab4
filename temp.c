#include <stdio.h>

float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
void categorize_temperature(float celsius);
int is_valid_input(float temperature, char scale);

int main() {
    float temperature, converted_temperature;
    int input_scale, output_scale;

    while (1) {
        printf("Enter the temperature value: ");
        if (scanf("%f", &temperature) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            return 1; // Exit on invalid input
        }

        printf("Choose the input temperature scale (1 - Celsius, 2 - Fahrenheit, 3 - Kelvin): ");
        if (scanf("%d", &input_scale) != 1 || (input_scale < 1 || input_scale > 3)) {
            printf("Invalid input scale. Please choose 1, 2, or 3.\n");
            return 1;
        }

        if (!is_valid_input(temperature, input_scale)) {
            printf("Invalid temperature value for the chosen scale.\n");
            return 1;
        }

        printf("Choose the target temperature scale (1 - Celsius, 2 - Fahrenheit, 3 - Kelvin): ");
        if (scanf("%d", &output_scale) != 1 || (output_scale < 1 || output_scale > 3)) {
            printf("Invalid target scale. Please choose 1, 2, or 3.\n");
            return 1;
        }

        if (input_scale == output_scale) {
            printf("Input scale and target scale cannot be the same.\n");
            return 1;
        }

        if (input_scale == 1 && output_scale == 2) { // C to F
            converted_temperature = celsius_to_fahrenheit(temperature);
        } else if (input_scale == 1 && output_scale == 3) { // C to K
            converted_temperature = celsius_to_kelvin(temperature);
        } else if (input_scale == 2 && output_scale == 1) { // F to C
            converted_temperature = fahrenheit_to_celsius(temperature);
        } else if (input_scale == 2 && output_scale == 3) { // F to K
            converted_temperature = fahrenheit_to_kelvin(temperature);
        } else if (input_scale == 3 && output_scale == 1) { // K TO C
            converted_temperature = kelvin_to_celsius(temperature);
        } else if (input_scale == 3 && output_scale == 2) { // K TO F
            converted_temperature = kelvin_to_fahrenheit(temperature);
        }

        printf("Converted temperature: %.2f\n", converted_temperature);

        float celsius_temp;
        if (output_scale == 1) {
            celsius_temp = converted_temperature;
        } else if (output_scale == 2) {
            celsius_temp = fahrenheit_to_celsius(converted_temperature);
        } else {
            celsius_temp = kelvin_to_celsius(converted_temperature);
        }

        categorize_temperature(celsius_temp);
        break;
    }

    return 0;
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Category: Freezing\nAdvisory: Layer up!\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Category: Cold\nAdvisory: Wear a jacket!\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Category: Comfortable\nAdvisory: You should feel comfortable\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Category: Hot\nAdvisory: Stay hydrated!\n");
    } else {
        printf("Category: Extreme Heat\nAdvisory: Stay indoors.\n");
    }
}

int is_valid_input(float temperature, char scale) {
    if (scale == 3 && temperature < 0) {
        return 0;
    }
    return 1;
}
