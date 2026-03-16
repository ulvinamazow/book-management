#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


class Book{
    private:
        string bookName;
        string bookAuthor;
        int bookYear;
        int bookID;
    public:
        Book(string name="", string author="", int year=0, int id=0) {
            bookName=name;
            bookAuthor=author;
            bookYear=year;
            bookID=id;
        }

    void setName(const string& name) { bookName = name; }
    void setAuthor(const string& author) { bookAuthor = author; }
    void setYear(int year) { bookYear = year; }
    void setID(int id) { bookID = id; }

    string getName() const { return bookName; }
    string getAuthor() const { return bookAuthor; }
    int getYear() const { return bookYear; }
    int getID() const { return bookID; }
    
};

vector<Book> library;
const string FILE_NAME= "books.txt";

void loadFromFile() {
    ifstream file(FILE_NAME);
    if (!file.is_open()) 
    {
        return;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string name, author, yearStr, idStr;

        getline(ss, name, ',');
        getline(ss, author, ',');
        getline(ss, yearStr, ',');
        getline(ss, idStr, ',');
    
        int year = stoi(yearStr);
        int id = stoi(idStr);

        library.push_back(Book(name, author, year, id));
    }
    file.close();
}

void saveToFile() {
    ofstream file(FILE_NAME);
    if (!file.is_open())
    {
        cerr<<"Xeta:Fayl acilmadi!"<<endl;
        return;
    }

    for (const auto& b : library)
    {
        file<< b.getName() << ","
        << b.getAuthor() << ","
        << b.getYear() << ","
        << b.getID() << "\n";
    }
    file.close();
}


bool idExists(int id) {
    for (const Book& b : library)
    {
        if (b.getID() == id)
        {
            return true;
        }
    }
    return false;
}

void addBook() {
    Book kitab;
    string ad, muellif;
    int il, id; 

    cout<<"kitab adini yazin: ";
    getline(cin, ad);
    kitab.setName(ad);

    cout<<"muellifi qeyd edin: ";
    getline(cin, muellif);
    kitab.setAuthor(muellif);

    cout<<"nesr ilini yazin: ";
    cin>>il;
    kitab.setYear(il);


    while (true)
    {
        cout<<"Kitab ID-ni yazin: ";
        cin>>id;

        if (!idExists(id))
        {
            break;
             
        }
        cout<<"Bu ID artiq movcuddur. Basqa ID daxil edin.\n"; 
    }
    
    kitab.setID(id);

    cin.ignore();

    library.push_back(kitab);

    saveToFile();

    cout<<"Kitab elave edildi.\n";
}

void showBooks() {

    if (library.empty())
    {
        cout<<"Kitab yoxdur.\n";
        return;
    }

    for(size_t i=0;i<library.size();i++) {
        cout<<"Kitab "<<i+1<<endl;
        cout<<"Ad:"<<library[i].getName()<<endl;
        cout<<"Muellif:"<<library[i].getAuthor()<<endl;
        cout<<"Il:"<<library[i].getYear()<<endl;
        cout<<"ID:"<<library[i].getID()<<endl;
        cout<<"--------------------------------------\n";
    }
    
}

void searchBook() {
    string ad;
    bool tapildi=false;

    cout<<"Axtarilacaq kitab adi: ";
    getline(cin, ad);

    for(const Book& b : library) {
        if (b.getName() == ad)
        {
            cout<<"Kitab tapildi:\n";
            cout<<"Ad: "<<b.getName()<<endl;
            cout<<"Muellif: "<<b.getAuthor()<<endl;
            cout<<"Il: "<<b.getYear()<<endl;
            cout<<"ID: "<<b.getID()<<endl;
            cout<<"-------------------------------------\n";
            tapildi=true;
        }
    }
    if (!tapildi)
    {
        cout<<"Kitab tapilmadi.\n";
        cout<<endl;
    }
    
}

void deleteBook() {
    int id;

    cout<<"Silinecek kitab ID: ";
    cin>>id;

    for(size_t i=0;i<library.size();i++) {

        if(library[i].getID() == id) {

            library.erase(library.begin() + i);
            saveToFile();
            cout<<"Kitab Silindi.\n";
            
            cin.ignore();
            return;
        }
    }
    cout<<"Kitab tapilmadi.\n\n";
    cin.ignore();
}

void showMenu() {
    cout<<"1) Kitab elave etmek"<<endl;
    cout<<"2) Kitablarin siyahisini gormek"<<endl;
    cout<<"3) Kitab axtarmaq"<<endl;
    cout<<"4) Kitab silmek"<<endl;
    cout<<"5) Proqramdan cixmaq"<<endl;
    cout<<"Secim edin: ";
}



int main() {

    loadFromFile();

    int emeliyyat;

    do
    {
        showMenu();

        cin>>emeliyyat;
        cin.ignore();

        switch (emeliyyat)
        {
        case 1:
            addBook();
            break;
        case 2:
            showBooks();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            deleteBook();
            break;
        case 5:
            cout<<"proqramdan cixilir...\n";
            break;
        default:
            cout<<"yanlis secim, yeniden cehd edin.\n";
        }
    } while (emeliyyat!=5);
    

    

    return 0;


}

