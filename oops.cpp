#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 
 
class Book {
public:
    // Properties
    string title;
    string author;
    bool isAvailable;

    // Constructor
    Book(string title, string author){
      this->title=title;
      this->author=author;
    }

    // Method to check out the book
    void checkOut() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book checked out successfully." << endl;
        } else {
            cout << "Book is not available." << endl;
        }
    }

    // Method to return the book
    void returnBook() {
        isAvailable = true;
        cout << "Book returned successfully." << endl;
    }
};

class Member {
public:
    // Properties
    string name;
    int memberId;
    vector<Book*> borrowedBooks;

    // Constructor
    Member(string name, int memberId) : name(name), memberId(memberId) {}

    // Method to borrow a book
    void borrowBook(Book* book) {
        if (book->isAvailable) {
            borrowedBooks.push_back(book);
            book->checkOut();
            cout << "Book borrowed successfully." << endl;
        } else {
            cout << "Book is not available for borrowing." << endl;
        }
    }

    // Method to return a book
    void returnBook(Book* book) {
        auto it = find(borrowedBooks.begin(), borrowedBooks.end(), book);
        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it);
            book->returnBook();
            cout << "Book returned successfully." << endl;
        } else {
            cout << "You did not borrow this book from the library." << endl;
        }
    }
};

class Library {
public:
    // Properties
    vector<Book> books;
    vector<Member> members;

    // Method to add a book to the library
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book added to the library." << endl;
    }

    // Method to add a member to the library
    void addMember(const Member& member) {
        members.push_back(member);
        cout << "Member added to the library." << endl;
    }
};

int main() {
    // Create a library
    Library library;

    // Add books to the library
    Book book1("The Catcher in the Rye", "J.D. Salinger");
    Book book2("To Kill a Mockingbird", "Harper Lee");
    library.addBook(book1);
    library.addBook(book2);

    // Add members to the library
    Member member1("Alice", 101);
    Member member2("Bob", 102);
    library.addMember(member1);
    library.addMember(member2);

    // Member borrows a book
    member1.borrowBook(&book1);

    // Member tries to borrow the same book again (not allowed)
    member1.borrowBook(&book1);

    // Member returns the book
    member1.returnBook(&book1);

    return 0;
}
