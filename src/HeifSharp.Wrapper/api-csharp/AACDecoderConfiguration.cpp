#include <AACDecoderConfiguration.h>

#include "helpers.h"

extern "C"
{
    DLL_API AACDecoderConfiguration* CreateAACDefaultDecoderConfiguration(Heif* heif);
    DLL_API AACDecoderConfiguration* CreateAACDecoderConfiguration(Heif* heif, HEIF::FourCC& type);
    DLL_API void AACDecoderConfigurationGetConfig(AACDecoderConfiguration* decoder,
                                                  std::uint8_t*& data,
                                                  std::uint32_t& size);
    DLL_API HEIF::ErrorCode AACDecoderConfigurationSetConfig(AACDecoderConfiguration* decoder,
                                                             std::uint8_t* data,
                                                             std::uint32_t size);
    DLL_API std::uint32_t AACDecoderConfigurationGetSampleRate(AACDecoderConfiguration* decoder);
    DLL_API std::uint8_t AACDecoderConfigurationGetChannels(AACDecoderConfiguration* decoder);
    DLL_API void DisposeAACDecoderConfiguration(AACDecoderConfiguration* decoderConfiguration);
}

AACDecoderConfiguration* CreateAACDefaultDecoderConfiguration(Heif* heif)
{
    return new AACDecoderConfiguration(heif);
}

AACDecoderConfiguration* CreateAACDecoderConfiguration(Heif* heif, HEIF::FourCC& type)
{
    return new AACDecoderConfiguration(heif, type);
}

void AACDecoderConfigurationGetConfig(AACDecoderConfiguration* decoder, std::uint8_t*& data, std::uint32_t& size)
{
    if (decoder == NULL)
    {
        return;
    }

    decoder->getConfig(data, size);
}

HEIF::ErrorCode AACDecoderConfigurationSetConfig(AACDecoderConfiguration* decoder,
                                                 std::uint8_t* data,
                                                 std::uint32_t size)
{
    if (decoder == NULL)
    {
        return HEIF::ErrorCode::UNINITIALIZED;
    }

    return decoder->setConfig(data, size);
}

std::uint32_t AACDecoderConfigurationGetSampleRate(AACDecoderConfiguration* decoder)
{
    if (decoder == NULL)
        return -1;

    return decoder->getSampleRate();
}

std::uint8_t AACDecoderConfigurationGetChannels(AACDecoderConfiguration* decoder)
{
    if (decoder == NULL)
        return -1;

    return decoder->getChannels();
}

void DisposeAACDecoderConfiguration(AACDecoderConfiguration* decoderConfiguration)
{
    if (decoderConfiguration != NULL)
    {
        delete decoderConfiguration;
        decoderConfiguration = NULL;
    }
}