
int _CONF_add_string(CONF *conf,CONF_VALUE *section,CONF_VALUE *value)

{
  int iVar1;
  void *ptr;
  char *pcVar2;
  
  pcVar2 = section->value;
  value->section = section->section;
  iVar1 = OPENSSL_sk_push(pcVar2,value);
  if (iVar1 != 0) {
    ptr = (void *)OPENSSL_LH_insert(conf->data,value);
    if (ptr != (void *)0x0) {
      OPENSSL_sk_delete_ptr(pcVar2,ptr);
      CRYPTO_free(*(void **)((int)ptr + 4));
      CRYPTO_free(*(void **)((int)ptr + 8));
      CRYPTO_free(ptr);
      return 1;
    }
    iVar1 = 1;
  }
  return iVar1;
}

