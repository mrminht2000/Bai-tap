#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printResult (vector <int> index, string **du_lieu)
{
    for (int i = 0; i < index.size(); i++)
    {
        for (int j = 0; j < 5; j++)
            cout << du_lieu[index[i]][j] << endl;
        cout << endl;
    }
}

string chuanHoa (string input)
{
    while (input[0] == ' ') input.erase(1, 0);
    while (input[input.length() - 1] == ' ') input.erase(1, input.length() - 1);

    return input;
}

int main()
{
    vector <int> index;                                                                                //Luu chi so sinh vien
    string information[5] = {"ho va ten", "ma so sinh vien", "ngay sinh", "diem tich luy", "que quan"};//Luu kieu thong tin sinh vien
    string **du_lieu = du_lieu_sinhvien();

// Hoi que quan
    string inputData;
    cout << "Nhap que quan sinh vien: ";
    cin.ignore(0);
    getline(cin, inputData);                                                                           //Nhap que quan

    inputData = chuanHoa(inputData);

    for (int i = 0; i < 10; i++)
        if (chuanHoa(du_lieu[i][4]) == inputData) index.push_back(i);

    cout << "Co " << index.size() << " ket qua tim kiem." << endl;

// Hoi cac thong tin con lai
    int ask = 3;

    while ((index.size() > 1) && (ask > -1))
    {
        cout << "Nhap " << information[ask] << " sinh vien: ";
        cin.ignore(0);
        getline(cin, inputData);

        inputData = chuanHoa((inputData));

        for (int i = 0; i < index.size(); i++)
        {
            if (chuanHoa(du_lieu[index[i]][ask]) != inputData)
            {
                index.erase(index.begin() + i);
                i--;
            }
        }
        cout << "Co " << index.size() << " ket qua tim kiem." << endl;
        ask--;
    }
// In thong tin
    printResult(index, du_lieu);

    return 0;
}
