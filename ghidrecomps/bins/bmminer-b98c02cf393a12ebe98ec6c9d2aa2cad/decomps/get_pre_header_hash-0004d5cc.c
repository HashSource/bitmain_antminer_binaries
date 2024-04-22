
undefined4 get_pre_header_hash(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  FILE *__stream;
  undefined4 uVar3;
  
  iVar2 = axi_fpga_addr;
  *param_1 = *(undefined4 *)(axi_fpga_addr + 0x140);
  uVar1 = log_level;
  param_1[1] = *(undefined4 *)(iVar2 + 0x144);
  param_1[2] = *(undefined4 *)(iVar2 + 0x148);
  param_1[3] = *(undefined4 *)(iVar2 + 0x14c);
  param_1[4] = *(undefined4 *)(iVar2 + 0x150);
  param_1[5] = *(undefined4 *)(iVar2 + 0x154);
  param_1[6] = *(undefined4 *)(iVar2 + 0x158);
  uVar3 = *(undefined4 *)(iVar2 + 0x15c);
  param_1[7] = uVar3;
  if (uVar1 < 6) {
    return uVar3;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,
            "%s:%d:%s: PRE_HEADER_HASH buf[0]: 0x%x, buf[1]: 0x%x, buf[2]: 0x%x, buf[3]: 0x%x, buf[4]: 0x%x, buf[5]: 0x%x, buf[6]: 0x%x, buf[7]: 0x%x\n"
            ,"znyq7010.c",0x29f,DAT_0004d68c,*param_1,param_1[1],param_1[2],param_1[3],param_1[4],
            param_1[5],param_1[6],param_1[7]);
  }
  fclose(__stream);
  return param_1[7];
}

