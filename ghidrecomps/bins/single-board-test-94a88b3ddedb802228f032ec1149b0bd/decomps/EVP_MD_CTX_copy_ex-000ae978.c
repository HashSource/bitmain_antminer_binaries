
int EVP_MD_CTX_copy_ex(EVP_MD_CTX *out,EVP_MD_CTX *in)

{
  int iVar1;
  ulong uVar2;
  void *pvVar3;
  EVP_PKEY_CTX *pEVar4;
  size_t __n;
  EVP_MD *pEVar5;
  ENGINE *pEVar6;
  _func_1223 *p_Var7;
  void *__dest;
  
  if ((in == (EVP_MD_CTX *)0x0) || (pEVar5 = in->digest, pEVar5 == (EVP_MD *)0x0)) {
    ERR_put_error(6,0x6e,0x6f,DAT_000aea70,300);
    iVar1 = 0;
  }
  else {
    if (in->engine != (ENGINE *)0x0) {
      iVar1 = ENGINE_init(in->engine);
      if (iVar1 == 0) {
        ERR_put_error(6,0x6e,0x26,DAT_000aea70,0x132);
        return 0;
      }
      pEVar5 = in->digest;
    }
    if (out->digest == pEVar5) {
      __dest = out->md_data;
      EVP_MD_CTX_set_flags(out,4);
    }
    else {
      __dest = (void *)0x0;
    }
    EVP_MD_CTX_cleanup(out);
    pEVar6 = in->engine;
    uVar2 = in->flags;
    pvVar3 = in->md_data;
    out->digest = in->digest;
    out->engine = pEVar6;
    out->flags = uVar2;
    out->md_data = pvVar3;
    pEVar4 = in->pctx;
    out->update = in->update;
    out->pctx = pEVar4;
    if ((in->md_data != (void *)0x0) && (__n = out->digest->ctx_size, __n != 0)) {
      if (__dest == (void *)0x0) {
        __dest = CRYPTO_malloc(__n,DAT_000aea70,0x143);
        out->md_data = __dest;
        if (__dest == (void *)0x0) {
          ERR_put_error(6,0x6e,0x41,DAT_000aea70,0x145);
          return 0;
        }
        __n = out->digest->ctx_size;
      }
      else {
        out->md_data = __dest;
      }
      memcpy(__dest,in->md_data,__n);
    }
    pEVar4 = in->pctx;
    out->update = in->update;
    if (pEVar4 != (EVP_PKEY_CTX *)0x0) {
      pEVar4 = EVP_PKEY_CTX_dup(pEVar4);
      out->pctx = pEVar4;
      if (pEVar4 == (EVP_PKEY_CTX *)0x0) {
        EVP_MD_CTX_cleanup(out);
        return 0;
      }
    }
    iVar1 = 1;
    p_Var7 = out->digest->copy;
    if (p_Var7 != (_func_1223 *)0x0) {
      iVar1 = (*p_Var7)(out,in);
    }
  }
  return iVar1;
}

