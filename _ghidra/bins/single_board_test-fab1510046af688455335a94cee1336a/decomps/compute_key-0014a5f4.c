
int compute_key(uchar *param_1,BIGNUM *param_2,DH *param_3)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *r;
  uint extraout_r2;
  uint uVar2;
  BIGNUM *pBVar3;
  BN_MONT_CTX *m_ctx;
  bool bVar4;
  int local_24 [2];
  
  iVar1 = BN_num_bits(param_3->p);
  if (iVar1 < 0x2711) {
    ctx = BN_CTX_new();
    if (ctx != (BN_CTX *)0x0) {
      BN_CTX_start(ctx);
      r = BN_CTX_get(ctx);
      if (param_3->priv_key == (BIGNUM *)0x0) {
        ERR_put_error(5,0x66,100,"dh_key.c",0xe4);
        iVar1 = -1;
      }
      else {
        m_ctx = (BN_MONT_CTX *)(param_3->flags & 1);
        if (m_ctx != (BN_MONT_CTX *)0x0) {
          m_ctx = BN_MONT_CTX_set_locked(&param_3->method_mont_p,0x1a,param_3->p,ctx);
          pBVar3 = (BIGNUM *)(param_3->flags << 0x1e);
          bVar4 = -1 < (int)pBVar3;
          uVar2 = extraout_r2;
          if (bVar4) {
            pBVar3 = param_3->priv_key;
            uVar2 = pBVar3->flags | 4;
          }
          if (bVar4) {
            pBVar3->flags = uVar2;
          }
          if (m_ctx == (BN_MONT_CTX *)0x0) {
            iVar1 = -1;
            goto LAB_0014a670;
          }
        }
        iVar1 = DH_check_pub_key(param_3,param_2,local_24);
        if ((iVar1 == 0) || (local_24[0] != 0)) {
          ERR_put_error(5,0x66,0x66,"dh_key.c",0xf4);
          iVar1 = -1;
        }
        else {
          iVar1 = (*param_3->meth->bn_mod_exp)
                            (param_3,r,param_2,param_3->priv_key,param_3->p,ctx,m_ctx);
          if (iVar1 == 0) {
            ERR_put_error(5,0x66,3,"dh_key.c",0xfa);
            iVar1 = -1;
          }
          else {
            iVar1 = BN_bn2bin(r,param_1);
          }
        }
      }
LAB_0014a670:
      BN_CTX_end(ctx);
      BN_CTX_free(ctx);
      return iVar1;
    }
  }
  else {
    ERR_put_error(5,0x66,0x67,"dh_key.c",0xd9);
  }
  return -1;
}

