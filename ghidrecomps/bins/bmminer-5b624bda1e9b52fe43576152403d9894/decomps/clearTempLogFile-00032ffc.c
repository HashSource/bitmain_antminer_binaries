
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void clearTempLogFile(void)

{
  FILE *pFVar1;
  
  pFVar1 = fopen("/tmp/temp","w");
  if (pFVar1 == (FILE *)0x0) {
    return;
  }
  (*(code *)(undefined *)0x0)();
  return;
}

