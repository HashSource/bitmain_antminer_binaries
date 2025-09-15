
int Curl_done(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  bool bVar8;
  
  piVar7 = (int *)*param_1;
  iVar6 = *piVar7;
  if (*(char *)(iVar6 + 0x86bc) == '\0') {
    Curl_getoff_all_pipelines(iVar6,piVar7,param_3,param_4,param_4);
    (*Curl_cfree)(*(undefined4 *)(iVar6 + 0x13c));
    pcVar1 = Curl_cfree;
    *(undefined4 *)(iVar6 + 0x13c) = 0;
    (*pcVar1)(*(undefined4 *)(iVar6 + 0x138));
    *(undefined4 *)(iVar6 + 0x138) = 0;
    if ((param_2 - 0x17U < 0x14) && ((1 << (param_2 - 0x17U & 0xff) & 0x80009U) != 0)) {
      param_3 = 1;
    }
    if (*(code **)(piVar7[0x86] + 0xc) != (code *)0x0) {
      param_2 = (**(code **)(piVar7[0x86] + 0xc))(piVar7,param_2,param_3);
    }
    if (param_2 != 0x2a) {
      iVar2 = Curl_pgrsDone(piVar7);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
      if (param_2 != 0) {
        iVar2 = 0;
      }
      if (iVar2 != 0) {
        param_2 = 0x2a;
      }
    }
    if ((((param_3 != 0) || (*(int *)(piVar7[0x97] + 0xc) + *(int *)(piVar7[0x96] + 0xc) == 0)) ||
        (*(char *)(iVar6 + 0x312) != '\0')) || (*(char *)((int)piVar7 + 0x1ed) != '\0')) {
      iVar2 = piVar7[0x12];
      *(undefined1 *)(iVar6 + 0x86bc) = 1;
      if (iVar2 != 0) {
        Curl_resolv_unlock(iVar6);
        piVar7[0x12] = 0;
      }
      (*Curl_cfree)(*(undefined4 *)(iVar6 + 0x85b8));
      *(undefined4 *)(iVar6 + 0x85b8) = 0;
      if ((((*(char *)(iVar6 + 0x312) == '\0') || (piVar7[0x9d] == 2)) || (piVar7[0xa3] == 2)) &&
         ((*(char *)((int)piVar7 + 0x1ed) == '\0' && (param_3 == 0)))) {
        uVar5 = *(uint *)(*(int *)(iVar6 + 0x40) + 0x94);
        bVar8 = (int)uVar5 < 0;
        if (bVar8) {
          uVar5 = *(uint *)(*(int *)(iVar6 + 0x40) + 0xc);
        }
        *(undefined1 *)(piVar7 + 0x10) = 0;
        if (bVar8) {
          uVar5 = uVar5 << 2;
        }
        if ((uVar5 != 0) && (uVar5 < *(uint *)(*(int *)(iVar6 + 0x580) + 0x18))) {
          Curl_infof(iVar6,"Connection cache is full, closing the oldest one.\n");
          piVar4 = (int *)find_oldest_idle_connection(iVar6);
          if (piVar4 != (int *)0x0) {
            *piVar4 = iVar6;
            Curl_disconnect(piVar4,0);
            if (piVar7 == piVar4) {
              *(undefined4 *)(iVar6 + 0x590) = 0;
              goto LAB_00045abc;
            }
          }
        }
        iVar2 = piVar7[0x7c];
        iVar3 = piVar7[0x11];
        *(int **)(iVar6 + 0x590) = piVar7;
        if ((char)iVar2 == '\0') {
          iVar2 = piVar7[0x27];
        }
        else {
          iVar2 = piVar7[0x2b];
        }
        Curl_infof(iVar6,"Connection #%ld to host %s left intact\n",iVar3,iVar2);
      }
      else {
        iVar3 = Curl_disconnect(piVar7,param_3);
        iVar2 = iVar3;
        if (iVar3 != 0) {
          iVar2 = 1;
        }
        if (param_2 != 0) {
          iVar2 = 0;
        }
        if (iVar2 != 0) {
          param_2 = iVar3;
        }
      }
LAB_00045abc:
      *param_1 = 0;
      (*Curl_cfree)(*(undefined4 *)(iVar6 + 0x14c));
      *(undefined4 *)(iVar6 + 0x14c) = 0;
      (*Curl_cfree)(*(undefined4 *)(iVar6 + 0x13c));
      *(undefined4 *)(iVar6 + 0x13c) = 0;
      return param_2;
    }
  }
  return 0;
}

