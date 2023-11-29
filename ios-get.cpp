// This program reads a fle called Message.dat
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
ifstream yourfle ("message.dat"); // Open fle for input
char row[80],ch;
int i;
if (!yourfle)
{
cout << "Cannot open fle .. ";
return 1;
}
for (i = 1;i <= 6;i++)
{
yourfle.get(row,80); // Read a line from the fle
yourfle.get(ch); // Read ‘\n’
cout << row <<endl;; // Display the line on the screen
}
yourfle.close();
return 0;
}