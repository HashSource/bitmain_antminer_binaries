
undefined4 dtls1_check_timeout_num(SSL *param_1)

{
  undefined4 uVar1;
  BIO *bp;
  ENGINE *pEVar2;
  EVP_CIPHER_CTX *pEVar3;
  uint uVar4;
  
  uVar4 = param_1->enc_read_ctx[2].block_mask + 1;
  param_1->enc_read_ctx[2].block_mask = uVar4;
  if (uVar4 < 3) {
    return 0;
  }
  uVar4 = SSL_get_options();
  if ((uVar4 & 0x1000) == 0) {
    bp = SSL_get_wbio(param_1);
    pEVar2 = (ENGINE *)BIO_ctrl(bp,0x2f,0,(void *)0x0);
    pEVar3 = param_1->enc_read_ctx;
    uVar4 = pEVar3[2].block_mask;
    if (pEVar2 < pEVar3[2].engine) {
      pEVar3[2].engine = pEVar2;
    }
  }
  else {
    uVar4 = param_1->enc_read_ctx[2].block_mask;
  }
  if (uVar4 < 0xd) {
    uVar1 = 0;
  }
  else {
    ossl_statem_fatal(param_1,0xffffffff,0x13e,0x138,"ssl/d1_lib.c",0x17e);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

