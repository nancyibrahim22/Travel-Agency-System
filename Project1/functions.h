#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <string>
#include <stdio.h>
const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

struct User {
    string username;
    string password;
    string phonenumber;
    string first_name;
    string last_name;
    string address;
    string email;

};
extern User user;

struct trips {
    string id;
    string startdate;
    string enddate;
    string destination;
    string transportation;
    string hotel;
    string address;
    string boarding;
    int cost;
    int max_reservation;
    int no_of_reservations;
    
};
extern trips trip;

void cut_startdate(int& day, int& month, int& year, string trip_id);
void time_function(int& day, int& month, int& year);
void cancel_reservation();
void open_reservations(int turn);
void res_trip();
void first_form();
void search_line(string, int, string&);
void admin_role();
void add_trips();
void show_users();
void edit_clint_information();
void edit_function(string filename, string want_to_edit, string want_to_change_to);
void show_reserved_trip_for_user();
void change_res();

void edit_clint_information();
void cancellation_date(int& total_days, string id);
void delete_blink_lines(string path);
void show_reserved_trip_for_user();
void readUser();

void client_form();

void login();
void delete_folder();
void show_users();
void show_reservations();
void show_no_of_reservations();




#endif 

