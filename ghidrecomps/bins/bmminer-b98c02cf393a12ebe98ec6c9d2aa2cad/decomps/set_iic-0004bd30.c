
uint set_iic(uint param_1)

{
  FILE *__stream;
  int iVar1;
  uint uVar2;
  
  iVar1 = 3000;
  *(uint *)(axi_fpga_addr + 0x30) = param_1 & 0x7fffffff;
  do {
    usleep(1000);
    uVar2 = *(uint *)(axi_fpga_addr + 0x30);
    if ((int)uVar2 < 0) goto LAB_0004bd5e;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (1 < log_level) {
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: ERROR: set_iic timeout \n","znyq7010.c",0x6f,DAT_0004bdb0);
    }
    fclose(__stream);
  }
LAB_0004bd5e:
  return uVar2 & 0xff;
}

