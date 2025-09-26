
undefined4
do_sigver_init(EVP_MD_CTX *param_1,undefined4 *param_2,EVP_MD *param_3,ENGINE *param_4,
              EVP_PKEY *param_5,int param_6)

{
  int iVar1;
  char *name;
  EVP_PKEY_CTX *pEVar2;
  int local_1c;
  
  pEVar2 = param_1->pctx;
  if (pEVar2 == (EVP_PKEY_CTX *)0x0) {
    pEVar2 = EVP_PKEY_CTX_new(param_5,param_4);
    param_1->pctx = pEVar2;
    if (pEVar2 == (EVP_PKEY_CTX *)0x0) {
      return 0;
    }
  }
  if ((-1 < *(int *)(*(int *)pEVar2 + 4) << 0x1d) && (param_3 == (EVP_MD *)0x0)) {
    iVar1 = EVP_PKEY_get_default_digest_nid(param_5,&local_1c);
    if (iVar1 < 1) {
LAB_0015803e:
      ERR_put_error(6,0xa1,0x9e,"m_sigver.c",0x55);
      return 0;
    }
    name = OBJ_nid2sn(local_1c);
    param_3 = EVP_get_digestbyname(name);
    if (param_3 == (EVP_MD *)0x0) goto LAB_0015803e;
    pEVar2 = param_1->pctx;
  }
  if (param_6 == 0) {
    if (*(code **)(*(int *)pEVar2 + 0x3c) != (code *)0x0) {
      iVar1 = (**(code **)(*(int *)pEVar2 + 0x3c))(pEVar2,param_1);
      if (iVar1 < 1) {
        return 0;
      }
      pEVar2 = param_1->pctx;
      *(undefined4 *)(pEVar2 + 0x10) = 0x40;
      goto LAB_00157fe6;
    }
    iVar1 = EVP_PKEY_sign_init(pEVar2);
  }
  else {
    if (*(code **)(*(int *)pEVar2 + 0x44) != (code *)0x0) {
      iVar1 = (**(code **)(*(int *)pEVar2 + 0x44))(pEVar2,param_1);
      if (iVar1 < 1) {
        return 0;
      }
      pEVar2 = param_1->pctx;
      *(undefined4 *)(pEVar2 + 0x10) = 0x80;
      goto LAB_00157fe6;
    }
    iVar1 = EVP_PKEY_verify_init(pEVar2);
  }
  if (iVar1 < 1) {
    return 0;
  }
  pEVar2 = param_1->pctx;
LAB_00157fe6:
  iVar1 = EVP_PKEY_CTX_ctrl(pEVar2,-1,0xf8,1,0,param_3);
  if (iVar1 < 1) {
    return 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_1->pctx;
  }
  if (*(int *)(*(int *)param_1->pctx + 4) << 0x1d < 0) {
    return 1;
  }
  iVar1 = EVP_DigestInit_ex(param_1,param_3,param_4);
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

