#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void printString (const char *myString)
{
    cout << myString;
} //Ham in xau

void deleteChar (char *myString)
{
    int deletePos = rand() % strlen(myString);
    while (deletePos < strlen(myString) - 1)
    {
        myString[deletePos] = myString[deletePos + 1];
        deletePos ++;
    }
    myString[deletePos] = '\0';

} //Ham xoa 1 ky tu trong xau

void changeSpace (char *myString)
{
    for (int i = 0; i < strlen(myString); i++)
        if (myString[i] == ' ') myString[i] = '*';
} //Ham thay the dau cach bang dau *

int main()
{
    // Nhap do dai xau
    int stringLength;
    cout << "Nhap do dai xau: ";
    cin >> stringLength;

    //Cap phat bo nho cho xau
    char *myString;
    myString = new char[stringLength];

    //Nhap xau ki tu
    cout << "Nhap xau ki tu: ";
    cin.ignore();
    cin. getline(myString, stringLength + 1);

    //In xau vua nhap
    cout << "Xau vua nhap : "; printString(myString);
    cout << endl;

    //Xoa mot ky tu bat ky trong xau va in ra
    deleteChar(myString);
    cout << "Xau vua duoc xoa 1 ky tu ngau nhien: "; printString(myString);

    //Thay the cac dau cach trong xau vaf in ra man hinh
    cout << endl;
    changeSpace(myString);
    cout << "Xau vua duoc thay the dau cach la: "; printString(myString);

	return 0;
}

