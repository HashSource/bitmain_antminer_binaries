
undefined4 addr_contains_part_1(undefined4 param_1,undefined4 param_2,size_t param_3)

{
  byte *__s;
  byte bVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  uint *puVar5;
  int iVar6;
  size_t sVar7;
  size_t __n;
  uint uVar8;
  size_t *psVar9;
  uint __n_00;
  undefined4 *puVar10;
  int iVar11;
  byte *pbVar12;
  byte *local_80;
  size_t local_78;
  undefined4 local_6c;
  undefined1 auStack_68 [15];
  byte abStack_59 [16];
  byte abStack_49 [16];
  byte abStack_39 [21];
  
  iVar6 = 0;
  __s = abStack_49 + 1;
  iVar11 = 0;
  iVar2 = OPENSSL_sk_num(param_2);
  if (0 < iVar2) {
    do {
      piVar3 = (int *)OPENSSL_sk_value(param_2,iVar6);
      if (piVar3 == (int *)0x0) {
        return 0xffffffff;
      }
      if (*piVar3 == 0) {
        psVar9 = (size_t *)piVar3[1];
        sVar7 = *psVar9;
        if ((int)param_3 < (int)sVar7 || (int)sVar7 < 0) {
          return 0xffffffff;
        }
        if (sVar7 == 0) {
          memset(__s,0,param_3);
          __n = param_3;
        }
        else {
          pvVar4 = (void *)psVar9[2];
          memcpy(__s,pvVar4,sVar7);
          if ((psVar9[3] & 7) == 0) {
            memset(__s + sVar7,0,param_3 - sVar7);
            memcpy(abStack_39 + 1,pvVar4,sVar7);
            __n = param_3 - sVar7;
          }
          else {
            iVar2 = sVar7 - 1;
            bVar1 = (byte)(0xff >> (8 - (psVar9[3] & 7) & 0xff));
            __s[iVar2] = __s[iVar2] & ~bVar1;
            pbVar12 = abStack_39 + 1;
            memset(__s + sVar7,0,param_3 - sVar7);
            memcpy(pbVar12,pvVar4,sVar7);
            pbVar12[iVar2] = bVar1 | pbVar12[iVar2];
            __n = param_3 - sVar7;
          }
        }
        memset(abStack_39 + sVar7 + 1,0xff,__n);
      }
      else {
        if (*piVar3 != 1) {
          return 0xffffffff;
        }
        puVar10 = (undefined4 *)piVar3[1];
        psVar9 = (size_t *)*puVar10;
        sVar7 = *psVar9;
        if ((int)param_3 < (int)sVar7 || (int)sVar7 < 0) {
          return 0xffffffff;
        }
        if (sVar7 != 0) {
          memcpy(__s,(void *)psVar9[2],sVar7);
          if ((psVar9[3] & 7) != 0) {
            __s[sVar7 - 1] = __s[sVar7 - 1] & ~(byte)(0xff >> (8 - (psVar9[3] & 7) & 0xff));
          }
        }
        memset(__s + sVar7,0,param_3 - sVar7);
        psVar9 = (size_t *)puVar10[1];
        sVar7 = *psVar9;
        if ((int)param_3 < (int)sVar7 || (int)sVar7 < 0) {
          return 0xffffffff;
        }
        pbVar12 = abStack_39 + 1;
        if (sVar7 != 0) {
          memcpy(pbVar12,(void *)psVar9[2],sVar7);
          if ((psVar9[3] & 7) != 0) {
            pbVar12[sVar7 - 1] = (byte)(0xff >> (8 - (psVar9[3] & 7) & 0xff)) | pbVar12[sVar7 - 1];
          }
        }
        memset(pbVar12 + sVar7,0xff,param_3 - sVar7);
      }
      local_80 = abStack_39 + 1;
      while( true ) {
        iVar2 = OPENSSL_sk_num(param_1);
        if (iVar2 <= iVar11) {
          return 0;
        }
        piVar3 = (int *)OPENSSL_sk_value(param_1,iVar11);
        if (piVar3 == (int *)0x0) {
          return 0;
        }
        if (*piVar3 == 0) {
          puVar5 = (uint *)piVar3[1];
          __n_00 = *puVar5;
          uVar8 = __n_00 >> 0x1f;
          if ((int)param_3 < (int)__n_00) {
            uVar8 = 1;
          }
          if (uVar8 != 0) {
            return 0;
          }
          if (__n_00 == 0) {
            memset(auStack_68,0,param_3);
            local_78 = param_3;
          }
          else {
            pvVar4 = (void *)puVar5[2];
            memcpy(auStack_68,pvVar4,__n_00);
            if ((puVar5[3] & 7) == 0) {
              local_78 = param_3 - __n_00;
              memset(auStack_68 + __n_00,0,local_78);
              memcpy(abStack_59 + 1,pvVar4,__n_00);
            }
            else {
              local_6c = __n_00 - 1;
              local_78 = param_3 - __n_00;
              bVar1 = (byte)(0xff >> (8 - (puVar5[3] & 7) & 0xff));
              auStack_68[local_6c] = auStack_68[local_6c] & ~bVar1;
              pbVar12 = abStack_59 + 1;
              memset(auStack_68 + __n_00,0,param_3 - __n_00);
              memcpy(pbVar12,pvVar4,__n_00);
              pbVar12[local_6c] = pbVar12[local_6c] | bVar1;
            }
          }
          memset(abStack_59 + __n_00 + 1,0xff,local_78);
        }
        else {
          if (*piVar3 != 1) {
            return 0;
          }
          puVar10 = (undefined4 *)piVar3[1];
          psVar9 = (size_t *)*puVar10;
          sVar7 = *psVar9;
          if ((int)param_3 < (int)sVar7 || (int)sVar7 < 0) {
            return 0;
          }
          if (sVar7 != 0) {
            memcpy(auStack_68,(void *)psVar9[2],sVar7);
            if ((psVar9[3] & 7) != 0) {
              auStack_68[sVar7 - 1] =
                   auStack_68[sVar7 - 1] & ~(byte)(0xff >> (8 - (psVar9[3] & 7) & 0xff));
            }
          }
          memset(auStack_68 + sVar7,0,param_3 - sVar7);
          psVar9 = (size_t *)puVar10[1];
          sVar7 = *psVar9;
          if ((int)param_3 < (int)sVar7 || (int)sVar7 < 0) {
            return 0;
          }
          pbVar12 = abStack_59 + 1;
          if (sVar7 != 0) {
            memcpy(pbVar12,(void *)psVar9[2],sVar7);
            if ((psVar9[3] & 7) != 0) {
              pbVar12[sVar7 - 1] = (byte)(0xff >> (8 - (psVar9[3] & 7) & 0xff)) | pbVar12[sVar7 - 1]
              ;
            }
          }
          memset(pbVar12 + sVar7,0xff,param_3 - sVar7);
        }
        iVar2 = memcmp(abStack_59 + 1,local_80,param_3);
        if (-1 < iVar2) break;
        iVar11 = iVar11 + 1;
      }
      iVar2 = memcmp(auStack_68,__s,param_3);
      if (0 < iVar2) {
        return 0;
      }
      iVar6 = iVar6 + 1;
      iVar2 = OPENSSL_sk_num(param_2);
    } while (iVar6 < iVar2);
  }
  return 1;
}

