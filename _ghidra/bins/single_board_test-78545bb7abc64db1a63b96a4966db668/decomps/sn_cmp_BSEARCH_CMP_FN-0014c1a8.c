
void sn_cmp_BSEARCH_CMP_FN(undefined4 *param_1,int *param_2)

{
  strcmp(*(char **)*param_1,*(char **)(&nid_objs + *param_2 * 0x18));
  return;
}

