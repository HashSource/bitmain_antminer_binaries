
undefined4 tls13_restore_handshake_digest_for_pha(int param_1)

{
  int iVar1;
  
  if (*(EVP_MD_CTX **)(param_1 + 0x608) == (EVP_MD_CTX *)0x0) {
    ossl_statem_fatal(param_1,0x50,0x269,0x44,"ssl/statem/statem_lib.c",0x97e);
    return 0;
  }
  iVar1 = EVP_MD_CTX_copy_ex(*(EVP_MD_CTX **)(*(int *)(param_1 + 0x7c) + 0xd8),
                             *(EVP_MD_CTX **)(param_1 + 0x608));
  if (iVar1 != 0) {
    return 1;
  }
  ossl_statem_fatal(param_1,0x50,0x269,0x44,"ssl/statem/statem_lib.c",0x985);
  return 0;
}

