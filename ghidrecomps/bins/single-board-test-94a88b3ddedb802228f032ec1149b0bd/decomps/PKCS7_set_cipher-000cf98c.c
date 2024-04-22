
int PKCS7_set_cipher(PKCS7 *p7,EVP_CIPHER *cipher)

{
  int iVar1;
  pkcs7_st *ppVar2;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if (iVar1 == 0x17) {
    ppVar2 = (pkcs7_st *)((p7->d).sign)->cert;
    iVar1 = EVP_CIPHER_type(cipher);
  }
  else {
    if (iVar1 != 0x18) {
      ERR_put_error(0x21,0x6c,0x71,DAT_000cf9f4,0x24d);
      return 0;
    }
    ppVar2 = ((p7->d).sign)->contents;
    iVar1 = EVP_CIPHER_type(cipher);
  }
  if (iVar1 != 0) {
    ppVar2->detached = (int)cipher;
  }
  else {
    ERR_put_error(0x21,0x6c,0x90,DAT_000cf9f4,0x255);
  }
  return (uint)(iVar1 != 0);
}

