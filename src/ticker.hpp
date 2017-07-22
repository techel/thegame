#pragma once
#include <chrono>
#include <thread>

class Ticker
{
public:
    Ticker() = default;

    template<class Func>
    void tick(Func f)
    {
        auto now = std::chrono::high_resolution_clock::now();
        float delta = FirstFrame ? 0.0f : (std::chrono::duration_cast<std::chrono::milliseconds>(now - LastFrameTime).count()) / 1000.0f;
        LastFrameTime = now;
        FirstFrame = false;

        if(TimeCounter >= 1.0f)
        {
            FramesPerSecond = static_cast<float>(FrameCounter);
            FrameCounter = 0;
            TimeCounter -= 1.0f;
        }

        f(delta);

        TimeCounter += delta;
        FrameCounter++;

        std::this_thread::sleep_for(std::chrono::milliseconds(15));
    }

    float getFPS() const { return FramesPerSecond; }

private:
    bool FirstFrame = true;
    std::chrono::time_point<std::chrono::high_resolution_clock> LastFrameTime;
    float TimeCounter = 0.0f;
    unsigned int FrameCounter = 0;
    float FramesPerSecond = 0.0f;
};