#include <iostream>
#include <vector>

using namespace std;

bool is_decimal_symbol(char);
bool is_negative_symbol(char);
bool is_whitespace_or_eol(char);
vector<string> parse_numbers_from(string);

int main() {
    const string message = "abc@ 127.32 -28 .3";
    const vector<string> numbers = parse_numbers_from(message);

    for (auto number : numbers) {
        cout << number << endl;
    }

    cout << "Done" << endl;
    return 0;
}

vector<string> parse_numbers_from(string message) {
    vector<string> numbers;
    string buffer;
    bool skip_until_whitespace = false, can_read_decimal = true, can_read_negative = true;

    for (int i = 0; i <= message.length(); i++) {
        char chr = message[i];

        if (skip_until_whitespace) {
            if (is_whitespace_or_eol(chr)) {
                skip_until_whitespace = false;
                can_read_decimal = can_read_negative = true;
                buffer = "";
            }
            continue;
        }

        if (isdigit(chr)) {
            buffer += chr;
            can_read_negative = false;
        }
        else if (is_decimal_symbol(chr) && can_read_decimal) {
            if (buffer == "") {
                buffer = "0";
            }
            buffer += chr;
            can_read_decimal = false;
            can_read_negative = false;
        }
        else if (is_negative_symbol(chr) && can_read_negative) {
            buffer = chr;
            can_read_negative = false;
        }
        else if (is_whitespace_or_eol(chr)) {
            if (buffer != "") {
                numbers.push_back(buffer);
                buffer = "";
            }
            can_read_decimal = can_read_negative = true;
        }
        else {
            skip_until_whitespace = true;
            buffer = "";
        }
    }

    return numbers;
}


bool is_decimal_symbol(char chr) {
    return chr == '.';
}

bool is_negative_symbol (char chr) {
    return chr == '-';
}

bool is_whitespace_or_eol(char chr) {
    return chr == ' ' or chr == '\0';
}
