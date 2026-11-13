
#include <iostream>
#include <cstdint>

char* ToBinary(int num) {
    char* result = new char[33];
    int i = 0;

    if (num == 0) {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    while (num > 0) {
        result[i] = (num & 1) + '0';
        num = num >> 1;
        ++i;
    }

    result[i] = '\0';

    for (int j = 0; j < i / 2; ++j) {
        char temp = result[j];
        result[j] = result[i - 1 - j];
        result[i - 1 - j] = temp;
    }

    return result;
}

char* ToHex(int num) {
    char* result = new char[9];
    char hex[] = "0123456789ABCDEF";
    int i = 0;

    if (num == 0) {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    while (num > 0) {
        result[i] = hex[num & 15];
        num = num >> 4;
        ++i;
    }

    result[i] = '\0';

    for (int j = 0; j < i / 2; ++j) {
        char temp = result[j];
        result[j] = result[i - 1 - j];
        result[i - 1 - j] = temp;
    }

    return result;
}

int BinaryToDecimal(char* str) {
    int result = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != '0' && str[i] != '1') {
            return -1;
        }

        result = result * 2 + (str[i] - '0');
    }

    return result;
}

int HexToDecimal(char* str) {
    int result = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        int digit;

        if (str[i] >= '0' && str[i] <= '9') {
            digit = str[i] - '0';
        }
        else if (str[i] >= 'A' && str[i] <= 'F') {
            digit = str[i] - 'A' + 10;
        }
        else if (str[i] >= 'a' && str[i] <= 'f') {
            digit = str[i] - 'a' + 10;
        }
        else {
            return -1;
        }

        result = result * 16 + digit;
    }

    return result;
}

int main() {
    int num;
    char binary[33];
    char hex[9];

    std::cout << "Enter number: ";
    std::cin >> num;

    char* b = ToBinary(num);
    char* h = ToHex(num);

    std::cout << "Binary: " << b << '\n';
    std::cout << "Hexadecimal: " << h << '\n';

    std::cout << "\nEnter binary number: ";
    std::cin >> binary;

    int decimal1 = BinaryToDecimal(binary);

    if (decimal1 == -1) {
        std::cout << "Incorrect binary number\n";
    }
    else {
        std::cout << "Decimal: " << decimal1 << '\n';
    }

    std::cout << "\nEnter hexadecimal number: ";
    std::cin >> hex;

    int decimal2 = HexToDecimal(hex);

    if (decimal2 == -1) {
        std::cout << "Incorrect hexadecimal number\n";
    }
    else {
        std::cout << "Decimal: " << decimal2 << '\n';
    }

    delete[] b;
    delete[] h;

    return 0;
}


