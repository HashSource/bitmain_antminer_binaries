
void dtls1_stop_timer(SSL *param_1)

{
  BIO *bp;
  EVP_CIPHER_CTX *pEVar1;
  
  pEVar1 = param_1->enc_read_ctx;
  pEVar1[2].cipher_data = (void *)0x0;
  pEVar1[2].final_used = 0;
  pEVar1[2].block_mask = 0;
  pEVar1 = param_1->enc_read_ctx;
  pEVar1[2].final[0] = '\0';
  pEVar1[2].final[1] = '\0';
  pEVar1[2].final[2] = '\0';
  pEVar1[2].final[3] = '\0';
  pEVar1[2].final[4] = '\0';
  pEVar1[2].final[5] = '\0';
  pEVar1[2].final[6] = '\0';
  pEVar1[2].final[7] = '\0';
  pEVar1 = param_1->enc_read_ctx;
  pEVar1[2].final[8] = '@';
  pEVar1[2].final[9] = 'B';
  pEVar1[2].final[10] = '\x0f';
  pEVar1[2].final[0xb] = '\0';
  bp = SSL_get_rbio(param_1);
  BIO_ctrl(bp,0x2d,0,param_1->enc_read_ctx[2].final);
  dtls1_clear_sent_buffer(param_1);
  return;
}

