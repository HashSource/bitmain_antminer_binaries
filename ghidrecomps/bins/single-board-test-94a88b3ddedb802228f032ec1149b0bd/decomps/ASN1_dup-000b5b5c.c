
void * ASN1_dup(undefined1 *i2d,undefined1 *d2i,void *x)

{
  int iVar1;
  void *ptr;
  undefined4 uVar2;
  void *local_20;
  void *local_1c [2];
  
  if (x != (void *)0x0) {
    iVar1 = (*(code *)i2d)(x,0);
    ptr = CRYPTO_malloc(iVar1 + 10,DAT_000b5bb4,0x4c);
    if (ptr == (void *)0x0) {
      ERR_put_error(0xd,0x6f,0x41,DAT_000b5bb4,0x4e);
      x = (void *)0x0;
    }
    else {
      local_20 = ptr;
      uVar2 = (*(code *)i2d)(x,&local_20);
      local_1c[0] = ptr;
      x = (void *)(*(code *)d2i)(0,local_1c,uVar2);
      CRYPTO_free(ptr);
    }
  }
  return x;
}

