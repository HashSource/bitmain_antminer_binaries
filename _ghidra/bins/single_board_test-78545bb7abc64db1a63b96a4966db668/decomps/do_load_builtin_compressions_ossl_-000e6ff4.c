
void do_load_builtin_compressions_ossl_(void)

{
  COMP_METHOD *pCVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  pCVar1 = COMP_zlib();
  CRYPTO_mem_ctrl(3);
  ssl_comp_methods = OPENSSL_sk_new(0xe6fe9);
  iVar2 = COMP_get_type(pCVar1);
  if (((iVar2 != 0) && (ssl_comp_methods != 0)) &&
     (puVar3 = (undefined4 *)CRYPTO_malloc(0xc,"ssl/ssl_ciph.c",0x1d3), puVar3 != (undefined4 *)0x0)
     ) {
    puVar3[2] = pCVar1;
    *puVar3 = 1;
    uVar4 = COMP_get_name(pCVar1);
    puVar3[1] = uVar4;
    OPENSSL_sk_push(ssl_comp_methods,puVar3);
    OPENSSL_sk_sort(ssl_comp_methods);
  }
  CRYPTO_mem_ctrl(2);
  return;
}

