
void set_BC_command_buffer(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  FILE *__stream;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar2 = axi_fpga_addr;
  uVar1 = log_level;
  *(undefined4 *)(axi_fpga_addr + 0xc4) = *param_1;
  local_24 = 0;
  local_28 = 0;
  *(undefined4 *)(iVar2 + 200) = param_1[1];
  local_20 = 0;
  local_1c = 0;
  *(undefined4 *)(iVar2 + 0xcc) = param_1[2];
  if (uVar1 < 8) {
    get_BC_command_buffer(&local_28);
    return;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,
            "%s:%d:%s: set BC_COMMAND_BUFFER value[0]: 0x%x, value[1]: 0x%x, value[2]: 0x%x\n",
            "znyq7010.c",0x1c3,DAT_0004cbbc,*param_1,param_1[1],param_1[2]);
  }
  fclose(__stream);
  get_BC_command_buffer(&local_28);
  return;
}

