
void address_to_pubkeyhash(undefined *param_1)

{
  undefined4 uVar1;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined local_14;
  
  uVar1 = DAT_00047b84;
  local_28 = 0;
  local_2c = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  b58tobin(&local_2c);
  *param_1 = 0x76;
  param_1[1] = 0xa9;
  param_1[2] = 0x14;
  _cg_memcpy(param_1 + 3,(int)&local_2c + 1,0x14,"util.c",uVar1,0x3c6);
  param_1[0x17] = 0x88;
  param_1[0x18] = 0xac;
  return;
}

