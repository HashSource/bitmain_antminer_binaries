
undefined4 dtls_get_message(int *param_1,int *param_2,int *param_3)

{
  undefined2 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  pitem *ppVar7;
  uint uVar8;
  int iVar9;
  pqueue pq;
  int iVar10;
  int iVar11;
  size_t sVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  uint uVar15;
  undefined4 uVar16;
  undefined1 *puVar17;
  int iVar18;
  void *pvVar19;
  uint uVar20;
  undefined4 *data;
  char *pcVar21;
  undefined4 *puVar22;
  int local_174;
  size_t local_170;
  uint local_16c;
  uchar local_168 [4];
  int local_164;
  char local_160;
  char local_15f;
  char local_15e;
  char local_15d;
  char local_154 [4];
  uint local_150;
  ushort local_14c [2];
  int local_148 [5];
  char acStack_134 [12];
  undefined1 auStack_128 [260];
  
  iVar11 = param_1[0x20];
  memset((void *)(iVar11 + 0x14c),0,0x2c);
LAB_000fc668:
  iVar6 = param_1[0x20];
  do {
    ppVar7 = pqueue_peek(*(pqueue *)(iVar6 + 0x110));
    if (ppVar7 == (pitem *)0x0) goto LAB_000fc692;
LAB_000fc67c:
    pvVar19 = ppVar7->data;
    iVar6 = param_1[0x20];
    if (*(ushort *)(iVar6 + 0x10c) <= *(ushort *)((int)pvVar19 + 8)) {
      if ((*(int *)((int)pvVar19 + 0x30) == 0) &&
         (*(ushort *)((int)pvVar19 + 8) == *(ushort *)(iVar6 + 0x10c))) {
        iVar10 = *(int *)((int)pvVar19 + 0x10);
        pqueue_pop(*(pqueue *)(iVar6 + 0x110));
        iVar6 = dtls1_preprocess_fragment(param_1,pvVar19);
        if (iVar6 == 0) {
          dtls1_hm_fragment_free(pvVar19);
          pitem_free(ppVar7);
          param_1[0x1d] = 0;
          return 0;
        }
        if (*(size_t *)((int)pvVar19 + 0x10) != 0) {
          memcpy((void *)(*(int *)(param_1[0x1b] + 4) + *(int *)((int)pvVar19 + 0xc) + 0xc),
                 *(void **)((int)pvVar19 + 0x2c),*(size_t *)((int)pvVar19 + 0x10));
        }
        dtls1_hm_fragment_free(pvVar19);
        pitem_free(ppVar7);
        param_1[0x1d] = iVar10;
        iVar9 = param_1[0x1b];
        iVar10 = *(int *)(param_1[0x1f] + 0x20c);
LAB_000fc7fc:
        puVar17 = *(undefined1 **)(iVar9 + 4);
        *param_2 = iVar10;
        *param_3 = param_1[0x1d];
        if (*param_2 == 0x101) {
          if ((code *)param_1[0x21] != (code *)0x0) {
            (*(code *)param_1[0x21])(0,*param_1,0x14,puVar17,1,param_1,param_1[0x22]);
            return 1;
          }
        }
        else {
          iVar6 = *(int *)(iVar11 + 0x150);
          *puVar17 = *(undefined1 *)(iVar11 + 0x14c);
          uVar2 = (undefined1)((uint)iVar6 >> 0x10);
          puVar17[1] = uVar2;
          puVar17[3] = (char)iVar6;
          uVar3 = (undefined1)((uint)iVar6 >> 8);
          puVar17[2] = uVar3;
          puVar17[4] = (char)((ushort)*(undefined2 *)(iVar11 + 0x154) >> 8);
          uVar1 = *(undefined2 *)(iVar11 + 0x154);
          puVar17[0xb] = (char)iVar6;
          puVar17[9] = uVar2;
          puVar17[5] = (char)uVar1;
          puVar17[10] = uVar3;
          puVar17[6] = 0;
          puVar17[7] = 0;
          puVar17[8] = 0;
          if (*param_1 == 0x100) {
            puVar17 = puVar17 + 0xc;
          }
          else {
            iVar6 = iVar6 + 0xc;
          }
          if ((*param_2 == 0x14) && (iVar10 = ssl3_take_mac(param_1), iVar10 == 0)) {
            return 0;
          }
          iVar10 = ssl3_finish_mac(param_1,puVar17,iVar6);
          if (iVar10 == 0) {
            return 0;
          }
          if ((code *)param_1[0x21] != (code *)0x0) {
            (*(code *)param_1[0x21])(0,*param_1,0x16,puVar17,iVar6,param_1,param_1[0x22]);
          }
          memset((void *)(iVar11 + 0x14c),0,0x2c);
          iVar11 = *(int *)(param_1[0x1b] + 4);
          *(short *)(param_1[0x20] + 0x10c) = *(short *)(param_1[0x20] + 0x10c) + 1;
          param_1[0x1c] = iVar11 + 0xc;
        }
        return 1;
      }
LAB_000fc692:
      iVar6 = (**(code **)(param_1[1] + 0x38))(param_1,0x16,&local_174,&local_160,0xc,0,&local_170);
      if (iVar6 < 1) {
LAB_000fc8da:
        param_1[5] = 3;
        return 0;
      }
      if (local_174 == 0x14) {
        if (local_160 != '\x01') {
          uVar13 = 0x304;
          uVar14 = 0x67;
LAB_000fc8c0:
          ossl_statem_fatal(param_1,10,0x172,uVar14,"ssl/statem/statem_dtls.c",uVar13);
LAB_000fc8ce:
          param_1[0x1d] = 0;
          return 0;
        }
        iVar10 = 0x101;
        memcpy(*(void **)(param_1[0x1b] + 4),&local_160,local_170);
        iVar9 = param_1[0x1b];
        iVar18 = param_1[0x1f];
        iVar6 = *(int *)(iVar9 + 4);
        param_1[0x1d] = local_170 - 1;
        param_1[0x1c] = iVar6 + 1;
        *(size_t *)(iVar18 + 0x208) = local_170 - 1;
        *(undefined4 *)(iVar18 + 0x20c) = 0x101;
        goto LAB_000fc7fc;
      }
      if (local_170 != 0xc) {
        uVar13 = 0x314;
LAB_000fc8bc:
        uVar14 = 0xf4;
        goto LAB_000fc8c0;
      }
      dtls1_get_message_header(&local_160,local_154);
      iVar10 = local_148[1];
      iVar6 = local_148[0];
      uVar15 = local_150;
      uVar8 = RECORD_LAYER_get_rrec_length(param_1 + 0x194);
      uVar20 = local_148[1];
      if (uVar8 < (uint)iVar10) {
        uVar13 = 0x325;
LAB_000fc91c:
        ossl_statem_fatal(param_1,0x2f,0x172,0x10f,"ssl/statem/statem_dtls.c",uVar13);
        goto LAB_000fc8ce;
      }
      iVar9 = param_1[0x20];
      if (*(ushort *)(iVar9 + 0x10c) == local_14c[0]) {
        if ((iVar10 == 0U || (uint)iVar10 <= uVar15) && (iVar10 != 0U && uVar15 != iVar10)) {
LAB_000fc98e:
          iVar6 = dtls1_reassemble_fragment(param_1,local_154);
          if (1 < iVar6 + 3U) {
            return 0;
          }
          goto LAB_000fc668;
        }
        if ((((param_1[7] != 0) || (*(int *)(iVar9 + 0x158) != 0)) || (param_1[0x10] == 1)) ||
           (local_160 != '\0')) {
          iVar9 = dtls1_preprocess_fragment(param_1,local_154);
          if (iVar9 == 0) goto LAB_000fc8ce;
          sVar12 = iVar10;
          if (iVar10 != 0) {
            iVar6 = (**(code **)(param_1[1] + 0x38))
                              (param_1,0x16,0,*(int *)(param_1[0x1b] + 4) + iVar6 + 0xc,iVar10,0,
                               &local_170);
            if (iVar6 < 1) goto LAB_000fc8da;
            sVar12 = local_170;
            if (iVar10 != local_170) {
              uVar13 = 0x372;
              goto LAB_000fc91c;
            }
          }
          param_1[0x1d] = sVar12;
          iVar9 = param_1[0x1b];
          iVar10 = *(int *)(param_1[0x1f] + 0x20c);
          goto LAB_000fc7fc;
        }
        if (((local_15f != '\0') || (local_15e != '\0')) || (local_15d != '\0')) {
          uVar13 = 0x34e;
          goto LAB_000fc8bc;
        }
        if ((code *)param_1[0x21] != (code *)0x0) {
          (*(code *)param_1[0x21])(0,*param_1,0x16,&local_160,0xc,param_1,param_1[0x22]);
          iVar9 = param_1[0x20];
        }
        pq = *(pqueue *)(iVar9 + 0x110);
        param_1[0x1d] = 0;
        ppVar7 = pqueue_peek(pq);
        if (ppVar7 != (pitem *)0x0) goto LAB_000fc67c;
        goto LAB_000fc692;
      }
      if (local_150 < (uint)(local_148[0] + local_148[1])) {
LAB_000fc908:
        data = (undefined4 *)0x0;
        goto LAB_000fc90c;
      }
      local_168[0] = '\0';
      local_168[1] = '\0';
      local_168[2] = '\0';
      local_168[3] = '\0';
      local_164 = (uint)CONCAT11((char)local_14c[0],(char)(local_14c[0] >> 8)) << 0x10;
      ppVar7 = pqueue_find(*(pqueue *)(iVar9 + 0x110),local_168);
      if ((ppVar7 != (pitem *)0x0) && (uVar20 == local_150)) {
LAB_000fc9e0:
        if (uVar20 == 0) goto LAB_000fc668;
        break;
      }
      uVar15 = (uint)*(ushort *)(param_1[0x20] + 0x10c);
      if ((local_14c[0] <= uVar15) || (uVar15 + 10 < (uint)local_14c[0])) {
        ppVar7 = (pitem *)0x0;
        goto LAB_000fc9e0;
      }
      if ((uVar15 == 0) && (local_154[0] == '\x14')) {
        ppVar7 = (pitem *)0x0;
        goto LAB_000fc9e0;
      }
      if (uVar20 != local_150) goto LAB_000fc98e;
      uVar15 = 0x454c;
      if (0x454c < (uint)param_1[0x13f]) {
        uVar15 = param_1[0x13f];
      }
      if ((uVar15 < uVar20) ||
         (data = (undefined4 *)dtls1_hm_fragment_new(uVar20,0), data == (undefined4 *)0x0))
      goto LAB_000fc908;
      pcVar4 = local_154;
      puVar5 = data;
      do {
        puVar22 = puVar5;
        pcVar21 = pcVar4;
        uVar13 = *(undefined4 *)(pcVar21 + 4);
        uVar14 = *(undefined4 *)(pcVar21 + 8);
        uVar16 = *(undefined4 *)(pcVar21 + 0xc);
        *puVar22 = *(undefined4 *)pcVar21;
        puVar22[1] = uVar13;
        puVar22[2] = uVar14;
        puVar22[3] = uVar16;
        pcVar4 = pcVar21 + 0x10;
        puVar5 = puVar22 + 4;
      } while (pcVar21 + 0x10 != acStack_134);
      uVar13 = *(undefined4 *)(pcVar21 + 0x14);
      uVar14 = *(undefined4 *)(pcVar21 + 0x18);
      puVar22[4] = *(undefined4 *)(pcVar21 + 0x10);
      puVar22[5] = uVar13;
      puVar22[6] = uVar14;
      if ((((uVar20 != 0) &&
           ((iVar6 = (**(code **)(param_1[1] + 0x38))(param_1,0x16,0,data[0xb],uVar20,0,&local_16c),
            iVar6 < 1 || (uVar20 != local_16c)))) ||
          (ppVar7 = pitem_new(local_168,data), ppVar7 == (pitem *)0x0)) ||
         (ppVar7 = pqueue_insert(*(pqueue *)(param_1[0x20] + 0x110),ppVar7), ppVar7 == (pitem *)0x0)
         ) goto LAB_000fc90c;
      goto LAB_000fc668;
    }
    pqueue_pop(*(pqueue *)(iVar6 + 0x110));
    dtls1_hm_fragment_free(pvVar19);
    pitem_free(ppVar7);
    iVar6 = param_1[0x20];
  } while( true );
  while (uVar20 = uVar20 - local_16c, uVar20 != 0) {
    uVar15 = uVar20;
    if (0xff < uVar20) {
      uVar15 = 0x100;
    }
    iVar6 = (**(code **)(param_1[1] + 0x38))(param_1,0x16,0,auStack_128,uVar15,0,&local_16c);
    if (iVar6 < 1) {
      if (ppVar7 == (pitem *)0x0) {
        data = (undefined4 *)0x0;
LAB_000fc90c:
        dtls1_hm_fragment_free(data);
      }
      return 0;
    }
  }
  goto LAB_000fc668;
}

