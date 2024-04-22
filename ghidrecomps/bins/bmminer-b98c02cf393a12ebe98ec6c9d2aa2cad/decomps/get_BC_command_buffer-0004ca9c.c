
undefined4 get_BC_command_buffer(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  FILE *__stream;
  undefined4 uVar3;
  
  iVar2 = axi_fpga_addr;
  *param_1 = *(undefined4 *)(axi_fpga_addr + 0xc4);
  uVar1 = log_level;
  param_1[1] = *(undefined4 *)(iVar2 + 200);
  uVar3 = *(undefined4 *)(iVar2 + 0xcc);
  param_1[2] = uVar3;
  if (uVar1 < 8) {
    return uVar3;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: BC_COMMAND_BUFFER buf[0]: 0x%x, buf[1]: 0x%x, buf[2]: 0x%x\n",
            "znyq7010.c",0x1b9,DAT_0004cb20,*param_1,param_1[1],param_1[2]);
  }
  fclose(__stream);
  return uVar3;
}

