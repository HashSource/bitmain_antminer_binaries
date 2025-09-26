
size_t X509_VERIFY_PARAM_set1_ip_asc(int param_1,char *param_2)

{
  size_t siz;
  void *pvVar1;
  int iVar2;
  uchar auStack_28 [20];
  
  siz = a2i_ipadd(auStack_28,param_2);
  if (siz != 0) {
    if ((siz == 4) || (siz == 0x10)) {
      iVar2 = *(int *)(param_1 + 0x20);
      pvVar1 = BUF_memdup(auStack_28,siz);
      if (pvVar1 != (void *)0x0) {
        if (*(void **)(iVar2 + 0x14) != (void *)0x0) {
          CRYPTO_free(*(void **)(iVar2 + 0x14));
        }
        *(void **)(iVar2 + 0x14) = pvVar1;
        if (iVar2 != -0x18) {
          *(size_t *)(iVar2 + 0x18) = siz;
          return 1;
        }
        return 1;
      }
    }
    siz = 0;
  }
  return siz;
}

