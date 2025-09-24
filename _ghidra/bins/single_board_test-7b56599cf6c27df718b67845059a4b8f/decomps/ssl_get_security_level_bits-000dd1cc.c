
undefined4 ssl_get_security_level_bits(undefined4 param_1,int param_2,uint *param_3)

{
  uint uVar1;
  
  if (param_2 == 0) {
    uVar1 = SSL_get_security_level();
  }
  else {
    uVar1 = SSL_CTX_get_security_level(param_2);
  }
  uVar1 = uVar1 & ~((int)uVar1 >> 0x1f);
  if (4 < (int)uVar1) {
    uVar1 = 5;
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = uVar1;
  }
  return *(undefined4 *)(&minbits_table_29000 + uVar1 * 4);
}

