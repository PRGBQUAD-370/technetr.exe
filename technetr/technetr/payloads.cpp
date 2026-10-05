#include "technetr.h"

int red = 0, green = 0, blue = 0;
bool ifblue = false;

COLORREF Hue ( int length )
{
    if (red != length) {
        red++;
        if (ifblue)
            return RGB ( red, 0, length );
        else
            return RGB ( red, 0, 0 );
    }
    else if (green != length) {
        green++;
        return RGB ( length, green, 0 );
    }
    else if (blue != length) {
        blue++;
        return RGB ( 0, length, blue );
    }
    else {
        red = green = blue = 0;
        ifblue = true;
        return RGB ( 0, 0, 0 );
    }
}

DWORD 
WINAPI 
triangles 
( LPVOID lpParam )
{

    while (1) {
        int w = GetSystemMetrics ( 0 ), h = GetSystemMetrics ( 1 );
        HDC hdc = GetDC ( 0 );
        HPEN hPen = CreatePen ( PS_SOLID, 2, RGB ( 255, 0, 0 ) );
        HPEN hOldPen = SelectPen ( hdc, hPen );

        HBRUSH hBrush = CreateSolidBrush ( RGB ( 0, 0, 255 ) );
        HBRUSH hOldBrush = SelectBrush ( hdc, hBrush );

        POINT vertices[] = { {rand ( ) % w, rand ( ) % h}, {rand ( ) % w, rand ( ) % h}, {rand ( ) % w, rand ( ) % h} };
        Polygon ( hdc, vertices, sizeof ( vertices ) / sizeof ( vertices[0] ) );

        SelectBrush ( hdc, hOldBrush );
        DeleteObject ( hBrush );

        SelectPen ( hdc, hOldPen );
        DeleteObject ( hPen );
        ReleaseDC ( 0, hdc );
    }
	return 0;
}

DWORD
WINAPI
train1
( LPVOID lpParam )
{

    int w = GetSystemMetrics ( 0 );
    int h = GetSystemMetrics ( 1 );
    while (1) {
        HDC hdc = GetDC ( 0 );
        BitBlt ( hdc, 0, 0, w, h, hdc, -30, 0, SRCCOPY );
        BitBlt ( hdc, 0, 0, w, h, hdc, w - 30, 0, SRCCOPY );
        BitBlt ( hdc, 0, 0, w, h, hdc, 0, -30, SRCCOPY );
        BitBlt ( hdc, 0, 0, w, h, hdc, 0, h - 30, SRCCOPY );
        ReleaseDC ( 0, hdc );
    }
    return 0;
}

DWORD
WINAPI
ColorLines
( LPVOID lpParam )
{

    while (1) {
        HDC hdc = GetDC ( NULL );
        int w = GetSystemMetrics ( SM_CXSCREEN );
        int h = GetSystemMetrics ( SM_CYSCREEN );
        for (int i = 0; i < 65; i++) {
            HPEN pen = CreatePen ( PS_SOLID, 1 + (rand ( ) % 5), RGB ( rand ( ) % 256, rand ( ) % 256, rand ( ) % 256 ) );
            SelectObject ( hdc, pen );
            MoveToEx ( hdc, rand ( ) % w, rand ( ) % h, NULL );
            LineTo ( hdc, rand ( ) % w, rand ( ) % h );
            DeleteObject ( pen );
        }
        ReleaseDC ( NULL, hdc );
        Sleep ( 100 );
    }
    return 0;
}

DWORD
WINAPI
ErasePause
( LPVOID lpParam )
{

    HDC hdc = GetDC ( 0 );
    int w = GetSystemMetrics ( 0 );
    int h = GetSystemMetrics ( 1 );
    while (TRUE)
    {
        hdc = GetDC ( 0 );
        BitBlt ( hdc, 1, 1, w, h, hdc, 0, 0, SRCERASE );
        BitBlt ( hdc, -1, -1, w, h, hdc, 0, 0, SRCERASE );
        ReleaseDC ( GetDesktopWindow ( ), hdc );
        DeleteDC ( hdc );
    }
    return 0;
}

DWORD
WINAPI
patblt
( LPVOID lpParam )
{

    while (1) {
        HDC hdc = GetDC ( NULL );
        int w = GetSystemMetrics ( SM_CXSCREEN ),
            h = GetSystemMetrics ( SM_CYSCREEN );

        HBRUSH brush = CreateSolidBrush ( RGB ( rand ( ) % 255, rand ( ) % 255, rand ( ) % 255 ) );
        SelectObject ( hdc, brush );
        PatBlt ( hdc, 0, 0, w, h, PATINVERT );
        DeleteObject ( brush );
        ReleaseDC ( 0, hdc );
    }
    return 0;
}

DWORD
WINAPI
CursorDraw
( LPVOID lpParam )
{

    UNREFERENCED_PARAMETER ( lpParam );
    RECT rect;
    GetWindowRect ( GetDesktopWindow ( ), &rect );
    int w = rect.right - rect.left;
    int h = rect.bottom - rect.top;
    HDC hdcDesktop = GetDC ( GetDesktopWindow ( ) );
    for (int t = 0;; t++)
    {
        CURSORINFO curInf = { sizeof ( CURSORINFO ) };
        if (GetCursorInfo ( &curInf ) && curInf.hCursor)
        {
            int spawnCount = (rand ( ) % 6) + 1;
            for (int i = 0; i < spawnCount; i++)
            {
                int x = rand ( ) % (w - GetSystemMetrics ( SM_CXCURSOR ) + 1);
                int y = rand ( ) % (h - GetSystemMetrics ( SM_CYCURSOR ) + 1);

                DrawIcon ( hdcDesktop, x, y, curInf.hCursor );
            }
            DestroyCursor ( curInf.hCursor );
        }
        Sleep ( rand ( ) % 8 + 3 );
    }
    ReleaseDC ( GetDesktopWindow ( ), hdcDesktop );
    return 0;
}

DWORD 
WINAPI 
DesktopCopyBlt
( LPVOID lpParam ) 
{
    HDC hdc;
    int w = GetSystemMetrics ( 0 );
    int h = GetSystemMetrics ( 1 );
    while (1) {
        hdc = GetDC ( 0 );
        BitBlt ( hdc, rand ( ) % 1, rand ( ) % 1, w, h, hdc, rand ( ) % 1, rand ( ) % 1, SRCCOPY );
        Sleep ( 100 );
        ReleaseDC ( 0, hdc );
    }
	return 0;
}

DWORD
WINAPI
train2
( LPVOID lpParam )
{

    int w = GetSystemMetrics ( 0 );
    int h = GetSystemMetrics ( 1 );
    while (1) {
        HDC hdc = GetDC ( 0 );
        BitBlt ( hdc, 0, 0, w, h, hdc, -30, 0, SRCCOPY );
        BitBlt ( hdc, 0, 0, w, h, hdc, w - 30, 0, SRCCOPY );
        ReleaseDC ( 0, hdc );
        Sleep ( 10 );
    }
    return 0;
}

DWORD
WINAPI
PlainRGBQuad
( LPVOID lpParam )
{

    HDC desk = GetDC ( 0 ); HWND wnd = GetDesktopWindow ( );
    int sw = GetSystemMetrics ( 0 ), sh = GetSystemMetrics ( 1 );
    BITMAPINFO bmi = { 40, sw, sh, 1, 24 };
    PRGBTRIPLE rgbtriple;
    for (;;) {
        desk = GetDC ( 0 );
        HDC deskMem = CreateCompatibleDC ( desk );
        HBITMAP scr = CreateDIBSection ( desk, &bmi, 0, (void**)&rgbtriple, 0, 0 );
        SelectObject ( deskMem, scr );
        BitBlt ( deskMem, 0, 0, sw, sh, desk, 0, 0, SRCERASE );
        for (int i = 0; i < sw * sh; i++) {
            int x = i % sw, y = i / sh;
            rgbtriple[i].rgbtRed += x & y;
            rgbtriple[i].rgbtGreen += x & y;
            rgbtriple[i].rgbtBlue += x & y;
        }
        BitBlt ( desk, 0, 0, sw, sh, deskMem, 0, 0, SRCERASE );
        ReleaseDC ( wnd, desk );
        DeleteDC ( desk ); DeleteDC ( deskMem ); DeleteObject ( scr ); DeleteObject ( wnd ); DeleteObject ( rgbtriple ); DeleteObject ( &sw ); DeleteObject ( &sh ); DeleteObject ( &bmi );
    }
    return 0;
}

DWORD
WINAPI
sustainepic
( LPVOID lpParam )
{

    int w = GetSystemMetrics ( 0 );
    int h = GetSystemMetrics ( 1 );
    while (1) {
        HDC hdc = GetDC ( 0 );
        HBRUSH brush = CreateSolidBrush ( Hue ( 239 ) );
        SelectObject ( hdc, brush );
        BitBlt ( hdc, -30, 0, w, h, hdc, -30, 0, SRCCOPY );
        BitBlt ( hdc, 0, 0, w, h, hdc, 0, -30, 0x1900ac010e );
        BitBlt ( hdc, 0, 0, w, h, hdc, 0, h - 30, 0x1900ac010e );
        DeleteObject ( brush );
        ReleaseDC ( 0, hdc );
    }
    return 0;
}


VOID
WINAPI
sound1
( )
{

    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL );

    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof ( buffer ); ++t)

        buffer[t] = static_cast<char> ( t % 25 | t << 2 + t >> 1 ^ t >> 2 | t << 1 - t >> 3 ^ t >> 6 + t << 12 ^ t >> 6 );

    WAVEHDR header = { buffer, sizeof ( buffer ), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );

    Sleep ( 30000 );

    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutClose ( hWaveOut );

}

VOID
WINAPI
sound2
( )
{

    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL );

    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof ( buffer ); ++t)

        buffer[t] = static_cast<char> ( (t >> 6 | t << 1) + (6) + (t) ^ t >> 5 | t << 1 );

    WAVEHDR header = { buffer, sizeof ( buffer ), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );

    Sleep ( 30000 );

    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutClose ( hWaveOut );

}

VOID
WINAPI
sound3
( )
{

    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL );

    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof ( buffer ); ++t)

        buffer[t] = static_cast<char> ( (t * ((t & 4096 ? t % 65536 < 59392 ? 7 : t & 7 : 16) ^ (1 & t >> 14)) >> (3 & (0 - t) >> (t & 2048 ? 2 : 10))) & 128 ? 255 : 0 );

    WAVEHDR header = { buffer, sizeof ( buffer ), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );

    Sleep ( 30000 );

    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutClose ( hWaveOut );

}

VOID
WINAPI
sound4
( )
{

    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL );
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof ( buffer ); ++t)
        buffer[t] = static_cast<char> ( (t >> (t >> 12) % 4) + t * (1 + (1 + (t >> 16) % 6) * (t >> 10) * (t >> 11) % 8) ^ t >> 13 ^ t >> 6 );

    WAVEHDR header = { buffer, sizeof ( buffer ), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );

    Sleep ( 30000 );

    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutClose ( hWaveOut );

}

VOID
WINAPI
sound5
( )
{

    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL );

    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof ( buffer ); ++t)

        buffer[t] = static_cast<char> ( (t & 4095) * (255 & t * (t & t >> 13)) >> 12 ) + (127 & t * (234 & t >> 8 & t >> 3) >> (3 & t >> 14));

    WAVEHDR header = { buffer, sizeof ( buffer ), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );

    Sleep ( 30000 );

    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutClose ( hWaveOut );

}

VOID
WINAPI
sound6
( )
{

    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL );

    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof ( buffer ); ++t) {

        int8_t sample = static_cast<int8_t> ( ((t / 2 * (4 | t >> 13 & 3) >> (~t >> 11 & 1) | ~t >> 5) & 127) + (t * (t >> 11 & t >> 13) * (~t >> 9 & 3) & 127) / 2 + ((t & 4096 ? (t * (t ^ t % 255) | t >> 5) >> 1 : t >> 4 | (t & 8192 ? t << 1 : t)) & 127) + 64 );
        buffer[t] = static_cast<char> ( sample + 128 );

    }

    WAVEHDR header = { buffer, sizeof ( buffer ), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );

    Sleep ( 30000 );

    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutClose ( hWaveOut );

}

VOID
WINAPI
sound7
( )
{

    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL );

    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof ( buffer ); ++t)

        buffer[t] = static_cast<char> ( t & t >> 6 | t << 1 + t >> 5 | t << 3 | t >> 3 | t >> 2 | t << 1 );

    WAVEHDR header = { buffer, sizeof ( buffer ), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );

    Sleep ( 30000 );

    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutClose ( hWaveOut );

}

VOID
WINAPI
sound8
( )
{

    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL );

    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof ( buffer ); ++t)

        buffer[t] = static_cast<char> ( (t >> 6 | t << 1) + (t >> 5 | t << 3 | t >> 3) | t >> 2 | t << 1 | 9 * t & t >> 4 | 5 * t & t >> 7 | 3 * t & t >> 10 | t >> 1 );

    WAVEHDR header = { buffer, sizeof ( buffer ), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );

    Sleep ( 30000 );

    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutClose ( hWaveOut );

}
