
int pkey_ec_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,char *param_3)

{
  int iVar1;
  long p1;
  EVP_MD *p2;
  
  iVar1 = strcmp(param_2,DAT_000f8504);
  if (iVar1 == 0) {
    iVar1 = EC_curve_nist2nid(param_3);
    if (((iVar1 == 0) && (iVar1 = OBJ_sn2nid(param_3), iVar1 == 0)) &&
       (iVar1 = OBJ_ln2nid(param_3), iVar1 == 0)) {
      ERR_put_error(0x10,0xc6,0x8d,DAT_000f851c,0x1a6);
      return 0;
    }
    iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x198,6,0x1001,iVar1,(void *)0x0);
    return iVar1;
  }
  iVar1 = strcmp(param_2,DAT_000f8508);
  if (iVar1 == 0) {
    iVar1 = strcmp(param_3,DAT_000f850c);
    if (iVar1 != 0) {
      iVar1 = strcmp(param_3,DAT_000f8510);
      if (iVar1 != 0) goto LAB_000f84e6;
      iVar1 = 1;
    }
    iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x198,6,0x1002,iVar1,(void *)0x0);
  }
  else {
    iVar1 = strcmp(param_2,DAT_000f8514);
    if (iVar1 == 0) {
      p2 = EVP_get_digestbyname(param_3);
      if (p2 != (EVP_MD *)0x0) {
        iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x198,0x400,0x1005,0,p2);
        return iVar1;
      }
      ERR_put_error(0x10,0xc6,0x97,DAT_000f851c,0x1b6);
      return 0;
    }
    iVar1 = strcmp(param_2,DAT_000f8518);
    if (iVar1 == 0) {
      p1 = strtol(param_3,(char **)0x0,10);
      iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x198,0x400,0x1003,p1,(void *)0x0);
      return iVar1;
    }
LAB_000f84e6:
    iVar1 = -2;
  }
  return iVar1;
}

