
int CMS_RecipientInfo_set0_password(CMS_RecipientInfo *ri,uchar *pass,ssize_t passlen)

{
  int iVar1;
  uchar *puVar2;
  int iVar3;
  
  if (*(int *)ri == 3) {
    iVar3 = *(int *)(ri + 4);
    puVar2 = pass;
    if (pass != (uchar *)0x0) {
      puVar2 = (uchar *)0x1;
    }
    *(uchar **)(iVar3 + 0x10) = pass;
    if (((uint)puVar2 & (uint)passlen >> 0x1f) != 0) {
      passlen = strlen((char *)pass);
    }
    iVar1 = 1;
    *(ssize_t *)(iVar3 + 0x14) = passlen;
  }
  else {
    ERR_put_error(0x2e,0xa8,0xb1,DAT_000d641c,0x47);
    iVar1 = 0;
  }
  return iVar1;
}

