
undefined4 pkey_dsa_ctrl(int param_1,int param_2,uint param_3,EVP_MD *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0x14);
  if (param_2 == 0xb) {
LAB_000ff50a:
    uVar2 = 1;
  }
  else {
    if (param_2 < 0xc) {
      if (param_2 == 2) {
        ERR_put_error(10,0x78,0x96,DAT_000ff5b8,0xd3);
        return 0xfffffffe;
      }
      if (param_2 < 3) {
        if (param_2 == 1) {
          iVar1 = EVP_MD_type(param_4);
          if ((((iVar1 != 0x40) && (iVar1 = EVP_MD_type(param_4), iVar1 != 0x74)) &&
              (iVar1 = EVP_MD_type(param_4), iVar1 != 0x42)) &&
             (((iVar1 = EVP_MD_type(param_4), iVar1 != 0x2a3 &&
               (iVar1 = EVP_MD_type(param_4), iVar1 != 0x2a0)) &&
              ((iVar1 = EVP_MD_type(param_4), iVar1 != 0x2a1 &&
               (iVar1 = EVP_MD_type(param_4), iVar1 != 0x2a2)))))) {
            iVar1 = 0xc2;
LAB_000ff4ea:
            ERR_put_error(10,0x78,0x6a,DAT_000ff5b8,iVar1);
            return 0;
          }
LAB_000ff576:
          puVar3[5] = (uint)param_4;
          return 1;
        }
      }
      else if ((param_2 == 5) || (param_2 == 7)) goto LAB_000ff50a;
    }
    else if (param_2 == 0x1001) {
      if (0xff < (int)param_3) {
        *puVar3 = param_3;
        goto LAB_000ff50a;
      }
    }
    else if (param_2 < 0x1002) {
      if (param_2 == 0xd) {
        param_4->type = puVar3[5];
        return 1;
      }
    }
    else if (param_2 == 0x1002) {
      if (((param_3 & 0xffffffbf) == 0xa0) || ((param_3 & 0xfffffeff) == 0)) {
        puVar3[1] = param_3;
        return 1;
      }
    }
    else if (param_2 == 0x1003) {
      iVar1 = EVP_MD_type(param_4);
      if (((iVar1 != 0x40) && (iVar1 = EVP_MD_type(param_4), iVar1 != 0x2a3)) &&
         (iVar1 = EVP_MD_type(param_4), iVar1 != 0x2a0)) {
        iVar1 = 0xb4;
        goto LAB_000ff4ea;
      }
      goto LAB_000ff576;
    }
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}

