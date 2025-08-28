
int EVP_SignFinal(EVP_MD_CTX *ctx,uchar *md,uint *s,EVP_PKEY *pkey)

{
  uint uVar1;
  int iVar2;
  EVP_MD *pEVar3;
  uint extraout_r3;
  uint uVar4;
  EVP_PKEY_CTX *ctx_00;
  uint local_78;
  uint local_74;
  EVP_MD_CTX EStack_70;
  uchar auStack_58 [64];
  
  uVar4 = 0;
  *s = 0;
  EVP_MD_CTX_init(&EStack_70);
  iVar2 = EVP_MD_CTX_copy_ex(&EStack_70,ctx);
  if ((iVar2 != 0) && (iVar2 = EVP_DigestFinal_ex(&EStack_70,auStack_58,&local_78), iVar2 != 0)) {
    EVP_MD_CTX_cleanup(&EStack_70);
    pEVar3 = ctx->digest;
    if (-1 < (int)(pEVar3->flags << 0x1d)) {
      if ((pEVar3->required_pkey_type[0] != 0) &&
         ((iVar2 = pkey->type, iVar2 == pEVar3->required_pkey_type[0] ||
          ((pEVar3->required_pkey_type[1] != 0 &&
           ((iVar2 == pEVar3->required_pkey_type[1] ||
            ((pEVar3->required_pkey_type[2] != 0 &&
             ((iVar2 == pEVar3->required_pkey_type[2] ||
              ((pEVar3->required_pkey_type[3] != 0 && (pEVar3->required_pkey_type[3] == iVar2)))))))
            ))))))) {
        if (pEVar3->sign != (_func_1225 *)0x0) {
          iVar2 = (*pEVar3->sign)(pEVar3->type,auStack_58,local_78,md,s,(pkey->pkey).ptr);
          return iVar2;
        }
        ERR_put_error(6,0x6b,0x68,"p_sign.c",0x80);
        return 0;
      }
      ERR_put_error(6,0x6b,0x6e,"p_sign.c",0x7b);
      return 0;
    }
    local_74 = EVP_PKEY_size(pkey);
    ctx_00 = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
    if (ctx_00 != (EVP_PKEY_CTX *)0x0) {
      iVar2 = EVP_PKEY_sign_init(ctx_00);
      if ((0 < iVar2) && (iVar2 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,1,0,ctx->digest), 0 < iVar2)) {
        iVar2 = EVP_PKEY_sign(ctx_00,md,&local_74,auStack_58,local_78);
        uVar1 = extraout_r3;
        if (0 < iVar2) {
          uVar1 = local_74;
        }
        uVar4 = (uint)(0 < iVar2);
        if (0 < iVar2) {
          *s = uVar1;
        }
      }
      goto LAB_000b1c7a;
    }
  }
  ctx_00 = (EVP_PKEY_CTX *)0x0;
  uVar4 = 0;
LAB_000b1c7a:
  EVP_PKEY_CTX_free(ctx_00);
  return uVar4;
}

