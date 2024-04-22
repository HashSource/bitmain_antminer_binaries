
/* WARNING: Type propagation algorithm not settling */

int dtls1_get_record(SSL *param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  pitem *ppVar5;
  uchar *puVar6;
  pqueue pq;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uchar *puVar10;
  SSL3_RECORD *pSVar11;
  ssl3_state_st *psVar12;
  undefined4 uVar13;
  dtls1_state_st *pdVar14;
  uchar **ppuVar15;
  ulong uVar16;
  ssl3_state_st *psVar17;
  uchar **ppuVar18;
  byte *buf;
  uint uVar19;
  DTLS1_BITMAP *pDVar20;
  uint uVar21;
  uint uVar22;
  uchar *puVar23;
  uchar *puVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  
  psVar17 = param_1->s3;
  ppVar5 = pqueue_peek((param_1->d1->unprocessed_rcds).q);
  if (ppVar5 != (pitem *)0x0) {
    pdVar14 = param_1->d1;
    if ((pdVar14->unprocessed_rcds).epoch != pdVar14->r_epoch) {
LAB_00076cd8:
      ppVar5 = pqueue_pop((pdVar14->processed_rcds).q);
      goto joined_r0x00076e66;
    }
    while (ppVar5 = pqueue_peek((pdVar14->unprocessed_rcds).q), ppVar5 != (pitem *)0x0) {
      ppVar5 = pqueue_pop((param_1->d1->unprocessed_rcds).q);
      if (ppVar5 != (pitem *)0x0) {
        psVar12 = param_1->s3;
        ppuVar18 = (uchar **)ppVar5->data;
        puVar6 = (psVar12->rbuf).buf;
        if (puVar6 != (uchar *)0x0) {
          CRYPTO_free(puVar6);
          psVar12 = param_1->s3;
        }
        ppuVar15 = ppuVar18 + 6;
        param_1->packet = *ppuVar18;
        param_1->packet_length = (uint)ppuVar18[1];
        puVar23 = ppuVar18[3];
        puVar10 = ppuVar18[4];
        puVar6 = ppuVar18[5];
        (psVar12->rbuf).buf = ppuVar18[2];
        (psVar12->rbuf).len = (size_t)puVar23;
        (psVar12->rbuf).offset = (int)puVar10;
        (psVar12->rbuf).left = (int)puVar6;
        pSVar11 = &param_1->s3->rrec;
        do {
          puVar24 = *ppuVar15;
          puVar23 = ppuVar15[1];
          puVar6 = ppuVar15[2];
          puVar10 = ppuVar15[3];
          ppuVar15 = ppuVar15 + 4;
          pSVar11->type = (int)puVar24;
          pSVar11->length = (uint)puVar23;
          pSVar11->off = (uint)puVar6;
          pSVar11->data = puVar10;
          pSVar11 = (SSL3_RECORD *)&pSVar11->input;
        } while (ppuVar15 != ppuVar18 + 0xe);
        *(uchar **)pSVar11 = *ppuVar15;
        puVar6 = *ppuVar18;
        psVar12 = param_1->s3;
        *(undefined4 *)(psVar12->read_sequence + 2) = *(undefined4 *)(puVar6 + 5);
        *(undefined2 *)(psVar12->read_sequence + 6) = *(undefined2 *)(puVar6 + 9);
        CRYPTO_free(ppVar5->data);
        pitem_free(ppVar5);
      }
      iVar7 = dtls1_process_record(param_1);
      if (iVar7 == 0) {
        pdVar14 = param_1->d1;
        goto LAB_00076cd8;
      }
      pdVar14 = param_1->d1;
      psVar12 = param_1->s3;
      iVar7 = pqueue_size((pdVar14->processed_rcds).q);
      if ((iVar7 < 100) &&
         (iVar7 = dtls1_buffer_record_part_1
                            (param_1,&pdVar14->processed_rcds,(psVar12->rrec).seq_num), iVar7 < 0))
      {
        return 0xffffffff;
      }
      pdVar14 = param_1->d1;
    }
  }
  pdVar14 = param_1->d1;
  uVar3 = pdVar14->r_epoch;
  pq = (pdVar14->processed_rcds).q;
  (pdVar14->processed_rcds).epoch = uVar3;
  (pdVar14->unprocessed_rcds).epoch = uVar3 + 1;
  ppVar5 = pqueue_pop(pq);
joined_r0x00076e66:
  if (ppVar5 != (pitem *)0x0) {
    psVar17 = param_1->s3;
    ppuVar18 = (uchar **)ppVar5->data;
    puVar6 = (psVar17->rbuf).buf;
    if (puVar6 != (uchar *)0x0) {
      CRYPTO_free(puVar6);
      psVar17 = param_1->s3;
    }
    ppuVar15 = ppuVar18 + 6;
    param_1->packet = *ppuVar18;
    param_1->packet_length = (uint)ppuVar18[1];
    puVar23 = ppuVar18[3];
    puVar6 = ppuVar18[4];
    puVar10 = ppuVar18[5];
    (psVar17->rbuf).buf = ppuVar18[2];
    (psVar17->rbuf).len = (size_t)puVar23;
    (psVar17->rbuf).offset = (int)puVar6;
    (psVar17->rbuf).left = (int)puVar10;
    pSVar11 = &param_1->s3->rrec;
    do {
      puVar24 = *ppuVar15;
      puVar23 = ppuVar15[1];
      puVar6 = ppuVar15[2];
      puVar10 = ppuVar15[3];
      ppuVar15 = ppuVar15 + 4;
      pSVar11->type = (int)puVar24;
      pSVar11->length = (uint)puVar23;
      pSVar11->off = (uint)puVar6;
      pSVar11->data = puVar10;
      pSVar11 = (SSL3_RECORD *)&pSVar11->input;
    } while (ppuVar15 != ppuVar18 + 0xe);
    *(uchar **)pSVar11 = *ppuVar15;
    puVar6 = *ppuVar18;
    psVar17 = param_1->s3;
    *(undefined4 *)(psVar17->read_sequence + 2) = *(undefined4 *)(puVar6 + 5);
    *(undefined2 *)(psVar17->read_sequence + 6) = *(undefined2 *)(puVar6 + 9);
    CRYPTO_free(ppVar5->data);
    pitem_free(ppVar5);
    return 1;
  }
LAB_00076eaa:
  if ((param_1->rstate == 0xf1) && (0xc < param_1->packet_length)) {
    uVar19 = (psVar17->rrec).length;
    if (param_1->packet_length - 0xd < uVar19) {
LAB_00076f56:
      uVar8 = ssl3_read_n(param_1,uVar19,uVar19,1);
      if (uVar8 != uVar19) goto LAB_00076ea4;
    }
LAB_00076e82:
    pdVar14 = param_1->d1;
    uVar16 = (psVar17->rrec).epoch;
    param_1->rstate = 0xf0;
    if (uVar16 == pdVar14->r_epoch) {
      pDVar20 = &pdVar14->bitmap;
      bVar4 = false;
    }
    else {
      if ((uVar16 != pdVar14->r_epoch + 1) || (1 < (psVar17->rrec).type - 0x15U)) goto LAB_00076ea4;
      pDVar20 = &pdVar14->next_bitmap;
      bVar4 = true;
    }
    if ((((pdVar14->mtu == 0) || ((psVar17->rrec).type != 0x16)) || (param_1->packet_length < 0xe))
       || (param_1->packet[0xd] != '\x01')) {
      psVar12 = param_1->s3;
      uVar19 = (uint)psVar12->read_sequence[7] - (uint)pDVar20->max_seq_num[7];
      if ((uVar19 & 0x80) == 0) {
        uVar9 = ((int)uVar19 >> 8) +
                ((uint)psVar12->read_sequence[6] - (uint)pDVar20->max_seq_num[6]);
        uVar25 = ((uint)psVar12->read_sequence[5] - (uint)pDVar20->max_seq_num[5]) +
                 ((int)uVar9 >> 8);
        uVar22 = ((uint)psVar12->read_sequence[4] - (uint)pDVar20->max_seq_num[4]) +
                 ((int)uVar25 >> 8);
        uVar21 = ((uint)psVar12->read_sequence[3] - (uint)pDVar20->max_seq_num[3]) +
                 ((int)uVar22 >> 8);
        uVar27 = ((uint)psVar12->read_sequence[2] - (uint)pDVar20->max_seq_num[2]) +
                 ((int)uVar21 >> 8);
        uVar26 = ((uint)psVar12->read_sequence[1] - (uint)pDVar20->max_seq_num[1]) +
                 ((int)uVar27 >> 8);
        uVar8 = ((uint)psVar12->read_sequence[0] - (uint)pDVar20->max_seq_num[0]) +
                ((int)uVar26 >> 8);
        uVar9 = uVar25 | uVar9 | uVar22 | uVar21 | uVar27 | uVar26 | uVar8;
      }
      else {
        uVar9 = ((int)uVar19 >> 8) +
                ((uint)psVar12->read_sequence[6] - (uint)pDVar20->max_seq_num[6]);
        uVar26 = ((uint)psVar12->read_sequence[5] - (uint)pDVar20->max_seq_num[5]) +
                 ((int)uVar9 >> 8);
        uVar27 = ((uint)psVar12->read_sequence[4] - (uint)pDVar20->max_seq_num[4]) +
                 ((int)uVar26 >> 8);
        uVar25 = ((uint)psVar12->read_sequence[3] - (uint)pDVar20->max_seq_num[3]) +
                 ((int)uVar27 >> 8);
        uVar22 = ((uint)psVar12->read_sequence[2] - (uint)pDVar20->max_seq_num[2]) +
                 ((int)uVar25 >> 8);
        uVar21 = ((uint)psVar12->read_sequence[1] - (uint)pDVar20->max_seq_num[1]) +
                 ((int)uVar22 >> 8);
        uVar8 = ((uint)psVar12->read_sequence[0] - (uint)pDVar20->max_seq_num[0]) +
                ((int)uVar21 >> 8);
        uVar9 = ~uVar9 | ~uVar26 | ~uVar27 | ~uVar25 | ~uVar22 | ~uVar21 | ~uVar8;
      }
      uVar8 = ((int)uVar8 >> 8) * 0x100;
      if ((uVar9 & 0xff) == 0) {
        uVar8 = uVar8 + (uVar19 & 0xff);
      }
      else {
        uVar8 = uVar8 | 0x80;
      }
      if (((int)uVar8 < 1) &&
         ((0x1e < -uVar8 && uVar8 != 0xffffffe1 ||
          ((int)((pDVar20->map >> (-uVar8 & 0xff)) << 0x1f) < 0)))) goto LAB_00076ea4;
      uVar13 = *(undefined4 *)(psVar12->read_sequence + 4);
      *(undefined4 *)(psVar12->rrec).seq_num = *(undefined4 *)psVar12->read_sequence;
      *(undefined4 *)((psVar12->rrec).seq_num + 4) = uVar13;
    }
    if ((psVar17->rrec).length == 0) goto LAB_00076eaa;
    if (!bVar4) {
      iVar7 = dtls1_process_record();
      if (iVar7 != 0) {
        dtls1_record_bitmap_update(param_1,pDVar20);
        return 1;
      }
      (psVar17->rrec).length = 0;
      param_1->packet_length = 0;
      goto LAB_00076eaa;
    }
    uVar19 = SSL_state(param_1);
    if ((((uVar19 & 0x3000) != 0) || (param_1->in_handshake != 0)) &&
       (pdVar14 = param_1->d1, pdVar14->mtu == 0)) {
      iVar7 = pqueue_size((pdVar14->unprocessed_rcds).q);
      if ((iVar7 < 100) &&
         (iVar7 = dtls1_buffer_record_part_1
                            (param_1,&pdVar14->unprocessed_rcds,(psVar17->rrec).seq_num), iVar7 < 0)
         ) {
        return -1;
      }
      dtls1_record_bitmap_update(param_1,pDVar20);
    }
  }
  else {
    iVar7 = ssl3_read_n(param_1,0xd,(param_1->s3->rbuf).len,0);
    if (iVar7 < 1) {
      return iVar7;
    }
    if (param_1->packet_length != 0xd) goto LAB_00076ea8;
    param_1->rstate = 0xf1;
    buf = param_1->packet;
    if (param_1->msg_callback != (_func_3292 *)0x0) {
      (*param_1->msg_callback)(0,0,0x100,buf,0xd,param_1,param_1->msg_callback_arg);
    }
    psVar12 = param_1->s3;
    (psVar17->rrec).type = (uint)*buf;
    bVar1 = buf[2];
    bVar2 = buf[1];
    (psVar17->rrec).epoch = (uint)CONCAT11(buf[3],buf[4]);
    *(undefined4 *)(psVar12->read_sequence + 2) = *(undefined4 *)(buf + 5);
    *(undefined2 *)(psVar12->read_sequence + 6) = *(undefined2 *)(buf + 9);
    iVar7 = param_1->max_cert_list;
    uVar19 = (uint)CONCAT11(buf[0xb],buf[0xc]);
    (psVar17->rrec).length = uVar19;
    if (iVar7 == 0) {
      if ((uint)CONCAT11(bVar2,bVar1) == param_1->version) {
LAB_00076f46:
        if (uVar19 < 0x4541) {
          if (param_1->packet_length - 0xd < uVar19) goto LAB_00076f56;
          goto LAB_00076e82;
        }
        goto LAB_00076ea4;
      }
      (psVar17->rrec).length = 0;
      param_1->packet_length = 0;
      goto LAB_00076eaa;
    }
    if ((((uint)CONCAT11(bVar2,bVar1) ^ param_1->version) & 0xff00) == 0) goto LAB_00076f46;
  }
LAB_00076ea4:
  (psVar17->rrec).length = 0;
LAB_00076ea8:
  param_1->packet_length = 0;
  goto LAB_00076eaa;
}

