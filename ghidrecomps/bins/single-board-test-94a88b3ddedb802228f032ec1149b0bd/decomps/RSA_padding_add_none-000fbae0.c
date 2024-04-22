
int RSA_padding_add_none(uchar *to,int tlen,uchar *f,int fl)

{
  int iVar1;
  
  if (tlen < fl) {
    ERR_put_error(4,0x6b,0x6e,DAT_000fbb20,0x45);
    iVar1 = 0;
  }
  else if (fl < tlen) {
    ERR_put_error(4,0x6b,0x7a,DAT_000fbb20,0x4a);
    iVar1 = 0;
  }
  else {
    memcpy(to,f,fl);
    iVar1 = 1;
  }
  return iVar1;
}

