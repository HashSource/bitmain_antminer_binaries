
/* WARNING: Type propagation algorithm not settling */

int dtls1_get_record(SSL *param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  pitem *ppVar5;
  uchar *puVar6;
  int iVar7;
  uint uVar8;
  pqueue pq;
  uint uVar9;
  int iVar10;
  SSL3_RECORD *pSVar11;
  ssl3_state_st *psVar12;
  undefined4 uVar13;
  dtls1_state_st *pdVar14;
  int *piVar15;
  ulong uVar16;
  ssl3_state_st *psVar17;
  int *piVar18;
  uint uVar19;
  byte *buf;
  DTLS1_BITMAP *pDVar20;
  uint uVar21;
  uint uVar22;
  size_t sVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  
  psVar17 = param_1->s3;
  ppVar5 = pqueue_peek((param_1->d1->unprocessed_rcds).q);
  if (ppVar5 != (pitem *)0x0) {
    pdVar14 = param_1->d1;
    if ((pdVar14->unprocessed_rcds).epoch != pdVar14->r_epoch) {
LAB_0012c3e0:
      ppVar5 = pqueue_pop((pdVar14->processed_rcds).q);
      goto joined_r0x0012c56e;
    }
    while (ppVar5 = pqueue_peek((pdVar14->unprocessed_rcds).q), ppVar5 != (pitem *)0x0) {
      ppVar5 = pqueue_pop((param_1->d1->unprocessed_rcds).q);
      if (ppVar5 != (pitem *)0x0) {
        psVar12 = param_1->s3;
        piVar18 = (int *)ppVar5->data;
        puVar6 = (psVar12->rbuf).buf;
        if (puVar6 != (uchar *)0x0) {
          CRYPTO_free(puVar6);
          psVar12 = param_1->s3;
        }
        piVar15 = piVar18 + 6;
        param_1->packet = (uchar *)*piVar18;
        param_1->packet_length = piVar18[1];
        sVar23 = piVar18[3];
        iVar10 = piVar18[4];
        iVar7 = piVar18[5];
        (psVar12->rbuf).buf = (uchar *)piVar18[2];
        (psVar12->rbuf).len = sVar23;
        (psVar12->rbuf).offset = iVar10;
        (psVar12->rbuf).left = iVar7;
        pSVar11 = &param_1->s3->rrec;
        do {
          iVar7 = *piVar15;
          uVar19 = piVar15[1];
          uVar8 = piVar15[2];
          puVar6 = (uchar *)piVar15[3];
          piVar15 = piVar15 + 4;
          pSVar11->type = iVar7;
          pSVar11->length = uVar19;
          pSVar11->off = uVar8;
          pSVar11->data = puVar6;
          pSVar11 = (SSL3_RECORD *)&pSVar11->input;
        } while (piVar15 != piVar18 + 0xe);
        *(uchar **)pSVar11 = (uchar *)*piVar15;
        iVar7 = *piVar18;
        psVar12 = param_1->s3;
        *(undefined4 *)(psVar12->read_sequence + 2) = *(undefined4 *)(iVar7 + 5);
        *(undefined2 *)(psVar12->read_sequence + 6) = *(undefined2 *)(iVar7 + 9);
        CRYPTO_free(ppVar5->data);
        pitem_free(ppVar5);
      }
      iVar7 = dtls1_process_record(param_1);
      if (iVar7 == 0) {
        pdVar14 = param_1->d1;
        goto LAB_0012c3e0;
      }
      pdVar14 = param_1->d1;
      psVar12 = param_1->s3;
      iVar7 = pqueue_size((pdVar14->processed_rcds).q);
      if ((iVar7 < 100) &&
         (iVar7 = dtls1_buffer_record_part_1
                            (param_1,&pdVar14->processed_rcds,(psVar12->rrec).seq_num), iVar7 < 0))
      {
        return -1;
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
joined_r0x0012c56e:
  if (ppVar5 != (pitem *)0x0) {
    psVar17 = param_1->s3;
    piVar18 = (int *)ppVar5->data;
    puVar6 = (psVar17->rbuf).buf;
    if (puVar6 != (uchar *)0x0) {
      CRYPTO_free(puVar6);
      psVar17 = param_1->s3;
    }
    piVar15 = piVar18 + 6;
    param_1->packet = (uchar *)*piVar18;
    param_1->packet_length = piVar18[1];
    sVar23 = piVar18[3];
    iVar7 = piVar18[4];
    iVar10 = piVar18[5];
    (psVar17->rbuf).buf = (uchar *)piVar18[2];
    (psVar17->rbuf).len = sVar23;
    (psVar17->rbuf).offset = iVar7;
    (psVar17->rbuf).left = iVar10;
    pSVar11 = &param_1->s3->rrec;
    do {
      iVar7 = *piVar15;
      uVar19 = piVar15[1];
      uVar8 = piVar15[2];
      puVar6 = (uchar *)piVar15[3];
      piVar15 = piVar15 + 4;
      pSVar11->type = iVar7;
      pSVar11->length = uVar19;
      pSVar11->off = uVar8;
      pSVar11->data = puVar6;
      pSVar11 = (SSL3_RECORD *)&pSVar11->input;
    } while (piVar15 != piVar18 + 0xe);
    *(uchar **)pSVar11 = (uchar *)*piVar15;
    iVar7 = *piVar18;
    psVar17 = param_1->s3;
    *(undefined4 *)(psVar17->read_sequence + 2) = *(undefined4 *)(iVar7 + 5);
    *(undefined2 *)(psVar17->read_sequence + 6) = *(undefined2 *)(iVar7 + 9);
    CRYPTO_free(ppVar5->data);
    pitem_free(ppVar5);
    return 1;
  }
LAB_0012c5b2:
  if ((param_1->rstate == 0xf1) && (0xc < param_1->packet_length)) {
    uVar8 = (psVar17->rrec).length;
    if (param_1->packet_length - 0xd < uVar8) {
LAB_0012c65e:
      uVar19 = ssl3_read_n(param_1,uVar8,uVar8,1);
      if (uVar19 != uVar8) goto LAB_0012c5ac;
    }
LAB_0012c58a:
    pdVar14 = param_1->d1;
    uVar16 = (psVar17->rrec).epoch;
    param_1->rstate = 0xf0;
    if (uVar16 == pdVar14->r_epoch) {
      pDVar20 = &pdVar14->bitmap;
      bVar4 = false;
    }
    else {
      if ((uVar16 != pdVar14->r_epoch + 1) || (1 < (psVar17->rrec).type - 0x15U)) goto LAB_0012c5ac;
      pDVar20 = &pdVar14->next_bitmap;
      bVar4 = true;
    }
    if ((((pdVar14->mtu == 0) || ((psVar17->rrec).type != 0x16)) || (param_1->packet_length < 0xe))
       || (param_1->packet[0xd] != '\x01')) {
      psVar12 = param_1->s3;
      uVar8 = (uint)psVar12->read_sequence[7] - (uint)pDVar20->max_seq_num[7];
      if ((uVar8 & 0x80) == 0) {
        uVar9 = ((int)uVar8 >> 8) +
                ((uint)psVar12->read_sequence[6] - (uint)pDVar20->max_seq_num[6]);
        uVar24 = ((uint)psVar12->read_sequence[5] - (uint)pDVar20->max_seq_num[5]) +
                 ((int)uVar9 >> 8);
        uVar22 = ((uint)psVar12->read_sequence[4] - (uint)pDVar20->max_seq_num[4]) +
                 ((int)uVar24 >> 8);
        uVar21 = ((uint)psVar12->read_sequence[3] - (uint)pDVar20->max_seq_num[3]) +
                 ((int)uVar22 >> 8);
        uVar26 = ((uint)psVar12->read_sequence[2] - (uint)pDVar20->max_seq_num[2]) +
                 ((int)uVar21 >> 8);
        uVar25 = ((uint)psVar12->read_sequence[1] - (uint)pDVar20->max_seq_num[1]) +
                 ((int)uVar26 >> 8);
        uVar19 = ((uint)psVar12->read_sequence[0] - (uint)pDVar20->max_seq_num[0]) +
                 ((int)uVar25 >> 8);
        uVar9 = uVar24 | uVar9 | uVar22 | uVar21 | uVar26 | uVar25 | uVar19;
      }
      else {
        uVar9 = ((int)uVar8 >> 8) +
                ((uint)psVar12->read_sequence[6] - (uint)pDVar20->max_seq_num[6]);
        uVar25 = ((uint)psVar12->read_sequence[5] - (uint)pDVar20->max_seq_num[5]) +
                 ((int)uVar9 >> 8);
        uVar26 = ((uint)psVar12->read_sequence[4] - (uint)pDVar20->max_seq_num[4]) +
                 ((int)uVar25 >> 8);
        uVar24 = ((uint)psVar12->read_sequence[3] - (uint)pDVar20->max_seq_num[3]) +
                 ((int)uVar26 >> 8);
        uVar22 = ((uint)psVar12->read_sequence[2] - (uint)pDVar20->max_seq_num[2]) +
                 ((int)uVar24 >> 8);
        uVar21 = ((uint)psVar12->read_sequence[1] - (uint)pDVar20->max_seq_num[1]) +
                 ((int)uVar22 >> 8);
        uVar19 = ((uint)psVar12->read_sequence[0] - (uint)pDVar20->max_seq_num[0]) +
                 ((int)uVar21 >> 8);
        uVar9 = ~uVar9 | ~uVar25 | ~uVar26 | ~uVar24 | ~uVar22 | ~uVar21 | ~uVar19;
      }
      uVar19 = ((int)uVar19 >> 8) * 0x100;
      if ((uVar9 & 0xff) == 0) {
        uVar19 = uVar19 + (uVar8 & 0xff);
      }
      else {
        uVar19 = uVar19 | 0x80;
      }
      if (((int)uVar19 < 1) &&
         ((0x1e < -uVar19 && uVar19 != 0xffffffe1 ||
          ((int)((pDVar20->map >> (-uVar19 & 0xff)) << 0x1f) < 0)))) goto LAB_0012c5ac;
      uVar13 = *(undefined4 *)(psVar12->read_sequence + 4);
      *(undefined4 *)(psVar12->rrec).seq_num = *(undefined4 *)psVar12->read_sequence;
      *(undefined4 *)((psVar12->rrec).seq_num + 4) = uVar13;
    }
    if ((psVar17->rrec).length == 0) goto LAB_0012c5b2;
    if (!bVar4) {
      iVar7 = dtls1_process_record();
      if (iVar7 != 0) {
        dtls1_record_bitmap_update(param_1,pDVar20);
        return 1;
      }
      (psVar17->rrec).length = 0;
      param_1->packet_length = 0;
      goto LAB_0012c5b2;
    }
    uVar8 = SSL_state(param_1);
    if ((((uVar8 & 0x3000) != 0) || (param_1->in_handshake != 0)) &&
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
    if (param_1->packet_length != 0xd) goto LAB_0012c5b0;
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
    uVar8 = (uint)CONCAT11(buf[0xb],buf[0xc]);
    (psVar17->rrec).length = uVar8;
    if (iVar7 == 0) {
      if ((uint)CONCAT11(bVar2,bVar1) == param_1->version) {
LAB_0012c64e:
        if (uVar8 < 0x4541) {
          if (param_1->packet_length - 0xd < uVar8) goto LAB_0012c65e;
          goto LAB_0012c58a;
        }
        goto LAB_0012c5ac;
      }
      (psVar17->rrec).length = 0;
      param_1->packet_length = 0;
      goto LAB_0012c5b2;
    }
    if ((((uint)CONCAT11(bVar2,bVar1) ^ param_1->version) & 0xff00) == 0) goto LAB_0012c64e;
  }
LAB_0012c5ac:
  (psVar17->rrec).length = 0;
LAB_0012c5b0:
  param_1->packet_length = 0;
  goto LAB_0012c5b2;
}

