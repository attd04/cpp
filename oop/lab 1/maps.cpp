#include <iostream>
#include <map>
#include <string>
using namespace std;

// problem 8

int main8()
{
    map<int, int> studs; // defining map and its variable types
    int mCount, qCount; // defining integers
    
    // counting first sequence
    cin >> mCount; // input first #'s
    
    for (int i = 0; i < mCount; i++)
    {
        int temp;
        cin >> temp;
        
        if (studs.find(temp) != studs.end())
            studs[temp]++;
        
        else
            studs.insert(make_pair(temp, 1));
    }
    
    // count other sequence
    cin >> qCount;
    
    for (int i = 0; i < qCount; i++)
    {
        int temp;
        cin >> temp;
        
        if (i < qCount - 1)
            
            if(studs.find(temp) != studs.end())
                cout << studs[temp] << " ";
        
            else
                cout << 0 << " ";
        
        else


// --------------------------------------------------

// problem 10

int main10()
{
    map <string, int> a;
    int k;
    cin >> k;
    for(int i=0; i<k;i++){
        string tmp;
        cin>>tmp;
        a[tmp]++;
    }
    map <string, int>::iterator ai;
    int temp = 0;
    string res;
    for(ai = a.begin();ai!=a.end();ai++){
        if(ai->second > temp){
            temp = ai->second;
            res = ai->first;
        }
    }
    cout<<temp;
    return 0;
}

// --------------------------------------------------

// problem 11.2

int main11()
{
    int count;
    cin >> count; // input how many words
    
    map<string, string> m; // define map
    for (int i = 0; i < count; i++)
    {
        string key, value; // define values
        cin >> key >> value; // input values
        
        m.insert(make_pair(key, value)); // make pair out of values
    }
    for (const auto &[key, value] : m) // loop thru pairs
    {
        if (m.find(value) != m.end() && m.at(value) == key) // if value matches key, print yes
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO"; // otherwise print no
    return 0;
}

// --------------------------------------------------

// problem 12

int main12() {
    string s;
    map<char, int> charCount;
    int count = 0;

    // read the input string
    
    getline(cin, s);

    // count the frequency of each character
    for (char c : s) {
        charCount[c]++;
    }

    // count the number of characters that appear more than twice
    for (auto entry : charCount) {
        if (entry.second > 2) {
            count++;
        }
    }

    // output the result
    cout << count << endl;

    return 0;
}

// --------------------------------------------------

// problem 13

int main() {
    int n;
    cin >> n; // Input the number of elements in the sequence

    map<int, int> freq; // Create a map to store the frequency of each element
    int maxRepeated = INT_MIN; 

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num; // Input the next element in the sequence

        freq[num]++; 

        // Check if the current element is repeated more than twice
        if (freq[num] > 2 && num > maxRepeated) {
            maxRepeated = num; 
        }
    }

    // Check if any element was repeated more than twice
    if (maxRepeated == INT_MIN) {
        cout << "NO" << endl;
    }
    else {
        cout << maxRepeated << endl;
    }

    return 0;
}

// --------------------------------------------------
            cout << studs[temp];
    }
}

