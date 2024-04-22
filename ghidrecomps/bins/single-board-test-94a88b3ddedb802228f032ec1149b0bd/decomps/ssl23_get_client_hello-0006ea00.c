
int ssl23_get_client_hello(SSL *param_1)

{
  uchar *puVar1;
  SSL_METHOD *pSVar2;
  uchar *puVar3;
  char cVar4;
  uchar *puVar5;
  ssl3_state_st *psVar6;
  byte bVar7;
  int iVar8;
  ssl2_state_st *psVar9;
  _func_3291 *p_Var10;
  byte *pbVar11;
  size_t __n;
  undefined4 *__s2;
  size_t __n_00;
  uint uVar12;
  uint uVar13;
  int iVar14;
  char *pcVar15;
  uchar *puVar16;
  char cVar17;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined2 local_2c;
  byte local_2a;
  
  if (param_1->state == 0x2210) {
    iVar14 = ssl3_setup_buffers();
    if (iVar14 == 0) {
      return -1;
    }
    iVar14 = ssl23_read_bytes(param_1,0xb);
    if (iVar14 != 0xb) {
      return iVar14;
    }
    __s2 = (undefined4 *)param_1->packet;
    local_34 = *__s2;
    uStack_30 = __s2[1];
    local_2a = *(byte *)((int)__s2 + 10);
    local_2c = *(undefined2 *)(__s2 + 2);
    __n_00 = 0xb;
    if (((int)((uint)*(byte *)__s2 << 0x18) < 0) && (*(byte *)((int)__s2 + 2) == 1)) {
      if (*(byte *)((int)__s2 + 3) == 0) {
        if ((*(byte *)(__s2 + 1) == 2) && ((param_1->references & 0x1000000U) == 0)) {
          iVar14 = -1;
          iVar8 = param_1->version;
          __n = 0xb;
          cVar17 = true;
          uVar12 = 0;
          goto LAB_0006ea24;
        }
      }
      else if (*(byte *)((int)__s2 + 3) == 3) {
        bVar7 = *(byte *)(__s2 + 1);
        if (bVar7 == 0) {
          uVar12 = param_1->references;
LAB_0006ef1a:
          if ((uVar12 & 0x2000000) != 0) {
            __n = 0xb;
            cVar17 = (uVar12 & 0x1000000) == 0;
            iVar8 = param_1->version;
            if ((bool)cVar17) {
              uVar12 = 0;
              iVar14 = -1;
            }
            else {
              uVar12 = 0xffffffff;
              iVar14 = -2;
            }
            goto LAB_0006ea24;
          }
          iVar8 = 0x300;
        }
        else {
          uVar12 = param_1->references;
          if (bVar7 < 3) {
            if (bVar7 == 2) goto LAB_0006ef90;
LAB_0006eede:
            if ((uVar12 & 0x4000000) != 0) goto LAB_0006ef1a;
            iVar8 = 0x301;
          }
          else {
            if (-1 < (int)(uVar12 << 4)) {
              param_1->state = 0x2211;
              uVar12 = 0xffffffff;
              param_1->version = 0x303;
              iVar14 = -2;
              __n = 0xb;
              cVar17 = false;
              iVar8 = 0x303;
              goto LAB_0006ea24;
            }
LAB_0006ef90:
            if ((uVar12 & 0x10000000) != 0) goto LAB_0006eede;
            iVar8 = 0x302;
          }
        }
        cVar17 = false;
        param_1->version = iVar8;
        param_1->state = 0x2211;
        uVar12 = 0xffffffff;
        iVar14 = -2;
        __n = 0xb;
        goto LAB_0006ea24;
      }
LAB_0006ed42:
      uVar12 = 0xffffffff;
      iVar14 = -2;
      __n = 0xb;
      cVar17 = false;
      iVar8 = param_1->version;
      goto LAB_0006ea24;
    }
    if (((*(byte *)__s2 != 0x16) || (*(byte *)((int)__s2 + 1) != 3)) ||
       (*(byte *)((int)__s2 + 5) != 1)) {
LAB_0006ecf2:
      iVar14 = strncmp(DAT_0006ed5c,(char *)__s2,4);
      if (((iVar14 == 0) || (iVar14 = strncmp(DAT_0006ed60,(char *)__s2,5), iVar14 == 0)) ||
         ((iVar14 = strncmp(DAT_0006ed64,(char *)__s2,5), iVar14 == 0 ||
          (iVar14 = strncmp(DAT_0006ed68,(char *)__s2,4), iVar14 == 0)))) {
        ERR_put_error(0x14,0x76,0x9c,DAT_0006eff0,0x18a);
        return -1;
      }
      iVar14 = strncmp(DAT_0006ed6c,(char *)__s2,7);
      if (iVar14 == 0) {
        ERR_put_error(0x14,0x76,0x9b,DAT_0006eff0,0x18d);
        return -1;
      }
      goto LAB_0006ed42;
    }
    if (*(byte *)((int)__s2 + 3) == 0) {
      if (*(byte *)(__s2 + 1) < 5) {
LAB_0006ef2c:
        ERR_put_error(0x14,0x76,0x12a,DAT_0006eff0,0x15c);
        return -1;
      }
      bVar7 = *(byte *)((int)__s2 + 9);
      if (bVar7 < 3) goto LAB_0006ecf2;
      if (*(byte *)(__s2 + 1) < 6) goto LAB_0006ef2c;
    }
    else {
      bVar7 = *(byte *)((int)__s2 + 9);
      if (bVar7 < 3) goto LAB_0006ecf2;
    }
    if (bVar7 < 4) {
      bVar7 = *(byte *)((int)__s2 + 10);
      if (bVar7 == 0) {
        if (param_1->references << 6 < 0) {
          if (param_1->references << 5 < 0) goto LAB_0006ed42;
LAB_0006efe6:
          param_1->version = 0x301;
          goto LAB_0006ee76;
        }
      }
      else {
        if (2 < bVar7) goto LAB_0006ef9c;
        iVar14 = param_1->references;
        if (bVar7 != 1) goto LAB_0006efc4;
LAB_0006efb8:
        if (-1 < iVar14 << 5) goto LAB_0006efe6;
        if (iVar14 << 6 < 0) goto LAB_0006ed42;
      }
      param_1->version = 0x300;
    }
    else {
LAB_0006ef9c:
      iVar14 = param_1->references;
      if (iVar14 << 4 < 0) {
LAB_0006efc4:
        if (iVar14 << 3 < 0) goto LAB_0006efb8;
        param_1->version = 0x302;
      }
      else {
        param_1->version = 0x303;
      }
    }
LAB_0006ee76:
    iVar8 = param_1->version;
    uVar12 = 2;
    iVar14 = 1;
    __n = 0xb;
    cVar17 = '\x03';
  }
  else {
    iVar8 = param_1->version;
    __n = 0;
    uVar12 = 0xffffffff;
    cVar17 = false;
    __n_00 = 0;
    iVar14 = -2;
LAB_0006ea24:
    if (0x303 < iVar8) {
      OpenSSLDie(DAT_0006ed54,0x193,DAT_0006ed58);
      iVar8 = param_1->version;
    }
  }
  if ((iVar8 < 0x303) && ((*(uint *)(param_1->cert + 0x38) & 0x30000) != 0)) {
    ERR_put_error(0x14,0x76,0x17b,DAT_0006ed54,0x197);
    return -1;
  }
  if (param_1->state == 0x2211) {
    pbVar11 = param_1->packet;
    bVar7 = pbVar11[4];
    __n_00 = (uint)pbVar11[1] | (*pbVar11 & 0x7f) << 8;
    if (0x1000 < __n_00) {
      ERR_put_error(0x14,0x76,0xd6,DAT_0006eff0,0x1bc);
      return -1;
    }
    if (__n_00 < 9) {
      iVar14 = 0x1c1;
LAB_0006edda:
      ERR_put_error(0x14,0x76,0xd5,DAT_0006eff0,iVar14);
      return -1;
    }
    iVar14 = ssl23_read_bytes(param_1,__n_00 + 2);
    if (iVar14 < 1) {
      return iVar14;
    }
    ssl3_finish_mac(param_1,param_1->packet + 2,param_1->packet_length - 2);
    if (param_1->msg_callback != (_func_3292 *)0x0) {
      (*param_1->msg_callback)
                (0,2,0,param_1->packet + 2,param_1->packet_length - 2,param_1,
                 param_1->msg_callback_arg);
    }
    puVar3 = param_1->packet;
    puVar16 = puVar3 + 0xb;
    uVar13 = (uint)CONCAT11(puVar3[5],puVar3[6]);
    uVar12 = (uint)CONCAT11(puVar3[9],puVar3[10]);
    iVar14 = CONCAT11(puVar3[7],puVar3[8]) + uVar13;
    pcVar15 = param_1->init_buf->data;
    if (uVar12 + 0xb + iVar14 != param_1->packet_length) {
      iVar14 = 0x1e3;
      goto LAB_0006edda;
    }
    pcVar15[5] = bVar7;
    *pcVar15 = '\x01';
    if (0x1f < uVar12) {
      uVar12 = 0x20;
    }
    pcVar15[4] = '\x03';
    memset(pcVar15 + 6,0,0x20);
    memcpy(pcVar15 + 6 + (0x20 - uVar12),puVar16 + iVar14,uVar12);
    iVar14 = 0;
    puVar3 = (uchar *)(pcVar15 + 0x29);
    pcVar15[0x26] = '\0';
    if (uVar13 == 0) {
      cVar17 = '\0';
      cVar4 = '\0';
    }
    else {
      uVar12 = 0;
      puVar5 = puVar16;
      do {
        puVar1 = puVar16 + uVar12;
        uVar12 = uVar12 + 3;
        if (*puVar1 == '\0') {
          iVar14 = iVar14 + 2;
          *puVar3 = puVar5[1];
          puVar3[1] = puVar5[2];
          puVar3 = puVar3 + 2;
        }
        puVar5 = puVar5 + 3;
      } while (uVar12 < uVar13);
      cVar4 = (char)((uint)iVar14 >> 8);
      cVar17 = (char)iVar14;
    }
    pcVar15[0x27] = cVar4;
    uVar12 = 1;
    pcVar15[0x28] = cVar17;
    cVar17 = '\x02';
    *puVar3 = '\x01';
    puVar3[1] = '\0';
    puVar3 = puVar3 + (-2 - (int)param_1->init_buf->data);
    pcVar15[3] = (char)puVar3;
    pcVar15[1] = (char)((uint)puVar3 >> 0x10);
    pcVar15[2] = (char)((uint)puVar3 >> 8);
    psVar6 = param_1->s3;
    iVar8 = param_1->version;
    (psVar6->tmp).reuse_message = 1;
    (psVar6->tmp).message_type = 1;
    (psVar6->tmp).message_size = (ulong)puVar3;
  }
  else {
    if (cVar17 == '\x01') {
      if (param_1->s2 == (ssl2_state_st *)0x0) {
        iVar14 = ssl2_new(param_1);
        if (iVar14 == 0) {
          return -1;
        }
      }
      else {
        ssl2_clear();
      }
      if (param_1->s3 != (ssl3_state_st *)0x0) {
        ssl3_free(param_1);
      }
      iVar14 = BUF_MEM_grow_clean(param_1->init_buf,0x3fff);
      if (iVar14 == 0) {
        return -1;
      }
      param_1->state = 0x2010;
      puVar3 = param_1->s2->rbuf;
      param_1->s2->ssl2_rollback = (uint)((param_1->references & 0x6000000U) != 0x6000000);
      param_1->rstate = 0xf0;
      param_1->packet_length = __n;
      param_1->packet = puVar3;
      memcpy(puVar3,&local_34,__n);
      psVar9 = param_1->s2;
      psVar9->rbuf_left = __n_00;
      psVar9->rbuf_offs = 0;
      pSVar2 = SSLv2_server_method();
      p_Var10 = (_func_3291 *)pSVar2->ssl_accept;
      param_1->method = pSVar2;
      param_1->handshake_func = p_Var10;
      goto LAB_0006ea4a;
    }
    if (iVar14 != 1) goto LAB_0006ea4a;
  }
  if (iVar8 == 2) {
    pSVar2 = SSLv2_server_method();
  }
  else if (iVar8 == 0x300) {
    pSVar2 = SSLv3_server_method();
  }
  else if (iVar8 == 0x301) {
    pSVar2 = TLSv1_server_method();
  }
  else if (iVar8 == 0x302) {
    pSVar2 = TLSv1_1_server_method();
  }
  else {
    if (iVar8 != 0x303) goto LAB_0006ed94;
    pSVar2 = TLSv1_2_server_method();
  }
  if (pSVar2 != (SSL_METHOD *)0x0) {
    param_1->method = pSVar2;
    iVar14 = ssl_init_wbio_buffer(param_1,1);
    if (iVar14 == 0) {
      return -1;
    }
    param_1->state = 0x2110;
    if (cVar17 == '\x03') {
      param_1->packet_length = __n_00;
      param_1->rstate = 0xf0;
      puVar3 = (param_1->s3->rbuf).buf;
      if (puVar3 == (uchar *)0x0) {
        iVar14 = ssl3_setup_read_buffer(param_1);
        if (iVar14 == 0) {
          return -1;
        }
        puVar3 = (param_1->s3->rbuf).buf;
      }
      param_1->packet = puVar3;
      memcpy(puVar3,&local_34,__n_00);
      psVar6 = param_1->s3;
      (psVar6->rbuf).left = __n_00;
      (psVar6->rbuf).offset = 0;
    }
    else {
      psVar6 = param_1->s3;
      param_1->packet_length = 0;
      (psVar6->rbuf).left = 0;
      (psVar6->rbuf).offset = 0;
    }
    param_1->handshake_func = (_func_3291 *)param_1->method->ssl_accept;
LAB_0006ea4a:
    if (2 < uVar12) {
      ERR_put_error(0x14,0x76,0xfc,DAT_0006eff0,0x280);
      return -1;
    }
    param_1->init_num = 0;
    iVar14 = SSL_accept(param_1);
    return iVar14;
  }
LAB_0006ed94:
  ERR_put_error(0x14,0x76,0x102,DAT_0006eff0,0x25a);
  return -1;
}

