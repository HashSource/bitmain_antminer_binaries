
int * ASIdentifierChoice_is_canonical_part_1(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  BIGNUM *pBVar4;
  ASN1_INTEGER *pAVar5;
  ASN1_INTEGER *x;
  int iVar6;
  BIGNUM *bn;
  ASN1_INTEGER *y;
  ASN1_INTEGER *ai;
  ASN1_INTEGER *y_00;
  ASN1_INTEGER *y_01;
  
  iVar6 = 0;
  bn = (BIGNUM *)0x0;
  ai = (ASN1_INTEGER *)0x0;
  do {
    iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 4));
    if (iVar1 + -1 <= iVar6) {
      iVar6 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 4));
      piVar2 = (int *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 4),iVar6 + -1);
      if ((piVar2 == (int *)0x0) || (*piVar2 != 1)) {
        piVar2 = (int *)0x1;
      }
      else {
        iVar6 = ASN1_INTEGER_cmp(*(ASN1_INTEGER **)piVar2[1],
                                 (ASN1_INTEGER *)((undefined4 *)piVar2[1])[1]);
        piVar2 = (int *)(uint)(iVar6 < 1);
      }
      goto LAB_0017bf46;
    }
    piVar2 = (int *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 4),iVar6);
    iVar6 = iVar6 + 1;
    piVar3 = (int *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 4),iVar6);
    if (piVar2 == (int *)0x0) goto LAB_0017bf46;
    pAVar5 = ai;
    if (*piVar2 == 0) {
      x = (ASN1_INTEGER *)piVar2[1];
      y_00 = x;
    }
    else {
      if (*piVar2 != 1) {
LAB_0017bf44:
        piVar2 = (int *)0x0;
        ai = pAVar5;
LAB_0017bf46:
        ASN1_INTEGER_free(ai);
        BN_free(bn);
        return piVar2;
      }
      x = *(ASN1_INTEGER **)piVar2[1];
      y_00 = (ASN1_INTEGER *)((undefined4 *)piVar2[1])[1];
    }
    if (piVar3 == (int *)0x0) {
      piVar2 = (int *)0x0;
      goto LAB_0017bf46;
    }
    if (*piVar3 == 0) {
      y = (ASN1_INTEGER *)piVar3[1];
      y_01 = y;
    }
    else {
      if (*piVar3 != 1) goto LAB_0017bf44;
      y = *(ASN1_INTEGER **)piVar3[1];
      y_01 = (ASN1_INTEGER *)((undefined4 *)piVar3[1])[1];
    }
    iVar1 = ASN1_INTEGER_cmp(x,y);
    if (((-1 < iVar1) || (iVar1 = ASN1_INTEGER_cmp(x,y_00), 0 < iVar1)) ||
       (iVar1 = ASN1_INTEGER_cmp(y,y_01), 0 < iVar1)) goto LAB_0017bf44;
    if (((bn == (BIGNUM *)0x0) && (bn = BN_new(), bn == (BIGNUM *)0x0)) ||
       ((pBVar4 = ASN1_INTEGER_to_BN(y_00,bn), pBVar4 == (BIGNUM *)0x0 ||
        (iVar1 = BN_add_word(bn,1), iVar1 == 0)))) {
      piVar2 = (int *)0x0;
      ERR_put_error(0x22,0xa2,0x41,"crypto/x509v3/v3_asid.c",0x130);
      goto LAB_0017bf46;
    }
    pAVar5 = BN_to_ASN1_INTEGER(bn,ai);
    if (pAVar5 == (ASN1_INTEGER *)0x0) {
      ERR_put_error(0x22,0xa2,0x41,"crypto/x509v3/v3_asid.c",0x138);
      piVar2 = (int *)0x0;
      goto LAB_0017bf46;
    }
    iVar1 = ASN1_INTEGER_cmp(pAVar5,y);
    ai = pAVar5;
    if (-1 < iVar1) goto LAB_0017bf44;
  } while( true );
}

