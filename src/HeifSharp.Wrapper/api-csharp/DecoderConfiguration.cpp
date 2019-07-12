#include <DecoderConfiguration.h>
#include "helpers.h"

#define CLASS_NAME DecoderConfig

extern "C"
{
    NATIVE_METHOD(void, Dispose)
    {
        CHECK_PTR_RETURN(nativeObject);

        delete nativeObject;
        nativeObject = NULL;
    }

    NATIVE_METHOD(const HEIF::DecoderConfigId&, GetId)
    {
        CHECK_PTR_RETURN_VAL(nativeObject, HEIF::DecoderConfigId(0));

        return nativeObject->getId();
    }

    NATIVE_METHOD_ARG(void, GetConfig, std::uint8_t*& data, std::uint32_t& size)
    {
        CHECK_PTR_RETURN(nativeObject);

        nativeObject->getConfig(data, size);
    }

    NATIVE_METHOD_ARG(HEIF::ErrorCode, SetConfig, const std::uint8_t* data, std::uint32_t size)
    {
		CHECK_PTR_RETURN_VAL(nativeObject, HEIF::ErrorCode::DECODER_CONFIGURATION_ERROR);

		return nativeObject->setConfig(data, size);
    }
}