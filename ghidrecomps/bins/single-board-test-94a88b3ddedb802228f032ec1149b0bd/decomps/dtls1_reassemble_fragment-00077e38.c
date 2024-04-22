
int dtls1_reassemble_fragment(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  pitem *ppVar2;
  void *__s;
  undefined4 uVar3;
  uint uVar4;
  void *pvVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 *ptr;
  int iVar14;
  size_t __n;
  undefined4 uVar15;
  bool bVar16;
  undefined4 local_130;
  int local_12c;
  undefined auStack_128 [260];
  
  iVar13 = param_2[4];
  if ((uint)(iVar13 + param_2[3]) <= (uint)param_2[1]) {
    uVar6 = *(uint *)(param_1 + 0x108);
    if (uVar6 < 0x454c) {
      uVar6 = 0x454c;
    }
    if ((uint)param_2[1] <= uVar6) {
      if (iVar13 == 0) {
        return -3;
      }
      local_130 = 0;
      local_12c = (uint)CONCAT11((char)*(undefined2 *)(param_2 + 2),
                                 (char)((ushort)*(undefined2 *)(param_2 + 2) >> 8)) << 0x10;
      ppVar2 = pqueue_find(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x244),(uchar *)&local_130);
      if (ppVar2 == (pitem *)0x0) {
        iVar11 = param_2[1];
        ptr = (undefined4 *)CRYPTO_malloc(0x34,DAT_00078104,0xb5);
        if (ptr != (undefined4 *)0x0) {
          if (iVar11 == 0) {
            ptr[0xb] = 0;
            __s = CRYPTO_malloc(0,DAT_00078104,199);
            if (__s != (void *)0x0) {
              __n = 0;
LAB_00077f64:
              memset(__s,0,__n);
              ptr[0xc] = __s;
              puVar1 = ptr;
              puVar9 = param_2;
              do {
                puVar8 = puVar9;
                puVar7 = puVar1;
                uVar15 = puVar8[1];
                uVar12 = puVar8[2];
                uVar3 = puVar8[3];
                puVar9 = puVar8 + 4;
                *puVar7 = *puVar8;
                puVar7[1] = uVar15;
                puVar7[2] = uVar12;
                puVar7[3] = uVar3;
                puVar1 = puVar7 + 4;
              } while (puVar9 != param_2 + 8);
              uVar3 = puVar8[5];
              uVar12 = puVar8[6];
              puVar7[4] = *puVar9;
              puVar7[5] = uVar3;
              puVar7[6] = uVar12;
              ptr[3] = 0;
              ptr[4] = ptr[1];
              goto LAB_00077ea6;
            }
          }
          else {
            pvVar5 = CRYPTO_malloc(iVar11,DAT_00078104,0xba);
            if (pvVar5 != (void *)0x0) {
              ptr[0xb] = pvVar5;
              __n = iVar11 + 7U >> 3;
              __s = CRYPTO_malloc(__n,DAT_00078104,199);
              if (__s != (void *)0x0) goto LAB_00077f64;
              CRYPTO_free(pvVar5);
            }
          }
          CRYPTO_free(ptr);
        }
      }
      else {
        ptr = (undefined4 *)ppVar2->data;
        if (ptr[1] == param_2[1]) {
LAB_00077ea6:
          if (ptr[0xc] == 0) {
            while (iVar11 = (**(code **)(*(int *)(param_1 + 8) + 0x34))(param_1,0x16,auStack_128),
                  0 < iVar11) {
              iVar13 = iVar13 - iVar11;
              if (iVar13 == 0) {
                return -3;
              }
            }
LAB_000780a0:
            iVar13 = 1 - (int)ppVar2;
            if ((pitem *)0x1 < ppVar2) {
              iVar13 = 0;
            }
LAB_00077ed6:
            if (iVar13 == 0) goto LAB_00077e66;
          }
          else {
            iVar11 = (**(code **)(*(int *)(param_1 + 8) + 0x34))
                               (param_1,0x16,param_2[3] + ptr[0xb],iVar13,0);
            iVar14 = DAT_00078110;
            if (iVar11 != iVar13) {
              iVar13 = 1 - (int)ppVar2;
              iVar11 = -1;
              if ((pitem *)0x1 < ppVar2) {
                iVar13 = 0;
              }
              goto LAB_00077ed6;
            }
            if (iVar13 < 1) goto LAB_000780a0;
            uVar6 = param_2[3];
            if (iVar13 < 9) {
              if ((int)uVar6 < (int)(iVar13 + uVar6)) {
                do {
                  iVar13 = (int)uVar6 >> 3;
                  uVar4 = uVar6 & 7;
                  uVar6 = uVar6 + 1;
                  *(byte *)(ptr[0xc] + iVar13) = *(byte *)(ptr[0xc] + iVar13) | (byte)(1 << uVar4);
                  iVar14 = DAT_00078110;
                } while ((int)uVar6 < iVar11 + param_2[3]);
              }
            }
            else {
              *(byte *)(ptr[0xc] + ((int)uVar6 >> 3)) =
                   *(byte *)(DAT_00078110 + (uVar6 & 7)) | *(byte *)(ptr[0xc] + ((int)uVar6 >> 3));
              uVar6 = iVar13 + param_2[3];
              iVar13 = (int)(uVar6 - 1) >> 3;
              iVar10 = ((int)param_2[3] >> 3) + 1;
              if (iVar10 < iVar13) {
                do {
                  *(undefined *)(ptr[0xc] + iVar10) = 0xff;
                  iVar10 = iVar10 + 1;
                  uVar6 = iVar11 + param_2[3];
                  iVar13 = (int)(uVar6 - 1) >> 3;
                } while (iVar10 < iVar13);
              }
              *(byte *)(ptr[0xc] + iVar13) =
                   *(byte *)(ptr[0xc] + iVar13) | *(byte *)((uVar6 & 7) + iVar14 + 8);
            }
            uVar6 = param_2[1];
            if ((int)uVar6 < 1) {
              OpenSSLDie(DAT_00078104,0x2ce,DAT_0007810c);
              uVar6 = param_2[1];
            }
            pvVar5 = (void *)ptr[0xc];
            iVar13 = (int)(uVar6 - 1) >> 3;
            if (*(char *)((int)pvVar5 + iVar13) == *(char *)(iVar14 + (uVar6 & 7) + 8)) {
              iVar13 = iVar13 + -1;
              if (-1 < iVar13) {
                do {
                  if (*(char *)((int)pvVar5 + iVar13) != -1) goto LAB_00078008;
                  bVar16 = iVar13 != 0;
                  iVar13 = iVar13 + -1;
                } while (bVar16);
              }
              CRYPTO_free(pvVar5);
              ptr[0xc] = 0;
            }
LAB_00078008:
            if (ppVar2 != (pitem *)0x0) {
              return -3;
            }
            ppVar2 = pitem_new((uchar *)&local_130,ptr);
            if (ppVar2 != (pitem *)0x0) {
              ppVar2 = pqueue_insert(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x244),ppVar2);
              if (ppVar2 != (pitem *)0x0) {
                return -3;
              }
              OpenSSLDie(DAT_00078104,0x2e3,DAT_00078108);
              return -3;
            }
            iVar11 = -1;
          }
          if (ptr[5] != 0) {
            EVP_CIPHER_CTX_free((EVP_CIPHER_CTX *)ptr[6]);
            EVP_MD_CTX_destroy((EVP_MD_CTX *)ptr[7]);
          }
          if ((void *)ptr[0xb] != (void *)0x0) {
            CRYPTO_free((void *)ptr[0xb]);
          }
          if ((void *)ptr[0xc] != (void *)0x0) {
            CRYPTO_free((void *)ptr[0xc]);
          }
          CRYPTO_free(ptr);
          goto LAB_00077e66;
        }
      }
    }
  }
  iVar11 = -1;
LAB_00077e66:
  *param_3 = 0;
  return iVar11;
}

