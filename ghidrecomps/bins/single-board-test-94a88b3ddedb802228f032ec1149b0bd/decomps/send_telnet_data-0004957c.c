
uint send_telnet_data(int param_1,char *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char local_38 [4];
  int local_34;
  undefined4 local_30;
  undefined2 local_2c;
  
  pcVar5 = param_2;
  do {
    if (pcVar5 == param_2 + param_3) {
      return 0;
    }
    local_38[0] = *pcVar5;
    iVar3 = 0;
    if (local_38[0] == -1) {
      iVar4 = 2;
      local_38[1] = 0xff;
    }
    else {
      iVar4 = 1;
    }
    do {
      local_30 = *(undefined4 *)(param_1 + 0x154);
      local_2c = 4;
      iVar1 = Curl_poll(&local_30,1,0xffffffff);
      if (iVar1 + 1U < 2) {
        return 0x37;
      }
      local_34 = 0;
      uVar2 = Curl_write(param_1,*(undefined4 *)(param_1 + 0x154),local_38 + iVar3,iVar4 - iVar3,
                         &local_34);
      iVar3 = iVar3 + local_34;
      iVar1 = 1 - uVar2;
      if (1 < uVar2) {
        iVar1 = 0;
      }
      if (iVar4 <= iVar3) {
        iVar1 = 0;
      }
    } while (iVar1 != 0);
    pcVar5 = pcVar5 + 1;
  } while (uVar2 == 0);
  return uVar2;
}

