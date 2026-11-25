#pragma once
#include <cstdint>

namespace nsp_box_switch_recompiler_pc {
inline constexpr const char* kModuleName = "nsp-box-switch-recompiler-pc";
inline constexpr const char* kBuildSalt = "9c93711ca827a602";
struct RuntimeConfig {
    uint32_t target_fps = 144;
    float fov_radius = 65.0f;
    float smooth_factor = 1.45f;
    bool draw_bounds = true;
};
} // namespace nsp_box_switch_recompiler_pc
