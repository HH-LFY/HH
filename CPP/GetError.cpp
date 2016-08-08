void show( )
{
    TCHAR *lpMsgBuf;
    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|
                  FORMAT_MESSAGE_FROM_SYSTEM,
                  NULLGetLastError(),
                  MAKELANGlD(LANG_NEUTRAL,SUBLANG_DEFAULT),
                  (LPTSTR)&lpMsgBuf,
                  0,
                  NULL);
    MessageBox(NULL,lpMsgBuf,"",MB_ICONERROR);
}
