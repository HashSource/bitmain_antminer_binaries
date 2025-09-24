
int RSA_padding_add_X931(uchar *to,int tlen,uchar *f,int fl)

{
  void *pvVar1;
  int iVar2;
  uchar *puVar3;
  uchar *puVar4;
  
  iVar2 = tlen - fl;
  if (iVar2 + -2 < 0) {
    ERR_put_error(4,0x7f,0x6e,"crypto/rsa/rsa_x931.c",0x1e);
    iVar2 = -1;
  }
  else {
    if (iVar2 == 2) {
      puVar3 = to + 1;
      *to = 'j';
    }
    else {
      puVar3 = to + 1;
      *to = 'k';
      puVar4 = puVar3;
      if (iVar2 + -2 != 1) {
        puVar4 = puVar3 + (iVar2 - 3U);
        memset(puVar3,0xbb,iVar2 - 3U);
      }
      puVar3 = puVar4 + 1;
      *puVar4 = 0xba;
    }
    pvVar1 = memcpy(puVar3,f,fl);
    iVar2 = 1;
    *(undefined1 *)((int)pvVar1 + fl) = 0xcc;
  }
  return iVar2;
}

