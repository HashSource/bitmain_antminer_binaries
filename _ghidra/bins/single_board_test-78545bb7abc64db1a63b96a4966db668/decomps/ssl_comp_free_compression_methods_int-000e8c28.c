
void ssl_comp_free_compression_methods_int(void)

{
  undefined4 uVar1;
  
  uVar1 = ssl_comp_methods;
  ssl_comp_methods = 0;
  OPENSSL_sk_pop_free(uVar1,0xe7061);
  return;
}

