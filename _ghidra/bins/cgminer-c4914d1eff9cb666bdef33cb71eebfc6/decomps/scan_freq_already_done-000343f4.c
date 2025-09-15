
/* WARNING: Unknown calling convention */

_Bool scan_freq_already_done(void)

{
  FILE *__stream;
  FILE *fp;
  
  __stream = fopen("/config/scanfreqdone","r");
  if (__stream != (FILE *)0x0) {
    fclose(__stream);
  }
  return __stream != (FILE *)0x0;
}

