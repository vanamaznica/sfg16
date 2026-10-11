#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Directory
{
public:
    string name, owner, phone, address, activity;

    void add()
    {
        ofstream file("Directory.txt", ios::app);

        cout << "Company: ";
        getline(cin, name);
        cout << "Owner: ";
        getline(cin, owner);
        cout << "Phone: ";
        getline(cin, phone);
        cout << "Address: ";
        getline(cin, address);
        cout << "Activity: ";
        getline(cin, activity);

        file << name << endl;
        file << owner << endl;
        file << phone << endl;
        file << address << endl;
        file << activity << endl;

        file.close();
    }

    void show()
    {
        ifstream file("Directory.txt");

        while (getline(file, name))
        {
            getline(file, owner);
            getline(file, phone);
            getline(file, address);
            getline(file, activity);

            cout << name << endl;
            cout << owner << endl;
            cout << phone << endl;
            cout << address << endl;
            cout << activity << endl;
            cout << endl;
        }

        file.close();
    }

    void search(int n)
    {
        string s, a[5];
        bool found = false;

        cout << "Enter search text: ";
        getline(cin, s);

        ifstream file("Directory.txt");

        while (getline(file, a[0]))
        {
            for (int i = 1; i < 5; i++)
                getline(file, a[i]);

            if (a[n] == s)
            {
                for (int i = 0; i < 5; i++)
                    cout << a[i] << endl;

                cout << endl;
                found = true;
            }
        }

        if (!found)
            cout << "Not found" << endl;

        file.close();
    }
};

int main()
{
    Directory d;
    int n;

    do
    {
        cout << "1 Add\n2 Show\n3 Search company\n4 Search owner\n5 Search phone\n6 Search activity\n0 Exit\n";
        cin >> n;
        cin.ignore();

        if (n == 1)
            d.add();
        if (n == 2)
            d.show();
        if (n == 3)
            d.search(0);
        if (n == 4)
            d.search(1);
        if (n == 5)
            d.search(2);
        if (n == 6)
            d.search(4);

    } while (n != 0);
}
