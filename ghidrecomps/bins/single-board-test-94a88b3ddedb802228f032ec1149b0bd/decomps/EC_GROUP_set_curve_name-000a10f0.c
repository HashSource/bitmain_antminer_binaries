
void EC_GROUP_set_curve_name(EC_GROUP *group,int nid)

{
  *(int *)(group + 0x30) = nid;
  return;
}

