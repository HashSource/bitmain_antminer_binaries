
undefined4 ssl3_send_server_hello(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  size_t __n;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 local_1c;
  
  local_1c = 0;
  if (param_1[0xd] == 0x2130) {
    iVar9 = *(int *)(param_1[0xf] + 4);
    iVar5 = *(int *)(*(int *)(param_1[2] + 100) + 0x3c);
    *(char *)(iVar9 + iVar5) = (char)((uint)*param_1 >> 8);
    iVar5 = iVar5 + iVar9;
    *(char *)(iVar5 + 1) = (char)*param_1;
    iVar3 = param_1[0x16];
    uVar8 = *(undefined4 *)(iVar3 + 0xa4);
    uVar6 = *(undefined4 *)(iVar3 + 0xa8);
    uVar1 = *(undefined4 *)(iVar3 + 0xac);
    *(undefined4 *)(iVar5 + 2) = *(undefined4 *)(iVar3 + 0xa0);
    *(undefined4 *)(iVar5 + 6) = uVar8;
    *(undefined4 *)(iVar5 + 10) = uVar6;
    *(undefined4 *)(iVar5 + 0xe) = uVar1;
    uVar8 = *(undefined4 *)(iVar3 + 0xb4);
    uVar6 = *(undefined4 *)(iVar3 + 0xb8);
    uVar1 = *(undefined4 *)(iVar3 + 0xbc);
    *(undefined4 *)(iVar5 + 0x12) = *(undefined4 *)(iVar3 + 0xb0);
    *(undefined4 *)(iVar5 + 0x16) = uVar8;
    *(undefined4 *)(iVar5 + 0x1a) = uVar6;
    *(undefined4 *)(iVar5 + 0x1e) = uVar1;
    if ((*(int *)(param_1[0x39] + 0x20) << 0x1e < 0) || (param_1[0x1b] != 0)) {
      __n = *(size_t *)(param_1[0x30] + 0x44);
      if ((int)__n < 0x21) goto LAB_00085f30;
      iVar3 = 0x44;
      iVar5 = 0x5fc;
    }
    else {
      *(undefined4 *)(param_1[0x30] + 0x44) = 0;
      __n = 0;
LAB_00085f30:
      *(char *)(iVar5 + 0x22) = (char)__n;
      iVar7 = (int)(void *)(iVar5 + 0x23) + __n;
      memcpy((void *)(iVar5 + 0x23),(void *)(param_1[0x30] + 0x48),__n);
      iVar3 = ssl3_put_cipher_by_char(*(undefined4 *)(param_1[0x16] + 0x344),iVar7);
      pbVar4 = *(byte **)(param_1[0x16] + 0x38c);
      if (pbVar4 != (byte *)0x0) {
        pbVar4 = (byte *)(uint)*pbVar4;
      }
      *(char *)(iVar7 + iVar3) = (char)pbVar4;
      iVar2 = ssl_prepare_serverhello_tlsext(param_1);
      if (iVar2 < 1) {
        iVar5 = 0x613;
        iVar3 = 0x113;
      }
      else {
        iVar3 = ssl_add_serverhello_tlsext(param_1,iVar7 + iVar3 + 1,iVar9 + 0x4000,&local_1c);
        if (iVar3 != 0) {
          (**(code **)(*(int *)(param_1[2] + 100) + 0x40))(param_1,2,iVar3 - iVar5);
          param_1[0xd] = 0x2131;
          goto LAB_00085eba;
        }
        ssl3_send_alert(param_1,2,local_1c);
        iVar5 = 0x61b;
        iVar3 = 0x44;
      }
    }
    ERR_put_error(0x14,0xf2,iVar3,DAT_00085fe4,iVar5);
    uVar1 = 0xffffffff;
    param_1[0xd] = 5;
  }
  else {
LAB_00085eba:
    uVar1 = (**(code **)(*(int *)(param_1[2] + 100) + 0x44))(param_1);
  }
  return uVar1;
}

