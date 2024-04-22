
int ssl3_get_client_certificate(int *param_1)

{
  int iVar1;
  X509 *a;
  void *pvVar2;
  int iVar3;
  _STACK **pp_Var4;
  undefined4 uVar5;
  int iVar6;
  _STACK *st;
  uint len;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  byte *local_28;
  int local_24;
  
  iVar1 = (**(code **)(param_1[2] + 0x30))(param_1,0x2180,0x2181,0xffffffff,param_1[0x42],&local_24)
  ;
  if (local_24 == 0) {
    return iVar1;
  }
  iVar3 = param_1[0x16];
  if (*(int *)(iVar3 + 0x340) == 0x10) {
    if ((param_1[0x32] & 3U) == 3) {
      ERR_put_error(0x14,0x89,199,DAT_00087b4c,0xc59);
      st = (_STACK *)0x0;
      uVar5 = 0x28;
    }
    else {
      if ((*param_1 < 0x301) || (*(int *)(iVar3 + 0x390) == 0)) {
        *(undefined4 *)(iVar3 + 0x354) = 1;
        return 1;
      }
      ERR_put_error(0x14,0x89,0xe9,DAT_00087b4c,0xc62);
      st = (_STACK *)0x0;
      uVar5 = 10;
    }
  }
  else if (*(int *)(iVar3 + 0x340) == 0xb) {
    local_28 = (byte *)param_1[0x10];
    st = sk_new_null();
    iVar3 = 0xc72;
    if (st == (_STACK *)0x0) {
LAB_00087a2c:
      ERR_put_error(0x14,0x89,0x41,DAT_00087b4c,iVar3);
      goto LAB_000878b2;
    }
    uVar9 = (uint)local_28[1] << 8 | (uint)*local_28 << 0x10 | (uint)local_28[2];
    if (uVar9 + 3 == iVar1) {
      pbVar7 = local_28 + 3;
      if (uVar9 == 0) {
LAB_00087a3c:
        local_28 = pbVar7;
        iVar1 = sk_num(st);
        if (iVar1 < 1) {
          if (*param_1 == 0x300) {
            ERR_put_error(0x14,0x89,0xb0,DAT_00087b4c,0xc9e);
            uVar5 = 0x28;
          }
          else if ((param_1[0x32] & 3U) == 3) {
            ERR_put_error(0x14,0x89,199,DAT_00087b4c,0xca5);
            uVar5 = 0x28;
          }
          else {
            if ((*(int *)(param_1[0x16] + 0x178) == 0) ||
               (iVar1 = ssl3_digest_cached_records(param_1), iVar1 != 0)) goto LAB_00087a52;
            uVar5 = 0x50;
          }
        }
        else {
          iVar1 = ssl_verify_cert_chain(param_1,st);
          if (0 < iVar1) {
LAB_00087a52:
            iVar1 = param_1[0x30];
            if (*(X509 **)(iVar1 + 0x9c) != (X509 *)0x0) {
              X509_free(*(X509 **)(iVar1 + 0x9c));
              iVar1 = param_1[0x30];
            }
            pvVar2 = sk_shift(st);
            iVar6 = param_1[0x30];
            iVar3 = param_1[0x3b];
            *(void **)(iVar1 + 0x9c) = pvVar2;
            *(int *)(iVar6 + 0xa0) = iVar3;
            if (*(int *)(iVar6 + 0x98) != 0) {
LAB_00087a82:
              pp_Var4 = *(_STACK ***)(iVar6 + 0x98);
              if (*pp_Var4 != (_STACK *)0x0) {
                sk_pop_free(*pp_Var4,DAT_00087b50);
                pp_Var4 = *(_STACK ***)(param_1[0x30] + 0x98);
              }
              *pp_Var4 = st;
              return 1;
            }
            uVar5 = ssl_sess_cert_new();
            *(undefined4 *)(iVar6 + 0x98) = uVar5;
            iVar6 = param_1[0x30];
            if (*(int *)(iVar6 + 0x98) != 0) goto LAB_00087a82;
            iVar3 = 0xcc4;
            goto LAB_00087a2c;
          }
          uVar5 = ssl_verify_alarm_type(param_1[0x3b]);
          ERR_put_error(0x14,0x89,0x86,DAT_00087b4c,0xcb3);
        }
      }
      else {
        len = (uint)local_28[4] << 8 | (uint)local_28[3] << 0x10 | (uint)local_28[5];
        local_28 = local_28 + 6;
        for (uVar8 = len + 3; uVar8 <= uVar9; uVar8 = uVar8 + len + 3) {
          pbVar7 = local_28 + len;
          a = d2i_X509((X509 **)0x0,&local_28,len);
          if (a == (X509 *)0x0) {
            ERR_put_error(0x14,0x89,0xd,DAT_00087b4c,0xc88);
            goto LAB_000878b2;
          }
          if (local_28 != pbVar7) {
            ERR_put_error(0x14,0x89,0x87,DAT_00087b4c,0xc8e);
            ssl3_send_alert(param_1,2,0x32);
            param_1[0xd] = 5;
LAB_000878da:
            X509_free(a);
            goto LAB_000878e0;
          }
          iVar1 = sk_push(st,a);
          if (iVar1 == 0) {
            ERR_put_error(0x14,0x89,0x41,DAT_00087b4c,0xc92);
            param_1[0xd] = 5;
            goto LAB_000878da;
          }
          pbVar7 = local_28;
          if (uVar9 <= uVar8) goto LAB_00087a3c;
          len = (uint)local_28[1] << 8 | (uint)*local_28 << 0x10 | (uint)local_28[2];
          local_28 = local_28 + 3;
        }
        ERR_put_error(0x14,0x89,0x87,DAT_00087b4c,0xc81);
        uVar5 = 0x32;
      }
    }
    else {
      local_28 = local_28 + 3;
      ERR_put_error(0x14,0x89,0x9f,DAT_00087b4c,0xc79);
      uVar5 = 0x32;
    }
  }
  else {
    st = (_STACK *)0x0;
    uVar5 = 10;
    ERR_put_error(0x14,0x89,0x106,DAT_00087b4c,0xc6c);
  }
  ssl3_send_alert(param_1,2,uVar5);
LAB_000878b2:
  param_1[0xd] = 5;
  if (st != (_STACK *)0x0) {
LAB_000878e0:
    sk_pop_free(st,DAT_00087b50);
  }
  return -1;
}

