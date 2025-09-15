
int pkey_dh_paramgen(int param_1,EVP_PKEY *param_2)

{
  int iVar1;
  DSA *r;
  void *key;
  DH *pDVar2;
  int iVar3;
  BN_GENCB *cb;
  int *piVar4;
  EVP_MD *pEVar5;
  int iVar6;
  BN_GENCB BStack_2c;
  
  piVar4 = *(int **)(param_1 + 0x14);
  iVar3 = piVar4[5];
  if (iVar3 != 0) {
    if (iVar3 == 2) {
      key = (void *)DH_get_2048_224();
    }
    else if (iVar3 == 3) {
      key = (void *)DH_get_2048_256();
    }
    else {
      if (iVar3 != 1) {
        return -2;
      }
      key = (void *)DH_get_1024_160();
    }
    EVP_PKEY_assign(param_2,0x398,key);
    return 1;
  }
  cb = *(BN_GENCB **)(param_1 + 0x1c);
  if (cb != (BN_GENCB *)0x0) {
    cb = &BStack_2c;
    evp_pkey_set_cb_translate(cb,param_1);
  }
  if (piVar4[2] == 0) {
    pDVar2 = DH_new();
    if (pDVar2 == (DH *)0x0) {
      return 0;
    }
    iVar3 = DH_generate_parameters_ex(pDVar2,*piVar4,piVar4[1],cb);
    if (iVar3 == 0) {
      DH_free(pDVar2);
      return 0;
    }
    EVP_PKEY_assign(param_2,0x1c,pDVar2);
    return iVar3;
  }
  iVar6 = *piVar4;
  iVar3 = piVar4[3];
  pEVar5 = (EVP_MD *)piVar4[4];
  if (2 < piVar4[2]) {
    return 0;
  }
  r = DSA_new();
  if (r == (DSA *)0x0) {
    return 0;
  }
  if (iVar3 == -1) {
    if (iVar6 < 0x800) {
      iVar3 = 0xa0;
      if (pEVar5 == (EVP_MD *)0x0) goto LAB_0010090a;
    }
    else {
      iVar3 = 0x100;
      iVar1 = 0x100;
      if (pEVar5 == (EVP_MD *)0x0) goto LAB_001008f8;
    }
  }
  else if (pEVar5 == (EVP_MD *)0x0) {
    iVar1 = iVar3;
    if (iVar6 < 0x800) {
LAB_0010090a:
      pEVar5 = EVP_sha1();
    }
    else {
LAB_001008f8:
      iVar3 = iVar1;
      pEVar5 = EVP_sha256();
    }
  }
  if (piVar4[2] == 1) {
    iVar3 = dsa_builtin_paramgen(r,iVar6,iVar3,pEVar5,0,0,0,0,0,cb);
  }
  else {
    if (piVar4[2] != 2) goto LAB_0010088e;
    iVar3 = dsa_builtin_paramgen2(r,iVar6,iVar3,pEVar5,0,0,0xffffffff,0,0,0,cb);
  }
  if (0 < iVar3) {
    pDVar2 = DSA_dup_DH(r);
    DSA_free(r);
    if (pDVar2 == (DH *)0x0) {
      return 0;
    }
    EVP_PKEY_assign(param_2,0x398,pDVar2);
    return 1;
  }
LAB_0010088e:
  DSA_free(r);
  return 0;
}

