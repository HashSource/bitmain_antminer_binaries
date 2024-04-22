
_STACK * ssl_bytes_to_cipher_list(int param_1,char *param_2,size_t param_3,_STACK **param_4)

{
  int iVar1;
  void *pvVar2;
  int extraout_r1;
  int iVar3;
  int iVar4;
  char *pcVar5;
  _STACK *st;
  _STACK *p_Var6;
  
  if (*(int *)(param_1 + 0x58) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 0;
  }
  iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x4c))(0,0);
  if ((iVar1 == 0) || (__aeabi_idivmod(param_3,iVar1), extraout_r1 != 0)) {
    ERR_put_error(0x14,0xa1,0x97,DAT_0007b24c,0x5e6);
    p_Var6 = (_STACK *)0x0;
  }
  else {
    if ((param_4 == (_STACK **)0x0) || (st = *param_4, st == (_STACK *)0x0)) {
      st = sk_new_null();
      if (st == (_STACK *)0x0) {
        ERR_put_error(0x14,0xa1,0x41,DAT_0007b24c,0x5ec);
        return (_STACK *)0x0;
      }
    }
    else {
      sk_zero(st);
    }
    iVar4 = *(int *)(param_1 + 0x98);
    if (*(void **)(iVar4 + 0x154) != (void *)0x0) {
      CRYPTO_free(*(void **)(iVar4 + 0x154));
      iVar4 = *(int *)(param_1 + 0x98);
    }
    pvVar2 = BUF_memdup(param_2,param_3);
    iVar3 = *(int *)(param_1 + 0x98);
    *(void **)(iVar4 + 0x154) = pvVar2;
    if (*(int *)(iVar3 + 0x154) == 0) {
      iVar1 = 0x5f8;
LAB_0007b22a:
      ERR_put_error(0x14,0xa1,0x41,DAT_0007b24c,iVar1);
LAB_0007b1c8:
      if ((param_4 == (_STACK **)0x0) || (*param_4 == (_STACK *)0x0)) {
        p_Var6 = (_STACK *)0x0;
        sk_free(st);
      }
      else {
        p_Var6 = (_STACK *)0x0;
      }
    }
    else {
      *(size_t *)(iVar3 + 0x158) = param_3;
      if (0 < (int)param_3) {
        iVar4 = 0;
        do {
          while (*(int *)(param_1 + 0x58) != 0) {
            if ((iVar1 == 3) && (*param_2 != '\0')) {
              pcVar5 = param_2 + 3;
              goto LAB_0007b106;
            }
            pcVar5 = param_2 + iVar1;
            if ((pcVar5[-2] != '\0') || (pcVar5[-1] != -1)) break;
            if (*(int *)(param_1 + 400) != 0) {
              ERR_put_error(0x14,0xa1,0x159,DAT_0007b24c,0x605);
              ssl3_send_alert(param_1,2,0x28);
              goto LAB_0007b1c8;
            }
            *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 1;
LAB_0007b120:
            iVar4 = iVar4 + iVar1;
            param_2 = pcVar5;
            if ((int)param_3 <= iVar4) goto LAB_0007b160;
          }
          if ((((iVar1 == 3) && (pcVar5 = param_2 + 3, *param_2 != '\0')) ||
              (pcVar5 = param_2 + iVar1, pcVar5[-2] != 'V')) || (pcVar5[-1] != '\0')) {
LAB_0007b106:
            pvVar2 = (void *)ssl_get_cipher_by_char(param_1,param_2);
            if ((pvVar2 == (void *)0x0) || (iVar3 = sk_push(st,pvVar2), iVar3 != 0))
            goto LAB_0007b120;
            iVar1 = 0x62a;
            goto LAB_0007b22a;
          }
          iVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x40))(param_1,0x77,0,0);
          if (iVar3 == 0) {
            ERR_put_error(0x14,0xa1,0x175,DAT_0007b24c,0x61c);
            if (*(int *)(param_1 + 0x58) != 0) {
              ssl3_send_alert(param_1,2,0x56);
            }
            goto LAB_0007b1c8;
          }
          iVar4 = iVar4 + iVar1;
          param_2 = pcVar5;
        } while (iVar4 < (int)param_3);
      }
LAB_0007b160:
      p_Var6 = st;
      if (param_4 != (_STACK **)0x0) {
        *param_4 = st;
      }
    }
  }
  return p_Var6;
}

