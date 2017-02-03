#pragma once

#include <spotify/json.hpp>

#include <noise/noise.h>
#include "noise/module/Wrapper.h"

namespace spotify
{
namespace json
{

template<>
struct default_codec_t<noise::module::Wrapper<noise::module::Cache>>
{
    using CacheWrapper = noise::module::Wrapper<noise::module::Cache>;
    static codec::object_t<CacheWrapper> codec()
    {
        auto codec = codec::object<CacheWrapper>();
        codec.required("type", codec::eq<std::string>("Cache"));
        codec.required("SourceModule", codec::ignore_t<int>());
        return codec;
    }
};
}
}
