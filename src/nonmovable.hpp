#pragma once

struct nonMovable
{
    nonMovable() = default;
    nonMovable(nonMovable&&) = delete;
    nonMovable &operator=(nonMovable&&) = delete;
};

struct nonCopyable
{
    nonCopyable() = default;
    nonCopyable(const nonCopyable&) = delete;
    nonCopyable &operator=(const nonCopyable&) = delete;
};