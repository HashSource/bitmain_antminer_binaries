
int Curl_connecthost(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined auStack_20 [12];
  
  iVar4 = *param_1;
  curlx_tvnow(auStack_20);
  iVar1 = Curl_timeleft(iVar4,auStack_20,1);
  if (iVar1 < 0) {
    Curl_failf(iVar4,DAT_00039768);
    iVar1 = 0x1c;
  }
  else {
    iVar2 = Curl_num_addresses(*param_2);
    iVar3 = *param_2;
    param_1[0x84] = iVar2;
    param_1[0x15] = 0;
    param_1[0x57] = -1;
    param_1[0x58] = -1;
    param_1[0x14] = iVar3;
    Curl_expire(*param_1,200);
    iVar2 = param_1[0x14];
    if (*(int *)(iVar2 + 0x1c) != 0) {
      iVar1 = iVar1 >> 1;
    }
    param_1[0x85] = iVar1;
    do {
      iVar1 = singleipconnect(param_1,iVar2,param_1 + 0x57);
      if (iVar1 == 0) {
        if (param_1[0x57] == -1) {
          return 7;
        }
        goto LAB_0003973e;
      }
      iVar2 = *(int *)(param_1[0x14] + 0x1c);
      param_1[0x14] = iVar2;
    } while (iVar2 != 0);
    if (param_1[0x57] != -1) {
LAB_0003973e:
      iVar1 = 0;
      *(int *)(iVar4 + 0x8718) = *(int *)(iVar4 + 0x8718) + 1;
    }
  }
  return iVar1;
}

