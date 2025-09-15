
int DSA_size(DSA *param_1)

{
  int iVar1;
  uchar local_1c [4];
  ASN1_INTEGER local_18;
  
  iVar1 = BN_num_bits(param_1->q);
  local_18.data = local_1c;
  local_18.length = iVar1 + 7;
  if (iVar1 + 7 < 0) {
    local_18.length = iVar1 + 0xe;
  }
  local_18.length = local_18.length >> 3;
  local_1c[0] = 0xff;
  local_18.type = 2;
  iVar1 = i2d_ASN1_INTEGER(&local_18,(uchar **)0x0);
  iVar1 = ASN1_object_size(1,iVar1 << 1,0x10);
  return iVar1;
}

