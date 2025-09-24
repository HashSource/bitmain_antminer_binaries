
int EVP_MD_CTX_copy_ex(EVP_MD_CTX *out,EVP_MD_CTX *in)

{
  int iVar1;
  _func_1226 *__n;
  EVP_PKEY_CTX *pEVar2;
  EVP_MD *pEVar3;
  ENGINE *pEVar4;
  _func_1230 *p_Var5;
  _func_1223 *UNRECOVERED_JUMPTABLE;
  void *__dest;
  void *pvVar6;
  ulong uVar7;
  
  if ((in == (EVP_MD_CTX *)0x0) || (pEVar3 = in->digest, pEVar3 == (EVP_MD *)0x0)) {
    ERR_put_error(6,0x6e,0x6f,"crypto/evp/digest.c",0xe2);
    return 0;
  }
  if (in->engine != (ENGINE *)0x0) {
    iVar1 = ENGINE_init(in->engine);
    if (iVar1 == 0) {
      ERR_put_error(6,0x6e,0x26,"crypto/evp/digest.c",0xe8);
      return 0;
    }
    pEVar3 = in->digest;
  }
  if (out->digest == pEVar3) {
    __dest = out->md_data;
    EVP_MD_CTX_set_flags(out,4);
  }
  else {
    __dest = (void *)0x0;
  }
  EVP_MD_CTX_reset(out);
  pEVar4 = in->engine;
  uVar7 = in->flags;
  pvVar6 = in->md_data;
  out->digest = in->digest;
  out->engine = pEVar4;
  out->flags = uVar7;
  out->md_data = pvVar6;
  p_Var5 = in->update;
  out->pctx = in->pctx;
  out->update = p_Var5;
  EVP_MD_CTX_clear_flags(out,0x400);
  out->md_data = (void *)0x0;
  pvVar6 = in->md_data;
  out->pctx = (EVP_PKEY_CTX *)0x0;
  if ((pvVar6 != (void *)0x0) && (__n = out->digest->verify, __n != (_func_1226 *)0x0)) {
    if (__dest == (void *)0x0) {
      __dest = CRYPTO_malloc((int)__n,"crypto/evp/digest.c",0x103);
      out->md_data = __dest;
      if (__dest == (void *)0x0) {
        ERR_put_error(6,0x6e,0x41,"crypto/evp/digest.c",0x105);
        return 0;
      }
      __n = out->digest->verify;
    }
    else {
      out->md_data = __dest;
    }
    memcpy(__dest,in->md_data,(size_t)__n);
  }
  pEVar2 = in->pctx;
  out->update = in->update;
  if (pEVar2 != (EVP_PKEY_CTX *)0x0) {
    pEVar2 = EVP_PKEY_CTX_dup(pEVar2);
    out->pctx = pEVar2;
    if (pEVar2 == (EVP_PKEY_CTX *)0x0) {
      EVP_MD_CTX_reset(out);
      return 0;
    }
  }
  UNRECOVERED_JUMPTABLE = out->digest->copy;
  if (UNRECOVERED_JUMPTABLE != (_func_1223 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00129676. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(out,in);
    return iVar1;
  }
  return 1;
}

