#include"Header.h"
#include"Funtion.h"


int main()
{
    Car newCar;
    ifstream ifs;

    ifs.open("Password.dat");
    if (!ifs.is_open())// truong hop chua tao mscn, tao mscn lan dau
    {

        while (1)
        {
            cout << "Tao Ma So Ca Nhan" << endl;
            newCar.creatPassword();
            if (newCar.checkIsNumberOnly()) // check gia tri nhan vao la so tu 0-9
            {
                cout << "Tao Ma So Ca Nhan Thanh Cong !!" << endl;
                while (1) // sau khi tao mscn thanh cong hoi user xem muon doi lai ko
                {
                    cout << "Ban co muon thay doi lai ma so ca nhan khong?" << endl;
                    cout << "Yes(y)                       No(n)" << endl;
                    char ys;
                    cin >> ys;
                    if (ys == 'y') {
                        system("cls");
                        while (1)
                        {
                            cout << "Xin Moi Tao Lai Ma So Ca Nhan" << endl;
                            newCar.creatPassword();
                            if (newCar.checkIsNumberOnly())
                            {
                                cout << "Tao Ma So Ca Nhan Thanh Cong !!" << endl;
                                system("pause");
                                system("cls");
                                break;
                            }
                            else {
                                cout << "Xin Moi Tao Lai Ma So Ca Nhan" << endl;
                                system("pause");
                                system("cls");
                            }
                        }
                    }
                    else if (ys == 'n') break;
                    else {
                        cout << "Sai Cu Phap Xin Moi Nhap Lai !" << endl;
                        system("pause");
                        system("cls");
                    }
                }
                break;
            }
            else {
                cout << "Xin Moi Tao Lai Ma So Ca Nhan" << endl;
                system("pause");
                system("cls");
            }
        }

    }
    ifs.close();


    while (1) // dang nhap khi da co mscn
    {
        system("cls");
        cout << "Xin Moi Nhap Ma So Ca Nhan" << endl;
        char mscn[8];   //Mang nhap vao de so sanh
        for (int i = 0; i < 8; i++)
        {
            cin >> mscn[i];
        }

        system("cls");
        cout << "MANG NHAP TRUOC KHI SAP XEP: ";
        for (int i = 0; i < 8; i++)
        {
            cout << mscn[i] << " ";
        }
        cout << endl;

        bubbleSort(mscn, 8);
        cout << "--> MA SO CA NHAN TRUOC KHI SAP XEP: ";
        for (int i = 0; i < 8; i++)
        {
            cout << mscn[i] << " ";
        }
        cout << endl;

        char mscnGoc[8];// dung de luu mscn trong bo nho
        cout << "MA SO CA NHAN TRUOC KHI SAP XEP: ";
        ifs.open("Password.dat");
        for (int i = 0; i < 8; i++)
        {
            ifs >> mscnGoc[i];
            cout << mscnGoc[i] << " ";
        }
        ifs.close();
        cout << endl;

        cout << "MA SO CA NHAN SAU KHI SAP XEP: ";
        newCar.readPassword();
        newCar.selectionSort();
        cout << endl;

        if (newCar.comparePassword(mscn))
        {
            cout << "Dang nhap thanh cong !!" << endl;
            system("pause");
            system("cls");

            while (1) // vong lap de hoi xem co muon thay doi mat khau sau khi dang nhap thanh cong
            {

                cout << "Ban co muon thay doi lai ma so ca nhan khong?" << endl;
                cout << "Yes(y)                       No(n)" << endl;
                char ys;
                cin >> ys;
                if (ys == 'y') {
                    system("cls");
                    while (1)
                    {
                        cout << "Xin Moi Tao Lai Ma So Ca Nhan" << endl;
                        newCar.creatPassword();
                        if (newCar.checkIsNumberOnly())
                        {
                            cout << "Tao Ma So Ca Nhan Thanh Cong !!" << endl;
                            system("pause");
                            system("cls");
                            break;
                        }
                        else {
                            cout << "Xin Moi Tao Lai Ma So Ca Nhan" << endl;
                            system("pause");
                            system("cls");
                        }
                    }
                }
                else if (ys == 'n') 
                {
                    system("cls");
                    break;
                }
                else {
                    cout << "Sai Cu Phap Xin Moi Nhap Lai !" << endl;
                    system("pause");
                    system("cls");
                }
            }
            break;
        }
        else {
            cout << "Dang nhap khong thanh cong !!" << endl;
            cout << "Ma so ca nhan chua chinh xac" << endl;
            system("pause");
            system("cls");
        }
    }

    ifs.open("safe_distance.dat");
    if (!ifs.is_open())
    {
        newCar.setupSafeDistanceSpeed();
    }
    
    
    while (1)
    {
        cout << "XIN MOI LUA CHON: " << endl;
        cout << "1. P" << endl;
        cout << "2. R" << endl;
        cout << "3. N" << endl;
        cout << "4. D" << endl;
        cout << "5. POWER OFF" << endl;
        cout << "----------------------" << endl;
        cout << "6. SETTING" << endl;
        cout << "  >> ";
        char button;
        cin >> button;
        switch (button)
        {
        case '1':
            newCar.P_mode();
            break;
        case '2':
            newCar.R_mode();
            break;
        case '3':
            newCar.N_mode();
            break;
        case '4':
            system("cls");
            newCar.readSafeDistance();
            newCar.D_mode();
            system("cls");
            break;
        case '5': return 0;
        case '6':
            while (1)
            {
                system("cls");
                cout << "1. CAI DAT MA SO CA NHAN" << endl;
                cout << "2. CAI DAT KHOANG CACH AN TOAN" << endl;
                cout << "3. TRO VE MENU" << endl;
                cout << "  >> ";
                char button;
                cin >> button;
                if (button == '1')
                {
                    while (1)
                    {
                        system("cls");
                        cout << "DAT LAI MA SO CA NHAN: ";
                        newCar.creatPassword();
                        if (!newCar.checkIsNumberOnly())
                        {
                            cout << endl << "NHAP SAI KY TU" << endl;
                            system("pause");

                        }
                        else {
                            cout << "CAI DAT THANH CONG" << endl;
                            system("pause");
                            break;
                        }
                    }
                }
                else if (button == '2')newCar.setupSafeDistanceSpeed();
                else if (button == '3') {
                    system("cls");
                    break;
                }
                else {
                    cout << "SAI CU PHAP" << endl;
                    system("cls");
                }
            }
            break;
        default: {
            cout << "SAI CU PHAP XIN MOI NHAP LAI" << endl;
            system("pause");
            system("cls");
        }

        }
    }
    
}
