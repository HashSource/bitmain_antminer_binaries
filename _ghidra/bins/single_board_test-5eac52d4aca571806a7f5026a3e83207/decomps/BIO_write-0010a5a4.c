
int BIO_write(BIO *b,void *data,int len)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  BIO_METHOD *pBVar4;
  code *pcVar5;
  uint local_24 [2];
  
  if (len < 0) {
    return 0;
  }
  if (b == (BIO *)0x0) {
    return 0;
  }
  if ((b->method == (BIO_METHOD *)0x0) || (b->method->bwrite == (_func_737 *)0x0)) {
    ERR_put_error(0x20,0x80,0x79,"crypto/bio/bio_lib.c",0x149);
    return -2;
  }
  pcVar5 = (code *)b->cb_arg;
  if (b->callback == (_func_745 *)0x0) {
    if (pcVar5 != (code *)0x0) goto LAB_0010a5d4;
  }
  else {
    if (pcVar5 == (code *)0x0) {
      iVar1 = (*b->callback)(b,3,(char *)data,len,0,1);
    }
    else {
LAB_0010a5d4:
      iVar1 = (*pcVar5)(b,3,data,len,0,0,1,0);
    }
    if (iVar1 < 1) {
      return iVar1;
    }
  }
  if (b->shutdown == 0) {
    ERR_put_error(0x20,0x80,0x78,"crypto/bio/bio_lib.c",0x153);
    return -2;
  }
  uVar2 = (*b->method->bwrite)(b,(char *)data,len);
  if (0 < (int)uVar2) {
    pBVar4 = b[1].method;
    b[1].method = (BIO_METHOD *)((int)&pBVar4->type + local_24[0]);
    b[1].callback = b[1].callback + CARRY4((uint)pBVar4,local_24[0]);
  }
  pcVar5 = (code *)b->cb_arg;
  if (b->callback == (_func_745 *)0x0) {
    if (pcVar5 == (code *)0x0) goto LAB_0010a644;
  }
  else if (pcVar5 == (code *)0x0) {
    if ((0 < (int)uVar2) && (uVar2 = local_24[0], (int)local_24[0] < 0)) {
      return -1;
    }
    lVar3 = (*b->callback)(b,0x83,(char *)data,len,0,uVar2);
    return lVar3;
  }
  uVar2 = (*pcVar5)(b,0x83,data,len,0,0,uVar2,local_24);
LAB_0010a644:
  if (0 < (int)uVar2) {
    uVar2 = local_24[0];
  }
  return uVar2;
}

