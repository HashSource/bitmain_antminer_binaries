
char * BIO_ADDR_path_string(short *param_1)

{
  char *pcVar1;
  
  if (*param_1 == 1) {
    pcVar1 = CRYPTO_strdup((char *)(param_1 + 1),"crypto/bio/b_addr.c",0x124);
    return pcVar1;
  }
  return (char *)0x0;
}

