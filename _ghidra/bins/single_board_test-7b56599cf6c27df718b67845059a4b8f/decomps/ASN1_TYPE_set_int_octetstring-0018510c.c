
int ASN1_TYPE_set_int_octetstring(ASN1_TYPE *a,long num,uchar *data,int len)

{
  int iVar1;
  ASN1_TYPE *local_2c;
  long local_28;
  int *local_24;
  int local_20 [2];
  uchar *local_18;
  undefined4 local_14;
  
  local_24 = local_20;
  local_20[1] = 4;
  local_14 = 0;
  local_2c = a;
  local_28 = num;
  local_20[0] = len;
  local_18 = data;
  iVar1 = ASN1_TYPE_pack_sequence(&asn1_int_oct_it,&local_28,&local_2c);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

