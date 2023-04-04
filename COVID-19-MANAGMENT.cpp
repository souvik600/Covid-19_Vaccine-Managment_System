#include<iostream>
#include<cstring>
#include<iomanip>
#include<string>
#include<cstdlib>   //System colour
#include<fstream>   //File handle
#include<conio.h>
#include<unistd.h>   //Sleep
#include<windows.h>

#define TOTAL_VACCINE 500
using namespace std;

class CovidManagement
{
protected:
    string username;
    string password;
    string usn;

    // FOR VACCINE CENTER
    string astrazeneca = "Astrazeneca";
    string moderna = "Moderna";
    string sinopharm = "Sinopharm";
    int astrazenecaVacc = 0;
    int modernaVacc = 0;
    int sinopharmVacc = 0;
    int add = 0, center_no = 0;
    int total_vaccine = 0 ;
    string data;
    int vaccineName;

public:
    void menu();
    void admin();
    void adminPassword();
    void user();
    void userPassword();

    //For Admin
    void addVaccineStock();
    void showVaccineStock();
    void showPatintData();
    void showTotalNoOfVaccineApplied();
    void addNewDoctorData();
    void showDoctorData();
    void vaccinatedPatints();
    void showDataVaccinated();
    void showPatintVaccinated();
    void updateVaccine();
    void searchByNid();
    void searchByAge();
    void searchByProfession();
    void searchByGender();

    //For User
    void applyVaccine();
    void showPatintDitails();
    void showData();

    // For Doctor Details
    string identification_id;
    string specialization;

    // For User and some Doctor Details
    string phone_no, profession, address, vaccine_name,name,gender,age,nid, dose;
    string line;
};
//For main menu
void CovidManagement::menu()
{
    system("cls");
    int choice;
    cout<<"\n\t\t\t***********************************";
    cout<<"\n\t\t\t****  Covid Management System *****";
    cout<<"\n\t\t\t***********************************";
    cout<<"\n\n\t\t\t=====>>  MAIN MENU  <<=====";
    cout<<"\n\n\t\t\t 1. ADMIN";
    cout<<"\n\t\t\t 2. USER";
    cout<<"\n\t\t\t 3. EXIT";
    cout<<"\n\n\t\t\tEnter Choice :";
    cin>>choice;
    //calling main menu
    switch (choice)
    {
    case 1:
        admin();
        break;
    case 2:
        user();
        break;
    case 3:
        system("cls");
        cout<<"\n\t\t\t***********************************";
        cout<<"\n\t\t\t****  Covid Management System *****";
        cout<<"\n\t\t\t***********************************";
        cout<<"\n\n\n\t\t\t\tThank you \n\n\n\n";
        Sleep(10);
        exit(0);
    default:
        cout<<"\n\t\t\tInvalid Keyword Please Try Again";
        cout<<"\n\n\t\t\tPress Any Key to Continue :";
        getch();
        menu() ;
    }
}

//Admin
void CovidManagement::admin()
{
    adminPassword();
A:
    system("cls");
    int adminChoice;
    cout<<"\n\t\t\t***********************************";
    cout<<"\n\t\t\t****  Covid Management System *****";
    cout<<"\n\t\t\t***********************************";

    //ADMIN NENU OPTION
    cout<<"\n\n\t\t\t 1. Add Vaccine Stock";
    cout<<"\n\t\t\t 2. Show Vaccine Stock";
    cout<<"\n\t\t\t 3. Show Patient data";
    cout<<"\n\t\t\t 4. Show Total Number of Vaccine Applied";
    cout<<"\n\t\t\t 5. Add New Doctor Data";
    cout<<"\n\t\t\t 6. Show Doctor Data";
    cout<<"\n\t\t\t 7. Want to Completed Vaccine";
    cout<<"\n\t\t\t 8. EXIT";
    cout<<"\n\n\t\t\t Enter Choice :";
    cin>>adminChoice;

    switch(adminChoice)
    {
    case 1:
        addVaccineStock();
        goto A;
        break;
    case 2:
        showVaccineStock();
        goto A;
        break;
    case 3:
        showPatintData();
        goto A;
        break;
    case 4:
        showTotalNoOfVaccineApplied();
        goto A;
        break;
    case 5:
        addNewDoctorData();
        goto A;
        break;

    case 6:
        showDoctorData();
        goto A;
        break;
    case 7:
        vaccinatedPatints();
        goto A;
        break;

    case 8:
        menu();
    default:
        cout<<"\n\n\t\t\t Your Keyword is Invalid......";
        cout<<"\n\t\t\t Please Try Again......";
        cout<<"\n\n\t\t\t\t Press Any Key To Continue";
        getch;
        goto A;
        break;
    }
}
//Admin Login
void CovidManagement::adminPassword()
{
    system("cls");
    string admin_name;
    string admin_password;
    cout<<"\n\t\t\t***********************************";
    cout<<"\n\t\t\t****  Covid Management System *****";
    cout<<"\n\t\t\t***********************************";
    cout<<"\n\n\t\t\t=====>>  LOGIN ADMIN  <<=====";
    cout<<"\n\n\t\tEnter  Your  Name    : ";
    cin>>admin_name;
    cout<<"\n\n\t\tEnter Your Password  : ";
    cin>>admin_password;


    if (admin_name == "souvik" && admin_password == "s2512das")
    {

        cout<<"\n\n\n\n\t\t\t || Verifying Admin  ||\n\t\t\t";
        for (int a = 1; a < 8; a++)
        {
            cout<< "...";
            sleep(1);
        }
        cout<<"\n\n\t\t\t Login Successful....\n\n"<<endl;
        system("cls");
    }
    else
    {
        cout<<"\n\n\n\n\t\t\t || Verifying Admin  ||\n\t\t\t";
        for (int a = 1; a < 8; a++)
        {
            cout<< "...";
            sleep(1);
        }
        cout<<"\n\n\t\t\t Invalid Name 0r Password\n\n"<<endl;
        system("PAUSE");
        system("cls");
        menu();
    }

}

//User
void CovidManagement::user()
{
    system("cls");
    userPassword();
A:
    int userChoice;
    cout<<"\n\t\t\t***********************************";
    cout<<"\n\t\t\t****  Covid Management System *****";
    cout<<"\n\t\t\t***********************************";

    //USER NENU OPTION
    cout<<"\n\t\t\t 1. Apply for Vaccine Dose";
    cout<<"\n\t\t\t 2. Show Patient Details";
    cout<<"\n\t\t\t 3. LOGOUT";
    cout<<"\n\n\t\t\t Enter Choice :";
    cin>>userChoice;
    switch(userChoice)
    {
    case 1:
        applyVaccine();
        goto A;
        break;

    case 2:
        showPatintDitails();
        goto A;
        break;
    case 3:
        menu();
    default:
        cout<<"\n\n\t\t\t Your Keyword is Invalid......";
        cout<<"\n\t\t\t Please Try Again......";
        cout<<"\n\n\t\t\t\t Press Any Key To Continue";
        getch();
        goto A;
        break;
    }

}
//User Re-gestation & Login
void CovidManagement::userPassword()
{
    system("cls");
    char c;
    int userChoice;
    string file_name, user_name;
    ofstream fileo;
    ifstream filei;
    cout<<"\n\t\t\t***********************************";
    cout<<"\n\t\t\t****  Covid Management System *****";
    cout<<"\n\t\t\t***********************************";
    cout<<"\n\n\t\t\t=====>>  USER SUB-MENU  <<=====";
    cout<<"\n\n\t\t 1. Create Account";
    cout<<"\n\n\t\t 2. Login";
    cout<<"\n\n\t\t 3. Back";
    cout<<"\n\n\t\t\t Enter Choice :";
    cin>>userChoice;
    if (userChoice == 1)
    {
        system("cls");
        cout << "\n\t\t\t\t*****************************************";
        cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
        cout << "\n\t\t\t\t*****************************************";
        cout<<"\n\n\t\t\t=====>>  USER REGISTATION  <<=====";
        cout << "\n\t\tEnter Your User Name: ";
        cin >> usn;
        cout << "\n\t\tEnter Your password: ";
        cin >> password;
        file_name = usn + ".txt";
        fileo.open(file_name.c_str());
        fileo << usn << endl
              << password << endl;
        cout << "\n\n\tYou are successfully registered:";
        cout << "\n\n\tPress Any Key To Continue..";
        Sleep(50);
        getch();
        fileo.close();
        user();
    }
    else if (userChoice == 2)
    {
        system("cls");
        string u_name, u_pass;
        cout << "\n\t\t\t\t*****************************************";
        cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
        cout << "\n\t\t\t\t*****************************************";
        // LOGIN USER
        cout<<"\n\n\t\t\t=====>>  LOGIN USER  <<=====";
        cout << "\n\n\t\tEnter Your Username: ";
        cin >> u_name;
        cout << "\n\t\tEnter Your Password: ";
        cin >> u_pass;
        file_name = u_name + ".txt";
        filei.open(file_name.c_str());
        if (!filei.is_open() && filei.fail())
        {
            cout << "\nYou are not registered, please register before logging in.\n";
            filei.close();
            getch();
            userPassword();
        }
        getline(filei, user_name);
        getline(filei, u_pass);
        if (u_name == usn && u_pass == password)
        {
            cout << "\nYou are successfully logged in:)";

            user();
        }
        system("cls");

    }
    else if (userChoice == 3)
    {
        menu();
    }
    else
    {
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
        cout << "\n\n Press Any Key To Continue: ";
        getch();
        userPassword();
    }
}


void CovidManagement::addVaccineStock()
{
A:
    fstream file;
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> ADD VACCINE IN CENTER <<--";
    cout << "\n\n\t\t1. " << astrazeneca  << "\t\t2. " << moderna ;
    cout << "\n\n\t\t3. " << sinopharm << "\t\t4. BACK";
    cout << "\n\n\n\t\tEnter Choice: ";
    cin >> vaccineName;
    switch (vaccineName)
    {
    case 1:
    {
        file.open("Astrazeneca.txt");
        cout << "\n\n\n\t\tEnter Number Of AstraZeneca Vaccines You Want To Add: ";
        cin >> add;
        string temp;
        while (getline(file, temp))
        {
            astrazenecaVacc = atoi(temp.c_str());
        };

        astrazenecaVacc = (astrazenecaVacc + add);
        file.close();

        file.open("Astrazeneca.txt", ios::out);
        file << astrazenecaVacc;
        file.close();
        cout << "\n\n\tTotal AstraZeneca Vaccine : " << astrazenecaVacc;
        cout << "\n\n\t\tSUCCESSFULLY ADDED VACCINES ";
        cout << "\n\n\nPress Any Key To Continue...";
        getch();
        goto A;
        break;
    }
    case 2:
    {
        file.open("moderna.txt");
        cout << "\n\n\n\t\tEnter Number Of Moderna Vaccines You Want To Add: ";
        cin >> add;
        string temp;
        while (getline(file, temp))
        {
            modernaVacc = atoi(temp.c_str());
        };

        modernaVacc = (modernaVacc + add);
        file.close();

        file.open("moderna.txt", ios::out);
        file << modernaVacc;
        file.close();
        cout << "\n\n\tTotal Moderna Vaccine : " <<modernaVacc;
        cout << "\n\n\t\tSUCCESSFULLY ADDED VACCINES ";
        cout << "\n\n\nPress Any Key To Continue...";
        getch();
        goto A;
        break;
    }
    case 3:
    {
        file.open("sinopharm.txt");
        cout << "\n\n\n\t\tEnter Number OfSinoPharm Vaccines You Want To Add: ";
        cin >> add;
        string temp;
        while (getline(file, temp))
        {
            sinopharmVacc = atoi(temp.c_str());
        };

        sinopharmVacc = (sinopharmVacc + add);
        file.close();

        file.open("sinopharm.txt", ios::out);
        file << sinopharmVacc;
        file.close();
        cout << "\n\n\tTotal Sinopharm Vaccine : " <<sinopharmVacc;
        cout << "\n\n\t\tSUCCESSFULLY ADDED VACCINES ";
        cout << "\n\n\nPress Any Key To Continue...";
        getch();
        goto A;
        break;


    }
    case 4:
        break;
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
        cout << "\n\n Press Any Key To Continue: ";
        getch();
        addVaccineStock();
        break;
    }
}
void CovidManagement::showVaccineStock()
{
    system("cls");
    ifstream file1, file2, file3;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM       *";
    cout << "\n\t\t\t\t*****************************************";
    file1.open("Astrazeneca.txt");
    file2.open("moderna.txt");
    file3.open("sinopharm.txt");
    if (!file1 && !file2 && !file3)
    {
        cout << "\nFile Not Found ";
    }
    else
    {
        file1 >> astrazenecaVacc;
        cout << "\n\n\n\t\t Total AstraZeneca Vaccine: " << astrazenecaVacc;
        file2>>modernaVacc;
        cout<<"\n\n\n\t\t Total Moderna Vaccine: "<<modernaVacc;
        file3>>sinopharmVacc;
        cout<<"\n\n\n\t\t Total Sinopharm Vaccine:"<< sinopharmVacc;
        total_vaccine = astrazenecaVacc + modernaVacc + sinopharmVacc;
        cout<<"\n\n\n\t\t Total Vaccine :"<<total_vaccine;
    }
    file1.close();
    file2.close();
    file3.close();
    cout << "\n\n\tPress Any Key To Continue..";
    getch();
}
void CovidManagement::addNewDoctorData()
{

    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM       *";
    cout << "\n\t\t\t\t*****************************************";

    cout<<"\n\n\t\t\t\t=====>>  ADD DOCTOR DATA <<=====";

    fstream file;


    cout << "\n\n\t\tEnter Name: ";
    cin>>name;

    cout << "\n\n\t\tEnter Identification Number: ";
    cin >> identification_id;

    cout << "\n\n\t\tEnter Your Mobile Number: ";
    cin >> phone_no;

    cout << "\n\n\t\tEnter Gender (M/F): ";
    cin >> gender;

    cout << "\n\n\t\tEnter Age: ";
    cin >> age;

    cout << "\n\n\t\tEnter Specialization: ";
    cin>>specialization;

    data += "NAME   : " + name + "\n\n";
    data += "Identification Number  : " + identification_id + "\n\n";
    data += "Mobile  : " + phone_no + "\n\n";
    data += "Gender : " + gender + "\n\n";
    data += "Age  : " + age + "\n\n";
    data += "Specialization  : " + specialization + "\n\n";
    data += "  ::::::::::::::::::::::::::: "  "\n\n";

    file.open("Doctor_Data.txt", ios::app);
    file<<data;
    cout << "\n\nYOUR DATA HAS BEEN SUCCESSFULLY RECORD" << endl;
    cout << "\n\nPress Any Key To Continue..";
    file.close();
    getch();
}
void CovidManagement::showDoctorData()
{
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *   ";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t\t===>> DOCTOR DATA  <<===\n\n";
    ifstream file;
    file.open("Doctor_Data.txt");
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        while (getline(file, line))
        {
            cout  << line << endl;
        }
    }

    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}
void CovidManagement::showPatintData()
{
B:
    system("cls");
    int choice;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SEARCH PATIENT DATA <<--";
    cout << "\n\t\t1. Search Data By NID \t\t\t2. Search Data BY  AGE" << endl;
    cout << "\n\t\t3. Search Data By Profession \t\t4. Search Data By Gender" << endl;
    cout << "\n\t\t5. EXIT";
    cout << "\n\n\t\tEnter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        searchByNid();
        goto B;
    case 2:
        searchByAge();
        goto B;
    case 3:
        searchByProfession();
        goto B;
    case 4:
        searchByGender();
        goto B;
    case 5:
        break;
    default:
        cout << "\n\n\t\tInvalid Choice.. Please Try Again..";
        getch();
        goto B;
    }
}

void CovidManagement::searchByNid()
{
    int count = 0;
    string unid;
    ifstream file;
    file.open("PatientData.dat", ios::in | ios::binary);
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SEARCH PATIENT DATA BY NID <<--";
    cout << "\n\n\t\tEnter NID No.: ";
    cin >> unid;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(CovidManagement));
    }
    while (!file.eof())
    {
        if (unid.compare(nid) == 0)
        {
            count++;
            showData();
        }
        file.read((char *)this, sizeof(CovidManagement));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void CovidManagement::searchByAge()
{
    int count = 0;
    string uage;
    ifstream file;
    file.open("PatientData.dat", ios::in | ios::binary);
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SEARCH PATIENT DATA BY AGE <<--";
    cout << "\n\n\t\tEnter Your Age: ";
    cin >> uage;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(CovidManagement));
    }
    while (!file.eof())
    {
        if (uage.compare(age) == 0)
        {
            count++;
            showData();
        }
        file.read((char *)this, sizeof(CovidManagement));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void CovidManagement::searchByProfession()
{
    int count = 0;
    string uprofession;
    ifstream file;
    file.open("PatientData.dat", ios::in | ios::binary);
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SEARCH PATIENT DATA BY PROFESSION <<--";
    cout << "\n\n\t\tEnter Your Profession: ";
    cin >> uprofession;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(CovidManagement));
    }
    while (!file.eof())
    {
        if (uprofession.compare(profession) == 0)
        {
            count++;
            showData();
        }
        file.read((char *)this, sizeof(CovidManagement));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void CovidManagement::searchByGender()
{
    int count = 0;
    string ugender;
    ifstream file;
    file.open("PatientData.dat", ios::in | ios::binary);
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SEARCH PATIENT DATA BY GENDER <<--";
    cout << "\n\n\t\tEnter Your Gender: ";
    cin >> ugender;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(CovidManagement));
    }
    while (!file.eof())
    {
        if (ugender.compare(gender) == 0)
        {
            count++;
            showData();
        }
        file.read((char *)this, sizeof(CovidManagement));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void CovidManagement::showTotalNoOfVaccineApplied()
{
    ifstream ind;
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> VACCINATED PERSON <<--";
    int i = 0;
    ind.open("PatientData.dat");
    ind.seekg(0, ios::beg);
    while (ind.read((char *)this, sizeof(CovidManagement)))
    {
        i++;
    }
    ind.close();
    cout << "\n\n\t\tVaccine Applied Person: " << i;
    cout << "\n\nPress Any Key To Continue..";
    getch();
}
void CovidManagement::vaccinatedPatints()
{
    int choice;
    int count = 0;
    string unid;
    ifstream file;
    file.open("PatientData.dat", ios::in | ios::binary);
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SEARCH DATA BY NID <<--";
    cout << "\n\n\tEnter NID No.: ";
    cin >> unid;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(CovidManagement));
    }
    while (!file.eof())
    {
        if (unid.compare(nid) == 0)
        {
            count++;
            showData();
            ifstream file1, file2, file3;
            file1.open("Astrazeneca.txt");
            file2.open("moderna.txt");
            file3.open("sinopharm.txt");
            if (!file1 && !file2 && !file3)
            {
                cout << "\nFile Not Found ";
            }
            else
            {
                file1 >> astrazenecaVacc;
                cout << "\n\t Total AstraZeneca Vaccine: " << astrazenecaVacc;
                file2>>modernaVacc;
                cout<<"\n\t Total Moderna Vaccine: "<<modernaVacc;
                file3>>sinopharmVacc;
                cout<<"\n\t Total Sinopharm Vaccine:"<< sinopharmVacc;
                total_vaccine = astrazenecaVacc + modernaVacc + sinopharmVacc;
                cout<<"\n\t.......................................";
                cout<<"\n\t Total Vaccine :"<<total_vaccine;
            }
            file1.close();
            file2.close();
            file3.close();
            cout << "\n\n\t Do You Want Vaccinated This Pataint";
            cout << "\n\n\t\t1. YES \t\t2. NO" << endl;
            cout<<"\n\n\t Enter your Choice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                updateVaccine();

            case 2:
                break;
            default:
                cout << "\n\n\t\tInvalid Choice.. Please Try Again..";
            }

        }
        file.read((char *)this, sizeof(CovidManagement));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    getch();

}

void CovidManagement::updateVaccine()
{
A:
    fstream file;
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> Select Vaccine <<--";
    cout << "\n\n\t\t1. " << astrazeneca  << "\t\t2. " << moderna ;
    cout << "\n\n\t\t3. " << sinopharm << "\t\t4. BACK";
    cout << "\n\n\n\t\tEnter Choice: ";
    cin >> vaccineName;
    switch (vaccineName)
    {
    case 1:
    {
        file.open("Astrazeneca.txt");
        string temp;
        while (getline(file, temp))
        {
            astrazenecaVacc = atoi(temp.c_str());
        };

        astrazenecaVacc = (astrazenecaVacc - 1);
        file.close();

        file.open("Astrazeneca.txt", ios::out);
        file << astrazenecaVacc;
        file.close();
        cout << "\n\tTotal AstraZeneca Vaccine : " << astrazenecaVacc;
        showPatintVaccinated();
        cout << "\n\n\nPress Any Key To Continue...";
        getch();
        goto A;
        break;
    }
    case 2:
    {
        file.open("moderna.txt");
        string temp;
        while (getline(file, temp))
        {
            modernaVacc = atoi(temp.c_str());
        };

        modernaVacc = (modernaVacc - 1);
        file.close();

        file.open("moderna.txt", ios::out);
        file << modernaVacc;
        file.close();
        cout << "\n\tTotal Moderna Vaccine : " <<modernaVacc;
        showPatintVaccinated();
        cout << "\n\n\nPress Any Key To Continue...";
        getch();
        goto A;
        break;
    }
    case 3:
    {
        file.open("sinopharm.txt");
        string temp;
        while (getline(file, temp))
        {
            sinopharmVacc = atoi(temp.c_str());
        };

        sinopharmVacc = (sinopharmVacc - 1);
        file.close();

        file.open("sinopharm.txt", ios::out);
        file << sinopharmVacc;
        file.close();
        cout << "\n\tTotal Sinopharm Vaccine : " <<sinopharmVacc;
        showPatintVaccinated();
        cout << "\n\n\nPress Any Key To Continue...";
        getch();
        goto A;
        break;


    }
    case 4:
        break;
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
        cout << "\nPress Any Key To Continue: ";
        getch();
        break;
    }

}

void CovidManagement::showDataVaccinated()
{
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Name: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << name;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "NID No.: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << nid;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Mobile No.: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << phone_no;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Gender: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << gender;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Age: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << age;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Profession: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << profession;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Vaccine Name: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << vaccine_name;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Dose: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << dose;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "\t  =====   VACCINATED  ======";
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "*********************************************\n ";

}
void CovidManagement::showPatintVaccinated()
{
    int count = 0;
    ifstream file;
    file.open("PatientData.dat");
    showDataVaccinated();
    file.close();
    cout<<"\t\n Succefully Vaccinated This Patient";
}

//***********USER*************

void CovidManagement::applyVaccine()
{
    fstream file;
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> APPLY FOR VACCINE <<--";
    cout << "\n\n\t\tEnter Name: ";
    cin>>name;

C:
    cout << "\n\n\t\tEnter NID No.: ";
    cin >> nid;
    if (nid.length() != 10)
    {
        cout << "\nInvalid NID Card Number";
        goto C;
    }

B:
    cout << "\n\n\t\tEnter Your Mobile Number: ";
    cin >> phone_no;
    if (phone_no.length() != 11)
    {
        cout << "\nInvalid Phone Number";
        goto B;
    }
    cout << "\n\n\t\tEnter Gender (M/F): ";
    cin >> gender;
    cout << "\n\n\t\tEnter Age: ";
    cin >> age;
    cout << "\n\n\t\tEnter Profession: ";
    cin>> profession;
    cout << "\n\n\t\tEnter Permanent Address: ";
    cin >> address;
    cout << "\n\n\t\tEnter Vaccine Name [AstraZeneca,Moderna & Sinopharm ]: ";
    cin >> vaccine_name;
    cout << "\n\n\t\tEnter Dose: ";
    cin >> dose;


    file.open("PatientData.dat", ios::app | ios::binary);
    file.write((char *)this, sizeof(CovidManagement));
    cout << "\n\nYOU HAVE SUCCESSFULLY VACCINATED :";
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
    system("cls");
}

void CovidManagement::showPatintDitails()
{

    int count = 0;
    string unid;
    ifstream file;
    file.open("PatientData.dat", ios::in | ios::binary);
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SEARCH DATA BY NID <<--";
    cout << "\n\n\t\tEnter NID No.: ";
    cin >> unid;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(CovidManagement));
    }
    while (!file.eof())
    {
        if (unid.compare(nid) == 0)
        {
            count++;
            showData();

        }
        file.read((char *)this, sizeof(CovidManagement));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
    system("cls");
}

void CovidManagement::showData()
{
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Name: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << name;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "NID No.: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << nid;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Mobile No.: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << phone_no;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Gender: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << gender;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Age: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << age;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Profession: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << profession;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Vaccine Name: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << vaccine_name;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Dose: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << dose;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "*********************************************\n ";

}

int main()
{
    system("color E");
    CovidManagement system;
    system.menu();
}
