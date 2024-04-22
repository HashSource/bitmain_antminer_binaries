
void destroy_tuning_info(void *param_1)

{
  FILE *__stream;
  
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: destroy_tuning_info enter\n","board_frq_tuning.c",0x300);
    }
    fclose(__stream);
  }
  memset(param_1,0,0x585dc);
  return;
}

