
void printsub(int param_1,uint param_2,byte *param_3,uint param_4)

{
  char *pcVar1;
  undefined *puVar2;
  uint uVar3;
  byte bVar4;
  byte *pbVar5;
  uint uVar7;
  uint uVar8;
  byte *pbVar6;
  
  if (*(char *)(param_1 + 0x310) == '\0') {
    return;
  }
  uVar7 = param_2;
  if (param_2 != 0) {
    puVar2 = &DAT_00137464;
    if (param_2 == 0x3c) {
      puVar2 = &DAT_0013745c;
    }
    Curl_infof(param_1,"%s IAC SB ",puVar2);
    if (param_4 < 3) {
      uVar7 = 0;
    }
    else {
      uVar7 = (uint)param_3[param_4 - 2];
      uVar8 = (uint)param_3[param_4 - 1];
      if (uVar7 == 0xff && uVar8 == 0xf0) {
        uVar7 = 0xff;
      }
      else {
        Curl_infof(param_1,"(terminated by ");
        if (uVar7 < 0x28) {
          Curl_infof(param_1,&DAT_001360e4,(&telnetoptions)[uVar7]);
        }
        else {
          if (uVar7 - 0xec < 0x14) {
            puVar2 = &DAT_001360e4;
            uVar3 = *(uint *)(telnetcmds + (uVar7 - 0xec) * 4);
          }
          else {
            puVar2 = &UNK_00137488;
            uVar3 = uVar7;
          }
          Curl_infof(param_1,puVar2,uVar3);
        }
        if (uVar8 < 0x28) {
          Curl_infof(param_1,"%s",(&telnetoptions)[uVar8]);
        }
        else {
          if (uVar8 - 0xec < 0x14) {
            pcVar1 = "%s";
            uVar8 = *(uint *)(telnetcmds + (uVar8 - 0xec) * 4);
          }
          else {
            pcVar1 = "%d";
          }
          Curl_infof(param_1,pcVar1,uVar8);
        }
        Curl_infof(param_1,", not IAC SE!) ");
      }
    }
    param_4 = param_4 - 2;
  }
  if (param_4 == 0) {
    Curl_infof(param_1,"(Empty suboption?)");
    return;
  }
  uVar8 = (uint)*param_3;
  if (uVar8 < 0x28) {
    bVar4 = *param_3 - 0x18;
    if ((bVar4 < 0x10) && ((1 << (uint)bVar4 & 0x8881U) != 0)) {
      Curl_infof(param_1,"%s",(&telnetoptions)[uVar8]);
      goto LAB_00049694;
    }
    Curl_infof(param_1,"%s (unsupported)",(&telnetoptions)[uVar8]);
    bVar4 = *param_3;
  }
  else {
    Curl_infof(param_1,"%d (unknown)",param_3[uVar7]);
LAB_00049694:
    bVar4 = *param_3;
  }
  if (bVar4 == 0x1f) {
    if (4 < param_4) {
      Curl_infof(param_1,"Width: %hu ; Height: %hu",CONCAT11(param_3[1],param_3[2]),
                 CONCAT11(param_3[3],param_3[4]));
    }
    goto LAB_000496de;
  }
  switch(param_3[1]) {
  case 0:
    Curl_infof(param_1,&DAT_001374f0);
    bVar4 = *param_3;
    break;
  case 1:
    Curl_infof(param_1," SEND");
    bVar4 = *param_3;
    break;
  case 2:
    Curl_infof(param_1," INFO/REPLY");
    bVar4 = *param_3;
    break;
  case 3:
    Curl_infof(param_1," NAME");
    bVar4 = *param_3;
  }
  if (bVar4 != 0x23) {
    if (bVar4 == 0x27) {
      if ((param_3[1] == 0) && (Curl_infof(param_1,&DAT_001729cc), 3 < param_4)) {
        pbVar6 = param_3 + 3;
        do {
          pbVar5 = pbVar6 + 1;
          puVar2 = &DAT_0013677c;
          if (*pbVar6 == 0) {
LAB_0004976c:
            Curl_infof(param_1,puVar2);
          }
          else {
            if (*pbVar6 == 1) {
              puVar2 = &DAT_00137518;
              goto LAB_0004976c;
            }
            Curl_infof(param_1,"%c");
          }
          pbVar6 = pbVar5;
        } while (pbVar5 != param_3 + param_4);
      }
      goto LAB_000496de;
    }
    if (bVar4 != 0x18) {
      if (2 < param_4) {
        pbVar6 = param_3 + 2;
        do {
          pbVar5 = pbVar6 + 1;
          Curl_infof(param_1," %.2x",*pbVar6);
          pbVar6 = pbVar5;
        } while (pbVar5 != param_3 + param_4);
      }
      goto LAB_000496de;
    }
  }
  param_3[param_4] = 0;
  Curl_infof(param_1," \"%s\"",param_3 + 2);
LAB_000496de:
  if (param_2 != 0) {
    Curl_infof(param_1,"\n");
    return;
  }
  return;
}

