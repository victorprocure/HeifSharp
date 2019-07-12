#include <AudioSample.h>

#include "helpers.h"

extern "C"
{
    DLL_API AudioSample* AudioSampleCreate(Heif* heif);
}

AudioSample* AudioSampleCreate(Heif* heif)
{
    if (heif == NULL)
        return nullptr;

    return new AudioSample(heif);
}