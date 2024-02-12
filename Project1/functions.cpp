
#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <cstdio>
#include <filesystem>
#include <sstream>
#include <ctime>
#include "functions.h"
using namespace std;






void add_trips()
{
    bool found = false;
    do {
        cout << "------------------------------------------------------------------------------------------------------------------------";
        cout << "        Enter trip ID:" << endl;
        cin >> trip.id;
        cin.ignore();
        string store5;
        ifstream read5("trips\\id.txt");
        while (getline(read5, store5)) {
            if (store5 == trip.id) {
                found = false;
                SetConsoleTextAttribute(h, 4);
                cout << "This trip ID already exists, please try again." <<endl;
                SetConsoleTextAttribute(h, 7);
                break;
            }
            else {
                found = true;
            }
        }
    } while (!found);
    ofstream write3("trips\\id.txt", ios::app);
    write3 << trip.id << endl;
    write3.close();

    cout << "        Enter trip startdate:" << endl;
    getline(cin,trip.startdate);

    cout << "        Enter trip enddate:" << endl;
    getline(cin,trip.enddate);

    cout << "        Enter trip destination:" << endl;
    getline(cin, trip.destination);

    cout << "        Enter trip transportation:" << endl;

    getline(cin, trip.transportation);

    cout << "        Enter trip hotel:" << endl;
    getline(cin, trip.hotel);



    cout << "        Enter hotel adress:" << endl;
    getline(cin, trip.address);


    cout << "        Enter type of boarding" << endl;
    getline(cin, trip.boarding);

    cout << "        Enter maximum number of reservations:" << endl;
    cin >> trip.max_reservation;

    cout << "        Enter trip cost:" << endl;
    cin >> trip.cost;
    cin.ignore();


    trip.no_of_reservations = 0;


    ofstream write2;
    write2.open("trips\\" + trip.id + ".txt");
    write2 << trip.id << endl << trip.startdate << endl << trip.enddate << endl << trip.destination << endl << trip.transportation << endl << trip.hotel << endl << trip.address << endl << trip.boarding << endl << trip.cost << endl << trip.max_reservation << endl << trip.no_of_reservations;

    write2.close();


    cin.ignore();
    system("cls");
    admin_role();
}





void search_line(string file_name, int line_num, string& store) {
    ifstream read(file_name);
    for (int i = 1; i <= line_num; i++)
        getline(read, store);
    read.close();
}






//edit function//
void edit_function(string filename, string want_to_edit, string want_to_change_to)
{
    ifstream the_file_WTE(filename);
    ofstream write("felo.txt");

    string line;
    int new_line = 1;

    while (getline(the_file_WTE, line))
    {
        if (new_line != 1) write << endl;
        if (line == want_to_edit) {
            write << want_to_change_to;
        }
        else if (line.length() == 0)
            continue;


        else write << line;
        new_line++;
    }
    the_file_WTE.close();
    write.close();

    remove(filename.c_str());
    rename("felo.txt", filename.c_str());



}





void edit_trip_info() {
    int edit_no;
    string want_to_edit, want_to_change_to;
    bool correct = false;
    do {
        cout << "************Enter the id of the trip you want to edit:************** " <<endl;
        cin >> trip.id;
        cin.ignore();
        ifstream read4;
        read4.open("trips\\id.txt");
        string line;
        while (getline(read4, line)) {
            if (line == trip.id) correct = true;

        }
        read4.close();
        if (correct == false)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "                                 <<   invalid id, please enter another one   >>                                             " << endl;
            SetConsoleTextAttribute(h, 7);
        }
    } while (!correct);

    ifstream read3;
    read3.open("trips\\" + trip.id + ".txt");
    getline(read3, trip.id);
    getline(read3, trip.startdate);
    getline(read3, trip.enddate);
    getline(read3, trip.destination);
    getline(read3, trip.transportation);
    getline(read3, trip.hotel);
    getline(read3, trip.address);
    getline(read3, trip.boarding);
    read3 >> trip.cost;
    read3 >> trip.max_reservation;
    read3.close();



    bool edit = false;
    do
    {
        cout << "***********Choose the number of these choices you want to edit:**************" << endl << endl <<
            "      1-Start date:  " << trip.startdate << endl << endl <<
            "      2-End date:  " << trip.enddate << endl << endl <<
            "      3-Destination:  " << trip.destination << endl << endl <<
            "      4-Transportation: " << trip.transportation << endl << endl <<
            "      5-Hotel:  " << trip.hotel << endl << endl <<
            "      6-Address:  " << trip.address << endl << endl <<
            "      7-Type of boarding:  " << trip.boarding << endl << endl <<
            "      8-Maximum number of reservations:  " << trip.cost << endl << endl <<
            "      9-Cost:  " << trip.max_reservation << endl << endl;




        cin >> edit_no;
        cin.ignore();
        if (edit_no > 0 && edit_no <= 9)
        {
            edit = true;


            switch (edit_no)
            {
            case 1:
                want_to_edit = trip.startdate;
                break;

            case 2:
                want_to_edit = trip.enddate;
                break;

            case 3:
                want_to_edit = trip.destination;
                break;

            case 4:
                want_to_edit = trip.transportation;
                break;

            case 5:
                want_to_edit = trip.hotel;
                break;

            case 6:
                want_to_edit = trip.address;
                break;

            case 7:
                want_to_edit = trip.boarding;
                break;

            case 8:
                want_to_edit = to_string(trip.cost);
                break;

            case 9:
                want_to_edit = to_string(trip.max_reservation);
                break;
            }
            cout << "***************Enter what you want to change to:**************" << endl;

            getline(cin, want_to_change_to);

            edit_function("trips\\" + trip.id + ".txt", want_to_edit, want_to_change_to);



        }
        else cout << "***************enter an number from 1 to 9:*****************" << endl;


    } while (edit == false);

    cin.ignore();
    system("cls");
    admin_role();
}






void delete_folder()
{

    string want_to_edit, want_to_change_to = "";
    bool correct = false;
    do {
        cout << "*************enter the id of the trip you want to delete:************** " << endl;
        getline(cin, want_to_edit);

        trip.id = want_to_edit;
        ifstream read_ids;
        read_ids.open("trips\\id.txt");
        string line;
        while (getline(read_ids, line))
        {
            if (line == trip.id)
                correct = true;
        }
        read_ids.close();

        if (correct == false)
        {
            cout << "                                 <<   invalid id,please enter another one   >>                                             " << endl << endl;
        }
    } while (correct == false);






    string file = "trips\\" + trip.id + ".txt";

    edit_function("trips\\id.txt", want_to_edit, want_to_change_to);

    remove(file.c_str());

    cin.ignore();
    system("cls");
    admin_role();
}






void show_users()
{

    ifstream read_users;
    read_users.open("clients\\username.txt");
    string store_users;
    while (getline(read_users, store_users))
    {


        cout << endl << "    " << store_users << endl;
    }
    cin.ignore();
    system("cls");
    admin_role();
}





void show_reservations()
{
    ifstream read_reservations;
    read_reservations.open("trips\\reservations.txt");
    string store_reservations;
    while (getline(read_reservations, store_reservations))
    {
        cout << endl << "    " << store_reservations << endl;
    }
    cin.ignore();
    system("cls");
    admin_role();
}





void show_no_of_reservations()
{
    cout << " ********enter the id of the trip you want to show its number of reservations **********" << endl;
    getline(cin,trip.id);
    string store;
    search_line("trips\\" + trip.id + ".txt", 11, store);
    cout << endl << trip.id << ": "<< store << endl;
    

    cin.ignore();
    system("cls");
    admin_role();
}





void admin_role() {
    cout << "HELLO, ADMIN :)" << endl << endl;

    int choice;
    bool correct = false;
    do
    {




        cout << "**************choose the number of choice you want:************** " << endl << endl <<
            "       1-add trip " << endl << endl <<
            "       2-edit trip " << endl << endl <<
            "       3-delete trip " << endl << endl <<
            "       4-show all users " << endl << endl <<
            "       5-show all reservations " << endl << endl <<
            "       6-show number of reservations " << endl << endl <<
            "       7-logout " << endl << endl;

        cin >> choice;
        cin.ignore();


        if (choice >= 1 && choice <= 7)
        {
            correct = true;

            switch (choice)
            {
            case 1: {
                add_trips();
                break;
            }

            case 2: {

                edit_trip_info();
                break;
            }
            case 3: {

                delete_folder();
                break;

            }
            case 4: {
                show_users();
                break;
            }
            case 5: {
                show_reservations();
                break;

            }
            case 6: {
                show_no_of_reservations();
                break;
            }
            case 7: {
                logout();
                break;
            }
            }
        }
    } while (correct == false);
    
}


void open_reservations(int turn) {

    ifstream read("trips\\id.txt");
    while (getline(read, trip.id))
    {

        ifstream read2("trips\\" + trip.id + ".txt");

        getline(read2, trip.id);
        getline(read2, trip.startdate);
        getline(read2, trip.enddate);
        getline(read2, trip.destination);
        getline(read2, trip.transportation);
        getline(read2, trip.hotel);
        getline(read2, trip.address);
        getline(read2, trip.boarding);
        
        read2 >> trip.cost;
        read2 >> trip.max_reservation;

        read2 >> trip.no_of_reservations;

        read2.close();


        if (trip.no_of_reservations < trip.max_reservation) {

            cout << "\n" << "\t" << "\t" << trip.id << "\t" << trip.startdate << "\t" << trip.enddate << "\t" << trip.cost << endl
                << "\t" << "\t" << trip.destination << "\t" << trip.hotel << "\t" << trip.transportation << "\t" << trip.address << "\t" << trip.boarding << endl << endl;


        }
        else
            continue;
    }
    if (turn == 1) {
        cin.ignore();
        system("cls");
        client_form();
    }
    
}


void res_trip( ) {
    open_reservations(2);
    
    string store;
    cout << "***********Enter id********* ";
    cout << endl;
    getline(cin, trip.id);
    cout << endl;
    search_line("trips\\" + trip.id + ".txt", 11, store);

    trip.no_of_reservations = stoi(store);
    edit_function("trips\\" + trip.id + ".txt", to_string(trip.no_of_reservations++), to_string(trip.no_of_reservations));

    ofstream user_trip("clients\\" + user.username + ".txt", ios::app);
    user_trip << endl << trip.id;
    user_trip.close();

    ofstream file_res("trips\\reservations.txt", ios::app);
    file_res << user.username << ": " << trip.id<<endl;
    file_res.close();
    cout << "^^^^^^^^^^^^^^^^^^^^Successfully Reserved^^^^^^^^^^^^^^^^^^" << endl;
    
    cin.ignore();
    system("cls");
    client_form();
    
}






void change_res() {
    ifstream readTripid("clients\\" + user.username + ".txt");
    string storeTripid;
    int count = 0;
    while (getline(readTripid, storeTripid)) {
        count++;
        if (count <= 7)
            continue;
        else {
            ifstream read("trips\\" + storeTripid + ".txt");
            int i = 0;
            string storeTripinfo;
            while (getline(read, storeTripinfo)) {
                i++;

                if (i == 5)
                    cout << endl;

                else
                    cout << storeTripinfo<<'\t' ;
            }
            read.close();
        }
        cout << endl<<endl;
    }
    readTripid.close();
    
    cout << endl;
    
    cout << "PLease choose the trip id you want to change: " << endl;

    string change_id;
    getline(cin, change_id);

    edit_function("clients\\" + user.username + ".txt", change_id, "");
    delete_blink_lines("clients\\" + user.username + ".txt");

    edit_function("trips\\reservations.txt", user.username + ": " + change_id, "");
    delete_blink_lines("trips\\reservations.txt");

    cout << endl;
    string store_num_res;
    search_line("trips\\" + change_id + ".txt", 11, store_num_res);
    trip.no_of_reservations = stoi(store_num_res);
    edit_function("trips\\" + change_id + ".txt", to_string(trip.no_of_reservations--), to_string(trip.no_of_reservations));

    string trip_id;
    res_trip();

    cin.ignore();
    system("cls");
    client_form();

}





void login()
{
    string username;
    string password;
    bool founduser = false, foundpassword = false;
    string adminname, adminpassword;

    do {
        cout << "HELLO USER :)" << endl;
        cout << "===========================enter your name======================================" << endl;
        getline(cin, user.username);
        cout << endl << endl;

        ifstream read;
        read.open("clients\\" + user.username + ".txt");
        getline(read, username);
        getline(read, user.password);
        read.close();



        ifstream read2;
        read2.open("admin\\" + user.username + ".txt");
        getline(read2, adminname);
        getline(read2, adminpassword);
        read2.close();




        if (username == user.username)
        {
            founduser = true;
            do {
                cout << "==========================enter your password===================================" << endl;
                cout << endl;
                cin >> password;
                cout << endl << endl;
                if (password == user.password)
                {
                    foundpassword = true;
                    cout << "                          <<  login successfully >>\n";
                    cout << endl;
                    cin.ignore();
                    system("cls");
                    client_form();
                }
                else
                    cout << "                          xx wrong password xx\n";
                cout << endl;


            } while (foundpassword == false);

        }
        else if (user.username == adminname)
        {
            founduser = true;
            do {
                cout << "==========================enter your password=================================== " << endl;
                cout << endl;
                cin >> password;
                if (password == adminpassword)
                {
                    foundpassword = true;
                    cout << "             <<  login successfully >>\n";
                    cin.ignore();
                    system("cls");
                    
                    admin_role();
                    cout << endl;
                }
                else {
                    cout << "---------------------------please try again----------------------------\n ";
                    cout << endl;
                }

            } while (foundpassword == false);

        }
        else cout << "                      xx  invalid username  xx\n" << endl;

    } while (founduser == false);
    
}





void edit_clint_information() {

    string addres = "clients\\" + user.username + ".txt";
    string change_to, want_to_edit;
    int edit_number;


    ifstream read(addres);
    getline(read, user.username);
    getline(read, user.password);
    getline(read, user.phonenumber);
    getline(read, user.first_name);
    getline(read, user.last_name);
    getline(read, user.address);
    getline(read, user.email);
    read.close();


    cout << "    username: " << user.username << endl;
    cout << "1 - password: " << user.password << endl;
    cout << "2 - phone number: " << user.phonenumber << endl;
    cout << "3 - first name: " << user.first_name << endl;
    cout << "4 - last name: " << user.last_name << endl;
    cout << "5 - address: " << user.address << endl;
    cout << "6 - email: " << user.email << endl;
    cout << endl;
    
    

    do {
        cout << "select a number: ";
        cin >> edit_number;
        cout << endl;
        cin.ignore();
        if (edit_number > 6)
            cout << "enter a number from 1 to 6" << endl;
        else
            break;

    } while (true);

        switch (edit_number)
        {
        
        case 1:
            
            cout << "what you want to change it to ?\n";
            getline(cin, change_to);
            edit_function(addres, user.password, change_to);
            break;
        case 2:
            do {
                cout << "what you want to change it to ?\n";
                getline(cin, change_to);
                char check[10] = { '0','1','2','3','4','5','6','7','8','9' };
                int verify = 0;
                if (change_to.length() == 11) {
                    for (int i = 0; i < change_to.length(); i++) {
                        for (int j = 0; j <= 9; j++) {
                            if (change_to[i] == check[j]) {
                                verify++;
                            }
                        }
                    }
                    if (verify != change_to.length())
                        cout << "you must enter only numbers" << endl;

                    else
                        break;

                }
                else
                    cout << "A phone number must contain 11 number, please try again" << endl;
            } while (true);
            edit_function(addres, user.phonenumber, change_to);
            break;
        case 3:
            cout << "what you want to change it to ?\n";
            getline(cin, change_to);
            edit_function(addres, user.first_name, change_to);
            break;
        case 4:
            cout << "what you want to change it to ?\n";
            getline(cin, change_to);
            edit_function(addres, user.last_name, change_to);
            break;
        case 5:
            cout << "what you want to change it to ?\n";
            getline(cin, change_to);
            edit_function(addres, user.address, change_to);
            break;
        case 6:
            do {
                cout << "what you want to change it to ?\n";
                getline(cin, change_to);
                string mail = "@gmail.com";
                string mail2 = "@hotmail.com";
                string mail3 = "@i_cloud.com";
                string mail4 = "@yahoo.com";
                if (change_to.find(mail) != string::npos || change_to.find(mail2) != string::npos || change_to.find(mail3) != string::npos || change_to.find(mail4) != string::npos) {
                    break;
                }
                else
                    cout << "Please enter a valid e_mail... for example @xxxxx.com" << endl;
            } while (true);
            edit_function(addres, user.email, change_to);
            break;
        
        }



    cout << "changed successflly\n";

    cin.ignore();
    system("cls");
    client_form();
}




void time_function(int& day,int& month, int& year) {
    
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);
    day = newtime.tm_mday;
    month = newtime.tm_mon + 1;
    year = newtime.tm_year + 1900;

    
}


void cut_startdate(int& trip_day, int& trip_month, int& trip_year, string trip_id) {
    string temp_date;
    search_line("trips\\" + trip_id + ".txt", 2, temp_date);
    stringstream stream(temp_date);
    string date_store;
    getline(stream, date_store, ' ');
    trip_day = stoi(date_store);
    getline(stream, date_store, ' ');
    trip_month = stoi(date_store);
    getline(stream, date_store, ' ');
    trip_year = stoi(date_store);
    
}










void cancellation_date(int& total_days, string id)
{
    int trip_day, trip_month, trip_year;
    int persent_day, persent_month, persent_year;
    int var1 = 0, var2 = 0;
    total_days = 0;

    time_function(persent_day, persent_month, persent_year);
    cut_startdate(trip_day, trip_month, trip_year, id);

    int monthday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };


    if (trip_year - persent_year == 0)

    {
        if (persent_month == trip_month)
        {
            total_days = trip_day - persent_day + 1;
        }


        else
        {
            for (int i = persent_month; i < trip_month; i++)
            {

                total_days += monthday[i];

            }
            
            total_days = total_days + trip_day - persent_day + 1;
        }




    }
    else if (trip_year - persent_year != 0)
    {
        if (persent_month == 12 && trip_month == 1)

            total_days = 31 - persent_day + trip_day;

        else if (persent_month < 12 && trip_month == 1)
        {

            for (int i = persent_month; i <= 12; i++)
            {
                total_days += monthday[i];

            }
            total_days += trip_day - persent_day;
        }
        else if (persent_month == 12 && trip_month > 1)
        {
            for (int i = 1; i < trip_month; i++)

            {
                total_days += monthday[i];
            }
            total_days += (31 - persent_day) + trip_day;
        }
        else if (persent_month < 12 && trip_month>1)
        {
            

            for (int i = persent_month; i <= 12; i++)
            {
                var1 += monthday[i];
            }
            for (int i = 1; i < trip_month; i++)
            {
                var2 += monthday[i];
            }

            total_days = var1 + var2 - persent_day + trip_day;
        }

    }
    

}





void delete_blink_lines(string path) {
    ofstream write("temp.txt");
    string line;
    ifstream blink_lines(path);
    int new_line = 1;
    while (getline(blink_lines, line)) {

        if (line.length() == 0)
            continue;

        else {
            if (new_line != 1)
                write << endl;
            write << line;
        }
        new_line++;
    }

    write.close();
    blink_lines.close();
    remove(path.c_str());
    rename("temp.txt", path.c_str());
}





void cancel_reservation() {
    string store;
    ifstream get_the_last_trip("clients\\" + user.username + ".txt");
    int max = 0;

    while (getline(get_the_last_trip, store)) {
        max++;
        if (max <= 7) continue;
        else {
            cout << store << endl;
        }
    }
    get_the_last_trip.close();

    

    if (max > 7) {
        int total_days;
        string old_trip;
        cout << "enter the trip id you want to cancel: ";

        getline(cin, old_trip);

        cancellation_date(total_days, old_trip);

        if (total_days > 7) {
            cout << "\n\tthis trip is canceled successfully \t";
            cout << endl;
            edit_function("clients\\" + user.username + ".txt", old_trip, "");
            delete_blink_lines("clients\\" + user.username + ".txt");
            string store_num_res;
            search_line("trips\\" + old_trip + ".txt", 11, store_num_res);
            trip.no_of_reservations = stoi(store_num_res);
            edit_function("trips\\" + old_trip + ".txt", to_string(trip.no_of_reservations--), to_string(trip.no_of_reservations));
            edit_function("trips\\reservations.txt", user.username +": "+ old_trip, "");
            delete_blink_lines("trips\\reservations.txt");

        }

        else
        {
            char ch;
            cout << "\n\tsorry this trip can't be cancelled due to trip in next 7 days \n\n ";
            cout << "\tdays left  = " << total_days;
            cout << "try again\n";
            cout << "if you want to try again enter y and enter n to exit: ";
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
                cancel_reservation();
            else {
                system("cls");
                client_form();
            }
        }
    }

    else
        cout << "\nyou hadn't reserve a trip yet\n";

    cin.ignore();
    system("cls");
    client_form();
}




void readUser() {
    string confirmation_password;
    bool userCheck = false;
    do {
        string store_username;
        string store_adname;
        cout << "User name: ";
        getline(cin, user.username);
        search_line("admin\\" + user.username + ".txt", 1, store_adname);
        ifstream read("clients\\username.txt");
        while (getline(read, store_username)) {
            if (user.username == store_username||user.username==store_adname) {
                userCheck = true;
                break;
            }
            else
                userCheck = false;
        }
        if (userCheck) {
            SetConsoleTextAttribute(h, 4);
            cout << "This user name is already exist, please try again" << endl;
            SetConsoleTextAttribute(h, 7);
        }
    } while (userCheck);

    cout << "Password: ";
    getline(cin, user.password);

    do {
        cout << "confirmation password: ";
        getline(cin, confirmation_password);
        if (confirmation_password == user.password) {
            break;
        }
        else {
            SetConsoleTextAttribute(h, 4);
            cout << "You must enter the same password twice in order to confirm it." << endl;
            SetConsoleTextAttribute(h, 7);
        }
    } while (true);


    do {
        cout << "Phone number: ";
        getline(cin, user.phonenumber);
        char check[10] = { '0','1','2','3','4','5','6','7','8','9' };
        int verify = 0;
        if (user.phonenumber.length() == 11) {
            for (int i = 0; i < user.phonenumber.length(); i++) {
                for (int j = 0; j <= 9; j++) {
                    if (user.phonenumber[i] == check[j]) {
                        verify++;
                    }
                }
            }
            if (verify != user.phonenumber.length()) {
                SetConsoleTextAttribute(h, 4);
                cout << "you must enter only numbers" << endl;
                SetConsoleTextAttribute(h, 7);
            }
            else {
                break;
            }
        }
        else {
            SetConsoleTextAttribute(h, 4);
            cout << "A phone number must contain 11 number, please try again" << endl;
            SetConsoleTextAttribute(h, 7);
        }
    } while (true);

    cout << "First name: ";
    getline(cin, user.first_name);

    cout << "Last name: ";
    getline(cin, user.last_name);

    cout << "Address: ";
    getline(cin, user.address);

    do {
        cout << "E_mail: ";
        getline(cin, user.email);
        string mail = "@gmail.com";
        string mail2 = "@hotmail.com";
        string mail3 = "@i_cloud.com";
        string mail4 = "@yahoo.com";
        if (user.email.find(mail) != string::npos || user.email.find(mail2) != string::npos || user.email.find(mail3) != string::npos || user.email.find(mail4) != string::npos) {
            break;
        }
        else {
            SetConsoleTextAttribute(h, 4);
            cout << "Please enter a valid e_mail... for example @xxxxx.com" << endl;
            SetConsoleTextAttribute(h, 7);
        }
    } while (true);
    SetConsoleTextAttribute(h, 6);
    cout << "HELLO, " << user.username << "!" << endl;
    SetConsoleTextAttribute(h, 7);

    ofstream write("clients\\" + user.username + ".txt");
    write << user.username << endl << user.password << endl << user.phonenumber << endl << user.first_name << endl << user.last_name << endl << user.address << endl << user.email;
    write.close();

    ofstream writeuser("clients\\username.txt", ios::app);
    writeuser << user.username << endl;
    writeuser.close();
    cin.ignore();
    system("cls");
    first_form();
}



void show_reserved_trip_for_user() {
    ifstream show_trips("clients\\" + user.username + ".txt");
    int counter = 0;
    while (getline(show_trips, trip.id)) {
        counter++;

        if (counter <= 7) {

            continue;
        }
        else {

            string trip_details;
            ifstream open_trip("trips\\" + trip.id + ".txt");

            int inside_counter = 0;
            while (getline(open_trip, trip_details)) {
                inside_counter++;
                cout << trip_details << "\t";
                if (inside_counter == 5)
                    cout << endl;
                
                if (inside_counter == 9) break;

            }
            
            cout << endl<<endl;
        }
        
    }
    cin.ignore();
    system("cls");
    client_form();
    
}




void client_form() {
    
    cout << "hello user\n\n";
    cout << "1 - open reservation\n" <<
        "2 - reserve trip\n" <<
        "3 - change reservation\n" <<
        "4 - see the history of your reserved trips\n" <<
        "5 - cancel reservation\n" <<
        "6 - edit your information\n" <<
        "7 - logout\n" << endl;

    
    int user_2nd_choice;
    do {
        cout << "enter a number of the function you wnat to use: ";
        cin >> user_2nd_choice;
        cin.ignore();
        if (user_2nd_choice > 7 || user_2nd_choice == 0)
            cout << "you must enter a number from 1 to 6, please try again\n\n";
        else
            break;
    } while (true);


    string id;

    switch (user_2nd_choice)
    {
    case 1:
        open_reservations(1);
        break;
    case 2:
        res_trip();
        break;
    case 3:
        change_res();
        break;
    case 4:
        show_reserved_trip_for_user();
        break;
    case 5:
        cancel_reservation();
        break;
    case 6:
        edit_clint_information();
        break;
    case 7:
        logout();
        break;
    }

}




void first_form() {
    string username;
    cout << "hello to travel agendy system\n\n";


    cout << "1 - Register an account\n" <<
        "2 - login to your account\n\n";

    int user_1st_choice;
    
    do {
        cout << "type 1 to regist and 2 to login: ";
        cin >> user_1st_choice;
        cin.ignore();
        if (user_1st_choice == 1 || user_1st_choice == 2)
           break;
        else
            cout << "enter 1 or 2\n";
    } while (true);



    switch (user_1st_choice)
    {
    case 1:
        
        system("cls");


        readUser();
        break;
    case 2:
        
        system("cls");


        login();
        break;
    }

}

void logout() {
    first_form();
}