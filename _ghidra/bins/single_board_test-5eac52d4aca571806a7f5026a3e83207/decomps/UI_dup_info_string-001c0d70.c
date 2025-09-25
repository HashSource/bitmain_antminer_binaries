
int UI_dup_info_string(UI *ui,char *text)

{
  char *pcVar1;
  int *ptr;
  int iVar2;
  
  if (text == (char *)0x0) {
    ERR_put_error(0x28,0x6d,0x43,"crypto/ui/ui_lib.c",0x69);
  }
  else {
    pcVar1 = CRYPTO_strdup(text,"crypto/ui/ui_lib.c",0x145);
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(0x28,0x66,0x41,"crypto/ui/ui_lib.c",0x147);
      return -1;
    }
    ptr = (int *)CRYPTO_malloc(0x24,"crypto/ui/ui_lib.c",0x6d);
    if (ptr != (int *)0x0) {
      ptr[1] = (int)pcVar1;
      ptr[3] = 0;
      iVar2 = *(int *)(ui + 4);
      ptr[2] = 0;
      ptr[8] = 1;
      *ptr = 4;
      if (iVar2 == 0) {
        iVar2 = OPENSSL_sk_new_null();
        *(int *)(ui + 4) = iVar2;
        if (iVar2 == 0) {
          if ((ptr[8] << 0x1f < 0) && (CRYPTO_free((void *)ptr[1]), *ptr == 3)) {
            CRYPTO_free((void *)ptr[5]);
            CRYPTO_free((void *)ptr[6]);
            CRYPTO_free((void *)ptr[7]);
          }
          CRYPTO_free(ptr);
          return -1;
        }
      }
      ptr[5] = 0;
      ptr[6] = 0;
      ptr[7] = 0;
      iVar2 = OPENSSL_sk_push(iVar2,ptr);
      if (0 < iVar2) {
        return iVar2;
      }
      if ((ptr[8] << 0x1f < 0) && (CRYPTO_free((void *)ptr[1]), *ptr == 3)) {
        CRYPTO_free((void *)ptr[5]);
        CRYPTO_free((void *)ptr[6]);
        CRYPTO_free((void *)ptr[7]);
      }
      CRYPTO_free(ptr);
      return iVar2 + -1;
    }
  }
  return -1;
}

