
undefined4 get_pll_index_for_lowpower_mode(undefined param_1)

{
  FILE *__stream;
  undefined4 local_c;
  
  switch(param_1) {
  case 0:
    local_c = 0x43;
    break;
  case 1:
    local_c = 0x42;
    break;
  case 2:
    local_c = 0x40;
    break;
  case 3:
    local_c = 0x3f;
    break;
  default:
    if (3 < log_level) {
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d: get wrong freq index for low power mode of S11\n","main.c",0x33d6);
      }
      fclose(__stream);
    }
    local_c = 0x34;
  }
  return local_c;
}

