#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector < vector <string> > du_lieu_sinhvien()
{
    vector < vector <string> > du_lieu(10, vector <string> (5));
    // hoc sinh thu 1
    du_lieu[0][0] = "Le Quang Khanh   ";
    du_lieu[0][1] = "18020704";
    du_lieu[0][2] = "16/12/2000";
    du_lieu[0][3] =  "3.20";
    du_lieu[0][4] = "Ninh Binh";
    // hoc sinh thu 2
    du_lieu[1][0] = "Nguyen Van Chien";
    du_lieu[1][1] = "18020224";
    du_lieu[1][2] = "14/09/1999";
    du_lieu[1][3] =  "3.60";
    du_lieu[1][4] = "Ha Noi";

    //hoc sinh thu 3
    du_lieu[2][0] = "Cao Van Cuong";
    du_lieu[2][1] = "18020249";
    du_lieu[2][2] = "09/07/2000";
    du_lieu[2][3] =  "3.20";
    du_lieu[2][4] = "Hung Yen";
    //hoc sinh thu 4
    du_lieu[3][0] = "Luu Van Duc";
    du_lieu[3][1] = "18020343";
    du_lieu[3][2] = "16/10/2000";
    du_lieu[3][3] =  "3.10";
    du_lieu[3][4] = "Nam Dinh";
    //hoc sinh thu 5
    du_lieu[4][0] = "An Van Huy";
    du_lieu[4][1] = "18020646";
    du_lieu[4][2] = "31/01/2000";
    du_lieu[4][3] =  "2.37";
    du_lieu[4][4] = "Hai Duong";
    //hoc sinh thu 6
    du_lieu[5][0] = "Luong Tuan Anh";
    du_lieu[5][1] = "18020154";
    du_lieu[5][2] = "02/04/2000";
    du_lieu[5][3] =  "3.07";
    du_lieu[5][4] = "Hung Yen";
    //hoc sinh thu 7
    du_lieu[6][0] = "Nguyen Van Toan";
    du_lieu[6][1] = "18021280";
    du_lieu[6][2] = "02/04/2000";
    du_lieu[6][3] =  "2.35";
    du_lieu[6][4] = "Hai Phong";
    //hoc sinh thu 8
    du_lieu[7][0] = "Nguyen Cong Binh";
    du_lieu[7][1] = "18020211";
    du_lieu[7][2] = "04/05/2000";
    du_lieu[7][3] =  "2.67";
    du_lieu[7][4] = "Bac Ninh";
    //hoc sinh thu 9
    du_lieu[8][0] = "Nguyen Dinh Cuong";
    du_lieu[8][1] = "18020256";
    du_lieu[8][2] = "26/06/2000";
    du_lieu[8][3] =  "2.50";
    du_lieu[8][4] = "Bac Ninh";
    //hoc sinh thu 10
    du_lieu[9][0] = "Le Ba Tue";
    du_lieu[9][1] = "18021385";
    du_lieu[9][2] = "26/03/2000";
    du_lieu[9][3] =  "2.87";
    du_lieu[9][4] = "Bac Ninh";

    return du_lieu;
}

void printResult (vector <int> index, vector < vector <string> > du_lieu)
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
    vector < vector <string> > du_lieu = du_lieu_sinhvien();

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
