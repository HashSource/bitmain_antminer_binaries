
int BIO_gets(BIO *bp,char *buf,int size)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  uint local_1c;
  
  local_1c = 0;
  if (((bp == (BIO *)0x0) || (bp->method == (BIO_METHOD *)0x0)) ||
     (bp->method->create == (_func_742 *)0x0)) {
    ERR_put_error(0x20,0x68,0x79,"crypto/bio/bio_lib.c",0x1b6);
    return -2;
  }
  if (size < 0) {
    ERR_put_error(0x20,0x68,0x7d,"crypto/bio/bio_lib.c",0x1bb);
    return 0;
  }
  pcVar4 = (code *)bp->cb_arg;
  if (bp->callback == (_func_745 *)0x0) {
    if (pcVar4 != (code *)0x0) goto LAB_0010a966;
  }
  else {
    if (pcVar4 == (code *)0x0) {
      iVar1 = (*bp->callback)(bp,5,buf,size,0,1);
    }
    else {
LAB_0010a966:
      iVar1 = (*pcVar4)(bp,5,buf,size,0,0,1,0);
    }
    if (iVar1 < 1) {
      return iVar1;
    }
  }
  if (bp->shutdown == 0) {
    ERR_put_error(0x20,0x68,0x78,"crypto/bio/bio_lib.c",0x1c6);
    return -2;
  }
  uVar2 = (*bp->method->create)(bp);
  uVar3 = uVar2;
  if (0 < (int)uVar2) {
    uVar3 = 1;
    local_1c = uVar2;
  }
  pcVar4 = (code *)bp->cb_arg;
  if (bp->callback == (_func_745 *)0x0) {
    if (pcVar4 == (code *)0x0) goto joined_r0x0010a9c0;
  }
  else if (pcVar4 == (code *)0x0) {
    if ((uVar3 == 1) && (uVar3 = local_1c, (int)local_1c < 0)) {
      return -1;
    }
    uVar3 = (*bp->callback)(bp,0x85,buf,size,0,uVar3);
    local_1c = uVar3;
    goto joined_r0x0010a9c0;
  }
  uVar3 = (*pcVar4)(bp,0x85,buf,size,0,0,uVar3,&local_1c);
joined_r0x0010a9c0:
  if ((0 < (int)uVar3) && (uVar3 = local_1c, (uint)size < local_1c)) {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

