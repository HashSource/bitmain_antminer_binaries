
undefined4 pkey_pss_init(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  RSA *rsa;
  EVP_MD *local_1c;
  undefined4 local_18;
  int local_14;
  
  if (*(int *)*param_1 != 0x390) {
    return 0;
  }
  rsa = *(RSA **)(param_1[2] + 0x18);
  iVar4 = (rsa->ex_data).dummy;
  if (iVar4 == 0) {
    uVar1 = 1;
  }
  else {
    iVar5 = param_1[5];
    iVar4 = rsa_pss_get_param(iVar4,&local_1c,&local_18,&local_14);
    if (iVar4 != 0) {
      iVar4 = RSA_size(rsa);
      iVar2 = EVP_MD_size(local_1c);
      iVar4 = iVar4 - iVar2;
      uVar3 = RSA_bits(rsa);
      if ((uVar3 & 7) == 1) {
        iVar4 = iVar4 + -1;
      }
      if (local_14 <= iVar4) {
        *(int *)(iVar5 + 0x24) = local_14;
        *(int *)(iVar5 + 0x20) = local_14;
        *(EVP_MD **)(iVar5 + 0x18) = local_1c;
        *(undefined4 *)(iVar5 + 0x1c) = local_18;
        return 1;
      }
      ERR_put_error(4,0xa5,0x96,"crypto/rsa/rsa_pmeth.c",0x335);
    }
    uVar1 = 0;
  }
  return uVar1;
}

