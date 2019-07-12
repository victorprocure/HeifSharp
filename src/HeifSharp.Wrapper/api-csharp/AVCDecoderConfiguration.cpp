#include <AVCDecoderConfiguration.h>
#include "helpers.h"

extern "C"
{
    DLL_API AVCDecoderConfiguration* AVCDecoderConfigurationCreate(Heif* heif);
    DLL_API AVCDecoderConfiguration* AVCDecoderConfigurationCreateWithType(Heif* heif, const HEIF::FourCC& type);
    DLL_API void AVCDecoderConfigurationDispose(AVCDecoderConfiguration* avcDecoderConfiguration);
    DLL_API void AVCDecoderConfigurationGetConfig(AVCDecoderConfiguration* avcDecoderConfiguration,
                                                  std::uint8_t*& data,
                                                  std::uint32_t& size);
    DLL_API HEIF::ErrorCode AVCDecoderConfigurationSetConfig(AVCDecoderConfiguration* avcDecoderConfiguration,
                                                             const std::uint8_t* data,
                                                             std::uint32_t size);
}

AVCDecoderConfiguration* AVCDecoderConfigurationCreate(Heif* heif)
{
    CHECK_PTR_RETURN_NULL_PTR(heif);
    return new AVCDecoderConfiguration(heif);
}

AVCDecoderConfiguration* AVCDecoderConfigurationCreateWithType(Heif* heif, const HEIF::FourCC& type)
{
    CHECK_PTR_RETURN_NULL_PTR(heif);

    return new AVCDecoderConfiguration(heif, type);
}

void AVCDecoderConfigurationDispose(AVCDecoderConfiguration* avcDecoderConfiguration)
{
    CHECK_PTR_RETURN(avcDecoderConfiguration);

    delete avcDecoderConfiguration;
    avcDecoderConfiguration = NULL;
}

void AVCDecoderConfigurationGetConfig(AVCDecoderConfiguration* avcDecoderConfiguration,
                                      std::uint8_t*& data,
                                      std::uint32_t& size)
{
    CHECK_PTR_RETURN(avcDecoderConfiguration);
    CHECK_PTR_RETURN(data);
    if (size <= 0)
        return;

    avcDecoderConfiguration->getConfig(data, size);
}

HEIF::ErrorCode AVCDecoderConfigurationSetConfig(AVCDecoderConfiguration* avcDecoderConfiguration,
                                                 const std::uint8_t* data,
                                                 std::uint32_t size)
{
    CHECK_PTR_RETURN_VAL(avcDecoderConfiguration, HEIF::ErrorCode::UNINITIALIZED);
    CHECK_PTR_RETURN_VAL(data, HEIF::ErrorCode::DECODER_CONFIGURATION_ERROR);

    avcDecoderConfiguration->setConfig(data, size);
}