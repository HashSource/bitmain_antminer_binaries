
X509_SIG * d2i_PKCS8_fp(FILE *fp,X509_SIG **p8)

{
  X509_SIG *pXVar1;
  
  pXVar1 = (X509_SIG *)ASN1_d2i_fp((xnew *)0x186d41,(undefined1 *)0x186d11,fp,p8);
  return pXVar1;
}

