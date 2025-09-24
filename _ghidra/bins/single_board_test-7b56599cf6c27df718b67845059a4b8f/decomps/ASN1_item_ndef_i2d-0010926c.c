
int ASN1_item_ndef_i2d(ASN1_VALUE *val,uchar **out,ASN1_ITEM *it)

{
  int num;
  uchar *puVar1;
  ASN1_VALUE *local_28;
  uchar *local_24;
  
  local_28 = val;
  if ((out == (uchar **)0x0) || (*out != (uchar *)0x0)) {
    num = ASN1_item_ex_i2d(&local_28,out,it,-1,0x800);
  }
  else {
    num = ASN1_item_ex_i2d(&local_28,(uchar **)0x0,it,-1,0x800);
    if (0 < num) {
      puVar1 = (uchar *)CRYPTO_malloc(num,"crypto/asn1/tasn_enc.c",0x40);
      if (puVar1 == (uchar *)0x0) {
        ERR_put_error(0xd,0x76,0x41,"crypto/asn1/tasn_enc.c",0x41);
        num = -1;
      }
      else {
        local_24 = puVar1;
        ASN1_item_ex_i2d(&local_28,&local_24,it,-1,0x800);
        *out = puVar1;
      }
    }
  }
  return num;
}

