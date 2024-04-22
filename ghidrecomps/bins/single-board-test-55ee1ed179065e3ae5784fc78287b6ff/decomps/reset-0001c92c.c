
void reset(void)

{
  int local_c;
  
  local_c = -0x7fff8000;
  fpga_write(0x10,0x80008000);
  do {
    usleep(100000);
    fpga_read(0x10,&local_c);
  } while (local_c < 0);
  printf("%s:%d","reset",0x123);
  puts("fpga reset success");
  return;
}

