
/* WARNING: Unknown calling convention */

void freq_scan_set_state(void)

{
  int iVar1;
  FILE *__stream;
  FILE *pFile;
  int hash_rate_sale;
  
  iVar1 = freq_scan_get_sale_hash_rate();
  if (iVar1 < 0x34bc) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: hash_rate_for_sale = %d  < %d \n","freq_scan.c",0xdc,
                "freq_scan_set_state",iVar1,0x34bc);
      }
      fclose(__stream);
    }
    freq_scan_error_code_set(6,0xff);
  }
  return;
}

