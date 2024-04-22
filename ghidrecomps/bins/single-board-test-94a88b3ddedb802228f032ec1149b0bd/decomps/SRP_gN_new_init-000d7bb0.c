
char ** SRP_gN_new_init(char *param_1)

{
  char **ptr;
  char *pcVar1;
  int len;
  BIGNUM *pBVar2;
  char **ppcVar3;
  uchar auStack_9d4 [2504];
  
  ptr = (char **)CRYPTO_malloc(8,DAT_000d7c04,0x120);
  ppcVar3 = ptr;
  if (ptr != (char **)0x0) {
    pcVar1 = BUF_strdup(param_1);
    *ptr = pcVar1;
    if (pcVar1 != (char *)0x0) {
      len = t_fromb64(auStack_9d4,param_1);
      pBVar2 = BN_bin2bn(auStack_9d4,len,(BIGNUM *)0x0);
      ptr[1] = (char *)pBVar2;
      if (pBVar2 != (BIGNUM *)0x0) {
        return ptr;
      }
      CRYPTO_free(*ptr);
    }
    ppcVar3 = (char **)0x0;
    CRYPTO_free(ptr);
  }
  return ppcVar3;
}

