
undefined4 calculate_asic_number(uint param_1)

{
  FILE *__stream;
  undefined4 local_c;
  
  if (param_1 == 1) {
    local_c = 1;
  }
  else if (param_1 == 2) {
    local_c = 2;
  }
  else if ((param_1 < 3) || (4 < param_1)) {
    if ((param_1 < 5) || (8 < param_1)) {
      if ((param_1 < 9) || (0x10 < param_1)) {
        if ((param_1 < 0x11) || (0x20 < param_1)) {
          if ((param_1 < 0x21) || (0x40 < param_1)) {
            if ((param_1 < 0x41) || (0x80 < param_1)) {
              if (3 < log_level) {
                __stream = fopen(log_file,"a+");
                if (__stream != (FILE *)0x0) {
                  fprintf(__stream,"%s:%d: actual_asic_number = %d, but it is error\n",
                          "driver-bitmain.c",0xba0,param_1);
                }
                fclose(__stream);
              }
              local_c = 0xffffffff;
            }
            else {
              local_c = 0x80;
            }
          }
          else {
            local_c = 0x40;
          }
        }
        else {
          local_c = 0x20;
        }
      }
      else {
        local_c = 0x10;
      }
    }
    else {
      local_c = 8;
    }
  }
  else {
    local_c = 4;
  }
  return local_c;
}

