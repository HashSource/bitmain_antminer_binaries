
int CMS_RecipientInfo_set0_key(CMS_RecipientInfo *ri,uchar *key,size_t keylen)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)ri;
  if (iVar1 != 2) {
    ERR_put_error(0x2e,0x90,0x7b,DAT_000d5b9c,0x29b);
  }
  else {
    iVar2 = *(int *)(ri + 4);
    *(uchar **)(iVar2 + 0x10) = key;
    *(size_t *)(iVar2 + 0x14) = keylen;
  }
  return (uint)(iVar1 == 2);
}

