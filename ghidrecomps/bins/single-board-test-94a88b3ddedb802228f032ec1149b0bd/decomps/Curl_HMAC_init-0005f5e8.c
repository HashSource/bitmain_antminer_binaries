
int * Curl_HMAC_init(code **param_1,code *param_2,code *param_3)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  code *pcVar4;
  byte local_21 [5];
  
  piVar1 = (int *)(**DAT_0005f6b4)(param_1[5] + (int)(param_1[3] + 6) * 2);
  if (piVar1 != (int *)0x0) {
    pcVar4 = param_1[4];
    pcVar3 = param_1[3];
    piVar2 = piVar1 + 3;
    *piVar1 = (int)param_1;
    piVar1[1] = (int)piVar2;
    piVar1[2] = (int)(pcVar3 + (int)piVar2);
    if (pcVar4 < param_3) {
      (**param_1)();
      (*param_1[1])(piVar1[1],param_2,param_3);
      param_2 = param_1[3] + piVar1[2];
      (*param_1[2])(param_2,piVar1[1]);
      param_3 = param_1[5];
      piVar2 = (int *)piVar1[1];
    }
    (**param_1)(piVar2);
    (**param_1)(piVar1[2]);
    if (param_3 != (code *)0x0) {
      pcVar3 = param_2;
      do {
        local_21[0] = (byte)*pcVar3 ^ 0x36;
        (*param_1[1])(piVar1[1],local_21,1);
        pcVar4 = pcVar3 + 1;
        local_21[0] = (byte)*pcVar3 ^ 0x5c;
        (*param_1[1])(piVar1[2],local_21,1);
        pcVar3 = pcVar4;
      } while (pcVar4 != param_2 + (int)param_3);
    }
    if (param_3 < param_1[4]) {
      do {
        param_3 = param_3 + 1;
        (*param_1[1])(piVar1[1],DAT_0005f6b8);
        (*param_1[1])(piVar1[2],DAT_0005f6bc,1);
      } while (param_3 < param_1[4]);
    }
  }
  return piVar1;
}

