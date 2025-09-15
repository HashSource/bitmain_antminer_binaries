
undefined4
znyq_set_iic(byte param_1,byte param_2,char param_3,char param_4,byte param_5,byte param_6)

{
  FILE *__stream;
  undefined4 uVar1;
  uint uVar2;
  uint local_14;
  
  local_14 = 0;
  if (param_3 != '\0') {
    local_14 = 0x2000000;
  }
  if (param_4 != '\0') {
    local_14 = local_14 | (uint)param_5 << 8 | 0x1000000;
  }
  uVar2 = (uint)param_6 |
          local_14 | (param_2 & 3) << 0x1a | (param_1 >> 3 & 0xf) << 0x14 | (param_1 & 7) << 0x10;
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: value = 0x%08x\n","power.c",0x80,uVar2);
    }
    fclose(__stream);
  }
  uVar1 = set_iic(uVar2);
  return uVar1;
}

