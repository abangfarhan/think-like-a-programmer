//Program tested on Microsoft Visual Studio 2008 - Zahid Ghadialy
//Decorator is part of Structural Patterns 
//Structural Patterns deal with decoupling the interface and implementation of classes and objects
//The Decorator pattern provides us with a way to modify the behavior of individual objects without 
//    having to create a new derived class. 

//The example here shows a Library that contains information about the books
//After the class was created, it was decided to have a borrowable functionality added

#include<iostream>
#include<string>
#include<list>

using namespace std;

// The 'Component' abstract class
class LibraryItem
{
  public:
    void SetNumCopies(int value)
    {
        numCopies_ = value;
    }
    int GetNumCopies(void)
    {
        return numCopies_;
    }
    virtual void Display(void)=0;
  private:
    int numCopies_;
};

// The 'ConcreteComponent' class#1
class Book : public LibraryItem
{
  public:
    Book(string author, string title, int numCopies) : author_(author), title_(title)
    {
        SetNumCopies(numCopies);
    }
    void Display(void)
    {
        cout<<"\nBook ------ "<<endl;
        cout<<" Author : "<<author_<<endl;
        cout<<" Title : "<<title_<<endl;
        cout<<" # Copies : "<<GetNumCopies()<<endl;
    }
  private:
    Book(); //Default not allowed
    string author_;
    string title_;
};

// The 'ConcreteComponent' class#2
class Video : public LibraryItem
{
  public:
    Video(string director, string title, int playTime, int numCopies) : director_(director), title_(title), playTime_(playTime)
    {
        SetNumCopies(numCopies);
    }
    void Display(void)
    {
        cout<<"\nVideo ------ "<<endl;
        cout<<" Director : "<<director_<<endl;
        cout<<" Title : "<<title_<<endl;
        cout<<" Play Time : "<<playTime_<<" mins"<<endl;
        cout<<" # Copies : "<<GetNumCopies()<<endl;
    }
  private:
    Video(); //Default not allowed
    string director_;
    string title_;
    int playTime_;
};

// The 'Decorator' abstract class
class Decorator : public LibraryItem
{
  public:
    Decorator(LibraryItem* libraryItem) : libraryItem_(libraryItem) {}
    void Display(void)
    {
        libraryItem_->Display();
    }
    int GetNumCopies(void)
    {
        return libraryItem_->GetNumCopies();
    }
  protected:
    LibraryItem* libraryItem_;
  private:
    Decorator(); //not allowed
};

// The 'ConcreteDecorator' class
class Borrowable : public Decorator
{
  public:
    Borrowable(LibraryItem* libraryItem) : Decorator(libraryItem) {}
    void BorrowItem(string name)
    {
        borrowers_.push_back(name);
    }
    void ReturnItem(string name)
    {
        list<string>::iterator it = borrowers_.begin();
        while(it != borrowers_.end())
        {
            if(*it == name)
            {
                borrowers_.erase(it);
                break;
            }
            ++it;
        }
    }
    void Display()
    {
        Decorator::Display();
        int size = (int)borrowers_.size();
        cout<<" # Available Copies : "<<(Decorator::GetNumCopies() - size)<<endl;
        list<string>::iterator it = borrowers_.begin();
        while(it != borrowers_.end())
        {
            cout<<" borrower: "<<*it<<endl;
            ++it;
        }
    }
  protected:
    list<string> borrowers_;
};

//The Main method
int main()
{
    Book book("Erik Dahlman","3G evolution",6);
    book.Display();

    Video video("Peter Jackson", "The Lord of the Rings", 683, 24);
    video.Display();

    cout<<"Making video borrowable"<<endl;
    Borrowable borrowvideo(&video);
    borrowvideo.BorrowItem("Bill Gates");
    borrowvideo.BorrowItem("Steve Jobs");
    borrowvideo.Display();

    return 0;
}
