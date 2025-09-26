
undefined4 ssl3_init_finished_mac(int param_1)

{
  BIO_METHOD *type;
  BIO *bp;
  
  type = BIO_s_mem();
  bp = BIO_new(type);
  if (bp != (BIO *)0x0) {
    ssl3_free_digest_list(param_1);
    *(BIO **)(*(int *)(param_1 + 0x7c) + 0xd4) = bp;
    BIO_ctrl(bp,9,1,(void *)0x0);
    return 1;
  }
  ossl_statem_fatal(param_1,0x50,0x18d,0x41,"ssl/s3_enc.c",0x146);
  return 0;
}

