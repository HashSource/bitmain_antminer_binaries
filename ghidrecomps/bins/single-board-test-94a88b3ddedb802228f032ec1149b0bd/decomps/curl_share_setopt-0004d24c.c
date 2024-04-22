
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 curl_share_setopt(uint *param_1,undefined4 param_2,uint param_3)

{
  code **ppcVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1[1] != 0) {
    return 2;
  }
  switch(param_2) {
  case 1:
    *param_1 = *param_1 | 1 << (param_3 & 0xff);
    ppcVar1 = DAT_0004d338;
    switch(param_3) {
    case 2:
      if (param_1[0xb] != 0) {
        return 0;
      }
      uVar3 = Curl_cookie_init(0,0,0,1);
      param_1[0xb] = uVar3;
      break;
    case 3:
    case 5:
      goto switchD_0004d2b8_caseD_3;
    case 4:
      if (param_1[0xc] != 0) {
        return 0;
      }
      param_1[0xd] = 8;
      uVar3 = (**ppcVar1)(8,0x58);
      param_1[0xe] = 0;
      param_1[0xc] = uVar3;
      break;
    default:
      goto switchD_0004d270_caseD_5;
    }
    if (uVar3 == 0) {
      return 4;
    }
switchD_0004d2b8_caseD_3:
    return 0;
  case 2:
    *param_1 = *param_1 & ~(1 << (param_3 & 0xff));
    switch(param_3) {
    case 2:
      if (param_1[0xb] == 0) {
        return 0;
      }
      Curl_cookie_cleanup();
      param_1[0xb] = 0;
      return 0;
    case 3:
    case 5:
      return 0;
    case 4:
      (**DAT_0004d334)(param_1[0xc]);
      param_1[0xc] = 0;
      return 0;
    }
  default:
switchD_0004d270_caseD_5:
    uVar2 = 1;
    break;
  case 3:
    uVar2 = 0;
    param_1[2] = param_3;
    break;
  case 4:
    uVar2 = 0;
    param_1[3] = param_3;
    break;
  case 5:
    uVar2 = 0;
    param_1[4] = param_3;
  }
  return uVar2;
}

