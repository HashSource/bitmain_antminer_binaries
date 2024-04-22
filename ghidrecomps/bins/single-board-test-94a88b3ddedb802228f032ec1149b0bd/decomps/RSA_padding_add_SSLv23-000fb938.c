
int RSA_padding_add_SSLv23(uchar *to,int tlen,uchar *f,int fl)

{
  int iVar1;
  uchar *buf;
  uchar *buf_00;
  int num;
  uchar *puVar2;
  
  if (fl < tlen + -10) {
    buf_00 = to + 2;
    num = (tlen + -0xb) - fl;
    *to = '\0';
    to[1] = '\x02';
    iVar1 = RAND_bytes(buf_00,num);
    if (iVar1 < 1) {
LAB_000fb9a4:
      iVar1 = 0;
    }
    else {
      if (0 < num) {
        puVar2 = buf_00 + num;
        buf = buf_00;
        do {
          buf_00 = buf + 1;
          if (*buf == '\0') {
            iVar1 = RAND_bytes(buf,1);
            while( true ) {
              if (iVar1 < 1) goto LAB_000fb9a4;
              if (*buf != '\0') break;
              iVar1 = RAND_bytes(buf,1);
            }
          }
          buf = buf_00;
        } while (buf_00 != puVar2);
      }
      memset(buf_00,3,8);
      buf_00[8] = '\0';
      memcpy(buf_00 + 9,f,fl);
      iVar1 = 1;
    }
  }
  else {
    ERR_put_error(4,0x6e,0x6e,DAT_000fb9e0,0x49);
    iVar1 = 0;
  }
  return iVar1;
}

