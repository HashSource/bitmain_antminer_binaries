
undefined4 sig_cb(void *param_1,size_t param_2,int *param_3)

{
  undefined2 uVar1;
  short sVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_50;
  int local_4c;
  char acStack_48 [44];
  
  local_50 = 0;
  local_4c = 0;
  if ((param_1 != (void *)0x0) && (iVar8 = *param_3, iVar8 != 0x34 && (int)param_2 < 0x28)) {
    memcpy(acStack_48,param_1,param_2);
    acStack_48[param_2] = '\0';
    pcVar3 = strchr(acStack_48,0x2b);
    if (pcVar3 == (char *)0x0) {
      iVar9 = 0;
      do {
        iVar7 = iVar9 + 0x20;
        if ((*(char **)(&sigalg_lookup_tbl + iVar9) != (char *)0x0) &&
           (iVar4 = strcmp(acStack_48,*(char **)(&sigalg_lookup_tbl + iVar9)), iVar4 == 0)) {
          uVar1 = *(undefined2 *)((int)&DAT_002683f8 + iVar9);
          iVar9 = iVar8 + 1;
          *param_3 = iVar9;
          *(undefined2 *)((int)param_3 + iVar8 * 2 + 4) = uVar1;
          goto LAB_00103ea6;
        }
        iVar9 = iVar7;
      } while (iVar7 != 0x340);
    }
    else {
      *pcVar3 = '\0';
      if (pcVar3[1] != '\0') {
        get_sigorhash(&local_50,&local_4c,acStack_48);
        get_sigorhash(&local_50,&local_4c,pcVar3 + 1);
        if ((local_50 != 0) && (local_4c != 0)) {
          puVar6 = &sigalg_lookup_tbl;
          do {
            if ((local_4c == *(int *)(puVar6 + 8)) && (local_50 == *(int *)(puVar6 + 0x10))) {
              iVar8 = *param_3;
              uVar1 = *(undefined2 *)(puVar6 + 4);
              iVar9 = iVar8 + 1;
              *param_3 = iVar9;
              *(undefined2 *)((int)param_3 + iVar8 * 2 + 4) = uVar1;
LAB_00103ea6:
              iVar9 = iVar9 + -1;
              if (iVar9 == 0) {
                return 1;
              }
              sVar2 = *(short *)((int)param_3 + iVar9 * 2 + 4);
              if ((short)param_3[1] != sVar2) {
                piVar5 = param_3 + 1;
                iVar8 = 0;
                do {
                  iVar8 = iVar8 + 1;
                  if (iVar9 == iVar8) {
                    return 1;
                  }
                  piVar5 = (int *)((int)piVar5 + 2);
                } while (*(short *)piVar5 != sVar2);
              }
              *param_3 = iVar9;
              return 0;
            }
            puVar6 = puVar6 + 0x20;
          } while (puVar6 != legacy_rsa_sigalg);
        }
      }
    }
  }
  return 0;
}

