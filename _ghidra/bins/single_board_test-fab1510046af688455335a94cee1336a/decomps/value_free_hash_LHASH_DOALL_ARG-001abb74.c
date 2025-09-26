
void value_free_hash_LHASH_DOALL_ARG(void *param_1,_LHASH *param_2)

{
  if (*(int *)((int)param_1 + 4) != 0) {
    lh_delete(param_2,param_1);
    return;
  }
  return;
}

