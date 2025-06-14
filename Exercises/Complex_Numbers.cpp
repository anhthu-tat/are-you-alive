#include <iostream>
#include <fstream>
#include <cmath> 
using namespace std;

// Define a structure to represent a complex number
struct Complex {
    double real;
    double imag;    

    // Function to calculate the magnitude of the complex number
    double magnitude() const {
        return sqrt(real * real + imag * imag); //Calculate the magnitude of the complex number
    }
};

int main() {
    // Open the file containing complex numbers
    ifstream inputFile("D:\\C++\\File.txt");

    // Read the total number of complex numbers from the first line of the file
    int totalNum;
    inputFile >> totalNum;

    // Check if the number of complex numbers is less than 0
    if (totalNum <= 0) {
        cerr << "Error: The file contains an invalid number of complex numbers." << endl;
        return 1;
    }

    // Dynamically allocate an array to store the complex numbers
    Complex* complexNumbers = new Complex[totalNum];
    int numbersRead = 0; // Counter to track how many numbers have been read

    // Read each complex number from the file
    double realPart, imagPart;
    while (inputFile >> realPart >> imagPart && numbersRead < totalNum) {
        complexNumbers[numbersRead].real = realPart;
        complexNumbers[numbersRead].imag = imagPart;
        numbersRead++;
    }

    // Close the file after reading
    inputFile.close();

    // Sort the complex numbers in descending order of magnitude using bubble sort
    for (int i = 0; i < numbersRead - 1; ++i) {
        for (int j = 0; j < numbersRead - i - 1; ++j) {
            if (complexNumbers[j].magnitude() < complexNumbers[j + 1].magnitude()) {
                // Swap the complex numbers if they are out of order
                Complex temp = complexNumbers[j];
                complexNumbers[j] = complexNumbers[j + 1];
                complexNumbers[j + 1] = temp;
            }
        }
    }

    // Print the 5 complex numbers with the largest magnitude
    cout << "The 5 complex numbers with the largest magnitude are:" << endl;
    for (int i = 0; i < 5 && i < numbersRead; ++i) {
        cout << complexNumbers[i].real << " + " << complexNumbers[i].imag << "i "
             << "(Magnitude: " << complexNumbers[i].magnitude() << ")" << endl;
    }

    // Free the dynamically allocated memory
    delete[] complexNumbers;

    return 0;
}