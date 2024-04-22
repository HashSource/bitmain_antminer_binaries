
undefined4 makeup_work_pkg(void *param_1,undefined *param_2)

{
  ushort uVar1;
  
  param_2[2] = param_2[2] & 0x1f | 0x20;
  *param_2 = 0x55;
  param_2[1] = 0xaa;
  uVar1 = CRC16_v1(param_2 + 2,0x8e);
  *(ushort *)(param_2 + 0x90) = uVar1 >> 8 | uVar1 << 8;
  memcpy(param_1,param_2,0x92);
  return 0x92;
}

