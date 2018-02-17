#include <gdk/gdk.h>


typedef struct
{
    GdkWindow       *win;
    
    gint            w;
    gint            h;
    gint            x;
    gint            y;

}
tilerole;


static void tilerole_new()
{   
tilerole *til;    
GList * winlist ;
til = g_slice_new0 (tilerole);
winlist = gdk_screen_get_window_stack(gdk_screen_get_default());
g_list_foreach(winlist, (GFunc)info(), NULL);
}

static void info()
{
    
}