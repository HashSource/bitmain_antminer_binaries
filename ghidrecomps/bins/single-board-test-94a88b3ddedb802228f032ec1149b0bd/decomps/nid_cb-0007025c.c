
void * nid_cb(void *param_1,size_t param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char acStack_24 [20];
  
  if (param_1 != (void *)0x0) {
    if ((*param_3 != 0x1c) && ((int)param_2 < 0x14)) {
      memcpy(acStack_24,param_1,param_2);
      acStack_24[param_2] = '\0';
      iVar2 = EC_curve_nist2nid(acStack_24);
      if ((iVar2 != 0) ||
         ((iVar2 = OBJ_sn2nid(acStack_24), iVar2 != 0 ||
          (iVar2 = OBJ_ln2nid(acStack_24), iVar2 != 0)))) {
        iVar4 = *param_3;
        if (iVar4 == 0) {
LAB_000702b2:
          *param_3 = iVar4 + 1;
          param_3[iVar4 + 1] = iVar2;
          return (void *)0x1;
        }
        if (iVar2 != param_3[1]) {
          iVar5 = 0;
          piVar3 = param_3;
          do {
            iVar5 = iVar5 + 1;
            if (iVar5 == iVar4) goto LAB_000702b2;
            piVar1 = piVar3 + 2;
            piVar3 = piVar3 + 1;
          } while (iVar2 != *piVar1);
        }
      }
    }
    param_1 = (void *)0x0;
  }
  return param_1;
}

