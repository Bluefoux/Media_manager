#ifndef MEDIAMANAGER_HPP
#define MEDIAMANAGER_HPP

#include <vector>
#include <iostream>

#include "Book.hpp"
#include "Media.hpp"
#include "Ps2Game.hpp"
#include "Time.hpp"
#include "Vinyl.hpp"

class MediaManager
{
    private:
        int newmedia_size = 0;
        Media** mymedier = new Media *[newmedia_size];
    public:
        //Destructor//
        ~MediaManager();
        void addMedia(Media* media);
        void addBook(const Book& book);
        void addVinyl(const Vinyl& vinyl);
        void addPs2Game(const Ps2Game& game);
        std::string printMedia()const;
        std::vector<Book> getBooks()const;
        std::vector<Vinyl> getVinyls()const;
        std::vector<Ps2Game> getPs2Games()const;

    bool operator==(const MediaManager& opmedia) const;
};

#endif //MEDIAMANAGER_HPP