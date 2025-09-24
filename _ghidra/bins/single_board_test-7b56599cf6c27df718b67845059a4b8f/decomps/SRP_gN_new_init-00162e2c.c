
undefined4 * SRP_gN_new_init(char *param_1)

{
  undefined4 *ptr;
  int len;
  char *pcVar1;
  BIGNUM *pBVar2;
  uchar auStack_9dc [2500];
  
  ptr = (undefined4 *)CRYPTO_malloc(8,"crypto/srp/srp_vfy.c",0x134);
  if (ptr != (undefined4 *)0x0) {
    len = t_fromb64_constprop_5(auStack_9dc,param_1);
    if (-1 < len) {
      pcVar1 = CRYPTO_strdup(param_1,"crypto/srp/srp_vfy.c",0x13d);
      *ptr = pcVar1;
      if (pcVar1 != (char *)0x0) {
        pBVar2 = BN_bin2bn(auStack_9dc,len,(BIGNUM *)0x0);
        ptr[1] = pBVar2;
        if (pBVar2 != (BIGNUM *)0x0) {
          return ptr;
        }
        CRYPTO_free((void *)*ptr);
      }
    }
    CRYPTO_free(ptr);
  }
  return (undefined4 *)0x0;
}

