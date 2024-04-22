
void clearTempLogFile(void)

{
  FILE *pFVar1;
  
  pFVar1 = fopen("/tmp/temp","w");
  if (pFVar1 == (FILE *)0x0) {
    return;
  }
  (*(code *)PTR_fclose_0007cfe8)();
  return;
}

