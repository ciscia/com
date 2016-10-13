#ifdef __cplusplus
extern  "C" { 
#endif

#include    <stdarg.h>
#include    "oal.h"
#include    "oam.h"

u32 g_oam_log_seq   = 0;
u32 g_oam_log_level = OAM_LOG_LEVEL_DBG;
u32 g_oam_color     = 1;

u32 oam_main_init(void)
{
    return  0;
}

const char *g_oam_color_table[][4] =
{
    {               // NO COLOR
        "[ERR]",  
        "[WRN]",  
        "[HPY]",  
        "[DBG]",  
    },
    {
        "\033[0;31m[ERR]",  // 31=RED
        "\033[0;33m[WRN]",  // 33=YELLOw
        "\033[0;32m[HPY]",  // 32=GREEN
        "\033[0;30m[DBG]",  // 30=NONE
    },
};
void oam_log(const char *file, u32 line, u32 level, const char* fmt, ...) 
{
    u32     idx = g_oam_color ? 1 : 0;

    va_list args;

    va_start(args, fmt);

    if(level > g_oam_log_level)
    {
        return;
    }
    else  if(level > OAM_LOG_LEVEL_CNT)
    {
        level = OAM_LOG_LEVEL_ERR;
    }

    fprintf(stderr, "%s%s:%d::", g_oam_color_table[idx][level], file, line); 
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "%s", g_oam_color ? "\033[m\n" : "\n");

    va_end(args);
}


#ifdef __cplusplus
}
#endif
