
long BIO_callback_ctrl(BIO *b,int cmd,fp *fp)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  code *pcVar4;
  fp *local_14;
  
  if (b == (BIO *)0x0) {
    return 0;
  }
  local_14 = fp;
  if ((b->method == (BIO_METHOD *)0x0) ||
     (pcVar3 = (code *)b->method[1].name, cmd != 0xe || pcVar3 == (code *)0x0)) {
    ERR_put_error(0x20,0x83,0x79,"crypto/bio/bio_lib.c",0x222);
    return -2;
  }
  pcVar4 = (code *)b->cb_arg;
  if (b->callback == (_func_745 *)0x0) {
    if (pcVar4 != (code *)0x0) goto LAB_0010ac28;
  }
  else {
    if (pcVar4 == (code *)0x0) {
      iVar1 = (*b->callback)(b,6,(char *)&local_14,0xe,0,1);
    }
    else {
LAB_0010ac28:
      iVar1 = (*pcVar4)(b,6,&local_14,0,0xe,0,1,0);
    }
    if (iVar1 < 1) {
      return iVar1;
    }
    pcVar3 = (code *)b->method[1].name;
  }
  lVar2 = (*pcVar3)(b,0xe,local_14);
  pcVar3 = (code *)b->cb_arg;
  if (b->callback == (_func_745 *)0x0) {
    if (pcVar3 != (code *)0x0) goto LAB_0010ac44;
  }
  else {
    if (pcVar3 != (code *)0x0) {
LAB_0010ac44:
      lVar2 = (*pcVar3)(b,0x86,&local_14,0,0xe,0,lVar2,0);
      return lVar2;
    }
    lVar2 = (*b->callback)(b,0x86,(char *)&local_14,0xe,0,lVar2);
  }
  return lVar2;
}

