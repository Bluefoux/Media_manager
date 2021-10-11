#include "../include/MediaManager.hpp"
#include <iostream>

MediaManager::~MediaManager(){
    for (int i=0; i< newmedia_size; i++){
            delete mymedier[i];
    }
    delete[]mymedier;
}

void MediaManager::addMedia(Media* media) 
{
    int newsize = newmedia_size+1;
    try{
        Media** tmparr = new Media*[newsize];
        for (int i = 0; i < newsize-1; i++)
            {
                tmparr[i] = mymedier[i];
            }
        tmparr[newmedia_size] = media->clone();
        delete[]mymedier;
        mymedier = tmparr;
        newmedia_size++;
    }
    catch(...){}
}

void MediaManager::addBook(const Book& book) {
    Book tmp = book;
    Book* ptrtmp = &tmp;
    int newsize = newmedia_size+1;
    try {
        Media** tmparr = new Media*[newsize];
        for (int i = 0; i < newsize-1; i++)
        {
            tmparr[i] = mymedier[i];
        }
        tmparr[newmedia_size] = new Book();
        tmparr[newmedia_size]->copyMedia(*ptrtmp);
        delete[]mymedier;
        mymedier = tmparr;
        newmedia_size++;
    }
    catch (...){}
}

void MediaManager::addVinyl(const Vinyl& vinyl) {
    Vinyl tmp = vinyl;
    Vinyl* ptrtmp = &tmp;
    int newsize = newmedia_size+1;
    try{
        Media** tmparr = new Media*[newsize];
        for (int i = 0; i < newsize-1; i++)
        {
            tmparr[i] = mymedier[i];
        }
        tmparr[newmedia_size] = new Vinyl();
        tmparr[newmedia_size]->copyMedia(*ptrtmp);
        delete[]mymedier;
        mymedier = tmparr;
        newmedia_size++;
    }
    catch (...){}
}

void MediaManager::addPs2Game(const Ps2Game& game) {
    Ps2Game tmp = game;
    Ps2Game* ptrtmp = &tmp;
    int newsize = newmedia_size+1;
    try{
        Media** tmparr = new Media*[newsize];
        for (int i = 0; i < newsize-1; i++)
        {
            tmparr[i] = mymedier[i];
        }
        tmparr[newmedia_size] = new Ps2Game();
        tmparr[newmedia_size]->copyMedia(*ptrtmp);
        delete[]mymedier;
        mymedier = tmparr;
        newmedia_size++;
    }
    catch (...){}
}

std::string MediaManager::printMedia() const
{
    const int maxsize = 200;
    std::string tmpstr;
    std::vector<Book> tmpbooks{};
    tmpbooks = getBooks();
    for (Book i : tmpbooks)
    {
        if (tmpstr.size() < (tmpstr.max_size()-maxsize)){
            tmpstr = tmpstr + "\n" + i.prettyPrint();
        }
    }
    std::vector<Vinyl> tmpVinyls{};
    tmpVinyls = getVinyls();
    for (Vinyl i : tmpVinyls){
        if (tmpstr.size() < (tmpstr.max_size()-maxsize)){
            tmpstr = tmpstr + "\n" + i.prettyPrint();
        }
    }
    std::vector<Ps2Game> tmpPs2Games{};
    tmpPs2Games = getPs2Games();
    for (Ps2Game i : tmpPs2Games){
        if (tmpstr.size() < (tmpstr.max_size()-maxsize)){
            tmpstr = tmpstr + "\n" + i.prettyPrint();
        }
    }
    return tmpstr;
}

std::vector<Book> MediaManager::getBooks() const {
    std::vector<Book> tmpbooks{};
    try{
        Book* tmparr = new Book();
        for (int i=0; i<newmedia_size; i++){
            if (dynamic_cast<const Book*>(mymedier[i]) != nullptr){
                tmparr->copyMedia(*mymedier[i]);
                Book tmpbook = *tmparr;
                tmpbooks.push_back(tmpbook);
            }
        }
        delete tmparr;
    }
    catch (...){}
    return tmpbooks;
}
std::vector<Vinyl> MediaManager::getVinyls() const {
    std::vector<Vinyl> tmpvinyls{};
    try{
        Vinyl* tmparr = new Vinyl();
        for (int i=0; i<newmedia_size; i++){
            if (dynamic_cast<const Vinyl*>(mymedier[i]) != nullptr){
                tmparr->copyMedia(*mymedier[i]);
                Vinyl tmpvinyl = *tmparr;
                tmpvinyls.push_back(tmpvinyl);
            }
        }
        delete tmparr;
    }
    catch(...){}
    return tmpvinyls;
}

std::vector<Ps2Game> MediaManager::getPs2Games()const {
    std::vector<Ps2Game> tmpgames{};
    try{
        Ps2Game* tmparr = new Ps2Game();
        for (int i=0; i<newmedia_size; i++){
            if (dynamic_cast<const Ps2Game*>(mymedier[i]) != nullptr){
                tmparr->copyMedia(*mymedier[i]);
                Ps2Game tmpgame = *tmparr;
                tmpgames.push_back(tmpgame);
            }
        }
        delete tmparr;
    }
    catch(...){}
    return tmpgames;
}
bool MediaManager::operator==(const MediaManager& opmedia) const {
    std::vector<Book> tmpbooks{};
    tmpbooks = getBooks();
    std::vector<Vinyl> tmpvinyls{};
    tmpvinyls = getVinyls();
    std::vector<Ps2Game> tmpps2games{};
    tmpps2games = getPs2Games();
    bool tmpoperator =  ((tmpbooks == opmedia.getBooks()) && (tmpvinyls == opmedia.getVinyls()) && (tmpps2games == opmedia.getPs2Games()));
    return tmpoperator;
};