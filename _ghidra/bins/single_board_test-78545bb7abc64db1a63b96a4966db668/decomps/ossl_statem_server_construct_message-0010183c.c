
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
    *param_3 = 0x101a31;
    *param_4 = 3;
    break;
  case 0x16:
    uVar2 = 1;
    *param_3 = 0xff79d;
    *param_4 = 2;
    break;
  case 0x17:
    uVar2 = 1;
    *param_3 = 0x100365;
    *param_4 = 0xb;
    break;
  case 0x18:
    uVar2 = 1;
    *param_3 = 0xffa95;
    *param_4 = 0xc;
    break;
  case 0x19:
    uVar2 = 1;
    *param_3 = 0x1001a5;
    *param_4 = 0xd;
    break;
  case 0x1a:
    uVar2 = 1;
    *param_3 = 0x100b99;
    *param_4 = 0xe;
    break;
  case 0x21:
    uVar2 = 1;
    *param_3 = 0x100401;
    *param_4 = 4;
    break;
  case 0x22:
    uVar2 = 1;
    *param_3 = 0x103b59;
    *param_4 = 0x16;
    break;
  case 0x23:
    if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0) {
      pcVar1 = (code *)0xfc20d;
    }
    else {
      pcVar1 = (code *)0xfd975;
    }
    *param_3 = pcVar1;
    uVar2 = 1;
    *param_4 = 0x101;
    break;
  case 0x24:
    uVar2 = 1;
    *param_3 = 0xfd5e1;
    *param_4 = 0x14;
    break;
  case 0x25:
    uVar2 = 1;
    *param_3 = 0xff781;
    *param_4 = 8;
    break;
  case 0x28:
    uVar2 = 1;
    *param_3 = 0xfcf11;
    *param_4 = 0xf;
    break;
  case 0x2a:
    uVar2 = 1;
    *param_3 = 0xfd739;
    *param_4 = 0x18;
    break;
  case 0x2e:
    *param_3 = 0;
    uVar2 = 1;
    *param_4 = 0xffffffff;
  }
  return uVar2;
}

