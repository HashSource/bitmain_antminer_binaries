
undefined4 SSL_COMP_set0_compression_methods(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = ssl_comp_methods;
  ssl_comp_methods = param_1;
  return uVar1;
}

