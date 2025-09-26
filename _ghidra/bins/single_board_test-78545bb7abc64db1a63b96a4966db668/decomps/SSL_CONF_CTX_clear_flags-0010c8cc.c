
uint SSL_CONF_CTX_clear_flags(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = uVar1 & ~param_2;
  return uVar1 & ~param_2;
}

