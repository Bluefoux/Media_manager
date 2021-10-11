#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include "Media.hpp"

class  Book : public Media
{
    private:
        std::string title = "";
        std::string author = "";
        std::string isbn = "";
        int pages=0;
        int edition=0;
    public:
        Book() = default;
        Book(const std::string& title, const std::string& author, const std::string& isbn, int pages, int edition);
        ~Book(){}
        Book(const Book& copy_book);

        Book& operator=(const Book& tmp_book);
        void copyMedia(Media const& cp_media) override;
        Book* clone() const override;
        
        const std::string& getTitle() const;
        const std::string& getAuthor() const;
        const std::string& getIsbn() const;
        int getPages() const;
        int getEdition() const;

        std::string prettyPrint() const override; 

        bool operator==(const Book& book) const;
};

#endif //BOOK_HPP