
void ssl3_init_finished_mac(int param_1)

{
  BIO_METHOD *type;
  BIO *pBVar1;
  EVP_MD_CTX **ptr;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x58);
  if (*(BIO **)(iVar3 + 0x178) != (BIO *)0x0) {
    BIO_free(*(BIO **)(iVar3 + 0x178));
    iVar3 = *(int *)(param_1 + 0x58);
  }
  ptr = *(EVP_MD_CTX ***)(iVar3 + 0x17c);
  if (ptr != (EVP_MD_CTX **)0x0) {
    if (*ptr != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(*ptr);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if (ptr[1] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ptr[1]);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if (ptr[2] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ptr[2]);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if (ptr[3] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ptr[3]);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if (ptr[4] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ptr[4]);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if (ptr[5] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ptr[5]);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    CRYPTO_free(ptr);
    iVar3 = *(int *)(param_1 + 0x58);
    *(undefined4 *)(iVar3 + 0x17c) = 0;
  }
  type = BIO_s_mem();
  pBVar1 = BIO_new(type);
  iVar2 = *(int *)(param_1 + 0x58);
  *(BIO **)(iVar3 + 0x178) = pBVar1;
  BIO_ctrl(*(BIO **)(iVar2 + 0x178),9,1,(void *)0x0);
  return;
}

