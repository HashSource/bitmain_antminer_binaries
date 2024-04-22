
int ec_GF2m_have_precompute_mult
              (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = EC_EX_DATA_get_data(*(undefined4 *)(param_1 + 0x44),0xa1d4d,0xa1f49,0xa1ee9,param_4);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

