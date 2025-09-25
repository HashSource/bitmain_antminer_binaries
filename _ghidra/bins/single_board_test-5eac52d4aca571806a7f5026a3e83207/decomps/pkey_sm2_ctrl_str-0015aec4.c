
int pkey_sm2_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = strcmp(param_2,"ec_paramgen_curve");
  if (iVar1 == 0) {
    iVar1 = EC_curve_nist2nid(param_3);
    if (((iVar1 == 0) && (iVar1 = OBJ_sn2nid(param_3), iVar1 == 0)) &&
       (iVar1 = OBJ_ln2nid(param_3), iVar1 == 0)) {
      ERR_put_error(0x35,0x6e,0x6c,"crypto/sm2/sm2_pmeth.c",0xf1);
      return 0;
    }
    iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x198,6,0x1001,iVar1,(void *)0x0);
    return iVar1;
  }
  iVar1 = strcmp(param_2,"ec_param_enc");
  if (iVar1 == 0) {
    iVar1 = strcmp(param_3,"explicit");
    if (iVar1 != 0) {
      iVar1 = strcmp(param_3,"named_curve");
      if (iVar1 != 0) goto LAB_0015af6c;
      iVar1 = 1;
    }
    iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x198,6,0x1002,iVar1,(void *)0x0);
  }
  else {
LAB_0015af6c:
    iVar1 = -2;
  }
  return iVar1;
}

