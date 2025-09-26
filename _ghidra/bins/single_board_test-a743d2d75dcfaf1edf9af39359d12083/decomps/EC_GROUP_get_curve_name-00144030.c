
int EC_GROUP_get_curve_name(EC_GROUP *group)

{
  return *(int *)(group + 0x30);
}

