
void dump_core_reg(uint32_t value)

{
  FILE *__stream;
  uint32_t value_local;
  uint8_t core;
  uint8_t asic;
  int chain;
  FILE *pFile;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: dump core reg!\n","driver-btm-soc.c",0xe40,"dump_core_reg");
    }
    fclose(__stream);
  }
  do_dump_core_reg(value >> 0x10 & 0xff,(uint8_t)(value >> 8),value & 0xff);
  return;
}

