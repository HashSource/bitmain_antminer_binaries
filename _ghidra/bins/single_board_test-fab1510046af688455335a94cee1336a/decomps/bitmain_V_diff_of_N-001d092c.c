
/* WARNING: Unknown calling convention */

double bitmain_V_diff_of_N(int32_t N)

{
  int32_t N_00;
  double dVar1;
  double extraout_d4;
  
  bitmain_convert_N_to_V(N);
  dVar1 = bitmain_convert_N_to_V_furmula(N_00);
  return extraout_d4 - dVar1;
}

