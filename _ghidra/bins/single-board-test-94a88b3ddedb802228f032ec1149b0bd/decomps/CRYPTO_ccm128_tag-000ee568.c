
uint CRYPTO_ccm128_tag(byte *param_1,void *param_2,uint param_3)

{
  uint __n;
  
  __n = (((uint)*param_1 << 0x1a) >> 0x1d) * 2 + 2;
  if (param_3 < __n) {
    __n = 0;
  }
  else {
    memcpy(param_2,param_1 + 0x10,__n);
  }
  return __n;
}

