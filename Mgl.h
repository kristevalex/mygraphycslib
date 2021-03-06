/* README
It is objecting graphics libruary witch can help you in drawing.
* $name      Mgraphicslib
* $autor     Alex Kistev
* $date      2017
* $version   1.4
* $copyright (C) Mgraphicslib (1.4), Alex Kistev, 2017
You can use option of professional mode for it you shold put
    {
    #define __MGL_PROFESSSIONAL_MODE__
    }
in your code before including Mgl.
! $Note: use just if you understed that whith out it program works rightly.
*/


#ifndef __MGL_INCLUDED__ //{

    //{ DEFINES

#ifdef __M_GRAPHICS_LIB_INCUDED__

    #error You can not include diffrent versions of Mgl

#endif

#define __MGL_INCLUDED__

#define __M_GRAPHICS_LIB_INCLUDED__   // for comatiblity to erlyer vversion

#define __MGL_CFG_SELECTED_CODE__ -1

#define MMB_EMPTY 0
#define MMB_LEFT  1
#define MMB_RIGHT 2
#define MMB_FULL  3

#define ROUND( x )  ( (int) floor ((x) + 0.5) )

#define MGL_CHECK_VERSION( msg )  if( __MGL_VERSION__ < msg )M_ERROR( "neads higher version of Mgl" )

        //{ ERRORS

#define M_ERROR( msg )  _M_Error (__FILE__, __LINE__, __FUNCTION__, msg)

#ifndef __MGL_PROFESSSIONAL_MODE__ //{

    #define __MGL_WIN_CREATED__  WinCreated
    #define __MGL_WIN_NOT_CREATED__  (!__MGL_WIN_CREATED__)
    #define __MGL_WIN_CREATED_ASSERTED__  if( __MGL_WIN_NOT_CREATED__ )M_ERROR( "Window is not created." );
    #define __MGL_WIN_NOT_CREATED_ASSERTED__  if( __MGL_WIN_CREATED__ )M_ERROR( "Window is already created." );

    #define asserted  || M_ERROR( "Zero or false result." )

    #define __MGL_CFG_CREATED__  created
    #define __MGL_CFG_NOT_CREATED__  (!__MGL_CFG_CREATED__)
    #define __MGL_CFG_CREATED_ASSERTED__  if( __MGL_CFG_NOT_CREATED__ )M_ERROR( "Configuration isn't created" );
    #define __MGL_CFG_NOT_CREATED_ASSERTED__  if( __MGL_CFG_CREATED__ )M_ERROR( "Configuration is already created" );

    #define __MGL_CFG_Z_INITED__  z_coordinate_inited
    #define __MGL_CFG_Z_NOT_INITED__  (!__MGL_CFG_Z_INITED__)
    #define __MGL_CFG_Z_INITED_ASSERTED__  if( __MGL_CFG_Z_NOT_INITED__ )M_ERROR( "Z-way is not inited, look how to use it" );
    #define __MGL_CFG_Z_NOT_INITED_ASSERTED__  if( __MGL_CFG_Z_INITED__ )M_ERROR( "Z-way is already inited. Don't init it again" );
    #warning to do: How to use Z-way inition

#else

    #define __MGL_WIN_CREATED__  WinCreated
    #define __MGL_WIN_NOT_CREATED__  !__MGL_WIN_CREATED__
    #define __MGL_WIN_CREATED_ASSERTED__
    #define __MGL_WIN_NOT_CREATED_ASSERTED__

    #define asserted

    #define __MGL_CFG_CREATED__  created
    #define __MGL_CFG_NOT_CREATED__  !__MGL_CFG_CREATED__
    #define __MGL_CFG_CREATED_ASSERTED__
    #define __MGL_CFG_NOT_CREATED_ASSERTED__

    #define __MGL_CFG_Z_INITED__  z_coordinate_inited
    #define __MGL_CFG_Z_NOT_INITED__  (!__MGL_CFG_Z_INITED__)
    #define __MGL_CFG_Z_INITED_ASSERTED__
    #define __MGL_CFG_Z_NOT_INITED_ASSERTED__

#endif                             //}

        //}

    //}

    //{ VERSION

#if  defined (__STRICT_ANSI__) //{

    #ifdef __GNUC__
    #warning Mgl: Trying to extend strict ANSI compatibility   //Try to extend strict ANSI rules
    #endif

    #undef  __STRICT_ANSI__
    #define __STRICT_ANSI__UNDEFINED

#endif                         //}

#if !defined (WINVER) //{

    #define   WINVER  0x0500   // Defaults to Windows 2000
    #define   WINDOWS_ENABLE_CPLUSPLUS

#endif                //}

#ifdef __MGL_VERSION__ //{

    #undef  __MGL_VERSION__

#endif                 //}

#ifdef __M_GRAPHICS_LIB_VERSION__ //{

    #undef  __M_GRAPHICS_LIB_VERSION__

#endif                 //}

#define __MGL_VERSION__  1.5

#define __M_GRAPHICS_LIB_VERSION__  __MGL_VERSION__    // To compatiblity for erlier version


#if !defined (__cplusplus) //{

    #error Mgl: needs c++ for compiling

#endif                     //}

#ifdef __GNUC__

    #pragma GCC diagnostic ignored "-Wwrite-strings"

#endif

#if  defined (_MSC_VER) && (_MSC_VER >= 1400)   // { MSVC 8 (2005) or greater

    #pragma warning (disable: 26135)            // missing locking annotation
    #pragma warning (disable: 28125)            // the function must be called from within a try/except block
    #pragma warning (disable: 28159)            // consider using another function instead

    #pragma setlocale ("russian")               // Set source file encoding

#endif                                          // }

#if !defined (_WIN32_WINNT) //{
    #define   _WIN32_WINNT   WINVER      // Defaults to the same as WINVER
#endif                      //}

#if !defined (_WIN32_IE) //{
    #define   _WIN32_IE      WINVER      // Defaults to the same as WINVER
#endif                   //}

#if !defined (_USE_MATH_DEFINES) //{
    #define   _USE_MATH_DEFINES                       // math.h's M_PI etc.
#endif                           //}

    //}

    //{ INCLUDES

#include <windows.h>
#include <wincon.h>
#include <process.h>
#include <stdio.h>
#include <assert.h>
#include <shellapi.h>
#include <fstream>
#include <iostream>

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <direct.h>
#include <process.h>
#include <signal.h>
#include <locale.h>
#include <time.h>
#include <float.h>
#include <math.h>

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <stdexcept>

#include <conio.h>

using namespace std;

    //}

    //{ MAIN CODE

    namespace Mgl
        {

        //{ GLOBAL CROPE

            //{ TECNICAL

volatile bool WinCreated = false;

HDC win_hdc = NULL;
HWND win_hwnd = NULL;

const char szClassName[ ] = "ClassName1";

            //}

POINT _M_MousePos = {0, 0};
int _M_MouseButtons = 0;
double _M_MouseWheel = 0;

const unsigned _M_BUFSIZE = 1024;
const unsigned _M_BIGBUFSIZE = 2048;

            //{ ERRORS

unsigned _M_Error (const char file[], int line, const char func[], const char msg [])
    {
    DWORD winerr = GetLastError();
    int crterr = errno;
    int doserr = _doserrno;
    unsigned threadId = GetCurrentThreadId();

    string massbox_print = "";
    string console_print = "";
    char slg [_M_BIGBUFSIZE] = "";

    sprintf (slg, "%d", line);

    console_print += "Mgl tells:\n\n";
    console_print += "File: "; console_print += file; console_print += ", ";
    console_print += "Line: "; console_print += slg; console_print += ", ";
    console_print += "Function: "; console_print += func; console_print += ".\n\n";

    sprintf (slg, "%s", msg);
    console_print += "With Message: "; console_print += slg; console_print += ".\n\n";

    sprintf (slg, "%d", winerr);
    console_print += "GetLastError(): "; console_print += slg; console_print += ".\n";

    sprintf (slg, "%d", crterr);
    console_print += "errno: "; console_print += slg; console_print += " ("; console_print += strerror (crterr); console_print += ").\n";

    sprintf (slg, "%d", doserr);
    console_print += "_doserrno: "; console_print += slg; console_print += " ("; console_print += strerror (doserr); console_print += ").\n";

    sprintf (slg, "%d", threadId);
    console_print += "ThreadId: "; console_print += slg; console_print += ".\n\n";

    cerr << "\n--------------------------------------------------\n";
    cerr << console_print;
    cerr << "\n--------------------------------------------------\n";

    MessageBox (win_hwnd, "������ � ���������", "������!", MB_OK);

    exit (EXIT_FAILURE);
    }

            //}

        //}

        //{ CLASSES

            //{ PROTOTIPES

struct _m_win_struct_
    {
    HWND hwnd;
    size_t sizeX, sizeY;
    char* Name;
    int nFunsterStil;
    HINSTANCE hThisInstance;
    HICON Icon;

    _m_win_struct_    (          ) :
        hwnd          (NULL      ),
        sizeX         (800       ),
        sizeY         (600       ),
        Name          ("Untitled"),
        nFunsterStil  (10        ),
        hThisInstance (NULL      ),
        Icon          (NULL      )
        {}
    };

class M_HDC
    {
    private:

    int name;
    size_t sizeX_, sizeY_, posX_, posY_;
    HDC hdc;

    public:

    M_HDC (int _name, size_t _sizeX, size_t _sizeY, int _posX, int _posY)
        {
        Set (_name, _sizeX, _sizeY, _posX, _posY);
        }

    ~M_HDC ()
        {}

    inline int    getName  ();
    inline size_t getSizeX ();
    inline size_t getSizeY ();
    inline size_t getPosX  ();
    inline size_t getPosY  ();
    inline HDC   _getDC    ();

    inline void Set (int _name, size_t _sizeX, size_t _sizeY, int _posX, int _posY);

    inline void setPen   (HPEN     pen_);
    inline void setBrush (HBRUSH brush_);

    inline bool _translate_platform_ ();
    };

class M_CONFIGURATION
    {
    private:

    bool created;
    bool z_coordinate_inited;
    double zkx, zky;
    size_t number_hdcs;
    size_t selected;
    M_HDC* DCs;

    inline int  _GET_ (UINT code);

    public:

    M_CONFIGURATION () :
        z_coordinate_inited (false),
        created  (false),
        number_hdcs  (0),
        selected  (0),
        DCs  (NULL),
        zkx  (0.15),
        zky  (-0.1)
        {}

    ~M_CONFIGURATION ()
        {
        if (created == true)
            M_DELETE ();
        }

    inline void M_CREATE ();
    inline void M_ADD    (int _name, size_t _sizeX, size_t _sizeY, int _posX, int _posY);
    inline void M_DELETE ();
    inline void M_INITZ  (double kx, double ky);
    inline void M_INITZ  ();

    inline void M_SELECT (                          UINT code);
    inline void M_SELECT (HBRUSH brush_                      );
    inline void M_SELECT (               HPEN pen_           );
    inline void M_SELECT (HBRUSH brush_, HPEN pen_           );
    inline void M_SELECT (HBRUSH brush_, HPEN pen_, UINT code);
    inline void M_SELECT (HBRUSH brush_,            UINT code);
    inline void M_SELECT (               HPEN pen_, UINT code);

    inline void M_SETTEXTCOLOR (COLORREF color);
    inline void M_SETBKMODE    (COLORREF color);

    inline void M_TRANSLATE (         );
    inline void M_TRANSLATE (UINT code);

    inline bool M_LINE      (double x0, double y0, double x1, double y1, UINT code = __MGL_CFG_SELECTED_CODE__);
    inline bool M_RECTANGLE (double x0, double y0, double x1, double y1, UINT code = __MGL_CFG_SELECTED_CODE__);
    inline bool M_ELLIPSE   (double x0, double y0, double x1, double y1, UINT code = __MGL_CFG_SELECTED_CODE__);
    inline bool M_CIRCLE    (double x0, double y0, double r, UINT code = __MGL_CFG_SELECTED_CODE__);
    inline bool M_CIRCLE    (double x0, double y0, double z, double r, bool, UINT code = __MGL_CFG_SELECTED_CODE__);
    inline bool M_DRAWTEXT  (double x0, double y0, char* text,            UINT tp);
    inline bool M_DRAWTEXT  (double x0, double y0, char* text, UINT code, UINT tp);
    inline bool M_SPHERE    (double x0, double y0, double r, double delta);
    inline bool M_BITBLT    (int x0, int y0, size_t sizex, size_t sizey, HDC dc, int dc_x0, int dc_y0          );
    inline bool M_BITBLT    (int x0, int y0, size_t sizex, size_t sizey, HDC dc, int dc_x0, int dc_y0, UINT code);

    #warning to do: Add clear function

    inline HDC  M_GETDC ();
    };

            //}

            //{ REALESES

                //{ M_HDC

inline int    M_HDC::getName  ()
    {
    return name;
    }

inline size_t M_HDC::getSizeX ()
    {
    return sizeX_;
    }

inline size_t M_HDC::getSizeY ()
    {
    return sizeY_;
    }

inline size_t M_HDC::getPosX  ()
    {
    return posX_;
    }

inline size_t M_HDC::getPosY  ()
    {
    return posY_;
    }

inline HDC   M_HDC::_getDC    ()
    {
    return hdc;
    }

inline void  M_HDC::Set       (int _name, size_t _sizeX, size_t _sizeY, int _posX, int _posY)
    {
    sizeX_ = _sizeX;
    sizeY_ = _sizeY;
    posX_  = _posX ;
    posY_  = _posY ;
    name   =  _name;

    hdc = CreateCompatibleDC (win_hdc);
    if (!hdc)  M_ERROR ("Cannot create buffer: CreateCompatibleDC() failed");

    HBITMAP bmap = CreateCompatibleBitmap (win_hdc, sizeX_, sizeY_);
    if (!bmap) M_ERROR ("Cannot create buffer: CreateCompatibleBitmap() failed");

    SelectObject (hdc, bmap);
    }

inline void  M_HDC::setPen    (    HPEN pen_)
    {
    SelectObject (hdc, pen_);
    }

inline void  M_HDC::setBrush  (HBRUSH brush_)
    {
    SelectObject (hdc, brush_);
    }

inline bool  M_HDC::_translate_platform_ ()
    {
    BitBlt(win_hdc, posX_, posY_, sizeX_, sizeY_, hdc, 0, 0, SRCCOPY);
    }

                //}

                //{ M_CONFIGURATION

                    //{ IN LIBARY FUNCTIONS PRIVATE

inline int  M_CONFIGURATION::_GET_ (UINT code)
    {
    if (code == __MGL_CFG_SELECTED_CODE__) return selected;
    int i = 0;
    while (i <= number_hdcs)
        {
        if (i == number_hdcs)       break;
        if (code == DCs[i].getName()) break;
        i++;
        }
    if (i == number_hdcs)
        M_ERROR ("Cannot get object becose its not found, maybe code i not right");
    else
        return i;
    return -1;
    }

                    //}

                    //{ OUT FUNCTIONS OR FOR USER

inline void M_CONFIGURATION::M_CREATE ()
    {
    __MGL_CFG_NOT_CREATED_ASSERTED__

    created = true;
    DCs = (M_HDC*) calloc (number_hdcs, sizeof(M_HDC));
    }

inline void M_CONFIGURATION::M_ADD (int _name, size_t _sizeX, size_t _sizeY, int _posX, int _posY)
    {
    __MGL_CFG_CREATED_ASSERTED__

    int num = 0;
    for (int i = 0; i < number_hdcs; i++) if (_name == DCs[i].getName()) num++;
    if (num != 0) M_ERROR ("can't add to configuration becase name had already been declared");
    #warning to do: Do adding rightly
    else
        {
        if (_name == __MGL_CFG_SELECTED_CODE__) M_ERROR ("code is brownd by system (__MGL_CFG_SELECTED_CODE__)");
        else
            {
            number_hdcs++;
            //M_HDC* dcss = (M_HDC*) calloc (number_hdcs - 1, sizeof(M_HDC));
            //for (int i = 0; i < number_hdcs; i++)
            //    dcss[i].Set (DCs[i].getName(), DCs[i].getSizeX(), DCs[i].getSizeY(), DCs[i].getPosX(), DCs[i].getPosY());
            realloc (DCs, number_hdcs*sizeof(M_HDC));
            //for (int i = 0; i < number_hdcs; i++)
            //    DCs[i].Set (dcss[i].getName(), dcss[i].getSizeX(), dcss[i].getSizeY(), dcss[i].getPosX(), dcss[i].getPosY());
            //free (dcss);
            DCs[number_hdcs - 1].Set(_name, _sizeX, _sizeY, _posX, _posY);
            }
        }
    }

inline void M_CONFIGURATION::M_DELETE ()
    {
    __MGL_CFG_CREATED_ASSERTED__

    created = false;
    for (int i = 0; i < number_hdcs; i++)
        DeleteDC(DCs[i]._getDC());
    number_hdcs = 0;
    selected = 0;
    free(DCs);
    }

inline void M_CONFIGURATION::M_INITZ  (double kx, double ky)
    {
    __MGL_CFG_CREATED_ASSERTED__
    __MGL_CFG_Z_NOT_INITED_ASSERTED__

    zkx = kx;
    zky = ky;
    z_coordinate_inited = true;
    }

inline void M_CONFIGURATION::M_INITZ  ()
    {
    __MGL_CFG_CREATED_ASSERTED__
    __MGL_CFG_Z_NOT_INITED_ASSERTED__

    z_coordinate_inited = true;
    }

inline void M_CONFIGURATION::M_SELECT (                          UINT code)
    {
    selected = _GET_ (code);
    }

inline void M_CONFIGURATION::M_SELECT (HBRUSH brush_                      )
    {
    __MGL_CFG_CREATED_ASSERTED__

    DCs[selected   ].setBrush (brush_);
    }

inline void M_CONFIGURATION::M_SELECT (               HPEN pen_           )
    {
    __MGL_CFG_CREATED_ASSERTED__

    DCs[selected   ].setPen   (  pen_);
    }

inline void M_CONFIGURATION::M_SELECT (HBRUSH brush_, HPEN pen_           )
    {
    __MGL_CFG_CREATED_ASSERTED__

    DCs[selected   ].setBrush (brush_);
    DCs[selected   ].setPen   (  pen_);
    }

inline void M_CONFIGURATION::M_SELECT (HBRUSH brush_, HPEN pen_, UINT code)
    {
    __MGL_CFG_CREATED_ASSERTED__

    DCs[_GET_(code)].setBrush (brush_);
    DCs[_GET_(code)].setPen   (  pen_);
    }

inline void M_CONFIGURATION::M_SELECT (HBRUSH brush_,            UINT code)
    {
    __MGL_CFG_CREATED_ASSERTED__

    DCs[_GET_(code)].setBrush (brush_);
    }

inline void M_CONFIGURATION::M_SELECT (               HPEN pen_, UINT code)
    {
    __MGL_CFG_CREATED_ASSERTED__

    DCs[_GET_(code)].setPen   (  pen_);
    }

inline void M_CONFIGURATION::M_SETTEXTCOLOR (COLORREF color)
    {
    SetTextColor (DCs[selected]._getDC(), color);
    }

inline void M_CONFIGURATION::M_SETBKMODE    (COLORREF color)
    {
    SetBkMode (DCs[selected]._getDC(), color);
    }

inline void M_CONFIGURATION::M_TRANSLATE (        )
    {
    __MGL_CFG_CREATED_ASSERTED__

    DCs[selected   ]._translate_platform_();
    }

inline void M_CONFIGURATION::M_TRANSLATE (UINT code)
    {
    __MGL_CFG_CREATED_ASSERTED__

    DCs[_GET_(code)]._translate_platform_();
    }

inline bool M_CONFIGURATION::M_LINE (double x0, double y0, double x1, double y1, UINT code /* = __MGL_CFG_SELECTED_CODE__ */ )
    {
    __MGL_CFG_CREATED_ASSERTED__

    if (MoveToEx (DCs[_GET_(code)]._getDC(), x0, y0, NULL) == false)
        return false;
    if (LineTo   (DCs[_GET_(code)]._getDC(), x1, y1      ) == false)
        return false;

    return true;
    }

inline bool M_CONFIGURATION::M_RECTANGLE (double x0, double y0, double x1, double y1, UINT code /* = __MGL_CFG_SELECTED_CODE__ */ )
    {
    __MGL_CFG_CREATED_ASSERTED__

    return Rectangle (DCs[_GET_(code)]._getDC(), x0, y0, x1, y1) asserted;
    }

inline bool M_CONFIGURATION::M_ELLIPSE (double x0, double y0, double x1, double y1, UINT code /* = __MGL_CFG_SELECTED_CODE__ */ )
    {
    __MGL_CFG_CREATED_ASSERTED__

    return Ellipse (DCs[_GET_(code)]._getDC(), x0, y0, x1, y1) asserted;
    }

inline bool M_CONFIGURATION::M_CIRCLE (double x0, double y0, double r, UINT code /* = __MGL_CFG_SELECTED_CODE__ */ )
    {
    return M_ELLIPSE (x0 - r, y0 - r, x0 + r, y0 + r, code);
    }

inline bool M_CONFIGURATION::M_CIRCLE    (double x0, double y0, double z, double r, bool, UINT code /* = __MGL_CFG_SELECTED_CODE__ */ )
    {
    __MGL_CFG_Z_INITED_ASSERTED__

    return M_CIRCLE (x0 + zkx*z, y0 + z*zky, r, code);
    }

inline bool M_CONFIGURATION::M_DRAWTEXT  (double x0, double y0, char* text,            UINT tp)
    {
    __MGL_CFG_CREATED_ASSERTED__

    RECT rt;
    rt.left = x0;
    rt.top  = y0;
    return DrawText (DCs[selected   ]._getDC(), text, -1, &rt, tp);
    }

inline bool M_CONFIGURATION::M_DRAWTEXT  (double x0, double y0, char* text, UINT code, UINT tp)
    {
    __MGL_CFG_CREATED_ASSERTED__

    RECT rt;
    rt.left = x0;
    rt.top  = y0;
    return DrawText (DCs[_GET_(code)]._getDC(), text, -1, &rt, tp) asserted;
    }

inline bool M_CONFIGURATION::M_SPHERE    (double x0, double y0, double r, double delta)
    {
    __MGL_CFG_CREATED_ASSERTED__
    __MGL_CFG_Z_INITED_ASSERTED__

    //M_CIRCLE(x0, y0, r);

    for (double x = -r; x < r; x+= delta)
        {
        double zold = -r - 2;
        for (double y = -r; y < r; y+= delta)
            {
            double z;
            if (r*r - y*y - x*x >= 0)
                {
                z = sqrt (r*r - x*x - y*y);
                if (zold > -r - 1) M_LINE (x0 + x + zold*zkx, y0 + y - delta + zold*zky, x0 + x + z*zkx, y0 + y + z*zky);
                zold = z;
                }
            }
        }


    for (double x = -r; x < r; x+= delta)
        {
        double zold = -r - 2;
        for (double y = -r; y < r; y+= delta)
            {
            double z;
            if (r*r - y*y - x*x >= 0)
                {
                z = sqrt (r*r - x*x - y*y);
                if (zold > -r - 1) M_LINE (x0 + x - zold*zkx, y0 + y - delta - zold*zky, x0 + x - z*zkx, y0 + y - z*zky);
                zold = z;
                }
            }
        }

    for (double y = -r; y < r; y+= delta)
        {
        double zold = -r - 2;
        for (double x = -r; x < r; x+= delta)
            {
            double z;
            if (r*r - y*y - x*x >= 0)
                {
                z = sqrt (r*r - x*x - y*y);
                if (zold > -r - 1) M_LINE (x0 + x - delta + zold*zkx, y0 + y + zold*zky, x0 + x + z*zkx, y0 + y + z*zky);
                zold = z;
                }
            }
        }

    for (double x = -r; x < r; x+= delta)
        {
        double zold = -r - 2;
        for (double y = -r; y < r; y+= delta)
            {
            double z;
            if (r*r - y*y - x*x >= 0)
                {
                z = sqrt (r*r - x*x - y*y);
                if (zold > -r - 1) M_LINE (x0 + x - delta - zold*zkx, y0 + y - zold*zky, x0 + x - z*zkx, y0 + y - z*zky);
                zold = z;
                }
            }
        }
    }

inline bool M_CONFIGURATION::M_BITBLT    (int x0, int y0, size_t sizex, size_t sizey, HDC dc, int dc_x0, int dc_y0          )
    {
    __MGL_CFG_CREATED_ASSERTED__
    __MGL_WIN_CREATED_ASSERTED__

    return BitBlt (DCs[selected   ]._getDC(), x0, y0, sizex, sizey, dc, dc_x0, dc_y0, SRCCOPY) asserted;
    }

inline bool M_CONFIGURATION::M_BITBLT    (int x0, int y0, size_t sizex, size_t sizey, HDC dc, int dc_x0, int dc_y0, UINT code)
    {
    __MGL_CFG_CREATED_ASSERTED__
    __MGL_WIN_CREATED_ASSERTED__

    return BitBlt(DCs[_GET_(code)]._getDC(), x0, y0, sizex, sizey, dc, dc_x0, dc_y0, SRCCOPY);
    }

inline HDC  M_CONFIGURATION::M_GETDC ()
    {
    __MGL_CFG_CREATED_ASSERTED__

    return DCs[selected]._getDC();
    }

                    //}

                //}

            //}

        //}

        //{ FUNCTIONS

            //{ PROTOTIPES

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

void _thread_massage (void* winstr_param);

HICON MglIcon ();

void MCreateWindow (_m_win_struct_ winstr);

HDC   MLoadImage (char* filename);
HICON MLoadIcon  (char* filename);

inline int MMessageBox (char* title, char* text, UINT flag = MB_OK);

inline POINT MGetMousePos ();
inline int MGetMouseX ();
inline int MGetMouseY ();
inline int MGetMouseButtons ();

inline HDC MCreateComatibleDC (size_t sizeX_, size_t sizeY_);

inline bool MNotifyIcon (HICON icon, char* Tip, char* InfoTitle, char* Info, DWORD flags = NIIF_INFO);

            //}

            //{ REALESES

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
    switch (message)                  /* handle the messages */
        {
        case WM_DESTROY:
            {
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
            }

        case WM_PAINT:
            {
            //while (WinBlocked == true) Sleep(0);
            //WinBlocked = true;
            //cout << WinBlocked << true << "\n";
            //BitBlt (GetDC(hwnd), 0, 0, WinSizeX, WinSizeY, hdc_buf_2, 0, 0, SRCCOPY);
            //PAINTSTRUCT Ps = {};
            //HDC hdc = BeginPaint(hwnd, &Ps);
            //LPCWSTR message="My First Window";
            //RECT rect;
            //HDC wdc = GetWindowDC(hwnd);
            //GetClientRect (hwnd, &rect) ;
            //SetTextColor (win_hdc, RGB(200, 100, 0));
            //SetBkMode(win_hdc, TRANSPARENT);
            //rect.left = 40;
            //rect.top = 100;
            //DrawText (win_hdc, "My First Window _", -1, &rect, DT_NOCLIP) ;
            //DeleteDC(wdc);
            //HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
            //SelectObject(hdc, hBrush);
            //HPEN pen = CreatePen(PS_DASHDOTDOT, 1, RGB(0, 255, 0));
            //SelectObject(hdc, pen);
            //Rectangle (hdc, 110, 100, 200, 200);
            //DeleteObject(hBrush);
            //EndPaint(hwnd, &Ps);
            break;
            }

        case WM_LBUTTONUP:
        case WM_LBUTTONDOWN:
        case WM_RBUTTONUP:
        case WM_RBUTTONDOWN:
        case WM_MBUTTONUP:
        case WM_MBUTTONDOWN:
        case WM_MOUSEMOVE:
            {
            _M_MousePos.x   = LOWORD (lParam);
            _M_MousePos.y   = HIWORD (lParam);
            _M_MouseButtons = (int) wParam;
            break;
            }

        case WM_MOUSEWHEEL:
            {
            _M_MouseWheel+= GET_WHEEL_DELTA_WPARAM(wParam)/120;
            break;
            }

        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
        }

    return 0;
    }

void _thread_massage (void* winstr_param)
    {
    _m_win_struct_* winstr = (_m_win_struct_*) winstr_param;

    WNDCLASSEX wincl = {sizeof (WNDCLASSEX)};        /* Data structure for the windowclass */

    wincl.hInstance = winstr->hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.hIcon = winstr->Icon;
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.hbrBackground = (HBRUSH) GetStockObject(HOLLOW_BRUSH);

    if (!RegisterClassEx (&wincl))
        M_ERROR("RegisterClassEx failed");

    winstr->hwnd = CreateWindowEx (
           0,                        /* Extended possibilites for variation */
           szClassName,              /* Classname */
           winstr->Name,             /* Title Text */
           WS_OVERLAPPEDWINDOW,      /* default window */
           CW_USEDEFAULT,            /* Windows decides the position */
           CW_USEDEFAULT,            /* where the window ends up on the screen */
           winstr->sizeX,            /* The programs width */
           winstr->sizeY,            /* and height in pixels */
           HWND_DESKTOP,             /* The window is a child-window to desktop */
           NULL,                     /* No menu */
           winstr->hThisInstance,    /* Program Instance handler */
           NULL                      /* No Window Creation data */
           );

    ShowWindow (winstr->hwnd, winstr->nFunsterStil);

    win_hdc = GetDC (winstr->hwnd);
    win_hwnd = winstr->hwnd;

    WinCreated = true;

    MSG msg = {};            /* Here messages to the application are saved */
    while (GetMessage (&msg, NULL, 0, 0))
        {
        TranslateMessage (&msg);
        DispatchMessage  (&msg);

        Sleep (0);
        }
    }

inline void MCreateWindow (_m_win_struct_ winstr)
    {
    __MGL_WIN_NOT_CREATED_ASSERTED__

    _beginthread (_thread_massage, 0, &winstr);
    while (WinCreated == false) {}
    }

HDC MLoadImage (char* filename)
    {
    HBITMAP image_ = (HBITMAP) LoadImage (NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    if (!image_) M_ERROR ("LoadImage failed, maybe file name is not correct");

    HDC dc = CreateCompatibleDC (win_hdc);

    SelectObject(dc, image_);

    return dc;
    }

HICON MLoadIcon (char* filename)
    {
    return (HICON) LoadImage (NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    }

HICON MglIcon ()
    {
    const char image16 [16*16+1] =
        "0000001111000000"
        "0000112222110000"
        "0001222222221000"
        "0012222222222100"
        "0122222222222210"
        "0123232222222210"
        "1223232222222321"
        "1223232222222321"
        "1232323223223221"
        "1232323232323221"
        "0132323223323310"
        "0122222222322210"
        "0012222233222100"
        "0001222222221000"
        "0000112222110000"
        "0000001111000000";

    const COLORREF pal[4] = { RGB(239, 228, 176), RGB(0, 166, 71), RGB(181, 230, 29), RGB(250, 7, 44) };

    HDC dcMask  = MCreateComatibleDC(16, 16);
    HDC dcColor = MCreateComatibleDC(16, 16);

    for (int i = 0; i < 16*16; i++)
        {
        SetPixel (dcColor, i % 16, i / 16, pal [image16[i] - '0']);
        }

    ICONINFO info = { true, 0, 0, (HBITMAP) GetCurrentObject (dcMask,  OBJ_BITMAP),
                                  (HBITMAP) GetCurrentObject (dcColor, OBJ_BITMAP) };

    HICON icon = CreateIconIndirect (&info);

    DeleteDC (dcMask);
    DeleteDC (dcColor);

    return icon;
    }

inline int MMessageBox (char* title, char* text, UINT flag /* == MB_OK */ )
    {
    return MessageBox (win_hwnd, text, title, flag);
    }

inline POINT MGetMousePos ()
    {
    return _M_MousePos;
    }

inline int MGetMouseX ()
    {
    return _M_MousePos.x;
    }

inline int MGetMouseY ()
    {
    return _M_MousePos.y;
    }

inline int MGetMouseButtons ()
    {
    return _M_MouseButtons;
    }

inline int MDeltaMouseWheel ()
    {
    int a = _M_MouseWheel;
    _M_MouseWheel = 0;
    return a;
    }

HDC MCreateComatibleDC (size_t sizeX_, size_t sizeY_)
    {
    __MGL_WIN_CREATED_ASSERTED__

    HDC hdc = CreateCompatibleDC (win_hdc);
    if (!hdc)  M_ERROR ("Cannot create buffer: CreateCompatibleDC() failed");

    HBITMAP bmap = CreateCompatibleBitmap (win_hdc, sizeX_, sizeY_);
    if (!bmap) M_ERROR ("Cannot create buffer: CreateCompatibleBitmap() failed");

    SelectObject (hdc, bmap) asserted;

    return hdc;
    }

inline bool MNotifyIcon (HICON icon, char* Tip, char* InfoTitle, char* Info, DWORD flags /* == NIIF_INFO */ )
    {
    NOTIFYICONDATA nid = { sizeof (nid) };

    if (!icon) icon = MglIcon();

    nid.uFlags = NIF_ICON | NIF_TIP | NIF_INFO;
    nid.hWnd   = NULL;
    nid.uID    = 1;
    nid.hIcon  = icon;
    strncpy    (nid.szTip, Tip, sizeof (nid.szTip));
    strncpy    (nid.szInfoTitle, InfoTitle, sizeof (nid.szInfoTitle));
    strncpy    (nid.szInfo, Info, sizeof(nid.szInfo));
    nid.dwInfoFlags = flags;

    Shell_NotifyIcon (NIM_ADD,    &nid) asserted;
    Shell_NotifyIcon (NIM_MODIFY, &nid) asserted;

    if (nid.hIcon) DestroyIcon (nid.hIcon);

    return true;
    }

            //}

        //}

        }

    //}

#endif                               //}
