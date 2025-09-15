
void write_lcd_no_memset(uint line,char *buf,uint size)

{
  uint size_local;
  char *buf_local;
  uint line_local;
  char tmp42 [1024];
  uint Copied;
  
  Copied = 0;
  if ((buf != (char *)0x0) && (0 < cgpu.lcd_fd)) {
    if ((line < 4) && (size_local = size, line_local = line, size < 0x41)) {
      for (; size_local != 0; size_local = size_local - 0x10) {
        if (size_local < 0x11) {
          memcpy(lcd_output + line_local,buf + Copied,size_local);
          break;
        }
        memcpy(lcd_output + line_local,buf + Copied,0x10);
        Copied = Copied + 0x10;
        line_local = line_local + 1;
      }
      write(cgpu.lcd_fd,lcd_output,0x40);
    }
    else if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: write_lcd\'s arg is overflow\n","write_lcd_no_memset");
      _applog(2,tmp42,false);
    }
  }
  return;
}

