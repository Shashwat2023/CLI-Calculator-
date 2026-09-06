#include <iostream>
#include <string>

using namespace std;

int main() {
    // varibles declration
    string input;
    char op[100];
    string nums[100];

    int count = 0;
    int n_count = 0;
    double result;

    cout << "ABC say\n";

    while (true) {
        getline(cin, input);
        cout << "Welcome to the terminal calculator!!\n";

        count = 0;
        n_count = 0;

        size_t start = 0; 

        for (size_t i = 0; i < input.length(); i++) {
            if (input[i] == '+' ||
                input[i] == '-' ||
                input[i] == '*' ||
                input[i] == '/') {

                
                nums[n_count] = input.substr(start, i - start);
                n_count++;

                op[count] = input[i];
                count++;

                start = i + 1;
            }
        }

        
        nums[n_count] = input.substr(start);
        n_count++;

        result = stod(nums[0]);

        
        for (int i = 0; i < count; i++) {

            if (op[i] == '+') {
                result = result + stod(nums[i + 1]);

            } else if (op[i] == '-') {
                result = result - stod(nums[i + 1]);

            } else if (op[i] == '*') {
                result = result * stod(nums[i + 1]);

            } else if (op[i] == '/') {
                result = result / stod(nums[i + 1]);
            }
        }

        cout << "Result: " << result << "\n";
    }

    return 0;
}