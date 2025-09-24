
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * CONF_get1_default_config_file(void)

{
  char *pcVar1;
  size_t sVar2;
  char *pcVar3;
  
  pcVar1 = (char *)ossl_safe_getenv("OPENSSL_CONF");
  if (pcVar1 != (char *)0x0) {
    pcVar1 = CRYPTO_strdup(pcVar1,"crypto/conf/conf_mod.c",0x1e7);
    return pcVar1;
  }
  pcVar1 = X509_get_default_cert_area();
  sVar2 = strlen(pcVar1);
  pcVar1 = (char *)CRYPTO_malloc(sVar2 + 0xd,"crypto/conf/conf_mod.c",0x1f0);
  if (pcVar1 != (char *)0x0) {
    pcVar3 = X509_get_default_cert_area();
    BIO_snprintf(pcVar1,sVar2 + 0xd,"%s%s%s",pcVar3,&DAT_0020a0ac,"openssl.cnf");
  }
  return pcVar1;
}

