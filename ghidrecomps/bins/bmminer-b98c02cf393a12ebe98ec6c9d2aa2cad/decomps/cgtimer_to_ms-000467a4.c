
int cgtimer_to_ms(int *param_1)

{
  return *param_1 * 1000 + param_1[1] / 1000000;
}

