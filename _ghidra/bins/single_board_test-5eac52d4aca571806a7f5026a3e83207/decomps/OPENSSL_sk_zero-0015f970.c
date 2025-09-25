
void OPENSSL_sk_zero(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    memset((void *)param_1[1],0,*param_1 << 2);
    *param_1 = 0;
    return;
  }
  return;
}

