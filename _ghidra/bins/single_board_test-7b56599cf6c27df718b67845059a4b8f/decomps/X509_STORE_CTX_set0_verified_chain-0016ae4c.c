
void X509_STORE_CTX_set0_verified_chain
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  OPENSSL_sk_pop_free(*(undefined4 *)(param_1 + 0x50),0x16e591,0x744,&_GLOBAL_OFFSET_TABLE_,param_4)
  ;
  *(undefined4 *)(param_1 + 0x50) = param_2;
  return;
}

