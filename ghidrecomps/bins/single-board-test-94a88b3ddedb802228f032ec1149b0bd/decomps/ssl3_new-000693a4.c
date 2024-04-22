
undefined4 ssl3_new(int param_1)

{
  void *__s;
  
  __s = CRYPTO_malloc(0x42c,DAT_0006941c,0xb97);
  if (__s != (void *)0x0) {
    memset(__s,0,0x42c);
    *(undefined *)((int)__s + 0x128) = 0;
    *(undefined *)((int)__s + 0x129) = 0;
    *(undefined *)((int)__s + 0x12a) = 0;
    *(undefined *)((int)__s + 299) = 0;
    *(undefined *)((int)__s + 300) = 0;
    *(undefined *)((int)__s + 0x12d) = 0;
    *(undefined *)((int)__s + 0x12e) = 0;
    *(undefined *)((int)__s + 0x12f) = 0;
    *(undefined *)((int)__s + 0x14c) = 0;
    *(undefined *)((int)__s + 0x14d) = 0;
    *(undefined *)((int)__s + 0x14e) = 0;
    *(undefined *)((int)__s + 0x14f) = 0;
    *(undefined *)((int)__s + 0x150) = 0;
    *(undefined *)((int)__s + 0x151) = 0;
    *(undefined *)((int)__s + 0x152) = 0;
    *(undefined *)((int)__s + 0x153) = 0;
    *(void **)(param_1 + 0x58) = __s;
    SSL_SRP_CTX_init(param_1);
    (**(code **)(*(int *)(param_1 + 8) + 8))(param_1);
    return 1;
  }
  return 0;
}

