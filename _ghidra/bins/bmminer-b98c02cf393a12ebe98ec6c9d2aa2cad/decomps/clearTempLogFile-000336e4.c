
void clearTempLogFile(void)

{
  FILE *__stream;
  
  __stream = fopen("/tmp/temp","w");
  if (__stream == (FILE *)0x0) {
    return;
  }
  fclose(__stream);
  return;
}

