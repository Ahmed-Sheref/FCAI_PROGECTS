// ahmed sheref sayed : 20230542
// hassan walid hassan: 20230544
// yousef yasser: 20230519


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "string" 
using namespace std;

void Check_and_reserve_flight (vector <int> &capacity , vector <string> &flight_number , int choose , vector <string> &adress_flight)
{
    string fli_num;
    switch (choose)
    {
        case 2:
        cout << "flight_number: ";
        cin >> fli_num;
        for (int i = 0; i < flight_number.size(); i++)
        {
            if (fli_num == flight_number[i])
            {
                capacity[i] -= 1;
                cout << "\n";
                cout  << "DONE!";
                cout << "\n";
                cout << "\n";
            }
        }
        break;
        cout << "---------------\n";
        case 3:
        int sum = 0;
        for (int i = 0; i < flight_number.size(); i++)
        {
            cout << flight_number[i] << "--" << adress_flight[i] << "--" << capacity[i] << endl;
            cout << "--\n";
        }
        break;
    }
}

struct info
{
    string fl_nu;
    string adr_fli;
    int cap;
};


int main ()
{
    
    info inf;
    vector <int> capacity;
    vector <string> flight_number;
    vector <string> adress_flight;
    while (true)
    {
        cout << "flight_number: "; cin >> inf.fl_nu; flight_number.push_back(inf.fl_nu);
        cout << "capacity: "; cin >> inf.cap; capacity.push_back(inf.cap);
        cout << "adress flight: "; cin >> inf.adr_fli; adress_flight.push_back(inf.adr_fli);
        while(true)
        {
            int choose;
            cout << "-------------\n\n";
            cout << "1)add another filght\n2)reserve_flight\n3)Check_availability\n4)EXIT\n=> ";
            cin >> choose;
            cout << "\n";
            if (choose == 1)
            {
                break;
            }
            else if (choose == 2)
            {
                Check_and_reserve_flight(capacity , flight_number , choose , adress_flight);
                continue;
            }
            else if (choose == 3)
            {
                Check_and_reserve_flight(capacity , flight_number , choose , adress_flight);
                continue;
            }
            else if (choose == 4)
            {
                cout << "EXIT programm\n";
                return 0;
            }
            
        }
    }
}