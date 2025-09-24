
undefined4
serverinfoex_srv_add_cb
          (undefined4 param_1,uint param_2,uint param_3,int *param_4,uint *param_5,
          undefined4 param_6,uint param_7,undefined4 *param_8)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int local_20;
  uint local_1c [2];
  
  local_20 = 0;
  local_1c[0] = 0;
  if (param_7 != 0) {
    param_7 = 1;
  }
  if (((param_7 & param_3 >> 0xc) == 0) &&
     (iVar3 = ssl_get_server_cert_serverinfo(param_1,&local_20,local_1c), iVar3 != 0)) {
    *param_4 = 0;
    *param_5 = 0;
    if ((local_1c[0] == 0 || local_20 == 0) || ((int)local_1c[0] < 0)) {
LAB_001032ae:
      uVar4 = 0xffffffff;
      *param_8 = 0x50;
    }
    else {
      do {
        if (local_1c[0] < 6) goto LAB_001032ae;
        puVar1 = (undefined1 *)(local_20 + 4);
        puVar2 = (undefined1 *)(local_20 + 5);
        uVar5 = local_1c[0] - 8;
        iVar3 = local_20 + 8;
        if (local_1c[0] - 6 < 2) goto LAB_001032ae;
        uVar6 = (uint)CONCAT11(*(undefined1 *)(local_20 + 6),*(undefined1 *)(local_20 + 7));
        local_1c[0] = uVar5 - uVar6;
        local_20 = iVar3 + uVar6;
        if (uVar5 < uVar6) goto LAB_001032ae;
        if (param_2 == CONCAT11(*puVar1,*puVar2)) {
          *param_4 = iVar3;
          *param_5 = uVar6;
          return 1;
        }
      } while (local_1c[0] != 0);
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

