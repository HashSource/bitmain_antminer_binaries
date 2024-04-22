
int RSA_padding_add_X931(uchar *to,int tlen,uchar *f,int fl)

{
  int iVar1;
  uchar *puVar2;
  uchar *puVar3;
  
  iVar1 = tlen - fl;
  if (iVar1 + -2 < 0) {
    ERR_put_error(4,0x7f,0x6e,DAT_000fc514,0x51);
    iVar1 = -1;
  }
  else {
    if (iVar1 == 2) {
      puVar2 = to + 1;
      *to = 'j';
    }
    else {
      puVar2 = to + 1;
      *to = 'k';
      puVar3 = puVar2;
      if (iVar1 + -2 != 1) {
        puVar3 = puVar2 + (iVar1 - 3U);
        memset(puVar2,0xbb,iVar1 - 3U);
      }
      puVar2 = puVar3 + 1;
      *puVar3 = 0xba;
    }
    memcpy(puVar2,f,fl);
    iVar1 = 1;
    puVar2[fl] = 0xcc;
  }
  return iVar1;
}

