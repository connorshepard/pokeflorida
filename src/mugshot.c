#include "global.h"
#include "blit.h"
#include "window.h"
#include "menu.h"
#include "palette.h"
#include "event_data.h"
#include "constants/mugshots.h"

#define MUGSHOT_PALETTE_NUM 13

struct Mugshot{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    const u32* image;
    const u16* palette;
};

void DrawMugshot(void); //VAR_0x8000 = mugshot id
void DrawMugshotAtPos(void); //VAR_0x8000 = mugshot id, VAR_0x8001 = x, VAR_0x8002 = y
void ClearMugshot(void);

//mugshot definitions
static const u32 sMugshotImg_Mangrove[] = INCBIN_U32("graphics/mugshots/mangrove.4bpp.lz");
static const u16 sMugshotPal_Mangrove[] = INCBIN_U16("graphics/mugshots/mangrove.gbapal");

static const u32 sMugshotImg_May[] = INCBIN_U32("graphics/mugshots/may.4bpp.lz");
static const u16 sMugshotPal_May[] = INCBIN_U16("graphics/mugshots/may.gbapal");

static const u32 sMugshotImg_Brendan[] = INCBIN_U32("graphics/mugshots/brendan.4bpp.lz");
static const u16 sMugshotPal_Brendan[] = INCBIN_U16("graphics/mugshots/brendan.gbapal");

static const u32 sMugshotImg_Sidney[] = INCBIN_U32("graphics/mugshots/sidney.4bpp.lz");
static const u16 sMugshotPal_Sidney[] = INCBIN_U16("graphics/mugshots/sidney.gbapal");

static const u32 sMugshotImg_Wayne[] = INCBIN_U32("graphics/mugshots/wayne.4bpp.lz");
static const u16 sMugshotPal_Wayne[] = INCBIN_U16("graphics/mugshots/wayne.gbapal");

static const u32 sMugshotImg_Sudowoodo[] = INCBIN_U32("graphics/mugshots/sudowoodo.4bpp.lz");
static const u16 sMugshotPal_Sudowoodo[] = INCBIN_U16("graphics/mugshots/sudowoodo.gbapal");

static const u32 sMugshotImg_Tandemaus[] = INCBIN_U32("graphics/mugshots/tandemaus.4bpp.lz");
static const u16 sMugshotPal_Tandemaus[] = INCBIN_U16("graphics/mugshots/tandemaus.gbapal");

static const u32 sMugshotImg_Burrowl[] = INCBIN_U32("graphics/mugshots/burrowl.4bpp.lz");
static const u16 sMugshotPal_Burrowl[] = INCBIN_U16("graphics/mugshots/burrowl.gbapal");

static const struct Mugshot sMugshots[] = {
    //ADD YOUR MUGSHOTS HERE
 [MUGSHOT_MANGROVE] = {.x = 0, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Mangrove, .palette = sMugshotPal_Mangrove},
 [MUGSHOT_MAY] = {.x = 0, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_May, .palette = sMugshotPal_May},
 [MUGSHOT_BRENDAN] = {.x = 0, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Brendan, .palette = sMugshotPal_Brendan},
 [MUGSHOT_SIDNEY] = {.x = 0, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Sidney, .palette = sMugshotPal_Sidney},
 [MUGSHOT_WAYNE] = {.x = 0, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Wayne, .palette = sMugshotPal_Wayne},
 [MUGSHOT_SUDOWOODO] = {.x = 0, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Sudowoodo, .palette = sMugshotPal_Sudowoodo},
 [MUGSHOT_TANDEMAUS] = {.x = 0, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Tandemaus, .palette = sMugshotPal_Tandemaus},
 [MUGSHOT_BURROWL] = {.x = 0, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Burrowl, .palette = sMugshotPal_Burrowl}
};


//WindowId + 1, 0 if window is not open
static EWRAM_DATA u8 sMugshotWindow = 0;

void ClearMugshot(void){
    if(sMugshotWindow != 0){
        ClearStdWindowAndFrameToTransparent(sMugshotWindow - 1, 0);
        CopyWindowToVram(sMugshotWindow - 1, 3);
        RemoveWindow(sMugshotWindow - 1);
        sMugshotWindow = 0;
    }
}

static void DrawMugshotCore(const struct Mugshot* const mugshot, int x, int y){
    struct WindowTemplate t;
    u16 windowId;
    
    if(sMugshotWindow != 0){
        ClearMugshot();
    }
    
    #if GAME_VERSION==VERSION_EMERALD
    SetWindowTemplateFields(&t, 0, x, y, mugshot->width/8, mugshot->height/8, MUGSHOT_PALETTE_NUM, 0x40);
    #else
    t = SetWindowTemplateFields(0, x, y, mugshot->width/8, mugshot->height/8, MUGSHOT_PALETTE_NUM, 0x40);
    #endif
    windowId = AddWindow(&t);
    sMugshotWindow = windowId + 1;
    
    LoadPalette(mugshot->palette, 16 * MUGSHOT_PALETTE_NUM, 32);
    CopyToWindowPixelBuffer(windowId, (const void*)mugshot->image, 0, 0);
    PutWindowRectTilemap(windowId, 0, 0, mugshot->width/8, mugshot->height/8);
    CopyWindowToVram(windowId, 3);
}

void DrawMugshot(void){
    const struct Mugshot* const mugshot = sMugshots + VarGet(VAR_0x8000);
    DrawMugshotCore(mugshot, mugshot->x, mugshot->y);
}

void DrawMugshotAtPos(void){
    DrawMugshotCore(sMugshots + VarGet(VAR_0x8000), VarGet(VAR_0x8001), VarGet(VAR_0x8002));
}