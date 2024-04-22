
undefined4 T9_plus_write_pic_iic(char param_1,char param_2,byte param_3,byte param_4,byte param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint local_14;
  
  local_14 = 0;
  while( true ) {
    iVar1 = get_iic();
    if (iVar1 < 0) break;
    usleep(1000);
  }
  if (param_1 != '\0') {
    local_14 = 0x2000000;
  }
  if (param_2 != '\0') {
    local_14 = local_14 | 0x1000000 | (uint)param_3 << 8;
  }
  uVar2 = set_iic((uint)param_5 | local_14 | 0x400000 | (param_4 & 0xf) << 0x10);
  return uVar2;
}

