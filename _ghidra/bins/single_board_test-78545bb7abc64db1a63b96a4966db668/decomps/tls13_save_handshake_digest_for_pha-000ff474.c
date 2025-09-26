
undefined4 tls13_save_handshake_digest_for_pha(int param_1)

{
  int iVar1;
  EVP_MD_CTX *out;
  
  if (*(int *)(param_1 + 0x608) == 0) {
    iVar1 = ssl3_digest_cached_records(param_1,1);
    if (iVar1 == 0) {
      return 0;
    }
    out = (EVP_MD_CTX *)EVP_MD_CTX_new();
    *(EVP_MD_CTX **)(param_1 + 0x608) = out;
    if (out == (EVP_MD_CTX *)0x0) {
      ossl_statem_fatal(param_1,0x50,0x26a,0x44,"ssl/statem/statem_lib.c",0x965);
      return 0;
    }
    iVar1 = EVP_MD_CTX_copy_ex(out,*(EVP_MD_CTX **)(*(int *)(param_1 + 0x7c) + 0xd8));
    if (iVar1 == 0) {
      ossl_statem_fatal(param_1,0x50,0x26a,0x44,"ssl/statem/statem_lib.c",0x96c);
      EVP_MD_CTX_free(*(undefined4 *)(param_1 + 0x608));
      *(undefined4 *)(param_1 + 0x608) = 0;
      return 0;
    }
  }
  return 1;
}

