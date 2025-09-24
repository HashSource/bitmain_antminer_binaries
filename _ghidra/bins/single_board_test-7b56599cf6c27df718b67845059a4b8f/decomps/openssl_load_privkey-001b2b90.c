
EVP_PKEY *
openssl_load_privkey(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  BIO *bp;
  EVP_PKEY *pEVar1;
  
  fprintf(stderr,"(TEST_ENG_OPENSSL_PKEY)Loading Private key %s\n",param_2,&stderr,param_4);
  bp = BIO_new_file(param_2,"r");
  if (bp != (BIO *)0x0) {
    pEVar1 = PEM_read_bio_PrivateKey(bp,(EVP_PKEY **)0x0,(undefined1 *)0x0,(void *)0x0);
    BIO_free(bp);
    return pEVar1;
  }
  return (EVP_PKEY *)0x0;
}

