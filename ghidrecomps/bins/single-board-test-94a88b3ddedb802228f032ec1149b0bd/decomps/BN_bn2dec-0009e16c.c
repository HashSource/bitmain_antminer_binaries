
char * BN_bn2dec(BIGNUM *a)

{
  char cVar1;
  int iVar2;
  ulong *ptr;
  char *ptr_00;
  BIGNUM *a_00;
  ulong uVar3;
  char *pcVar4;
  char *pcVar5;
  ulong *puVar6;
  ulong *puVar7;
  int iVar8;
  
  iVar2 = BN_num_bits(a);
  iVar2 = (iVar2 * 3) / 10 + (iVar2 * 3) / 1000;
  ptr = (ulong *)CRYPTO_malloc(((iVar2 + 2) / 9 + 1) * 4,DAT_0009e2d8,0x7b);
  ptr_00 = (char *)CRYPTO_malloc(iVar2 + 5,DAT_0009e2d8,0x7c);
  if (ptr_00 == (char *)0x0 || ptr == (ulong *)0x0) {
    ERR_put_error(3,0x68,0x41,DAT_0009e2d8,0x7e);
    pcVar4 = ptr_00;
    if (ptr == (ulong *)0x0) {
      if (ptr_00 != (char *)0x0) {
        pcVar4 = (char *)0x1;
      }
    }
    else {
      if (ptr_00 != (char *)0x0) {
        pcVar4 = (char *)0x1;
      }
      CRYPTO_free(ptr);
    }
    goto LAB_0009e1f8;
  }
  pcVar4 = (char *)0x1;
  a_00 = BN_dup(a);
  if (a_00 != (BIGNUM *)0x0) {
    if (a_00->top == 0) {
      ptr_00[1] = '\0';
      *ptr_00 = '0';
      pcVar4 = (char *)0x0;
    }
    else {
      puVar7 = ptr;
      if (a_00->neg == 0) {
        iVar8 = 0;
        pcVar4 = ptr_00;
LAB_0009e238:
        do {
          uVar3 = BN_div_word(a_00,1000000000);
          *puVar7 = uVar3;
          puVar6 = puVar7 + 1;
          puVar7 = puVar7 + 1;
        } while (a_00->top != 0);
      }
      else {
        pcVar4 = ptr_00 + 1;
        *ptr_00 = '-';
        iVar8 = (int)ptr_00 - (int)pcVar4;
        if (a_00->top != 0) goto LAB_0009e238;
        uVar3 = ptr[-1];
        puVar6 = ptr;
      }
      puVar6 = puVar6 + -1;
      BIO_snprintf(pcVar4,iVar8 + iVar2 + 5,DAT_0009e2dc,uVar3);
      cVar1 = *pcVar4;
      while (cVar1 != '\0') {
        pcVar4 = pcVar4 + 1;
        cVar1 = *pcVar4;
      }
      while (ptr != puVar6) {
        while( true ) {
          puVar6 = puVar6 + -1;
          BIO_snprintf(pcVar4,(size_t)(ptr_00 + ((iVar2 + 5) - (int)pcVar4)),DAT_0009e2e0,*puVar6);
          if (*pcVar4 == '\0') break;
          do {
            pcVar4 = pcVar4 + 1;
          } while (*pcVar4 != '\0');
          if (ptr == puVar6) goto LAB_0009e2a0;
        }
      }
LAB_0009e2a0:
      pcVar4 = (char *)0x0;
    }
  }
  CRYPTO_free(ptr);
  if (a_00 != (BIGNUM *)0x0) {
    BN_free(a_00);
  }
LAB_0009e1f8:
  pcVar5 = ptr_00;
  if (pcVar4 != (char *)0x0) {
    pcVar5 = (char *)0x0;
    CRYPTO_free(ptr_00);
  }
  return pcVar5;
}

