
int ssl23_accept(SSL *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  BUF_MEM *str;
  int iVar4;
  _func_3294 *p_Var5;
  undefined4 in_stack_ffffffc0;
  undefined4 in_stack_ffffffc4;
  time_t local_2c [2];
  
  local_2c[0] = time((time_t *)0x0);
  RAND_add(local_2c,4,(double)CONCAT44(in_stack_ffffffc4,in_stack_ffffffc0));
  ERR_clear_error();
  piVar1 = __errno_location();
  p_Var5 = param_1->info_callback;
  *piVar1 = 0;
  if (p_Var5 == (_func_3294 *)0x0) {
    p_Var5 = *(_func_3294 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar2 = SSL_state(param_1);
  if (((uVar2 & 0x3000) == 0) || (iVar3 = SSL_state(param_1), iVar3 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  iVar3 = param_1->state;
  do {
    if (iVar3 < 0x2212) {
      if (0x220f < iVar3) {
        param_1->shutdown = 0;
        iVar3 = ssl23_get_client_hello(param_1);
        if (-1 < iVar3) {
          param_1->in_handshake = param_1->in_handshake + -1;
          return iVar3;
        }
        goto LAB_0006f0a0;
      }
      if ((iVar3 != 0x2000) && (iVar3 != 0x2003)) goto LAB_0006f08c;
    }
    else if ((iVar3 != 0x4000) && (iVar3 != 0x6000)) {
LAB_0006f08c:
      iVar3 = -1;
      ERR_put_error(0x14,0x73,0xff,DAT_0006f150,0xd8);
      goto LAB_0006f0a0;
    }
    param_1->server = 1;
    if (p_Var5 != (_func_3294 *)0x0) {
      (*p_Var5)(param_1,0x10,1);
    }
    param_1->type = 0x2000;
    if (param_1->init_buf == (BUF_MEM *)0x0) {
      str = BUF_MEM_new();
      if (str == (BUF_MEM *)0x0) {
        iVar3 = -1;
        goto LAB_0006f0a0;
      }
      iVar4 = BUF_MEM_grow(str,0x4000);
      if (iVar4 == 0) {
        iVar3 = -1;
        BUF_MEM_free(str);
LAB_0006f0a0:
        param_1->in_handshake = param_1->in_handshake + -1;
        if (p_Var5 != (_func_3294 *)0x0) {
          (*p_Var5)(param_1,0x2002,iVar3);
        }
        return iVar3;
      }
      param_1->init_buf = str;
    }
    ssl3_init_finished_mac(param_1);
    param_1->state = 0x2210;
    *(int *)(param_1->psk_server_callback + 0x40) =
         *(int *)(param_1->psk_server_callback + 0x40) + 1;
    param_1->init_num = 0;
    if (p_Var5 == (_func_3294 *)0x0) {
      iVar3 = 0x2210;
    }
    else if (iVar3 != 0x2210) {
      param_1->state = iVar3;
      (*p_Var5)(param_1,0x2001,1);
      iVar3 = 0x2210;
      param_1->state = 0x2210;
    }
  } while( true );
}

