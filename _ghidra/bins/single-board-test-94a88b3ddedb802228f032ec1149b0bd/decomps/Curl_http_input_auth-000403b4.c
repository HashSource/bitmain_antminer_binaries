
undefined4 Curl_http_input_auth(int *param_1,int param_2,byte *param_3)

{
  int iVar1;
  ushort **ppuVar2;
  byte *pbVar3;
  byte bVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  
  iVar8 = *param_1;
  if (param_2 == 0) {
    puVar6 = (uint *)(iVar8 + 0x8714);
    iVar5 = iVar8 + 0x8620;
  }
  else {
    puVar6 = (uint *)(iVar8 + 0x8710);
    iVar5 = iVar8 + 0x8630;
  }
  bVar4 = *param_3;
  do {
    if (bVar4 == 0) {
      return 0;
    }
    iVar1 = Curl_raw_nequal(&DAT_00135cc0,param_3,4);
    if (iVar1 == 0) {
      iVar1 = Curl_raw_nequal("Digest",param_3,6);
      if (iVar1 == 0) {
        iVar1 = Curl_raw_nequal("Basic",param_3,5);
        if (iVar1 != 0) {
          *puVar6 = *puVar6 | 1;
          *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) | 1;
          if (*(int *)(iVar5 + 4) == 1) {
            *(undefined4 *)(iVar5 + 8) = 0;
            Curl_infof(iVar8,"Authentication problem. Ignoring this.\n");
            *(undefined1 *)(iVar8 + 0x8640) = 1;
            bVar4 = *param_3;
            goto LAB_00040410;
          }
        }
        goto LAB_0004040c;
      }
      if (-1 < *(int *)(iVar5 + 8) << 0x1e) {
        *puVar6 = *puVar6 | 2;
        *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) | 2;
        iVar1 = Curl_input_digest(param_1,param_2,param_3);
        if (iVar1 != 0) goto LAB_0004054c;
        goto LAB_0004040c;
      }
      Curl_infof(iVar8,"Ignoring duplicate digest auth header.\n");
      bVar4 = *param_3;
LAB_00040410:
      if (bVar4 != 0 && bVar4 != 0x2c) {
        do {
          param_3 = param_3 + 1;
          bVar4 = *param_3;
        } while (bVar4 != 0x2c && bVar4 != 0);
      }
      if (bVar4 == 0x2c) {
        param_3 = param_3 + 1;
      }
    }
    else {
      *puVar6 = *puVar6 | 8;
      *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) | 8;
      if (*(int *)(iVar5 + 4) != 8 && *(int *)(iVar5 + 4) != 0x20) {
LAB_0004040c:
        bVar4 = *param_3;
        goto LAB_00040410;
      }
      iVar1 = Curl_input_ntlm(param_1,param_2,param_3);
      if (iVar1 != 0) {
LAB_0004054c:
        Curl_infof(iVar8,"Authentication problem. Ignoring this.\n");
        *(undefined1 *)(iVar8 + 0x8640) = 1;
        goto LAB_0004040c;
      }
      iVar1 = *(int *)(iVar5 + 4);
      *(undefined1 *)(iVar8 + 0x8640) = 0;
      if (iVar1 != 0x20) goto LAB_0004040c;
      *puVar6 = *puVar6 & 0xfffffff7;
      *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) & 0xfffffff7;
      *puVar6 = *puVar6 | 0x20;
      *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) | 0x20;
      uVar7 = (uint)*param_3;
      if (uVar7 != 0) {
        ppuVar2 = __ctype_b_loc();
        do {
          pbVar3 = param_3 + 1;
          if (-1 < (int)((uint)(*ppuVar2)[uVar7] << 0x12)) break;
          uVar7 = (uint)param_3[1];
          param_3 = pbVar3;
        } while (uVar7 != 0);
      }
      iVar1 = Curl_raw_nequal(&DAT_00135cc0,param_3,4);
      if (iVar1 == 0) goto LAB_0004040c;
      uVar7 = (uint)param_3[4];
      param_3 = param_3 + 4;
      if (uVar7 != 0) {
        ppuVar2 = __ctype_b_loc();
        do {
          if (-1 < (int)((uint)(*ppuVar2)[uVar7] << 0x12)) {
            iVar1 = (*Curl_cstrdup)(param_3);
            param_1[0xab] = iVar1;
            if (iVar1 == 0) {
              return 0x1b;
            }
            goto LAB_0004040c;
          }
          param_3 = param_3 + 1;
          uVar7 = (uint)*param_3;
        } while (uVar7 != 0);
      }
    }
    uVar7 = (uint)*param_3;
    if (uVar7 == 0) {
      return 0;
    }
    ppuVar2 = __ctype_b_loc();
    while ((int)((uint)(*ppuVar2)[uVar7] << 0x12) < 0) {
      uVar7 = (uint)param_3[1];
      param_3 = param_3 + 1;
      if (uVar7 == 0) {
        return 0;
      }
    }
    bVar4 = *param_3;
  } while( true );
}

