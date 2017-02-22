#include "playercore.h"

VLCPlayer::VLCPlayer()
{
    this->vlc_mediaplayer = NULL;

    this->vlc_inst = libvlc_new(0, NULL);

    if(vlc_inst == NULL);
        //throw exception
}

VLCPlayer::~VLCPlayer()
{
    if(this->vlc_mediaplayer != NULL)
        libvlc_media_player_release(this->vlc_mediaplayer);

    libvlc_release(this->vlc_inst);
}

void VLCPlayer::loadMediaURL(std::string url)
{
    libvlc_media_t* m = libvlc_media_new_location(this->vlc_inst,url.c_str());

    if(this->vlc_mediaplayer == NULL)
    {
        this->vlc_mediaplayer = libvlc_media_player_new_from_media(m);
    }
    else
    {
        libvlc_media_player_set_media(this->vlc_mediaplayer,m);
    }

    libvlc_media_release(m);
}

void VLCPlayer::play()
{
    libvlc_media_player_play(this->vlc_mediaplayer);
}

void VLCPlayer::play(std::string url)
{
    this->loadMediaURL(url);
    this->play();
}

void VLCPlayer::stop()
{
    libvlc_media_player_stop(this->vlc_mediaplayer);
}
