
int BIO_puts(BIO *bp,char *buf)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  long in_r2;
  long extraout_r2;
  long extraout_r2_00;
  BIO_METHOD *pBVar4;
  _func_741 *p_Var5;
  code *pcVar6;
  uint local_1c [2];
  
  local_1c[0] = 0;
  if (((bp == (BIO *)0x0) || (bp->method == (BIO_METHOD *)0x0)) ||
     (bp->method->ctrl == (_func_741 *)0x0)) {
    ERR_put_error(0x20,0x6e,0x79,"crypto/bio/bio_lib.c",0x189);
    return -2;
  }
  pcVar6 = (code *)bp->cb_arg;
  if (bp->callback == (_func_745 *)0x0) {
    if (pcVar6 != (code *)0x0) goto LAB_0010a844;
  }
  else {
    if (pcVar6 == (code *)0x0) {
      iVar1 = (*bp->callback)(bp,4,buf,0,0,1);
      in_r2 = extraout_r2;
    }
    else {
LAB_0010a844:
      iVar1 = (*pcVar6)(bp,4,buf,0,0,0,1,0);
      in_r2 = extraout_r2_00;
    }
    if (iVar1 < 1) {
      return iVar1;
    }
  }
  if (bp->shutdown == 0) {
    ERR_put_error(0x20,0x6e,0x78,"crypto/bio/bio_lib.c",0x194);
    return -2;
  }
  p_Var5 = bp->method->ctrl;
  uVar2 = (*p_Var5)(bp,(int)buf,in_r2,p_Var5);
  uVar3 = uVar2;
  if (0 < (int)uVar2) {
    pBVar4 = bp[1].method;
    uVar3 = 1;
    bp[1].method = (BIO_METHOD *)((int)&pBVar4->type + uVar2);
    bp[1].callback = bp[1].callback + ((int)uVar2 >> 0x1f) + (uint)CARRY4((uint)pBVar4,uVar2);
    local_1c[0] = uVar2;
  }
  pcVar6 = (code *)bp->cb_arg;
  if (bp->callback == (_func_745 *)0x0) {
    if (pcVar6 == (code *)0x0) goto joined_r0x0010a8c8;
  }
  else if (pcVar6 == (code *)0x0) {
    if ((uVar3 == 1) && (uVar3 = local_1c[0], (int)local_1c[0] < 0)) {
      return -1;
    }
    uVar3 = (*bp->callback)(bp,0x84,buf,0,0,uVar3);
    local_1c[0] = uVar3;
    goto joined_r0x0010a8c8;
  }
  uVar3 = (*pcVar6)(bp,0x84,buf,0,0,0,uVar3,local_1c);
joined_r0x0010a8c8:
  if ((0 < (int)uVar3) && (uVar3 = local_1c[0], (int)local_1c[0] < 0)) {
    ERR_put_error(0x20,0x6e,0x66,"crypto/bio/bio_lib.c",0x1a6);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

