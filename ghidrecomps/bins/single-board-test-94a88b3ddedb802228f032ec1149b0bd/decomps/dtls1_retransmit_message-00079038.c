
undefined4
dtls1_retransmit_message(SSL *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort uVar3;
  pitem *ppVar4;
  BIO *bp;
  dtls1_state_st *pdVar5;
  undefined4 uVar6;
  ulong uVar7;
  EVP_CIPHER_CTX *pEVar8;
  COMP_CTX *pCVar9;
  undefined4 uVar10;
  dtls1_state_st *pdVar11;
  COMP_CTX *pCVar12;
  EVP_MD_CTX *pEVar13;
  SSL_SESSION *pSVar14;
  ssl3_state_st *psVar15;
  undefined *puVar16;
  uint uVar17;
  int iVar18;
  SSL_SESSION *pSVar19;
  EVP_MD_CTX *pEVar20;
  EVP_CIPHER_CTX *pEVar21;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  local_38 = 0;
  local_34 = (uint)CONCAT11((char)param_2,(char)((uint)param_2 >> 8)) << 0x10;
  ppVar4 = pqueue_find(param_1->d1->sent_messages,(uchar *)&local_38);
  if (ppVar4 == (pitem *)0x0) {
    fprintf(*DAT_00079190,DAT_00079194,param_2);
    *param_4 = 0;
    uVar6 = 0;
  }
  else {
    puVar16 = (undefined *)ppVar4->data;
    *param_4 = 1;
    if (*(int *)(puVar16 + 0x14) == 0) {
      iVar18 = 0xc;
    }
    else {
      iVar18 = 1;
    }
    memcpy(param_1->init_buf->data,*(void **)(puVar16 + 0x2c),iVar18 + *(int *)(puVar16 + 4));
    uVar7 = *(ulong *)(puVar16 + 4);
    uVar2 = *(undefined2 *)(puVar16 + 8);
    pdVar11 = param_1->d1;
    uVar1 = *(ushort *)(puVar16 + 0x28);
    param_1->init_num = iVar18 + uVar7;
    *(undefined *)&(pdVar11->w_msg_hdr).seq = *puVar16;
    pdVar5 = param_1->d1;
    pEVar21 = param_1->enc_write_ctx;
    pEVar20 = param_1->write_hash;
    uVar3 = pdVar5->w_epoch;
    (pdVar11->w_msg_hdr).frag_off = uVar7;
    pEVar8 = *(EVP_CIPHER_CTX **)(puVar16 + 0x10);
    (pdVar11->w_msg_hdr).is_ccs = 0;
    uVar17 = uVar3 - 1;
    *(undefined2 *)&(pdVar11->w_msg_hdr).frag_len = uVar2;
    (pdVar11->w_msg_hdr).saved_retransmit_state.enc_write_ctx = pEVar8;
    pCVar12 = param_1->compress;
    pEVar8 = *(EVP_CIPHER_CTX **)(puVar16 + 0x18);
    pSVar19 = param_1->session;
    pEVar13 = *(EVP_MD_CTX **)(puVar16 + 0x1c);
    pdVar5->listen = 1;
    param_1->enc_write_ctx = pEVar8;
    param_1->write_hash = pEVar13;
    pCVar9 = *(COMP_CTX **)(puVar16 + 0x20);
    pSVar14 = *(SSL_SESSION **)(puVar16 + 0x24);
    param_1->compress = pCVar9;
    param_1->session = pSVar14;
    pdVar5->w_epoch = uVar1;
    if (uVar1 == uVar17) {
      psVar15 = param_1->s3;
      uVar6 = *(undefined4 *)(pdVar5->last_write_sequence + 4);
      pCVar9 = (COMP_CTX *)psVar15->write_sequence;
      local_30 = *(undefined4 *)pCVar9;
      uStack_2c = *(undefined4 *)(psVar15->write_sequence + 4);
      *(undefined4 *)psVar15->write_sequence = *(undefined4 *)pdVar5->last_write_sequence;
      *(undefined4 *)(psVar15->write_sequence + 4) = uVar6;
      pSVar14 = (SSL_SESSION *)&stack0xffffffd8;
    }
    if (*(int *)(puVar16 + 0x14) == 0) {
      uVar6 = 0x16;
    }
    else {
      uVar6 = 0x14;
    }
    uVar6 = dtls1_do_write(param_1,uVar6,pCVar9,pSVar14);
    uVar1 = *(ushort *)(puVar16 + 0x28);
    pdVar5 = param_1->d1;
    param_1->enc_write_ctx = pEVar21;
    param_1->write_hash = pEVar20;
    param_1->compress = pCVar12;
    param_1->session = pSVar19;
    pdVar5->w_epoch = uVar3;
    if (uVar17 == uVar1) {
      uVar10 = *(undefined4 *)(param_1->s3->write_sequence + 4);
      *(undefined4 *)pdVar5->last_write_sequence = *(undefined4 *)param_1->s3->write_sequence;
      *(undefined4 *)(pdVar5->last_write_sequence + 4) = uVar10;
      psVar15 = param_1->s3;
      *(undefined4 *)psVar15->write_sequence = local_30;
      *(undefined4 *)(psVar15->write_sequence + 4) = uStack_2c;
      pdVar5 = param_1->d1;
    }
    pdVar5->listen = 0;
    bp = SSL_get_wbio(param_1);
    BIO_ctrl(bp,0xb,0,(void *)0x0);
  }
  return uVar6;
}

