# Malicious Activity API Pattern

- Key Logger(FindWindowA, ShowWindow, GetAsyncKeyState) (SetWindowsHookEx, RegisterHotKey, GetMessage,UnhookWindowsHookEx)

- Screen Capture(GetDC, GetWindowDC), CreateCompatibleDC, CreateCompatibleBitmap, SelectObject, BitBlt, WriteFile 

- Antidebugging(IsDebuggerPresent, CheckRemoteDebuggerPresent, OutputDebugStringA, OutputDebugStringW) 

- Downloader (URLDownloadToFile, WinExec,ShellExecute)

- DLL InjectionOpenProcess, VirtualAllocEx, WriteProcessMemory, CreateRemoteThread 

- Dropper (FindResource, LoadResource, SizeOfResourceFor


# Example

1. CreateProcessW
2. VirtualAllocEx
3. WriteProcessMemory
4. WriteProcessMemory
5. GetThreadContext
6. SetThreadContext
7. ResumeThread

# Dynamic imports

If the dll is imported dynamically,walking through the imports will not give you any idea about the dlls and functions it uses. In such a case, debug the application (if possible). Set a breakpoint on kernel32.LoadLibraryA / kernel32.LoadLibraryW or even the undocumented ntdll.LdrLoadDll and run the app. When the breakpoint is hit you immediately know which dll it is trying to import. Similarly setting a breakpoint on GetProcAddress will reveal the function the application wants to use.
