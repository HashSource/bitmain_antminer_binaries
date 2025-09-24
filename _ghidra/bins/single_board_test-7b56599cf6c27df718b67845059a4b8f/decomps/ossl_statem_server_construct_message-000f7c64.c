
undefined4
ossl_statem_server_construct_message
          (int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  
  switch(*(undefined4 *)(param_1 + 0x40)) {
  case 0x13:
    uVar2 = 1;
    *param_3 = 0;
    *param_4 = 0;
    break;
  default:
    ossl_statem_fatal(param_1,0x50,0x1af,0xec,"ssl/statem/statem_srvr.c",0x404);
    uVar2 = 0;
    break;
  case 0x15:
    uVar2 = 1;
    *param_3 = 0xf7e59;
    *param_4 = 3;
    break;
  case 0x16:
    uVar2 = 1;
    *param_3 = 0xf5bc5;
    *param_4 = 2;
    break;
  case 0x17:
    uVar2 = 1;
    *param_3 = 0xf678d;
    *param_4 = 0xb;
    break;
  case 0x18:
    uVar2 = 1;
    *param_3 = 0xf5ebd;
    *param_4 = 0xc;
    break;
  case 0x19:
    uVar2 = 1;
    *param_3 = 0xf65cd;
    *param_4 = 0xd;
    break;
  case 0x1a:
    uVar2 = 1;
    *param_3 = 0xf6fc1;
    *param_4 = 0xe;
    break;
  case 0x21:
    uVar2 = 1;
    *param_3 = 0xf6829;
    *param_4 = 4;
    break;
  case 0x22:
    uVar2 = 1;
    *param_3 = 0xf9f81;
    *param_4 = 0x16;
    break;
  case 0x23:
    if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0) {
      pcVar1 = (code *)0xf2635;
    }
    else {
      pcVar1 = (code *)0xf3d9d;
    }
    *param_3 = pcVar1;
    uVar2 = 1;
    *param_4 = 0x101;
    break;
  case 0x24:
    uVar2 = 1;
    *param_3 = 0xf3a09;
    *param_4 = 0x14;
    break;
  case 0x25:
    uVar2 = 1;
    *param_3 = 0xf5ba9;
    *param_4 = 8;
    break;
  case 0x28:
    uVar2 = 1;
    *param_3 = 0xf3339;
    *param_4 = 0xf;
    break;
  case 0x2a:
    uVar2 = 1;
    *param_3 = 0xf3b61;
    *param_4 = 0x18;
    break;
  case 0x2e:
    *param_3 = 0;
    uVar2 = 1;
    *param_4 = 0xffffffff;
  }
  return uVar2;
}

