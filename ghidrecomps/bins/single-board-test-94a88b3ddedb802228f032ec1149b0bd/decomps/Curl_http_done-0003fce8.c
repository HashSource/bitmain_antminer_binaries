
int Curl_http_done(int *param_1,int param_2,int param_3)

{
  code **ppcVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = *param_1;
  iVar9 = *(int *)(iVar8 + 0x14c);
  Curl_unencode_cleanup();
  iVar5 = *(int *)(iVar8 + 0x1e8);
  param_1[0x9b] = *(int *)(iVar8 + 400);
  param_1[0x9c] = iVar5;
  ppcVar1 = DAT_0003fdc4;
  if (iVar9 != 0) {
    puVar6 = *(undefined4 **)(iVar9 + 0x5c);
    if (puVar6 != (undefined4 *)0x0) {
      (**DAT_0003fdc4)(*puVar6);
      (**ppcVar1)(puVar6);
      *(undefined4 *)(iVar9 + 0x5c) = 0;
    }
    if (*(int *)(iVar8 + 0x278) == 3) {
      uVar3 = *(uint *)(iVar9 + 0x20);
      iVar7 = *(int *)(iVar9 + 0x24);
      uVar2 = *(uint *)(iVar9 + 0x28);
      iVar5 = *(int *)(iVar9 + 0x2c);
      *(uint *)(iVar8 + 0x70) = uVar2 + uVar3;
      *(uint *)(iVar8 + 0x74) = iVar5 + iVar7 + (uint)CARRY4(uVar2,uVar3);
      Curl_formclean(iVar9);
      if (*(FILE **)(iVar9 + 0x38) != (FILE *)0x0) {
        fclose(*(FILE **)(iVar9 + 0x38));
        *(undefined4 *)(iVar9 + 0x38) = 0;
      }
    }
    else if (*(int *)(iVar8 + 0x278) == 4) {
      uVar3 = *(uint *)(iVar9 + 0x20);
      iVar7 = *(int *)(iVar9 + 0x24);
      uVar2 = *(uint *)(iVar9 + 0x28);
      iVar5 = *(int *)(iVar9 + 0x2c);
      *(uint *)(iVar8 + 0x70) = uVar2 + uVar3;
      *(uint *)(iVar8 + 0x74) = iVar5 + iVar7 + (uint)CARRY4(uVar2,uVar3);
    }
    if (param_2 != 0) {
      return param_2;
    }
    if (((param_3 == 0) && (*(char *)((int)param_1 + 0x1f9) == '\0')) &&
       (*(char *)(iVar8 + 0x329) == '\0')) {
      uVar2 = *(uint *)(iVar8 + 0x80);
      uVar3 = *(uint *)(iVar8 + 0x84);
      uVar4 = *(uint *)(iVar9 + 0x20) + uVar2;
      iVar5 = ((*(int *)(iVar9 + 0x24) +
               ((int)uVar2 >> 0x1f) + (uint)CARRY4(*(uint *)(iVar9 + 0x20),uVar2)) -
              ((int)uVar3 >> 0x1f)) - (uint)(uVar4 < uVar3);
      if ((int)(iVar5 - (uint)(uVar4 == uVar3)) < 0 !=
          (SBORROW4(iVar5,(uint)(uVar4 == uVar3)) != false)) {
        Curl_failf(iVar8,DAT_0003fdc8);
        return 0x34;
      }
    }
  }
  return 0;
}

