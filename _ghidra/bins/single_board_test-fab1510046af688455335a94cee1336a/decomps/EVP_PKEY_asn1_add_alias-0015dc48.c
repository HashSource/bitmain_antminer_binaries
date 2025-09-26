
int EVP_PKEY_asn1_add_alias(int to,int from)

{
  int *__s;
  int iVar1;
  _STACK *st;
  
  __s = (int *)CRYPTO_malloc(0x6c,"ameth_lib.c",0x121);
  if (__s != (int *)0x0) {
    memset(__s,0,0x6c);
    st = app_methods;
    *__s = from;
    __s[1] = to;
    __s[2] = 3;
    __s[4] = 0;
    __s[3] = 0;
    __s[5] = 0;
    __s[6] = 0;
    __s[7] = 0;
    __s[8] = 0;
    __s[9] = 0;
    __s[10] = 0;
    __s[0xb] = 0;
    __s[0x18] = 0;
    __s[0x17] = 0;
    __s[0x19] = 0;
    __s[0x1a] = 0;
    __s[0xc] = 0;
    __s[0xd] = 0;
    __s[0xe] = 0;
    __s[0xf] = 0;
    __s[0x10] = 0;
    __s[0x11] = 0;
    __s[0x12] = 0;
    __s[0x13] = 0;
    __s[0x15] = 0;
    __s[0x16] = 0;
    if (((st != (_STACK *)0x0) ||
        (st = sk_new((cmp *)0x15d8fd), app_methods = st, st != (_STACK *)0x0)) &&
       (iVar1 = sk_push(st,__s), iVar1 != 0)) {
      sk_sort(app_methods);
      return 1;
    }
    if (__s[2] << 0x1e < 0) {
      if ((void *)__s[3] != (void *)0x0) {
        CRYPTO_free((void *)__s[3]);
      }
      if ((void *)__s[4] != (void *)0x0) {
        CRYPTO_free((void *)__s[4]);
      }
      CRYPTO_free(__s);
    }
  }
  return 0;
}

