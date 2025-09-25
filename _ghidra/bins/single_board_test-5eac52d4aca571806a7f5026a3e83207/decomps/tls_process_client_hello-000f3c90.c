
undefined4 tls_process_client_hello(int param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  int *ptr;
  uint uVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  void *__src;
  size_t __n;
  uint uVar13;
  int iVar14;
  int local_28;
  int iStack_24;
  
  if (((*(int *)(param_1 + 0x5ec) == 0) &&
      (iVar9 = *(int *)(param_1 + 0x7c), *(int *)(iVar9 + 0x180) != 0)) &&
     (*(int *)(iVar9 + 0x204) != 0)) {
    if ((*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) ||
       (iVar12 = **(int **)(param_1 + 4), iVar12 < 0x304 || iVar12 == 0x10000)) {
      if ((*(int *)(param_1 + 0x4ec) << 1 < 0) ||
         ((*(int *)(iVar9 + 0x338) == 0 && (-1 < *(int *)(param_1 + 0x4ec) << 0xd)))) {
        ssl3_send_alert(param_1,1,100);
        return 1;
      }
      *(undefined4 *)(param_1 + 0x5ec) = 1;
      *(undefined4 *)(param_1 + 0x20) = 1;
      goto LAB_000f3ca8;
    }
    ossl_statem_fatal(param_1,0x50,0x17d,0x44,"ssl/statem/statem_srvr.c",0x572);
  }
  else {
LAB_000f3ca8:
    ptr = (int *)CRYPTO_zalloc(0x26c,"ssl/statem/statem_srvr.c",0x580);
    if (ptr != (int *)0x0) {
      iVar9 = RECORD_LAYER_is_sslv2_record(param_1 + 0x650);
      *ptr = iVar9;
      if (iVar9 == 0) {
        uVar11 = param_2[1];
LAB_000f3da0:
        if (uVar11 < 2) {
          ossl_statem_fatal(param_1,0x32,0x17d,0xa0,"ssl/statem/statem_srvr.c",0x5b5);
        }
        else {
          pbVar8 = (byte *)*param_2;
          bVar1 = *pbVar8;
          ptr[1] = (uint)bVar1 << 8;
          ptr[1] = (uint)CONCAT11(bVar1,pbVar8[1]);
          iVar12 = param_2[1];
          *param_2 = (int)(pbVar8 + 2);
          uVar11 = iVar12 - 2;
          param_2[1] = uVar11;
          if (iVar9 == 0) {
            if (uVar11 < 0x20) {
LAB_000f3eb6:
              uVar10 = 0x5f8;
            }
            else {
              iVar14 = *(int *)(pbVar8 + 6);
              iVar12 = *(int *)(pbVar8 + 10);
              iVar9 = *(int *)(pbVar8 + 0xe);
              ptr[2] = *(int *)(pbVar8 + 2);
              ptr[3] = iVar14;
              ptr[4] = iVar12;
              ptr[5] = iVar9;
              iVar9 = *(int *)(pbVar8 + 0x1e);
              iVar12 = *(int *)(pbVar8 + 0x12);
              iVar14 = *(int *)(pbVar8 + 0x16);
              ptr[8] = *(int *)(pbVar8 + 0x1a);
              ptr[9] = iVar9;
              ptr[6] = iVar12;
              ptr[7] = iVar14;
              iVar9 = *param_2;
              iVar14 = param_2[1];
              iVar12 = iVar14 + -0x20;
              param_2[1] = iVar12;
              *param_2 = iVar9 + 0x20;
              if (iVar12 == 0) goto LAB_000f3eb6;
              uVar11 = (uint)*(byte *)(iVar9 + 0x20);
              uVar6 = iVar14 - 0x21;
              if (uVar6 < uVar11) goto LAB_000f3eb6;
              param_2[1] = uVar6 - uVar11;
              *param_2 = iVar9 + 0x21 + uVar11;
              if (0x20 < uVar11) {
                ptr[10] = 0;
                goto LAB_000f3eb6;
              }
              ptr[10] = uVar11;
              memcpy(ptr + 0xb,(void *)(iVar9 + 0x21),uVar11);
              if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0) {
                if (param_2[1] != 0) {
                  uVar6 = param_2[1] - 1;
                  pbVar8 = (byte *)*param_2 + 1;
                  uVar11 = (uint)*(byte *)*param_2;
                  if (uVar11 <= uVar6) {
                    param_2[1] = uVar6 - uVar11;
                    *param_2 = (int)(pbVar8 + uVar11);
                    ptr[0x13] = uVar11;
                    memcpy(ptr + 0x14,pbVar8,uVar11);
                    iVar9 = SSL_get_options(param_1);
                    if ((iVar9 << 0x12 < 0) && (ptr[0x13] == 0)) {
                      CRYPTO_free(ptr);
                      return 1;
                    }
                    goto LAB_000f3f72;
                  }
                }
                uVar10 = 0x5ff;
              }
              else {
LAB_000f3f72:
                if (1 < (uint)param_2[1]) {
                  puVar7 = (undefined1 *)*param_2;
                  uVar6 = param_2[1] - 2;
                  uVar11 = (uint)CONCAT11(*puVar7,puVar7[1]);
                  if (uVar11 <= uVar6) {
                    *param_2 = (int)(puVar7 + 2 + uVar11);
                    param_2[1] = uVar6 - uVar11;
                    ptr[0x54] = (int)(puVar7 + 2);
                    ptr[0x55] = uVar11;
                    if (param_2[1] != 0) {
                      uVar11 = param_2[1] - 1;
                      pbVar8 = (byte *)*param_2 + 1;
                      __n = (size_t)*(byte *)*param_2;
                      if (__n <= uVar11) {
                        iVar9 = uVar11 - __n;
                        *param_2 = (int)(pbVar8 + __n);
                        param_2[1] = iVar9;
                        if (iVar9 == 0) {
                          ptr[0x97] = 0;
                          ptr[0x98] = 0;
                        }
                        else {
                          iVar9 = PACKET_get_length_prefixed_2(param_2,ptr + 0x97);
                          if ((iVar9 == 0) || (param_2[1] != 0)) {
                            uVar10 = 0x629;
                            goto LAB_000f3ebe;
                          }
                        }
LAB_000f4016:
                        ptr[0x56] = __n;
                        memcpy(ptr + 0x57,pbVar8,__n);
                        local_28 = ptr[0x97];
                        iStack_24 = ptr[0x98];
                        iVar9 = tls_collect_extensions
                                          (param_1,&local_28,0x80,ptr + 0x9a,ptr + 0x99,1);
                        if (iVar9 != 0) {
                          *(int **)(param_1 + 0x5c8) = ptr;
                          return 2;
                        }
                        goto LAB_000f3d78;
                      }
                    }
                    uVar10 = 0x61e;
                    goto LAB_000f3ebe;
                  }
                }
                uVar10 = 0x618;
              }
            }
LAB_000f3ebe:
            ossl_statem_fatal(param_1,0x32,0x17d,0x9f,"ssl/statem/statem_srvr.c",uVar10);
          }
          else {
            if (uVar11 < 2) {
LAB_000f3e62:
              uVar10 = 0x5c7;
            }
            else {
              bVar2 = pbVar8[2];
              bVar1 = pbVar8[3];
              *param_2 = (int)(pbVar8 + 4);
              param_2[1] = iVar12 - 4U;
              if (iVar12 - 4U < 2) goto LAB_000f3e62;
              bVar3 = pbVar8[4];
              bVar4 = pbVar8[5];
              *param_2 = (int)(pbVar8 + 6);
              param_2[1] = iVar12 - 6U;
              if (iVar12 - 6U < 2) goto LAB_000f3e62;
              uVar11 = (uint)CONCAT11(bVar3,bVar4);
              bVar4 = pbVar8[6];
              bVar3 = pbVar8[7];
              *param_2 = (int)(pbVar8 + 8);
              param_2[1] = iVar12 - 8U;
              if (0x20 < uVar11) {
                ossl_statem_fatal(param_1,0x2f,0x17d,0x9f,"ssl/statem/statem_srvr.c",0x5cd);
                goto LAB_000f3d78;
              }
              uVar6 = (uint)CONCAT11(bVar2,bVar1);
              if (uVar6 <= iVar12 - 8U) {
                ptr[0x55] = uVar6;
                ptr[0x54] = (int)(pbVar8 + 8);
                iVar9 = *param_2;
                iVar12 = param_2[1];
                *param_2 = (int)(iVar9 + uVar6);
                param_2[1] = iVar12 - uVar6;
                if (uVar11 <= iVar12 - uVar6) {
                  uVar13 = (uint)CONCAT11(bVar4,bVar3);
                  memcpy(ptr + 0xb,(void *)(iVar9 + uVar6),uVar11);
                  uVar6 = param_2[1] - uVar11;
                  __src = (void *)(*param_2 + uVar11);
                  *param_2 = (int)__src;
                  param_2[1] = uVar6;
                  if (uVar13 <= uVar6) {
                    param_2[1] = uVar6 - uVar13;
                    *param_2 = (int)__src + uVar13;
                    if (uVar6 - uVar13 == 0) {
                      ptr[10] = uVar11;
                      uVar11 = uVar13;
                      if (0x1f < uVar13) {
                        uVar11 = 0x20;
                      }
                      memset(ptr + 2,0,0x20);
                      if (uVar13 < uVar11) {
                        uVar10 = 0x5eb;
                        goto LAB_000f3cf6;
                      }
                      memcpy((void *)((0x20 - uVar11) + (int)(ptr + 2)),__src,uVar11);
                      ptr[0x97] = 0;
                      ptr[0x98] = 0;
                      __n = 1;
                      pbVar8 = &null_compression_26978;
                      goto LAB_000f4016;
                    }
                  }
                }
              }
              uVar10 = 0x5d8;
            }
            ossl_statem_fatal(param_1,0x32,0x17d,0xd5,"ssl/statem/statem_srvr.c",uVar10);
          }
        }
      }
      else if (((*(int *)(*(int *)(param_1 + 0x7c) + 0x180) == 0) ||
               (*(int *)(*(int *)(param_1 + 0x7c) + 0x204) == 0)) &&
              (*(int *)(param_1 + 0x44c) == 0)) {
        if (param_2[1] != 0) {
          uVar11 = param_2[1] - 1;
          cVar5 = *(char *)*param_2;
          *param_2 = (int)((char *)*param_2 + 1);
          param_2[1] = uVar11;
          if (cVar5 == '\x01') goto LAB_000f3da0;
        }
        uVar10 = 0x5ae;
LAB_000f3cf6:
        ossl_statem_fatal(param_1,0x50,0x17d,0x44,"ssl/statem/statem_srvr.c",uVar10);
      }
      else {
        ossl_statem_fatal(param_1,10,0x17d,0xf4,"ssl/statem/statem_srvr.c",0x593);
      }
LAB_000f3d78:
      CRYPTO_free((void *)ptr[0x9a]);
      goto LAB_000f3d88;
    }
    ossl_statem_fatal(param_1,0x50,0x17d,0x44,"ssl/statem/statem_srvr.c",0x583);
  }
  ptr = (int *)0x0;
LAB_000f3d88:
  CRYPTO_free(ptr);
  return 0;
}

