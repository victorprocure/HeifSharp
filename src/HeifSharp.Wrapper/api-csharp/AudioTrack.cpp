#include <AudioTrack.h>
#include "helpers.h"

extern "C"
{
    DLL_API AudioTrack* AudioTrackCreate(Heif* heif);
    DLL_API void AudioTrackDispose(AudioTrack* audioTrack);

    DLL_API void AudioTrackAddSample(AudioTrack* audioTrack, AudioSample* audioSample);
    DLL_API void AudioTrackSetSample(AudioTrack* audioTrack, AudioSample* oldAudioSample, AudioSample* newAudioSample);
}

AudioTrack* AudioTrackCreate(Heif* heif)
{
    CHECK_PTR_RETURN_NULL_PTR(heif);

    return new AudioTrack(heif);
}

void AudioTrackDispose(AudioTrack* audioTrack)
{
    CHECK_PTR_RETURN(audioTrack);

    delete audioTrack;
    audioTrack = NULL;
}

void AudioTrackAddSample(AudioTrack* audioTrack, AudioSample* audioSample)
{
    CHECK_PTR_RETURN(audioTrack);
    CHECK_PTR_RETURN(audioSample);

    audioTrack->addSample(audioSample);
}

void AudioTrackSetSample(AudioTrack* audioTrack, AudioSample* oldAudioSample, AudioSample* newAudioSample)
{
    CHECK_PTR_RETURN(audioTrack);
    CHECK_PTR_RETURN(oldAudioSample);
    CHECK_PTR_RETURN(newAudioSample);

    audioTrack->setSample(oldAudioSample, newAudioSample);
}