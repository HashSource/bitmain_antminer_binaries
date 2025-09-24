
size_t OPENSSL_sk_find(size_t *param_1,int param_2)

{
  void *pvVar1;
  int *piVar2;
  size_t __nmemb;
  size_t sVar3;
  int local_14 [2];
  
  if ((param_1 != (size_t *)0x0) && (__nmemb = *param_1, __nmemb != 0)) {
    if ((__compar_fn_t)param_1[4] == (__compar_fn_t)0x0) {
      if (0 < (int)__nmemb) {
        piVar2 = (int *)param_1[1];
        sVar3 = 0;
        if (param_2 == *piVar2) {
          return 0;
        }
        do {
          sVar3 = sVar3 + 1;
          if (__nmemb == sVar3) {
            return 0xffffffff;
          }
          piVar2 = piVar2 + 1;
        } while (param_2 != *piVar2);
        return sVar3;
      }
    }
    else {
      local_14[0] = param_2;
      if (param_1[2] == 0) {
        if (1 < (int)__nmemb) {
          qsort((void *)param_1[1],__nmemb,4,(__compar_fn_t)param_1[4]);
        }
        param_1[2] = 1;
      }
      if ((local_14[0] != 0) &&
         (pvVar1 = OBJ_bsearch_ex_(local_14,(void *)param_1[1],*param_1,4,(cmp *)param_1[4],2),
         pvVar1 != (void *)0x0)) {
        return (int)((int)pvVar1 - param_1[1]) >> 2;
      }
    }
  }
  return 0xffffffff;
}

