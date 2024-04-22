
undefined4
do_sigver_init(EVP_MD_CTX *param_1,EVP_PKEY_CTX **param_2,EVP_MD *param_3,ENGINE *param_4,
              EVP_PKEY *param_5,int param_6)

{
  int iVar1;
  EVP_PKEY_CTX *ctx;
  char *name;
  int *ctx_00;
  int local_1c;
  
  ctx_00 = (int *)param_1->pctx;
  if (ctx_00 == (int *)0x0) {
    ctx_00 = (int *)EVP_PKEY_CTX_new(param_5,param_4);
    param_1->pctx = (EVP_PKEY_CTX *)ctx_00;
    if (ctx_00 == (int *)0x0) {
      return 0;
    }
  }
  if ((-1 < *(int *)(*ctx_00 + 4) << 0x1d) && (param_3 == (EVP_MD *)0x0)) {
    iVar1 = EVP_PKEY_get_default_digest_nid(param_5,&local_1c);
    if (iVar1 < 1) {
LAB_000b48a2:
      ERR_put_error(6,0xa1,0x9e,DAT_000b4900,0x55);
      return 0;
    }
    name = OBJ_nid2sn(local_1c);
    param_3 = EVP_get_digestbyname(name);
    if (param_3 == (EVP_MD *)0x0) goto LAB_000b48a2;
    ctx_00 = (int *)param_1->pctx;
  }
  if (param_6 == 0) {
    if (*(code **)(*ctx_00 + 0x3c) != (code *)0x0) {
      iVar1 = (**(code **)(*ctx_00 + 0x3c))(ctx_00,param_1);
      if (iVar1 < 1) {
        return 0;
      }
      ctx = param_1->pctx;
      *(undefined4 *)(ctx + 0x10) = 0x40;
      goto LAB_000b484a;
    }
    iVar1 = EVP_PKEY_sign_init((EVP_PKEY_CTX *)ctx_00);
  }
  else {
    if (*(code **)(*ctx_00 + 0x44) != (code *)0x0) {
      iVar1 = (**(code **)(*ctx_00 + 0x44))(ctx_00,param_1);
      if (iVar1 < 1) {
        return 0;
      }
      ctx = param_1->pctx;
      *(undefined4 *)(ctx + 0x10) = 0x80;
      goto LAB_000b484a;
    }
    iVar1 = EVP_PKEY_verify_init((EVP_PKEY_CTX *)ctx_00);
  }
  if (iVar1 < 1) {
    return 0;
  }
  ctx = param_1->pctx;
LAB_000b484a:
  iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0xf8,1,0,param_3);
  if (iVar1 < 1) {
    return 0;
  }
  if (param_2 != (EVP_PKEY_CTX **)0x0) {
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

