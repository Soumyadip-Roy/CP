#include <bits/stdc++.h>
using namespace std;

class Student
{
    string name;
    int roll, marks;

public:
    void setData(string n, int r, int m)
    {
        name = n;
        roll = r;
        marks = m;
    }

    void display()
    {
        cout << name << " " << roll << " " << marks << endl;
    }

    vector<int> linearSearch(Student s[], int key, int n)
    {   
        vector<int>v;
        for (int i = 0; i < n; i++)
        {
            if (s[i].marks == key)
                v.push_back(i);
        }
        return v;
    }

    int binarySearch(Student s[], string p, int n)
    {
        s[0].bubbleSort(s,n);
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (s[mid].name == p)
            {
                cout << "Name : " << s[mid].name << "\nRoll :" << s[mid].roll << "\nSGPA : " << s[mid].marks << "\n";
                return mid;
            }
            else if (p > s[mid].name)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    void bubbleSort(Student s[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (s[j].name > s[j + 1].name)
                {
                    swap(s[j], s[j + 1]);
                }
            }
        }
    }
    
    void insertionSort(Student s[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            int j = i - 1;
            int key = s[i].marks;

            while (j >= 0 and key < s[j].marks)
            {
                swap(s[j + 1], s[j]);
                j--;
            }
        }
    }
};

int main()
{

    cout << "Enter no. of records : ";
    int n;
    cin >> n;
    Student s[n];
    Student search;

    int cont;
    do
    {
        cout << "1 - Enter Data \n2 - Display Data \n3 - LInear Search \n4 - Binary Search \n5 - Bubble Sort \n6 - Insertion Sort\n";

        int x;
        cout << "Enter your choice : ";
        cin >> x;

        if (x == 1)
        { // Taking user Input
            string name;
            int roll, marks;
            for (int i = 0; i < n; i++)
            {
                cout<<"Enter name :";cin >> name;
                cout<<"Enter roll :";cin >> roll;
                cout<<"Enter marks :";cin >> marks;

                s[i].setData(name, roll, marks);
            }
        }
        else if (x == 2)
        {
            //Display
            for (int i = 0; i < n; i++)
            {
                s[i].display();
            }
        }

        else if (x == 3)
        {
            //SGPA linear search
            int key;
            cout << "Enter marks : ";
            cin >> key;

            vector<int> pos = search.linearSearch(s, key, n);

            if (pos.size() == 0)
            {
                cout << "NOT_FOUND\n";
            }
            else
                cout << "Element found at : ";
                for(auto x : pos)cout<<x<<" ";
                cout<<"\n";
        }

        //record by name binary search
        else if (x == 4)
        {
            string nam;
            cout << "Enter name : ";
            cin >> nam;
            int posName = search.binarySearch(s, nam, n);
            if (posName == -1)
            {
                cout << "NAME_NOT_FOUND\n";
            }
            else
                cout << "Element found at : " << posName << "\n";
        }

        else if (x == 5)
        {
            //Sort by roll No
            search.bubbleSort(s, n);
        }
        else if (x == 6)
        {
            //Sort by roll No
            search.insertionSort(s, n);
        }

        cout << "Press 1 to continue : ";
        cin >> cont;
    } while (cont == 1);

    return 0;
}

// 4
// Jasskaran 20 8
// Ankit 12 9
// Soumyadip 50 10
// Ritik 42 4

// 6
// a 1 2
// d 4 5
// f 6 7
// b 2 3
// e 5 6
// c 3 4
