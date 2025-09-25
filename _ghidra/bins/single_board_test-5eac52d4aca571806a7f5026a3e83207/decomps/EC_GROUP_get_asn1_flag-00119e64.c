
int EC_GROUP_get_asn1_flag(EC_GROUP *group)

{
  return *(int *)(group + 0x14);
}

