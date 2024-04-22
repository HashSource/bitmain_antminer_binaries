
int CMS_RecipientInfo_kekri_id_cmp(CMS_RecipientInfo *ri,uchar *id,size_t idlen)

{
  int iVar1;
  ASN1_STRING local_20;
  
  if (*(int *)ri == 2) {
    local_20.type = 4;
    local_20.flags = 0;
    local_20.length = idlen;
    local_20.data = id;
    iVar1 = ASN1_OCTET_STRING_cmp(&local_20,**(ASN1_STRING ***)(*(int *)(ri + 4) + 4));
  }
  else {
    ERR_put_error(0x2e,0x8a,0x7b,DAT_000d599c,0x1f1);
    iVar1 = -2;
  }
  return iVar1;
}

