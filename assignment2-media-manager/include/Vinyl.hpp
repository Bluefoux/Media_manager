#ifndef VINYL_HPP
#define VINYL_HPP

#include <string>
#include <vector>
#include "Track.hpp"
#include "Media.hpp"
#include "Time.hpp"

enum class VinylTypes
{
    LONG_PLAY, 
    EXTENDED_PLAY
};


class Vinyl : public Media
{
    private:
        std::string title = "";
        std::string artist = "";
        Time runtime = 0;
        int year = 0;
        std::vector<Track> tracks{};
        VinylTypes type = VinylTypes::LONG_PLAY;
    public:
        Vinyl() = default;
        Vinyl(const std::string& title, VinylTypes type, int year, const std::string& artist, const Time& runtime);
        Vinyl(const Vinyl &cp_vinyl);
        ~Vinyl(){};
        Vinyl* clone() const override;
        Vinyl& operator=(const Vinyl& tmp_Vinyl);
        void copyMedia(Media const& cp_media) override;
        void addTrack(const Track& track);
        const std::string& getTitle() const;
        int getYear() const;
        VinylTypes getType() const;
        const std::string& getArtist() const;
        const Time& getRuntime() const;
        const std::vector<Track>& getTracks() const;
        
        std::string prettyPrint() const override;
        bool operator==(const Vinyl& vinyl) const;
};

#endif //VINYL_HPP