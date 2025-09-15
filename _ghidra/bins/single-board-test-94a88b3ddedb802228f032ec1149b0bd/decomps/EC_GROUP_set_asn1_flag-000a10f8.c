
void EC_GROUP_set_asn1_flag(EC_GROUP *group,int flag)

{
  *(uint *)(group + 0x34) = *(uint *)(group + 0x34) & 0x80000000 | flag & 0x7fffffffU;
  return;
}

