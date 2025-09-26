
int EVP_add_cipher(EVP_CIPHER *cipher)

{
  char *pcVar1;
  int iVar2;
  
  if (cipher != (EVP_CIPHER *)0x0) {
    OPENSSL_init();
    pcVar1 = OBJ_nid2sn(cipher->nid);
    iVar2 = OBJ_NAME_add(pcVar1,2,(char *)cipher);
    if (iVar2 != 0) {
      check_defer(cipher->nid);
      pcVar1 = OBJ_nid2ln(cipher->nid);
      iVar2 = OBJ_NAME_add(pcVar1,2,(char *)cipher);
      return iVar2;
    }
  }
  return 0;
}

