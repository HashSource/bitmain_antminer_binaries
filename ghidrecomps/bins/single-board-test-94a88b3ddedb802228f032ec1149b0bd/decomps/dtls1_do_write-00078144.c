
/* WARNING: Type propagation algorithm not settling */

long dtls1_do_write(SSL *param_1,int param_2)

{
  char cVar1;
  undefined2 uVar2;
  undefined uVar3;
  BIO *pBVar4;
  long lVar5;
  ulong uVar6;
  EVP_MD *md;
  char *pcVar7;
  uint uVar8;
  EVP_MD_CTX *ctx;
  int iVar9;
  uint uVar10;
  dtls1_state_st *pdVar11;
  uint uVar12;
  char *pcVar13;
  int iVar14;
  EVP_CIPHER_CTX *pEVar15;
  uint local_30;
  int local_2c;
  
  pdVar11 = param_1->d1;
  iVar14 = *(int *)&pdVar11->w_msg_hdr;
  if (iVar14 != 0) {
    pBVar4 = SSL_get_wbio(param_1);
    lVar5 = BIO_ctrl(pBVar4,0x31,0,(void *)0x0);
    (pdVar11->w_msg_hdr).msg_len = iVar14 - lVar5;
    pdVar11 = param_1->d1;
    *(undefined4 *)&pdVar11->w_msg_hdr = 0;
  }
  uVar12 = (pdVar11->w_msg_hdr).msg_len;
  pBVar4 = SSL_get_wbio(param_1);
  lVar5 = BIO_ctrl(pBVar4,0x31,0,(void *)0x0);
  if ((uVar12 < 0x100U - lVar5) &&
     ((lVar5 = SSL_ctrl(param_1,0x20,0,(void *)0x0), lVar5 << 0x13 < 0 ||
      (iVar14 = dtls1_query_mtu_part_0(param_1), iVar14 == 0)))) {
    return -1;
  }
  uVar12 = (param_1->d1->w_msg_hdr).msg_len;
  pBVar4 = SSL_get_wbio(param_1);
  lVar5 = BIO_ctrl(pBVar4,0x31,0,(void *)0x0);
  if (uVar12 < 0x100U - lVar5) {
    OpenSSLDie(DAT_00078554,0x112,DAT_00078564);
  }
  if (((param_1->init_off == 0) && (param_2 == 0x16)) &&
     (param_1->init_num != (param_1->d1->w_msg_hdr).frag_off + 0xc)) {
    OpenSSLDie(DAT_00078554,0x118,DAT_00078560);
  }
  ctx = param_1->write_hash;
  if (ctx == (EVP_MD_CTX *)0x0) {
LAB_00078500:
    iVar14 = 0;
  }
  else {
    if (param_1->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
      uVar6 = EVP_CIPHER_CTX_flags(param_1->enc_write_ctx);
      if ((uVar6 & 0xf0007) == 6) goto LAB_00078500;
      ctx = param_1->write_hash;
    }
    md = EVP_MD_CTX_md(ctx);
    iVar14 = EVP_MD_size(md);
  }
  if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar6 = EVP_CIPHER_CTX_flags(param_1->enc_write_ctx), (uVar6 & 0xf0007) != 2)) {
    local_2c = 0;
  }
  else {
    local_2c = EVP_CIPHER_block_size(param_1->enc_write_ctx->cipher);
    local_2c = local_2c << 1;
  }
  iVar9 = param_1->init_num;
  uVar3 = true;
  local_30 = 0;
  do {
    if (iVar9 < 1) {
      return 0;
    }
    pBVar4 = SSL_get_wbio(param_1);
    lVar5 = BIO_ctrl(pBVar4,0xd,0,(void *)0x0);
    uVar12 = lVar5 + iVar14 + 0xd + local_2c;
    uVar10 = (param_1->d1->w_msg_hdr).msg_len;
    if ((uVar10 <= uVar12) || (uVar10 = uVar10 - uVar12, uVar10 < 0xd)) {
      pBVar4 = SSL_get_wbio(param_1);
      lVar5 = BIO_ctrl(pBVar4,0xb,0,(void *)0x0);
      if (lVar5 < 1) {
        return lVar5;
      }
      uVar12 = (param_1->d1->w_msg_hdr).msg_len;
      if (uVar12 <= local_2c + iVar14 + 0x19U) {
        return 0xffffffff;
      }
      uVar10 = (uVar12 - 0xd) - (local_2c + iVar14);
    }
    uVar8 = param_1->init_num;
    uVar12 = uVar10;
    if (uVar8 <= uVar10) {
      uVar12 = uVar8;
    }
    if ((int)uVar12 < 0) {
      uVar12 = 0x7fffffff;
    }
    if (param_2 == 0x16) {
      iVar9 = param_1->init_off;
      if (iVar9 == 0) {
LAB_00078366:
        if (uVar12 < 0xc) {
          return 0xffffffff;
        }
        pEVar15 = (EVP_CIPHER_CTX *)(uVar12 - 0xc);
      }
      else {
        if (iVar9 < 0xd) {
          OpenSSLDie(DAT_00078554,0x154,DAT_0007855c);
          iVar9 = param_1->init_off;
          uVar8 = param_1->init_num;
        }
        uVar8 = uVar8 + 0xc;
        iVar9 = iVar9 + -0xc;
        uVar12 = uVar8;
        if (uVar10 <= uVar8) {
          uVar12 = uVar10;
        }
        param_1->init_num = uVar8;
        param_1->init_off = iVar9;
        if (-1 < (int)uVar12) goto LAB_00078366;
        uVar12 = 0x7fffffff;
        pEVar15 = (EVP_CIPHER_CTX *)0x7ffffff3;
      }
      pdVar11 = param_1->d1;
      cVar1 = *(char *)&(pdVar11->w_msg_hdr).seq;
      pcVar7 = param_1->init_buf->data;
      (pdVar11->w_msg_hdr).is_ccs = local_30;
      (pdVar11->w_msg_hdr).saved_retransmit_state.enc_write_ctx = pEVar15;
      pcVar7[iVar9] = cVar1;
      pcVar7[iVar9 + 1] = (char)*(undefined2 *)((int)&(pdVar11->w_msg_hdr).frag_off + 2);
      pcVar7[iVar9 + 2] = (char)((pdVar11->w_msg_hdr).frag_off >> 8);
      pcVar7[iVar9 + 3] = (char)(pdVar11->w_msg_hdr).frag_off;
      pcVar7[iVar9 + 4] = (char)((ushort)*(undefined2 *)&(pdVar11->w_msg_hdr).frag_len >> 8);
      pcVar7[iVar9 + 5] = (char)*(undefined2 *)&(pdVar11->w_msg_hdr).frag_len;
      pcVar7[iVar9 + 6] = (char)*(undefined2 *)((int)&(pdVar11->w_msg_hdr).is_ccs + 2);
      pcVar7[iVar9 + 7] = (char)((pdVar11->w_msg_hdr).is_ccs >> 8);
      pcVar7[iVar9 + 8] = (char)(pdVar11->w_msg_hdr).is_ccs;
      pcVar7[iVar9 + 9] =
           (char)*(undefined2 *)
                  ((int)&(pdVar11->w_msg_hdr).saved_retransmit_state.enc_write_ctx + 2);
      pcVar7[iVar9 + 10] =
           (char)((uint)(pdVar11->w_msg_hdr).saved_retransmit_state.enc_write_ctx >> 8);
      pcVar7[iVar9 + 0xb] = (char)(pdVar11->w_msg_hdr).saved_retransmit_state.enc_write_ctx;
    }
    uVar10 = dtls1_write_bytes(param_1,param_2,param_1->init_buf->data + param_1->init_off,uVar12);
    if ((int)uVar10 < 0) {
      if (!(bool)uVar3) {
        return 0xffffffff;
      }
      pBVar4 = SSL_get_wbio(param_1);
      lVar5 = BIO_ctrl(pBVar4,0x2b,0,(void *)0x0);
      if (lVar5 < 1) {
        return 0xffffffff;
      }
      uVar12 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
      if ((uVar12 & 0x1000) != 0) {
        return 0xffffffff;
      }
      pdVar11 = param_1->d1;
      iVar9 = *(int *)&pdVar11->w_msg_hdr;
      if (iVar9 != 0) {
        pBVar4 = SSL_get_wbio(param_1);
        lVar5 = BIO_ctrl(pBVar4,0x31,0,(void *)0x0);
        (pdVar11->w_msg_hdr).msg_len = iVar9 - lVar5;
        pdVar11 = param_1->d1;
        *(undefined4 *)&pdVar11->w_msg_hdr = 0;
      }
      uVar12 = (pdVar11->w_msg_hdr).msg_len;
      pBVar4 = SSL_get_wbio(param_1);
      lVar5 = BIO_ctrl(pBVar4,0x31,0,(void *)0x0);
      if (uVar12 < 0x100U - lVar5) {
        uVar12 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
        if ((uVar12 & 0x1000) != 0) {
          return 0xffffffff;
        }
        iVar9 = dtls1_query_mtu_part_0(param_1);
        if (iVar9 == 0) {
          return 0xffffffff;
        }
        iVar9 = param_1->init_num;
        uVar3 = false;
      }
      else {
        iVar9 = param_1->init_num;
        uVar3 = false;
      }
    }
    else {
      if (uVar10 != uVar12) {
        OpenSSLDie(DAT_00078554,400,DAT_00078558);
      }
      if ((param_2 == 0x16) && (pdVar11 = param_1->d1, pdVar11->listen == 0)) {
        pcVar13 = param_1->init_buf->data;
        pcVar7 = pcVar13 + param_1->init_off;
        if ((local_30 == 0) && (param_1->version != 0x100)) {
          pcVar13[param_1->init_off] = *(char *)&(pdVar11->w_msg_hdr).seq;
          pcVar7[1] = (char)*(undefined2 *)((int)&(pdVar11->w_msg_hdr).frag_off + 2);
          pcVar7[2] = (char)((pdVar11->w_msg_hdr).frag_off >> 8);
          pcVar7[3] = (char)(pdVar11->w_msg_hdr).frag_off;
          pcVar7[4] = (char)((ushort)*(undefined2 *)&(pdVar11->w_msg_hdr).frag_len >> 8);
          uVar2 = *(undefined2 *)&(pdVar11->w_msg_hdr).frag_len;
          pcVar7[6] = '\0';
          pcVar7[7] = '\0';
          pcVar7[5] = (char)uVar2;
          pcVar7[8] = '\0';
          pcVar7[9] = (char)*(undefined2 *)((int)&(pdVar11->w_msg_hdr).frag_off + 2);
          pcVar7[10] = (char)((pdVar11->w_msg_hdr).frag_off >> 8);
          pcVar7[0xb] = (char)(pdVar11->w_msg_hdr).frag_off;
          uVar12 = uVar10;
        }
        else {
          pcVar7 = pcVar7 + 0xc;
          uVar12 = uVar10 - 0xc;
        }
        ssl3_finish_mac(param_1,pcVar7,uVar12);
        uVar12 = param_1->init_num;
      }
      else {
        uVar12 = param_1->init_num;
      }
      if (uVar12 == uVar10) {
        if (param_1->msg_callback != (_func_3292 *)0x0) {
          (*param_1->msg_callback)
                    (1,param_1->version,param_2,param_1->init_buf->data,param_1->init_off + uVar10,
                     param_1,param_1->msg_callback_arg);
        }
        param_1->init_off = 0;
        param_1->init_num = 0;
        return 1;
      }
      iVar9 = uVar12 - uVar10;
      param_1->init_num = iVar9;
      local_30 = local_30 + (uVar10 - 0xc);
      param_1->init_off = param_1->init_off + uVar10;
    }
  } while( true );
}

