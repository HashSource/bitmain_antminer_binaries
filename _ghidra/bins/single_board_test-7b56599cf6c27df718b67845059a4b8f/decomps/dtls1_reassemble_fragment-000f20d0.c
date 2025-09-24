
undefined4 dtls1_reassemble_fragment(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  pitem *ppVar3;
  int iVar4;
  char *ptr;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  char *pcVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined4 *data;
  undefined4 *puVar13;
  undefined4 *puVar14;
  uint local_134;
  uchar local_130 [4];
  int local_12c;
  undefined1 auStack_128 [260];
  
  uVar12 = param_2[4];
  if (param_2[3] + uVar12 <= (uint)param_2[1]) {
    uVar9 = 0x454c;
    if (0x454c < *(uint *)(param_1 + 0x4fc)) {
      uVar9 = *(uint *)(param_1 + 0x4fc);
    }
    if ((uint)param_2[1] <= uVar9) {
      if (uVar12 == 0) {
        return 0xfffffffd;
      }
      local_130[0] = '\0';
      local_130[1] = '\0';
      local_130[2] = '\0';
      local_130[3] = '\0';
      local_12c = (uint)CONCAT11((char)*(undefined2 *)(param_2 + 2),
                                 (char)((ushort)*(undefined2 *)(param_2 + 2) >> 8)) << 0x10;
      ppVar3 = pqueue_find(*(pqueue *)(*(int *)(param_1 + 0x80) + 0x110),local_130);
      if (ppVar3 == (pitem *)0x0) {
        data = (undefined4 *)dtls1_hm_fragment_new(param_2[1],1);
        if (data == (undefined4 *)0x0) goto LAB_000f20f8;
        puVar1 = param_2;
        puVar2 = data;
        do {
          puVar14 = puVar2;
          puVar13 = puVar1;
          uVar5 = puVar13[1];
          uVar8 = puVar13[2];
          uVar11 = puVar13[3];
          *puVar14 = *puVar13;
          puVar14[1] = uVar5;
          puVar14[2] = uVar8;
          puVar14[3] = uVar11;
          puVar1 = puVar13 + 4;
          puVar2 = puVar14 + 4;
        } while (puVar13 + 4 != param_2 + 8);
        uVar5 = puVar13[5];
        uVar8 = puVar13[6];
        puVar14[4] = puVar13[4];
        puVar14[5] = uVar5;
        puVar14[6] = uVar8;
        data[3] = 0;
        data[4] = data[1];
      }
      else {
        data = (undefined4 *)ppVar3->data;
        if (data[1] != param_2[1]) goto LAB_000f20f8;
      }
      if (data[0xc] == 0) {
        while( true ) {
          uVar9 = uVar12;
          if (0xff < uVar12) {
            uVar9 = 0x100;
          }
          iVar4 = (**(code **)(*(int *)(param_1 + 4) + 0x38))
                            (param_1,0x16,0,auStack_128,uVar9,0,&local_134);
          if (iVar4 < 1) break;
          uVar12 = uVar12 - local_134;
          if (uVar12 == 0) {
            return 0xfffffffd;
          }
        }
      }
      else {
        iVar4 = (**(code **)(*(int *)(param_1 + 4) + 0x38))
                          (param_1,0x16,0,param_2[3] + data[0xb],uVar12,0,&local_134);
        if ((0 < iVar4) && (uVar12 == local_134)) {
          if ((int)uVar12 < 9) {
            uVar9 = param_2[3];
            if ((int)uVar9 < (int)(uVar12 + uVar9)) {
              do {
                iVar4 = (int)uVar9 >> 3;
                uVar6 = uVar9 & 7;
                uVar9 = uVar9 + 1;
                *(byte *)(data[0xc] + iVar4) = *(byte *)(data[0xc] + iVar4) | (byte)(1 << uVar6);
              } while ((int)uVar9 < (int)(param_2[3] + uVar12));
            }
          }
          else {
            iVar4 = (int)param_2[3] >> 3;
            *(byte *)(data[0xc] + iVar4) =
                 *(byte *)(data[0xc] + iVar4) | (&bitmask_start_values)[param_2[3] & 7];
            uVar9 = uVar12 + param_2[3];
            iVar4 = (int)(uVar9 - 1) >> 3;
            iVar7 = ((int)param_2[3] >> 3) + 1;
            if (iVar7 < iVar4) {
              do {
                *(undefined1 *)(data[0xc] + iVar7) = 0xff;
                iVar7 = iVar7 + 1;
                uVar9 = param_2[3] + uVar12;
                iVar4 = (int)(uVar9 - 1) >> 3;
              } while (iVar7 < iVar4);
            }
            *(byte *)(data[0xc] + iVar4) =
                 *(byte *)(data[0xc] + iVar4) | *(byte *)((int)&bitmask_end_values + (uVar9 & 7));
          }
          uVar12 = param_2[1];
          if (uVar12 != 0) {
            ptr = (char *)data[0xc];
            iVar4 = (int)(uVar12 - 1) >> 3;
            if (ptr[iVar4] == *(char *)((int)&bitmask_end_values + (uVar12 & 7))) {
              iVar4 = iVar4 + -1;
              if (iVar4 < 0) {
LAB_000f2224:
                CRYPTO_free(ptr);
                data[0xc] = 0;
              }
              else if (ptr[iVar4] == -1) {
                pcVar10 = ptr + iVar4;
                do {
                  if (ptr == pcVar10) goto LAB_000f2224;
                  pcVar10 = pcVar10 + -1;
                } while (*pcVar10 == -1);
              }
            }
            if (ppVar3 != (pitem *)0x0) {
              return 0xfffffffd;
            }
            ppVar3 = pitem_new(local_130,data);
            if ((ppVar3 != (pitem *)0x0) &&
               (ppVar3 = pqueue_insert(*(pqueue *)(*(int *)(param_1 + 0x80) + 0x110),ppVar3),
               ppVar3 != (pitem *)0x0)) {
              return 0xfffffffd;
            }
            goto LAB_000f20fa;
          }
        }
      }
      if (ppVar3 != (pitem *)0x0) {
        return 0xffffffff;
      }
      goto LAB_000f20fa;
    }
  }
LAB_000f20f8:
  data = (undefined4 *)0x0;
LAB_000f20fa:
  dtls1_hm_fragment_free(data);
  return 0xffffffff;
}

