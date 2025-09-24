
undefined4 sm3_final(undefined1 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  size_t __n;
  undefined4 *ptr;
  
  ptr = param_2 + 10;
  uVar1 = param_2[0x1a] + 1;
  *(undefined1 *)((int)ptr + param_2[0x1a]) = 0x80;
  if (uVar1 < 0x39) {
    __n = 0x38 - uVar1;
  }
  else {
    memset((void *)(uVar1 + (int)ptr),0,0x40 - uVar1);
    sm3_block_data_order(param_2,ptr,1);
    __n = 0x38;
    uVar1 = 0;
  }
  memset((void *)(uVar1 + (int)ptr),0,__n);
  uVar2 = param_2[9];
  uVar1 = param_2[8];
  *(char *)((int)param_2 + 99) = (char)uVar2;
  *(char *)((int)param_2 + 0x67) = (char)uVar1;
  *(char *)(param_2 + 0x18) = (char)((uint)uVar2 >> 0x18);
  *(char *)((int)param_2 + 0x61) = (char)((uint)uVar2 >> 0x10);
  *(char *)((int)param_2 + 0x62) = (char)((uint)uVar2 >> 8);
  *(char *)(param_2 + 0x19) = (char)(uVar1 >> 0x18);
  *(char *)((int)param_2 + 0x66) = (char)(uVar1 >> 8);
  *(char *)((int)param_2 + 0x65) = (char)(uVar1 >> 0x10);
  sm3_block_data_order(param_2,ptr,1,uVar1 >> 8,param_4);
  param_2[0x1a] = 0;
  OPENSSL_cleanse(ptr,0x40);
  uVar2 = *param_2;
  param_1[3] = (char)uVar2;
  *param_1 = (char)((uint)uVar2 >> 0x18);
  param_1[1] = (char)((uint)uVar2 >> 0x10);
  param_1[2] = (char)((uint)uVar2 >> 8);
  uVar2 = param_2[1];
  param_1[7] = (char)uVar2;
  param_1[4] = (char)((uint)uVar2 >> 0x18);
  param_1[5] = (char)((uint)uVar2 >> 0x10);
  param_1[6] = (char)((uint)uVar2 >> 8);
  uVar2 = param_2[2];
  param_1[0xb] = (char)uVar2;
  param_1[8] = (char)((uint)uVar2 >> 0x18);
  param_1[9] = (char)((uint)uVar2 >> 0x10);
  param_1[10] = (char)((uint)uVar2 >> 8);
  uVar2 = param_2[3];
  param_1[0xf] = (char)uVar2;
  param_1[0xc] = (char)((uint)uVar2 >> 0x18);
  param_1[0xd] = (char)((uint)uVar2 >> 0x10);
  param_1[0xe] = (char)((uint)uVar2 >> 8);
  uVar2 = param_2[4];
  param_1[0x13] = (char)uVar2;
  param_1[0x10] = (char)((uint)uVar2 >> 0x18);
  param_1[0x11] = (char)((uint)uVar2 >> 0x10);
  param_1[0x12] = (char)((uint)uVar2 >> 8);
  uVar2 = param_2[5];
  param_1[0x17] = (char)uVar2;
  param_1[0x14] = (char)((uint)uVar2 >> 0x18);
  param_1[0x15] = (char)((uint)uVar2 >> 0x10);
  param_1[0x16] = (char)((uint)uVar2 >> 8);
  uVar2 = param_2[6];
  param_1[0x18] = (char)((uint)uVar2 >> 0x18);
  param_1[0x19] = (char)((uint)uVar2 >> 0x10);
  param_1[0x1a] = (char)((uint)uVar2 >> 8);
  param_1[0x1b] = (char)uVar2;
  uVar2 = param_2[7];
  param_1[0x1f] = (char)uVar2;
  param_1[0x1c] = (char)((uint)uVar2 >> 0x18);
  param_1[0x1d] = (char)((uint)uVar2 >> 0x10);
  param_1[0x1e] = (char)((uint)uVar2 >> 8);
  return 1;
}

