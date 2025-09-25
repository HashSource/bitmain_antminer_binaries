
int * SRP_VBASE_new(char *param_1)

{
  int *ptr;
  int iVar1;
  char *pcVar2;
  
  ptr = (int *)CRYPTO_malloc(0x14,"crypto/srp/srp_vfy.c",0x111);
  if (ptr != (int *)0x0) {
    iVar1 = OPENSSL_sk_new_null();
    *ptr = iVar1;
    if (iVar1 != 0) {
      iVar1 = OPENSSL_sk_new_null();
      ptr[1] = iVar1;
      if (iVar1 != 0) {
        ptr[3] = 0;
        ptr[4] = 0;
        ptr[2] = 0;
        if (param_1 != (char *)0x0) {
          pcVar2 = CRYPTO_strdup(param_1,"crypto/srp/srp_vfy.c",0x11d);
          ptr[2] = (int)pcVar2;
          if (pcVar2 == (char *)0x0) {
            OPENSSL_sk_free(*ptr);
            OPENSSL_sk_free(ptr[1]);
            CRYPTO_free(ptr);
            return (int *)0x0;
          }
        }
        return ptr;
      }
    }
    CRYPTO_free(ptr);
  }
  return (int *)0x0;
}

