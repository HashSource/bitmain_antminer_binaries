
void BIO_set_cipher(BIO *b,EVP_CIPHER *c,uchar *k,uchar *i,int enc)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  char *extraout_r2;
  int extraout_r3;
  undefined8 uVar4;
  long in_stack_ffffffd0;
  long in_stack_ffffffd4;
  
  uVar4 = BIO_get_data();
  iVar3 = (int)uVar4;
  if (iVar3 != 0) {
    pcVar1 = (code *)BIO_get_callback(b,(int)((ulonglong)uVar4 >> 0x20),extraout_r2,extraout_r3,
                                      in_stack_ffffffd0,in_stack_ffffffd4);
    if (pcVar1 == (code *)0x0) {
      BIO_set_init(b,1);
      EVP_CipherInit_ex(*(EVP_CIPHER_CTX **)(iVar3 + 0x14),c,(ENGINE *)0x0,k,i,enc);
    }
    else {
      iVar2 = (*pcVar1)(b,6,c,4,enc,0);
      if (0 < iVar2) {
        BIO_set_init(b,1);
        iVar3 = EVP_CipherInit_ex(*(EVP_CIPHER_CTX **)(iVar3 + 0x14),c,(ENGINE *)0x0,k,i,enc);
        if (iVar3 != 0) {
          (*pcVar1)(b,6,c,4,enc,1);
          return;
        }
      }
    }
  }
  return;
}

