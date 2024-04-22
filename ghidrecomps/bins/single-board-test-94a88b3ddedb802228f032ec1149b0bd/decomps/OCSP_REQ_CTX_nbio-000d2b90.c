
/* WARNING: Type propagation algorithm not settling */

int OCSP_REQ_CTX_nbio(uint *param_1)

{
  byte bVar1;
  size_t sVar2;
  void *pvVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  ushort **ppuVar7;
  ulong uVar8;
  byte *pbVar9;
  ushort *puVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  bool bVar14;
  byte *local_30;
  byte *local_2c [2];
  
  uVar12 = *param_1;
  do {
    while( true ) {
      if ((uVar12 & 0x1000) == 0) {
        iVar5 = BIO_read((BIO *)param_1[3],(void *)param_1[1],param_1[2]);
        if (iVar5 < 1) {
          iVar5 = BIO_test_flags((BIO *)param_1[3],8);
          if (iVar5 == 0) {
            return 0;
          }
          goto LAB_000d2ef0;
        }
        iVar6 = BIO_write((BIO *)param_1[4],(void *)param_1[1],iVar5);
        if (iVar6 != iVar5) {
          return 0;
        }
        uVar12 = *param_1;
      }
      if (uVar12 == 0x1005) break;
      if (0x1005 < (int)uVar12) {
        if (uVar12 != 0x1007) {
          if (0x1006 < (int)uVar12) {
            if (uVar12 == 0x1008) {
              return 1;
            }
            if (uVar12 != 0x1009) {
              return 0;
            }
            iVar5 = BIO_write((BIO *)param_1[4],DAT_000d2ef8,2);
            if (iVar5 != 2) goto LAB_000d2d58;
            *param_1 = 0x1005;
            break;
          }
          goto LAB_000d2cc2;
        }
        goto LAB_000d2d28;
      }
      if (uVar12 == 3) {
LAB_000d2c30:
        lVar4 = BIO_ctrl((BIO *)param_1[4],3,0,&local_30);
        pbVar13 = local_30;
        if (1 < lVar4) {
          if (*local_30 != 0x30) goto LAB_000d2d58;
          uVar12 = (uint)local_30[1];
          bVar14 = -1 < (int)(uVar12 << 0x18);
          if (bVar14) {
            uVar12 = uVar12 + 2;
          }
          if (bVar14) {
            param_1[5] = uVar12;
            local_30 = local_30 + 1;
          }
          else {
            pbVar13 = local_30 + 1;
            if (lVar4 < 6) goto LAB_000d2cea;
            uVar12 = uVar12 & 0x7f;
            if (3 < uVar12 - 1) {
LAB_000d2d58:
              *param_1 = 0x1000;
              return 0;
            }
            pbVar9 = local_30 + 2;
            uVar11 = 0;
            pbVar13 = pbVar9;
            do {
              param_1[5] = uVar11 << 8;
              local_30 = pbVar13 + 1;
              uVar11 = (uint)*pbVar13 | uVar11 << 8;
              param_1[5] = uVar11;
              pbVar13 = local_30;
            } while (local_30 != pbVar9 + uVar12);
            if (param_1[6] < uVar11) goto LAB_000d2d58;
            param_1[5] = uVar11 + uVar12 + 2;
          }
          *param_1 = 4;
LAB_000d2c62:
          lVar4 = BIO_ctrl((BIO *)param_1[4],3,0,(void *)0x0);
          pbVar13 = local_30;
          if ((int)param_1[5] <= lVar4) {
            *param_1 = 0x1008;
            return 1;
          }
        }
      }
      else {
        if (3 < (int)uVar12) {
          if (uVar12 != 4) {
            return 0;
          }
          goto LAB_000d2c62;
        }
        if ((int)uVar12 < 1) {
          return 0;
        }
        while ((sVar2 = BIO_ctrl((BIO *)param_1[4],3,0,&local_30), 0 < (int)sVar2 &&
               (pvVar3 = memchr(local_30,10,sVar2), pvVar3 != (void *)0x0))) {
          uVar12 = BIO_gets((BIO *)param_1[4],(char *)param_1[1],param_1[2]);
          if ((int)uVar12 < 1) {
            iVar5 = BIO_test_flags((BIO *)param_1[4],8);
            pbVar13 = local_30;
            if (iVar5 != 0) goto LAB_000d2cea;
            iVar5 = 0;
            goto LAB_000d2eda;
          }
          if (param_1[2] == uVar12) goto LAB_000d2d58;
          if (*param_1 == 1) {
            pbVar13 = (byte *)param_1[1];
            uVar12 = (uint)*pbVar13;
            if (uVar12 == 0) {
LAB_000d2d8a:
              iVar5 = 0x10d;
LAB_000d2d4a:
              ERR_put_error(0x27,0x76,0x73,DAT_000d2efc,iVar5);
              goto LAB_000d2d58;
            }
            ppuVar7 = __ctype_b_loc();
            puVar10 = *ppuVar7;
            while (-1 < (int)((uint)puVar10[uVar12] << 0x12)) {
              pbVar13 = pbVar13 + 1;
              uVar12 = (uint)*pbVar13;
              if (uVar12 == 0) goto LAB_000d2d8a;
            }
            bVar1 = *pbVar13;
            while( true ) {
              if (bVar1 == 0) {
                iVar5 = 0x116;
                goto LAB_000d2d4a;
              }
              if (-1 < (int)((uint)puVar10[bVar1] << 0x12)) break;
              pbVar13 = pbVar13 + 1;
              bVar1 = *pbVar13;
            }
            bVar1 = *pbVar13;
            pbVar9 = pbVar13;
            while( true ) {
              if (bVar1 == 0) {
                iVar5 = 0x11f;
                goto LAB_000d2d4a;
              }
              if ((int)((uint)puVar10[bVar1] << 0x12) < 0) break;
              pbVar9 = pbVar9 + 1;
              bVar1 = *pbVar9;
            }
            *pbVar9 = 0;
            uVar8 = strtoul((char *)pbVar13,(char **)local_2c,10);
            if (*local_2c[0] != 0) goto LAB_000d2d58;
            uVar12 = (uint)pbVar9[1];
            pbVar9 = pbVar9 + 1;
            if (uVar12 != 0) {
              puVar10 = *ppuVar7;
LAB_000d2df8:
              if ((int)((uint)puVar10[uVar12] << 0x12) < 0) goto LAB_000d2df2;
              sVar2 = strlen((char *)pbVar9);
              local_2c[0] = pbVar9 + (sVar2 - 1);
              while ((int)((uint)puVar10[*local_2c[0]] << 0x12) < 0) {
                *local_2c[0] = 0;
                puVar10 = *ppuVar7;
                local_2c[0] = local_2c[0] + -1;
              }
            }
LAB_000d2e2e:
            if (uVar8 != 200) {
              ERR_put_error(0x27,0x76,0x72,DAT_000d2efc,0x13a);
              if (*pbVar9 == 0) {
                ERR_add_error_data(2,DAT_000d2f00,pbVar13);
              }
              else {
                ERR_add_error_data(4,DAT_000d2f00,pbVar13,DAT_000d2f04,pbVar9);
              }
              goto LAB_000d2d58;
            }
            *param_1 = 2;
          }
          else {
            local_30 = (byte *)param_1[1];
            bVar1 = *local_30;
            if (bVar1 == 0) {
LAB_000d2c2c:
              *param_1 = 3;
              goto LAB_000d2c30;
            }
            if (bVar1 == 10 || bVar1 == 0xd) {
              do {
                local_30 = local_30 + 1;
                bVar1 = *local_30;
                if (bVar1 == 0) goto LAB_000d2c2c;
              } while (bVar1 == 10 || bVar1 == 0xd);
            }
          }
        }
        pbVar13 = local_30;
        if ((int)param_1[2] <= (int)sVar2) goto LAB_000d2d58;
      }
LAB_000d2cea:
      local_30 = pbVar13;
      uVar12 = *param_1;
    }
    uVar12 = BIO_ctrl((BIO *)param_1[4],3,0,(void *)0x0);
    param_1[5] = uVar12;
    *param_1 = 0x1006;
LAB_000d2cc2:
    lVar4 = BIO_ctrl((BIO *)param_1[4],3,0,&local_30);
    iVar5 = BIO_write((BIO *)param_1[3],local_30 + (lVar4 - param_1[5]),param_1[5]);
    if (iVar5 < 1) {
LAB_000d2ed0:
      iVar5 = BIO_test_flags((BIO *)param_1[3],8);
      if (iVar5 == 0) {
LAB_000d2eda:
        *param_1 = 0x1000;
      }
      else {
LAB_000d2ef0:
        iVar5 = -1;
      }
      return iVar5;
    }
    uVar12 = param_1[5];
    param_1[5] = uVar12 - iVar5;
    pbVar13 = local_30;
    if (uVar12 - iVar5 != 0) goto LAB_000d2cea;
    *param_1 = 0x1007;
    BIO_ctrl((BIO *)param_1[4],1,0,(void *)0x0);
LAB_000d2d28:
    lVar4 = BIO_ctrl((BIO *)param_1[3],0xb,0,(void *)0x0);
    if (lVar4 < 1) goto LAB_000d2ed0;
    *param_1 = 1;
    uVar12 = 1;
  } while( true );
LAB_000d2df2:
  pbVar9 = pbVar9 + 1;
  uVar12 = (uint)*pbVar9;
  if (uVar12 == 0) goto LAB_000d2e2e;
  goto LAB_000d2df8;
}

