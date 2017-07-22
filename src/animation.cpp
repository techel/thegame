#include "animation.hpp"

#include <cassert>
#include <utility>

void Animation::setTexture(const sf::Texture &tex, unsigned int numFrames, float fps)
{
    Texture = &tex;
    NumFrames = numFrames;
    TimePerFrame = 1.0f / fps;
}

void Animation::play()
{
    assert(Texture);
    currentFrame = 0;
    currentFrameTime = 0.0f;
    Playing = true;

    if(Listener)
        Listener(true);
}

void Animation::tick(float seconds)
{
    if(Playing)
    {
        currentFrameTime += seconds;
        if(currentFrameTime >= TimePerFrame)
        {
            currentFrameTime = 0.0f;
            currentFrame++;

            if(currentFrame >= NumFrames)
                Playing = false;

            if(Listener)
                Listener(Playing);
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

    return sf::IntRect({ static_cast<int>(framewidth * currentFrame), 0 }, { static_cast<int>(framewidth), static_cast<int>(texsize.y) });
}
