/*============================================================================

  main.c

  Main REPL loop

  Copyright (c)2026 Kevin Boone, GPLv3.0

============================================================================*/

#include <efi/efi.h>
#include <efi/efilib.h>
#include "defs.h" 
#include "string.h" 
#include "console.h" 

/*============================================================================

  efi_main() is the entry point for the UEFI program. It is called by the
  crt.o stub appropriate for this kind of program, which is part of
  gnu-efi

  FWIW efi_main() gets passed a handle to the disk image from which the
  program was loaded, and also a reference to the EFI system table. This
  reference sets up the standard "ST", "BS", etc., API structures that 
  will be used extensively.

============================================================================*/

EFI_STATUS EFIAPI efi_main (EFI_HANDLE image_handle, 
    EFI_SYSTEM_TABLE *system_table) 
  {
  InitializeLib (image_handle, system_table);

  console_clear();
  Print(L"Kevin's dumb EFI shell\n");

  while (1)
    {
    Print(L"> ");

    char line[256];
    // Read a line and echo it back
    if (console_readline (line, sizeof (line)) == 0)
      {
      if (strcmp (line, "reboot") == 0)
        {
        RT->ResetSystem (EfiResetCold, 0, 0, NULL);
        }
      else if (strcmp (line, "clear") == 0)
        { 
        console_clear(); 
        }
      else
        {
        Print (L"You said: %a\n", line);
        }
      }
    else
      {
      // Interrupted
      Print(L"\n");
      }
    }

  // We never get here
  return EFI_SUCCESS;
  }
