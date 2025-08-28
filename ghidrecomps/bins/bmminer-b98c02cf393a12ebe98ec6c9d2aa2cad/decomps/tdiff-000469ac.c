
undefined4 tdiff(int *param_1,int *param_2)

{
  return SUB84((double)(longlong)(param_1[1] - param_2[1]) / 1000000.0 +
               (double)(longlong)(*param_1 - *param_2),0);
}

