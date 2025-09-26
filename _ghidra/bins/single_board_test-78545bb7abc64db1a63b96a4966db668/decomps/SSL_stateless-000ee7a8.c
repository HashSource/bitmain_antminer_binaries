
int SSL_stateless(SSL *param_1)

{
  int iVar1;
  
  iVar1 = SSL_clear(param_1);
  if (iVar1 != 0) {
    ERR_clear_error();
    *(uint *)param_1->mac_flags = *(uint *)param_1->mac_flags | 0x800;
    iVar1 = SSL_accept(param_1);
    *(uint *)param_1->mac_flags = *(uint *)param_1->mac_flags & 0xfffff7ff;
    if ((0 < iVar1) && (param_1[3].ex_data.sk != (stack_st_void *)0x0)) {
      return 1;
    }
    if (param_1[2].tlsext_debug_cb == (_func_3297 *)0x1) {
      iVar1 = ossl_statem_in_error(param_1);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      return -iVar1;
    }
    iVar1 = -1;
  }
  return iVar1;
}

