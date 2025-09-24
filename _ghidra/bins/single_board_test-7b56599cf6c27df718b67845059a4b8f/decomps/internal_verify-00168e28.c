
undefined4 internal_verify(int param_1)

{
  int iVar1;
  X509 *pXVar2;
  int iVar3;
  X509 *pXVar4;
  EVP_PKEY *r;
  X509 *pXVar5;
  undefined4 uVar6;
  int iVar7;
  X509 *pXVar8;
  
  iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50));
  iVar7 = iVar1 + -1;
  pXVar2 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar7);
  if (*(int *)(param_1 + 0x84) != 0) {
    pXVar4 = (X509 *)0x0;
    goto LAB_00168e66;
  }
  iVar3 = (**(code **)(param_1 + 0x24))(param_1,pXVar2,pXVar2);
  pXVar4 = pXVar2;
  if (iVar3 == 0) {
    if ((*(uint *)(*(int *)(param_1 + 0x10) + 0xc) & 0x80000) != 0) goto LAB_00168e66;
    if (iVar7 < 1) {
      *(undefined4 *)(param_1 + 0x5c) = 0;
      pXVar5 = pXVar2;
      if (pXVar2 == (X509 *)0x0) {
        pXVar5 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),0);
      }
      *(X509 **)(param_1 + 100) = pXVar5;
      *(undefined4 *)(param_1 + 0x60) = 0x15;
      iVar1 = (**(code **)(param_1 + 0x1c))(0,param_1);
      if (iVar1 != 0) goto LAB_00168e66;
      return 0;
    }
    iVar7 = iVar1 + -2;
    *(int *)(param_1 + 0x5c) = iVar7;
    pXVar4 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar7);
    if (-1 < iVar7) goto LAB_00168e9c;
  }
  else if (-1 < iVar7) {
    do {
      pXVar2 = pXVar4;
      if ((*(int *)(*(int *)(param_1 + 0x10) + 0xc) << 0x11 < 0) &&
         (pXVar4[1].references << 0x12 < 0)) {
        pXVar5 = pXVar4;
        if (pXVar4[1].references << 0x1b < 0) {
          iVar3 = x509_signing_allowed(pXVar4,pXVar4);
          iVar1 = iVar7;
          if (iVar3 == 0) goto LAB_00168eca;
          *(int *)(param_1 + 0x5c) = iVar7;
          goto LAB_00168eba;
        }
        r = (EVP_PKEY *)X509_get0_pubkey(pXVar4);
        pXVar8 = pXVar4;
        if (r != (EVP_PKEY *)0x0) goto LAB_00168ed4;
        *(int *)(param_1 + 0x5c) = iVar7;
        goto LAB_00168f82;
      }
LAB_00168e66:
      iVar1 = x509_check_cert_time(param_1,pXVar2,iVar7);
      if (iVar1 == 0) {
        return 0;
      }
      *(X509 **)(param_1 + 0x68) = pXVar4;
      *(X509 **)(param_1 + 100) = pXVar2;
      *(int *)(param_1 + 0x5c) = iVar7;
      iVar1 = (**(code **)(param_1 + 0x1c))(1,param_1);
      if (iVar1 == 0) {
        return 0;
      }
      iVar7 = iVar7 + -1;
      if (iVar7 < 0) {
        return 1;
      }
      pXVar4 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar7);
LAB_00168e9c:
      if (pXVar4 != pXVar2) {
        iVar3 = x509_signing_allowed(pXVar2,pXVar4);
        iVar1 = iVar7 + 1;
        pXVar5 = pXVar4;
        if (iVar3 != 0) {
          *(int *)(param_1 + 0x5c) = iVar1;
          pXVar5 = pXVar2;
          if (pXVar2 == (X509 *)0x0) {
            pXVar5 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar1);
          }
LAB_00168eba:
          *(X509 **)(param_1 + 100) = pXVar5;
          *(int *)(param_1 + 0x60) = iVar3;
          iVar3 = (**(code **)(param_1 + 0x1c))(0,param_1);
          pXVar5 = pXVar4;
          if (iVar3 == 0) {
            return 0;
          }
        }
LAB_00168eca:
        r = (EVP_PKEY *)X509_get0_pubkey(pXVar2);
        pXVar8 = pXVar2;
        if (r != (EVP_PKEY *)0x0) goto LAB_00168ed4;
        *(int *)(param_1 + 0x5c) = iVar1;
        pXVar4 = pXVar2;
        if (pXVar2 == (X509 *)0x0) {
          pXVar4 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar1);
        }
LAB_00168f82:
        uVar6 = 6;
        goto LAB_00168eea;
      }
    } while( true );
  }
  return 1;
LAB_00168ed4:
  iVar1 = X509_verify(pXVar5,r);
  pXVar2 = pXVar5;
  pXVar4 = pXVar8;
  if (iVar1 < 1) {
    *(int *)(param_1 + 0x5c) = iVar7;
    pXVar4 = pXVar5;
    if (pXVar5 == (X509 *)0x0) {
      pXVar4 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar7);
    }
    uVar6 = 7;
LAB_00168eea:
    *(X509 **)(param_1 + 100) = pXVar4;
    *(undefined4 *)(param_1 + 0x60) = uVar6;
    iVar1 = (**(code **)(param_1 + 0x1c))(0,param_1);
    pXVar2 = pXVar5;
    pXVar4 = pXVar8;
    if (iVar1 == 0) {
      return 0;
    }
  }
  goto LAB_00168e66;
}

