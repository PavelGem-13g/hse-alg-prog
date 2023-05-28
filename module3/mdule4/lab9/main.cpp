#include <iostream>

#define lmax 1000

using namespace std;

int substr(string strings[], int length, string substrings[], int numbers[]){
    int k = 0;
    for (int i = 0; i < length; ++i) {
        int j = 0;
        while(j<strings[i].length()){
            if(strings[i][j]=='['){
                int start = j;
                while (j<strings[i].length() && strings[i][j]!=']')++j;
                if(j<strings[i].length() && j-start-1>0 && strings[i][j]==']'){
                    substrings[k].assign(strings[i], start+1, j-start-1);
                    numbers[k] = i;
                    ++k;
                }
            }
            ++j;
        }
    }
    return k;
}

int get_min_code(string substrings[], int numbers[], int length_sub){
    int repeat=-1;
    for (int i = 0; i < length_sub; ++i) {
        for (int j = 0; j < substrings[i].length(); ++j) {
            for (int k = 0; k < substrings[i].length(); ++k) {
                if(substrings[i][j]==substrings[i][k]){
                    repeat = i;
                }
            }
        }
    }

    return repeat;
}

int clear_string(string &str){
    int flag = 0;
    for (int i = 0; i < str.length()-1; ++i) {
        if((str[i]=='/' && str[i+1]=='*') ||
        (str[i]=='*' && str[i+1]=='/')){
            str.erase(i, 2);
            flag = 1;
        }
    }
    return flag;
}

int main() {
    cout<<('a'>'A');
    cout<<"Лабораторная работа №9\nВыполнил: Пашенцев Павел Владимирович"<<endl;
    int length = 0, length_sub = 0;
    string s = "";
    do {
        cout<<"Введите количество линий"<<endl;
        cin >> length;
        if (cin.fail())cin.clear();
        getline(cin, s);
    } while (length <= 0);
    string strings[lmax];
    cin.clear();

    for (int i = 0; i < length; ++i) {
        getline(cin, strings[i]);
    }
    cout<<"Входной массив:"<<endl;
    for (int i = 0; i < length; ++i) {
        cout<<strings[i]<<endl;
    }

    string substrings[lmax];
    int numbers[lmax];

    length_sub = substr(strings, length, substrings, numbers);
    if(length_sub){
        cout<<"Массив подстрок:"<<endl;
        for (int i = 0; i < length_sub; ++i) {
            cout<<substrings[i]<<endl;
        }

        int min_substring = get_min_code(substrings, numbers, length_sub);
        if(min_substring==-1){
            cout<<"Нет подстрок с повторениями"<<endl;
        } else{
            cout<<"Номер подстроки с минимальным кодом: "<<min_substring+1<<endl;

            int min_string = numbers[min_substring];
            if(clear_string(strings[min_string])){
                cout<<"Строка после изменения: "<<strings[min_string]<<endl;
            } else{
                cout<<"Строка не изменилась"<<endl;
            }
        }
    } else{
        cout<<"Нет подстрок";
    }
    return 0;
}
