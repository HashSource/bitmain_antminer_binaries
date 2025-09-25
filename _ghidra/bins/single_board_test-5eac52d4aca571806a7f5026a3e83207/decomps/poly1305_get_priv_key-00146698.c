
undefined4 poly1305_get_priv_key(int param_1,void *param_2,uint *param_3)

{
  void *__src;
  size_t __n;
  ASN1_STRING *x;
  
  x = *(ASN1_STRING **)(param_1 + 0x18);
  if (param_2 == (void *)0x0) {
    *param_3 = 0x20;
    return 1;
  }
  if (x != (ASN1_STRING *)0x0) {
    if (*param_3 < 0x20) {
      return 0;
    }
    __src = (void *)ASN1_STRING_get0_data(x);
    __n = ASN1_STRING_length(x);
    memcpy(param_2,__src,__n);
    *param_3 = 0x20;
    return 1;
  }
  return 0;
}

