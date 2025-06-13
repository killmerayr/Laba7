#include <iostream>
#include <string>

using namespace std;


class Calculator {
public:
    int calculate(const string& s) {
        int index = 0;
        return parse(s, index);
    }

private:
    int parse(const string& s, int& i) {
        int result = 0;
        int sign = 1;
        int num = 0;

        while (i < s.size()) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            }
            else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            }
            else if (c == '(') {
                ++i;  // пропускаем (
                num = parse(s, i);  
            }
            else if (c == ')') {
                result += sign * num;
                return result;  
            }
            else if (c == ' ') {
                // просто пропускаем
            }

            ++i;
        }

        result += sign * num;
        return result;
    }
};

int main() {
    Calculator calc;

    string expr;
    cout << "Введите выражение: ";
    getline(cin, expr);

    int result = calc.calculate(expr);
    cout << "Результат: " << result << endl;

    return 0;
}
