
uint set_iic(uint param_1)

{
  uint uVar1;
  FILE *__stream;
  int local_c;
  
  local_c = 0;
  *(uint *)(axi_fpga_addr + 0x30) = param_1 & 0x7fffffff;
  do {
    uVar1 = get_iic();
    if ((int)uVar1 < 0) {
LAB_000362a6:
      return uVar1 & 0xff;
    }
    local_c = local_c + 1;
    if (3000 < local_c) {
      if (3 < log_level) {
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d: ERROR: set_iic timeout\n","znyq7010.c",0x6f);
        }
        fclose(__stream);
      }
      goto LAB_000362a6;
    }
    usleep(1000);
  } while( true );
}

