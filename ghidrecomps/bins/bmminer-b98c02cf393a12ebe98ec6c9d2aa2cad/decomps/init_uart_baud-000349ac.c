
void init_uart_baud(void)

{
  FILE *__stream;
  
  if (log_level < 4) {
    set_baud(1);
    return;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: set baud=%d\n","driver-btm-c5.c",0x2598,DAT_00034a14,1);
  }
  fclose(__stream);
  set_baud(1);
  return;
}

