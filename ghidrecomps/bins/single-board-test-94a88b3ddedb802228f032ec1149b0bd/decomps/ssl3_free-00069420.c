
void ssl3_free(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    ssl3_cleanup_key_block();
    iVar1 = *(int *)(param_1 + 0x58);
    if (*(int *)(iVar1 + 0xec) != 0) {
      ssl3_release_read_buffer(param_1);
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(int *)(iVar1 + 0xfc) != 0) {
      ssl3_release_write_buffer(param_1);
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(void **)(iVar1 + 0x120) != (void *)0x0) {
      CRYPTO_free(*(void **)(iVar1 + 0x120));
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(DH **)(iVar1 + 0x348) != (DH *)0x0) {
      DH_free(*(DH **)(iVar1 + 0x348));
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(EC_KEY **)(iVar1 + 0x34c) != (EC_KEY *)0x0) {
      EC_KEY_free(*(EC_KEY **)(iVar1 + 0x34c));
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(_STACK **)(iVar1 + 0x36c) != (_STACK *)0x0) {
      sk_pop_free(*(_STACK **)(iVar1 + 0x36c),DAT_000694bc);
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(BIO **)(iVar1 + 0x178) != (BIO *)0x0) {
      BIO_free(*(BIO **)(iVar1 + 0x178));
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(int *)(iVar1 + 0x17c) != 0) {
      ssl3_free_digest_list(param_1);
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(void **)(iVar1 + 0x424) != (void *)0x0) {
      CRYPTO_free(*(void **)(iVar1 + 0x424));
    }
    SSL_SRP_CTX_free(param_1);
    OPENSSL_cleanse(*(void **)(param_1 + 0x58),0x42c);
    CRYPTO_free(*(void **)(param_1 + 0x58));
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  return;
}

