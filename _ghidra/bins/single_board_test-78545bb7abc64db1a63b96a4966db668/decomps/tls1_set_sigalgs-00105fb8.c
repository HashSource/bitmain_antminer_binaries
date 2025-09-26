
undefined4 tls1_set_sigalgs(int param_1,int param_2,uint param_3,int param_4)

{
  undefined2 *ptr;
  undefined1 *puVar1;
  uint uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  
  if ((param_3 & 1) != 0) {
    return 0;
  }
  uVar2 = param_3 >> 1;
  ptr = (undefined2 *)CRYPTO_malloc(uVar2 << 1,"ssl/t1_lib.c",0x813);
  if (ptr == (undefined2 *)0x0) {
    ERR_put_error(0x14,0x278,0x41,"ssl/t1_lib.c",0x814);
    return 0;
  }
  if (param_3 != 0) {
    param_2 = param_2 + 8;
    puVar3 = ptr;
    do {
      puVar1 = &sigalg_lookup_tbl;
      while ((*(int *)(param_2 + -8) != *(int *)(puVar1 + 8) ||
             (*(int *)(param_2 + -4) != *(int *)(puVar1 + 0x10)))) {
        puVar1 = puVar1 + 0x20;
        if (puVar1 == legacy_rsa_sigalg) {
          CRYPTO_free(ptr);
          return 0;
        }
      }
      param_2 = param_2 + 8;
      puVar4 = puVar3 + 1;
      *puVar3 = *(undefined2 *)(puVar1 + 4);
      puVar3 = puVar4;
    } while ((uint)((int)puVar4 - (int)ptr) < param_3);
  }
  if (param_4 == 0) {
    CRYPTO_free(*(void **)(param_1 + 0xd0));
    *(undefined2 **)(param_1 + 0xd0) = ptr;
    *(uint *)(param_1 + 0xd4) = uVar2;
    return 1;
  }
  CRYPTO_free(*(void **)(param_1 + 0xd8));
  *(undefined2 **)(param_1 + 0xd8) = ptr;
  *(uint *)(param_1 + 0xdc) = uVar2;
  return 1;
}

