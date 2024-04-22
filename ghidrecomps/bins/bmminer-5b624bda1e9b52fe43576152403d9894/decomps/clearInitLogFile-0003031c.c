
/* WARNING: Unknown calling convention */

void clearInitLogFile(void)

{
  FILE *pFVar1;
  FILE *fd;
  
  pthread_mutex_lock(DAT_00030374);
  pFVar1 = fopen(DAT_00030378,DAT_0003037c);
  if (pFVar1 != (FILE *)0x0) {
    fclose(pFVar1);
  }
  if (*(char *)(DAT_00030380 + 0xd0) != '\0') {
    pFVar1 = fopen(DAT_00030384,DAT_0003037c);
    if (pFVar1 != (FILE *)0x0) {
      fclose(pFVar1);
    }
    pFVar1 = fopen(DAT_00030378,DAT_0003037c);
    if (pFVar1 != (FILE *)0x0) {
      fclose(pFVar1);
    }
    pFVar1 = fopen(DAT_00030388,DAT_0003037c);
    if (pFVar1 != (FILE *)0x0) {
      fclose(pFVar1);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0000a2c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f228)(DAT_00030374);
  return;
}

