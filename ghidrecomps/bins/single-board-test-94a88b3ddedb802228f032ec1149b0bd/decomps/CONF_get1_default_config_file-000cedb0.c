
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * CONF_get1_default_config_file(void)

{
  char *pcVar1;
  size_t sVar2;
  char *src;
  
  pcVar1 = getenv("OPENSSL_CONF");
  if (pcVar1 != (char *)0x0) {
    pcVar1 = BUF_strdup(pcVar1);
    return pcVar1;
  }
  pcVar1 = X509_get_default_cert_area();
  sVar2 = strlen(pcVar1);
  sVar2 = sVar2 + 0xd;
  pcVar1 = (char *)CRYPTO_malloc(sVar2,"conf_mod.c",0x21b);
  if (pcVar1 != (char *)0x0) {
    src = X509_get_default_cert_area();
    BUF_strlcpy(pcVar1,src,sVar2);
    BUF_strlcat(pcVar1,"/",sVar2);
    BUF_strlcat(pcVar1,"openssl.cnf",sVar2);
  }
  return pcVar1;
}

