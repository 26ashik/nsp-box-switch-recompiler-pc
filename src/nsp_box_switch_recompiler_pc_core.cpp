#include "../include/nsp_box_switch_recompiler_pc_runtime.hpp"
#include <windows.h>
#include <atomic>

namespace nsp_box_switch_recompiler_pc {
static std::atomic<bool> g_running{true};
void PollHotkeys(bool& menu_open) noexcept {
    if (GetAsyncKeyState(VK_INSERT) & 1) menu_open = !menu_open;
    if (GetAsyncKeyState(VK_END) & 1) g_running.store(false, std::memory_order_relaxed);
}
} // namespace nsp_box_switch_recompiler_pc

int main() {
    bool menu_open = true;
    while (nsp_box_switch_recompiler_pc::g_running.load(std::memory_order_relaxed)) {
        nsp_box_switch_recompiler_pc::PollHotkeys(menu_open);
        Sleep(6);
    }
    return 0;
}
