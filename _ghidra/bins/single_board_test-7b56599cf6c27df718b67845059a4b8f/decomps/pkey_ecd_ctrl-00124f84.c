
uint pkey_ecd_ctrl(undefined4 param_1,int param_2,undefined4 param_3,EVP_MD *param_4)

{
  uint uVar1;
  EVP_MD *pEVar2;
  
  if (param_2 != 1) {
    if (param_2 == 7) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0xfffffffe;
    }
    return uVar1;
  }
  if (param_4 != (EVP_MD *)0x0) {
    pEVar2 = EVP_md_null();
    if (param_4 != pEVar2) {
      ERR_put_error(0x10,0x10f,0x8a,"crypto/ec/ecx_meth.c",0x32c);
    }
    return (uint)(param_4 == pEVar2);
  }
  return 1;
}

