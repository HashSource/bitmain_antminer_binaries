
uint * rpl_memchr(uint *param_1,char param_2,uint *param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = param_3;
  if (param_3 != (uint *)0x0) {
    if (((uint)param_1 & 3) == 0) {
LAB_00052f6a:
      uVar3 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
      if ((uint *)0x3 < param_3) {
        uVar2 = *param_1 ^ uVar3;
        for (uVar2 = uVar2 + 0xfefefeff & ~uVar2; (uVar2 & 0x80808080) == 0;
            uVar2 = uVar2 + 0xfefefeff & ~uVar2) {
          param_1 = param_1 + 1;
          param_3 = param_3 + -1;
          if (param_3 < (uint *)0x4) {
            if (param_3 == (uint *)0x0) {
              return (uint *)0x0;
            }
            break;
          }
          uVar2 = *param_1 ^ uVar3;
        }
      }
      puVar1 = param_1;
      if ((char)*param_1 != param_2) {
        param_3 = (uint *)((int)param_1 + (int)param_3);
        do {
          param_1 = (uint *)((int)param_1 + 1);
          if (param_1 == param_3) {
            return (uint *)0x0;
          }
          puVar1 = param_1;
        } while (*(char *)param_1 != param_2);
      }
    }
    else {
      puVar1 = param_1;
      if ((char)*param_1 != param_2) {
        param_1 = (uint *)((int)param_1 + 1);
        do {
          param_3 = (uint *)((int)param_3 + -1);
          if (param_3 == (uint *)0x0) {
            return (uint *)0x0;
          }
          if (((uint)param_1 & 3) == 0) goto LAB_00052f6a;
          uVar3 = *param_1;
          puVar1 = param_1;
          param_1 = (uint *)((int)param_1 + 1);
        } while ((char)uVar3 != param_2);
      }
    }
  }
  return puVar1;
}

