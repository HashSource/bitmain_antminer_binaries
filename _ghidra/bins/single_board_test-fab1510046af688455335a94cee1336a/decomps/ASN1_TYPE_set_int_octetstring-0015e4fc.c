
int ASN1_TYPE_set_int_octetstring(ASN1_TYPE *a,long num,uchar *data,int len)

{
  int iVar1;
  int iVar2;
  int len_00;
  ASN1_STRING *str;
  int iVar3;
  uchar *local_64;
  ASN1_STRING local_60;
  ASN1_INTEGER local_50;
  uchar auStack_40 [32];
  
  local_50.data = auStack_40;
  local_50.length = 0x20;
  local_60.type = 4;
  local_60.length = len;
  local_60.data = data;
  ASN1_INTEGER_set(&local_50,num);
  iVar1 = i2d_ASN1_INTEGER(&local_50,(uchar **)0x0);
  iVar2 = i2d_ASN1_bytes(&local_60,(uchar **)0x0,4,0);
  len_00 = ASN1_object_size(1,iVar2 + iVar1,0x10);
  str = ASN1_STRING_new();
  if (str != (ASN1_STRING *)0x0) {
    iVar3 = ASN1_STRING_set(str,(void *)0x0,len_00);
    if (iVar3 == 0) {
      ASN1_STRING_free(str);
      str = (ASN1_STRING *)0x0;
    }
    else {
      local_64 = str->data;
      str->length = len_00;
      ASN1_put_object(&local_64,1,iVar2 + iVar1,0x10,0);
      i2d_ASN1_INTEGER(&local_50,&local_64);
      i2d_ASN1_bytes(&local_60,&local_64,4,0);
      ASN1_TYPE_set(a,0x10,str);
      str = (ASN1_STRING *)0x1;
    }
  }
  return (int)str;
}

