#include <EntityGroup.h>
#include "helpers.h"

#define CLASS_NAME EntityGroup

extern "C"
{
    NATIVE_CONSTRUCTOR_ARG(Heif* heif, const HEIF::FourCC& type)
    {
        CHECK_PTR_RETURN_NULL_PTR(heif);

        return new CLASS_NAME(heif, type);
    }

    NATIVE_METHOD(void, Dispose)
    {
        CHECK_PTR_RETURN(nativeObject);

        delete nativeObject;
        nativeObject = NULL;
    }

    NATIVE_METHOD(std::uint32_t, GetEntityCount)
    {
        CHECK_PTR_RETURN_VAL(nativeObject, 0);

        return nativeObject->getEntityCount();
    }

    NATIVE_METHOD_ARG(bool, IsItem, std::uint32_t itemId)
    {
        CHECK_PTR_RETURN_VAL(nativeObject, false);

        return nativeObject->isItem(itemId);
    }

    NATIVE_METHOD_ARG(Item*, GetItem, std::uint32_t itemId)
    {
		CHECK_PTR_RETURN_NULL_PTR(nativeObject);

		return nativeObject->getItem(itemId);
    }

	NATIVE_METHOD_ARG(bool, IsTrack, std::uint32_t itemId)
    {
        CHECK_PTR_RETURN_VAL(nativeObject, false);

        return nativeObject->isTrack(itemId);
    }

    NATIVE_METHOD_ARG(Track*, GetTrack, std::uint32_t itemId)
    {
		CHECK_PTR_RETURN_NULL_PTR(nativeObject);

		return nativeObject->getTrack(itemId);
    }

	NATIVE_METHOD_ARG(bool, IsSample, std::uint32_t itemId)
    {
        CHECK_PTR_RETURN_VAL(nativeObject, false);

        return nativeObject->isSample(itemId);
    }

    NATIVE_METHOD_ARG(Sample*, GetSample, std::uint32_t itemId)
    {
		CHECK_PTR_RETURN_NULL_PTR(nativeObject);

		return nativeObject->getSample(itemId);
    }
}