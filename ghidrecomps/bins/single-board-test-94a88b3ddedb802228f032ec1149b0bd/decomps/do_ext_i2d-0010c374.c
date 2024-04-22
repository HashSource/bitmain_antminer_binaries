
X509_EXTENSION * do_ext_i2d(int param_1,int param_2,int param_3,ASN1_VALUE *param_4)

{
  int num;
  ASN1_STRING *data;
  X509_EXTENSION *pXVar1;
  uchar *local_20;
  uchar *local_1c [2];
  
  if (*(ASN1_ITEM **)(param_1 + 8) == (ASN1_ITEM *)0x0) {
    num = (**(code **)(param_1 + 0x18))(param_4,0);
    local_20 = (uchar *)CRYPTO_malloc(num,DAT_0010c408,0xc1);
    if (local_20 == (uchar *)0x0) goto LAB_0010c3f2;
    local_1c[0] = local_20;
    (**(code **)(param_1 + 0x18))(param_4,local_1c);
  }
  else {
    local_20 = (uchar *)0x0;
    num = ASN1_item_i2d(param_4,&local_20,*(ASN1_ITEM **)(param_1 + 8));
    if (num < 0) goto LAB_0010c3f2;
  }
  data = ASN1_STRING_type_new(4);
  if (data != (ASN1_STRING *)0x0) {
    data->length = num;
    data->data = local_20;
    pXVar1 = X509_EXTENSION_create_by_NID((X509_EXTENSION **)0x0,param_2,param_3,data);
    if (pXVar1 != (X509_EXTENSION *)0x0) {
      ASN1_STRING_free(data);
      return pXVar1;
    }
  }
LAB_0010c3f2:
  ERR_put_error(0x22,0x87,0x41,DAT_0010c408,0xd3);
  return (X509_EXTENSION *)0x0;
}

