
void * i2s_ASN1_IA5STRING(undefined4 param_1,void **param_2)

{
  void *__dest;
  
  if (param_2 == (void **)0x0) {
    __dest = (void *)0x0;
  }
  else {
    __dest = *param_2;
    if (__dest != (void *)0x0) {
      __dest = CRYPTO_malloc((int)__dest + 1,DAT_0010cf1c,0x57);
      if (__dest == (void *)0x0) {
        ERR_put_error(0x22,0x95,0x41,DAT_0010cf1c,0x58);
      }
      else {
        memcpy(__dest,param_2[2],(size_t)*param_2);
        *(undefined *)((int)__dest + (int)*param_2) = 0;
      }
    }
  }
  return __dest;
}

