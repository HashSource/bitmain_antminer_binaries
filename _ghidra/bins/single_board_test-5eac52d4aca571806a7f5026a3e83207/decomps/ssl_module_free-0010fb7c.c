
void ssl_module_free(void)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if (ssl_names != (void *)0x0) {
    if (ssl_names_count != 0) {
      iVar5 = 0;
      uVar6 = 0;
      do {
        pvVar2 = ssl_names;
        CRYPTO_free(*(void **)((int)ssl_names + iVar5));
        uVar3 = 0;
        if (*(int *)((int)pvVar2 + iVar5 + 8) != 0) {
          do {
            iVar4 = uVar3 * 8;
            iVar1 = uVar3 * 8;
            uVar3 = uVar3 + 1;
            CRYPTO_free(*(void **)(*(int *)((int)pvVar2 + iVar5 + 4) + iVar1));
            CRYPTO_free(*(void **)(iVar4 + *(int *)((int)pvVar2 + iVar5 + 4) + 4));
          } while (uVar3 < *(uint *)((int)pvVar2 + iVar5 + 8));
        }
        uVar6 = uVar6 + 1;
        CRYPTO_free(*(void **)((int)pvVar2 + iVar5 + 4));
        iVar5 = iVar5 + 0xc;
      } while (uVar6 < ssl_names_count);
    }
    CRYPTO_free(ssl_names);
    ssl_names = (void *)0x0;
    ssl_names_count = 0;
  }
  return;
}

