
void SSL_CTX_set0_CA_list(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  OPENSSL_sk_pop_free(*(undefined4 *)(param_1 + 0xa4),0x16da91,0x46c,&_GLOBAL_OFFSET_TABLE_,param_4)
  ;
  *(undefined4 *)(param_1 + 0xa4) = param_2;
  return;
}

