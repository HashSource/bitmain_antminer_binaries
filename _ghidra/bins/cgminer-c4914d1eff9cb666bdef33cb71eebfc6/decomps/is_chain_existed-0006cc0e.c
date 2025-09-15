
_Bool is_chain_existed(uint8_t chain)

{
  FILE *__stream;
  _Bool _Var1;
  uint8_t chain_local;
  FILE *pFile;
  
  if (dev->chain_exist[chain] == 0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: chain[%d] does not exist\n","eeprom.c",0x47,"is_chain_existed",
                (uint)chain);
      }
      fclose(__stream);
    }
    _Var1 = false;
  }
  else {
    _Var1 = true;
  }
  return _Var1;
}

