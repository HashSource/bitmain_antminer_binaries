
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 curl_share_setopt(uint *param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_1[1] != 0) {
    return 2;
  }
  switch(param_2) {
  case 1:
    *param_1 = *param_1 | 1 << (param_3 & 0xff);
    switch(param_3) {
    case 2:
      if (param_1[0xb] == 0) {
        uVar2 = Curl_cookie_init(0,0,0,1);
        param_1[0xb] = uVar2;
joined_r0x0004d32e:
        if (uVar2 == 0) {
          return 4;
        }
      }
      break;
    case 3:
    case 5:
      break;
    case 4:
      if (param_1[0xc] == 0) {
        param_1[0xd] = 8;
        uVar2 = (*Curl_ccalloc)(8,0x58);
        param_1[0xe] = 0;
        param_1[0xc] = uVar2;
        goto joined_r0x0004d32e;
      }
      break;
    default:
      goto switchD_0004d270_default;
    }
    goto switchD_0004d2b8_caseD_3;
  case 2:
    *param_1 = *param_1 & ~(1 << (param_3 & 0xff));
    switch(param_3) {
    case 2:
      if (param_1[0xb] != 0) {
        Curl_cookie_cleanup();
        param_1[0xb] = 0;
        return 0;
      }
      break;
    case 3:
    case 5:
      break;
    case 4:
      (*Curl_cfree)(param_1[0xc]);
      param_1[0xc] = 0;
      return 0;
    default:
      goto switchD_0004d270_default;
    }
switchD_0004d2b8_caseD_3:
    uVar1 = 0;
    break;
  case 3:
    uVar1 = 0;
    param_1[2] = param_3;
    break;
  case 4:
    uVar1 = 0;
    param_1[3] = param_3;
    break;
  case 5:
    uVar1 = 0;
    param_1[4] = param_3;
    break;
  default:
switchD_0004d270_default:
    uVar1 = 1;
  }
  return uVar1;
}

