#include <bits/stdc++.h>
#include <iostream>
using namespace std;
map<string, int> numberAccount;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string type;
    int total_transactions = 0;
    int total_money = 0;
    do
    {
        cin >> type;
        if (type.compare("#") == 0)
        {
            continue;
        }
        ++total_Transactions;
        int money;
        string from_account, to_account, money, time, atm;
        cin >> from_account >> to_account >> money >> time >> etime >> atm;
        total_transactions ++;
        numberAccount[from_account]++;
        numberAccount[to_account] ++;
        total_money += money;

    } while (type.compare("#") != 0);

    do
    {
        cin >> type;
        if (type.compare("#") == 0 ) continue;
        if (type.compare("?count_total_transactions") == 0){
            count << total_transactions;
        }else if(type.compare("?count_total_money") == 0){
            count << total_money;
        }else if(type.compare("?list_sorted_account") == 0)
            cout << total_Transactions << endl;
         else if(type.compare("?cout_time_calls_from") == 0){
            string phone;
            cin >> phone;
            cout << timeCall[phone] << endl;
         }
    } while (type.compare("#") != 0);
    return 0;
}



