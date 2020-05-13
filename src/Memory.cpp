#include "Memory.h"

MemoryArena* AllocateArena(uptr size, bool isTemp) {
    uptr headerSize = sizeof(MemoryArena);
    void* mem = PlatformAlloc(size + headerSize, 128, nullptr);
    assert((uptr)mem % 128 == 0, "Memory aligment violation");
    MemoryArena header = {};
    header.free = size;
    header.size = size;
    header.isTemporary = isTemp;
    header.begin = (void*)((byte*)mem + headerSize);
    memcpy(mem, &header, sizeof(MemoryArena));
    return (MemoryArena*)mem;
}
