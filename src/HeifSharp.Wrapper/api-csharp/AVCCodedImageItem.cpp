#include <AVCCodedImageItem.h>
#include "helpers.h"

#define CLASS_NAME AVCCodedImageItem

extern "C"
{
    NATIVE_CONSTRUCTOR_ARG(Heif* heif)
    {
        CHECK_PTR_RETURN_NULL_PTR(heif);

        return new AVCCodedImageItem(heif);
    }
    NATIVE_METHOD_ARG(void, Dispose, AVCCodedImageItem* avcCodedImageItem)
    {
        CHECK_PTR_RETURN(avcCodedImageItem);
        delete avcCodedImageItem;
        avcCodedImageItem = NULL;
    }
}