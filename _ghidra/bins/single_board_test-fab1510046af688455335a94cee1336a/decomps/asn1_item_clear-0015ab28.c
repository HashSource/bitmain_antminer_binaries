
void asn1_item_clear(int *param_1,undefined1 *param_2)

{
  uint *puVar1;
  code *pcVar2;
  
  do {
    switch(*param_2) {
    case 0:
      puVar1 = *(uint **)(param_2 + 8);
      if (puVar1 == (uint *)0x0) {
        pcVar2 = *(code **)(param_2 + 0x10);
        if (pcVar2 != (code *)0x0) goto LAB_0015ab64;
        pcVar2 = (code *)0x0;
        if (*(int *)(param_2 + 4) == 1) {
          *param_1 = *(int *)(param_2 + 0x14);
          return;
        }
        goto LAB_0015ab46;
      }
      if ((*puVar1 & 0x306) != 0) goto switchD_0015ab30_caseD_1;
      param_2 = (undefined1 *)puVar1[4];
      break;
    case 4:
      if ((*(int *)(param_2 + 0x10) != 0) &&
         (pcVar2 = *(code **)(*(int *)(param_2 + 0x10) + 0xc), pcVar2 != (code *)0x0))
      goto LAB_0015ab6a;
    case 1:
    case 2:
    case 3:
    case 6:
switchD_0015ab30_caseD_1:
      pcVar2 = (code *)0x0;
LAB_0015ab46:
      *param_1 = (int)pcVar2;
switchD_0015ab30_default:
      return;
    case 5:
      pcVar2 = *(code **)(param_2 + 0x10);
      if (pcVar2 != (code *)0x0) {
LAB_0015ab64:
        pcVar2 = *(code **)(pcVar2 + 0x10);
        if (pcVar2 != (code *)0x0) {
LAB_0015ab6a:
          (*pcVar2)();
          return;
        }
      }
      goto LAB_0015ab46;
    default:
      goto switchD_0015ab30_default;
    }
  } while( true );
}

