#pragma once
#include <cstdint>
#include <functional>

struct ViewTag {};
struct SETag {};
struct BGMTag {};

template <typename Tag>
class StrongId
{
public:
    // デフォルト構築時は 0 を「無効なID」として扱う
    constexpr StrongId() : mValue(0) {}
    explicit constexpr StrongId(uint32_t value) : mValue(value) {}
    
    constexpr uint32_t Get() const { return mValue; }
    constexpr bool IsValid() const { return mValue != 0; }

    auto operator<=>(const StrongId&) const = default;

private:
    uint32_t mValue;
};

// std::unordered_map のキーとして使えるようにするためのハッシュ定義
template <typename Tag>
struct std::hash<StrongId<Tag>> {
    std::size_t operator()(const StrongId<Tag>& id) const noexcept {
        return std::hash<uint32_t>{}(id.Get());
    }
};

using ViewId = StrongId<ViewTag>;
using SEId = StrongId<SETag>;
using BGMId = StrongId<BGMTag>;