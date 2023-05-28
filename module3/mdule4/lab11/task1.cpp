#include <iostream>

using namespace std;

int nod(int n, int m){
    if (n!=0 and m!=0){
        if(n>m){
            n = n%m;
        } else{
            m = m%n;
        }
        return nod(n, m);
    }
    if(n>m){
        return n;
    } else{
        return m;
    }
}

int nod2(int n, int m){
    while (n!=0 and m!=0){
        if(n>m){
            n = n%m;
        } else{
            m = m%n;
        }
    }
    return n+m;
}

int input_int(string phrase){
    int result=-1;
    string cache;
    do{
        cout<<phrase<<endl;
        cin>>result;
        if(cin.fail()){
            cin.clear();
            getline(cin, cache);
            result = -1;
        }
    } while (result<0);
    return result;
}

int main() {
    int n, m;
    n = input_int("Введите первое число ");
    m = input_int("Введите второе число ");
    int res = nod(n,m);
    int res2 = nod(n, m);
    cout<<"Первый результат "<<res<<endl<<"Второй результат "<<res2<<endl;
    return 0;
}
