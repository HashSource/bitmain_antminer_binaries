
void dump_asic_reg(uint32_t value)

{
  FILE *__stream;
  uint32_t value_local;
  uint8_t asic;
  int chain;
  FILE *pFile;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: dump asic reg!\n","driver-btm-soc.c",0xe32,"dump_asic_reg");
    }
    fclose(__stream);
  }
  do_dump_asic_reg(value >> 0x10 & 0xff,(uint8_t)(value >> 8));
  return;
}

