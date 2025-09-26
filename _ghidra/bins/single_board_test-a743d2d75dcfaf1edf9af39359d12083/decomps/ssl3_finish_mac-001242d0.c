
void ssl3_finish_mac(int param_1,void *param_2,size_t param_3)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_1 + 0x58);
  if (((BIO *)puVar1[0x5e] != (BIO *)0x0) && ((*puVar1 & 0x20) == 0)) {
    BIO_write((BIO *)puVar1[0x5e],param_2,param_3);
    return;
  }
  if (*(EVP_MD_CTX **)puVar1[0x5f] != (EVP_MD_CTX *)0x0) {
    EVP_DigestUpdate(*(EVP_MD_CTX **)puVar1[0x5f],param_2,param_3);
    puVar1 = *(uint **)(param_1 + 0x58);
  }
  if (*(EVP_MD_CTX **)(puVar1[0x5f] + 4) != (EVP_MD_CTX *)0x0) {
    EVP_DigestUpdate(*(EVP_MD_CTX **)(puVar1[0x5f] + 4),param_2,param_3);
    puVar1 = *(uint **)(param_1 + 0x58);
  }
  if (*(EVP_MD_CTX **)(puVar1[0x5f] + 8) != (EVP_MD_CTX *)0x0) {
    EVP_DigestUpdate(*(EVP_MD_CTX **)(puVar1[0x5f] + 8),param_2,param_3);
    puVar1 = *(uint **)(param_1 + 0x58);
  }
  if (*(EVP_MD_CTX **)(puVar1[0x5f] + 0xc) != (EVP_MD_CTX *)0x0) {
    EVP_DigestUpdate(*(EVP_MD_CTX **)(puVar1[0x5f] + 0xc),param_2,param_3);
    puVar1 = *(uint **)(param_1 + 0x58);
  }
  if (*(EVP_MD_CTX **)(puVar1[0x5f] + 0x10) != (EVP_MD_CTX *)0x0) {
    EVP_DigestUpdate(*(EVP_MD_CTX **)(puVar1[0x5f] + 0x10),param_2,param_3);
    puVar1 = *(uint **)(param_1 + 0x58);
  }
  if (*(EVP_MD_CTX **)(puVar1[0x5f] + 0x14) != (EVP_MD_CTX *)0x0) {
    EVP_DigestUpdate(*(EVP_MD_CTX **)(puVar1[0x5f] + 0x14),param_2,param_3);
    return;
  }
  return;
}

