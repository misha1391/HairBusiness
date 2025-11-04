#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> // Нужен для разделения по пробелам 

using namespace std;

// Логика: если на данный день максимальная стоимость(смотря на этот день и будующее), то продать все, иначе ждать

//               Телеграмм лучше!
template<typename T> T max(vector<T> vec) {
    T maximum = vec[0];
    for (const auto& i : vec) {
        maximum = max(maximum, i);
    }
    return maximum;
}

int main()
{
    ifstream fileRead("INPUT.txt");
    string line;
    int amountDays = 0;
    vector<unsigned> costByDay;
    while (getline(fileRead, line)) {
        if (amountDays == 0) amountDays = stoi(line);
        else {
            stringstream ssline(line);
            string subline;
            while (getline(ssline, subline, ' ')) {
                costByDay.push_back(stoi(subline));
            }
        }
    }
    fileRead.close();
    if (!(amountDays > 0 && amountDays <= 100)) {
        cerr << "Вы инвалид, количество дней могут быть в диапозоне 0 < x <= 100" << endl;
        exit(-1);
    }
    if (amountDays != costByDay.size()) {
        cerr << "Вы инвалид, количество дней и стоимостей не совпадают!" << endl;
        exit(-1);
    }

    int hairLength = 1;
    int money = 0;

    for (int i = 0; i < amountDays; i++) {
        if (costByDay[0] == max(costByDay)) {
            money += costByDay[0] * hairLength;
            hairLength = 0;
        }
        costByDay.erase(costByDay.begin());
        hairLength++;
    }

    ofstream fileWrite("OUTPUT.txt");
    fileWrite << money << endl;
    fileWrite.close();
    cout << money << endl;
    system("pause");
}