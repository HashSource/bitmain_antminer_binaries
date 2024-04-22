
void CRYPTO_mem_leaks_fp(FILE *param_1)

{
  int iVar1;
  char *file;
  BIO_METHOD *type;
  BIO *bp;
  int iVar2;
  
  iVar1 = DAT_0008ada4;
  if (*(int *)(DAT_0008ada4 + 0x18) != 0) {
    CRYPTO_mem_ctrl_constprop_2();
    type = BIO_s_file();
    bp = BIO_new(type);
    CRYPTO_lock(9,0x14,DAT_0008ada8,0xd4);
    if ((((int)(*(uint *)(iVar1 + 4) << 0x1f) < 0) && (*(int *)(iVar1 + 8) != 0)) &&
       (iVar2 = *(int *)(iVar1 + 8) + -1, *(int *)(iVar1 + 8) = iVar2, file = DAT_0008ada8,
       iVar2 == 0)) {
      *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | 2;
      CRYPTO_lock(10,0x1b,file,0x109);
    }
    CRYPTO_lock(10,0x14,DAT_0008ada8,0x112);
    if (bp != (BIO *)0x0) {
      BIO_ctrl(bp,0x6a,0,param_1);
      CRYPTO_mem_leaks(bp);
      BIO_free(bp);
      return;
    }
  }
  return;
}

