
void bn_set_static_words(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  param_1[3] = 0;
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[4] = param_1[4] | 2;
  param_1[2] = param_3;
  bn_correct_top();
  return;
}

