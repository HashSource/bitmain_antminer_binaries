
undefined4
ossl_statem_client_construct_message
          (int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  
  switch(*(undefined4 *)(param_1 + 0x40)) {
  case 0xc:
    uVar2 = 1;
    *param_3 = 0xedd09;
    *param_4 = 1;
    break;
  case 0xd:
    uVar2 = 1;
    *param_3 = 0xeede5;
    *param_4 = 0xb;
    break;
  case 0xe:
    uVar2 = 1;
    *param_3 = 0xee8c1;
    *param_4 = 0x10;
    break;
  case 0xf:
    uVar2 = 1;
    *param_3 = 0xf3339;
    *param_4 = 0xf;
    break;
  case 0x10:
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
  case 0x11:
    uVar2 = 1;
    *param_3 = 0xee5ed;
    *param_4 = 0x43;
    break;
  case 0x12:
    uVar2 = 1;
    *param_3 = 0xf3a09;
    *param_4 = 0x14;
    break;
  default:
    ossl_statem_fatal(param_1,0x50,0x1ae,0xec,"ssl/statem/statem_clnt.c",0x37f);
    uVar2 = 0;
    break;
  case 0x2b:
    uVar2 = 1;
    *param_3 = 0xf3b61;
    *param_4 = 0x18;
    break;
  case 0x2f:
    *param_3 = 0;
    uVar2 = 1;
    *param_4 = 0xffffffff;
    break;
  case 0x30:
    uVar2 = 1;
    *param_3 = 0xeeeed;
    *param_4 = 5;
  }
  return uVar2;
}

