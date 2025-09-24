
int UI_add_input_string(UI *ui,char *prompt,int flags,char *result_buf,int minsize,int maxsize)

{
  int *ptr;
  int iVar1;
  
  if (prompt == (char *)0x0) {
    ERR_put_error(0x28,0x6d,0x43,"crypto/ui/ui_lib.c",0x69);
    return -1;
  }
  if (result_buf == (char *)0x0) {
    ERR_put_error(0x28,0x6d,0x69,"crypto/ui/ui_lib.c",0x6c);
    return -1;
  }
  ptr = (int *)CRYPTO_malloc(0x24,"crypto/ui/ui_lib.c",0x6d);
  if (ptr == (int *)0x0) {
    return -1;
  }
  ptr[1] = (int)prompt;
  ptr[3] = (int)result_buf;
  iVar1 = *(int *)(ui + 4);
  ptr[2] = flags;
  ptr[8] = 0;
  *ptr = 1;
  if (iVar1 == 0) {
    iVar1 = OPENSSL_sk_new_null();
    *(int *)(ui + 4) = iVar1;
    if (iVar1 == 0) {
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
  iVar1 = OPENSSL_sk_push(iVar1,ptr);
  if (0 < iVar1) {
    return iVar1;
  }
  if ((ptr[8] << 0x1f < 0) && (CRYPTO_free((void *)ptr[1]), *ptr == 3)) {
    CRYPTO_free((void *)ptr[5]);
    CRYPTO_free((void *)ptr[6]);
    CRYPTO_free((void *)ptr[7]);
  }
  CRYPTO_free(ptr);
  return iVar1 + -1;
}

