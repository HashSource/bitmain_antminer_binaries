
int * Curl_HMAC_init(undefined4 *param_1,byte *param_2,uint param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte local_21 [5];
  
  piVar1 = (int *)(*Curl_cmalloc)(param_1[5] + (param_1[3] + 6) * 2);
  if (piVar1 != (int *)0x0) {
    uVar4 = param_1[4];
    iVar3 = param_1[3];
    piVar2 = piVar1 + 3;
    *piVar1 = (int)param_1;
    piVar1[1] = (int)piVar2;
    piVar1[2] = iVar3 + (int)piVar2;
    if (uVar4 < param_3) {
      (*(code *)*param_1)();
      (*(code *)param_1[1])(piVar1[1],param_2,param_3);
      param_2 = (byte *)(piVar1[2] + param_1[3]);
      (*(code *)param_1[2])(param_2,piVar1[1]);
      param_3 = param_1[5];
      piVar2 = (int *)piVar1[1];
    }
    (*(code *)*param_1)(piVar2);
    (*(code *)*param_1)(piVar1[2]);
    if (param_3 != 0) {
      pbVar5 = param_2;
      do {
        local_21[0] = *pbVar5 ^ 0x36;
        (*(code *)param_1[1])(piVar1[1],local_21,1);
        pbVar6 = pbVar5 + 1;
        local_21[0] = *pbVar5 ^ 0x5c;
        (*(code *)param_1[1])(piVar1[2],local_21,1);
        pbVar5 = pbVar6;
      } while (pbVar6 != param_2 + param_3);
    }
    if (param_3 < (uint)param_1[4]) {
      do {
        param_3 = param_3 + 1;
        (*(code *)param_1[1])(piVar1[1],&hmac_ipad);
        (*(code *)param_1[1])(piVar1[2],&hmac_opad,1);
      } while (param_3 < (uint)param_1[4]);
    }
  }
  return piVar1;
}

