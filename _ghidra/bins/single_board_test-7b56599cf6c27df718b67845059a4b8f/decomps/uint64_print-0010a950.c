
void uint64_print(BIO *param_1,undefined4 *param_2,int param_3)

{
  param_2 = (undefined4 *)*param_2;
  if ((*(uint *)(param_3 + 0x14) & 2) == 0) {
    BIO_printf(param_1,"%ju\n",*param_2,param_2[1]);
    return;
  }
  BIO_printf(param_1,"%jd\n",*param_2,param_2[1]);
  return;
}

