
EVP_PKEY_METHOD * EVP_PKEY_meth_new(int id,int flags)

{
  EVP_PKEY_METHOD *__s;
  
  __s = (EVP_PKEY_METHOD *)CRYPTO_malloc(0x6c,"pmeth_lib.c",200);
  if (__s != (EVP_PKEY_METHOD *)0x0) {
    memset(__s,0,0x6c);
    *(int *)__s = id;
    *(uint *)(__s + 4) = flags | 1;
    *(int *)(__s + 8) = 0;
    *(int *)(__s + 0xc) = 0;
    *(int *)(__s + 0x10) = 0;
    *(int *)(__s + 0x14) = 0;
    *(int *)(__s + 0x18) = 0;
    *(int *)(__s + 0x1c) = 0;
    *(int *)(__s + 0x20) = 0;
    *(int *)(__s + 0x24) = 0;
    *(int *)(__s + 0x28) = 0;
    *(int *)(__s + 0x2c) = 0;
    *(int *)(__s + 0x30) = 0;
    *(int *)(__s + 0x34) = 0;
    *(int *)(__s + 0x38) = 0;
    *(int *)(__s + 0x3c) = 0;
    *(int *)(__s + 0x40) = 0;
    *(int *)(__s + 0x44) = 0;
    *(int *)(__s + 0x48) = 0;
    *(int *)(__s + 0x4c) = 0;
    *(int *)(__s + 0x50) = 0;
    *(int *)(__s + 0x54) = 0;
    *(int *)(__s + 0x58) = 0;
    *(int *)(__s + 0x5c) = 0;
    *(int *)(__s + 0x60) = 0;
    *(int *)(__s + 100) = 0;
    *(int *)(__s + 0x68) = 0;
  }
  return __s;
}

