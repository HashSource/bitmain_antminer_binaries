
void do_all_fn_LHASH_DOALL_ARG(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  if (*param_1 != *param_2) {
    return;
  }
  (*(code *)param_2[1])(param_1,param_2[2],*param_1,(code *)param_2[1],param_4);
  return;
}

