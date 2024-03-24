#include <math.h>
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

#include "gpio.h"
#include "source.h"

extern const char *STRING;

static int l_esp_chip_info_cores(lua_State *L)
{
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    lua_pushnumber(L, chip_info.cores);
    return 1;
}

static int l_sleep(lua_State *L)
{
    double ms = lua_tonumber(L, 1);
    vTaskDelay((int) ms / portTICK_PERIOD_MS);
    return 1;
}

static int l_gpio_set_level(lua_State *L)
{
    int gpio_pin = lua_tointeger(L, 1);
    int level = lua_toboolean(L, 2);
    ez_gpio_set_level(gpio_pin, level);
    return 1;
}

void app_main(void)
{
    const int pins[] = {4};
    ez_gpio_init(pins, 1);

    lua_State *L = luaL_newstate();

    luaL_openlibs(L);

    lua_pushcfunction(L, l_esp_chip_info_cores);
    lua_setglobal(L, "getESPChipInfo");

    lua_pushcfunction(L, l_sleep);
    lua_setglobal(L, "sleep");

    lua_pushcfunction(L, l_gpio_set_level);
    lua_setglobal(L, "gpioSetLevel");

    int success = luaL_dostring(L, SCRIPT);
    if (success != 0)
    {
        if (success == LUA_ERRSYNTAX)
        {
            printf("Failed to read syntax\n");
        }
        if (success == LUA_ERRMEM)
        {
            printf("Failed to allocatez memory\n");
        }
    }

    lua_close(L);

    fflush(stdout);
    esp_restart();
}
