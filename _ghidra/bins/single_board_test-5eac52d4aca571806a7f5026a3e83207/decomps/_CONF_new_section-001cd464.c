
CONF_VALUE * _CONF_new_section(CONF *conf,char *section)

{
  char *pcVar1;
  CONF_VALUE *ptr;
  size_t sVar2;
  char *__dest;
  int iVar3;
  
  pcVar1 = (char *)OPENSSL_sk_new_null();
  if ((pcVar1 == (char *)0x0) ||
     (ptr = (CONF_VALUE *)CRYPTO_malloc(0xc,"crypto/conf/conf_api.c",0xc5), ptr == (CONF_VALUE *)0x0
     )) {
    ptr = (CONF_VALUE *)0x0;
    OPENSSL_sk_free(pcVar1);
  }
  else {
    sVar2 = strlen(section);
    __dest = (char *)CRYPTO_malloc(sVar2 + 1,"crypto/conf/conf_api.c",200);
    ptr->section = __dest;
    if (__dest != (char *)0x0) {
      memcpy(__dest,section,sVar2 + 1);
      ptr->value = pcVar1;
      ptr->name = (char *)0x0;
      iVar3 = OPENSSL_LH_insert(conf->data,ptr);
      if ((iVar3 == 0) && (iVar3 = OPENSSL_LH_error(conf->data), iVar3 < 1)) {
        return ptr;
      }
    }
    OPENSSL_sk_free(pcVar1);
    CRYPTO_free(ptr->section);
  }
  CRYPTO_free(ptr);
  return (CONF_VALUE *)0x0;
}

