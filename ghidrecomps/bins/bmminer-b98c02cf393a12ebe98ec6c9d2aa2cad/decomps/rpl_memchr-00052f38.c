
uint * rpl_memchr(uint *param_1,char param_2,uint *param_3)

{
  char cVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = param_3;
  if (param_3 != (uint *)0x0) {
    if (((uint)param_1 & 3) == 0) {
LAB_00052f6a:
      uVar4 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
      if ((uint *)0x3 < param_3) {
        uVar3 = *param_1 ^ uVar4;
        for (uVar3 = uVar3 + 0xfefefeff & ~uVar3; (uVar3 & 0x80808080) == 0;
            uVar3 = uVar3 + 0xfefefeff & ~uVar3) {
          param_1 = param_1 + 1;
          param_3 = param_3 + -1;
          if (param_3 < (uint *)0x4) {
            if (param_3 == (uint *)0x0) {
              return (uint *)0x0;
            }
            break;
          }
          uVar3 = *param_1 ^ uVar4;
        }
      }
      puVar2 = param_1;
      if (*(char *)param_1 != param_2) {
        param_3 = (uint *)((int)param_1 + (int)param_3);
        do {
          param_1 = (uint *)((int)param_1 + 1);
          if (param_1 == param_3) {
            return (uint *)0x0;
          }
          puVar2 = param_1;
        } while (*(char *)param_1 != param_2);
      }
    }
    else {
      puVar2 = param_1;
      if (*(char *)param_1 != param_2) {
        param_1 = (uint *)((int)param_1 + 1);
        do {
          param_3 = (uint *)((int)param_3 + -1);
          if (param_3 == (uint *)0x0) {
            return (uint *)0x0;
          }
          if (((uint)param_1 & 3) == 0) goto LAB_00052f6a;
          cVar1 = *(char *)param_1;
          puVar2 = param_1;
          param_1 = (uint *)((int)param_1 + 1);
        } while (cVar1 != param_2);
      }
    }
  }
  return puVar2;
}

