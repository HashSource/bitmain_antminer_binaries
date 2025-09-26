
char * BN_bn2dec(BIGNUM *a)

{
  int iVar1;
  ulong *ptr;
  char *ptr_00;
  int iVar2;
  ulong uVar3;
  int num;
  BIGNUM *a_00;
  ulong *puVar4;
  char *pcVar5;
  
  iVar1 = BN_num_bits(a);
  iVar1 = (iVar1 * 3) / 10 + (iVar1 * 3) / 1000;
  num = iVar1 + 5;
  iVar1 = (iVar1 + 2) / 0x13 + 1;
  ptr = (ulong *)CRYPTO_malloc(iVar1 * 4,"crypto/bn/bn_print.c",0x48);
  ptr_00 = (char *)CRYPTO_malloc(num,"crypto/bn/bn_print.c",0x49);
  if (ptr == (ulong *)0x0 || ptr_00 == (char *)0x0) {
    a_00 = (BIGNUM *)0x0;
    ERR_put_error(3,0x68,0x41,"crypto/bn/bn_print.c",0x4b);
  }
  else {
    a_00 = BN_dup(a);
    if (a_00 != (BIGNUM *)0x0) {
      iVar2 = BN_is_zero();
      if (iVar2 != 0) {
        ptr_00[1] = '\0';
        *ptr_00 = '0';
        goto LAB_001973d4;
      }
      iVar2 = BN_is_negative(a_00);
      puVar4 = ptr;
      pcVar5 = ptr_00;
      if (iVar2 != 0) {
        pcVar5 = ptr_00 + 1;
        *ptr_00 = '-';
      }
      do {
        iVar2 = BN_is_zero(a_00);
        if (iVar2 != 0) {
          iVar1 = BIO_snprintf(pcVar5,num - ((int)pcVar5 - (int)ptr_00),"%lu",puVar4[-1]);
          if (-1 < iVar1) {
            puVar4 = puVar4 + -1;
            pcVar5 = pcVar5 + iVar1;
            if (ptr == puVar4) goto LAB_001973d4;
            goto LAB_0019745c;
          }
          break;
        }
        if (iVar1 <= (int)puVar4 - (int)ptr >> 2) break;
        uVar3 = BN_div_word(a_00,0x89e80000);
        *puVar4 = uVar3;
        puVar4 = puVar4 + 1;
      } while (uVar3 != 0xffffffff);
    }
  }
LAB_00197392:
  CRYPTO_free(ptr);
  BN_free(a_00);
  CRYPTO_free(ptr_00);
  return (char *)0x0;
  while (ptr != puVar4) {
LAB_0019745c:
    puVar4 = puVar4 + -1;
    iVar1 = BIO_snprintf(pcVar5,num - ((int)pcVar5 - (int)ptr_00),"%019lu",*puVar4);
    pcVar5 = pcVar5 + iVar1;
    if (iVar1 < 0) goto LAB_00197392;
  }
LAB_001973d4:
  CRYPTO_free(ptr);
  BN_free(a_00);
  return ptr_00;
}

