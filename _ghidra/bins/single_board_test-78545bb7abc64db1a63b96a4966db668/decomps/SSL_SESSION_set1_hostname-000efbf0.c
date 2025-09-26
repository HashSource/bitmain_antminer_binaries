
char * SSL_SESSION_set1_hostname(int param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  CRYPTO_free(*(void **)(param_1 + 0x1cc));
  if (param_2 != (char *)0x0) {
    pcVar1 = CRYPTO_strdup(param_2,"ssl/ssl_sess.c",0x378);
    pcVar2 = pcVar1;
    if (pcVar1 != (char *)0x0) {
      pcVar2 = (char *)0x1;
    }
    *(char **)(param_1 + 0x1cc) = pcVar1;
    return pcVar2;
  }
  *(undefined4 *)(param_1 + 0x1cc) = 0;
  return (char *)0x1;
}

