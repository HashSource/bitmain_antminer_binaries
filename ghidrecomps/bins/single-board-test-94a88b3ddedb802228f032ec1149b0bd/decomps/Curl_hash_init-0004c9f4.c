
undefined4 Curl_hash_init(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  code **ppcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  ppcVar1 = DAT_0004caa0;
  if ((param_2 != 0 && param_3 != 0) && (param_4 != 0 && param_5 != 0)) {
    iVar4 = 0;
    param_1[2] = param_4;
    param_1[1] = param_3;
    param_1[5] = 0;
    param_1[3] = param_5;
    param_1[4] = param_2;
    iVar2 = (**ppcVar1)(param_2 << 2);
    *param_1 = iVar2;
    if (iVar2 == 0) {
      param_1[4] = 0;
      return 1;
    }
    if (0 < param_2) {
      do {
        uVar3 = Curl_llist_alloc(DAT_0004caa4);
        *(undefined4 *)(iVar2 + iVar4 * 4) = uVar3;
        iVar2 = *param_1;
        if (*(int *)(iVar2 + iVar4 * 4) == 0) {
          if (iVar4 != 0) {
            iVar5 = (iVar4 + -1) * 4;
            iVar6 = 0;
            do {
              Curl_llist_destroy(*(undefined4 *)(iVar2 + iVar5),0);
              bVar7 = iVar6 != iVar4 + -1;
              iVar6 = iVar6 + 1;
              *(undefined4 *)(*param_1 + iVar5) = 0;
              iVar5 = iVar5 + -4;
              iVar2 = *param_1;
            } while (bVar7);
          }
          (**DAT_0004caa8)(iVar2);
          *param_1 = 0;
          param_1[4] = 0;
          return 1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != param_2);
    }
    return 0;
  }
  return 1;
}

