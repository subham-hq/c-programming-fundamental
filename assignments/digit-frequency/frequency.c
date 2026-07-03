#include <stdio.h>

int frequency(int num, int digit)
{
    int freq = 0;

    // Convert negative number to positive
    if (num < 0)
        num = -num;

    // Special case: if number is 0 and digit is 0
    if (num == 0 && digit == 0)
        return 1;

    // Loop through each digit of the number
    while (num > 0)
    {
        // Check if last digit matches the given digit
        if (num % 10 == digit)
        {
            freq++; // Increment count
        }

        // Remove the last digit
        num /= 10;
    }

    // Return total frequency count
    return freq;
}
