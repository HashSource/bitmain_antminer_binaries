
undefined4 check_crl(undefined4 *param_1,X509_CRL *param_2)

{
  int iVar1;
  ASN1_TIME *pAVar2;
  EVP_PKEY *r;
  X509 *a;
  X509 *b;
  uint uVar3;
  int iVar4;
  int iVar5;
  time_t *t;
  undefined4 uVar6;
  X509_STORE_CTX XStack_a8;
  
  iVar5 = param_1[0x17];
  iVar1 = OPENSSL_sk_num(param_1[0x14]);
  iVar4 = param_1[0x1a];
  if (iVar4 == 0) {
    if (iVar5 < iVar1 + -1) {
      iVar4 = OPENSSL_sk_value(param_1[0x14],iVar5 + 1);
    }
    else {
      iVar4 = OPENSSL_sk_value(param_1[0x14]);
      iVar1 = (*(code *)param_1[9])(param_1,iVar4,iVar4);
      if (iVar1 == 0) {
        param_1[0x18] = 0x21;
        iVar1 = (*(code *)param_1[7])(0,param_1);
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
    if (iVar4 == 0) {
      return 1;
    }
  }
  if (param_2[1].akid == (AUTHORITY_KEYID *)0x0) {
    if ((*(int *)(iVar4 + 0x80) << 0x1e < 0) && ((*(uint *)(iVar4 + 0x84) & 2) == 0)) {
      param_1[0x18] = 0x23;
      iVar1 = (*(code *)param_1[7])(0,param_1);
      if (iVar1 == 0) {
        return 0;
      }
    }
    uVar3 = param_1[0x1c];
    if ((uVar3 & 0x80) == 0) {
      param_1[0x18] = 0x2c;
      iVar1 = (*(code *)param_1[7])(0,param_1);
      if (iVar1 == 0) {
        return 0;
      }
      uVar3 = param_1[0x1c];
    }
    if (-1 < (int)(uVar3 << 0x1c)) {
      if ((param_1[0x1e] == 0) &&
         (iVar1 = X509_STORE_CTX_init(&XStack_a8,(X509_STORE *)*param_1,(X509 *)param_1[0x1a],
                                      (stack_st_X509 *)param_1[2]), iVar1 != 0)) {
        XStack_a8.untrusted = (stack_st_X509 *)param_1[3];
        X509_STORE_CTX_set0_param(&XStack_a8,(X509_VERIFY_PARAM *)param_1[4]);
        XStack_a8.verify = (_func_1997 *)param_1[7];
        XStack_a8.current_reasons = (uint)param_1;
        iVar1 = X509_verify_cert(&XStack_a8);
        if (iVar1 < 1) {
          X509_STORE_CTX_cleanup(&XStack_a8);
        }
        else {
          uVar6 = param_1[0x14];
          iVar1 = OPENSSL_sk_num(uVar6);
          a = (X509 *)OPENSSL_sk_value(uVar6,iVar1 + -1);
          iVar1 = OPENSSL_sk_num(XStack_a8.last_untrusted);
          b = (X509 *)OPENSSL_sk_value(XStack_a8.last_untrusted,iVar1 + -1);
          iVar1 = X509_cmp(a,b);
          X509_STORE_CTX_cleanup(&XStack_a8);
          if (iVar1 == 0) goto LAB_00166d9c;
        }
      }
      param_1[0x18] = 0x36;
      iVar1 = (*(code *)param_1[7])(0,param_1);
      if (iVar1 == 0) {
        return 0;
      }
    }
LAB_00166d9c:
    if ((int)param_2[1].signature << 0x1e < 0) {
      param_1[0x18] = 0x29;
      iVar1 = (*(code *)param_1[7])(0,param_1);
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  if ((int)(param_1[0x1c] << 0x19) < 0) goto LAB_00166d0e;
  uVar3 = *(uint *)(param_1[4] + 0xc);
  if ((int)(uVar3 << 0x1e) < 0) {
    t = (time_t *)(param_1[4] + 4);
  }
  else {
    t = (time_t *)(uVar3 & 0x200000);
    if (t != (time_t *)0x0) goto LAB_00166d0e;
  }
  param_1[0x1b] = param_2;
  pAVar2 = (ASN1_TIME *)X509_CRL_get0_lastUpdate(param_2);
  iVar1 = X509_cmp_time(pAVar2,t);
  if (iVar1 == 0) {
    param_1[0x18] = 0xf;
    iVar1 = (*(code *)param_1[7])(0,param_1);
joined_r0x00166d64:
    if (iVar1 == 0) {
      return 0;
    }
  }
  else if (0 < iVar1) {
    param_1[0x18] = 0xb;
    iVar1 = (*(code *)param_1[7])(0,param_1);
    goto joined_r0x00166d64;
  }
  iVar1 = X509_CRL_get0_nextUpdate(param_2);
  if (iVar1 != 0) {
    pAVar2 = (ASN1_TIME *)X509_CRL_get0_nextUpdate(param_2);
    iVar1 = X509_cmp_time(pAVar2,t);
    if (iVar1 == 0) {
      param_1[0x18] = 0x10;
      iVar1 = (*(code *)param_1[7])(0,param_1);
    }
    else {
      if ((-1 < iVar1) || ((param_1[0x1c] & 2) != 0)) goto LAB_00166d0a;
      param_1[0x18] = 0xc;
      iVar1 = (*(code *)param_1[7])(0,param_1);
    }
    if (iVar1 == 0) {
      return 0;
    }
  }
LAB_00166d0a:
  param_1[0x1b] = 0;
LAB_00166d0e:
  r = (EVP_PKEY *)X509_get0_pubkey(iVar4);
  if (r == (EVP_PKEY *)0x0) {
    param_1[0x18] = 6;
    iVar4 = (*(code *)param_1[7])(0,param_1);
    if (iVar4 != 0) {
      return 1;
    }
    return 0;
  }
  iVar4 = X509_CRL_check_suiteb(param_2,r,*(undefined4 *)(param_1[4] + 0xc));
  if (iVar4 != 0) {
    param_1[0x18] = iVar4;
    iVar4 = (*(code *)param_1[7])(0,param_1);
    if (iVar4 == 0) {
      return 0;
    }
  }
  iVar4 = X509_CRL_verify(param_2,r);
  if (0 < iVar4) {
    return 1;
  }
  param_1[0x18] = 8;
  iVar4 = (*(code *)param_1[7])(0,param_1);
  if (iVar4 != 0) {
    return 1;
  }
  return 0;
}

