#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"

#include <string.h>
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"

#include "source.h"

extern const char* STRING;

void app_main(void)
{
    lua_State *L = luaL_newstate();

    luaL_openlibs(L);

    printf("Hello\n");

    int success = luaL_dostring(L, SCRIPT);
    if (success != 0)
    {
        if (success == LUA_ERRSYNTAX) {
            printf("Failed to read syntax\n");
        }
        if (success == LUA_ERRMEM) {
            printf("Failed to allocatez memory\n");
        }
    }

    vTaskDelay(5000 / portTICK_PERIOD_MS);

    fflush(stdout);
    lua_close(L);

    printf("Goodbye\n");
    fflush(stdout);

    esp_restart();
}
