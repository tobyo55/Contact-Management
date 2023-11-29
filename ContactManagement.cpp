#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include<algorithm>
using namespace std;

struct Contact
{
    string fname;
    string lname;
    string phone_num;
    bool isFavorite;
};

string fname, lname, phone_num;

void addContact();
void searchContact();
void deleteContact();
void markAsFavorite();
void displayFavorites();
void editContact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);

int main()
{
    short int choice;
    while (true)
    {
        system("cls");
        system("color 0A");
        cout << "\n\n\n\t\t\tContact Management";
        cout << "\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Delete Contact\n\t4. Mark as Favorite\n\t5. Display Favorites\n\t6. Edit Contact\n\t7. Help\n\t8. Exit\n\t> ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            deleteContact();
            break;
        case 4:
            markAsFavorite();
            break;
        case 5:
            displayFavorites();
            break;
        case 6:
            editContact();
            break;
        case 7:
            help();
            break;
        case 8:
            self_exit();
            break;
        default:
            cout << "\n\n\tInvalid Input!\n";
            cout << "\n\tPress Any Key to Continue...";
            getch();
        }
    }

    return 0;
}

void self_exit()
{
    system("cls");
    cout << "\n\n\n\t\tThank You for Using!\n\n\n\n\n";
    exit(1);
    getch();
}

void help()
{
    system("cls");
    cout << "\n\n\t\t\tContact Management - Help\n";
    cout << "\n\t1. Add Contact: Allows you to add a new contact to the system.";
    cout << "\n\t2. Search Contact: Lets you search for a contact by first name or last name.";
    cout << "\n\t3. Delete Contact: Allows you to delete a contact from the system.";
    cout << "\n\t4. Mark as Favorite: Marks a contact as a favorite.";
    cout << "\n\t5. Display Favorites: Shows a list of all contacts marked as favorites.";
    cout << "\n\t6. Edit Contact: Allows you to edit the information of an existing contact.";
    cout << "\n\t7. Help: Displays this help menu.";
    cout << "\n\t8. Exit: Exits the contact management system.";
    cout << "\n\n\tNote: To exit the program, choose option 8 (Exit) in the main menu.\n";
    cout << "\n\tPress Any Key to Continue...";
    getch();
}

void addContact()
{
    ofstream phone("number.txt", ios::app);
    system("cls");

    Contact newContact;

    cout << "\n\n\tEnter First Name: ";
    cin >> newContact.fname;
    cout << "\n\tEnter Last Name: ";
    cin >> newContact.lname;
    cout << "\n\tEnter 11-Digit Phone Number: ";
    cin >> newContact.phone_num;
    newContact.isFavorite = false;

    if (check_digits(newContact.phone_num) == true)
    {
        if (check_numbers(newContact.phone_num) == true)
        {
            if (phone.is_open())
            {
                phone << newContact.fname << " " << newContact.lname << " " << newContact.phone_num << " " << (newContact.isFavorite ? "1" : "0") << endl;
                cout << "\n\tContact Saved Successfully!\n\n\n\n\n";
                getch();
            }
            else
            {
                cout << "\n\tError Opening File!\n\n\n\n\n";
                getch();
            }
        }
        else
        {
            cout << "\n\tA Phone Number Must Contain Numbers Only!\n\n\n\n\n";
            getch();
        }
    }
    else
    {
        cout << "\n\tA Phone Number Must Contain 11 Digits!\n\n\n\n\n";
        getch();
    }
    phone.close();
}

void searchContact()
{
    bool found = false;
    ifstream myfile("number.txt");
    string keyword;
    cout << "\n\tEnter Name to Search: ";
    cin >> keyword;
    while (myfile >> fname >> lname >> phone_num)
    {
        if (keyword == fname || keyword == lname)
        {
            system("cls");
            cout << "\n\n\n\t\tContact details...";
            cout << "\n\n\tFirst Name: " << fname;
            cout << "\n\tLast Name: " << lname;
            cout << "\n\tPhone Number: " << phone_num;
            found = true;
            break;
        }
    }
    if (found == false)
        cout << "\n\tNo Such Contact Found!\n\n\n\n\n";
    getch();
}

void deleteContact()
{
    ifstream inFile("number.txt");

    cout << "\n\tContacts available for deletion:\n";

    while (inFile >> fname >> lname >> phone_num)
    {
        cout << "\t" << fname << " " << lname << " " << phone_num << endl;
    }

    inFile.close();

    string contactToDelete;
    cout << "\n\tEnter Name To Delete: ";
    cin >> contactToDelete;

    inFile.open("number.txt");
    ofstream tempFile("temp.txt");

    bool found = false;

    while (inFile >> fname >> lname >> phone_num)
    {
        if (contactToDelete != fname && contactToDelete != lname)
        {
            tempFile << fname << " " << lname << " " << phone_num << " " << (phone_num == "1" ? "1" : "0") << endl;
        }
        else
        {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove("number.txt");
    rename("temp.txt", "number.txt");

    if (found)
    {
        cout << "\n\tContact Deleted Successfully!\n\n\n\n\n";
    }
    else
    {
        cout << "\n\tNo Such Contact Found for Deletion!\n\n\n\n\n";
    }
    getch();
}



void markAsFavorite()
{
    ifstream inFile("number.txt");
    ofstream tempFile("temp.txt");

    cout << "\n\tContacts Available for Marking as Favorite:\n";

    bool found = false;

    while (inFile >> fname >> lname >> phone_num)
    {
        cout << "\t" << fname << " " << lname << " " << phone_num << endl;
        tempFile << fname << " " << lname << " " << phone_num << " " << (phone_num == "1" ? "1" : "0") << endl;
        found = true;
    }

    inFile.close();
    tempFile.close();

    if (!found)
    {
        cout << "\n\tNo Contacts to Mark as Favorite!\n\n\n\n\n";
        getch();
        return;
    }

    string contactToFavorite;
    cout << "\n\tEnter Name to Mark as Favorite: ";
    cin >> contactToFavorite;

    inFile.open("temp.txt");
    ofstream outFile("number.txt");

    found = false;

    while (inFile >> fname >> lname >> phone_num)
    {
        if (contactToFavorite == fname || contactToFavorite == lname)
        {
            outFile << fname << " " << lname << " " << phone_num << " " << "1" << endl;
            found = true;
        }
        else
        {
            outFile << fname << " " << lname << " " << phone_num << " " << "0" << endl;
        }
    }

    inFile.close();
    outFile.close();

    remove("temp.txt");

    if (found)
    {
        cout << "\n\tContact Marked as Favorite Successfully!\n\n\n\n\n";
    }
    else
    {
        cout << "\n\tNo Such Contact Found!\n\n\n\n\n";
    }
    getch();
}

void displayFavorites()
{
    ifstream inFile("number.txt");

    bool found = false;

    while (inFile >> fname >> lname >> phone_num)
    {
        if (phone_num == "1")
        {
            cout << "\n\tFavorite Contact: " << fname << " " << lname << " " << phone_num << endl;
            found = true;
        }
    }

    inFile.close();

    if (!found)
    {
        cout << "\n\tNo Favorite Contacts!\n\n\n\n\n";
    }
    getch();
}



void editContact()
{
    ifstream inFile("number.txt");
    vector<Contact> contacts;

    while (inFile >> fname >> lname >> phone_num)
    {
        Contact contact;
        contact.fname = fname;
        contact.lname = lname;
        contact.phone_num = phone_num;
        contacts.push_back(contact);
    }

    inFile.close();

    if (contacts.empty())
    {
        cout << "\n\tNo Contacts to Edit!\n\n\n\n\n";
        getch();
        return;
    }

    cout << "\n\tContacts Available for Editing:\n";
    for (int i = 0; i < contacts.size(); ++i)
    {
        cout << "\t" << i + 1 << ". " << contacts[i].fname << " " << contacts[i].lname << " " << contacts[i].phone_num << endl;
    }

    int editChoice;
    cout << "\n\tChoose the Contact to Edit: ";
    cin >> editChoice;

    if (editChoice >= 1 && editChoice <= contacts.size())
    {
        cout << "\n\tEditing Contact: " << contacts[editChoice - 1].fname << " " << contacts[editChoice - 1].lname << " " << contacts[editChoice - 1].phone_num << endl;

        cout << "\n\tEnter New First Name: ";
        cin >> contacts[editChoice - 1].fname;
        cout << "\tEnter New Last Name: ";
        cin >> contacts[editChoice - 1].lname;
        cout << "\tEnter New Phone Number: ";
        cin >> contacts[editChoice - 1].phone_num;

        ofstream outFile("number.txt");
        for (const auto &contact : contacts)
        {
            outFile << contact.fname << " " << contact.lname << " " << contact.phone_num << " " << (contact.isFavorite ? "1" : "0") << endl;
        }
        outFile.close();

        cout << "\n\tContact Edited Successfully!\n\n\n\n\n";
        getch();
    }
    else
    {
        cout << "\n\tInvalid Choice!\n\n\n\n\n";
        getch();
    }
}

bool check_digits(string x)
{
    if (x.length() == 11)
        return true;
    else
        return false;
}

bool check_numbers(string x)
{
    bool check = true;

    for (int i = 0; i < x.length(); i++)
    {
        if (!(int(x[i]) >= 48 && int(x[i]) <= 57))
        {
            check = false;
            break;
        }
    }

    if (check == true)
        return true;
    if (check == false)
        return false;
}
