#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
using namespace std;
struct Time
{
    int hour;
    int mins;
    int secs;
};

map<string, int> listCallTime;
map<string, int> countCallTime;
int totalNumberLog = 0;
int allValid = 1;

// tách chuỗi
vector<string> split(string s, string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

bool isValidPhoneNumber(string phone)
{
    if (phone.length() != 10)
    {
        return false;
    }

    if (phone[0] != '0')
    {
        return false;
    }

    return phone.find_first_not_of("0123456789") == string::npos;
}

int caculatorCallTime(string fromTime, string toTime)
{
    string hour, mins, secs;
    // Xử lý fromTime
    vector<string> time = split(fromTime, ":");
    Time from = {stoi(time[0]), stoi(time[1]), stoi(time[2])};
    // Xử lý toTime
    time = split(toTime, ":");
    Time to = {stoi(time[0]), stoi(time[1]), stoi(time[2])};

    int result = (to.hour - from.hour) * 3600 + (to.mins - from.mins) * 60 + (to.secs - from.secs);
    return result;
}

void checkPhoneNumber()
{
    cout << allValid << endl;
}

void getNumberCallsFrom(string phoneNumber)
{
    if (countCallTime.count(phoneNumber) == 1)
    {
        cout << countCallTime[phoneNumber] << endl;
    }
    else
    {
        cout << "0" << endl;
    }
}

void countTimeCallsFrom(string phoneNumber)
{
    if (listCallTime.count(phoneNumber) == 1)
    {
        cout << listCallTime[phoneNumber] << endl;
    }
    else
    {
        cout << "0" << endl;
    }
}

void numberTotalCalls()
{
    cout << totalNumberLog << endl;
}

int main()
{
    string fromNumber, toNumber, date, fromTime, toTime;
    string call;
    int stop = 0;
    bool isPrint = false;
    while (true)
    {
        string temp = "";
        getline(cin, temp);
        if (temp.size() == 0)
        {
            break;
        }
        stringstream s(temp);

        // Nếu có call ở đầu thì insert log
        if (temp.find("call") != string::npos && temp.find("?") == string::npos)
        {
            s >> call >> fromNumber >> toNumber >> date >> fromTime >> toTime;
            if (!isValidPhoneNumber(fromNumber) || !isValidPhoneNumber(toNumber))
            {
                allValid = 0;
                continue;
            }
            totalNumberLog++;
            // Tính thời gian gọi của từng số
            int callTime = caculatorCallTime(fromTime, toTime);
            listCallTime[fromNumber] += callTime;
            countCallTime[fromNumber]++;
        }

        // Nếu là query
        if (temp.find("?") != string::npos)
        {
            string query;
            string param;
            temp.replace(0, 1, ""); // bỏ dấu ? ở đầu query
            stringstream s(temp);
            s >> query >> param; // Lấy câu lệnh và tham số
            if (isPrint == false && allValid == 0)
            {
                checkPhoneNumber();
                isPrint = true;
            }
            if (query.find("check_phone_number") != string::npos)
            {
                checkPhoneNumber();
            }

            if (query.find("number_calls_from") != string::npos)
            {
                getNumberCallsFrom(param);
            }

            if (query.find("number_total_calls") != string::npos)
            {
                numberTotalCalls();
            }

            if (query.find("count_time_calls_from") != string::npos)
            {
                countTimeCallsFrom(param);
            }
        }

        if (temp.find("#") != string::npos)
        {
            stop++;
            if (stop >= 2)
            {
                break;
            }
        }
    }

    return 0;
}