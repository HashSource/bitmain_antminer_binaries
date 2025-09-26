
undefined4 check_padding_md(EVP_MD *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (EVP_MD *)0x0) {
    return 1;
  }
  iVar1 = EVP_MD_type(param_1);
  if (param_2 == 3) {
    ERR_put_error(4,0x8c,0x8d,"crypto/rsa/rsa_pmeth.c",0x168);
    uVar2 = 0;
  }
  else {
    if (param_2 == 5) {
      iVar1 = RSA_X931_hash_id(iVar1);
      if (iVar1 == -1) {
        ERR_put_error(4,0x8c,0x8e,"crypto/rsa/rsa_pmeth.c",0x16e);
        return 0;
      }
    }
    else if (iVar1 != 0x75) {
      if (iVar1 < 0x76) {
        if (iVar1 != 0x40) {
          if (iVar1 < 0x41) {
            if (1 < iVar1 - 3U) goto LAB_0015bf6a;
          }
          else if ((iVar1 != 0x5f) && (iVar1 != 0x72)) goto LAB_0015bf6a;
        }
      }
      else if (iVar1 < 0x2a4) {
        if ((iVar1 < 0x2a0) && (iVar1 != 0x101)) {
LAB_0015bf6a:
          ERR_put_error(4,0x8c,0x9d,"crypto/rsa/rsa_pmeth.c",0x186);
          return 0;
        }
      }
      else if (3 < iVar1 - 0x448U) goto LAB_0015bf6a;
    }
    uVar2 = 1;
  }
  return uVar2;
}

