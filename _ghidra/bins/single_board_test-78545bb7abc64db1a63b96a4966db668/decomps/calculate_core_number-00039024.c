
uint32_t calculate_core_number(uint32_t actual_core_number)

{
  uint32_t actual_core_number_local;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t i;
  
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
              if ((actual_core_number < 0x81) || (0x100 < actual_core_number)) {
                if ((actual_core_number < 0x101) || (0x200 < actual_core_number)) {
                  if ((actual_core_number < 0x201) || (0x400 < actual_core_number)) {
                    print_time_stamp(time_stamp,0x30);
                    printf("%s ",time_stamp);
                    printf("%s : actual_core_number = %d, bigger than 1024\n",
                           "calculate_core_number",actual_core_number);
                    snprintf(tmp1,0x100,"actual_core_number = %d, bigger than 1024",
                             actual_core_number);
                    log_to_file(tmp1,time_stamp);
                    i = 0;
                  }
                  else {
                    i = 0x400;
                  }
                }
                else {
                  i = 0x200;
                }
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

