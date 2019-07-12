#include <CodedImageItem.h>
#include "helpers.h"

#define CLASS_NAME CodedImageItem

extern "C"
{
    NATIVE_METHOD(void, Dispose)
    {
        CHECK_PTR_RETURN(nativeObject);
        delete nativeObject;
        nativeObject = NULL;
    }

    NATIVE_METHOD(DecoderConfig*, GetDecoderConfiguration)
    {
        CHECK_PTR_RETURN_NULL_PTR(nativeObject);

        return nativeObject->getDecoderConfiguration();
    }
}