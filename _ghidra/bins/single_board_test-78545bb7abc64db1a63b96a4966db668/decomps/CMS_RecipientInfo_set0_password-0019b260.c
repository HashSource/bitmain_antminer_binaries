
int CMS_RecipientInfo_set0_password(CMS_RecipientInfo *ri,uchar *pass,ssize_t passlen)

{
  uint uVar1;
  int iVar2;
  
  if (*(int *)ri == 3) {
    uVar1 = (uint)passlen >> 0x1f;
    iVar2 = *(int *)(ri + 4);
    if (pass == (uchar *)0x0) {
      uVar1 = 0;
    }
    *(uchar **)(iVar2 + 0x10) = pass;
    if (uVar1 != 0) {
      passlen = strlen((char *)pass);
    }
    *(ssize_t *)(iVar2 + 0x14) = passlen;
    return 1;
  }
  ERR_put_error(0x2e,0xa8,0xb1,"crypto/cms/cms_pwri.c",0x1a);
  return 0;
}

