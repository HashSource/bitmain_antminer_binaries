
void * BUF_memdup(void *data,size_t siz)

{
  void *pvVar1;
  
  if (data != (void *)0x0) {
    pvVar1 = CRYPTO_malloc(siz,DAT_000a8b34,0x68);
    if (pvVar1 != (void *)0x0) {
      pvVar1 = (void *)(*(code *)PTR_memcpy_00194250)(pvVar1,data,siz);
      return pvVar1;
    }
    ERR_put_error(7,0x67,0x41,DAT_000a8b34,0x6a);
  }
  return (void *)0x0;
}

