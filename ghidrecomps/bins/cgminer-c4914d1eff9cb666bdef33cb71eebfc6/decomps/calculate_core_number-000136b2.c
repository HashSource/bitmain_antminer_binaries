
int calculate_core_number(uint actual_core_number)

{
  FILE *__stream;
  uint actual_core_number_local;
  FILE *pFile;
  int i;
  
  if (actual_core_number == 1) {
    i = 1;
  }
  else if (actual_core_number == 2) {
    i = 2;
  }
  else if ((actual_core_number < 3) || (4 < actual_core_number)) {
    if ((actual_core_number < 5) || (8 < actual_core_number)) {
      if ((actual_core_number < 9) || (0x10 < actual_core_number)) {
        if ((actual_core_number < 0x11) || (0x20 < actual_core_number)) {
          if ((actual_core_number < 0x21) || (0x40 < actual_core_number)) {
            if ((actual_core_number < 0x41) || (0x80 < actual_core_number)) {
              if ((actual_core_number < 0x81) || (0xd0 < actual_core_number)) {
                if (4 < log_level) {
                  print_crt_time_to_file(log_file,4);
                  __stream = fopen(log_file,"a+");
                  if (__stream != (FILE *)0x0) {
                    fprintf(__stream,"%s:%d:%s: actual_core_number = %d, but it is error\n","asic.c"
                            ,0x28a,"calculate_core_number",actual_core_number);
                  }
                  fclose(__stream);
                }
                i = -1;
              }
              else {
                i = 0x100;
              }
            }
            else {
              i = 0x80;
            }
          }
          else {
            i = 0x40;
          }
        }
        else {
          i = 0x20;
        }
      }
      else {
        i = 0x10;
      }
    }
    else {
      i = 8;
    }
  }
  else {
    i = 4;
  }
  return i;
}

