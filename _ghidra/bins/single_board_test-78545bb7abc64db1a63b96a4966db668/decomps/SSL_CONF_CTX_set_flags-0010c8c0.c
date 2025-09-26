
uint SSL_CONF_CTX_set_flags(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = param_2 | uVar1;
  return param_2 | uVar1;
}

