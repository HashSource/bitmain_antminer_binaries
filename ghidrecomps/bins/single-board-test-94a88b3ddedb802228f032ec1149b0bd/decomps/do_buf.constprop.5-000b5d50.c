
int do_buf_constprop_5(byte *param_1,int param_2,uint param_3,uint param_4,undefined4 param_5,
                      undefined4 param_6)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  byte *str;
  uchar *puVar5;
  int iVar7;
  ulong local_38 [2];
  uchar auStack_30 [12];
  uchar *puVar6;
  
  pbVar3 = param_1 + param_2;
  if (param_1 == pbVar3) {
    iVar7 = 0;
  }
  else {
    iVar7 = 0;
    str = param_1;
    do {
      if (param_1 == str) {
        uVar4 = (param_4 & 1) << 5;
      }
      else {
        uVar4 = 0;
      }
      switch(param_3 & 7) {
      case 0:
        iVar1 = UTF8_getc(str,param_2,local_38);
        if (iVar1 < 0) {
          return -1;
        }
        str = str + iVar1;
        break;
      case 1:
        local_38[0] = (ulong)*str;
        str = str + 1;
        break;
      case 2:
        local_38[0] = (ulong)CONCAT11(*str,str[1]);
        str = str + 2;
        break;
      default:
        goto LAB_000b5df8;
      case 4:
        local_38[0] = (uint)str[1] << 0x10 | (uint)*str << 0x18 | (uint)str[3] | (uint)str[2] << 8;
        str = str + 4;
      }
      if (pbVar3 == str) {
        if ((param_4 & 1) != 0) {
          uVar4 = 0x40;
        }
        if ((param_3 & 8) == 0) goto LAB_000b5e20;
LAB_000b5dc0:
        iVar1 = UTF8_putc(auStack_30,6,local_38[0]);
        if (0 < iVar1) {
          puVar6 = auStack_30;
          do {
            puVar5 = puVar6 + 1;
            iVar2 = do_esc_char_constprop_6(*puVar6,uVar4 | param_4 & 0xff,param_5,param_6);
            iVar7 = iVar7 + iVar2;
            if (iVar2 < 0) {
              return -1;
            }
            puVar6 = puVar5;
          } while (puVar5 != auStack_30 + iVar1);
        }
      }
      else {
        if ((param_3 & 8) != 0) goto LAB_000b5dc0;
LAB_000b5e20:
        iVar1 = do_esc_char_constprop_6(local_38[0],uVar4 | param_4 & 0xff,param_5,param_6);
        if (iVar1 < 0) {
LAB_000b5df8:
          return -1;
        }
        iVar7 = iVar7 + iVar1;
      }
    } while (pbVar3 != str);
  }
  return iVar7;
}

