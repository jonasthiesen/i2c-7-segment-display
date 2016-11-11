#include <Wire.h>
#define expander1 B0111000
#define expander2 B0111001

void setup() {
    Wire.begin();
    Serial.begin(9600);
}

void loop() {
    for (int i = 0; i < 100; i++) {
        showNumber(i);
        delay(500);
    }
}

void expanderWrite1(byte _data) {
    Wire.beginTransmission(expander1);
    Wire.write(_data);
    Wire.endTransmission();
}

void expanderWrite2(byte _data) {
    Wire.beginTransmission(expander2);
    Wire.write(_data);
    Wire.endTransmission();
}

int firstDigit(int number) {
	return (number - (number % 10)) / 10;
}

int secondDigit(int number) {
	return number % 10;
}

void showNumber(int number) {
    int digit1 = firstDigit(number);
    int digit2 = secondDigit(number);

    switch (digit1) {
    case 0:
        expanderWrite1(B11000000);
        break;

    case 1:
        expanderWrite1(B11111001);
        break;

    case 2:
        expanderWrite1(B10100100);
        break;

    case 3:
        expanderWrite1(B10110000);
        break;

    case 4:
        expanderWrite1(B10011001);
        break;

    case 5:
        expanderWrite1(B10010010);
        break;

    case 6:
        expanderWrite1(B10000010);
        break;

    case 7:
        expanderWrite1(B11111000);
        break;

    case 8:
        expanderWrite1(B10000000);
        break;

    case 9:
        expanderWrite1(B10010000);
        break;

    default:
        expanderWrite1(B00000110);
        break;
    }

    switch (digit2) {
    case 0:
        expanderWrite2(B11000000);
        break;

    case 1:
        expanderWrite2(B11111001);
        break;

    case 2:
        expanderWrite2(B10100100);
        break;

    case 3:
        expanderWrite2(B10110000);
        break;

    case 4:
        expanderWrite2(B10011001);
        break;

    case 5:
        expanderWrite2(B10010010);
        break;

    case 6:
        expanderWrite2(B10000010);
        break;

    case 7:
        expanderWrite2(B11111000);
        break;

    case 8:
        expanderWrite2(B10000000);
        break;

    case 9:
        expanderWrite2(B10010000);
        break;

    default:
        expanderWrite2(B00000110);
        break;
    }
}
