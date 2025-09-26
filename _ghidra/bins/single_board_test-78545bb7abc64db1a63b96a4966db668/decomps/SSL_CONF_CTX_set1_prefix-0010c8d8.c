
char * SSL_CONF_CTX_set1_prefix(int param_1,char *param_2)

{
  char *__s;
  size_t sVar1;
  char *pcVar2;
  
  if (param_2 != (char *)0x0) {
    __s = CRYPTO_strdup(param_2,"ssl/ssl_conf.c",0x3b7);
    pcVar2 = __s;
    if (__s != (char *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 4));
      *(char **)(param_1 + 4) = __s;
      pcVar2 = (char *)0x1;
      sVar1 = strlen(__s);
      *(size_t *)(param_1 + 8) = sVar1;
    }
    return pcVar2;
  }
  CRYPTO_free(*(void **)(param_1 + 4));
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return (char *)0x1;
}

