#include "../include/Book.hpp"
#include <iostream>

Book::Book(const std::string& title, const std::string& author, const std::string& isbn, 
int pages, int edition): title(title), author(author), isbn(isbn), pages(pages), 
edition(edition){
    this->pages = pages;
    this->edition = edition;
}
    
Book::Book(const Book& copy_book): title(copy_book.title), author(copy_book.author), 
isbn(copy_book.isbn), pages(copy_book.pages), edition(copy_book.edition){}
        
Book& Book::operator=(const Book& tmp_book){
    title = tmp_book.title;
    author = tmp_book.author;
    isbn = tmp_book.isbn;
    pages = tmp_book.pages;
    edition = tmp_book.edition;
    return *this;
}
void Book::copyMedia(Media const& cp_media)
{
    const Book& tmp_book = dynamic_cast<const Book&>(cp_media);
    title = tmp_book.title;
    author = tmp_book.author;
    isbn = tmp_book.isbn;
    pages = tmp_book.pages;
    edition = tmp_book.edition;
}

Book* Book::clone() const {return new Book(*this);}

const std::string& Book::getTitle() const {return title;}
const std::string& Book::getAuthor() const { return author; }
const std::string& Book::getIsbn() const { return isbn; }
int Book::getPages() const { return pages; }
int Book::getEdition() const { return edition; }

std::string Book::prettyPrint() const {
    try {
        return "Title: " + title + "\nAuthor: " + author + "\nPages: " + std::to_string(pages) +"\nIsbn:" + isbn + 
        "\nEdition: " + std::to_string(edition);
        throw ("This is way too many Books");
    }
    catch (...){
        return "do not do that";
    };
}
bool Book::operator==(const Book& book) const 
{
    bool tmpoperator = ((edition == book.getEdition()) && (title == book.getTitle()) && (author == book.getAuthor()));
    return tmpoperator;
}