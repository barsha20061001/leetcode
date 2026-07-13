class Solution {
public:
    int flipLights(int n, int presses) {
        if (presses == 0)
        // If no buttons are pressed,
         // the bulbs never change.
        // Initially every bulb is ON.
            return 1;

        if (n == 1)
            return 2;
            // Suppose there is only one bulb. Initially 1 Possible states are ON OFF
        // No matter how many presses, only 2 different states exist.

        if (n == 2) {
            if (presses == 1)
                return 3;
            return 4;
        }

        if (presses == 1)
            return 4;

        if (presses == 2)
            return 7;

        return 8;
    }
};