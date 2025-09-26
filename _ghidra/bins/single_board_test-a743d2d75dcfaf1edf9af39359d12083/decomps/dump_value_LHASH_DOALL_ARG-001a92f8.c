
void dump_value_LHASH_DOALL_ARG(undefined4 *param_1,BIO *param_2)

{
  if (param_1[1] != 0) {
    BIO_printf(param_2,"[%s] %s=%s\n",*param_1,param_1[1],param_1[2]);
    return;
  }
  BIO_printf(param_2,"[[%s]]\n",*param_1);
  return;
}

