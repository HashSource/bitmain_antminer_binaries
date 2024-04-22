
int get_bt8d_fpga_divider(int baud)

{
  FILE *__stream;
  int baud_local;
  FILE *pFile;
  int divider;
  
  divider = 0x1a;
  if (baud == 0x1c200) {
    divider = 0x1a;
  }
  else if ((double)(longlong)baud == DAT_00078570) {
    divider = 1;
  }
  else if (baud == 3000000) {
    divider = 0;
  }
  else if (baud == 6000000) {
    divider = 3;
  }
  else if (baud == 12000000) {
    divider = 4;
  }
  else if (baud == 25000000) {
    divider = 5;
  }
  else if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: Error divider for fpage, baud = %d\n","chip1391.c",0xf8,
              "get_bt8d_fpga_divider",baud);
    }
    fclose(__stream);
  }
  return divider;
}

