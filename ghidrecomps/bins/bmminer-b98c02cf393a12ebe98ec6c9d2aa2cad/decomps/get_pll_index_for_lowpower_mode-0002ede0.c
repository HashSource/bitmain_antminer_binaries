
undefined4 get_pll_index_for_lowpower_mode(undefined4 param_1)

{
  FILE *__stream;
  
  switch(param_1) {
  case 0:
    return 0x43;
  case 1:
    return 0x42;
  case 2:
    return 0x40;
  case 3:
    return 0x3f;
  }
  if (3 < log_level) {
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: get wrong freq index for low power mode of S11\n",
              "driver-btm-c5.c",0xa1b,DAT_0002ee54);
    }
    fclose(__stream);
    return 0x34;
  }
  return 0x34;
}

