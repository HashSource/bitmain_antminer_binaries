
int tls_setup_handshake(SSL *param_1)

{
  bool bVar1;
  int iVar2;
  stack_st_SSL_CIPHER *psVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  _func_3212 **pp_Var8;
  undefined1 auStack_18 [4];
  int local_14;
  
  iVar2 = ssl3_init_finished_mac();
  if (iVar2 != 0) {
    iVar2 = param_1->in_handshake;
    param_1[3].packet = (uchar *)0x0;
    param_1[3].packet_length = 0;
    param_1[3].s2 = (ssl2_state_st *)0x0;
    param_1[3].s3 = (ssl3_state_st *)0x0;
    param_1[3].d1 = (dtls1_state_st *)0x0;
    param_1[3].read_ahead = 0;
    *(undefined2 *)&param_1[3].msg_callback = 0;
    if (iVar2 == 0) {
      if ((*(int *)(param_1->mac_flags + 0x180) == 0) || (*(int *)(param_1->mac_flags + 0x204) == 0)
         ) {
        piVar6 = (int *)(param_1[3].max_send_fragment + 0x38);
        do {
          ExclusiveAccess(piVar6);
          bVar1 = (bool)hasExclusiveAccess(piVar6);
        } while (!bVar1);
        *piVar6 = *piVar6 + 1;
      }
      else {
        piVar6 = (int *)(param_1[3].max_send_fragment + 0x3c);
        do {
          ExclusiveAccess(piVar6);
          bVar1 = (bool)hasExclusiveAccess(piVar6);
        } while (!bVar1);
        *piVar6 = *piVar6 + 1;
      }
      memset((void *)(param_1->mac_flags + 0xac),0,0x20);
      param_1->enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
      iVar2 = *(int *)(param_1->type + 100);
      *(undefined4 *)(param_1->mac_flags + 0x218) = 0;
      if (*(int *)(iVar2 + 0x30) << 0x1c < 0) {
        param_1->d1 = (dtls1_state_st *)0x1;
      }
      return 1;
    }
    psVar3 = SSL_get_ciphers(param_1);
    iVar2 = ssl_get_min_max_version(param_1,auStack_18,&local_14,0);
    if (iVar2 == 0) {
      for (; iVar4 = OPENSSL_sk_num(psVar3), iVar2 < iVar4; iVar2 = iVar2 + 1) {
        iVar4 = OPENSSL_sk_value(psVar3,iVar2);
        if (*(int *)(*(int *)(param_1->type + 100) + 0x30) << 0x1c < 0) {
          iVar7 = *(int *)(iVar4 + 0x28);
          if (local_14 == 0x100) {
            if (iVar7 != 0x100) {
              iVar5 = 0xff00;
              goto LAB_000f5060;
            }
          }
          else {
            iVar5 = local_14;
            if (iVar7 == 0x100) {
              iVar7 = 0xff00;
            }
LAB_000f5060:
            if (iVar7 < iVar5) goto LAB_000f5064;
            if (local_14 != 0x100) {
              iVar7 = *(int *)(iVar4 + 0x2c);
              iVar4 = local_14;
              if (iVar7 == 0x100) {
                iVar7 = 0xff00;
              }
              goto LAB_000f508c;
            }
          }
          iVar7 = *(int *)(iVar4 + 0x2c);
          if (iVar7 == 0x100) goto LAB_000f5090;
          iVar4 = 0xff00;
LAB_000f508c:
          if (iVar7 <= iVar4) {
LAB_000f5090:
            if ((*(int *)(param_1->mac_flags + 0x180) == 0) ||
               (*(int *)(param_1->mac_flags + 0x204) == 0)) {
              piVar6 = (int *)(param_1[3].max_send_fragment + 0x44);
              do {
                ExclusiveAccess(piVar6);
                bVar1 = (bool)hasExclusiveAccess(piVar6);
              } while (!bVar1);
              *piVar6 = *piVar6 + 1;
            }
            else {
              pp_Var8 = &(param_1[3].method)->get_cipher_by_char;
              do {
                ExclusiveAccess(pp_Var8);
                bVar1 = (bool)hasExclusiveAccess(pp_Var8);
              } while (!bVar1);
              *pp_Var8 = *pp_Var8 + 1;
              *(undefined4 *)(param_1->mac_flags + 0x244) = 0;
            }
            return 1;
          }
        }
        else if (*(int *)(iVar4 + 0x20) <= local_14) {
          iVar4 = *(int *)(iVar4 + 0x24);
          iVar7 = local_14;
          goto LAB_000f508c;
        }
LAB_000f5064:
      }
      ossl_statem_fatal(param_1,0x28,0x1fc,0xb5,"ssl/statem/statem_lib.c",0x80);
      ERR_add_error_data(1,"No ciphers enabled for max supported SSL/TLS version");
    }
    else {
      ossl_statem_fatal(param_1,0x50,0x1fc,0x44,"ssl/statem/statem_lib.c",0x6e);
    }
    iVar2 = 0;
  }
  return iVar2;
}

