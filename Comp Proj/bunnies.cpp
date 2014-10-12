#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

//in this project, there are 36691 bunnies
//these bunnies have interesting social lives
//we are analyzing the social lives of these bunnies
//more friends = higher social status

int main()
{
    fstream f;
    unsigned int bunnyfriends[36691];
    f.open("Data.txt",ios::in | ios::out);
    string s,bunny,frnd;
    for(int i=0;i<36691;i++)
    {
        bunnyfriends[i]=0; //initialize the bunnies
    }
    while(!f.eof())
    {
        s="";
        bunny="";
        getline(f,s);
        int flag = 1;
        for(int i = 0;i<s.size();i++)
        {
            if(s.at(i)==' ')
            {
                break;
            }
            if(flag==1)
                bunny += s.at(i);
        }
        unsigned int a = atoi(bunny.c_str());
        bunnyfriends[a]++;
        //cout << "Bunny no. " << a << " has a new friend.";
    }
    long long i;
    FILE *fp = fopen("Degree.txt", "w");
    for(i = 1; i < 36691; i++) {
        fprintf(fp, "%lld has a degree of %d\n", i, bunnyfriends[i]);
    }
    fclose(fp);
    while(i!=-1)
    {
        cout << "Enter bunny no:\n";
        cin >> i;
        cout << "Bunny no. " << i << " has " << bunnyfriends[i] << " friends.\n";
    }
    f.close();
    return 0;
}

