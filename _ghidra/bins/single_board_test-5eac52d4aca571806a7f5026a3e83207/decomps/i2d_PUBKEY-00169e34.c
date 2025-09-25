
int i2d_PUBKEY(EVP_PKEY *a,uchar **pp)

{
  int iVar1;
  X509_PUBKEY *local_c;
  
  local_c = (X509_PUBKEY *)0x0;
  if (a != (EVP_PKEY *)0x0) {
    iVar1 = X509_PUBKEY_set(&local_c,a);
    if (iVar1 == 0) {
      a = (EVP_PKEY *)0xffffffff;
    }
    else {
      a = (EVP_PKEY *)i2d_X509_PUBKEY(local_c,pp);
      X509_PUBKEY_free(local_c);
    }
  }
  return (int)a;
}

