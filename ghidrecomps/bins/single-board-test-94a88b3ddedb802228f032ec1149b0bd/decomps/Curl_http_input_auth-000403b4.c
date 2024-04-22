
undefined4 Curl_http_input_auth(int *param_1,int param_2,byte *param_3)

{
  code **ppcVar1;
  int iVar2;
  ushort **ppuVar3;
  byte *pbVar4;
  byte bVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  
  ppcVar1 = DAT_000405bc;
  iVar9 = *param_1;
  if (param_2 == 0) {
    puVar7 = (uint *)(iVar9 + 0x8714);
    iVar6 = iVar9 + 0x8620;
  }
  else {
    puVar7 = (uint *)(iVar9 + 0x8710);
    iVar6 = iVar9 + 0x8630;
  }
  bVar5 = *param_3;
  do {
    if (bVar5 == 0) {
      return 0;
    }
    iVar2 = Curl_raw_nequal(DAT_000405a8,param_3,4);
    if (iVar2 == 0) {
      iVar2 = Curl_raw_nequal(DAT_000405ac,param_3,6);
      if (iVar2 == 0) {
        iVar2 = Curl_raw_nequal(DAT_000405b8,param_3);
        if (iVar2 != 0) {
          *puVar7 = *puVar7 | 1;
          *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) | 1;
          if (*(int *)(iVar6 + 4) == 1) {
            *(undefined4 *)(iVar6 + 8) = 0;
            Curl_infof(iVar9,DAT_000405b4);
            *(undefined *)(iVar9 + 0x8640) = 1;
            bVar5 = *param_3;
            goto LAB_00040410;
          }
        }
        goto LAB_0004040c;
      }
      if (-1 < *(int *)(iVar6 + 8) << 0x1e) {
        *puVar7 = *puVar7 | 2;
        *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) | 2;
        iVar2 = Curl_input_digest(param_1,param_2);
        if (iVar2 != 0) goto LAB_0004054c;
        goto LAB_0004040c;
      }
      Curl_infof(iVar9,DAT_000405b0);
      bVar5 = *param_3;
LAB_00040410:
      if (bVar5 != 0 && bVar5 != 0x2c) {
        do {
          param_3 = param_3 + 1;
          bVar5 = *param_3;
        } while (bVar5 != 0x2c && bVar5 != 0);
      }
      if (bVar5 == 0x2c) {
        param_3 = param_3 + 1;
      }
    }
    else {
      *puVar7 = *puVar7 | 8;
      *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) | 8;
      if (*(int *)(iVar6 + 4) != 8 && *(int *)(iVar6 + 4) != 0x20) {
LAB_0004040c:
        bVar5 = *param_3;
        goto LAB_00040410;
      }
      iVar2 = Curl_input_ntlm(param_1,param_2);
      if (iVar2 != 0) {
LAB_0004054c:
        Curl_infof(iVar9,DAT_000405b4);
        *(undefined *)(iVar9 + 0x8640) = 1;
        goto LAB_0004040c;
      }
      iVar2 = *(int *)(iVar6 + 4);
      *(undefined *)(iVar9 + 0x8640) = 0;
      if (iVar2 != 0x20) goto LAB_0004040c;
      *puVar7 = *puVar7 & 0xfffffff7;
      *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & 0xfffffff7;
      *puVar7 = *puVar7 | 0x20;
      *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) | 0x20;
      uVar8 = (uint)*param_3;
      if (uVar8 != 0) {
        ppuVar3 = __ctype_b_loc();
        do {
          pbVar4 = param_3 + 1;
          if (-1 < (int)((uint)(*ppuVar3)[uVar8] << 0x12)) break;
          uVar8 = (uint)param_3[1];
          param_3 = pbVar4;
        } while (uVar8 != 0);
      }
      iVar2 = Curl_raw_nequal(DAT_000405a8,param_3);
      if (iVar2 == 0) goto LAB_0004040c;
      uVar8 = (uint)param_3[4];
      param_3 = param_3 + 4;
      if (uVar8 != 0) {
        ppuVar3 = __ctype_b_loc();
        do {
          if (-1 < (int)((uint)(*ppuVar3)[uVar8] << 0x12)) {
            iVar2 = (**ppcVar1)(param_3);
            param_1[0xab] = iVar2;
            if (iVar2 == 0) {
              return 0x1b;
            }
            goto LAB_0004040c;
          }
          param_3 = param_3 + 1;
          uVar8 = (uint)*param_3;
        } while (uVar8 != 0);
      }
    }
    uVar8 = (uint)*param_3;
    if (uVar8 == 0) {
      return 0;
    }
    ppuVar3 = __ctype_b_loc();
    while ((int)((uint)(*ppuVar3)[uVar8] << 0x12) < 0) {
      uVar8 = (uint)param_3[1];
      param_3 = param_3 + 1;
      if (uVar8 == 0) {
        return 0;
      }
    }
    bVar5 = *param_3;
  } while( true );
}

