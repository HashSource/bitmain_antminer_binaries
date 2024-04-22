
int SSL_CTX_set_ssl_version(SSL_CTX *ctx,SSL_METHOD *meth)

{
  undefined4 uVar1;
  _STACK *p_Var2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = DAT_00079e78;
  uVar3 = DAT_00079e74;
  iVar4 = meth->version;
  ctx->method = meth;
  if (iVar4 == 2) {
    uVar3 = uVar1;
  }
  p_Var2 = (_STACK *)
           ssl_create_cipher_list(meth,&ctx->cipher_list,&ctx->cipher_list_by_id,uVar3,ctx->cert);
  if ((p_Var2 == (_STACK *)0x0) || (iVar4 = sk_num(p_Var2), iVar4 < 1)) {
    ERR_put_error(0x14,0xaa,0xe6,DAT_00079e7c,0x117);
    iVar4 = 0;
  }
  else {
    iVar4 = 1;
  }
  return iVar4;
}

