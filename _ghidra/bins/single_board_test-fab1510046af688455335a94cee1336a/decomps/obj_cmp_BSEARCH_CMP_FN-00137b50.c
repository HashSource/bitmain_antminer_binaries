
void obj_cmp_BSEARCH_CMP_FN(int *param_1,int *param_2)

{
  size_t __n;
  
  __n = *(size_t *)(*param_1 + 0xc);
  if ((__n == *(size_t *)(&DAT_001fc1cc + *param_2 * 0x18)) && (__n != 0)) {
    memcmp(*(void **)(*param_1 + 0x10),*(void **)(&DAT_001fc1d0 + *param_2 * 0x18),__n);
    return;
  }
  return;
}

