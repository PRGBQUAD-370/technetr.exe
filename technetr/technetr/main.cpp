#include "technetr.h"

VOID
WINAPI
Initialize
( VOID )
{

    HMODULE hModUser32 = LoadLibraryW ( L"user32.dll" );
    BOOL ( WINAPI * SetProcessDPIAware )(VOID) = (BOOL ( WINAPI* )(VOID))GetProcAddress ( hModUser32, "SetProcessDPIAware" );

    if ( SetProcessDPIAware ) SetProcessDPIAware ( );
    FreeLibrary ( hModUser32 );

}

INT
WINAPI
wWinMain (
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ PWSTR pszCmdLine,
    _In_ INT nShowCmd
)
{
    UNREFERENCED_PARAMETER ( hInstance );
    UNREFERENCED_PARAMETER ( hPrevInstance );
    UNREFERENCED_PARAMETER ( pszCmdLine );
    UNREFERENCED_PARAMETER ( nShowCmd );

    Initialize ( );

    if (MessageBoxW ( NULL, L"This is a technetr.exe,\r\nRun?", L"technetr.exe", MB_YESNO | MB_ICONWARNING ) == IDNO) {
        ExitProcess ( 0 );
    }
    else {

        if (MessageBoxW ( NULL, L"Are you sure?", L"technetr.exe - Final Warning", MB_YESNO | MB_ICONWARNING ) == IDNO) {
            ExitProcess ( 0 );
        }
        else

            Sleep ( 1000 );

        HANDLE hThread1 = CreateThread ( 0, 0, triangles, 0, 0, 0 );
        sound1 ( );
        TerminateThread ( hThread1, 0 );
        CloseHandle ( hThread1 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN );
        Sleep ( 100 );
        HANDLE hThread2 = CreateThread ( 0, 0, train1, 0, 0, 0 );
        HANDLE hThread2dot1 = CreateThread ( 0, 0, ColorLines, 0, 0, 0 );
        sound2 ( );
        TerminateThread ( hThread2, 0 );
        CloseHandle ( hThread2 );
        TerminateThread ( hThread2dot1, 0 );
        CloseHandle ( hThread2dot1 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN );
        Sleep ( 100 );
        HANDLE hThread3 = CreateThread ( 0, 0, ErasePause, 0, 0, 0 );
        sound3 ( );
        TerminateThread ( hThread3, 0 );
        CloseHandle ( hThread3 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN );
        Sleep ( 100 );
        HANDLE hThread4 = CreateThread ( 0, 0, patblt, 0, 0, 0 );
        sound4 ( );
        TerminateThread ( hThread4, 0 );
        CloseHandle ( hThread4 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN );
        Sleep ( 100 );
        HANDLE hThread5 = CreateThread ( 0, 0, CursorDraw, 0, 0, 0 );
		HANDLE hThread5dot1 = CreateThread ( 0, 0, DesktopCopyBlt, 0, 0, 0 );
        sound5 ( );
        TerminateThread ( hThread5, 0 );
        CloseHandle ( hThread5 );
        TerminateThread ( hThread5dot1, 0 );
        CloseHandle ( hThread5dot1 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN );
        Sleep ( 100 );
        HANDLE hThread6 = CreateThread ( 0, 0, train2, 0, 0, 0 );
        sound6 ( );
        TerminateThread ( hThread6, 0 );
        CloseHandle ( hThread6 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN );
        Sleep ( 100 );
        HANDLE hThread7 = CreateThread ( 0, 0, PlainRGBQuad, 0, 0, 0 );
        sound7 ( );
        TerminateThread ( hThread7, 0 );
        CloseHandle ( hThread7 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN );
        Sleep ( 100 );
        HANDLE hThread8 = CreateThread ( 0, 0, sustainepic, 0, 0, 0 );
        sound8 ( );
        TerminateThread ( hThread8, 0 );
        CloseHandle ( hThread8 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN );
        Sleep ( 100 );

        return 0;

    }
}