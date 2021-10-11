#ifndef MEDIA_HPP
#define MEDIA_HPP

#include <string>
#include <iostream>

class Media
{
    public:
        Media() = default;
        Media(const Media& cp_media){}
        Media& operator=(Media const& cp_media) {return *this;}
        virtual void copyMedia(Media const& cp_media) = 0;
        virtual inline ~Media(){};
        virtual Media* clone() const =0;
        bool operator==(const Media& media) const;
        virtual std::string prettyPrint() const=0;
};

#endif //MEDIA_HPP