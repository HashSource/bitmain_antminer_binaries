
int pkey_dh_paramgen(int param_1,EVP_PKEY *param_2)

{
  int iVar1;
  BN_GENCB *cb;
  DSA *r;
  void *key;
  DH *pDVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  EVP_MD *pEVar6;
  
  piVar4 = *(int **)(param_1 + 0x14);
  iVar3 = piVar4[6];
  if (iVar3 != 0) {
    if (iVar3 == 2) {
      pDVar2 = (DH *)DH_get_2048_224();
    }
    else if (iVar3 == 3) {
      pDVar2 = (DH *)DH_get_2048_256();
    }
    else {
      if (iVar3 != 1) {
        return -2;
      }
      pDVar2 = (DH *)DH_get_1024_160();
    }
    goto LAB_001978a8;
  }
  if (piVar4[7] != 0) {
    key = (void *)DH_new_by_nid();
    if (key == (void *)0x0) {
      return 0;
    }
    EVP_PKEY_assign(param_2,0x1c,key);
    return 1;
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    cb = (BN_GENCB *)0x0;
  }
  else {
    cb = (BN_GENCB *)BN_GENCB_new();
    if (cb == (BN_GENCB *)0x0) {
      return 0;
    }
    evp_pkey_set_cb_translate(cb,param_1);
  }
  if (piVar4[2] == 0) {
    pDVar2 = DH_new();
    if (pDVar2 == (DH *)0x0) {
      BN_GENCB_free(cb);
      return 0;
    }
    iVar3 = DH_generate_parameters_ex(pDVar2,*piVar4,piVar4[1],cb);
    BN_GENCB_free(cb);
    if (iVar3 == 0) {
      DH_free(pDVar2);
      return 0;
    }
    EVP_PKEY_assign(param_2,0x1c,pDVar2);
    return iVar3;
  }
  if (2 < piVar4[2]) goto LAB_0019787c;
  iVar5 = *piVar4;
  iVar3 = piVar4[3];
  pEVar6 = (EVP_MD *)piVar4[5];
  r = DSA_new();
  if (r == (DSA *)0x0) goto LAB_0019787c;
  if (iVar3 == -1) {
    if (iVar5 < 0x800) {
      iVar3 = 0xa0;
      if (pEVar6 == (EVP_MD *)0x0) goto LAB_00197924;
    }
    else {
      iVar3 = 0x100;
      iVar1 = 0x100;
      if (pEVar6 == (EVP_MD *)0x0) goto LAB_00197912;
    }
  }
  else if (pEVar6 == (EVP_MD *)0x0) {
    iVar1 = iVar3;
    if (iVar5 < 0x800) {
LAB_00197924:
      pEVar6 = EVP_sha1();
    }
    else {
LAB_00197912:
      iVar3 = iVar1;
      pEVar6 = EVP_sha256();
    }
  }
  if (piVar4[2] == 1) {
    iVar3 = dsa_builtin_paramgen(r,iVar5,iVar3,pEVar6,0,0,0,0,0,cb);
LAB_00197948:
    if (0 < iVar3) {
      BN_GENCB_free(cb);
      pDVar2 = DSA_dup_DH(r);
      DSA_free(r);
      if (pDVar2 == (DH *)0x0) {
        return 0;
      }
LAB_001978a8:
      EVP_PKEY_assign(param_2,0x398,pDVar2);
      return 1;
    }
  }
  else if (piVar4[2] == 2) {
    iVar3 = dsa_builtin_paramgen2(r,iVar5,iVar3,pEVar6,0,0,0xffffffff,0,0,0,cb);
    goto LAB_00197948;
  }
  DSA_free(r);
LAB_0019787c:
  BN_GENCB_free(cb);
  return 0;
}

