#ifndef PLAYERCORE_H_
#define PLAYERCORE_H_

#include <string>

#include <vlc/vlc.h>

class VLCPlayer
{
    private:
        libvlc_instance_t* vlc_inst;
        libvlc_media_player_t* vlc_mediaplayer;
    
    public:
        VLCPlayer();
        virtual ~VLCPlayer();

        void loadMediaURL(std::string url);

        void play();
        void play(std::string url);
        void stop();
};

#endif //PLAYERCORE_H_
