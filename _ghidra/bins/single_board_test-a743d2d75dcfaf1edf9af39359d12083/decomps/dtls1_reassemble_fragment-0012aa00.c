
uint dtls1_reassemble_fragment(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  pitem *ppVar2;
  void *__s;
  undefined4 uVar3;
  void *pvVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 *ptr;
  size_t __n;
  undefined4 uVar14;
  bool bVar15;
  uchar local_130 [4];
  int local_12c;
  undefined1 auStack_128 [260];
  
  uVar13 = param_2[4];
  if (uVar13 + param_2[3] <= (uint)param_2[1]) {
    uVar5 = *(uint *)(param_1 + 0x108);
    if (uVar5 < 0x454c) {
      uVar5 = 0x454c;
    }
    if ((uint)param_2[1] <= uVar5) {
      if (uVar13 == 0) {
        return 0xfffffffd;
      }
      local_130[0] = '\0';
      local_130[1] = '\0';
      local_130[2] = '\0';
      local_130[3] = '\0';
      local_12c = (uint)CONCAT11((char)*(undefined2 *)(param_2 + 2),
                                 (char)((ushort)*(undefined2 *)(param_2 + 2) >> 8)) << 0x10;
      ppVar2 = pqueue_find(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x244),local_130);
      if (ppVar2 == (pitem *)0x0) {
        iVar8 = param_2[1];
        ptr = (undefined4 *)CRYPTO_malloc(0x34,"d1_both.c",0xb5);
        if (ptr != (undefined4 *)0x0) {
          if (iVar8 == 0) {
            ptr[0xb] = 0;
            __s = CRYPTO_malloc(0,"d1_both.c",199);
            if (__s != (void *)0x0) {
              __n = 0;
LAB_0012ab2c:
              memset(__s,0,__n);
              ptr[0xc] = __s;
              puVar1 = ptr;
              puVar10 = param_2;
              do {
                puVar9 = puVar10;
                puVar6 = puVar1;
                uVar14 = puVar9[1];
                uVar12 = puVar9[2];
                uVar3 = puVar9[3];
                puVar10 = puVar9 + 4;
                *puVar6 = *puVar9;
                puVar6[1] = uVar14;
                puVar6[2] = uVar12;
                puVar6[3] = uVar3;
                puVar1 = puVar6 + 4;
              } while (puVar10 != param_2 + 8);
              uVar3 = puVar9[5];
              uVar12 = puVar9[6];
              puVar6[4] = *puVar10;
              puVar6[5] = uVar3;
              puVar6[6] = uVar12;
              ptr[3] = 0;
              ptr[4] = ptr[1];
              goto LAB_0012aa6e;
            }
          }
          else {
            pvVar4 = CRYPTO_malloc(iVar8,"d1_both.c",0xba);
            if (pvVar4 != (void *)0x0) {
              ptr[0xb] = pvVar4;
              __n = iVar8 + 7U >> 3;
              __s = CRYPTO_malloc(__n,"d1_both.c",199);
              if (__s != (void *)0x0) goto LAB_0012ab2c;
              CRYPTO_free(pvVar4);
            }
          }
          CRYPTO_free(ptr);
        }
      }
      else {
        ptr = (undefined4 *)ppVar2->data;
        if (ptr[1] == param_2[1]) {
LAB_0012aa6e:
          if (ptr[0xc] == 0) {
            while( true ) {
              uVar5 = uVar13;
              if (0xff < uVar13) {
                uVar5 = 0x100;
              }
              uVar5 = (**(code **)(*(int *)(param_1 + 8) + 0x34))(param_1,0x16,auStack_128,uVar5,0);
              if ((int)uVar5 < 1) break;
              uVar13 = uVar13 - uVar5;
              if (uVar13 == 0) {
                return 0xfffffffd;
              }
            }
LAB_0012ac68:
            iVar8 = 1 - (int)ppVar2;
            if ((pitem *)0x1 < ppVar2) {
              iVar8 = 0;
            }
LAB_0012aa9e:
            if (iVar8 == 0) goto LAB_0012aa2e;
          }
          else {
            uVar5 = (**(code **)(*(int *)(param_1 + 8) + 0x34))
                              (param_1,0x16,param_2[3] + ptr[0xb],uVar13,0);
            if (uVar5 != uVar13) {
              iVar8 = 1 - (int)ppVar2;
              uVar5 = 0xffffffff;
              if ((pitem *)0x1 < ppVar2) {
                iVar8 = 0;
              }
              goto LAB_0012aa9e;
            }
            if ((int)uVar13 < 1) goto LAB_0012ac68;
            uVar7 = param_2[3];
            if ((int)uVar13 < 9) {
              if ((int)uVar7 < (int)(uVar13 + uVar7)) {
                do {
                  iVar8 = (int)uVar7 >> 3;
                  uVar13 = uVar7 & 7;
                  uVar7 = uVar7 + 1;
                  *(byte *)(ptr[0xc] + iVar8) = *(byte *)(ptr[0xc] + iVar8) | (byte)(1 << uVar13);
                } while ((int)uVar7 < (int)(uVar5 + param_2[3]));
              }
            }
            else {
              *(byte *)(ptr[0xc] + ((int)uVar7 >> 3)) =
                   (&bitmask_start_values)[uVar7 & 7] | *(byte *)(ptr[0xc] + ((int)uVar7 >> 3));
              uVar13 = uVar13 + param_2[3];
              iVar8 = (int)(uVar13 - 1) >> 3;
              iVar11 = ((int)param_2[3] >> 3) + 1;
              if (iVar11 < iVar8) {
                do {
                  *(undefined1 *)(ptr[0xc] + iVar11) = 0xff;
                  iVar11 = iVar11 + 1;
                  uVar13 = uVar5 + param_2[3];
                  iVar8 = (int)(uVar13 - 1) >> 3;
                } while (iVar11 < iVar8);
              }
              *(byte *)(ptr[0xc] + iVar8) =
                   *(byte *)(ptr[0xc] + iVar8) | *(byte *)((int)&bitmask_end_values + (uVar13 & 7));
            }
            uVar13 = param_2[1];
            if ((int)uVar13 < 1) {
              OpenSSLDie("d1_both.c",0x2ce,"((long)msg_hdr->msg_len) > 0");
              uVar13 = param_2[1];
            }
            pvVar4 = (void *)ptr[0xc];
            iVar8 = (int)(uVar13 - 1) >> 3;
            if (*(char *)((int)pvVar4 + iVar8) == *(char *)((int)&bitmask_end_values + (uVar13 & 7))
               ) {
              iVar8 = iVar8 + -1;
              if (-1 < iVar8) {
                do {
                  if (*(char *)((int)pvVar4 + iVar8) != -1) goto LAB_0012abd0;
                  bVar15 = iVar8 != 0;
                  iVar8 = iVar8 + -1;
                } while (bVar15);
              }
              CRYPTO_free(pvVar4);
              ptr[0xc] = 0;
            }
LAB_0012abd0:
            if (ppVar2 != (pitem *)0x0) {
              return 0xfffffffd;
            }
            ppVar2 = pitem_new(local_130,ptr);
            if (ppVar2 != (pitem *)0x0) {
              ppVar2 = pqueue_insert(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x244),ppVar2);
              if (ppVar2 != (pitem *)0x0) {
                return 0xfffffffd;
              }
              OpenSSLDie("d1_both.c",0x2e3,"item != NULL");
              return 0xfffffffd;
            }
            uVar5 = 0xffffffff;
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
          goto LAB_0012aa2e;
        }
      }
    }
  }
  uVar5 = 0xffffffff;
LAB_0012aa2e:
  *param_3 = 0;
  return uVar5;
}

