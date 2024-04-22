
undefined Curl_getinfo(int param_1,uint param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  
  if (param_1 == 0) {
LAB_0004a812:
    return 0x30;
  }
  uVar3 = param_2 & 0xf00000;
  if (uVar3 != 0x300000) {
    if (uVar3 < 0x300001) {
      if (uVar3 == 0x100000) {
        if (param_3 == (undefined8 *)0x0) {
          return 0x30;
        }
        switch(param_2) {
        case 0x100001:
          goto switchD_0004aa34_caseD_100001;
        default:
          return 0x30;
        case 0x100012:
          *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x871c);
          return 0;
        case 0x100015:
          *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x2d0);
          return 0;
        case 0x10001e:
          *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x8670);
          return 0;
        case 0x10001f:
          *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x8720);
          return 0;
        case 0x100020:
          *(int *)param_3 = param_1 + 0x8724;
          return 0;
        case 0x100024:
          *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x3cc);
          return 0;
        case 0x100029:
          *(int *)param_3 = param_1 + 0x8758;
          return 0;
        }
      }
      if (uVar3 != 0x200000) {
        return 0x30;
      }
      if (param_3 == (undefined8 *)0x0) {
        return 0x30;
      }
      switch(param_2) {
      case 0x200002:
        *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x86f4);
        return 0;
      default:
        return 0x30;
      case 0x20000b:
        *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x8708);
        return 0;
      case 0x20000c:
        *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x870c);
        return 0;
      case 0x20000d:
        *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x284);
        return 0;
      case 0x20000e:
        *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x8700);
        return 0;
      case 0x200014:
        *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x17c);
        return 0;
      case 0x200016:
        *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x86f8);
        return 0;
      case 0x200017:
        *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x8714);
        return 0;
      case 0x200018:
        *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x8710);
        return 0;
      case 0x200019:
        *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x85cc);
        return 0;
      case 0x20001a:
        *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x8718);
        return 0;
      case 0x20001d:
        uVar1 = Curl_getconnectinfo(param_1,0);
        *(undefined4 *)param_3 = uVar1;
        return 0;
      case 0x200023:
        *(uint *)param_3 = (uint)*(byte *)(param_1 + 0x8704);
        return 0;
      case 0x200025:
        *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x86a0);
        return 0;
      case 0x200026:
        *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x86a4);
        return 0;
      case 0x200027:
        *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x86a8);
        return 0;
      case 0x200028:
        *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x8754);
        return 0;
      case 0x20002a:
        *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x8788);
        return 0;
      }
    }
    if (uVar3 == 0x400000) {
      if (param_3 == (undefined8 *)0x0) {
        return 0x30;
      }
      switch(param_2) {
      case 0x40001b:
        uVar1 = Curl_ssl_engines_list(param_1);
        *(undefined4 *)param_3 = uVar1;
        return 0;
      case 0x40001c:
        uVar1 = Curl_cookie_list(param_1);
        *(undefined4 *)param_3 = uVar1;
        return 0;
      default:
        return 0x30;
      case 0x400022:
        *(int *)param_3 = param_1 + 0x878c;
        return 0;
      case 0x40002b:
      case 0x40002d:
        goto switchD_0004a9c6_caseD_40002b;
      }
    }
    if (uVar3 != 0x500000) {
      return 0x30;
    }
    if (param_3 == (undefined8 *)0x0) {
      return 0x30;
    }
    if (param_2 != 0x50002c) {
      return 0x30;
    }
    uVar1 = Curl_getconnectinfo(param_1,0);
    *(undefined4 *)param_3 = uVar1;
    return 0;
  }
  if (param_3 == (undefined8 *)0x0) {
    return 0x30;
  }
  switch(param_2) {
  case 0x300003:
    *param_3 = *(undefined8 *)(param_1 + 0x4b0);
    break;
  case 0x300004:
    *param_3 = *(undefined8 *)(param_1 + 0x4c8);
    break;
  case 0x300005:
    *param_3 = *(undefined8 *)(param_1 + 0x4d0);
    break;
  case 0x300006:
    *param_3 = *(undefined8 *)(param_1 + 0x4e0);
    break;
  case 0x300007:
    uVar6 = __aeabi_l2d(*(undefined4 *)(param_1 + 0x490),*(undefined4 *)(param_1 + 0x494));
    *param_3 = uVar6;
    break;
  case 0x300008:
    uVar6 = __aeabi_l2d(*(undefined4 *)(param_1 + 0x488),*(undefined4 *)(param_1 + 0x48c));
    *param_3 = uVar6;
    break;
  case 0x300009:
    uVar6 = __aeabi_l2d(*(undefined4 *)(param_1 + 0x4b8),*(undefined4 *)(param_1 + 0x4bc));
    *param_3 = uVar6;
    break;
  case 0x30000a:
    uVar6 = __aeabi_l2d(*(undefined4 *)(param_1 + 0x4c0),*(undefined4 *)(param_1 + 0x4c4));
    *param_3 = uVar6;
    break;
  default:
    goto LAB_0004a812;
  case 0x30000f:
    if (*(int *)(param_1 + 0x4a8) << 0x19 < 0) {
      uVar6 = __aeabi_l2d(*(undefined4 *)(param_1 + 0x478),*(undefined4 *)(param_1 + 0x47c));
    }
    else {
LAB_0004ad90:
      uVar6 = 0xbff0000000000000;
    }
    goto LAB_0004ac1c;
  case 0x300010:
    if (-1 < *(int *)(param_1 + 0x4a8) << 0x1a) goto LAB_0004ad90;
    uVar6 = __aeabi_l2d(*(undefined4 *)(param_1 + 0x480),*(undefined4 *)(param_1 + 0x484));
LAB_0004ac1c:
    *param_3 = uVar6;
    break;
  case 0x300011:
    *param_3 = *(undefined8 *)(param_1 + 0x4e8);
    break;
  case 0x300013:
    *param_3 = *(undefined8 *)(param_1 + 0x4f0);
    break;
  case 0x300021:
    *param_3 = *(undefined8 *)(param_1 + 0x4d8);
  }
  return 0;
switchD_0004aa34_caseD_100001:
  iVar2 = *(int *)(param_1 + 0x450);
  if (*(int *)(param_1 + 0x450) == 0) {
    iVar2 = DAT_0004ad9c;
  }
  *(int *)param_3 = iVar2;
  return 0;
switchD_0004a9c6_caseD_40002b:
  iVar5 = *(int *)(param_1 + 8);
  *(int *)param_3 = param_1 + 0x8794;
  iVar2 = Curl_ssl_backend();
  iVar4 = 0;
  *(int *)(param_1 + 0x8794) = iVar2;
  *(undefined4 *)(param_1 + 0x8798) = 0;
  if ((iVar5 != 0) && (iVar2 != 0)) {
    if (*(char *)(iVar5 + 0x178) == '\0') {
      if (*(char *)(iVar5 + 400) == '\0') {
        return 0;
      }
      iVar4 = 1;
    }
    iVar5 = iVar4 * 0x18 + iVar5;
    if (param_2 == 0x40002b) {
      uVar1 = *(undefined4 *)(iVar5 + 0x184);
    }
    else {
      uVar1 = *(undefined4 *)(iVar5 + 0x188);
    }
    *(undefined4 *)(param_1 + 0x8798) = uVar1;
  }
  return 0;
}

