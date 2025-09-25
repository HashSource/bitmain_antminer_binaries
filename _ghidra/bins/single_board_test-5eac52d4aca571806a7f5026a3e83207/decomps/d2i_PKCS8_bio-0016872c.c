
X509_SIG * d2i_PKCS8_bio(BIO *bp,X509_SIG **p8)

{
  X509_SIG *pXVar1;
  
  pXVar1 = (X509_SIG *)ASN1_d2i_bio((xnew *)0x182af1,(undefined1 *)0x182ac1,bp,p8);
  return pXVar1;
}

