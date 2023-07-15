//Isabelle Kwan
//301542393
//itk1
#include "a4_birthdayBST.hpp"
#include "a4_birthdaylib.hpp"

int main(){ //fancy header
    cout<<"⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂"<<
    "⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂"<<endl;
    cout<<"⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳ Find Famous Birthdays! ⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳"<<endl;
    cout<<"⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂"<<
    "⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂"<<endl;
    cout<<"⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳ Isabelle Kwan ⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳"<<endl;
    cout<<"⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂  301542339 "<<
    "⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂⁂"<<endl;
    cout<<"⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳ itk1@sfu.ca ⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳"<<endl;

    //initialize variables
    int choice=-1;
    int fileloaded=-1;
    //initialize BST of birthday structs
    BirthdayBST* birthdaytree = new BirthdayBST;
    //file name variable
    string filename = "";

    do{
        //option menu 
        cout<<"⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳"<<
        "⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳⨳"<<endl;
        cout<<"Press 1-6 for the following options and then enter:"<<endl;
        cout<<"1) to load a birthday file."<<endl;
        cout<<"2) to list birthdays sorted by Month-Day."<<endl;
        cout<<"3) to look up a birthday"<<endl;
        cout<<"4) to add a birthday"<<endl;
        cout<<"5) to save a birthday file"<<endl;
        cout<<"6) to terminate the program"<<endl;

        cout<<"Option: ";
        cin>>choice;

        if(choice==6){ //terminate program 
            cout<<"Thank you and have a nice day!\n";
        }

        //check for invalid input
        while (choice != 1 && choice != 2 
            && choice != 3 && choice != 4 && choice !=5 && choice!=6){
            cout<<"Invalid input. Try again."<<endl;
            cout<<"Press 1-6 for the following options and then enter: "<<endl;
            cin>>choice;
        } 

        if(choice == 1){ //when user types one, load file
            cout<<"Enter full name of the birthday file"<<
            " (with extension): "<<endl;
            cin>>filename; // save user file to file name

            fstream myfile; //create a file pointer
            myfile.open(filename); //open file
            short year,month,day; //initialize date variables
            string name,knownFor; //initialize character variables

            //check for previous file
           if(fileloaded==1 && myfile.good()){
                delete birthdaytree; //delete old file if new file is loaded
                birthdaytree = new BirthdayBST;
           }

            //check if file doesn't exist and  keep previous file
            if(!myfile.good() && fileloaded == 1){
                cout<<"Error opening the file. Keeping previous file."<<endl;
            }
            //check if new file doesn't exist, error
            else if(!myfile.good()){
                cout<<"Error opening the file. Check if it is available\n";
            }
            else{ //read file
                while(myfile.eof()==0){ //while file still has lines
                    //look for year,month,day in file
                    char skip;
                    string skipline; //store banner characters
                    myfile>>year>>skip>>month>>skip>>day;
                    getline(myfile>>ws,name);
                    getline(myfile>>ws,knownFor);
                    getline(myfile>>ws,skipline);

                    //check if new line has no content
                    if(name != "" && knownFor != ""){ 
                        //call function to make structs and store them in BST
                        Birthday* people = create_Birthday(year, month, day,
                                                            name, knownFor);
                        birthdaytree->insertNode(people);
                    } 
                    name = "";
                    knownFor = ""; //reinitialize variables
                } 
                myfile.close(); //close file
                int size = birthdaytree->getSize(); //print size of BST
                cout<<size<<" entries read."<<endl;
                //update load file variable
                fileloaded = 1;
            }
        }
        
        if(fileloaded == -1 and choice!=6){ //make sure file is loaded first
            cout<<"Please load a file before choosing other options."<<endl;
        }

        if(choice == 2 && fileloaded == 1){ //option 2
            //print birthdays
            birthdaytree->inOrderPrint(cout);            
        }

        if(choice == 3 && fileloaded == 1){ //option 3
            //initialize variables
            int usermonth=0,userday=0;
            cout<<"What is the month? (input 1-12 and press enter) ";
            cin>>usermonth; //get month input
            cout<<"What is the day? (input 1-31 and press enter) ";
            cin>>userday; //get day input

            cout<<"You have entered "<<usermonth<<"-"<<userday<<endl;

            // if birthday doesn't exist
            if(birthdaytree->findNodeByMD(usermonth, userday)==NULL){ 
                cout<<"No such birthday on record."<<endl;
            }else{ // birthday is found -> print
            birthdaytree->printAllNodeWithMatchingMD(usermonth,userday,cout);
            }
        }

        if(choice == 4 && fileloaded == 1){ //add a birthday (option 4)
            short month,day,year;
            string name,knownFor;
            cout<<"What is the year (input a 4 digit year)? ";
            cin>>year;
            cout<<"What is the month (input 1-12 and press enter) ";
            cin>>month;
            cout<<"What is the day (input 1-31 and press enter) ";
            cin>>day;
            cout<<"What is the name of the person? ";
            getline(cin>>ws,name);
            cout<<"What is this person known for? ";
            getline(cin>>ws,knownFor);

            //check if it already exists
            if(birthdaytree->findNodeByYMDN(year,month,day,name)!=NULL){
                cout<<"An entry with the same birthday and name already"
                <<" exists.Nothing added."<<endl;
            }else{ //add the birthday to BST
                Birthday* people=create_Birthday(year,month,day,name,knownFor);
                birthdaytree->insertNode(people);
                cout<<"Birthday added."<<endl;
            }
        }
        if(choice == 5 && fileloaded == 1){ //save to a file
            string savefile = "";
            cout<<"Input the name of the file you would like to save to: ";
            getline(cin>>ws,savefile);

            //write to file
            ofstream newfile;
            newfile.open(savefile);

            //print birthdays to new file
            birthdaytree->inOrderPrint(newfile);

            //display how many entries were added
            cout<<birthdaytree->getSize()<<" entries have been saved."<<endl;

            newfile.close();
        }

    }while(choice!=6);
    //free BST
    delete birthdaytree;
}