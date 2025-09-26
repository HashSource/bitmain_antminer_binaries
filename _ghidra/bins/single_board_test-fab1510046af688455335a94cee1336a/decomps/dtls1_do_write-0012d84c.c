
/* WARNING: Type propagation algorithm not settling */

long dtls1_do_write(SSL *param_1,int param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  BIO *pBVar3;
  long lVar4;
  ulong uVar5;
  EVP_MD *md;
  char *pcVar6;
  uint uVar7;
  EVP_MD_CTX *ctx;
  int iVar8;
  uint uVar9;
  dtls1_state_st *pdVar10;
  uint uVar11;
  char *pcVar12;
  int iVar13;
  EVP_CIPHER_CTX *pEVar14;
  uint local_30;
  int local_2c;
  
  pdVar10 = param_1->d1;
  iVar13 = *(int *)&pdVar10->w_msg_hdr;
  if (iVar13 != 0) {
    pBVar3 = SSL_get_wbio(param_1);
    lVar4 = BIO_ctrl(pBVar3,0x31,0,(void *)0x0);
    (pdVar10->w_msg_hdr).msg_len = iVar13 - lVar4;
    pdVar10 = param_1->d1;
    *(undefined4 *)&pdVar10->w_msg_hdr = 0;
  }
  uVar11 = (pdVar10->w_msg_hdr).msg_len;
  pBVar3 = SSL_get_wbio(param_1);
  lVar4 = BIO_ctrl(pBVar3,0x31,0,(void *)0x0);
  if ((uVar11 < 0x100U - lVar4) &&
     ((lVar4 = SSL_ctrl(param_1,0x20,0,(void *)0x0), lVar4 << 0x13 < 0 ||
      (iVar13 = dtls1_query_mtu_part_0(param_1), iVar13 == 0)))) {
    return -1;
  }
  uVar11 = (param_1->d1->w_msg_hdr).msg_len;
  pBVar3 = SSL_get_wbio(param_1);
  lVar4 = BIO_ctrl(pBVar3,0x31,0,(void *)0x0);
  if (uVar11 < 0x100U - lVar4) {
    OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu(s)");
  }
  if (((param_1->init_off == 0) && (param_2 == 0x16)) &&
     (param_1->init_num != (param_1->d1->w_msg_hdr).frag_off + 0xc)) {
    OpenSSLDie("d1_both.c",0x118,
               "s->init_num == (int)s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH");
  }
  ctx = param_1->write_hash;
  if (ctx == (EVP_MD_CTX *)0x0) {
LAB_0012dc08:
    iVar13 = 0;
  }
  else {
    if (param_1->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
      uVar5 = EVP_CIPHER_CTX_flags(param_1->enc_write_ctx);
      if ((uVar5 & 0xf0007) == 6) goto LAB_0012dc08;
      ctx = param_1->write_hash;
    }
    md = EVP_MD_CTX_md(ctx);
    iVar13 = EVP_MD_size(md);
  }
  if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar5 = EVP_CIPHER_CTX_flags(param_1->enc_write_ctx), (uVar5 & 0xf0007) != 2)) {
    local_2c = 0;
  }
  else {
    local_2c = EVP_CIPHER_block_size(param_1->enc_write_ctx->cipher);
    local_2c = local_2c << 1;
  }
  iVar8 = param_1->init_num;
  uVar1 = true;
  local_30 = 0;
  do {
    if (iVar8 < 1) {
      return 0;
    }
    pBVar3 = SSL_get_wbio(param_1);
    lVar4 = BIO_ctrl(pBVar3,0xd,0,(void *)0x0);
    uVar11 = lVar4 + iVar13 + 0xd + local_2c;
    uVar9 = (param_1->d1->w_msg_hdr).msg_len;
    if ((uVar9 <= uVar11) || (uVar9 = uVar9 - uVar11, uVar9 < 0xd)) {
      pBVar3 = SSL_get_wbio(param_1);
      lVar4 = BIO_ctrl(pBVar3,0xb,0,(void *)0x0);
      if (lVar4 < 1) {
        return lVar4;
      }
      uVar11 = (param_1->d1->w_msg_hdr).msg_len;
      if (uVar11 <= local_2c + iVar13 + 0x19U) {
        return -1;
      }
      uVar9 = (uVar11 - 0xd) - (local_2c + iVar13);
    }
    uVar7 = param_1->init_num;
    uVar11 = uVar9;
    if (uVar7 <= uVar9) {
      uVar11 = uVar7;
    }
    if ((int)uVar11 < 0) {
      uVar11 = 0x7fffffff;
    }
    if (param_2 == 0x16) {
      iVar8 = param_1->init_off;
      if (iVar8 == 0) {
LAB_0012da6e:
        if (uVar11 < 0xc) {
          return -1;
        }
        pEVar14 = (EVP_CIPHER_CTX *)(uVar11 - 0xc);
      }
      else {
        if (iVar8 < 0xd) {
          OpenSSLDie("d1_both.c",0x154,"s->init_off > DTLS1_HM_HEADER_LENGTH");
          iVar8 = param_1->init_off;
          uVar7 = param_1->init_num;
        }
        uVar7 = uVar7 + 0xc;
        iVar8 = iVar8 + -0xc;
        uVar11 = uVar7;
        if (uVar9 <= uVar7) {
          uVar11 = uVar9;
        }
        param_1->init_num = uVar7;
        param_1->init_off = iVar8;
        if (-1 < (int)uVar11) goto LAB_0012da6e;
        uVar11 = 0x7fffffff;
        pEVar14 = (EVP_CIPHER_CTX *)0x7ffffff3;
      }
      pdVar10 = param_1->d1;
      uVar2 = (pdVar10->w_msg_hdr).seq;
      pcVar6 = param_1->init_buf->data;
      (pdVar10->w_msg_hdr).is_ccs = local_30;
      (pdVar10->w_msg_hdr).saved_retransmit_state.enc_write_ctx = pEVar14;
      pcVar6[iVar8] = (char)uVar2;
      pcVar6[iVar8 + 1] = (char)*(undefined2 *)((int)&(pdVar10->w_msg_hdr).frag_off + 2);
      pcVar6[iVar8 + 2] = (char)((pdVar10->w_msg_hdr).frag_off >> 8);
      pcVar6[iVar8 + 3] = (char)(pdVar10->w_msg_hdr).frag_off;
      pcVar6[iVar8 + 4] = (char)((ushort)(short)(pdVar10->w_msg_hdr).frag_len >> 8);
      pcVar6[iVar8 + 5] = (char)(short)(pdVar10->w_msg_hdr).frag_len;
      pcVar6[iVar8 + 6] = (char)*(undefined2 *)((int)&(pdVar10->w_msg_hdr).is_ccs + 2);
      pcVar6[iVar8 + 7] = (char)((pdVar10->w_msg_hdr).is_ccs >> 8);
      pcVar6[iVar8 + 8] = (char)(pdVar10->w_msg_hdr).is_ccs;
      pcVar6[iVar8 + 9] =
           (char)*(undefined2 *)
                  ((int)&(pdVar10->w_msg_hdr).saved_retransmit_state.enc_write_ctx + 2);
      pcVar6[iVar8 + 10] =
           (char)((uint)(pdVar10->w_msg_hdr).saved_retransmit_state.enc_write_ctx >> 8);
      pcVar6[iVar8 + 0xb] = (char)(pdVar10->w_msg_hdr).saved_retransmit_state.enc_write_ctx;
    }
    uVar9 = dtls1_write_bytes(param_1,param_2,param_1->init_buf->data + param_1->init_off,uVar11);
    if ((int)uVar9 < 0) {
      if (!(bool)uVar1) {
        return -1;
      }
      pBVar3 = SSL_get_wbio(param_1);
      lVar4 = BIO_ctrl(pBVar3,0x2b,0,(void *)0x0);
      if (lVar4 < 1) {
        return -1;
      }
      uVar11 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
      if ((uVar11 & 0x1000) != 0) {
        return -1;
      }
      pdVar10 = param_1->d1;
      iVar8 = *(int *)&pdVar10->w_msg_hdr;
      if (iVar8 != 0) {
        pBVar3 = SSL_get_wbio(param_1);
        lVar4 = BIO_ctrl(pBVar3,0x31,0,(void *)0x0);
        (pdVar10->w_msg_hdr).msg_len = iVar8 - lVar4;
        pdVar10 = param_1->d1;
        *(undefined4 *)&pdVar10->w_msg_hdr = 0;
      }
      uVar11 = (pdVar10->w_msg_hdr).msg_len;
      pBVar3 = SSL_get_wbio(param_1);
      lVar4 = BIO_ctrl(pBVar3,0x31,0,(void *)0x0);
      if (uVar11 < 0x100U - lVar4) {
        uVar11 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
        if ((uVar11 & 0x1000) != 0) {
          return -1;
        }
        iVar8 = dtls1_query_mtu_part_0(param_1);
        if (iVar8 == 0) {
          return -1;
        }
        iVar8 = param_1->init_num;
        uVar1 = false;
      }
      else {
        iVar8 = param_1->init_num;
        uVar1 = false;
      }
    }
    else {
      if (uVar9 != uVar11) {
        OpenSSLDie("d1_both.c",400,"len == (unsigned int)ret");
      }
      if ((param_2 == 0x16) && (pdVar10 = param_1->d1, pdVar10->listen == 0)) {
        pcVar12 = param_1->init_buf->data;
        pcVar6 = pcVar12 + param_1->init_off;
        if ((local_30 == 0) && (param_1->version != 0x100)) {
          pcVar12[param_1->init_off] = (char)(pdVar10->w_msg_hdr).seq;
          pcVar6[1] = (char)*(undefined2 *)((int)&(pdVar10->w_msg_hdr).frag_off + 2);
          pcVar6[2] = (char)((pdVar10->w_msg_hdr).frag_off >> 8);
          pcVar6[3] = (char)(pdVar10->w_msg_hdr).frag_off;
          pcVar6[4] = (char)((ushort)(short)(pdVar10->w_msg_hdr).frag_len >> 8);
          uVar5 = (pdVar10->w_msg_hdr).frag_len;
          pcVar6[6] = '\0';
          pcVar6[7] = '\0';
          pcVar6[5] = (char)(short)uVar5;
          pcVar6[8] = '\0';
          pcVar6[9] = (char)*(undefined2 *)((int)&(pdVar10->w_msg_hdr).frag_off + 2);
          pcVar6[10] = (char)((pdVar10->w_msg_hdr).frag_off >> 8);
          pcVar6[0xb] = (char)(pdVar10->w_msg_hdr).frag_off;
          uVar11 = uVar9;
        }
        else {
          pcVar6 = pcVar6 + 0xc;
          uVar11 = uVar9 - 0xc;
        }
        ssl3_finish_mac(param_1,pcVar6,uVar11);
        uVar11 = param_1->init_num;
      }
      else {
        uVar11 = param_1->init_num;
      }
      if (uVar11 == uVar9) {
        if (param_1->msg_callback != (_func_3292 *)0x0) {
          (*param_1->msg_callback)
                    (1,param_1->version,param_2,param_1->init_buf->data,param_1->init_off + uVar9,
                     param_1,param_1->msg_callback_arg);
        }
        param_1->init_off = 0;
        param_1->init_num = 0;
        return 1;
      }
      iVar8 = uVar11 - uVar9;
      param_1->init_num = iVar8;
      local_30 = local_30 + (uVar9 - 0xc);
      param_1->init_off = param_1->init_off + uVar9;
    }
  } while( true );
}

