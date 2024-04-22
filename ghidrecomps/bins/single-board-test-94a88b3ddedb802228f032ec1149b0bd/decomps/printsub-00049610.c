
void printsub(int param_1,uint param_2,byte *param_3,uint param_4)

{
  undefined4 uVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar5;
  uint uVar6;
  byte *pbVar4;
  
  if (*(char *)(param_1 + 0x310) == '\0') {
    return;
  }
  uVar5 = param_2;
  if (param_2 != 0) {
    Curl_infof(param_1,DAT_00049838);
    if (param_4 < 3) {
      uVar5 = 0;
    }
    else {
      uVar5 = (uint)param_3[param_4 - 2];
      uVar6 = (uint)param_3[param_4 - 1];
      if (uVar5 == 0xff && uVar6 == 0xf0) {
        uVar5 = 0xff;
      }
      else {
        Curl_infof(param_1,DAT_0004987c);
        if (uVar5 < 0x28) {
          Curl_infof(param_1,DAT_00049880);
        }
        else {
          uVar1 = DAT_00049880;
          if (0x13 < uVar5 - 0xec) {
            uVar1 = DAT_00049884;
          }
          Curl_infof(param_1,uVar1);
        }
        if (uVar6 < 0x28) {
          Curl_infof(param_1,DAT_00049840,*(undefined4 *)(DAT_0004983c + uVar6 * 4));
        }
        else {
          uVar1 = DAT_00049840;
          if (0x13 < uVar6 - 0xec) {
            uVar1 = DAT_00049888;
          }
          Curl_infof(param_1,uVar1);
        }
        Curl_infof(param_1,DAT_0004988c);
      }
    }
    param_4 = param_4 - 2;
  }
  if (param_4 == 0) {
    Curl_infof(param_1,DAT_00049850);
    return;
  }
  uVar6 = (uint)*param_3;
  if (uVar6 < 0x28) {
    bVar2 = *param_3 - 0x18;
    if ((bVar2 < 0x10) && ((1 << (uint)bVar2 & 0x8881U) != 0)) {
      Curl_infof(param_1,DAT_00049840,*(undefined4 *)(DAT_0004983c + uVar6 * 4));
      goto LAB_00049694;
    }
    Curl_infof(param_1,DAT_00049844,*(undefined4 *)(DAT_0004983c + uVar6 * 4));
    bVar2 = *param_3;
  }
  else {
    Curl_infof(param_1,DAT_0004985c,param_3[uVar5]);
LAB_00049694:
    bVar2 = *param_3;
  }
  if (bVar2 == 0x1f) {
    if (4 < param_4) {
      Curl_infof(param_1,DAT_00049848,CONCAT11(param_3[1],param_3[2]),
                 CONCAT11(param_3[3],param_3[4]));
    }
    goto LAB_000496de;
  }
  switch(param_3[1]) {
  case 0:
    Curl_infof(param_1,DAT_00049878);
    bVar2 = *param_3;
    break;
  case 1:
    Curl_infof(param_1,DAT_00049874);
    bVar2 = *param_3;
    break;
  case 2:
    Curl_infof(param_1,DAT_00049870);
    bVar2 = *param_3;
    break;
  case 3:
    Curl_infof(param_1,DAT_00049854);
    bVar2 = *param_3;
  }
  if (bVar2 != 0x23) {
    if (bVar2 == 0x27) {
      if ((param_3[1] == 0) && (Curl_infof(param_1,DAT_00049860), 3 < param_4)) {
        pbVar4 = param_3 + 3;
        do {
          pbVar3 = pbVar4 + 1;
          uVar1 = DAT_00049868;
          if ((*pbVar4 == 0) || (uVar1 = DAT_00049890, *pbVar4 == 1)) {
            Curl_infof(param_1,uVar1);
          }
          else {
            Curl_infof(param_1,DAT_00049864);
          }
          pbVar4 = pbVar3;
        } while (pbVar3 != param_3 + param_4);
      }
      goto LAB_000496de;
    }
    if (bVar2 != 0x18) {
      if (2 < param_4) {
        pbVar4 = param_3 + 2;
        do {
          pbVar3 = pbVar4 + 1;
          Curl_infof(param_1,DAT_00049858,*pbVar4);
          pbVar4 = pbVar3;
        } while (pbVar3 != param_3 + param_4);
      }
      goto LAB_000496de;
    }
  }
  param_3[param_4] = 0;
  Curl_infof(param_1,DAT_0004986c,param_3 + 2);
LAB_000496de:
  if (param_2 != 0) {
    Curl_infof(param_1,DAT_0004984c);
    return;
  }
  return;
}

