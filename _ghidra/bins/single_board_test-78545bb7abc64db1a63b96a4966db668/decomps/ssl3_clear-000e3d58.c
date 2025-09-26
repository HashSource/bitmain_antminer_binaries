
int ssl3_clear(undefined4 *param_1)

{
  int iVar1;
  
  ssl3_cleanup_key_block();
  CRYPTO_free(*(void **)(param_1[0x1f] + 0x21c));
  OPENSSL_sk_pop_free(*(undefined4 *)(param_1[0x1f] + 0x224),0x177669);
  CRYPTO_free(*(void **)(param_1[0x1f] + 0x248));
  CRYPTO_clear_free(*(undefined4 *)(param_1[0x1f] + 0x250),*(undefined4 *)(param_1[0x1f] + 0x254),
                    "ssl/s3_lib.c",0xd16);
  CRYPTO_free(*(void **)(param_1[0x1f] + 0x268));
  CRYPTO_free(*(void **)(param_1[0x1f] + 0x26c));
  EVP_PKEY_free(*(EVP_PKEY **)(param_1[0x1f] + 0x214));
  EVP_PKEY_free(*(EVP_PKEY **)(param_1[0x1f] + 0x358));
  ssl3_free_digest_list(param_1);
  CRYPTO_free(*(void **)(param_1[0x1f] + 0x340));
  CRYPTO_free(*(void **)(param_1[0x1f] + 0x348));
  memset((void *)param_1[0x1f],0,0x35c);
  iVar1 = ssl_free_wbio_buffer(param_1);
  if (iVar1 != 0) {
    *param_1 = 0x300;
    CRYPTO_free((void *)param_1[0x167]);
    iVar1 = 1;
    param_1[0x167] = 0;
    param_1[0x168] = 0;
  }
  return iVar1;
}

