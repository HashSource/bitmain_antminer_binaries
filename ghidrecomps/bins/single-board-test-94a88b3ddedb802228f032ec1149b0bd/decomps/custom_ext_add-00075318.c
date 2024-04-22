
undefined4
custom_ext_add(int param_1,int param_2,undefined4 *param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined *__dest;
  int *piVar7;
  code *pcVar8;
  void *local_30;
  uint local_2c [2];
  
  piVar7 = (int *)(*(int *)(param_1 + 0x98) + 0x164);
  if (param_2 == 0) {
    piVar7 = (int *)(*(int *)(param_1 + 0x98) + 0x15c);
  }
  uVar3 = piVar7[1];
  __dest = (undefined *)*param_3;
  if (uVar3 != 0) {
    uVar4 = 0;
    do {
      iVar6 = *piVar7;
      local_30 = (void *)0x0;
      local_2c[0] = 0;
      iVar5 = iVar6 + uVar4 * 0x18;
      if (param_2 == 0) {
        pcVar8 = *(code **)(iVar5 + 4);
        if (pcVar8 == (code *)0x0) {
LAB_00075374:
          if ((param_4 - (int)__dest < 4) || ((param_4 - (int)__dest) - 4U < local_2c[0])) {
            return 0;
          }
          *__dest = (char)((ushort)*(undefined2 *)(iVar6 + uVar4 * 0x18) >> 8);
          __dest[1] = (char)*(undefined2 *)(iVar6 + uVar4 * 0x18);
          __dest[2] = (char)(local_2c[0] >> 8);
          __dest[3] = (char)local_2c[0];
          __dest = __dest + 4;
          if (local_2c[0] != 0) {
            memcpy(__dest,local_30,local_2c[0]);
            __dest = __dest + local_2c[0];
          }
          uVar2 = *(ushort *)(iVar5 + 2);
          if ((int)((uint)uVar2 << 0x1e) < 0) {
            OpenSSLDie(DAT_00075438,0xa8,DAT_0007543c);
            uVar2 = *(ushort *)(iVar5 + 2);
          }
          *(ushort *)(iVar5 + 2) = uVar2 | 2;
          if (*(code **)(iVar5 + 8) != (code *)0x0) {
            (**(code **)(iVar5 + 8))
                      (param_1,*(undefined2 *)(iVar6 + uVar4 * 0x18),local_30,
                       *(undefined4 *)(iVar5 + 0xc));
          }
        }
        else {
LAB_00075358:
          iVar1 = (*pcVar8)(param_1,*(undefined2 *)(iVar6 + uVar4 * 0x18),&local_30,local_2c,param_5
                            ,*(undefined4 *)(iVar5 + 0xc));
          if (iVar1 < 0) {
            return 0;
          }
          if (iVar1 != 0) goto LAB_00075374;
        }
        uVar3 = piVar7[1];
      }
      else if (((int)((uint)*(ushort *)(iVar5 + 2) << 0x1f) < 0) &&
              (pcVar8 = *(code **)(iVar5 + 4), pcVar8 != (code *)0x0)) goto LAB_00075358;
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  *param_3 = __dest;
  return 1;
}

