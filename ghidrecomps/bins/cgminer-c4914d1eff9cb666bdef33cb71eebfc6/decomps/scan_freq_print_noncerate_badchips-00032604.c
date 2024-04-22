
/* WARNING: Unknown calling convention */

void scan_freq_print_noncerate_badchips(void)

{
  FILE *__stream;
  FILE *pFile;
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] != 0) {
      scan_freq_print_nonce_zero_chip(i);
    }
  }
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fputc(10,__stream);
    }
    fclose(__stream);
  }
  return;
}

