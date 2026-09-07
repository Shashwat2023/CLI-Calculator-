#include <iostream>
#include <string>

using namespace std;


struct parser_output
{
    string nums[100];
    char op[100];

    int count;
    int n_count;
};
struct bracket_output
{
    int b_pos[100];
    char brackets[100];
    int b_pos_count;
};


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


parser_output parse(string input)
{
    parser_output output;

    output.count = 0;
    output.n_count = 0;

    size_t start = 0;

    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == '+' ||
            input[i] == '-' ||
            input[i] == '*' ||
            input[i] == '/')
        {
            output.nums[output.n_count] = input.substr(start, i - start);
            output.n_count++;

            output.op[output.count] = input[i];
            output.count++;

            start = i + 1;
        }
    }

    output.nums[output.n_count] = input.substr(start);
    output.n_count++;

    return output;
}


bracket_output find_brackets(string input)
{
    bracket_output output;

    output.b_pos_count = 0;

    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == '{' ||
            input[i] == '[' ||
            input[i] == '(' ||
            input[i] == '}' ||
            input[i] == ']' ||
            input[i] == ')')
        {
            output.brackets[output.b_pos_count] = input[i];
            output.b_pos[output.b_pos_count] = i;

            output.b_pos_count++;
        }
    }

    return output;
}


double bracket_solve(bracket_output bracket_data, parser_output input_data,string* input){
    for (size_t i = 0; i < bracket_data.b_pos_count; i++)
    {
        if (bracket_data.brackets[i]=='}' ||
            bracket_data.brackets[i]==']' ||
            bracket_data.brackets[i]==')'  )
        {
            int start = bracket_data.b_pos[i - 1] + 1;
            int end = bracket_data.b_pos[i];

            string new_bracket = (*input).substr(start, end - start);
            parser_output b_parsed = parse(new_bracket);
            double b_result = solve(b_parsed.nums,b_parsed.op,b_parsed.count,b_parsed.n_count);
            
            // erasing the bracket and replacing it with new data
            int open_pos = bracket_data.b_pos[i-1];
            int close_pos= bracket_data.b_pos[i];

            int length = close_pos-open_pos+1;
            
            (*input).replace(open_pos,length,to_string(b_result));

            bracket_data= find_brackets(*input);
            input_data= parse(*input);  
            if (bracket_data.b_pos_count == 0 ){
                double result = solve(input_data.nums,input_data.op,input_data.count,input_data.n_count);
                return result;
            }
            
        }
        
    } 
    if (bracket_data.b_pos_count == 0 ){
                double result = solve(input_data.nums,input_data.op,input_data.count,input_data.n_count);
                return result;
            }
    return 0;
}


bool bracket_check(bracket_output bracket_data)
{
    for (int i = 0; i < bracket_data.b_pos_count; i += 2)
    {
        
        char open = bracket_data.brackets[i];
        char close = bracket_data.brackets[i + 1];

        if (open == '(' && close == ')')
        {
            continue;
        }
        else if (open == '[' && close == ']')
        {
            continue;
        }
        else if (open == '{' && close == '}')
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string input;
    double result;

    cout << "CLI Calculator says\n";
    cout << "Welcome to the terminal calculator!!\n";

    while (true)
    {
        getline(cin, input);

        parser_output parsed = parse(input);

        bracket_output bracket_data = find_brackets(input);

        if (bracket_data.b_pos_count%2==0)
        {
            bool check = bracket_check(bracket_data);

            if (bracket_check)
            {
                result = bracket_solve(bracket_data , parsed , &input);
                cout << "Result: " << result << "\n";
            }else
            {
                cout << "Entered Wrong Expression Try Again!!!!!"<<"\n";
            }
            
        }else
            {
                cout << "Entered Wrong Expression Try Again!!!!!"<< "\n";
            }        
    }
    return 0;
}