
/* WARNING: Type propagation algorithm not settling */

long dtls1_send_change_cipher_spec(SSL *param_1,int param_2,int param_3)

{
  ushort uVar1;
  bool bVar2;
  BIO *pBVar3;
  long lVar4;
  ulong uVar5;
  EVP_MD *md;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  EVP_MD_CTX *ctx;
  int iVar9;
  dtls1_state_st *pdVar10;
  uint uVar11;
  int iVar12;
  
  if (param_1->state == param_2) {
    pcVar8 = param_1->init_buf->data;
    *pcVar8 = '\x01';
    pdVar10 = param_1->d1;
    iVar12 = param_1->version;
    uVar1 = pdVar10->next_handshake_write_seq;
    pdVar10->handshake_write_seq = uVar1;
    param_1->init_num = 1;
    if (iVar12 == 0x100) {
      pdVar10->next_handshake_write_seq = uVar1 + 1;
      pcVar8[1] = (char)(uVar1 >> 8);
      pcVar8[2] = (char)param_1->d1->handshake_write_seq;
      pdVar10 = param_1->d1;
      param_1->init_num = param_1->init_num + 2;
    }
    uVar1 = pdVar10->handshake_write_seq;
    param_1->init_off = 0;
    (pdVar10->w_msg_hdr).frag_off = 0;
    (pdVar10->w_msg_hdr).is_ccs = 0;
    (pdVar10->w_msg_hdr).saved_retransmit_state.enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    *(ushort *)&(pdVar10->w_msg_hdr).frag_len = uVar1;
    *(undefined *)&(pdVar10->w_msg_hdr).seq = 1;
    dtls1_buffer_message(param_1,1);
    pdVar10 = param_1->d1;
    param_1->state = param_3;
    iVar12 = *(int *)&pdVar10->w_msg_hdr;
  }
  else {
    pdVar10 = param_1->d1;
    iVar12 = *(int *)&pdVar10->w_msg_hdr;
  }
  if (iVar12 != 0) {
    pBVar3 = SSL_get_wbio(param_1);
    lVar4 = BIO_ctrl(pBVar3,0x31,0,(void *)0x0);
    (pdVar10->w_msg_hdr).msg_len = iVar12 - lVar4;
    pdVar10 = param_1->d1;
    *(undefined4 *)&pdVar10->w_msg_hdr = 0;
  }
  uVar11 = (pdVar10->w_msg_hdr).msg_len;
  pBVar3 = SSL_get_wbio(param_1);
  lVar4 = BIO_ctrl(pBVar3,0x31,0,(void *)0x0);
  if ((uVar11 < 0x100U - lVar4) &&
     ((lVar4 = SSL_ctrl(param_1,0x20,0,(void *)0x0), lVar4 << 0x13 < 0 ||
      (iVar12 = dtls1_query_mtu_part_0(param_1), iVar12 == 0)))) {
    return -1;
  }
  uVar11 = (param_1->d1->w_msg_hdr).msg_len;
  pBVar3 = SSL_get_wbio(param_1);
  lVar4 = BIO_ctrl(pBVar3,0x31,0,(void *)0x0);
  if (uVar11 < 0x100U - lVar4) {
    OpenSSLDie(DAT_0007902c,0x112,DAT_00079034);
  }
  ctx = param_1->write_hash;
  if (ctx == (EVP_MD_CTX *)0x0) {
LAB_00078f48:
    iVar12 = 0;
  }
  else {
    if (param_1->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
      uVar5 = EVP_CIPHER_CTX_flags(param_1->enc_write_ctx);
      if ((uVar5 & 0xf0007) == 6) goto LAB_00078f48;
      ctx = param_1->write_hash;
    }
    md = EVP_MD_CTX_md(ctx);
    iVar12 = EVP_MD_size(md);
  }
  if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar5 = EVP_CIPHER_CTX_flags(param_1->enc_write_ctx), (uVar5 & 0xf0007) != 2)) {
    iVar6 = 0;
  }
  else {
    iVar6 = EVP_CIPHER_block_size(param_1->enc_write_ctx->cipher);
    iVar6 = iVar6 << 1;
  }
  iVar9 = param_1->init_num;
  bVar2 = true;
  while( true ) {
    while( true ) {
      if (iVar9 < 1) {
        return 0;
      }
      pBVar3 = SSL_get_wbio(param_1);
      lVar4 = BIO_ctrl(pBVar3,0xd,0,(void *)0x0);
      uVar7 = iVar12 + 0xd + iVar6 + lVar4;
      uVar11 = (param_1->d1->w_msg_hdr).msg_len;
      if ((uVar11 <= uVar7) || (uVar11 = uVar11 - uVar7, uVar11 < 0xd)) {
        pBVar3 = SSL_get_wbio(param_1);
        lVar4 = BIO_ctrl(pBVar3,0xb,0,(void *)0x0);
        if (lVar4 < 1) {
          return lVar4;
        }
        uVar11 = (param_1->d1->w_msg_hdr).msg_len;
        if (uVar11 <= iVar12 + iVar6 + 0x19U) {
          return 0xffffffff;
        }
        uVar11 = (uVar11 - 0xd) - (iVar12 + iVar6);
      }
      if ((uint)param_1->init_num <= uVar11) {
        uVar11 = param_1->init_num;
      }
      if ((int)uVar11 < 0) {
        uVar11 = 0x7fffffff;
      }
      uVar7 = dtls1_write_bytes(param_1,0x14,param_1->init_buf->data + param_1->init_off);
      if ((int)uVar7 < 0) break;
      if (uVar7 != uVar11) {
        OpenSSLDie(DAT_0007902c,400,DAT_00079030);
      }
      if (uVar7 == param_1->init_num) {
        if (param_1->msg_callback != (_func_3292 *)0x0) {
          (*param_1->msg_callback)
                    (1,param_1->version,0x14,param_1->init_buf->data,uVar7 + param_1->init_off,
                     param_1,param_1->msg_callback_arg);
        }
        param_1->init_off = 0;
        param_1->init_num = 0;
        return 1;
      }
      iVar9 = param_1->init_num - uVar7;
      param_1->init_num = iVar9;
      param_1->init_off = param_1->init_off + uVar7;
    }
    if (!bVar2) {
      return 0xffffffff;
    }
    pBVar3 = SSL_get_wbio(param_1);
    lVar4 = BIO_ctrl(pBVar3,0x2b,0,(void *)0x0);
    if (lVar4 < 1) break;
    uVar11 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar11 & 0x1000) != 0) {
      return 0xffffffff;
    }
    pdVar10 = param_1->d1;
    iVar9 = *(int *)&pdVar10->w_msg_hdr;
    if (iVar9 != 0) {
      pBVar3 = SSL_get_wbio(param_1);
      lVar4 = BIO_ctrl(pBVar3,0x31,0,(void *)0x0);
      (pdVar10->w_msg_hdr).msg_len = iVar9 - lVar4;
      pdVar10 = param_1->d1;
      *(undefined4 *)&pdVar10->w_msg_hdr = 0;
    }
    uVar11 = (pdVar10->w_msg_hdr).msg_len;
    pBVar3 = SSL_get_wbio(param_1);
    lVar4 = BIO_ctrl(pBVar3,0x31,0,(void *)0x0);
    if (uVar11 < 0x100U - lVar4) {
      uVar11 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
      if ((uVar11 & 0x1000) != 0) {
        return 0xffffffff;
      }
      iVar9 = dtls1_query_mtu_part_0(param_1);
      if (iVar9 == 0) {
        return 0xffffffff;
      }
      iVar9 = param_1->init_num;
      bVar2 = false;
    }
    else {
      iVar9 = param_1->init_num;
      bVar2 = false;
    }
  }
  return 0xffffffff;
}

