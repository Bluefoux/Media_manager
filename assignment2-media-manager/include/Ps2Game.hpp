#ifndef PS2GAME_HPP
#define PS2GAME_HPP

#include <string>
#include <iostream>
#include "Media.hpp"

class Ps2Game: public Media
{
    private:
        std::string title = "";
        std::string studio = "";
        int year = 0;
    public:
        Ps2Game() = default;
        Ps2Game(const std::string& title, const std::string& studio, int year);
        Ps2Game(const Ps2Game &copy_Ps2Game);
        ~Ps2Game(){};
        Ps2Game& operator=(const Ps2Game& tmp_Ps2Game);
        void copyMedia(Media const& cp_media) override;
        Ps2Game* clone() const override;

        const std::string& getTitle()  const;
        const std::string& getStudio()  const;
        int getYear() const;

        std::string prettyPrint() const override;
        bool operator==(const Ps2Game& game) const;
};
#endif // PS2GAME_HPP