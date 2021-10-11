#include "../include/Ps2Game.hpp"

Ps2Game::Ps2Game(const std::string& title, const std::string& studio, int year) : title(title), studio(studio), year(year){}

Ps2Game::Ps2Game(const Ps2Game &copy_Ps2Game): title(copy_Ps2Game.title), studio(copy_Ps2Game.studio),
year(copy_Ps2Game.year){}
        
Ps2Game& Ps2Game::operator=(const Ps2Game& tmp_Ps2Game){
    title = tmp_Ps2Game.title;
    studio = tmp_Ps2Game.studio;
    year = tmp_Ps2Game.year;
    return *this;
}
void Ps2Game::copyMedia(Media const& cp_media)
{
    const Ps2Game& tmp_Ps2Game = dynamic_cast<const Ps2Game&>(cp_media);
    title = tmp_Ps2Game.title;
    studio = tmp_Ps2Game.studio;
    year = tmp_Ps2Game.year;
}
Ps2Game* Ps2Game::clone() const {return new Ps2Game(*this);}
const std::string& Ps2Game::getTitle()  const { return title; }
const std::string& Ps2Game::getStudio()  const { return studio; }
int Ps2Game::getYear() const {return year;}

std::string Ps2Game::prettyPrint() const{
    try {
        return "Title: " + title + "\nStudio: " + studio + "\nYear: " + std::to_string(year);
    }
    catch (...)
    {
        return "this is way too much";
    }
}

bool Ps2Game::operator==(const Ps2Game& game) const 
{
    bool tmpoperator = ((year == game.getYear()) && (title == game.getTitle()) && (studio == game.getStudio()));
    return tmpoperator;     
}