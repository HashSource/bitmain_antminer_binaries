
int EC_GROUP_get_asn1_flag(EC_GROUP *group)

{
  return *(uint *)(group + 0x34) & 0x7fffffff;
}

