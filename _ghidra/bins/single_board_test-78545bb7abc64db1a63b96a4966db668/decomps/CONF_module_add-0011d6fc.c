
int CONF_module_add(char *name,undefined1 *ifunc,undefined1 *ffunc)

{
  undefined4 *ptr;
  char *pcVar1;
  int iVar2;
  
  if ((supported_modules == 0) &&
     (supported_modules = OPENSSL_sk_new_null(), supported_modules == 0)) {
    return 0;
  }
  ptr = (undefined4 *)CRYPTO_zalloc(0x18,"crypto/conf/conf_mod.c",0xee);
  if (ptr == (undefined4 *)0x0) {
    ERR_put_error(0xe,0x7a,0x41,"crypto/conf/conf_mod.c",0xef);
  }
  else {
    *ptr = 0;
    pcVar1 = CRYPTO_strdup(name,"crypto/conf/conf_mod.c",0xf4);
    ptr[2] = ifunc;
    ptr[1] = pcVar1;
    ptr[3] = ffunc;
    if (pcVar1 == (char *)0x0) {
      CRYPTO_free(ptr);
    }
    else {
      iVar2 = OPENSSL_sk_push(supported_modules,ptr);
      if (iVar2 != 0) {
        return 1;
      }
      CRYPTO_free((void *)ptr[1]);
      CRYPTO_free(ptr);
    }
  }
  return 0;
}

