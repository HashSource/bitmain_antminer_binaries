
undefined4 * SRP_gN_new_init(char *param_1)

{
  undefined4 *ptr;
  char *pcVar1;
  int len;
  BIGNUM *pBVar2;
  undefined4 *puVar3;
  uchar auStack_9d4 [2504];
  
  ptr = (undefined4 *)CRYPTO_malloc(8,"srp_vfy.c",0x120);
  puVar3 = ptr;
  if (ptr != (undefined4 *)0x0) {
    pcVar1 = BUF_strdup(param_1);
    *ptr = pcVar1;
    if (pcVar1 != (char *)0x0) {
      len = t_fromb64(auStack_9d4,param_1);
      pBVar2 = BN_bin2bn(auStack_9d4,len,(BIGNUM *)0x0);
      ptr[1] = pBVar2;
      if (pBVar2 != (BIGNUM *)0x0) {
        return ptr;
      }
      CRYPTO_free((void *)*ptr);
    }
    puVar3 = (undefined4 *)0x0;
    CRYPTO_free(ptr);
  }
  return puVar3;
}

