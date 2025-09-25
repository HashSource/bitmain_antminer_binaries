
void uint32_print(BIO *param_1,undefined4 *param_2,int param_3)

{
  if ((*(uint *)(param_3 + 0x14) & 2) == 0) {
    BIO_printf(param_1,"%u\n",*(undefined4 *)*param_2);
    return;
  }
  BIO_printf(param_1,"%d\n",*(undefined4 *)*param_2);
  return;
}

