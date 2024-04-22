
void singlesocket(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  size_t __n;
  int *local_54;
  int local_44;
  int local_40;
  int local_3c;
  int local_38 [5];
  
  iVar9 = param_1 + 0x48;
  local_54 = &local_40;
  local_3c = -1;
  uVar6 = 0;
  local_38[0] = 0xffffffff;
  local_38[1] = 0xffffffff;
  local_38[2] = 0xffffffff;
  local_38[3] = 0xffffffff;
  uVar2 = multi_getsock_constprop_6(param_2,&local_3c);
  do {
    uVar7 = 1 << (uVar6 & 0xff);
    uVar11 = 1 << (uVar6 + 0x10 & 0xff);
    if (((uVar11 | uVar7) & uVar2) == 0) {
      __n = uVar6 << 2;
      goto LAB_00039dfe;
    }
    local_54 = local_54 + 1;
    iVar10 = *local_54;
    piVar3 = (int *)sh_getentry(iVar9,iVar10);
    uVar7 = (uint)((uVar7 & uVar2) != 0);
    if ((uVar11 & uVar2) != 0) {
      uVar7 = uVar7 | 2;
    }
    if (piVar3 == (int *)0x0) {
      local_44 = iVar10;
      piVar3 = (int *)sh_getentry(iVar9);
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)(*Curl_ccalloc)(1,0x10);
        if (piVar3 == (int *)0x0) {
          return;
        }
        *piVar3 = param_2;
        piVar3[2] = local_44;
        iVar8 = Curl_hash_add(iVar9,&local_44,4,piVar3);
        if (iVar8 == 0) {
          (**DAT_00039f64)(piVar3);
          return;
        }
      }
LAB_00039dd6:
      if (*(code **)(param_1 + 0x1c) != (code *)0x0) {
        (**(code **)(param_1 + 0x1c))
                  (param_2,iVar10,uVar7,*(undefined4 *)(param_1 + 0x20),piVar3[3]);
      }
      piVar3[1] = uVar7;
    }
    else if (piVar3[1] != uVar7) goto LAB_00039dd6;
    uVar6 = uVar6 + 1;
  } while (uVar6 != 5);
  __n = 0x14;
LAB_00039dfe:
  if (0 < *(int *)(param_2 + 0x34)) {
    iVar10 = 0;
    iVar9 = param_2;
    do {
      iVar8 = *(int *)(iVar9 + 0x20);
      if (uVar6 != 0) {
        if (local_3c != iVar8) {
          piVar3 = &local_3c;
          uVar2 = 0;
          do {
            uVar2 = uVar2 + 1;
            if (uVar2 == uVar6) goto LAB_00039e2c;
            piVar3 = piVar3 + 1;
          } while (*piVar3 != iVar8);
        }
        iVar8 = -1;
      }
LAB_00039e2c:
      piVar3 = (int *)sh_getentry(param_1 + 0x48,iVar8);
      if (piVar3 != (int *)0x0) {
        iVar5 = *(int *)(param_2 + 8);
        if (iVar5 == 0) {
LAB_00039e92:
          if (*(code **)(param_1 + 0x1c) != (code *)0x0) {
            (**(code **)(param_1 + 0x1c))(param_2,iVar8,4,*(undefined4 *)(param_1 + 0x20),piVar3[3])
            ;
          }
          local_40 = iVar8;
          Curl_hash_delete(param_1 + 0x48,&local_40,4);
        }
        else {
          if ((*(int *)(iVar5 + 0x25c) == 0) || (*(uint *)(*(int *)(iVar5 + 0x25c) + 0xc) < 2)) {
            bVar1 = true;
          }
          else if (*piVar3 == param_2) {
            iVar4 = Curl_recvpipe_head(param_2,iVar5);
            if (iVar4 == 0) {
              *piVar3 = ***(int ***)(iVar5 + 0x25c);
              bVar1 = false;
            }
            else {
              bVar1 = false;
              *piVar3 = *(int *)(**(int ***)(iVar5 + 0x25c))[2];
            }
          }
          else {
            bVar1 = false;
          }
          if ((*(int *)(iVar5 + 600) == 0) || (*(uint *)(*(int *)(iVar5 + 600) + 0xc) < 2)) {
            if (bVar1) goto LAB_00039e92;
          }
          else if (*piVar3 == param_2) {
            iVar8 = Curl_sendpipe_head(param_2,iVar5);
            if (iVar8 == 0) {
              *piVar3 = ***(int ***)(iVar5 + 600);
            }
            else {
              *piVar3 = *(int *)(**(int ***)(iVar5 + 600))[2];
            }
          }
        }
      }
      iVar10 = iVar10 + 1;
      iVar9 = iVar9 + 4;
    } while (iVar10 < *(int *)(param_2 + 0x34));
  }
  memcpy((void *)(param_2 + 0x20),&local_3c,__n);
  *(uint *)(param_2 + 0x34) = uVar6;
  return;
}

