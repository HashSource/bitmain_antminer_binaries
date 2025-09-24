
undefined4 tls_construct_client_hello(SSL *param_1,undefined4 param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  stack_st_SSL_CIPHER *psVar4;
  int iVar5;
  int iVar6;
  _func_3297 *p_Var7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  undefined4 uVar11;
  int *piVar12;
  char *pcVar13;
  uint uVar14;
  int iVar15;
  undefined4 *puVar16;
  uchar *__n;
  void **buf;
  uint uVar17;
  undefined8 uVar18;
  int local_2c [2];
  
  puVar16 = (undefined4 *)param_1[2].tlsext_ticket_expected;
  iVar3 = ssl_set_client_hello_version();
  if (iVar3 != 0) {
    uVar11 = 0x45a;
    goto LAB_000edde6;
  }
  if ((puVar16 == (undefined4 *)0x0) ||
     (iVar3 = ssl_version_supported(param_1,*puVar16,0), iVar3 == 0)) {
LAB_000edd32:
    p_Var7 = param_1[2].tlsext_debug_cb;
    if (p_Var7 == (_func_3297 *)0x0) {
      uVar18 = ssl_get_new_session(param_1);
      p_Var7 = (_func_3297 *)((ulonglong)uVar18 >> 0x20);
      if ((int)uVar18 == 0) {
        return 0;
      }
      goto LAB_000ede08;
    }
    if (-1 < *(int *)(*(int *)(param_1->type + 100) + 0x30) << 0x1c) goto LAB_000edd5c;
    iVar3 = param_1->mac_flags + 0xac;
LAB_000edd48:
    pbVar10 = (byte *)(iVar3 + -1);
    do {
      pbVar10 = pbVar10 + 1;
      p_Var7 = (_func_3297 *)(uint)*pbVar10;
      if (p_Var7 != (_func_3297 *)0x0) goto LAB_000edd5c;
    } while ((byte *)(iVar3 + 0x1f) != pbVar10);
LAB_000ede1e:
    uVar18 = ssl_fill_hello_random(param_1,0,iVar3,0x20,0);
    p_Var7 = (_func_3297 *)((ulonglong)uVar18 >> 0x20);
    if ((int)uVar18 < 1) {
      uVar11 = 0x47f;
      goto LAB_000ede38;
    }
  }
  else {
    uVar18 = SSL_SESSION_is_resumable(puVar16);
    p_Var7 = (_func_3297 *)((ulonglong)uVar18 >> 0x20);
    if ((int)uVar18 == 0) goto LAB_000edd32;
LAB_000ede08:
    iVar3 = param_1->mac_flags + 0xac;
    if (*(int *)(*(int *)(param_1->type + 100) + 0x30) << 0x1c < 0) goto LAB_000edd48;
    if (param_1[2].tlsext_debug_cb == (_func_3297 *)0x0) goto LAB_000ede1e;
  }
LAB_000edd5c:
  iVar3 = WPACKET_put_bytes__(param_2,p_Var7,param_1[3].init_buf,(int)param_1[3].init_buf >> 0x1f,2)
  ;
  if ((iVar3 == 0) || (iVar3 = WPACKET_memcpy(param_2,param_1->mac_flags + 0xac,0x20), iVar3 == 0))
  {
    uVar11 = 0x4a7;
  }
  else {
    if ((param_1->handshake_func == (_func_3291 *)0x0) &&
       (piVar12 = (int *)param_1[2].tlsext_ticket_expected, *piVar12 != 0x304)) {
      buf = (void **)(piVar12 + 0x53);
      __n = (uchar *)piVar12[0x52];
      if (param_1->version == 0x304) {
        param_1[2].next_proto_negotiated = __n;
        memcpy(&param_1[2].tlsext_opaque_prf_input,buf,(size_t)__n);
      }
      iVar3 = WPACKET_start_sub_packet_len__(param_2,1);
      if (iVar3 != 0) {
        if (__n != (uchar *)0x0) {
LAB_000ede96:
          iVar3 = WPACKET_memcpy(param_2,buf,__n);
          if (iVar3 == 0) goto LAB_000edea6;
        }
LAB_000edd9c:
        iVar3 = WPACKET_close(param_2);
        if (iVar3 != 0) {
          if (*(int *)(*(int *)(param_1->type + 100) + 0x30) << 0x1c < 0) {
            uVar9 = *(uint *)(param_1->enc_read_ctx[1].final + 8);
            if ((0x100 < uVar9) ||
               (iVar3 = WPACKET_sub_memcpy__(param_2,param_1->enc_read_ctx,uVar9,1), iVar3 == 0)) {
              uVar11 = 0x4d4;
              goto LAB_000edde0;
            }
          }
          iVar3 = WPACKET_start_sub_packet_len__(param_2,2);
          if (iVar3 == 0) {
            uVar11 = 0x4dc;
            goto LAB_000ede38;
          }
          psVar4 = SSL_get_ciphers(param_1);
          pcVar13 = param_1[3].tlsext_hostname;
          iVar3 = ssl_set_client_disabled(param_1);
          if (iVar3 == 0) {
            ossl_statem_fatal(param_1,0x50,0x1a9,0xbf,"ssl/statem/statem_clnt.c",0xea1);
            return 0;
          }
          if (psVar4 == (stack_st_SSL_CIPHER *)0x0) {
            uVar11 = 0xea7;
LAB_000ee19e:
            ossl_statem_fatal(param_1,0x50,0x1a9,0x44,"ssl/statem/statem_clnt.c",uVar11);
            return 0;
          }
          uVar9 = 0xfffa;
          uVar14 = 0xfffc;
          if (pcVar13 != (char *)0x0) {
            uVar9 = 0xfffc;
            uVar14 = 0xfffe;
          }
          uVar17 = 0;
          if ((param_1[3].new_session & 0x80U) == 0) {
            uVar9 = uVar14;
          }
          bVar1 = false;
          for (iVar3 = 0; iVar5 = OPENSSL_sk_num(psVar4), uVar17 < uVar9 && iVar3 < iVar5;
              iVar3 = iVar3 + 1) {
            iVar5 = OPENSSL_sk_value(psVar4,iVar3);
            iVar6 = ssl_cipher_disabled(param_1,iVar5,0x10001,0);
            if (iVar6 == 0) {
              iVar6 = (**(code **)(param_1->type + 0x50))(iVar5,param_2,local_2c);
              if (iVar6 == 0) {
                uVar11 = 0xeca;
                goto LAB_000ee19e;
              }
              if (!bVar1) {
                if (*(int *)(*(int *)(param_1->type + 100) + 0x30) << 0x1c < 0) {
                  iVar6 = *(int *)(iVar5 + 0x2c);
                  if (iVar6 == 0x100) {
                    iVar15 = *(int *)(param_1->mac_flags + 0x2ac);
                    if (iVar15 != 0x100) {
                      iVar6 = 0xff00;
                      iVar8 = iVar15;
                      goto LAB_000edf86;
                    }
                    iVar5 = *(int *)(iVar5 + 0x28);
                    if (iVar5 == 0x100) {
                      iVar5 = 0xff00;
                      iVar15 = 0xff00;
                    }
                    else {
                      iVar15 = 0xff00;
                    }
                  }
                  else {
                    iVar15 = *(int *)(param_1->mac_flags + 0x2ac);
                    iVar8 = iVar15;
                    if (iVar15 == 0x100) {
                      iVar8 = 0xff00;
                    }
LAB_000edf86:
                    if (iVar8 < iVar6) goto LAB_000edf8a;
                    iVar5 = *(int *)(iVar5 + 0x28);
                    if (iVar5 == 0x100) {
                      iVar5 = 0xff00;
                    }
                    if (iVar15 == 0x100) {
                      iVar15 = 0xff00;
                    }
                  }
                  bVar1 = iVar15 <= iVar5;
                }
                else {
                  iVar6 = *(int *)(param_1->mac_flags + 0x2ac);
                  if (iVar6 <= *(int *)(iVar5 + 0x24)) {
                    bVar1 = *(int *)(iVar5 + 0x20) <= iVar6;
                  }
                }
              }
LAB_000edf8a:
              uVar17 = uVar17 + local_2c[0];
            }
          }
          bVar2 = (bool)(bVar1 ^ 1);
          if (uVar17 == 0) {
            bVar2 = true;
          }
          if (bVar2) {
            ossl_statem_fatal(param_1,0x50,0x1a9,0xb5,"ssl/statem/statem_clnt.c",0xee0);
            if (bVar1) {
              return 0;
            }
            ERR_add_error_data(1,"No ciphers enabled for max supported SSL/TLS version");
            return 0;
          }
          if ((pcVar13 == (char *)0x0) &&
             (iVar3 = (**(code **)(param_1->type + 0x50))(&scsv_27478,param_2,local_2c), iVar3 == 0)
             ) {
            uVar11 = 0xef0;
            goto LAB_000ee19e;
          }
          if ((param_1[3].new_session << 0x18 < 0) &&
             (iVar3 = (**(code **)(param_1->type + 0x50))(scsv_27479,param_2,local_2c), iVar3 == 0))
          {
            uVar11 = 0xefa;
            goto LAB_000ee19e;
          }
          iVar3 = WPACKET_close(param_2);
          if (iVar3 == 0) {
            uVar11 = 0x4e6;
LAB_000ede38:
            ossl_statem_fatal(param_1,0x50,0x1e7,0x44,"ssl/statem/statem_clnt.c",uVar11);
            return 0;
          }
          iVar3 = WPACKET_start_sub_packet_len__(param_2,1);
          if (iVar3 == 0) {
            uVar11 = 0x4ed;
            goto LAB_000ede38;
          }
          iVar3 = ssl_allow_compression(param_1);
          if ((((iVar3 != 0) && (param_1[3].method[1].ssl_renegotiate != (_func_3204 *)0x0)) &&
              ((*(int *)(*(int *)(param_1->type + 100) + 0x30) << 0x1c < 0 ||
               (*(int *)(param_1->mac_flags + 0x2ac) < 0x304)))) &&
             (iVar3 = OPENSSL_sk_num(), 0 < iVar3)) {
            iVar5 = 0;
            do {
              iVar6 = iVar5 + 1;
              uVar18 = OPENSSL_sk_value(param_1[3].method[1].ssl_renegotiate,iVar5);
              iVar5 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar18 >> 0x20),*(int *)uVar18,
                                          *(int *)uVar18 >> 0x1f,1);
              if (iVar5 == 0) {
                uVar11 = 0x4fa;
                goto LAB_000ede38;
              }
              iVar5 = iVar6;
            } while (iVar6 != iVar3);
          }
          iVar3 = WPACKET_put_bytes__(param_2,1,0,0,1);
          if ((iVar3 != 0) && (iVar3 = WPACKET_close(param_2), iVar3 != 0)) {
            iVar3 = tls_construct_extensions(param_1,param_2,0x80,0,0);
            if (iVar3 != 0) {
              return 1;
            }
            return 0;
          }
          uVar11 = 0x503;
          goto LAB_000edde0;
        }
      }
    }
    else if ((param_1->version == 0x304) && (param_1[3].server << 0xb < 0)) {
      param_1[2].next_proto_negotiated = (uchar *)0x20;
      buf = &param_1[2].tlsext_opaque_prf_input;
      if ((param_1[2].tlsext_debug_cb == (_func_3297 *)0x0) &&
         (iVar3 = RAND_bytes((uchar *)buf,0x20), iVar3 < 1)) {
        uVar11 = 0x4b7;
        goto LAB_000ede38;
      }
      iVar3 = WPACKET_start_sub_packet_len__(param_2,1);
      if (iVar3 != 0) {
        __n = (uchar *)0x20;
        goto LAB_000ede96;
      }
    }
    else {
      iVar3 = WPACKET_start_sub_packet_len__(param_2,1);
      if (iVar3 != 0) goto LAB_000edd9c;
    }
LAB_000edea6:
    uVar11 = 0x4ca;
  }
LAB_000edde0:
  iVar3 = 0x44;
LAB_000edde6:
  ossl_statem_fatal(param_1,0x50,0x1e7,iVar3,"ssl/statem/statem_clnt.c",uVar11);
  return 0;
}

