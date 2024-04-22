
void set_work_nonce2(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  FILE *__stream;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar2 = axi_fpga_addr;
  uVar1 = log_level;
  local_1c = 0;
  *(undefined4 *)(axi_fpga_addr + 0x108) = *param_1;
  local_20 = 0;
  *(undefined4 *)(iVar2 + 0x10c) = param_1[1];
  if (5 < uVar1) {
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set WORK_NONCE_2 value[0]: 0x%x, value[1]: 0x%x\n","znyq7010.c",
              0x2cf,DAT_0004d8f8,*param_1,param_1[1]);
    }
    fclose(__stream);
    local_1c = *(undefined4 *)(axi_fpga_addr + 0x10c);
    local_20 = *(undefined4 *)(axi_fpga_addr + 0x108);
    if (5 < log_level) {
      get_work_nonce2_part_1(&local_20);
      return;
    }
  }
  return;
}

