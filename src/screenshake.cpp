#include "screenshake.hpp"

#include <cmath>

void ScreenShaker::setParameters(float frequency, float amplitude, float length)
{
    Frequency = frequency;
    Amplitude = amplitude;
    Length = length;
}
void ScreenShaker::shake(float intensity, const sf::Vector2f &direction)
{
    Intensity = intensity;
    Direction = direction;
    
    Direction = direction / std::sqrt(direction.x*direction.x + direction.y*direction.y) * Amplitude * Intensity;

    CurrentInterpol = 0.0f;
    if(!Shaking)
    {
        CurrentOffset = { 0.0f, 0.0f };
        Shaking = true;
    }
}
void ScreenShaker::tick(float seconds)
{
    if(Shaking)
    {
        float damping = 1.0f - (CurrentInterpol / Length);
        CurrentOffset = Direction * std::sin(CurrentInterpol * Frequency * Intensity * 2 * 3.141592f) * damping * damping;

        CurrentInterpol += seconds;

        if(CurrentInterpol >= Length)
            Shaking = false;
    }
}

sf::Vector2f ScreenShaker::getOffset() const
{
    return CurrentOffset;
}
