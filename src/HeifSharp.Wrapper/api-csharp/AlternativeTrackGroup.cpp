#include <AlternativeTrackGroup.h>
#include "helpers.h"

extern "C"
{
    DLL_API AlternativeTrackGroup* CreateAlternativeTrackGroup(Heif* heif);
    DLL_API void DisposeAlternativeTrackGroup(AlternativeTrackGroup* alternativeTrackGroup);
    DLL_API void AlternativeTrackGroupSetContext(AlternativeTrackGroup* alternativeTrackGroup, const void* context);
    DLL_API void AlternativeTrackGroupGetContext(AlternativeTrackGroup* alternativeTrackGroup, const void* context);
    DLL_API std::uint32_t AlternativeTrackGroupGetTrackCount(AlternativeTrackGroup* alternativeTrackGroup);
    DLL_API Track* AlternativeTrackGroupGetTrack(AlternativeTrackGroup* alternativeTrackGroup, std::uint32_t trackId);
    DLL_API Result AlternativeTrackGroupAddTrack(AlternativeTrackGroup* alternativeTrackGroup, Track* track);
    DLL_API void AlternativeTrackGroupRemoveTrack(AlternativeTrackGroup* alternativeTrackGroup, Track* track);
}

AlternativeTrackGroup* CreateAlternativeTrackGroup(Heif* heif)
{
    CHECK_PTR_RETURN_NULL_PTR(heif);

    return new AlternativeTrackGroup(heif);
}

void DisposeAlternativeTrackGroup(AlternativeTrackGroup* alternativeTrackGroup)
{
    CHECK_PTR_RETURN(alternativeTrackGroup);

    delete alternativeTrackGroup;
    alternativeTrackGroup = NULL;
}

void AlternativeTrackGroupSetContext(AlternativeTrackGroup* alternativeTrackGroup, const void* context)
{
    CHECK_PTR_RETURN(alternativeTrackGroup);
    CHECK_PTR_RETURN(context);

    alternativeTrackGroup->setContext(context);
}

void AlternativeTrackGroupGetContext(AlternativeTrackGroup* alternativeTrackGroup, const void* context)
{
    CHECK_PTR_RETURN(alternativeTrackGroup);

    context = alternativeTrackGroup->getContext();
}

std::uint32_t AlternativeTrackGroupGetTrackCount(AlternativeTrackGroup* alternativeTrackGroup)
{
    CHECK_PTR_RETURN_VAL(alternativeTrackGroup, -1);

    return alternativeTrackGroup->getTrackCount();
}

Track* AlternativeTrackGroupGetTrack(AlternativeTrackGroup* alternativeTrackGroup, std::uint32_t trackId)
{
    CHECK_PTR_RETURN_NULL_PTR(alternativeTrackGroup);

    return alternativeTrackGroup->getTrack(trackId);
}

Result AlternativeTrackGroupAddTrack(AlternativeTrackGroup* alternativeTrackGroup, Track* track)
{
    CHECK_PTR_RETURN_VAL(alternativeTrackGroup, Result::ERROR_UNDEFINED);
    CHECK_PTR_RETURN_VAL(track, Result::ERROR_UNDEFINED);

    return alternativeTrackGroup->addTrack(track);
}

void AlternativeTrackGroupRemoveTrack(AlternativeTrackGroup* alternativeTrackGroup, Track* track)
{
    CHECK_PTR_RETURN(alternativeTrackGroup);
    CHECK_PTR_RETURN(track);

    alternativeTrackGroup->removeTrack(track);
}