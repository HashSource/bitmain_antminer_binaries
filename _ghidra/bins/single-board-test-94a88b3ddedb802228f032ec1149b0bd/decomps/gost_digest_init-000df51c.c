
undefined4 gost_digest_init(int param_1)

{
  void *__s;
  
  __s = *(void **)(param_1 + 0xc);
  memset(__s,0,0x70);
  gost_init((int)__s + 0x70,GostR3411_94_CryptoProParamSet);
  *(int *)((int)__s + 8) = (int)__s + 0x70;
  return 1;
}

