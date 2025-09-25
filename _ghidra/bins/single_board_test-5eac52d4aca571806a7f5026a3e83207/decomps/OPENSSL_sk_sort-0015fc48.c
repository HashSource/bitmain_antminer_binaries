
void OPENSSL_sk_sort(size_t *param_1)

{
  if (((param_1 != (size_t *)0x0) && (param_1[2] == 0)) &&
     ((__compar_fn_t)param_1[4] != (__compar_fn_t)0x0)) {
    if (1 < (int)*param_1) {
      qsort((void *)param_1[1],*param_1,4,(__compar_fn_t)param_1[4]);
    }
    param_1[2] = 1;
    return;
  }
  return;
}

