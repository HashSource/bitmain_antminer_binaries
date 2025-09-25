
undefined4 dh_copy_parameters(int param_1,int param_2)

{
  int iVar1;
  uchar *puVar2;
  BIGNUM *pBVar3;
  DH *pDVar4;
  int iVar5;
  undefined1 *puVar6;
  
  pDVar4 = *(DH **)(param_1 + 0x18);
  if (pDVar4 == (DH *)0x0) {
    pDVar4 = DH_new();
    *(DH **)(param_1 + 0x18) = pDVar4;
    if (pDVar4 == (DH *)0x0) {
      return 0;
    }
  }
  iVar5 = *(int *)(param_2 + 0x18);
  puVar6 = *(undefined1 **)(param_2 + 0xc);
  pBVar3 = *(BIGNUM **)(iVar5 + 8);
  if ((pBVar3 == (BIGNUM *)0x0) ||
     (((iVar1 = BN_get_flags(pBVar3,2), iVar1 != 0 && (iVar1 = BN_get_flags(pBVar3,1), iVar1 == 0))
      || (pBVar3 = BN_dup(pBVar3), pBVar3 != (BIGNUM *)0x0)))) {
    BN_clear_free(pDVar4->p);
    pDVar4->p = pBVar3;
    pBVar3 = *(BIGNUM **)(iVar5 + 0xc);
    if ((pBVar3 == (BIGNUM *)0x0) ||
       (((iVar1 = BN_get_flags(pBVar3,2), iVar1 != 0 && (iVar1 = BN_get_flags(pBVar3,1), iVar1 == 0)
         ) || (pBVar3 = BN_dup(pBVar3), pBVar3 != (BIGNUM *)0x0)))) {
      BN_clear_free(pDVar4->g);
      pDVar4->g = pBVar3;
      if (puVar6 != &dhx_asn1_meth) {
        pDVar4->length = *(long *)(iVar5 + 0x10);
        return 1;
      }
      pBVar3 = *(BIGNUM **)(iVar5 + 0x24);
      if (((pBVar3 == (BIGNUM *)0x0) ||
          ((iVar1 = BN_get_flags(pBVar3,2), iVar1 != 0 &&
           (iVar1 = BN_get_flags(pBVar3,1), iVar1 == 0)))) ||
         (pBVar3 = BN_dup(pBVar3), pBVar3 != (BIGNUM *)0x0)) {
        BN_clear_free(pDVar4->q);
        pDVar4->q = pBVar3;
        pBVar3 = *(BIGNUM **)(iVar5 + 0x28);
        if ((pBVar3 == (BIGNUM *)0x0) ||
           (((iVar1 = BN_get_flags(pBVar3,2), iVar1 != 0 &&
             (iVar1 = BN_get_flags(pBVar3,1), iVar1 == 0)) ||
            (pBVar3 = BN_dup(pBVar3), pBVar3 != (BIGNUM *)0x0)))) {
          BN_clear_free(pDVar4->j);
          pDVar4->j = pBVar3;
          CRYPTO_free(pDVar4->seed);
          pDVar4->seed = (uchar *)0x0;
          iVar1 = *(int *)(iVar5 + 0x2c);
          pDVar4->seedlen = 0;
          if (iVar1 != 0) {
            puVar2 = (uchar *)CRYPTO_memdup(iVar1,*(undefined4 *)(iVar5 + 0x30),
                                            "crypto/dh/dh_ameth.c",0x19b);
            pDVar4->seed = puVar2;
            if (puVar2 == (uchar *)0x0) {
              return 0;
            }
            pDVar4->seedlen = *(int *)(iVar5 + 0x30);
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

