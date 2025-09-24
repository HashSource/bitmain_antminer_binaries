
int RSA_padding_add_SSLv23(uchar *to,int tlen,uchar *f,int fl)

{
  int iVar1;
  uchar *buf;
  int num;
  uchar *puVar2;
  
  if (tlen + -10 <= fl) {
    ERR_put_error(4,0x6e,0x6e,"crypto/rsa/rsa_ssl.c",0x19);
    return 0;
  }
  num = (tlen + -0xb) - fl;
  buf = to + 2;
  *to = '\0';
  to[1] = '\x02';
  iVar1 = RAND_bytes(buf,num);
  if (iVar1 < 1) {
LAB_00153662:
    iVar1 = 0;
  }
  else {
    puVar2 = buf;
    if (0 < num) {
      puVar2 = buf + num;
      do {
        while (*buf == '\0') {
          iVar1 = RAND_bytes(buf,1);
          if (iVar1 < 1) goto LAB_00153662;
        }
        buf = buf + 1;
      } while (buf != puVar2);
    }
    builtin_memcpy(puVar2,"\x03\x03\x03\x03\x03\x03\x03\x03",9);
    memcpy(puVar2 + 9,f,fl);
    iVar1 = 1;
  }
  return iVar1;
}

