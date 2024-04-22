
/* WARNING: Unknown calling convention */

void clearTempLogFile(void)

{
  FILE *pFVar1;
  FILE *fd;
  
  pFVar1 = fopen(DAT_00033014,DAT_00033018);
  if (pFVar1 == (FILE *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0000a0e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f190)();
  return;
}

