
int Curl_http_done(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = *param_1;
  iVar8 = *(int *)(iVar7 + 0x14c);
  Curl_unencode_cleanup();
  iVar4 = *(int *)(iVar7 + 0x1e8);
  param_1[0x9b] = *(int *)(iVar7 + 400);
  param_1[0x9c] = iVar4;
  if (iVar8 != 0) {
    puVar5 = *(undefined4 **)(iVar8 + 0x5c);
    if (puVar5 != (undefined4 *)0x0) {
      (*Curl_cfree)(*puVar5);
      (*Curl_cfree)(puVar5);
      *(undefined4 *)(iVar8 + 0x5c) = 0;
    }
    if (*(int *)(iVar7 + 0x278) == 3) {
      uVar2 = *(uint *)(iVar8 + 0x20);
      iVar6 = *(int *)(iVar8 + 0x24);
      uVar1 = *(uint *)(iVar8 + 0x28);
      iVar4 = *(int *)(iVar8 + 0x2c);
      *(uint *)(iVar7 + 0x70) = uVar1 + uVar2;
      *(uint *)(iVar7 + 0x74) = iVar4 + iVar6 + (uint)CARRY4(uVar1,uVar2);
      Curl_formclean(iVar8);
      if (*(FILE **)(iVar8 + 0x38) != (FILE *)0x0) {
        fclose(*(FILE **)(iVar8 + 0x38));
        *(undefined4 *)(iVar8 + 0x38) = 0;
      }
    }
    else if (*(int *)(iVar7 + 0x278) == 4) {
      uVar2 = *(uint *)(iVar8 + 0x20);
      iVar6 = *(int *)(iVar8 + 0x24);
      uVar1 = *(uint *)(iVar8 + 0x28);
      iVar4 = *(int *)(iVar8 + 0x2c);
      *(uint *)(iVar7 + 0x70) = uVar1 + uVar2;
      *(uint *)(iVar7 + 0x74) = iVar4 + iVar6 + (uint)CARRY4(uVar1,uVar2);
    }
    if (param_2 != 0) {
      return param_2;
    }
    if (((param_3 == 0) && (*(char *)((int)param_1 + 0x1f9) == '\0')) &&
       (*(char *)(iVar7 + 0x329) == '\0')) {
      uVar1 = *(uint *)(iVar7 + 0x80);
      uVar2 = *(uint *)(iVar7 + 0x84);
      uVar3 = *(uint *)(iVar8 + 0x20) + uVar1;
      if ((int)(((*(int *)(iVar8 + 0x24) +
                 ((int)uVar1 >> 0x1f) + (uint)CARRY4(*(uint *)(iVar8 + 0x20),uVar1)) -
                ((int)uVar2 >> 0x1f)) - (uint)(uVar3 < uVar2)) < (int)(uint)(uVar3 == uVar2)) {
        Curl_failf(iVar7,"Empty reply from server");
        return 0x34;
      }
    }
  }
  return 0;
}

