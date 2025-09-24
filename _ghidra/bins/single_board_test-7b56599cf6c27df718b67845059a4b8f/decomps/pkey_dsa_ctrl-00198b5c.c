
undefined4 pkey_dsa_ctrl(int param_1,int param_2,uint param_3,EVP_MD *param_4)

{
  int iVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_1 + 0x14);
  if (param_2 == 0xb) {
    return 1;
  }
  if (param_2 < 0xc) {
    if (param_2 == 2) {
      ERR_put_error(10,0x78,0x96,"crypto/dsa/dsa_pmeth.c",0xa3);
      return 0xfffffffe;
    }
    if (2 < param_2) {
      if (param_2 == 5) {
        return 1;
      }
      if (param_2 != 7) {
        return 0xfffffffe;
      }
      return 1;
    }
    if (param_2 != 1) {
      return 0xfffffffe;
    }
    iVar1 = EVP_MD_type(param_4);
    if ((((((iVar1 == 0x40) || (iVar1 = EVP_MD_type(param_4), iVar1 == 0x74)) ||
          (iVar1 = EVP_MD_type(param_4), iVar1 == 0x42)) ||
         (((iVar1 = EVP_MD_type(param_4), iVar1 == 0x2a3 ||
           (iVar1 = EVP_MD_type(param_4), iVar1 == 0x2a0)) ||
          ((iVar1 = EVP_MD_type(param_4), iVar1 == 0x2a1 ||
           ((iVar1 = EVP_MD_type(param_4), iVar1 == 0x2a2 ||
            (iVar1 = EVP_MD_type(param_4), iVar1 == 0x448)))))))) ||
        (iVar1 = EVP_MD_type(param_4), iVar1 == 0x449)) ||
       ((iVar1 = EVP_MD_type(param_4), iVar1 == 0x44a ||
        (iVar1 = EVP_MD_type(param_4), iVar1 == 1099)))) {
      puVar2[5] = (uint)param_4;
      return 1;
    }
    iVar1 = 0x92;
  }
  else {
    if (param_2 == 0x1001) {
      if (0xff < (int)param_3) {
        *puVar2 = param_3;
        return 1;
      }
      return 0xfffffffe;
    }
    if (param_2 < 0x1002) {
      if (param_2 != 0xd) {
        return 0xfffffffe;
      }
      param_4->type = puVar2[5];
      return 1;
    }
    if (param_2 == 0x1002) {
      if (((param_3 & 0xffffffbf) != 0xa0) && ((param_3 & 0xfffffeff) != 0)) {
        return 0xfffffffe;
      }
      puVar2[1] = param_3;
      return 1;
    }
    if (param_2 != 0x1003) {
      return 0xfffffffe;
    }
    iVar1 = EVP_MD_type(param_4);
    if (((iVar1 == 0x40) || (iVar1 = EVP_MD_type(param_4), iVar1 == 0x2a3)) ||
       (iVar1 = EVP_MD_type(param_4), iVar1 == 0x2a0)) {
      puVar2[2] = (uint)param_4;
      return 1;
    }
    iVar1 = 0x80;
  }
  ERR_put_error(10,0x78,0x6a,"crypto/dsa/dsa_pmeth.c",iVar1);
  return 0;
}

