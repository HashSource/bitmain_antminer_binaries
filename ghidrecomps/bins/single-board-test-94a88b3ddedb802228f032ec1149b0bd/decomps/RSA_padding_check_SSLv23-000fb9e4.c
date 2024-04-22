
int RSA_padding_check_SSLv23(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  int iVar1;
  int iVar2;
  int iVar3;
  size_t __n;
  uchar *puVar4;
  bool bVar5;
  
  if (fl < 10) {
    ERR_put_error(4,0x72,0x6f,DAT_000fbadc,0x70);
  }
  else if ((fl + 1 == rsa_len) && (*f == '\x02')) {
    iVar2 = fl + -1;
    iVar3 = 0;
    puVar4 = f + 1;
    do {
      if (*puVar4 == '\0') {
        bVar5 = SBORROW4(iVar3,iVar2);
        iVar1 = iVar3 - iVar2;
        if (iVar3 != iVar2) {
          bVar5 = SBORROW4(iVar3,7);
          iVar1 = iVar3 + -7;
        }
        if ((iVar3 != iVar2 && iVar3 != 7) && iVar1 < 0 == bVar5) {
          if (((((puVar4[-8] == '\x03') && (puVar4[-7] == '\x03')) && (puVar4[-6] == '\x03')) &&
              ((puVar4[-5] == '\x03' && (puVar4[-4] == '\x03')))) &&
             ((puVar4[-3] == '\x03' && ((puVar4[-2] == '\x03' && (puVar4[-1] == '\x03')))))) {
            ERR_put_error(4,0x72,0x73,DAT_000fbadc,0x88);
            return -1;
          }
          __n = iVar2 - (iVar3 + 1);
          if ((int)__n <= tlen) {
            memcpy(to,puVar4 + 1,__n);
            return __n;
          }
          ERR_put_error(4,0x72,0x6d,DAT_000fbadc,0x8f);
          return -1;
        }
        break;
      }
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar2 != iVar3);
    ERR_put_error(4,0x72,0x71,DAT_000fbadc,0x80);
  }
  else {
    ERR_put_error(4,0x72,0x6b,DAT_000fbadc,0x74);
  }
  return -1;
}

