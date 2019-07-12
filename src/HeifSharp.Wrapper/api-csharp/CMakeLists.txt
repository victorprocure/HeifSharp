cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(HEIFPP_LIB_NAME_SHARED HeifWrapper)
set(API_CPP_SRC "../../HeifNative/srcs/api-cpp")

project(${HEIFPP_LIB_NAME_SHARED} LANGUAGES CXX)

add_library(${HEIFPP_LIB_NAME_SHARED} SHARED 
    ${API_CPP_SRC}/Heif.h
    ${API_CPP_SRC}/Heif.cpp

    ${API_CPP_SRC}/EntityGroup.h
    ${API_CPP_SRC}/EntityGroup.cpp
    ${API_CPP_SRC}/EqivGroup.h
    ${API_CPP_SRC}/EqivGroup.cpp

    ${API_CPP_SRC}/AlternativeTrackGroup.h
    ${API_CPP_SRC}/AlternativeTrackGroup.cpp

    ${API_CPP_SRC}/DecoderConfiguration.h
    ${API_CPP_SRC}/DecoderConfiguration.cpp
    ${API_CPP_SRC}/AACDecoderConfiguration.h
    ${API_CPP_SRC}/AACDecoderConfiguration.cpp
    ${API_CPP_SRC}/AVCDecoderConfiguration.h
    ${API_CPP_SRC}/AVCDecoderConfiguration.cpp
    ${API_CPP_SRC}/HEVCDecoderConfiguration.h
    ${API_CPP_SRC}/HEVCDecoderConfiguration.cpp

    ${API_CPP_SRC}/Track.h
    ${API_CPP_SRC}/Track.cpp
    ${API_CPP_SRC}/AudioTrack.h
    ${API_CPP_SRC}/AudioTrack.cpp
    ${API_CPP_SRC}/VideoTrack.h
    ${API_CPP_SRC}/VideoTrack.cpp

    ${API_CPP_SRC}/ImageSequence.h
    ${API_CPP_SRC}/ImageSequence.cpp

    ${API_CPP_SRC}/Sample.h
    ${API_CPP_SRC}/Sample.cpp
    ${API_CPP_SRC}/AudioSample.h
    ${API_CPP_SRC}/AudioSample.cpp
    ${API_CPP_SRC}/VideoSample.h
    ${API_CPP_SRC}/VideoSample.cpp

    ${API_CPP_SRC}/ItemProperty.h
    ${API_CPP_SRC}/ItemProperty.cpp
    ${API_CPP_SRC}/RawProperty.h
    ${API_CPP_SRC}/RawProperty.cpp
    ${API_CPP_SRC}/DescriptiveProperty.h
    ${API_CPP_SRC}/DescriptiveProperty.cpp
    ${API_CPP_SRC}/TransformativeProperty.h
    ${API_CPP_SRC}/TransformativeProperty.cpp

    ${API_CPP_SRC}/Item.h
    ${API_CPP_SRC}/Item.cpp

    ${API_CPP_SRC}/MetaItem.h
    ${API_CPP_SRC}/MetaItem.cpp
    ${API_CPP_SRC}/ExifItem.h
    ${API_CPP_SRC}/ExifItem.cpp
    ${API_CPP_SRC}/MimeItem.h
    ${API_CPP_SRC}/MimeItem.cpp
    ${API_CPP_SRC}/XMPItem.h
    ${API_CPP_SRC}/XMPItem.cpp
    ${API_CPP_SRC}/MPEG7Item.h
    ${API_CPP_SRC}/MPEG7Item.cpp

    ${API_CPP_SRC}/ImageItem.h
    ${API_CPP_SRC}/ImageItem.cpp
    ${API_CPP_SRC}/CodedImageItem.h
    ${API_CPP_SRC}/CodedImageItem.cpp
    ${API_CPP_SRC}/AVCCodedImageItem.h
    ${API_CPP_SRC}/AVCCodedImageItem.cpp
    ${API_CPP_SRC}/HEVCCodedImageItem.h
    ${API_CPP_SRC}/HEVCCodedImageItem.cpp
    ${API_CPP_SRC}/JPEGCodedImageItem.h
    ${API_CPP_SRC}/JPEGCodedImageItem.cpp

    ${API_CPP_SRC}/DerivedImageItem.h
    ${API_CPP_SRC}/DerivedImageItem.cpp
    ${API_CPP_SRC}/IdentityImageItem.h
    ${API_CPP_SRC}/IdentityImageItem.cpp
    ${API_CPP_SRC}/GridImageItem.h
    ${API_CPP_SRC}/GridImageItem.cpp
    ${API_CPP_SRC}/OverlayImageItem.h
    ${API_CPP_SRC}/OverlayImageItem.cpp

    ${API_CPP_SRC}/ErrorCodes.h
    ${API_CPP_SRC}/ErrorCodes.cpp
    ${API_CPP_SRC}/H26xTools.h
    ${API_CPP_SRC}/H26xTools.cpp
    ${API_CPP_SRC}/helpers.h
    ${API_CPP_SRC}/helpers.cpp
)

set_property(TARGET ${HEIFPP_LIB_NAME_SHARED} PROPERTY CXX_STANDARD 11)

target_include_directories(${HEIFPP_LIB_NAME_SHARED} PUBLIC ${API_CPP_SRC})

if(IOS)
    if(${IOS_PLATFORM} STREQUAL "OS")
        set(HEIF_SHARED_LIB_NAME heif_shared_iphoneos)
        set(HEIF_SHARED_WRITER_LIB_NAME heif_writer_shared_iphoneos)
    elseif(${IOS_PLATFORM} STREQUAL "SIMULATOR64")
        set(HEIF_SHARED_LIB_NAME heif_shared_iphonesimulator)
        set(HEIF_SHARED_WRITER_LIB_NAME heif_writer_shared_iphonesimulator)
    endif()
else()
    set(HEIF_SHARED_LIB_NAME heif_shared)
    set(HEIF_SHARED_WRITER_LIB_NAME heif_writer_shared)
endif()

target_link_libraries(${HEIFPP_LIB_NAME_SHARED} ${HEIF_SHARED_LIB_NAME} ${HEIF_SHARED_WRITER_LIB_NAME})
