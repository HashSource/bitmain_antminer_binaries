
void ssleay_rand_seed(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    ssleay_rand_add_part_0(SUB84((double)(longlong)param_2,0));
    return;
  }
  return;
}

