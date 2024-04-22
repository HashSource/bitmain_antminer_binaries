
int ASN1_item_i2d(ASN1_VALUE *val,uchar **out,ASN1_ITEM *it)

{
  int num;
  uchar *puVar1;
  ASN1_VALUE *local_20;
  uchar *local_1c;
  
  local_20 = val;
  if ((out == (uchar **)0x0) || (*out != (uchar *)0x0)) {
    num = ASN1_item_ex_i2d_constprop_1(&local_20,out,it,0);
  }
  else {
    num = ASN1_item_ex_i2d_constprop_0(&local_20,it,0);
    if (0 < num) {
      puVar1 = (uchar *)CRYPTO_malloc(num,DAT_000ba560,0x6d);
      if (puVar1 == (uchar *)0x0) {
        num = -1;
      }
      else {
        local_1c = puVar1;
        ASN1_item_ex_i2d_constprop_1(&local_20,&local_1c,it,0);
        *out = puVar1;
      }
    }
  }
  return num;
}

