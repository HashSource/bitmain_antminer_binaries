
void ssl3_free(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x7c) != 0)) {
    ssl3_cleanup_key_block();
    EVP_PKEY_free(*(EVP_PKEY **)(*(int *)(param_1 + 0x7c) + 0x358));
    iVar1 = *(int *)(param_1 + 0x7c);
    *(undefined4 *)(iVar1 + 0x358) = 0;
    EVP_PKEY_free(*(EVP_PKEY **)(iVar1 + 0x214));
    iVar1 = *(int *)(param_1 + 0x7c);
    *(undefined4 *)(iVar1 + 0x214) = 0;
    CRYPTO_free(*(void **)(iVar1 + 0x21c));
    OPENSSL_sk_pop_free(*(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x224),0x16da91,
                        *(int *)(param_1 + 0x7c),0x46c,param_4);
    CRYPTO_free(*(void **)(*(int *)(param_1 + 0x7c) + 0x248));
    CRYPTO_clear_free(*(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x250),
                      *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x254),"ssl/s3_lib.c",0xd02);
    CRYPTO_free(*(void **)(*(int *)(param_1 + 0x7c) + 0x268));
    CRYPTO_free(*(void **)(*(int *)(param_1 + 0x7c) + 0x26c));
    ssl3_free_digest_list(param_1);
    CRYPTO_free(*(void **)(*(int *)(param_1 + 0x7c) + 0x340));
    CRYPTO_free(*(void **)(*(int *)(param_1 + 0x7c) + 0x348));
    SSL_SRP_CTX_free(param_1);
    CRYPTO_clear_free(*(undefined4 *)(param_1 + 0x7c),0x35c,"ssl/s3_lib.c",0xd0c);
    *(undefined4 *)(param_1 + 0x7c) = 0;
  }
  return;
}

