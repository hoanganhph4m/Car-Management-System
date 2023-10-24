#include"Funtion.h"

void bubbleSort(char a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i - 1; j--)
        {
            if (*(a + j) < *(a + (j - 1))) swap(*(a + j), *(a + (j - 1)));
        }
    }

}

void Car::creatPassword()
{
    ofstream ofs("Password.dat");
    for (int i = 0; i < 8; i++) cin >> pw[i];
    for (int i = 0; i < 8; i++) ofs << pw[i] << endl;
    ofs.close();
}

void Car::readPassword()
{
    ifstream ifs;
    ifs.open("Password.dat");
    for (int i = 0; i < 8; i++)
    {
        ifs >> pw[i];
    }
    ifs.close();
}

void Car::readSafeDistance()
{
    ifstream ifs;
    ifs.open("safe_distance_speed.dat");
    for (int i = 0; i < 3; i++)
    {
        ifs >> sds[i];
    }
    ifs.close();
    ifs.open("safe_distance.dat");
    for (int i = 0; i < 4; i++)
    {
        ifs >> sd[i];
    }
    ifs.close();
}

void Car::selectionSort()
{
    int min;
    for (int i = 0; i < 8 - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < 8; j++)
        {
            if (*(pw + j) < *(pw + min)) min = j;
        }
        swap(*(pw + i), *(pw + min));
    }
    for (int i = 0; i < 8; i++)
    {
        cout << pw[i] << " ";
    }
    cout << endl;
}

bool Car::comparePassword(char a[])
{
    for (int i = 0; i < 8; i++)
    {
        if (pw[i] != a[i])
        {

            return false;
        }
    }

    return true;
}

bool Car::checkIsNumberOnly()
{
    for (int i = 0; i < 8; i++)
    {
        if (pw[i] < 48 || pw[i]>57)
        {
            return false;
        }
    }
    return true;
}

void Car::setupSafeDistanceSpeed()
{
    while (1)
    {
        system("cls");
        cout << "CAI DAT VAN TOC CANH BAO KHOANG CACH AN TOAN VOI 3 MUC VAN TOC" << endl;
        cout << "XIN MOI NHAP 3 MUC VAN TOC ";

        ofstream ofs("safe_distance_speed.dat");
        for (int i = 0; i < 3; i++) cin >> sds[i];


        if (checkSafeDistanceSpeed(sds, 3))
        {
            int min;
            for (int i = 0; i < 3 - 1; i++)
            {
                min = i;
                for (int j = i + 1; j < 3; j++)
                {
                    if (stoi(*(sds + j)) < stoi(*(sds + min))) min = j;
                }
                swap(*(sds + i), *(sds + min));
            }

            for (int i = 0; i < 3; i++) ofs << sds[i] << endl;

            system("cls");
            cout << "CAI DAT VAN TOC CANH BAO KHOANG CACH AN TOAN VOI 3 MUC VAN TOC:  " << endl;
            cout << "VAN TOC MUC 1: " << sds[0] << " km/h" << endl;
            cout << "VAN TOC MUC 2: " << sds[1] << " km/h" << endl;
            cout << "VAN TOC MUC 3: " << sds[2] << " km/h" << endl;
            system("pause");
            system("cls");
            ofs.close();
            break;
        }
        else
        {
            cout << "SAI THONG TIN XIN MOI NHAP LAI" << endl;
            system("pause");
        }
        ofs.close();
    }

    ofstream ofs("safe_distance.dat");

    while (1)
    {
        cout << "KHOANG CACH AN TOAN VOI VAN TOC DUOI " << sds[0] << "(km/h): ";
        cin >> sd[0];
        cout << endl;
        cout << "KHOANG CACH AN TOAN VOI VAN TOC TU " << sds[0] << "-" << sds[1] << "(km/h): ";
        cin >> sd[1];
        cout << endl;
        cout << "KHOANG CACH AN TOAN VOI VAN TOC TU " << sds[1] << "-" << sds[2] << "(km/h): ";
        cin >> sd[2];
        cout << endl;
        cout << "KHOANG CACH AN TOAN VOI VAN TOC TU " << sds[2] << "-" << sds[3] << "(km/h): ";
        cin >> sd[3];
        cout << endl;
        if (checkSafeDistanceSpeed(sd, 4))
        {
            cout << "LUU THANH CONG" << endl;
            for (int i = 0; i < 4; i++) ofs << sd[i] << endl;
            system("pause");
            system("cls");
            ofs.close();
            break;
        }
        else {
            cout << "SAI THONG TIN XIN MOI NHAP LAI" << endl;
            system("pause");
            system("cls");
        }
    }



}


bool Car::checkSafeDistanceSpeed(string a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char c : a[i])
        {
            if (!isdigit(c)) return false; // Nếu có ít nhất một ký tự không phải số, trả về false.
        }
        if (stoi(a[i]) < 0 || stoi(a[i]) > 300) return false;

    }
    return true;
}

void Car::D_mode()
{
    speed = 7;
    while (1)
    {
        cout << " ---- TOC DO HIEN TAI: " << speed << "km/h" << endl;

        if (speed < stoi(sds[0])) cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA " << sd[0] << "m" << endl;
        else if (speed >= stoi(sds[0]) && speed < stoi(sds[1])) cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA " << sd[1] << "m" << endl;
        else if (speed >= stoi(sds[1]) && speed < stoi(sds[2])) cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA " << sd[2] << "m" << endl;
        else cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA " << sd[3] << "m" << endl;

        cout << "MOI LUA CHON: " << endl;
        cout << "1: TANG TOC" << endl;
        cout << "2: GIAM TOC" << endl;
        cout << "3: PHANH" << endl;
        cout << "4: TRO VE MENU" << endl;
        cout << "  >> ";

        char button;
        cin >> button;

        if (button == '1') {
            speed += 5;
            system("cls");
        }
        else if (button == '2')
        {
            speed -= 5;
            if (speed < 0)
            {
                speed = 0;
                system("cls");
            }
            system("cls");
        }
        else if (button == '3') {
            speed = 0;
            system("cls");
        }
        else if (button == '4') {
            if (speed == 0)break;
            else
            {
                cout << "DUNG XE TRUOC KHI CHUYEN CHE DO" << endl;
                system("pause");
                system("cls");
            }
        }
        else {
            cout << "SAI CU PHAP IN MOI NHAP LAI";
            system("pause");
            system("cls");
        }

    }
}

void Car::P_mode()
{
    system("cls");
    cout << "DA VE SO P" << endl;
    cout << "CHU Y SU DUNG PHANH TAY" << endl;
    cout << endl;

}

void Car::N_mode()
{
    system("cls");
    cout << "DA VE SO N" << endl;
    cout << endl;

}

void Car::R_mode()
{

    while (1)
    {
        system("cls");
        cout << " ---- TOC DO HIEN TAI: " << speed << "km/h" << endl;
        cout << "CHU Y XE PHIA SAU" << endl;
        cout << "MOI LUA CHON: " << endl;
        cout << "1: TANG TOC" << endl;
        cout << "2: GIAM TOC" << endl;
        cout << "3: PHANH" << endl;
        cout << "4: TRO VE MENU" << endl;
        cout << "  >> ";

        char button;
        cin >> button;

        if (button == '1')
        {
            speed += 5;
            system("cls");
        }
        else if (button == '2')
        {
            speed -= 5;
            if (speed < 0)
            {
                speed = 0;
                system("cls");
            }
            system("cls");
        }
        else if (button == '3')
        {
            speed = 0;
            system("cls");
        }
        else if (button == '4')
        {
            if (speed == 0)
            {
                system("cls");
                break;
            }
            else
            {
                cout << "DUNG XE TRUOC KHI CHUYEN CHE DO" << endl;
                system("pause");
                system("cls");
            }

        }
        else
        {
            cout << "SAI CU PHAP IN MOI NHAP LAI";
            system("pause");
            system("cls");
        }
    }
}