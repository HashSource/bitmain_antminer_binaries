
undefined4 dtls1_query_mtu(SSL *param_1)

{
  ENGINE *pEVar1;
  uint uVar2;
  long lVar3;
  BIO *pBVar4;
  EVP_CIPHER_CTX *pEVar5;
  ENGINE *pEVar6;
  EVP_CIPHER *pEVar7;
  EVP_CIPHER_CTX *pEVar8;
  
  pEVar5 = param_1->enc_read_ctx;
  pEVar7 = pEVar5[2].cipher;
  if (pEVar7 != (EVP_CIPHER *)0x0) {
    pBVar4 = SSL_get_wbio(param_1);
    lVar3 = BIO_ctrl(pBVar4,0x31,0,(void *)0x0);
    pEVar5[2].engine = (ENGINE *)((int)pEVar7 - lVar3);
    pEVar5 = param_1->enc_read_ctx;
    pEVar5[2].cipher = (EVP_CIPHER *)0x0;
  }
  pEVar6 = pEVar5[2].engine;
  pEVar1 = (ENGINE *)dtls1_min_mtu(param_1);
  if (pEVar6 < pEVar1) {
    uVar2 = SSL_get_options(param_1);
    if ((uVar2 & 0x1000) != 0) {
      return 0;
    }
    pEVar8 = param_1->enc_read_ctx;
    pBVar4 = SSL_get_wbio(param_1);
    pEVar1 = (ENGINE *)BIO_ctrl(pBVar4,0x28,0,(void *)0x0);
    pEVar5 = param_1->enc_read_ctx;
    pEVar8[2].engine = pEVar1;
    pEVar6 = pEVar5[2].engine;
    pEVar1 = (ENGINE *)dtls1_min_mtu(param_1);
    if (pEVar6 < pEVar1) {
      pEVar5 = param_1->enc_read_ctx;
      pEVar1 = (ENGINE *)dtls1_min_mtu(param_1);
      pEVar5[2].engine = pEVar1;
      pBVar4 = SSL_get_wbio(param_1);
      BIO_ctrl(pBVar4,0x2a,(long)param_1->enc_read_ctx[2].engine,(void *)0x0);
    }
  }
  return 1;
}

