
int PKCS12_key_gen_asc(char *pass,int passlen,uchar *salt,int saltlen,int id,int iter,int n,
                      uchar *out,EVP_MD *md_type)

{
  uchar *puVar1;
  int iVar2;
  uchar *local_18;
  int local_14;
  
  if (pass == (char *)0x0) {
    local_18 = (uchar *)0x0;
    local_14 = 0;
  }
  else {
    puVar1 = OPENSSL_asc2uni(pass,passlen,&local_18,&local_14);
    if (puVar1 == (uchar *)0x0) {
      ERR_put_error(0x23,0x6e,0x41,"crypto/pkcs12/p12_key.c",0x2a);
      return 0;
    }
  }
  iVar2 = PKCS12_key_gen_uni(local_18,local_14,salt,saltlen,id,iter,n,out,md_type);
  if (iVar2 < 1) {
    iVar2 = 0;
  }
  else {
    CRYPTO_clear_free(local_18,local_14,"crypto/pkcs12/p12_key.c",0x31);
  }
  return iVar2;
}

