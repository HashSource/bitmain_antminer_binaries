
int UI_dup_input_string(UI *ui,char *prompt,int flags,char *result_buf,int minsize,int maxsize)

{
  char *pcVar1;
  int *ptr;
  int iVar2;
  
  if (prompt == (char *)0x0) {
    ERR_put_error(0x28,0x6d,0x43,"crypto/ui/ui_lib.c",0x69);
  }
  else {
    pcVar1 = CRYPTO_strdup(prompt,"crypto/ui/ui_lib.c",0xd5);
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(0x28,0x67,0x41,"crypto/ui/ui_lib.c",0xd7);
      return 0;
    }
    if (result_buf == (char *)0x0) {
      ERR_put_error(0x28,0x6d,0x69,"crypto/ui/ui_lib.c",0x6c);
    }
    else {
      ptr = (int *)CRYPTO_malloc(0x24,"crypto/ui/ui_lib.c",0x6d);
      if (ptr != (int *)0x0) {
        ptr[1] = (int)pcVar1;
        ptr[3] = (int)result_buf;
        iVar2 = *(int *)(ui + 4);
        ptr[2] = flags;
        ptr[8] = 1;
        *ptr = 1;
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
        ptr[7] = 0;
        ptr[5] = minsize;
        ptr[6] = maxsize;
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
  }
  return -1;
}

