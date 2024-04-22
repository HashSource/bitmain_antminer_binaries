
int RSA_padding_check_PKCS1_OAEP(uchar *to,int tlen,uchar *f,int fl,int rsa_len,uchar *p,int pl)

{
  int iVar1;
  
  iVar1 = RSA_padding_check_PKCS1_OAEP_mgf1();
  return iVar1;
}

