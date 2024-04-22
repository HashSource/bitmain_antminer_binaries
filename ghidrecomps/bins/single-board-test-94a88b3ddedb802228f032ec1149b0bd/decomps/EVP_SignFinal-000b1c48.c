
int EVP_SignFinal(EVP_MD_CTX *ctx,uchar *md,uint *s,EVP_PKEY *pkey)

{
  int iVar1;
  EVP_MD *pEVar2;
  uchar *tbs;
  uint uVar3;
  EVP_PKEY_CTX *ctx_00;
  uint local_78;
  uchar *local_74;
  EVP_MD_CTX EStack_70;
  uchar auStack_58 [64];
  
  uVar3 = 0;
  *s = 0;
  EVP_MD_CTX_init(&EStack_70);
  iVar1 = EVP_MD_CTX_copy_ex(&EStack_70,ctx);
  if ((iVar1 != 0) && (iVar1 = EVP_DigestFinal_ex(&EStack_70,auStack_58,&local_78), iVar1 != 0)) {
    EVP_MD_CTX_cleanup(&EStack_70);
    pEVar2 = ctx->digest;
    if (-1 < (int)(pEVar2->flags << 0x1d)) {
      if ((pEVar2->required_pkey_type[0] != 0) &&
         ((iVar1 = pkey->type, iVar1 == pEVar2->required_pkey_type[0] ||
          ((pEVar2->required_pkey_type[1] != 0 &&
           ((iVar1 == pEVar2->required_pkey_type[1] ||
            ((pEVar2->required_pkey_type[2] != 0 &&
             ((iVar1 == pEVar2->required_pkey_type[2] ||
              ((pEVar2->required_pkey_type[3] != 0 && (pEVar2->required_pkey_type[3] == iVar1)))))))
            ))))))) {
        if (pEVar2->sign != (_func_1225 *)0x0) {
          iVar1 = (*pEVar2->sign)(pEVar2->type,auStack_58,local_78,md,s,(pkey->pkey).ptr);
          return iVar1;
        }
        ERR_put_error(6,0x6b,0x68,DAT_000b1d48,0x80);
        return 0;
      }
      ERR_put_error(6,0x6b,0x6e,DAT_000b1d48,0x7b);
      return 0;
    }
    local_74 = (uchar *)EVP_PKEY_size(pkey);
    ctx_00 = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
    if (ctx_00 != (EVP_PKEY_CTX *)0x0) {
      iVar1 = EVP_PKEY_sign_init(ctx_00);
      if ((0 < iVar1) && (iVar1 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,1,0,ctx->digest), 0 < iVar1)) {
        tbs = auStack_58;
        iVar1 = EVP_PKEY_sign(ctx_00,md,(size_t *)&local_74,tbs,local_78);
        if (0 < iVar1) {
          tbs = local_74;
        }
        uVar3 = (uint)(0 < iVar1);
        if (0 < iVar1) {
          *s = (uint)tbs;
        }
      }
      goto LAB_000b1c7a;
    }
  }
  ctx_00 = (EVP_PKEY_CTX *)0x0;
  uVar3 = 0;
LAB_000b1c7a:
  EVP_PKEY_CTX_free(ctx_00);
  return uVar3;
}

