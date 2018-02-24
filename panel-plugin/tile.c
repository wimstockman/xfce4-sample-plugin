#include  <gdk/gdk.h>
#include  <gtk/gtk.h>
#include  <gdk/gdkx.h>

static void tilerole_new(gint h,gint w,gint x,gint y )
{ 
//tilerole *tile;    
//GList * winlist ;
//GList * list ;

GdkRectangle rect ;
GdkScreen *scr ;
GdkWindow *win;
gint desktop;

gdk_init(NULL,NULL);   
win = gdk_screen_get_active_window(gdk_screen_get_default());




desktop = gdk_x11_window_get_desktop(win);
printf(":%s:\n", "Hello, tile!");

scr = gdk_window_get_screen(win);
gdk_monitor_get_geometry (gdk_display_get_monitor_at_window (gdk_screen_get_display (scr),win),&rect);



printf("monitor values in pixels h:%d w:%d x:%d y:%d\n",rect.height,rect.width,rect.x,rect.y );   
printf("resize values in percentage h:%d w:%d x:%d y:%d\n",h,w,x,y );   

w = (gint)((float)w /100 * rect.width);
h = (gint)((float)h /100 * rect.height -20);
x = (gint)(((float)x/100 * rect.width) + rect.x); 
y = (gint)(((float)y/100 * rect.height) + rect.y); 


if (desktop > -1)
{
    //GdkWindowState state;    
    //state = gdk_window_get_state(GDK_WINDOW(win));
    
    //g_print ("sn: %u\n",gtk_window_get_default_title(win));
    gdk_window_unmaximize(win);
    gdk_window_move_resize(GDK_WINDOW(win),x,y,w,h);
printf("resize values in pixels h:%d w:%d x:%d y:%d\n",h,w,x,y );   
    
g_print ("desk: %s\n",gdk_x11_screen_get_window_manager_name(gdk_screen_get_default()));
}

    


/*

winlist = gdk_screen_get_window_stack(gdk_screen_get_default());
winlist = g_list_reverse (winlist);
 for (nIndex = 0; list = g_list_nth (winlist, nIndex); nIndex++) {

        g_print ("%d\n", (list->data));
        desktop = gdk_x11_window_get_desktop(list->data);
        if (desktop > -1)
        {
            g_print ("desk: %d\n",desktop);
            gdk_window_move_resize(GDK_WINDOW(list->data),0,0,h,w);
            if (GDK_WINDOW_STATE_MAXIMIZED ==  gdk_window_get_state(GDK_WINDOW(list->data)))
            {
            g_print ("stat: %d\n",gdk_window_get_state(GDK_WINDOW(list->data)));
            }
    
            
            
        }
        
        
 }        //g_print ("%s\n", gdk_property_get(list->data,"WM_NAME",2,0));
  */



}



int main(void)
{
    gint h = 300 ;
    gint w = 700 ;
    gint x = 10;
    gint y = 10;
    
    
    tilerole_new(h,w,x,y);
    return 0;

}
