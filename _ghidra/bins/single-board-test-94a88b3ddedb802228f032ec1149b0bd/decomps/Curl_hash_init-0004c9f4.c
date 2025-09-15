
undefined4 Curl_hash_init(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  if ((param_2 != 0 && param_3 != 0) && (param_4 != 0 && param_5 != 0)) {
    iVar3 = 0;
    param_1[2] = param_4;
    param_1[1] = param_3;
    param_1[5] = 0;
    param_1[3] = param_5;
    param_1[4] = param_2;
    iVar1 = (*Curl_cmalloc)(param_2 << 2);
    *param_1 = iVar1;
    if (iVar1 == 0) {
      param_1[4] = 0;
      return 1;
    }
    if (0 < param_2) {
      do {
        uVar2 = Curl_llist_alloc(0x4c9c9);
        *(undefined4 *)(iVar1 + iVar3 * 4) = uVar2;
        iVar1 = *param_1;
        if (*(int *)(iVar1 + iVar3 * 4) == 0) {
          if (iVar3 != 0) {
            iVar4 = (iVar3 + -1) * 4;
            iVar5 = 0;
            do {
              Curl_llist_destroy(*(undefined4 *)(iVar1 + iVar4),0);
              bVar6 = iVar5 != iVar3 + -1;
              iVar5 = iVar5 + 1;
              *(undefined4 *)(*param_1 + iVar4) = 0;
              iVar4 = iVar4 + -4;
              iVar1 = *param_1;
            } while (bVar6);
          }
          (*Curl_cfree)(iVar1);
          *param_1 = 0;
          param_1[4] = 0;
          return 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != param_2);
    }
    return 0;
  }
  return 1;
}

