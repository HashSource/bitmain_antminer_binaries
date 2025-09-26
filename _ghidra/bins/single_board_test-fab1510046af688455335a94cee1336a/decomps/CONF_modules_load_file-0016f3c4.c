
int CONF_modules_load_file(char *filename,char *appname,ulong flags)

{
  CONF *conf;
  int iVar1;
  uint uVar2;
  ulong uVar3;
  char *pcVar4;
  size_t sVar5;
  char *src;
  
  conf = NCONF_new((CONF_METHOD *)0x0);
  if (conf == (CONF *)0x0) {
    uVar2 = 0;
    pcVar4 = (char *)0x0;
LAB_0016f3f6:
    if (filename != (char *)0x0) goto LAB_0016f3f8;
  }
  else {
    pcVar4 = filename;
    if (filename != (char *)0x0) {
LAB_0016f3dc:
      iVar1 = NCONF_load(conf,pcVar4,(long *)0x0);
      if (iVar1 < 1) {
        uVar2 = flags & 0x10;
        if (uVar2 != 0) {
          uVar3 = ERR_peek_last_error();
          if ((uVar3 & 0xfff) == 0x72) {
            ERR_clear_error();
            uVar2 = 1;
          }
          else {
            uVar2 = 0;
          }
        }
      }
      else {
        uVar2 = CONF_modules_load(conf,appname,flags);
      }
      goto LAB_0016f3f6;
    }
    pcVar4 = getenv("OPENSSL_CONF");
    if (pcVar4 == (char *)0x0) {
      pcVar4 = X509_get_default_cert_area();
      sVar5 = strlen(pcVar4);
      sVar5 = sVar5 + 0xd;
      pcVar4 = (char *)CRYPTO_malloc(sVar5,"conf_mod.c",0x21b);
      if (pcVar4 != (char *)0x0) {
        src = X509_get_default_cert_area();
        BUF_strlcpy(pcVar4,src,sVar5);
        BUF_strlcat(pcVar4,"/",sVar5);
        BUF_strlcat(pcVar4,"openssl.cnf",sVar5);
        goto LAB_0016f3dc;
      }
    }
    else {
      pcVar4 = BUF_strdup(pcVar4);
      if (pcVar4 != (char *)0x0) goto LAB_0016f3dc;
    }
    uVar2 = 0;
    pcVar4 = (char *)0x0;
  }
  CRYPTO_free(pcVar4);
LAB_0016f3f8:
  NCONF_free(conf);
  return uVar2;
}

