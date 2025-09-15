
undefined4 internal_verify(int param_1)

{
  int iVar1;
  X509 *pXVar2;
  int iVar3;
  X509 *a;
  EVP_PKEY *r;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  X509 *pXVar7;
  code *pcVar8;
  time_t *t;
  
  pcVar8 = *(code **)(param_1 + 0x20);
  iVar1 = sk_num(*(_STACK **)(param_1 + 0x54));
  iVar6 = iVar1 + -1;
  *(int *)(param_1 + 0x60) = iVar6;
  pXVar2 = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar6);
  iVar3 = (**(code **)(param_1 + 0x28))(param_1,pXVar2,pXVar2);
  pXVar7 = pXVar2;
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_1 + 0x14);
    uVar5 = *(uint *)(iVar3 + 0xc);
    if ((int)(uVar5 << 0xc) < 0) goto LAB_000c0f6c;
    if (iVar6 < 1) {
      *(X509 **)(param_1 + 0x68) = pXVar2;
      *(undefined4 *)(param_1 + 100) = 0x15;
      uVar4 = (*pcVar8)(0,param_1);
      return uVar4;
    }
    iVar6 = iVar1 + -2;
    *(int *)(param_1 + 0x60) = iVar6;
    a = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar6);
    goto LAB_000c0fe6;
  }
  if (iVar6 < 0) {
    return 1;
  }
  iVar1 = pXVar2->valid;
  *(int *)(param_1 + 0x60) = iVar6;
  a = pXVar2;
  if (iVar1 == 0) goto LAB_000c103a;
LAB_000c0f64:
  do {
    iVar3 = *(int *)(param_1 + 0x14);
    uVar5 = *(uint *)(iVar3 + 0xc);
    pXVar2 = a;
    do {
      pXVar2->valid = 1;
LAB_000c0f6c:
      t = (time_t *)(uVar5 & 2);
      if (t != (time_t *)0x0) {
        t = (time_t *)(iVar3 + 4);
      }
      iVar1 = X509_cmp_time(pXVar2->cert_info->validity->notBefore,t);
      if (iVar1 == 0) {
        *(X509 **)(param_1 + 0x68) = pXVar2;
        *(undefined4 *)(param_1 + 100) = 0xd;
        iVar1 = (**(code **)(param_1 + 0x20))(0,param_1);
joined_r0x000c1024:
        if (iVar1 == 0) {
          return 0;
        }
      }
      else if (0 < iVar1) {
        *(X509 **)(param_1 + 0x68) = pXVar2;
        *(undefined4 *)(param_1 + 100) = 9;
        iVar1 = (**(code **)(param_1 + 0x20))(0,param_1);
        goto joined_r0x000c1024;
      }
      iVar1 = X509_cmp_time(pXVar2->cert_info->validity->notAfter,t);
      if (iVar1 == 0) {
        *(X509 **)(param_1 + 0x68) = pXVar2;
        *(undefined4 *)(param_1 + 100) = 0xe;
        iVar1 = (**(code **)(param_1 + 0x20))(0,param_1);
joined_r0x000c1052:
        if (iVar1 == 0) {
          return 0;
        }
      }
      else if (iVar1 < 0) {
        *(X509 **)(param_1 + 0x68) = pXVar2;
        *(undefined4 *)(param_1 + 100) = 10;
        iVar1 = (**(code **)(param_1 + 0x20))(0,param_1);
        goto joined_r0x000c1052;
      }
      *(X509 **)(param_1 + 0x6c) = pXVar7;
      *(X509 **)(param_1 + 0x68) = pXVar2;
      iVar1 = (*pcVar8)(1,param_1);
      if (iVar1 == 0) {
        return 0;
      }
      iVar6 = iVar6 + -1;
      if (iVar6 < 0) {
        return 1;
      }
      a = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar6);
LAB_000c0fe6:
      iVar1 = a->valid;
      *(int *)(param_1 + 0x60) = iVar6;
      pXVar7 = pXVar2;
      if (iVar1 != 0) goto LAB_000c0f64;
      if (a != pXVar2) break;
LAB_000c103a:
      iVar3 = *(int *)(param_1 + 0x14);
      uVar5 = *(uint *)(iVar3 + 0xc);
      pXVar2 = a;
    } while (-1 < (int)(uVar5 << 0x11));
    r = X509_get_pubkey(pXVar7);
    if (r == (EVP_PKEY *)0x0) {
      *(X509 **)(param_1 + 0x68) = pXVar7;
      *(undefined4 *)(param_1 + 100) = 6;
      iVar1 = (*pcVar8)(0,param_1);
      if (iVar1 == 0) {
        return 0;
      }
    }
    else {
      iVar1 = X509_verify(a,r);
      if (iVar1 < 1) {
        *(X509 **)(param_1 + 0x68) = a;
        *(undefined4 *)(param_1 + 100) = 7;
        iVar1 = (*pcVar8)(0,param_1);
        if (iVar1 == 0) {
          EVP_PKEY_free(r);
          return 0;
        }
      }
    }
    EVP_PKEY_free(r);
  } while( true );
}

