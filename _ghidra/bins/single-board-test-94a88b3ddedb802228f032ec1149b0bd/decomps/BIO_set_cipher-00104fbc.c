
void BIO_set_cipher(BIO *b,EVP_CIPHER *c,uchar *k,uchar *i,int enc)

{
  long lVar1;
  
  if (b != (BIO *)0x0) {
    if ((b->callback != (_func_745 *)0x0) &&
       (lVar1 = (*b->callback)(b,6,(char *)c,4,enc,0), lVar1 < 1)) {
      return;
    }
    b->init = 1;
    EVP_CipherInit_ex((EVP_CIPHER_CTX *)((int)b->ptr + 0x14),c,(ENGINE *)0x0,k,i,enc);
    if (b->callback != (_func_745 *)0x0) {
      (*b->callback)(b,6,(char *)c,4,enc,1);
    }
  }
  return;
}

