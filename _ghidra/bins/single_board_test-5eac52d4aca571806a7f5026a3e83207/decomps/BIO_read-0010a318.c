
int BIO_read(BIO *b,void *data,int len)

{
  int iVar1;
  uint uVar2;
  stack_st_void *psVar3;
  code *pcVar4;
  uint local_24 [2];
  
  if (len < 0) {
    return 0;
  }
  if (((b == (BIO *)0x0) || (b->method == (BIO_METHOD *)0x0)) ||
     (b->method->bputs == (_func_739 *)0x0)) {
    ERR_put_error(0x20,0x78,0x79,"crypto/bio/bio_lib.c",0x100);
    return -2;
  }
  pcVar4 = (code *)b->cb_arg;
  if (b->callback == (_func_745 *)0x0) {
    if (pcVar4 != (code *)0x0) goto LAB_0010a348;
  }
  else {
    if (pcVar4 == (code *)0x0) {
      iVar1 = (*b->callback)(b,2,(char *)data,len,0,1);
    }
    else {
LAB_0010a348:
      iVar1 = (*pcVar4)(b,2,data,len,0,0,1,0);
    }
    if (iVar1 < 1) {
      return iVar1;
    }
  }
  if (b->shutdown == 0) {
    ERR_put_error(0x20,0x78,0x78,"crypto/bio/bio_lib.c",0x10a);
    return -2;
  }
  uVar2 = (*b->method->bputs)(b,(char *)data);
  if (0 < (int)uVar2) {
    psVar3 = (b->ex_data).sk;
    (b->ex_data).sk = (stack_st_void *)((int)&(psVar3->stack).num + local_24[0]);
    (b->ex_data).dummy = (b->ex_data).dummy + (uint)CARRY4((uint)psVar3,local_24[0]);
  }
  pcVar4 = (code *)b->cb_arg;
  if (b->callback == (_func_745 *)0x0) {
    if (pcVar4 == (code *)0x0) goto joined_r0x0010a3b4;
  }
  else if (pcVar4 == (code *)0x0) {
    if ((0 < (int)uVar2) && (uVar2 = local_24[0], (int)local_24[0] < 0)) {
      return -1;
    }
    uVar2 = (*b->callback)(b,0x82,(char *)data,len,0,uVar2);
    local_24[0] = uVar2;
    goto joined_r0x0010a3b4;
  }
  uVar2 = (*pcVar4)(b,0x82,data,len,0,0,uVar2,local_24);
joined_r0x0010a3b4:
  if ((0 < (int)uVar2) && (uVar2 = local_24[0], (uint)len < local_24[0])) {
    ERR_put_error(0x20,0x78,0x44,"crypto/bio/bio_lib.c",0x119);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

