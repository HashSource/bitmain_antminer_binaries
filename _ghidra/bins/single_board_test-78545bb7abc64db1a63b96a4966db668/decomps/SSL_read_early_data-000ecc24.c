
uint SSL_read_early_data(SSL *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  void *pvVar2;
  void *extraout_r3;
  _func_3296 *p_Var3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = param_1->in_handshake;
  if (uVar4 == 0) {
    iVar1 = 0x721;
LAB_000ecca6:
    ERR_put_error(0x14,0x211,0x42,"ssl/ssl_lib.c",iVar1);
    return 0;
  }
  pvVar2 = param_1->msg_callback_arg;
  if (pvVar2 != (void *)0x8) {
    if (pvVar2 == (void *)0xa) goto LAB_000ecc82;
    if (pvVar2 != (void *)0x0) {
      ERR_put_error(0x14,0x211,0x42,"ssl/ssl_lib.c",0x74e);
      return 0;
    }
    uVar4 = SSL_in_before();
    if (uVar4 == 0) {
      iVar1 = 0x729;
      goto LAB_000ecca6;
    }
  }
  param_1->msg_callback_arg = &DAT_00000009;
  iVar1 = SSL_accept(param_1);
  pvVar2 = extraout_r3;
  if (iVar1 < 1) {
    pvVar2 = (void *)0x8;
    uVar4 = 0;
  }
  if (iVar1 < 1) {
    param_1->msg_callback_arg = pvVar2;
    return uVar4;
  }
LAB_000ecc82:
  p_Var3 = param_1[3].psk_server_callback;
  bVar5 = p_Var3 != (_func_3296 *)0x2;
  if (bVar5) {
    p_Var3 = (_func_3296 *)0xc;
  }
  if (bVar5) {
    param_1->msg_callback_arg = p_Var3;
  }
  else {
    param_1->msg_callback_arg = (void *)0xb;
    iVar1 = SSL_read_ex(param_1,param_2,param_3,param_4);
    if ((0 < iVar1) || (param_1->msg_callback_arg != (void *)0xc)) {
      param_1->msg_callback_arg = (void *)0xa;
      return (uint)(0 < iVar1);
    }
  }
  *param_4 = 0;
  return 2;
}

