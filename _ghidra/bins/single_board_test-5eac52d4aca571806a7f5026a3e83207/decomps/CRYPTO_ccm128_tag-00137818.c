
size_t CRYPTO_ccm128_tag(byte *param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  
  sVar1 = (short)(ushort)(((uint)*param_1 << 0x1a) >> 0x1d) * 2 + 2;
  if (sVar1 != param_3) {
    return 0;
  }
  memcpy(param_2,param_1 + 0x10,param_3);
  return sVar1;
}

