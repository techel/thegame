#pragma once

#include <sfml/Graphics/Texture.hpp>
#include <sfml/Graphics/Rect.hpp>
#include <functional>

class Animation
{
public:
    Animation() = default;

    void setTexture(const sf::Texture &tex, unsigned int numFrames, float fps, bool repeat = false);

    void play();

    void tick(float seconds);

    //called each frame change with boolean indicating whether animation is still playing
    using FrameListener = std::function<void(bool)>;
    void observeFrameChange(FrameListener l);

    sf::IntRect getTextureRect();

private:
    const sf::Texture *Texture = nullptr;
    unsigned int NumFrames;
    float TimePerFrame;
    bool Repeat;

    bool Playing = false;
    unsigned int CurrentFrame;
    float CurrentFrameTime;

    FrameListener Listener;
};