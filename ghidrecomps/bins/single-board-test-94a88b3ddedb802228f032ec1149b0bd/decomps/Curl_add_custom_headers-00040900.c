
int Curl_add_custom_headers(int *param_1,int param_2,undefined4 param_3)

{
  byte *pbVar1;
  char *pcVar2;
  ushort **ppuVar3;
  int iVar4;
  int iVar5;
  char **ppcVar6;
  char *__s;
  uint uVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  char **local_2c;
  
  iVar5 = *param_1;
  if (param_2 == 0) {
    if ((*(char *)(param_1 + 0x7c) != '\0') && (*(char *)((int)param_1 + 0x1fa) == '\0')) {
      uVar8 = 1;
      ppcVar6 = *(char ***)(iVar5 + 0x240);
      if (*(char *)(iVar5 + 0x24c) != '\0') {
        uVar8 = 2;
        local_2c = *(char ***)(iVar5 + 0x244);
      }
      goto LAB_0004092c;
    }
  }
  else if (*(char *)(iVar5 + 0x24c) != '\0') {
    ppcVar6 = *(char ***)(iVar5 + 0x244);
    uVar8 = 1;
    goto LAB_0004092c;
  }
  uVar8 = 1;
  ppcVar6 = *(char ***)(iVar5 + 0x240);
LAB_0004092c:
  iVar9 = 0;
  do {
    while (ppcVar6 == (char **)0x0) {
      if (uVar8 <= iVar9 + 1U) {
        return 0;
      }
      iVar9 = 1;
      ppcVar6 = local_2c;
    }
    __s = *ppcVar6;
    pcVar2 = strchr(__s,0x3a);
    if (pcVar2 == (char *)0x0) {
      pcVar2 = strchr(__s,0x3b);
      if (pcVar2 != (char *)0x0) {
        uVar7 = (uint)(byte)pcVar2[1];
        pbVar10 = (byte *)(pcVar2 + 1);
        if (uVar7 != 0) {
          ppuVar3 = __ctype_b_loc();
          pbVar1 = (byte *)(pcVar2 + 2);
          do {
            pbVar10 = pbVar1;
            if (-1 < (int)((uint)(*ppuVar3)[uVar7] << 0x12)) goto LAB_000409ac;
            uVar7 = (uint)*pbVar10;
            pbVar1 = pbVar10 + 1;
          } while (uVar7 != 0);
        }
        if (pbVar10[-1] == 0x3b) {
          pbVar10[-1] = 0x3a;
          iVar4 = Curl_add_bufferf(param_3,DAT_00040a8c,*ppcVar6);
joined_r0x00040a0e:
          if (iVar4 != 0) {
            return iVar4;
          }
        }
      }
    }
    else {
      uVar7 = (uint)(byte)pcVar2[1];
      pbVar10 = (byte *)(pcVar2 + 1);
      if (uVar7 != 0) {
        ppuVar3 = __ctype_b_loc();
        do {
          if (-1 < (int)((uint)(*ppuVar3)[uVar7] << 0x12)) {
            if (param_1[0x91] != 0) {
              iVar4 = Curl_raw_nequal(DAT_00040a84,__s,5);
              if (iVar4 != 0) break;
              __s = *ppcVar6;
            }
            if (*(int *)(iVar5 + 0x278) == 3) {
              iVar4 = Curl_raw_nequal(DAT_00040a94,__s,0xd);
              if (iVar4 != 0) break;
              __s = *ppcVar6;
            }
            if (*(char *)((int)param_1 + 0x1fb) != '\0') {
              iVar4 = Curl_raw_nequal(DAT_00040a90,__s,0xe);
              if (iVar4 != 0) break;
              __s = *ppcVar6;
            }
            if (param_1[0x94] != 0) {
              iVar4 = Curl_raw_nequal(DAT_00040a88,__s,10);
              if (iVar4 != 0) break;
              __s = *ppcVar6;
            }
            iVar4 = Curl_add_bufferf(param_3,DAT_00040a8c,__s);
            goto joined_r0x00040a0e;
          }
          pbVar10 = pbVar10 + 1;
          uVar7 = (uint)*pbVar10;
        } while (uVar7 != 0);
      }
    }
LAB_000409ac:
    ppcVar6 = (char **)ppcVar6[1];
  } while( true );
}

