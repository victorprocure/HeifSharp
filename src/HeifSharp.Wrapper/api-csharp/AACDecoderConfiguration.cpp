#pragma once

#include <AACDecoderConfiguration.h>

#include "helpers.h"

#define CLASS_NAME AACDecoderConfiguration

extern "C"
{
    DLL_API HEIFPP::AACDecoderConfiguration* CreateAACDefaultDecoderConfiguration(HEIFPP::Heif* heif);
    DLL_API HEIFPP::AACDecoderConfiguration* CreateAACDecoderConfiguration(HEIFPP::Heif* heif, HEIF::FourCC& type);
    DLL_API void AACDecoderConfigurationGetConfig(HEIFPP::AACDecoderConfiguration* decoder,
                                                  std::uint8_t*& data,
                                                  std::uint32_t& size);
    DLL_API HEIF::ErrorCode AACDecoderConfigurationSetConfig(HEIFPP::AACDecoderConfiguration* decoder,
                                                              std::uint8_t* data,
                                                              std::uint32_t size);
    DLL_API std::uint32_t AACDecoderConfigurationGetSampleRate(HEIFPP::AACDecoderConfiguration* decoder);
    DLL_API std::uint8_t AACDecoderConfigurationGetChannels(HEIFPP::AACDecoderConfiguration* decoder);
    DLL_API void DisposeAACDecoderConfiguration(HEIFPP::AACDecoderConfiguration* decoderConfiguration);
}

HEIFPP::AACDecoderConfiguration* CreateAACDefaultDecoderConfiguration(HEIFPP::Heif* heif)
{
    return new HEIFPP::AACDecoderConfiguration(heif);
}

HEIFPP::AACDecoderConfiguration* CreateAACDecoderConfiguration(HEIFPP::Heif* heif, HEIF::FourCC& type)
{
    return new HEIFPP::AACDecoderConfiguration(heif, type);
}

void AACDecoderConfigurationGetConfig(HEIFPP::AACDecoderConfiguration* decoder,
                                      std::uint8_t*& data,
                                      std::uint32_t& size)
{
    if (decoder == NULL)
    {
        return;
    }

    decoder->getConfig(data, size);
}

HEIF::ErrorCode AACDecoderConfigurationSetConfig(HEIFPP::AACDecoderConfiguration* decoder,
                                                  std::uint8_t* data,
                                                  std::uint32_t size)
{
    if (decoder == NULL)
    {
        return HEIF::ErrorCode::UNINITIALIZED;
    }

    return decoder->setConfig(data, size);
}

std::uint32_t AACDecoderConfigurationGetSampleRate(HEIFPP::AACDecoderConfiguration* decoder)
{
    if(decoder == NULL)
        return -1;

    return decoder->getSampleRate();
}

std::uint8_t AACDecoderConfigurationGetChannels(HEIFPP::AACDecoderConfiguration* decoder)
{
    if(decoder == NULL)
        return -1;

    return decoder->getChannels();
}

void DisposeAACDecoderConfiguration(HEIFPP::AACDecoderConfiguration* decoderConfiguration)
{
    if (decoderConfiguration != NULL)
    {
        delete decoderConfiguration;
        decoderConfiguration = NULL;
    }
}
