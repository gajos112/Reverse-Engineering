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

If the dll is imported dynamically,walking through the imports will not give you any idea about the dlls and functions it uses. In such a case, debug the application (if possible). Set a breakpoint on **kernel32.LoadLibraryA** / **kernel32.LoadLibraryW** or even the undocumented **ntdll.LdrLoadDll** and run the app. When the breakpoint is hit you immediately know which dll it is trying to import. Similarly setting a breakpoint on **GetProcAddress** will reveal the function the application wants to use.

# Changes the protection on a memory region

**VirtualProtect** - Changes the protection on a region of committed pages in the virtual address space of the calling process.

BOOL VirtualProtect(

  LPVOID lpAddress,
  
  SIZE_T dwSize,
  
  DWORD  flNewProtect,
  
  PDWORD lpflOldProtect
  
);



**PAGE_EXECUTE_READWRITE** - 0x40 - Enables execute, read-only, or read/write access to the committed region of pages.
Windows Server 2003 and Windows XP: This attribute is not supported by the CreateFileMapping function until Windows XP with SP2 and Windows Server 2003 with SP1.

# Looking for process

- **CreateToolhelp32Snapshot** 	Flags: TH32CS_SNAPPROCESS ProcessId: 0
Takes a snapshot of the specified processes, as well as the heaps, modules, and threads used by these processes. If the function succeeds, it returns an open handle to the specified snapshot.

- **Process32FirstW** 	ProcessName: [System Process] ProcessId: 0

- **Process32NextW** 	ProcessName: System ProcessId: 4

- **Process32NextW** 	ProcessName: explorer.exe ProcessId: 1632

- **NtOpenProcess** 	ProcessHandle: 0x00000174 ProcessIdentifier: 1632

- **NtAllocateVirtualMemory**	Protection: PAGE_EXECUTE_REDWRITE	ProcessHandle: 0x0000174	RegionSize: 0x00026000	BaseAddress: 0x02b0000

- **WriteProcessMemory**	ProcessHandle: 0x0000174	BaseAddress: 0x02b0000


# APIs

**Creation**
- CreateFileA
- DeleteFileA
- WriteFile
- fopen
- fwrite

**Internet**
- InternetConnectA
- InternetOpenA
- InternetReadFile
- InternetOpenUrlA
- InternetReadFile
- InternetSetCookieA
- WSACleanup
- WSAStartup

**Registry**
- RegCreateKey
- RegDeleteKeyA
- RegDeleteValueA
- RegSetValueExA

**Looking for process**
- CreateToolhelp32Snapshot
- Process32FirstW
- Process32NextW
- NtOpenProcess
- NtAllocateVirtualMemory
- WriteProcessMemory

**DLL load**
- kernel32 LoadLibraryA
- kernel32 LoadLibraryW
- ntdll.dll LdrLoadDll
- GetProcAddress
