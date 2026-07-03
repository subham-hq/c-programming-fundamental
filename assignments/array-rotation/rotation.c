#include <stdio.h>
#include <stdbool.h>

bool is_rotationally_same(int num)
{
    int original = num; // Store original number
    int rotated = 0;    // Will store rotated number
    int temp = num;     // Temporary variable for processing

    // Special case: 0 remains 0 after rotation
    if (num == 0)
        return true;

    // Process each digit
    while (temp > 0)
    {
        int digit = temp % 10;

        // Map digits based on 180° rotation
        if (digit == 0)
            rotated = rotated * 10 + 0;
        else if (digit == 1)
            rotated = rotated * 10 + 1;
        else if (digit == 8)
            rotated = rotated * 10 + 8;
        else if (digit == 6)
            rotated = rotated * 10 + 9;
        else if (digit == 9)
            rotated = rotated * 10 + 6;
        else
        {
            // Invalid digit for rotation
            return false;
        }

        // Remove last digit
        temp /= 10;
    }

    // Check if rotated number matches original
    return (rotated == original);
}