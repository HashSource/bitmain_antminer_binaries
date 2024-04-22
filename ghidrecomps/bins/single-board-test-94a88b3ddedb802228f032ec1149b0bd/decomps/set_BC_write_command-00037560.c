
void set_BC_write_command(int param_1)

{
  FILE *__stream;
  int iVar1;
  int local_c;
  
  local_c = 0;
  *(int *)(axi_fpga_addr + 0xc0) = param_1;
  if (param_1 < 0) {
    do {
      iVar1 = get_BC_write_command();
      if (-1 < iVar1) {
        return;
      }
      usleep(1000);
      local_c = local_c + 1;
    } while (local_c < 0xbb9);
    if (5 < log_level) {
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d: Error: set_BC_write_command wait buffer ready timeout!\n",
                "znyq7010.c",0x1f1);
      }
      fclose(__stream);
    }
  }
  else {
    get_BC_write_command();
  }
  return;
}

