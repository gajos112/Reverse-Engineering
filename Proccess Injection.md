# CreateProcessv

CreateProcess(NULL, commandLine, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &startupinfo, &processinfo)
 
// a function that will replace CreateProcessInternalW

// gets called whenever a process creates a child process

DWORD WINAPI CreateProcessInternalGuarded(

  __in         DWORD unknown1,                              // always (?) NULL
  
  __in_opt     LPCTSTR lpApplicationName,
  
  __inout_opt  LPTSTR lpCommandLine,
  
  __in_opt     LPSECURITY_ATTRIBUTES lpProcessAttributes,
  
  __in_opt     LPSECURITY_ATTRIBUTES lpThreadAttributes,
  
  __in         BOOL bInheritHandles,
  
  __in         DWORD dwCreationFlags,
  
  __in_opt     LPVOID lpEnvironment,
  
  __in_opt     LPCTSTR lpCurrentDirectory,
  
  __in         LPSTARTUPINFO lpStartupInfo,
  
  __out        LPPROCESS_INFORMATION lpProcessInformation,
  
__in DWORD unknown2 // always (?) NULL


- https://www.geoffchappell.com/studies/windows/win32/index.htm?tx=22

- http://www-users.math.umn.edu/~math-sa-sara0050/space16/slides/space2016121708-06.pdf

# SELF PROCCES INJECTION

CreateProcessInternalW (suspended) ->  Inject code (WriteProcessMemory) (NtWriteVivrtualMemory) -> Resume proccess (NtResumeThreat)

BOOL WriteProcessMemory(
  HANDLE  hProcess,
  LPVOID  lpBaseAddress,
  LPCVOID lpBuffer,
  SIZE_T  nSize,
  SIZE_T  *lpNumberOfBytesWritten
);

- hProcess - A handle to the process memory to be modified. The handle must have PROCESS_VM_WRITE and PROCESS_VM_OPERATION access to the process.

- lpBaseAddress - A pointer to the base address in the specified process to which data is written. Before data transfer occurs, the system verifies that all data in the base address and memory of the specified size is accessible for write access, and if it is not accessible, the function fails.

- lpBuffer - A pointer to the buffer that contains data to be written in the address space of the specified process.

- nSize - The number of bytes to be written to the specified process.

- lpNumberOfBytesWritten - A pointer to a variable that receives the number of bytes transferred into the specified process. This parameter is optional. If lpNumberOfBytesWritten is NULL, the parameter is ignored.
