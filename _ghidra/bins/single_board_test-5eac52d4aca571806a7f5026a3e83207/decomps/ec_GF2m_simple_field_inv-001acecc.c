
int ec_GF2m_simple_field_inv(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = BN_GF2m_mod_inv(param_2,param_3,*(undefined4 *)(param_1 + 0x28));
  if (iVar1 == 0) {
    ERR_put_error(0x10,0x128,0xa5,"crypto/ec/ec2_smpl.c",0x386);
  }
  return iVar1;
}

