#pragma once
#include "Memory.h"

template<typename Char>
struct StringBuilder {
    MemoryArena* arena;
    TempMemory memoryFrame;
    Char* buffer;
    uptr bufferSize;
    uptr at;
};

template <typename Char>
StringBuilder<Char> StringBuilderBegin(MemoryArena* arena, uptr size = 64) {
    StringBuilder<Char> builder {};
    builder.arena = arena;
    builder.memoryFrame =
}
