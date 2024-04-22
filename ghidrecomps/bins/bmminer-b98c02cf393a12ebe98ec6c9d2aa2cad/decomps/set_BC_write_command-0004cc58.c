
void set_BC_write_command(int param_1)

{
  int iVar1;
  FILE *__stream;
  int iVar2;
  
  *(int *)(axi_fpga_addr + 0xc0) = param_1;
  if (-1 < param_1) {
    get_BC_write_command();
    return;
  }
  iVar2 = 0xbb9;
  do {
    iVar1 = get_BC_write_command();
    if (-1 < iVar1) {
      return;
    }
    usleep(1000);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (log_level < 6) {
    return;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: Error: set_BC_write_command wait buffer ready timeout!\n",
            "znyq7010.c",0x1f1,DAT_0004cce0);
  }
  (*(code *)PTR_fclose_0007cfe8)(__stream);
  return;
}

