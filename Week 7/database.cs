//--------------------------------------------------------------------
//
//  Laboratory 11, In-lab Exercise 1                     database.cs
//
//  (Shell) Indexed accounts database program
//
//--------------------------------------------------------------------

// Builds a binary search tree index for the account records in the
// text file accounts.dat.

#include <iostream>
#include <fstream>
#include "BSTree.cpp"

using namespace std;

//--------------------------------------------------------------------
//
// Declarations specifying the accounts database
//

const int nameLength      = 11;   // Maximum number of characters in
                                  //   a name
const long bytesPerRecord = 38;   // Number of bytes used to store
                                  //   each record in the accounts
                                  //   database file

struct AccountRecord
{
    int acctID;                   // Account identifier
    char firstName[nameLength],   // Name of account holder
         lastName[nameLength];
    double balance;               // Account balance
};

//--------------------------------------------------------------------
//
// Declaration specifying the database index
//

struct IndexEntry
{
    int acctID;              // (Key) Account identifier
    long recNum;             // Record number

    int key () const
        { return acctID; }   // Return key field
};

//--------------------------------------------------------------------

void main ()
{
    ifstream acctFile ("accounts.dat");   // Accounts database file
    AccountRecord acctRec[100];                // Account record
    BSTree<IndexEntry,int> index;         // Database index
    IndexEntry entry;                     // Index entry
    int searchID;                         // User input account ID
    long recNum = 0;                          // Record number

    // Iterate through the database records. For each record, read the
    // account ID and add the (account ID, record number) pair to the
    // index.
    while(acctFile.good()) 
    {
     acctFile >> entry.acctID; 
     entry.recNum = recNum; 
     index.insert(entry); 
     acctFile >> acctRec[recNum].firstName >>acctRec[recNum].lastName 
              >>acctRec[recNum].balance; 
     recNum++; 
    }
    // Output the account IDs in ascending order.
    index.writeKeys(); 

    // Clear the status flags for the database file.

    acctFile.clear();

    // Read an account ID from the keyboard and output the
    // corresponding record.
    while(cin.good())
      {
       cout >>"Enter account ID :";
       cin >> searchID; 
       index.retrieve(searchID, entry); 
       cout << acctRec[entry.recNum].firstName <<acctRec[entry.recNum].lastName 
            << acctRec[entry.recNum].balance;    
      }

}
