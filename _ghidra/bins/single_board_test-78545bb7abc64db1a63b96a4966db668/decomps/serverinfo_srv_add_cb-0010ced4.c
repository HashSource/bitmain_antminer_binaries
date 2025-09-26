
int serverinfo_srv_add_cb
              (undefined4 param_1,uint param_2,int *param_3,uint *param_4,undefined4 *param_5)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int local_20;
  uint local_1c [2];
  
  local_1c[0] = 0;
  local_20 = 0;
  iVar3 = ssl_get_server_cert_serverinfo(param_1,&local_20,local_1c);
  if (iVar3 != 0) {
    *param_3 = 0;
    *param_4 = 0;
    if ((local_1c[0] == 0 || local_20 == 0) || ((int)local_1c[0] < 0)) {
LAB_0010cf0e:
      iVar3 = -1;
      *param_5 = 0x50;
    }
    else {
      do {
        if (local_1c[0] < 6) goto LAB_0010cf0e;
        puVar1 = (undefined1 *)(local_20 + 4);
        puVar2 = (undefined1 *)(local_20 + 5);
        uVar4 = local_1c[0] - 8;
        iVar3 = local_20 + 8;
        if (local_1c[0] - 6 < 2) goto LAB_0010cf0e;
        uVar5 = (uint)CONCAT11(*(undefined1 *)(local_20 + 6),*(undefined1 *)(local_20 + 7));
        local_1c[0] = uVar4 - uVar5;
        local_20 = iVar3 + uVar5;
        if (uVar4 < uVar5) goto LAB_0010cf0e;
        if (param_2 == CONCAT11(*puVar1,*puVar2)) {
          *param_3 = iVar3;
          *param_4 = uVar5;
          return 1;
        }
      } while (local_1c[0] != 0);
      iVar3 = 0;
    }
  }
  return iVar3;
}

