
undefined4 ssl3_check_client_certificate(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  EVP_PKEY *b;
  int *piVar3;
  int **ppiVar4;
  EVP_PKEY *pkey;
  int iVar5;
  int iVar6;
  
  ppiVar4 = *(int ***)(param_1 + 0x98);
  if (((((ppiVar4 == (int **)0x0) || (piVar3 = *ppiVar4, *piVar3 == 0)) || (piVar3[1] == 0)) ||
      ((*(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) << 0x1e < 0 && (piVar3[2] == 0)))) ||
     ((((uint)ppiVar4[0xe] & 0x30001) != 0 &&
      (iVar2 = tls1_check_chain(param_1,0,0,0,0xfffffffe), iVar2 == 0)))) {
LAB_00065a80:
    uVar1 = 0;
  }
  else {
    if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0xc) & 6) != 0) {
      iVar5 = *(int *)(*(int *)(param_1 + 0xc0) + 0x98);
      pkey = *(EVP_PKEY **)(**(int **)(param_1 + 0x98) + 4);
      iVar6 = *(int *)(iVar5 + 4);
      iVar2 = EVP_PKEY_id(pkey);
      if (iVar2 == 0x1c) {
        if ((iVar6 < 0) ||
           (b = X509_get_pubkey(*(X509 **)(iVar5 + iVar6 * 0x1c + 0xc)), b == (EVP_PKEY *)0x0)) {
LAB_00065a9c:
          **(uint **)(param_1 + 0x58) = **(uint **)(param_1 + 0x58) | 0x10;
          return 1;
        }
        iVar2 = EVP_PKEY_cmp_parameters(pkey,b);
        EVP_PKEY_free(b);
        if (iVar2 == 1) goto LAB_00065a9c;
        goto LAB_00065a80;
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}

