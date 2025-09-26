
void ec_GF2m_simple_field_mul(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  BN_GF2m_mod_mul_arr(param_2,param_3,param_4,param_1 + 0x5c);
  return;
}

