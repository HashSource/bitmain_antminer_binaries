
void bitmain_soc_reinit_device(cgpu_info *bitmain)

{
  FILE *__stream;
  cgpu_info *bitmain_local;
  FILE *pFile;
  
  if ((!status_error) && (3 < log_level)) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: reinit device, but do nothing here.\n","driver-btm-soc.c",0x1d11,
              "bitmain_soc_reinit_device");
    }
    fclose(__stream);
  }
  return;
}

