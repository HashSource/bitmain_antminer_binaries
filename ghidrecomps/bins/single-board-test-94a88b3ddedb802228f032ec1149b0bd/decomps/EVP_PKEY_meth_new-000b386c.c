
EVP_PKEY_METHOD * EVP_PKEY_meth_new(int id,int flags)

{
  int *__s;
  
  __s = (int *)CRYPTO_malloc(0x6c,DAT_000b38c8,200);
  if (__s != (int *)0x0) {
    memset(__s,0,0x6c);
    *__s = id;
    __s[1] = flags | 1;
    __s[2] = 0;
    __s[3] = 0;
    __s[4] = 0;
    __s[5] = 0;
    __s[6] = 0;
    __s[7] = 0;
    __s[8] = 0;
    __s[9] = 0;
    __s[10] = 0;
    __s[0xb] = 0;
    __s[0xc] = 0;
    __s[0xd] = 0;
    __s[0xe] = 0;
    __s[0xf] = 0;
    __s[0x10] = 0;
    __s[0x11] = 0;
    __s[0x12] = 0;
    __s[0x13] = 0;
    __s[0x14] = 0;
    __s[0x15] = 0;
    __s[0x16] = 0;
    __s[0x17] = 0;
    __s[0x18] = 0;
    __s[0x19] = 0;
    __s[0x1a] = 0;
  }
  return (EVP_PKEY_METHOD *)__s;
}

