#pragma once

#include <sfml/System/Vector2.hpp>

//
// Shakes a specified camera on the xy-plane.
// The amplitude and frequency is multiplied with the intensity.
//
//

class ScreenShaker
{
public:
    ScreenShaker() = default;

    void setParameters(float frequency, float amplitude, float length);

    void shake(float intensity, const sf::Vector2f &direction);
    void tick(float seconds);

    sf::Vector2f getOffset() const;

private:
    float Frequency, Amplitude, Length;
    bool Shaking = false;

    float Intensity, CurrentInterpol;
    sf::Vector2f Direction, CurrentOffset;
};
