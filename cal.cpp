#include <iostream>
#include <string>

using namespace std;



double solve(string nums[], char op[], int count, int n_count)
{
    double result;

    for (int i = 0; i < count; i++)
    {
        if (op[i] == '/')
        {
            if (stod(nums[i + 1]) == 0)
            {
                cout << "Error: Cannot divide by zero\n";
                return 0;
            }

            nums[i] = to_string(stod(nums[i]) / stod(nums[i + 1]));

            for (size_t j = i + 1; j + 1 < n_count; j++)
            {
                nums[j] = nums[j + 1];
            }

            n_count--;

            for (size_t j = i; j + 1 < count; j++)
            {
                op[j] = op[j + 1];
            }

            count--;
            i--;
        }

        else if (op[i] == '*')
        {
            nums[i] = to_string(stod(nums[i]) * stod(nums[i + 1]));

            for (size_t j = i + 1; j + 1 < n_count; j++)
            {
                nums[j] = nums[j + 1];
            }

            n_count--;

            for (size_t j = i; j + 1 < count; j++)
            {
                op[j] = op[j + 1];
            }

            count--;
            i--;
        }
    }

    for (int i = 0; i < count; i++)
    {
        if (op[i] == '+')
        {
            nums[i] = to_string(stod(nums[i]) + stod(nums[i + 1]));

            for (size_t j = i + 1; j + 1 < n_count; j++)
            {
                nums[j] = nums[j + 1];
            }

            n_count--;

            for (size_t j = i; j + 1 < count; j++)
            {
                op[j] = op[j + 1];
            }

            count--;
            i--;
        }

        else if (op[i] == '-')
        {
            nums[i] = to_string(stod(nums[i]) - stod(nums[i + 1]));

            for (size_t j = i + 1; j + 1 < n_count; j++)
            {
                nums[j] = nums[j + 1];
            }

            n_count--;

            for (size_t j = i; j + 1 < count; j++)
            {
                op[j] = op[j + 1];
            }

            count--;
            i--;
        }
    }

    result = stod(nums[0]);

    return result;
}


int main()
{
    // varibles declration
    string input;
    char op[100];
    string nums[100];

    int count = 0;
    int n_count = 0;
    double result;

    int b_pos[100];
    int b_pos_count = 0;
    char brackets[100];

    cout << "CLI Calculator say\n";
    cout << "Welcome to the terminal calculator!!\n";

    while (true)
    {
        getline(cin, input);

        count = 0;
        n_count = 0;
        b_pos_count = 0;

        size_t start = 0;

        for (size_t i = 0; i < input.length(); i++)
        {
            if (input[i] == '+' ||
                input[i] == '-' ||
                input[i] == '*' ||
                input[i] == '/')
            {
                nums[n_count] = input.substr(start, i - start);
                n_count++;

                op[count] = input[i];
                count++;

                start = i + 1;
            }

            else if(input[i] == '{' ||
                    input[i] == '[' ||
                    input[i] == '(' ||
                    input[i] == '}' ||
                    input[i] == ']' ||
                    input[i] == ')')
            {
                brackets[b_pos_count] = input[i];
                b_pos[b_pos_count] = i;
                b_pos_count++;
            }
        }




        

        nums[n_count] = input.substr(start);
        n_count++;

        result = solve(nums, op, count, n_count);

        cout << "Result: " << result << "\n";
    }

    return 0;
}