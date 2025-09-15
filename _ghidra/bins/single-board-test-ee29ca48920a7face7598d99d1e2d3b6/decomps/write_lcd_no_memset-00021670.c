
void write_lcd_no_memset(uint param_1,int param_2,uint param_3)

{
  uint local_41c;
  uint local_414;
  char acStack_40c [1024];
  int local_c;
  
  local_c = 0;
  if ((param_2 != 0) && (0 < (int)cgpu._36_4_)) {
    if ((param_1 < 4) && (local_41c = param_3, local_414 = param_1, param_3 < 0x41)) {
      for (; local_41c != 0; local_41c = local_41c - 0x10) {
        if (local_41c < 0x11) {
          memcpy(lcd_buffer + local_414 * 0x10 + 0x20,(void *)(param_2 + local_c),local_41c);
          break;
        }
        memcpy(lcd_buffer + local_414 * 0x10 + 0x20,(void *)(local_c + param_2),0x10);
        local_c = local_c + 0x10;
        local_414 = local_414 + 1;
      }
      write(cgpu._36_4_,lcd_buffer + 0x20,0x40);
    }
    else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_40c,0x400,"%s: write_lcd\'s arg is overflow\n","write_lcd_no_memset");
      _applog(2,acStack_40c,0);
    }
  }
  return;
}

