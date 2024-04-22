
int RSA_padding_check_none(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  if (tlen < fl) {
    ERR_put_error(4,0x6f,0x6d,DAT_000fbb6c,0x57);
    tlen = -1;
  }
  else {
    memset(to,0,tlen - fl);
    memcpy(to + (tlen - fl),f,fl);
  }
  return tlen;
}

