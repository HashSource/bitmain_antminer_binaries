
/* WARNING: Unknown calling convention */

void benchfile_dspwork(work *work,uint nonce)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char buf [1024];
  char tmp42 [2048];
  
  iVar1 = 4;
  iVar3 = 0;
  do {
    uVar2 = nonce & 0xff;
    iVar1 = iVar1 + -1;
    nonce = nonce >> 8;
    iVar3 = uVar2 + iVar3 * 0x100;
  } while (iVar1 != 0);
  __bin2hex(buf,work->data,0x80);
  if (((*DAT_0001e064 != '\0') || (*DAT_0001e068 != '\0')) || (2 < *DAT_0001e070)) {
    snprintf(tmp42,0x800,DAT_0001e06c,iVar3,iVar3,buf);
    _applog(3,tmp42,false);
  }
  return;
}

