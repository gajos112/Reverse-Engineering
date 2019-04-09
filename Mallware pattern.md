# Malicious Activity API Pattern

- Key Logger(FindWindowA, ShowWindow, GetAsyncKeyState) (SetWindowsHookEx, RegisterHotKey, GetMessage,UnhookWindowsHookEx)

- Screen Capture(GetDC, GetWindowDC), CreateCompatibleDC, CreateCompatibleBitmap, SelectObject, BitBlt, WriteFile 

- Antidebugging(IsDebuggerPresent, CheckRemoteDebuggerPresent, OutputDebugStringA, OutputDebugStringW) 

- Downloader (URLDownloadToFile, WinExec,ShellExecute)

- DLL InjectionOpenProcess, VirtualAllocEx, WriteProcessMemory, CreateRemoteThread 

- Dropper (FindResource, LoadResource, SizeOfResourceFor


1. CreateProcessW
2. VirtualAllocEx
3. WriteProcessMemory
4. WriteProcessMemory
5. GetThreadContext
6. SetThreadContext
7. ResumeThread
