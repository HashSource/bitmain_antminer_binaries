
undefined4
ssl_parse_serverhello_renegotiate_ext(int param_1,byte *param_2,int param_3,undefined4 *param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = (uint)*(byte *)(*(int *)(param_1 + 0x58) + 0x3d4);
  uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x58) + 0x415);
  uVar6 = uVar5 + uVar3;
  if (uVar6 != 0) {
    if (uVar5 == 0) {
      OpenSSLDie(DAT_00083b84,0xf0,DAT_00083b88);
      if (*(char *)(*(int *)(param_1 + 0x58) + 0x415) == '\0') goto LAB_00083b64;
    }
    else if (uVar3 == 0) {
LAB_00083b64:
      OpenSSLDie(DAT_00083b84,0xf1,DAT_00083b8c);
    }
  }
  if (param_3 < 1) {
    iVar2 = 0xf6;
  }
  else {
    if (*param_2 + 1 == param_3) {
      if (*param_2 != uVar6) {
        iVar2 = 0x108;
LAB_00083b16:
        ERR_put_error(0x14,0x12d,0x151,DAT_00083b84,iVar2);
        *param_4 = 0x28;
        return 0;
      }
      iVar4 = *(int *)(param_1 + 0x58);
      bVar1 = *(byte *)(iVar4 + 0x3d4);
      iVar2 = memcmp(param_2 + 1,(void *)(iVar4 + 0x394),(uint)bVar1);
      if (iVar2 != 0) {
        iVar2 = 0x110;
        goto LAB_00083b16;
      }
      iVar2 = memcmp(param_2 + 1 + bVar1,(void *)(iVar4 + 0x3d5),(uint)*(byte *)(iVar4 + 0x415));
      if (iVar2 == 0) {
        *(undefined4 *)(iVar4 + 0x418) = 1;
        return 1;
      }
      iVar2 = 0x119;
      iVar4 = 0x151;
      goto LAB_00083b40;
    }
    iVar2 = 0x100;
  }
  iVar4 = 0x150;
LAB_00083b40:
  ERR_put_error(0x14,0x12d,iVar4,DAT_00083b84,iVar2);
  *param_4 = 0x2f;
  return 0;
}

