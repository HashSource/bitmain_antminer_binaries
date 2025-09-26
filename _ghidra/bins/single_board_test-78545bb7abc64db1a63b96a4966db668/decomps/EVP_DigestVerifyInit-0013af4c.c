
int EVP_DigestVerifyInit(EVP_MD_CTX *ctx,EVP_PKEY_CTX **pctx,EVP_MD *type,ENGINE *e,EVP_PKEY *pkey)

{
  EVP_PKEY_CTX *ctx_00;
  int iVar1;
  char *name;
  code *pcVar2;
  int local_1c [2];
  
  ctx_00 = ctx->pctx;
  if (ctx_00 == (EVP_PKEY_CTX *)0x0) {
    ctx_00 = EVP_PKEY_CTX_new(pkey,e);
    ctx->pctx = ctx_00;
    if (ctx_00 == (EVP_PKEY_CTX *)0x0) {
      return 0;
    }
  }
  if (((uint)(type == (EVP_MD *)0x0) & (*(uint *)(*(int *)ctx_00 + 4) ^ 4) >> 2) == 0) {
LAB_0013af72:
    pcVar2 = *(code **)(*(int *)ctx_00 + 0x44);
    if (pcVar2 == (code *)0x0) {
      if (*(int *)(*(int *)ctx_00 + 0x70) == 0) {
        iVar1 = EVP_PKEY_verify_init(ctx_00);
        if (iVar1 < 1) {
          return 0;
        }
        ctx_00 = ctx->pctx;
      }
      else {
        *(undefined4 *)(ctx_00 + 0x10) = 0x10;
        ctx->update = (_func_1230 *)0x13ae31;
      }
    }
    else {
      iVar1 = (*pcVar2)(ctx_00,ctx);
      if (iVar1 < 1) {
        return 0;
      }
      ctx_00 = ctx->pctx;
      *(undefined4 *)(ctx_00 + 0x10) = 0x80;
    }
    iVar1 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,1,0,type);
    if (0 < iVar1) {
      if (pctx != (EVP_PKEY_CTX **)0x0) {
        *pctx = ctx->pctx;
      }
      if (-1 < *(int *)(*(int *)ctx->pctx + 4) << 0x1d) {
        iVar1 = EVP_DigestInit_ex(ctx,type,e);
        if (iVar1 == 0) {
          return 0;
        }
        pcVar2 = *(code **)(*(int *)ctx->pctx + 0x80);
        if (pcVar2 != (code *)0x0) {
          iVar1 = (*pcVar2)(ctx->pctx,ctx);
          return iVar1;
        }
      }
      return 1;
    }
  }
  else {
    iVar1 = EVP_PKEY_get_default_digest_nid(pkey,local_1c);
    if (0 < iVar1) {
      name = OBJ_nid2sn(local_1c[0]);
      type = EVP_get_digestbyname(name);
      if (type != (EVP_MD *)0x0) {
        ctx_00 = ctx->pctx;
        goto LAB_0013af72;
      }
    }
    ERR_put_error(6,0xa1,0x9e,"crypto/evp/m_sigver.c",0x2a);
  }
  return 0;
}

