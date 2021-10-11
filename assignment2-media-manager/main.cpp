// Edit this class as you choose. The main function below is just there to make
// sure the project compiles!
#include <string>
#include <iostream>
#include <vector>

#include "include/Book.hpp"
#include "include/Ps2Game.hpp"
#include "include/Vinyl.hpp"
#include "include/Time.hpp"
#include "include/MediaManager.hpp"
#include "include/Media.hpp"


int main() 
{
    MediaManager m_manager;
    std::string intitle;
    std::string inartist;
    std::string instudio;
    std::string inauthor;
    std::string inisbn;
    std::string choice;
    VinylTypes type = VinylTypes::LONG_PLAY;
    Time runtime = 0;
    int year = 0;
    int pages = 0;
    int edition = 0;

    Book* book_stuff = new Book[0];
    m_manager.addMedia(book_stuff);
    Vinyl* book_stuff1 = new Vinyl[0];
    m_manager.addMedia(book_stuff1);
    Ps2Game* book_stuff2 = new Ps2Game[0];
    m_manager.addMedia(book_stuff2);
    
    do {
        std::cout << "Write what you wish to do (addBook, addVinyl, addPs2game, print or quit)" << std::endl;
        std::cin >> choice;
        if (choice == "addBook"){
            std::cout << "Please enter the title: " << std::endl;
            std::cin >> intitle;
            std::string* ref_title = &intitle;
            std::cout << "Please enter the author: " << std::endl;
            std::cin >> inauthor;
            std::string* ref_tinauthor = &inauthor;
            std::cout << "Please enter the isbn: " << std::endl;
            std::cin >> inisbn;
            std::string* ref_inisbn = &inisbn;
            std::cout << "Please enter the pages: " << std::endl;
            std::cin >> pages;
            std::cout << "Please enter the edition: " << std::endl;
            std::cin >> edition;
            Book newbook(*ref_title, *ref_tinauthor, *ref_inisbn, pages, edition);
            Book* ptrbook = &newbook;
            m_manager.addBook(*ptrbook);
        } 
        if (choice == "addVinyl")
        {
            std::cout << "Please enter the title: " << std::endl;
            std::cin >> intitle;
            std::string* ref_title = &intitle;
            std::cout << "Please enter the artist: " << std::endl;
            std::cin >> inartist;
            std::string* ref_inartist = &inartist;
            std::cout << "Please enter the year: " << std::endl;
            std::cin >> year;
            Vinyl newvinyl(*ref_title, type, year, *ref_inartist, runtime);
            Vinyl* ptrvinyl = &newvinyl;
            m_manager.addVinyl(*ptrvinyl);
        } 
        if (choice == "addPs2game"){
            std::cout << "Please enter the title: " << std::endl;
            std::cin >> intitle;
            std::string* ref_title = &intitle;
            std::cout << "Please enter the studio: " << std::endl;
            std::cin >> instudio;
            std::string* ref_studio = &instudio;
            std::cout << "Please enter the year: " << std::endl;
            std::cin >> year;
            Ps2Game newps2game(*ref_title, *ref_studio, year);
            Ps2Game* ptrps2game = &newps2game;
            m_manager.addPs2Game(*ptrps2game);
        } 
        if (choice == "print"){
            std::cout << m_manager.printMedia();
        } 
        if (choice == "quit"){
            std::cout << "Have a nice day" << std::endl;
        }
    } while (choice != "quit");
    delete[]book_stuff;
    delete[]book_stuff1;
    delete[]book_stuff2;
};