
void bn_wexpand(BIGNUM *param_1,int param_2)

{
  if (param_2 <= param_1->dmax) {
    return;
  }
  bn_expand2(param_1,param_2);
  return;
}

