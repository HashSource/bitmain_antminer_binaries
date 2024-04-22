
void ClearLogInfo(void)

{
  FILE *pFVar1;
  
  pFVar1 = fopen("/tmp/search","w");
  if (pFVar1 != (FILE *)0x0) {
    fclose(pFVar1);
  }
  pFVar1 = fopen("/tmp/freq","w");
  if (pFVar1 != (FILE *)0x0) {
    fclose(pFVar1);
  }
  pFVar1 = fopen("/tmp/lasttemp","w");
  if (pFVar1 != (FILE *)0x0) {
    fclose(pFVar1);
  }
  return;
}

