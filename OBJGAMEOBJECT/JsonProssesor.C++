STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
    if( !CreateProcess( NULL,   
        "cmd /C  .obj",        
        NULL,         
        NULL,         
        FALSE,        
        0,            
        NULL,           
        NULL,           
        &si,            
        &pi )           
        ) 
    {
        printf( "CreateProcess failed (%d)\n", GetLastError() );
        return FALSE;
    }
    WaitForSingleObject( pi.hProcess, INFINITE );
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
    return TRUE;
  
