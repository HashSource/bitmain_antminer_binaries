
undefined4 CRYPTO_ccm128_setiv(byte *param_1,void *param_2,uint param_3,undefined4 param_4)

{
  uint __n;
  
  __n = 0xe - (*param_1 & 7);
  if (__n <= param_3) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    param_1[0xf] = (byte)param_4;
    param_1[0xc] = (byte)((uint)param_4 >> 0x18);
    param_1[0xd] = (byte)((uint)param_4 >> 0x10);
    param_1[0xe] = (byte)((uint)param_4 >> 8);
    *param_1 = *param_1 & 0xbf;
    memcpy(param_1 + 1,param_2,__n);
    return 0;
  }
  return 0xffffffff;
}

