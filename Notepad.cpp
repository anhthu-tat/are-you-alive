#include <iostream>
using namespace std;

// The BigInteger class will encapsulate the string representation of a large integer and its sign.
class BigInteger {
private:
    string digits; // Stores the digits of the number (e.g., "345672134579098765")
    bool is_negative;   // True if the number is negative, false otherwise

    // Function to normalize the digit string by removing leading zeros. results might have leading zeros that need removal.
    void normalize() {
        // Find the first non-zero digit
        size_t first_digit_idx = 0;
        while (first_digit_idx < digits.length() - 1 && digits[first_digit_idx] == '0') {
            first_digit_idx++;
        }
        digits = digits.substr(first_digit_idx); // Keep only from the first non-zero digit

        // If the number becomes "0" after normalization, ensure its sign is positive.
        if (digits == "0") {
            is_negative = false;
        }
    }

    // Helper function to compare the absolute values of two BigInteger objects.
    // This is crucial for correctly implementing subtraction and signed addition.
    // Returns: 1 if |this| > |other|, -1 if |this| < |other|, 0 if |this| == |other|.
    int absCompare(const BigInteger& other) const {
        // Compare by length first
        if (digits.length() > other.digits.length()) return 1;
        if (digits.length() < other.digits.length()) return -1;

        // If lengths are equal, compare digit by digit from left to right.
        for (size_t i = 0; i < digits.length(); ++i) {
            if (digits[i] > other.digits[i]) return 1;
            if (digits[i] < other.digits[i]) return -1;
        }
        return 0; // Absolute values are equal
    }

    // Helper function to add two BigInteger objects assuming both are positive.
    // This handles the carry logic as per guideline 3.
    // It also incorporates guideline 5 by conceptually padding shorter numbers with leading zeros.
    BigInteger addAbsolute(const BigInteger& num1_abs, const BigInteger& num2_abs) const {
        string result_str = "";
        int carry = 0;

        // Determine the maximum length for consistent iteration (guideline 5)
        int len1 = num1_abs.digits.length();
        int len2 = num2_abs.digits.length();
        int max_len = (len1 > len2) ? len1 : len2; // Manual max, since <algorithm> is not allowed

        // Pad the shorter string with leading zeros to match the maximum length (guideline 5).
        // This makes digit-by-digit access easier when iterating from right-to-left.
        string s1_padded = num1_abs.digits;
        string s2_padded = num2_abs.digits;

        if (len1 < max_len) {
            for (int i = 0; i < max_len - len1; ++i) {
                s1_padded.insert(0, 1, '0'); // Insert '0' at the front, simulating pushFront [6, 7]
            }
        } else if (len2 < max_len) {
            for (int i = 0; i < max_len - len2; ++i) {
                s2_padded.insert(0, 1, '0'); // Insert '0' at the front, simulating pushFront [6, 7]
            }
        }

        // Iterate from right to left (least significant digit to most significant).
        for (int i = max_len - 1; i >= 0; --i) {
            int digit1 = s1_padded[i] - '0';
            int digit2 = s2_padded[i] - '0';

            int sum = digit1 + digit2 + carry;
            result_str.insert(0, 1, (sum % 10) + '0'); // Insert digit at the front [6, 7]
            carry = sum / 10;
        }

        // If there's a remaining carry, add it to the leftmost position.
        if (carry > 0) {
            result_str.insert(0, 1, carry + '0'); // Insert carry at the front [6, 7]
        }

        BigInteger result_obj;
        result_obj.digits = result_str;
        result_obj.normalize(); // Remove any superfluous leading zeros from the final result (guideline 5)
        return result_obj;
    }

    // Helper function to subtract two BigInteger objects, assuming num1_abs >= num2_abs (absolute value).
    // This handles the borrow logic as per guideline 4.
    // It also incorporates guideline 5 by conceptually padding shorter numbers with leading zeros.
    BigInteger subtractAbsolute(const BigInteger& num1_abs, const BigInteger& num2_abs) const {
        string result_str = "";
        int borrow = 0;

        // Pad num2_abs with leading zeros to match num1_abs length (for columnar subtraction).
        string s1 = num1_abs.digits;
        string s2_padded = num2_abs.digits;

        int len1 = num1_abs.digits.length();
        int len2 = num2_abs.digits.length();

        if (len2 < len1) {
            for (int i = 0; i < len1 - len2; ++i) {
                s2_padded.insert(0, 1, '0'); // Insert '0' at the front, simulating pushFront [6, 7]
            }
        }

        // Iterate from right to left.
        for (int i = len1 - 1; i >= 0; --i) {
            int digit1 = (s1[i] - '0') - borrow; // Apply previous borrow
            int digit2 = (s2_padded[i] - '0');

            if (digit1 < digit2) {
                digit1 += 10; // Perform a "borrow" from the next column (guideline 4)
                borrow = 1;
            } else {
                borrow = 0;
            }
            result_str.insert(0, 1, (digit1 - digit2) + '0'); // Insert digit at the front [6, 7]
        }

        BigInteger result_obj;
        result_obj.digits = result_str;
        result_obj.normalize(); // Remove any superfluous leading zeros from the final result (guideline 5)
        return result_obj;
    }

public:
    // Default constructor [8-13]
    // Initializes the number to "0" and positive.
    BigInteger() : digits("0"), is_negative(false) {}

    // Parameterized constructor to create a BigInteger from a string.
    // Handles initial sign and calls normalize(). [8-14]
    BigInteger(string s) : is_negative(false) {
        if (s.empty()) {
            digits = "0";
            return;
        }
        size_t start_idx = 0;
        if (s == '-') {
            is_negative = true;
            start_idx = 1;
        } else if (s == '+') {
            start_idx = 1;
        }
        digits = s.substr(start_idx); // Extract digits after sign, if any
        normalize(); // Ensure the initial string is clean (e.g., "007" -> "7")
    }

    // Overloaded `<<` operator for printing BigInteger objects (guideline 2).
    // This is implemented as a friend function to directly access private members
    // `is_negative` and `digits` for output [15-23].
    friend ostream& operator<<(ostream& os, const BigInteger& bi) {
        // Only print the negative sign if the number is actually negative and not "0".
        if (bi.is_negative && bi.digits != "0") {
            os << "-";
        }
        os << bi.digits; // Print the digit string
        return os;
    }

    // Overloaded `+` operator for adding two BigInteger objects (guideline 3).
    // This method orchestrates calls to `addAbsolute` or `subtractAbsolute` based on signs.
    // Operator overloading allows custom types to behave like built-in types [3, 8, 9, 24-27].
    BigInteger operator+(const BigInteger& other) const {
        BigInteger result;
        // If both numbers have the same sign (e.g., 5+3 or -5 + -3), add their absolute values.
        if (this->is_negative == other.is_negative) {
            result = addAbsolute(*this, other); // Use the helper for absolute addition
            result.is_negative = this->is_negative; // Result retains the same sign
        }
        // If numbers have different signs (e.g., 5 + (-3) or -5 + 3), perform subtraction of absolute values.
        else {
            int comparison = this->absCompare(other);
            if (comparison == 0) { // If absolute values are equal (e.g., 5 + (-5) = 0)
                result = BigInteger("0"); // Result is zero
            } else if (comparison == 1) { // If |this| > |other| (e.g., 5 + (-3) = 2)
                result = subtractAbsolute(*this, other);
                result.is_negative = this->is_negative; // Result takes the sign of the larger absolute number (`this`)
            } else { // If |this| < |other| (e.g., 3 + (-5) = -2)
                result = subtractAbsolute(other, *this);
                result.is_negative = other.is_negative; // Result takes the sign of the larger absolute number (`other`)
            }
        }
        result.normalize(); // Ensure the final result is properly formatted (guideline 5)
        return result;
    }

    // Overloaded `-` operator for subtracting one BigInteger from another (guideline 4).
    // This method orchestrates calls to `addAbsolute` or `subtractAbsolute` based on signs.
    BigInteger operator-(const BigInteger& other) const {
        BigInteger result;
        // If both numbers have the same sign (e.g., 5 - 3 or -5 - (-3)), perform subtraction of absolute values.
        if (this->is_negative == other.is_negative) {
            int comparison = this->absCompare(other);
            if (comparison == 0) { // If absolute values are equal (e.g., 5 - 5 = 0)
                result = BigInteger("0");
            } else if (comparison == 1) { // If |this| > |other| (e.g., 5 - 3 = 2 or -5 - (-3) = -2)
                result = subtractAbsolute(*this, other);
                result.is_negative = this->is_negative; // Result takes the sign of `this`
            } else { // If |this| < |other| (e.g., 3 - 5 = -2 or -3 - (-5) = 2)
                result = subtractAbsolute(other, *this);
                result.is_negative = !this->is_negative; // Result takes the *opposite* sign of `this` (guideline 4, complement)
            }
        }
        // If numbers have different signs (e.g., 5 - (-3) = 8 or -5 - 3 = -8), perform addition of absolute values.
        else {
            result = addAbsolute(*this, other);
            result.is_negative = this->is_negative; // Result takes the sign of `this`
        }
        result.normalize(); // Ensure the final result is properly formatted (guideline 5)
        return result;
    }
};