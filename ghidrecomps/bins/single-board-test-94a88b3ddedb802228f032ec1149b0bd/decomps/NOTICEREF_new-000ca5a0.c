
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

NOTICEREF * NOTICEREF_new(void)

{
  NOTICEREF *pNVar1;
  
  pNVar1 = (NOTICEREF *)ASN1_item_new((ASN1_ITEM *)NOTICEREF_it);
  return pNVar1;
}

