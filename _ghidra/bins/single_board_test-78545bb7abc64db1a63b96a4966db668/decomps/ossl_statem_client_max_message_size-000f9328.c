
int ossl_statem_client_max_message_size(int *param_1)

{
  int iVar1;
  int iVar2;
  
  switch(param_1[0x10]) {
  case 2:
    return 0x102;
  case 3:
  case 0x26:
    return 20000;
  case 4:
  case 7:
    return param_1[0x13f];
  case 5:
  case 0x27:
    return 0x4000;
  case 6:
    return 0x19000;
  default:
    return 0;
  case 9:
    break;
  case 10:
    if (*param_1 == 0x100) {
      iVar1 = 3;
    }
    else {
      iVar1 = 1;
    }
    return iVar1;
  case 0xb:
    return 0x40;
  case 0x2d:
    return 1;
  }
  if (-1 < *(int *)(((int *)param_1[1])[0x19] + 0x30) << 0x1c) {
    iVar2 = *(int *)param_1[1];
    iVar1 = 0x10005;
    if (iVar2 != 0x10000 && 0x303 < iVar2) {
      iVar1 = 0x2010a;
    }
    return iVar1;
  }
  return 0x10005;
}

