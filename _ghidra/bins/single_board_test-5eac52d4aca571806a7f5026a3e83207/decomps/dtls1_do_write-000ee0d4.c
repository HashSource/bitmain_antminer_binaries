
/* WARNING: Type propagation algorithm not settling */

ENGINE * dtls1_do_write(SSL *param_1,int param_2)

{
  undefined2 uVar1;
  bool bVar2;
  int iVar3;
  ENGINE *pEVar4;
  EVP_CIPHER *pEVar5;
  ulong uVar6;
  long lVar7;
  int iVar8;
  EVP_MD *md;
  BIO *bp;
  uint uVar9;
  int iVar10;
  EVP_CIPHER_CTX *pEVar11;
  EVP_MD_CTX *ctx;
  stack_st_SSL_CIPHER *psVar12;
  ENGINE *pEVar13;
  int iVar14;
  int local_34;
  ENGINE *local_2c [2];
  
  iVar3 = dtls1_query_mtu();
  if (((iVar3 == 0) ||
      (pEVar13 = param_1->enc_read_ctx[2].engine, pEVar4 = (ENGINE *)dtls1_min_mtu(param_1),
      pEVar13 < pEVar4)) ||
     ((param_1->cipher_list_by_id == (stack_st_SSL_CIPHER *)0x0 && param_2 == 0x16 &&
      (param_1->cipher_list != (stack_st_SSL_CIPHER *)(param_1->enc_read_ctx[2].buf_len + 0xc))))) {
    return (ENGINE *)0xffffffff;
  }
  ctx = (EVP_MD_CTX *)param_1[2].info_callback;
  if (ctx == (EVP_MD_CTX *)0x0) {
LAB_000ee126:
    iVar3 = 0;
  }
  else {
    if (*(EVP_CIPHER_CTX **)(param_1[2].sid_ctx + 0x1c) != (EVP_CIPHER_CTX *)0x0) {
      pEVar5 = EVP_CIPHER_CTX_cipher(*(EVP_CIPHER_CTX **)(param_1[2].sid_ctx + 0x1c));
      uVar6 = EVP_CIPHER_flags(pEVar5);
      if ((int)(uVar6 << 10) < 0) goto LAB_000ee126;
      ctx = (EVP_MD_CTX *)param_1[2].info_callback;
    }
    md = EVP_MD_CTX_md(ctx);
    iVar3 = EVP_MD_size(md);
  }
  if (*(EVP_CIPHER_CTX **)(param_1[2].sid_ctx + 0x1c) != (EVP_CIPHER_CTX *)0x0) {
    pEVar5 = EVP_CIPHER_CTX_cipher(*(EVP_CIPHER_CTX **)(param_1[2].sid_ctx + 0x1c));
    uVar6 = EVP_CIPHER_flags(pEVar5);
    if ((uVar6 & 0xf0007) == 2) {
      local_34 = EVP_CIPHER_CTX_block_size(*(EVP_CIPHER_CTX **)(param_1[2].sid_ctx + 0x1c));
      local_34 = local_34 << 1;
      goto LAB_000ee14a;
    }
  }
  local_34 = 0;
LAB_000ee14a:
  pEVar4 = (ENGINE *)param_1->cipher_list;
  param_1->bbio = (BIO *)0x1;
  bVar2 = true;
  iVar14 = 0;
  do {
    while( true ) {
      if (pEVar4 == (ENGINE *)0x0) {
        return (ENGINE *)0x0;
      }
      if ((param_2 == 0x16) &&
         (psVar12 = param_1->cipher_list_by_id, psVar12 != (stack_st_SSL_CIPHER *)0x0)) {
        if (iVar14 == 0) {
          iVar14 = *(int *)(param_1->enc_read_ctx[2].oiv + 4);
        }
        else {
          if (psVar12 < (stack_st_SSL_CIPHER *)0xd) {
            return (ENGINE *)0xffffffff;
          }
          param_1->cipher_list_by_id = (stack_st_SSL_CIPHER *)&psVar12[-1].stack.sorted;
          param_1->cipher_list = (stack_st_SSL_CIPHER *)(pEVar4 + 0xc);
        }
      }
      lVar7 = BIO_ctrl(param_1->rbio,0xd,0,(void *)0x0);
      pEVar4 = (ENGINE *)(lVar7 + iVar3 + 0xd + local_34);
      pEVar13 = param_1->enc_read_ctx[2].engine;
      if ((pEVar13 <= pEVar4) || (pEVar13 = pEVar13 + -(int)pEVar4, pEVar13 < (ENGINE *)0xd)) {
        pEVar4 = (ENGINE *)BIO_ctrl(param_1->rbio,0xb,0,(void *)0x0);
        if ((int)pEVar4 < 1) {
          param_1->bbio = (BIO *)0x2;
          return pEVar4;
        }
        pEVar13 = param_1->enc_read_ctx[2].engine;
        if (pEVar13 <= (ENGINE *)(iVar3 + local_34 + 0x19)) {
          return (ENGINE *)0xffffffff;
        }
        pEVar13 = pEVar13 + (-0xd - (iVar3 + local_34));
      }
      if ((ENGINE *)param_1->cipher_list <= pEVar13) {
        pEVar13 = (ENGINE *)param_1->cipher_list;
      }
      pEVar4 = (ENGINE *)ssl_get_max_send_fragment(param_1);
      if (pEVar4 < pEVar13) {
        pEVar13 = (ENGINE *)ssl_get_max_send_fragment(param_1);
      }
      if (param_2 == 0x16) {
        if (pEVar13 < (ENGINE *)0xc) {
          return (ENGINE *)0xffffffff;
        }
        pEVar11 = param_1->enc_read_ctx;
        psVar12 = param_1->cipher_list_by_id;
        iVar8 = pEVar11[2].encrypt;
        iVar10 = *(int *)(param_1->hit + 4);
        *(int *)(pEVar11[2].oiv + 4) = iVar14;
        *(ENGINE **)(pEVar11[2].oiv + 8) = pEVar13 + -0xc;
        *(char *)((int)&(psVar12->stack).num + iVar10) = (char)iVar8;
        *(char *)((int)&(psVar12->stack).num + iVar10 + 1) =
             (char)*(undefined2 *)((int)&pEVar11[2].buf_len + 2);
        *(char *)((int)&(psVar12->stack).num + iVar10 + 2) = (char)((uint)pEVar11[2].buf_len >> 8);
        *(char *)((int)&(psVar12->stack).num + iVar10 + 3) = (char)pEVar11[2].buf_len;
        *(char *)((int)&(psVar12->stack).data + iVar10) =
             (char)((ushort)*(undefined2 *)pEVar11[2].oiv >> 8);
        *(char *)((int)&(psVar12->stack).data + iVar10 + 1) = (char)*(undefined2 *)pEVar11[2].oiv;
        *(char *)((int)&(psVar12->stack).data + iVar10 + 2) =
             (char)*(undefined2 *)(pEVar11[2].oiv + 6);
        *(char *)((int)&(psVar12->stack).data + iVar10 + 3) =
             (char)((uint)*(undefined4 *)(pEVar11[2].oiv + 4) >> 8);
        *(char *)((int)&(psVar12->stack).sorted + iVar10) =
             (char)*(undefined4 *)(pEVar11[2].oiv + 4);
        *(char *)((int)&(psVar12->stack).sorted + iVar10 + 1) =
             (char)*(undefined2 *)(pEVar11[2].oiv + 10);
        *(char *)((int)&(psVar12->stack).sorted + iVar10 + 2) =
             (char)((uint)*(undefined4 *)(pEVar11[2].oiv + 8) >> 8);
        *(char *)((int)&(psVar12->stack).sorted + iVar10 + 3) =
             (char)*(undefined4 *)(pEVar11[2].oiv + 8);
      }
      iVar8 = dtls1_write_bytes(param_1,param_2,
                                (int)&(param_1->cipher_list_by_id->stack).num +
                                *(int *)(param_1->hit + 4),pEVar13,local_2c);
      if (0 < iVar8) break;
      if (!bVar2) {
        return (ENGINE *)0xffffffff;
      }
      bp = SSL_get_wbio(param_1);
      lVar7 = BIO_ctrl(bp,0x2b,0,(void *)0x0);
      if (lVar7 < 1) {
        return (ENGINE *)0xffffffff;
      }
      uVar9 = SSL_get_options(param_1);
      if ((uVar9 & 0x1000) != 0) {
        return (ENGINE *)0xffffffff;
      }
      iVar8 = dtls1_query_mtu(param_1);
      if (iVar8 == 0) {
        return (ENGINE *)0xffffffff;
      }
      pEVar4 = (ENGINE *)param_1->cipher_list;
      bVar2 = false;
    }
    if (pEVar13 != local_2c[0]) {
      return (ENGINE *)0xffffffff;
    }
    if ((param_2 == 0x16) &&
       (pEVar11 = param_1->enc_read_ctx, *(int *)(pEVar11[2].final + 0xc) == 0)) {
      iVar10 = *(int *)(param_1->hit + 4);
      iVar8 = (int)&(param_1->cipher_list_by_id->stack).num + iVar10;
      if ((iVar14 == 0) && (param_1->version != 0x100)) {
        *(char *)((int)&(param_1->cipher_list_by_id->stack).num + iVar10) = (char)pEVar11[2].encrypt
        ;
        *(char *)(iVar8 + 1) = (char)*(undefined2 *)((int)&pEVar11[2].buf_len + 2);
        *(char *)(iVar8 + 2) = (char)((uint)pEVar11[2].buf_len >> 8);
        *(char *)(iVar8 + 3) = (char)pEVar11[2].buf_len;
        *(char *)(iVar8 + 4) = (char)((ushort)*(undefined2 *)pEVar11[2].oiv >> 8);
        uVar1 = *(undefined2 *)pEVar11[2].oiv;
        *(undefined1 *)(iVar8 + 6) = 0;
        *(undefined1 *)(iVar8 + 7) = 0;
        *(char *)(iVar8 + 5) = (char)uVar1;
        *(undefined1 *)(iVar8 + 8) = 0;
        *(char *)(iVar8 + 9) = (char)*(undefined2 *)((int)&pEVar11[2].buf_len + 2);
        *(char *)(iVar8 + 10) = (char)((uint)pEVar11[2].buf_len >> 8);
        *(char *)(iVar8 + 0xb) = (char)pEVar11[2].buf_len;
        pEVar13 = local_2c[0];
      }
      else {
        iVar8 = iVar8 + 0xc;
        pEVar13 = pEVar13 + -0xc;
      }
      iVar8 = ssl3_finish_mac(param_1,iVar8,pEVar13);
      if (iVar8 == 0) {
        return (ENGINE *)0xffffffff;
      }
      pEVar4 = (ENGINE *)param_1->cipher_list;
      pEVar13 = local_2c[0];
      if (pEVar4 == local_2c[0]) {
LAB_000ee390:
        if (param_1->read_hash != (EVP_MD_CTX *)0x0) {
          (*(code *)param_1->read_hash)
                    (1,param_1->version,param_2,*(undefined4 *)(param_1->hit + 4),
                     pEVar13 + (int)param_1->cipher_list_by_id,param_1,param_1->expand);
        }
        param_1->cipher_list_by_id = (stack_st_SSL_CIPHER *)0x0;
        param_1->cipher_list = (stack_st_SSL_CIPHER *)0x0;
        return (ENGINE *)0x1;
      }
    }
    else {
      pEVar4 = (ENGINE *)param_1->cipher_list;
      if (pEVar4 == pEVar13) goto LAB_000ee390;
    }
    local_2c[0] = pEVar13 + -0xc;
    pEVar11 = param_1->enc_read_ctx;
    pEVar4 = pEVar4 + -(int)pEVar13;
    iVar14 = iVar14 + (int)local_2c[0];
    param_1->cipher_list = (stack_st_SSL_CIPHER *)pEVar4;
    param_1->cipher_list_by_id = (stack_st_SSL_CIPHER *)(pEVar13 + (int)param_1->cipher_list_by_id);
    *(int *)(pEVar11[2].oiv + 4) = iVar14;
    pEVar11[2].oiv[8] = '\0';
    pEVar11[2].oiv[9] = '\0';
    pEVar11[2].oiv[10] = '\0';
    pEVar11[2].oiv[0xb] = '\0';
  } while( true );
}

