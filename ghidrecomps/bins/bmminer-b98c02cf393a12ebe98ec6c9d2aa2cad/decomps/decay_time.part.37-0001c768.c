
void decay_time_part_37(double *param_1)

{
  double in_d0;
  double dVar1;
  double in_d1;
  double unaff_d8;
  
  dVar1 = exp(unaff_d8);
  dVar1 = 1.0 - 1.0 / dVar1;
  *param_1 = (*param_1 + (in_d0 / in_d1) * dVar1) / (dVar1 + 1.0);
  return;
}

