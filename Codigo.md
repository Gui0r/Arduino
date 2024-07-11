// Configure digital pins for inputs and outputs
void setup() {
    pinMode(0, INPUT);  // Input bit 1 of the first number
    pinMode(1, INPUT);  // Input bit 2 of the first number
    pinMode(2, INPUT);  // Input bit 3 of the first number
    pinMode(3, INPUT);  // Input bit 4 of the first number
    pinMode(4, INPUT);  // Input bit 1 of the second number
    pinMode(5, INPUT);  // Input bit 2 of the second number
    pinMode(6, INPUT);  // Input bit 3 of the second number
    pinMode(7, INPUT);  // Input bit 4 of the second number
    pinMode(8, OUTPUT); // Output bit 1 of the result
    pinMode(9, OUTPUT); // Output bit 2 of the result
    pinMode(10, OUTPUT); // Output bit 3 of the result
    pinMode(11, OUTPUT); // Output bit 4 of the result
    pinMode(12, OUTPUT); // Output carry bit
    pinMode(13, INPUT);  // Input control for the addition operation
}

// Function to sum two bits and a carry bit
int sumBit(int bit1, int bit2, int carryIn) {
    // Logic for a full adder
    return (bit1 ^ bit2) ^ carryIn; // Sum of bits including carry-in
}

// Function to calculate the carry bit
int sumCarryBit(int bit1, int bit2, int carryIn) {
    // Logic for a full adder carry-out
    return (bit1 && bit2) || (bit1 && carryIn) || (bit2 && carryIn); // Carry-out logic
}

void loop() {
    int sumControl = digitalRead(13); // Read the control signal

    int bit1a = digitalRead(0);
    int bit1b = digitalRead(1);
    int bit1c = digitalRead(2);
    int bit1d = digitalRead(3);

    int bit2a = digitalRead(4);
    int bit2b = digitalRead(5);
    int bit2c = digitalRead(6);
    int bit2d = digitalRead(7);

    int result1a, result1b, result1c, result1d, carryOut;

    if (sumControl == 1) { // If the control signal is active
        int carryIn = 0; // Initialize carry bit


        result1a = sumBit(bit1a, bit2a, carryIn);
        carryIn = sumCarryBit(bit1a, bit2a, carryIn);
        result1b = sumBit(bit1b, bit2b, carryIn);
        carryIn = sumCarryBit(bit1b, bit2b, carryIn);
        result1c = sumBit(bit1c, bit2c, carryIn);
        carryIn = sumCarryBit(bit1c, bit2c, carryIn);
        result1d = sumBit(bit1d, bit2d, carryIn);
        carryOut = sumCarryBit(bit1d, bit2d, carryIn);
    }

    // Output the result bits and carry bit
    digitalWrite(8, result1a);
    digitalWrite(9, result1b);
    digitalWrite(10, result1c);
    digitalWrite(11, result1d);
    digitalWrite(12, carryOut);
}
