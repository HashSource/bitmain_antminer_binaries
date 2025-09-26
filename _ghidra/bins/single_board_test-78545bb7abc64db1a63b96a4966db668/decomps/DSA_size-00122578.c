
int DSA_size(DSA *param_1)

{
  int iVar1;
  uchar local_24 [4];
  ASN1_INTEGER local_20;
  
  iVar1 = BN_num_bits(param_1->p);
  local_20.length = iVar1 + 0xe;
  if (-1 < iVar1 + 7) {
    local_20.length = iVar1 + 7;
  }
  local_20.length = local_20.length >> 3;
  local_20.data = local_24;
  local_20.type = 2;
  local_24[0] = 0xff;
  iVar1 = i2d_ASN1_INTEGER(&local_20,(uchar **)0x0);
  iVar1 = ASN1_object_size(1,iVar1 << 1,0x10);
  return iVar1;
}

