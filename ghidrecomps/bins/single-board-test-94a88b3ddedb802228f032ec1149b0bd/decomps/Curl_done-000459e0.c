
int Curl_done(int **param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  code **ppcVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  bool bVar10;
  
  ppcVar2 = DAT_00045ba0;
  piVar9 = *param_1;
  iVar8 = *piVar9;
  if (*(char *)(iVar8 + 0x86bc) == '\0') {
    Curl_getoff_all_pipelines(iVar8,piVar9,param_3,param_4,param_4);
    (**ppcVar2)(*(undefined4 *)(iVar8 + 0x13c));
    pcVar6 = *ppcVar2;
    *(undefined4 *)(iVar8 + 0x13c) = 0;
    (*pcVar6)(*(undefined4 *)(iVar8 + 0x138));
    *(undefined4 *)(iVar8 + 0x138) = 0;
    if ((param_2 - 0x17U < 0x14) && ((1 << (param_2 - 0x17U & 0xff) & 0x80009U) != 0)) {
      param_3 = 1;
    }
    if (*(code **)(piVar9[0x86] + 0xc) != (code *)0x0) {
      param_2 = (**(code **)(piVar9[0x86] + 0xc))(piVar9,param_2,param_3);
    }
    if (param_2 != 0x2a) {
      iVar3 = Curl_pgrsDone(piVar9);
      if (iVar3 != 0) {
        iVar3 = 1;
      }
      if (param_2 != 0) {
        iVar3 = 0;
      }
      if (iVar3 != 0) {
        param_2 = 0x2a;
      }
    }
    if ((((param_3 != 0) || (*(int *)(piVar9[0x97] + 0xc) + *(int *)(piVar9[0x96] + 0xc) == 0)) ||
        (*(char *)(iVar8 + 0x312) != '\0')) || (*(char *)((int)piVar9 + 0x1ed) != '\0')) {
      iVar3 = piVar9[0x12];
      *(undefined *)(iVar8 + 0x86bc) = 1;
      if (iVar3 != 0) {
        Curl_resolv_unlock(iVar8);
        piVar9[0x12] = 0;
      }
      (**ppcVar2)(*(undefined4 *)(iVar8 + 0x85b8));
      *(undefined4 *)(iVar8 + 0x85b8) = 0;
      if ((((*(char *)(iVar8 + 0x312) == '\0') || (piVar9[0x9d] == 2)) || (piVar9[0xa3] == 2)) &&
         ((*(char *)((int)piVar9 + 0x1ed) == '\0' && (param_3 == 0)))) {
        uVar7 = *(uint *)(*(int *)(iVar8 + 0x40) + 0x94);
        bVar10 = (int)uVar7 < 0;
        if (bVar10) {
          uVar7 = *(uint *)(*(int *)(iVar8 + 0x40) + 0xc);
        }
        *(undefined *)(piVar9 + 0x10) = 0;
        if (bVar10) {
          uVar7 = uVar7 << 2;
        }
        if ((uVar7 != 0) && (uVar7 < *(uint *)(*(int *)(iVar8 + 0x580) + 0x18))) {
          Curl_infof(iVar8,DAT_00045b9c);
          piVar5 = (int *)find_oldest_idle_connection(iVar8);
          if (piVar5 != (int *)0x0) {
            *piVar5 = iVar8;
            Curl_disconnect(piVar5,0);
            if (piVar9 == piVar5) {
              *(undefined4 *)(iVar8 + 0x590) = 0;
              goto LAB_00045abc;
            }
          }
        }
        cVar1 = *(char *)(piVar9 + 0x7c);
        iVar3 = piVar9[0x11];
        *(int **)(iVar8 + 0x590) = piVar9;
        if (cVar1 == '\0') {
          iVar4 = piVar9[0x27];
        }
        else {
          iVar4 = piVar9[0x2b];
        }
        Curl_infof(iVar8,DAT_00045b98,iVar3,iVar4);
      }
      else {
        iVar4 = Curl_disconnect(piVar9,param_3);
        iVar3 = iVar4;
        if (iVar4 != 0) {
          iVar3 = 1;
        }
        if (param_2 != 0) {
          iVar3 = 0;
        }
        if (iVar3 != 0) {
          param_2 = iVar4;
        }
      }
LAB_00045abc:
      *param_1 = (int *)0x0;
      (**ppcVar2)(*(undefined4 *)(iVar8 + 0x14c));
      *(undefined4 *)(iVar8 + 0x14c) = 0;
      (**ppcVar2)(*(undefined4 *)(iVar8 + 0x13c));
      *(undefined4 *)(iVar8 + 0x13c) = 0;
      return param_2;
    }
  }
  return 0;
}

