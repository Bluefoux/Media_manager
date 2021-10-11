#include "../include/Vinyl.hpp"
#include <sstream>
#include <chrono>

//Vinyl class functions

Vinyl::Vinyl(const std::string& title, VinylTypes type, int year, const std::string& artist, const Time& runtime) :
title(title),  artist(artist), runtime(runtime), year(year), type(type) {}

Vinyl::Vinyl(const Vinyl &cp_vinyl): title(cp_vinyl.title), artist(cp_vinyl.artist), runtime(cp_vinyl.runtime), year(cp_vinyl.year), 
tracks(cp_vinyl.tracks), type(cp_vinyl.type) {}
        
Vinyl& Vinyl::operator=(const Vinyl& tmp_Vinyl){
    title = tmp_Vinyl.title;
    artist = tmp_Vinyl.artist;
    runtime = tmp_Vinyl.runtime;
    type = tmp_Vinyl.type;
    year = tmp_Vinyl.year;
    tracks = tmp_Vinyl.tracks;
    return *this;
}

void Vinyl::copyMedia(Media const& cp_media)
{
    const Vinyl& tmp_Vinyl = dynamic_cast<const Vinyl&>(cp_media);
    title = tmp_Vinyl.title;
    artist = tmp_Vinyl.artist;
    runtime = tmp_Vinyl.runtime;
    type = tmp_Vinyl.type;
    year = tmp_Vinyl.year;
    tracks = tmp_Vinyl.tracks;
}

Vinyl* Vinyl::clone() const {return new Vinyl(*this);}
void Vinyl::addTrack(const Track& track)
{
    tracks.push_back(track);
}
const std::string& Vinyl::getTitle() const { return title; }
int Vinyl::getYear() const { return year; }
VinylTypes Vinyl::getType() const { return type; }
const std::string& Vinyl::getArtist() const { return artist; }
const Time& Vinyl::getRuntime() const { return runtime; }
const std::vector<Track>& Vinyl::getTracks() const { return tracks; }

std::string Vinyl::prettyPrint() const
{
    const int maxsize = 200;
    std::string trackname;
    std::string tracktime;
    std::string typeprint;
    std::stringstream time_to_string1;
    std::stringstream time_to_string2;
    if (type == VinylTypes::LONG_PLAY)
    {
        typeprint = "LONG_PLAY";
    }
    else
    {
        typeprint = "EXTENDED_PLAY";
    }
    for (Track i : tracks){
        if (trackname.size() > (trackname.max_size()-maxsize) || (tracktime.size() > tracktime.max_size()-maxsize)){
            break;
        }
        trackname = trackname + " : " + i.getName();
        Time time = i.getLength();
        time_to_string1 << time.getChronoTime().count();
        tracktime = tracktime + ": " + time_to_string1.str();
    }
    time_to_string2 << runtime.getChronoTime().count();
    try{
        return "Title: " + title + "\nArtist: " + artist + "\nYear: " + std::to_string(year) + "\nRuntime: " + tracktime + 
        "\nVinyltypes: " + typeprint + "Tracktime =" + time_to_string2.str();
    }
    catch(...)
    {
        return "Do not do that";
    }
}

bool Vinyl::operator==(const Vinyl& vinyl) const 
{
    bool tmpoperator = ((title == vinyl.getTitle()) && (year == vinyl.getYear()) && (type == vinyl.getType()) && 
    (artist == vinyl.getArtist()) && (runtime == vinyl.getRuntime()) && (tracks == vinyl.getTracks()));
    return tmpoperator;
}