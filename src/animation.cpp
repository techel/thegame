#include "animation.hpp"

#include <cassert>
#include <utility>

void Animation::setTexture(const sf::Texture &tex, unsigned int numFrames, float fps, bool repeat)
{
    Texture = &tex;
    NumFrames = numFrames;
    TimePerFrame = 1.0f / fps;
    Repeat = repeat;
}

void Animation::play()
{
    assert(Texture);
    CurrentFrame = 0;
    CurrentFrameTime = 0.0f;
    Playing = true;

    if(Listener)
        Listener(true);
}

void Animation::tick(float seconds)
{
    if(Playing)
    {
        CurrentFrameTime += seconds;
        if(CurrentFrameTime >= TimePerFrame)
        {
            CurrentFrameTime = 0.0f;
            CurrentFrame++;

            if(CurrentFrame >= NumFrames)
                Playing = false;

            if(Listener)
                Listener(Playing);

            if(!Playing && Repeat)
                play();
        }
    }
}

void Animation::observeFrameChange(FrameListener l)
{
    Listener = std::move(l);
}

sf::IntRect Animation::getTextureRect()
{
    assert(Texture);
    const sf::Vector2u texsize = Texture->getSize();
    const unsigned int framewidth = texsize.x / NumFrames;

    return sf::IntRect({ static_cast<int>(framewidth * CurrentFrame), 0 }, { static_cast<int>(framewidth), static_cast<int>(texsize.y) });
}
