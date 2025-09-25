
undefined4 DTLSv1_listen(SSL *param_1,void *param_2)

{
  int iVar1;
  BIO *b;
  BIO *bp;
  int *piVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  void *parg;
  uint uVar6;
  uint uVar7;
  void *data;
  uint uVar8;
  _func_3197 *p_Var9;
  EVP_CIPHER_CTX *pEVar10;
  _func_3196 *p_Var11;
  char *data_00;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  bool bVar15;
  undefined8 uVar16;
  uint local_150;
  int local_14c;
  undefined4 local_148;
  undefined4 uStack_144;
  undefined1 auStack_140 [24];
  undefined1 auStack_128 [260];
  
  if (param_1->rwstate == 0) {
    SSL_set_accept_state(param_1);
  }
  iVar1 = SSL_clear(param_1);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  ERR_clear_error();
  b = SSL_get_rbio(param_1);
  bp = SSL_get_wbio(param_1);
  if (bp == (BIO *)0x0 || b == (BIO *)0x0) {
    ERR_put_error(0x14,0x15e,0x80,"ssl/d1_lib.c",0x1da);
  }
  else {
    if ((param_1->version & 0xff00U) == 0xfe00) {
      iVar1 = ssl3_setup_buffers(param_1);
      if (iVar1 != 0) {
        data = (void *)param_1[4].rwstate;
        uVar8 = 3U - param_1[4].type & 7;
        data_00 = (char *)(param_1[4].type + uVar8);
        piVar2 = __errno_location();
        do {
          *piVar2 = 0;
          iVar1 = BIO_read(b,data_00,0x400d);
          if (iVar1 < 1) {
            iVar1 = BIO_test_flags(b,8);
            goto joined_r0x000fb484;
          }
          if (iVar1 < 0xd) {
            uVar12 = 0;
            ERR_put_error(0x14,0x15e,0x12a,"ssl/d1_lib.c",0x21c);
            goto LAB_000fb016;
          }
          if (param_1->read_hash != (EVP_MD_CTX *)0x0) {
            (*(code *)param_1->read_hash)(0,0,0x100,data_00,0xd,param_1,param_1->expand);
          }
          if (iVar1 == 1) {
            iVar1 = 0x227;
LAB_000fb006:
            uVar12 = 0;
            ERR_put_error(0x14,0x15e,0x9f,"ssl/d1_lib.c",iVar1);
            goto LAB_000fb016;
          }
          if (*data_00 != '\x16') {
            iVar1 = 0x22c;
LAB_000fb44c:
            ERR_put_error(0x14,0x15e,0xf4,"ssl/d1_lib.c",iVar1);
            uVar12 = 0;
            goto LAB_000fb016;
          }
          if (data_00[1] != -2) {
            uVar12 = 0;
            ERR_put_error(0x14,0x15e,0x74,"ssl/d1_lib.c",0x235);
            goto LAB_000fb016;
          }
          if (iVar1 - 2U < 9) {
LAB_000fb082:
            iVar1 = 0x23d;
            goto LAB_000fb006;
          }
          local_148 = *(undefined4 *)(data_00 + 3);
          uStack_144 = *(undefined4 *)(data_00 + 7);
          if ((iVar1 - 0xbU < 2) ||
             (uVar14 = (uint)CONCAT11(data_00[0xb],data_00[0xc]), iVar1 - 0xdU < uVar14))
          goto LAB_000fb082;
          if (((char)local_148 != '\0') ||
             (local_148._1_1_ = (char)((uint)local_148 >> 8), local_148._1_1_ != '\0')) {
            iVar1 = 0x248;
            goto LAB_000fb44c;
          }
          if ((((uVar14 == 0) || (uVar14 - 1 < 3)) ||
              (uVar3 = (uint)(byte)data_00[0xf] << 8 | (uint)(byte)data_00[0xe] << 0x10 |
                       (uint)(byte)data_00[0x10], uVar14 - 4 < 2)) || (uVar14 - 6 < 3)) {
LAB_000fb076:
            iVar1 = 599;
            goto LAB_000fb006;
          }
          if (uVar14 - 9 < 3) goto LAB_000fb076;
          uVar13 = (uint)(byte)data_00[0x18] |
                   (uint)(byte)data_00[0x17] << 8 | (uint)(byte)data_00[0x16] << 0x10;
          if ((uVar14 - 0xc < uVar13) || (uVar13 != uVar14 - 0xc)) goto LAB_000fb076;
          if (data_00[0xd] != '\x01') {
            iVar1 = 0x25c;
            goto LAB_000fb44c;
          }
          if (2 < CONCAT11(data_00[0x11],data_00[0x12])) {
            uVar12 = 0;
            ERR_put_error(0x14,0x15e,0x192,"ssl/d1_lib.c",0x262);
            goto LAB_000fb016;
          }
          bVar15 = uVar3 == uVar13;
          if (uVar13 <= uVar3) {
            bVar15 = data_00[0x15] == '\0' && (data_00[0x14] == '\0' && data_00[0x13] == '\0');
          }
          if (!bVar15) {
            uVar12 = 0;
            ERR_put_error(0x14,0x15e,0x191,"ssl/d1_lib.c",0x26f);
            goto LAB_000fb016;
          }
          if (param_1->read_hash != (EVP_MD_CTX *)0x0) {
            (*(code *)param_1->read_hash)
                      (0,param_1->version,0x16,data_00 + 0xd,uVar14,param_1,param_1->expand);
          }
          if (uVar13 < 2) {
            iVar1 = 0x279;
            goto LAB_000fb006;
          }
          uVar3 = (uint)CONCAT11(data_00[0x19],data_00[0x1a]);
          if (uVar3 == 0x100) {
            uVar7 = *(uint *)param_1->type;
            if (uVar7 != 0x100) {
              uVar3 = 0xff00;
              uVar6 = uVar7;
              goto LAB_000fb158;
            }
          }
          else {
            uVar6 = *(uint *)param_1->type;
            uVar7 = uVar6;
            if (uVar6 == 0x100) {
              uVar7 = 0xff00;
            }
LAB_000fb158:
            bVar15 = 0x1fffe < uVar6;
            if (uVar6 != 0x1ffff) {
              bVar15 = uVar7 <= uVar3;
            }
            if (bVar15 && (uVar6 != 0x1ffff && uVar3 != uVar7)) {
              uVar12 = 0;
              ERR_put_error(0x14,0x15e,0x10b,"ssl/d1_lib.c",0x282);
              goto LAB_000fb016;
            }
          }
          if (uVar13 - 2 < 0x21) {
LAB_000fb174:
            iVar1 = 0x28d;
            goto LAB_000fb006;
          }
          uVar3 = (uint)(byte)data_00[0x3b];
          if (((uVar13 - 0x23 < uVar3) || (iVar1 = (uVar13 - 0x23) - uVar3, iVar1 == 0)) ||
             (iVar1 - 1U < (uint)(byte)data_00[uVar3 + 0x3c])) goto LAB_000fb174;
          if ((byte)data_00[uVar3 + 0x3c] != 0) {
            p_Var9 = param_1[3].method[1].ssl_free;
            if (p_Var9 == (_func_3197 *)0x0) {
              ERR_put_error(0x14,0x15e,0x193,"ssl/d1_lib.c",0x29c);
              return 0xffffffff;
            }
            iVar1 = (*p_Var9)(param_1);
            if (iVar1 != 0) {
              pEVar10 = param_1->enc_read_ctx;
              pEVar10[1].final[0x14] = '\x01';
              pEVar10[1].final[0x15] = '\0';
              pEVar10[1].final[0x10] = '\x01';
              pEVar10[1].final[0x11] = '\0';
              pEVar10[1].final[0x12] = '\x01';
              pEVar10[1].final[0x13] = '\0';
              DTLS_RECORD_LAYER_set_write_sequence(&param_1[3].tlsext_heartbeat,&local_148);
              SSL_set_options(param_1,0x2000);
              ossl_statem_set_hello_verify_done(param_1);
              lVar4 = BIO_ctrl(b,0x2e,0,param_2);
              if (lVar4 < 1) {
                BIO_ADDR_clear(param_2);
              }
              iVar1 = dtls_buffer_listen_record(param_1,uVar14,&local_148,uVar8);
              if (iVar1 == 0) {
                return 0xffffffff;
              }
              uVar12 = 1;
              goto LAB_000fb016;
            }
          }
          p_Var11 = param_1[3].method[1].ssl_clear;
          if (p_Var11 == (_func_3196 *)0x0) {
LAB_000fb3bc:
            ERR_put_error(0x14,0x15e,400,"ssl/d1_lib.c",700);
            return 0xffffffff;
          }
          iVar1 = (*p_Var11)(param_1);
          if ((iVar1 == 0) || (0xff < local_150)) goto LAB_000fb3bc;
          if (*(int *)param_1->type == 0x1ffff) {
            iVar1 = 0xfeff;
          }
          else {
            iVar1 = param_1->version;
          }
          iVar5 = ssl_get_max_send_fragment(param_1);
          uVar16 = WPACKET_init_static_len(auStack_140,data,iVar5 + 0xd,0);
          if ((int)uVar16 == 0) {
LAB_000fb402:
            ERR_put_error(0x14,0x15e,0x44,"ssl/d1_lib.c",0x2fb);
            WPACKET_cleanup(auStack_140);
            return 0xffffffff;
          }
          uVar16 = WPACKET_put_bytes__(auStack_140,(int)((ulonglong)uVar16 >> 0x20),0x16,0,1);
          if ((((int)uVar16 == 0) ||
              (iVar1 = WPACKET_put_bytes__(auStack_140,(int)((ulonglong)uVar16 >> 0x20),iVar1,0,2),
              iVar1 == 0)) || (iVar1 = WPACKET_memcpy(auStack_140,&local_148,8), iVar1 == 0))
          goto LAB_000fb402;
          uVar16 = WPACKET_start_sub_packet_len__(auStack_140,2);
          if ((int)uVar16 == 0) goto LAB_000fb402;
          uVar16 = WPACKET_put_bytes__(auStack_140,(int)((ulonglong)uVar16 >> 0x20),3,0,1);
          if ((int)uVar16 == 0) goto LAB_000fb402;
          uVar16 = WPACKET_put_bytes__(auStack_140,(int)((ulonglong)uVar16 >> 0x20),0,0,3);
          if ((int)uVar16 == 0) goto LAB_000fb402;
          uVar16 = WPACKET_put_bytes__(auStack_140,(int)((ulonglong)uVar16 >> 0x20),0,0,2);
          if (((((int)uVar16 == 0) ||
               (iVar1 = WPACKET_put_bytes__(auStack_140,(int)((ulonglong)uVar16 >> 0x20),0,0,3),
               iVar1 == 0)) ||
              (((iVar1 = WPACKET_start_sub_packet_len__(auStack_140,3), iVar1 == 0 ||
                ((iVar1 = dtls_raw_hello_verify_request(auStack_140,auStack_128,local_150),
                 iVar1 == 0 || (iVar1 = WPACKET_close(auStack_140), iVar1 == 0)))) ||
               (iVar1 = WPACKET_close(auStack_140), iVar1 == 0)))) ||
             ((iVar1 = WPACKET_get_total_written(auStack_140,&local_14c), iVar1 == 0 ||
              (iVar1 = WPACKET_finish(auStack_140), iVar1 == 0)))) goto LAB_000fb402;
          *(undefined2 *)((int)data + 0xe) = *(undefined2 *)((int)data + 0x16);
          *(undefined1 *)((int)data + 0x10) = *(undefined1 *)((int)data + 0x18);
          if (param_1->read_hash != (EVP_MD_CTX *)0x0) {
            (*(code *)param_1->read_hash)(1,0,0x100,data_00,0xd,param_1,param_1->expand);
          }
          parg = (void *)BIO_ADDR_new();
          if (parg == (void *)0x0) {
            ERR_put_error(0x14,0x15e,0x41,"ssl/d1_lib.c",0x311);
            goto LAB_000fb3b8;
          }
          lVar4 = BIO_ctrl(b,0x2e,0,parg);
          if (0 < lVar4) {
            BIO_ctrl(bp,0x2c,0,parg);
          }
          BIO_ADDR_free(parg);
          iVar1 = BIO_write(bp,data,local_14c);
        } while ((local_14c <= iVar1) && (lVar4 = BIO_ctrl(bp,0xb,0,(void *)0x0), 0 < lVar4));
        iVar1 = BIO_test_flags(bp,8);
joined_r0x000fb484:
        if (iVar1 != 0) {
LAB_000fb3b8:
          uVar12 = 0;
LAB_000fb016:
          BIO_ADDR_free(0);
          return uVar12;
        }
      }
      return 0xffffffff;
    }
    ERR_put_error(0x14,0x15e,0x103,"ssl/d1_lib.c",0x1e6);
  }
  return 0xffffffff;
}

