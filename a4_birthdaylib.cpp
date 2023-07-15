//Isabelle Kwan
//301542393
//itk1
#include "a4_birthdaylib.hpp"

Birthday* create_Birthday(short year, short month, short day,
                            string name, string knownFor){
    Birthday* newBDay = new Birthday;
    //only access memeber values if memory is successfully allocated
    if (newBDay != NULL) {
        newBDay->year = year;
        newBDay->month = month;
        newBDay->day = day;
        //create a deep copy of name, dont' forget size is lenght+1
        newBDay->name = name.c_str();
        //create a deep copy of knownFor, don't forget size is length+1
        newBDay->knownFor = knownFor.c_str();
    }
    return newBDay;
}

void delete_Birthday(Birthday* person){
    if(person!=NULL){
        delete person;
    }
}   

void print_Birthday(Birthday* person, ostream& os){
    cout << person->year << "-" << person->month << "-" << person->day << endl
    << person->name << endl << person->knownFor;
}

int compareBirthdaysByMD(const Birthday* p1, const Birthday* p2){
    const Birthday* ptr1 = (Birthday*) p1;
    const Birthday* ptr2 = (Birthday*) p2;

    if (ptr1->month != ptr2->month){
        return (ptr1->month - ptr2->month);
    }
    return (ptr1->day - ptr2->day);
}