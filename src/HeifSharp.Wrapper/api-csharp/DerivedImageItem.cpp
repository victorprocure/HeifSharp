#include <DerivedImageItem.h>
#include "helpers.h"

#define CLASS_NAME DerivedImageItem

extern "C"
{
    NATIVE_METHOD(void, Dispose)
    {
        CHECK_PTR_RETURN(nativeObject);

        delete nativeObject;
        nativeObject = NULL;
    }

    NATIVE_METHOD_ARG(ImageItem*, GetSourceImage, std::uint32_t index)
    {
		CHECK_PTR_RETURN_NULL_PTR(nativeObject);

		return nativeObject->getSourceImage(index);
    }

	NATIVE_METHOD_ARG(Result, RemoveImage, ImageItem* image)
    {
		CHECK_PTR_RETURN_VAL(nativeObject, Result::ERROR_UNDEFINED);

		return nativeObject->removeImage(image);
    }
}