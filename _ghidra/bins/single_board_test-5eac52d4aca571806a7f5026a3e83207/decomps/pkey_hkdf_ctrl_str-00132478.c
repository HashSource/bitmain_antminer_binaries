
int pkey_hkdf_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = strcmp(param_2,"mode");
  if (iVar2 == 0) {
    iVar2 = strcmp(param_3,"EXTRACT_AND_EXPAND");
    if (iVar2 != 0) {
      iVar2 = strcmp(param_3,"EXTRACT_ONLY");
      if (iVar2 == 0) {
        iVar2 = 1;
      }
      else {
        iVar2 = strcmp(param_3,"EXPAND_ONLY");
        if (iVar2 != 0) {
          return 0;
        }
        iVar2 = 2;
      }
    }
    iVar2 = EVP_PKEY_CTX_ctrl(param_1,-1,0x400,0x1007,iVar2,(void *)0x0);
    return iVar2;
  }
  cVar1 = *param_2;
  if (((cVar1 == 'm') && (param_2[1] == 'd')) && (param_2[2] == '\0')) {
    iVar2 = EVP_PKEY_CTX_md(param_1,0x400,0x1003,param_3);
    return iVar2;
  }
  iVar2 = strcmp(param_2,"salt");
  if (iVar2 == 0) {
    uVar3 = 0x1004;
LAB_00132584:
    iVar2 = EVP_PKEY_CTX_str2ctrl(param_1,uVar3,param_3);
    return iVar2;
  }
  iVar2 = strcmp(param_2,"hexsalt");
  if (iVar2 == 0) {
    uVar3 = 0x1004;
  }
  else {
    if (((cVar1 == 'k') && (param_2[1] == 'e')) && ((param_2[2] == 'y' && (param_2[3] == '\0')))) {
      uVar3 = 0x1005;
      goto LAB_00132584;
    }
    iVar2 = strcmp(param_2,"hexkey");
    if (iVar2 == 0) {
      uVar3 = 0x1005;
    }
    else {
      iVar2 = strcmp(param_2,"info");
      if (iVar2 == 0) {
        uVar3 = 0x1006;
        goto LAB_00132584;
      }
      iVar2 = strcmp(param_2,"hexinfo");
      if (iVar2 != 0) {
        ERR_put_error(0x34,0x67,0x67,"crypto/kdf/hkdf.c",0xae);
        return -2;
      }
      uVar3 = 0x1006;
    }
  }
  iVar2 = EVP_PKEY_CTX_hex2ctrl(param_1,uVar3,param_3);
  return iVar2;
}

