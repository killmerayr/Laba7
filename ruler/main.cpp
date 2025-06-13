#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Символы для разных уровней делений
char tickChar(int level, int maxLevel) {
    if (level == maxLevel) return '|';      // Самая длинная
    if (level >= maxLevel - 1) return ':';  // Средняя
    return '.';                             // Короткая
}

void drawTicks(vector<char>& ruler, vector<int>& labels, int left, int right, int level, int maxLevel) {
    if (level == 0) return;
    int mid = (left + right) / 2;
    ruler[mid] = tickChar(level, maxLevel);
    if (level >= maxLevel - 1) labels.push_back(mid); 
    drawTicks(ruler, labels, left, mid, level - 1, maxLevel);
    drawTicks(ruler, labels, mid, right, level - 1, maxLevel);
}

int main() {
    int n;
    cout << "Введите степень двойки (количество разбиений): ";
    cin >> n;
    int length = (1 << n) + 1; 
    vector<char> ruler(length, ' ');
    vector<int> labels;

    ruler[0] = '|';
    ruler[length - 1] = '|';
    labels.push_back(0);
    labels.push_back(length - 1);

    drawTicks(ruler, labels, 0, length - 1, n, n);

    for (char c : ruler) cout << c;
    cout << endl;

    int lastPos = 0;
    for (int i = 0; i < length; ++i) {
        bool found = false;
        for (int pos : labels) {
            if (pos == i) {
                cout << setw(0) << i;
                lastPos = i;
                found = true;
                break;
            }
        }
        if (!found) {
            if (i > lastPos) cout << " ";
        }
    }
    cout << endl;

    return 0;
}
