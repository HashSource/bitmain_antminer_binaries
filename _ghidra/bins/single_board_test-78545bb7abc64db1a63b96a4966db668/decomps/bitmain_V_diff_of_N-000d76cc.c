
/* WARNING: Unknown calling convention */

double bitmain_V_diff_of_N(int32_t N)

{
  double dVar1;
  double dVar2;
  
  dVar1 = bitmain_convert_N_to_V(N);
  dVar2 = bitmain_convert_N_to_V_furmula(N);
  return dVar1 - dVar2;
}

