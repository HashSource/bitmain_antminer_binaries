
int compute_key(uchar *param_1,BIGNUM *param_2,DH *param_3)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *mod;
  BIGNUM *pBVar2;
  BN_MONT_CTX *m_ctx;
  bool bVar3;
  int local_24 [2];
  
  iVar1 = BN_num_bits(param_3->p);
  if (iVar1 < 0x2711) {
    ctx = BN_CTX_new();
    if (ctx != (BN_CTX *)0x0) {
      BN_CTX_start(ctx);
      r = BN_CTX_get(ctx);
      if (param_3->priv_key == (BIGNUM *)0x0) {
        ERR_put_error(5,0x66,100,DAT_000a4c88,0xe4);
        iVar1 = -1;
      }
      else {
        m_ctx = (BN_MONT_CTX *)(param_3->flags & 1);
        if (m_ctx != (BN_MONT_CTX *)0x0) {
          mod = param_3->p;
          m_ctx = BN_MONT_CTX_set_locked(&param_3->method_mont_p,0x1a,mod,ctx);
          pBVar2 = (BIGNUM *)(param_3->flags << 0x1e);
          bVar3 = -1 < (int)pBVar2;
          if (bVar3) {
            pBVar2 = param_3->priv_key;
            mod = (BIGNUM *)(pBVar2->flags | 4);
          }
          if (bVar3) {
            pBVar2->flags = (int)mod;
          }
          if (m_ctx == (BN_MONT_CTX *)0x0) {
            iVar1 = -1;
            goto LAB_000a4bf0;
          }
        }
        iVar1 = DH_check_pub_key(param_3,param_2,local_24);
        if ((iVar1 == 0) || (local_24[0] != 0)) {
          ERR_put_error(5,0x66,0x66,DAT_000a4c88,0xf4);
          iVar1 = -1;
        }
        else {
          iVar1 = (*param_3->meth->bn_mod_exp)
                            (param_3,r,param_2,param_3->priv_key,param_3->p,ctx,m_ctx);
          if (iVar1 == 0) {
            ERR_put_error(5,0x66,3,DAT_000a4c88,0xfa);
            iVar1 = -1;
          }
          else {
            iVar1 = BN_bn2bin(r,param_1);
          }
        }
      }
LAB_000a4bf0:
      BN_CTX_end(ctx);
      BN_CTX_free(ctx);
      return iVar1;
    }
  }
  else {
    ERR_put_error(5,0x66,0x67,DAT_000a4c88,0xd9);
  }
  return -1;
}

