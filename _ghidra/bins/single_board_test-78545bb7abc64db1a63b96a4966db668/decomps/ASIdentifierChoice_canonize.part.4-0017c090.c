
ASIdOrRange * ASIdentifierChoice_canonize_part_4(int *param_1)

{
  int iVar1;
  int *piVar2;
  ASIdOrRange *a;
  int iVar3;
  BIGNUM *pBVar4;
  int iVar5;
  undefined4 *puVar6;
  ASN1_INTEGER *pAVar7;
  ASN1_INTEGER *y;
  BIGNUM *bn;
  ASN1_INTEGER *local_38;
  ASN1_INTEGER *local_34;
  ASN1_INTEGER *local_30;
  
  OPENSSL_sk_sort(param_1[1]);
  bn = (BIGNUM *)0x0;
  local_34 = (ASN1_INTEGER *)0x0;
  iVar1 = OPENSSL_sk_num(param_1[1]);
  iVar5 = 0;
  if (0 < iVar1 + -1) {
    do {
      piVar2 = (int *)OPENSSL_sk_value(param_1[1],iVar5);
      iVar1 = iVar5 + 1;
      a = (ASIdOrRange *)OPENSSL_sk_value(param_1[1],iVar1);
      if (piVar2 == (int *)0x0) {
        a = (ASIdOrRange *)0x0;
        goto LAB_0017c1e8;
      }
      if (*piVar2 == 0) {
        pAVar7 = (ASN1_INTEGER *)piVar2[1];
        local_38 = pAVar7;
      }
      else {
        if (*piVar2 != 1) goto LAB_0017c1e6;
        pAVar7 = (ASN1_INTEGER *)((undefined4 *)piVar2[1])[1];
        local_38 = *(ASN1_INTEGER **)piVar2[1];
      }
      if (a == (ASIdOrRange *)0x0) goto LAB_0017c1e8;
      if (a->type == 0) {
        y = (a->u).id;
        local_30 = y;
      }
      else {
        if (a->type != 1) goto LAB_0017c1e6;
        y = ((a->u).range)->min;
        local_30 = (ASN1_INTEGER *)((a->u).range)->max;
      }
      iVar3 = ASN1_INTEGER_cmp(local_38,y);
      if (((0 < iVar3) || (iVar3 = ASN1_INTEGER_cmp(local_38,pAVar7), 0 < iVar3)) ||
         (iVar3 = ASN1_INTEGER_cmp(y,local_30), 0 < iVar3)) goto LAB_0017c1e6;
      iVar3 = ASN1_INTEGER_cmp(pAVar7,y);
      if (-1 < iVar3) {
        a = (ASIdOrRange *)0x0;
        ERR_put_error(0x22,0xa1,0x74,"crypto/x509v3/v3_asid.c",0x1a2);
        goto LAB_0017c1e8;
      }
      if (((bn == (BIGNUM *)0x0) && (bn = BN_new(), bn == (BIGNUM *)0x0)) ||
         ((pBVar4 = ASN1_INTEGER_to_BN(pAVar7,bn), pBVar4 == (BIGNUM *)0x0 ||
          (iVar3 = BN_add_word(bn,1), iVar3 == 0)))) {
        a = (ASIdOrRange *)0x0;
        ERR_put_error(0x22,0xa1,0x41,"crypto/x509v3/v3_asid.c",0x1ad);
        goto LAB_0017c1e8;
      }
      pAVar7 = BN_to_ASN1_INTEGER(bn,local_34);
      if (pAVar7 == (ASN1_INTEGER *)0x0) {
        ERR_put_error(0x22,0xa1,0x41,"crypto/x509v3/v3_asid.c",0x1b5);
        a = (ASIdOrRange *)0x0;
        goto LAB_0017c1e8;
      }
      iVar3 = ASN1_INTEGER_cmp(pAVar7,y);
      local_34 = pAVar7;
      if (iVar3 == 0) {
        if (*piVar2 == 0) {
          puVar6 = (undefined4 *)CRYPTO_malloc(8,"crypto/x509v3/v3_asid.c",0x1c0);
          if (puVar6 == (undefined4 *)0x0) {
            ERR_put_error(0x22,0xa1,0x41,"crypto/x509v3/v3_asid.c",0x1c2);
            a = (ASIdOrRange *)0x0;
            goto LAB_0017c1e8;
          }
          *puVar6 = local_38;
          puVar6[1] = local_30;
          *piVar2 = 1;
          piVar2[1] = (int)puVar6;
          pAVar7 = (ASN1_INTEGER *)a->type;
          if (pAVar7 != (ASN1_INTEGER *)0x0) goto LAB_0017c194;
LAB_0017c232:
          (a->u).id = pAVar7;
        }
        else {
          if (*piVar2 == 1) {
            ASN1_INTEGER_free(*(ASN1_STRING **)(piVar2[1] + 4));
            *(ASN1_INTEGER **)(piVar2[1] + 4) = local_30;
          }
          pAVar7 = (ASN1_INTEGER *)a->type;
          if (pAVar7 == (ASN1_INTEGER *)0x0) goto LAB_0017c232;
LAB_0017c194:
          if (pAVar7 == (ASN1_INTEGER *)0x1) {
            ((a->u).id)->type = 0;
          }
        }
        ASIdOrRange_free(a);
        OPENSSL_sk_delete(param_1[1],iVar1);
        iVar1 = iVar5;
      }
      iVar3 = OPENSSL_sk_num(param_1[1]);
      iVar5 = iVar1;
    } while (iVar1 < iVar3 + -1);
  }
  iVar5 = OPENSSL_sk_num(param_1[1]);
  piVar2 = (int *)OPENSSL_sk_value(param_1[1],iVar5 + -1);
  if (((piVar2 == (int *)0x0) || (*piVar2 != 1)) ||
     (iVar5 = ASN1_INTEGER_cmp(*(ASN1_INTEGER **)piVar2[1],
                               (ASN1_INTEGER *)((undefined4 *)piVar2[1])[1]), iVar5 < 1)) {
    if (*param_1 == 0) {
      a = (ASIdOrRange *)0x1;
      goto LAB_0017c1e8;
    }
    if ((*param_1 == 1) && (iVar5 = OPENSSL_sk_num(param_1[1]), iVar5 != 0)) {
      a = (ASIdOrRange *)ASIdentifierChoice_is_canonical_part_1(param_1);
      if (a != (ASIdOrRange *)0x0) {
        a = (ASIdOrRange *)0x1;
      }
      goto LAB_0017c1e8;
    }
  }
LAB_0017c1e6:
  a = (ASIdOrRange *)0x0;
LAB_0017c1e8:
  ASN1_INTEGER_free(local_34);
  BN_free(bn);
  return a;
}

