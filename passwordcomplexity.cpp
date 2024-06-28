// #include <iostream>
// #include <string>
// #include <regex>
#include<bits/stdc++.h>

using namespace std;

bool containsUppercase(const string& password) {
    return regex_search(password, regex("[A-Z]"));
}

bool containsLowercase(const string& password) {
    return regex_search(password, regex("[a-z]"));
}

bool containsDigit(const string& password) {
    return regex_search(password, regex("[0-9]"));
}

bool containsSpecialChar(const string& password) {
    return regex_search(password, regex("[!@#$%^&*(),.?\":{}|<>]"));
}

string assessPasswordStrength(const string& password) {
    int strengthScore = 0;
    string feedback = "";

    if (password.length() >= 8) {
        strengthScore++;
    } else {
        feedback += "Password should be at least 8 characters long.\n";
    }

    if (containsUppercase(password)) {
        strengthScore++;
    } else {
        feedback += "Password should include at least one uppercase letter.\n";
    }

    if (containsLowercase(password)) {
        strengthScore++;
    } else {
        feedback += "Password should include at least one lowercase letter.\n";
    }

    if (containsDigit(password)) {
        strengthScore++;
    } else {
        feedback += "Password should include at least one number.\n";
    }

    if (containsSpecialChar(password)) {
        strengthScore++;
    } else {
        feedback += "Password should include at least one special character.\n";
    }

    if (strengthScore == 5) {
        feedback += "Your password is strong.\n";
    } else if (strengthScore >= 3) {
        feedback += "Your password is moderate.\n";
    } else {
        feedback += "Your password is weak.\n";
    }

    return feedback;
}

int main() {
    string password;
    cout << "Enter your password: ";
    cin >> password;

    string feedback = assessPasswordStrength(password);

    cout << "\nPassword Feedback:\n" << feedback;

    return 0;
}
