
void curve448_scalar_mul(undefined4 param_1)

{
  sc_montmul();
  sc_montmul(param_1,param_1,&sc_r2);
  return;
}

