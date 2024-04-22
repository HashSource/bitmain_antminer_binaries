
void asn1_item_clear(code **param_1,undefined *param_2)

{
  uint *puVar1;
  code *pcVar2;
  
  do {
    switch(*param_2) {
    case 0:
      puVar1 = *(uint **)(param_2 + 8);
      if (puVar1 == (uint *)0x0) {
        pcVar2 = *(code **)(param_2 + 0x10);
        if (pcVar2 != (code *)0x0) goto LAB_000b9120;
        pcVar2 = (code *)0x0;
        if (*(int *)(param_2 + 4) == 1) {
          *param_1 = *(code **)(param_2 + 0x14);
          return;
        }
        goto LAB_000b9102;
      }
      if ((*puVar1 & 0x306) != 0) goto switchD_000b90ec_caseD_1;
      param_2 = (undefined *)puVar1[4];
      break;
    case 4:
      if ((*(int *)(param_2 + 0x10) != 0) &&
         (pcVar2 = *(code **)(*(int *)(param_2 + 0x10) + 0xc), pcVar2 != (code *)0x0))
      goto LAB_000b9126;
    case 1:
    case 2:
    case 3:
    case 6:
switchD_000b90ec_caseD_1:
      pcVar2 = (code *)0x0;
LAB_000b9102:
      *param_1 = pcVar2;
      return;
    case 5:
      pcVar2 = *(code **)(param_2 + 0x10);
      if (pcVar2 != (code *)0x0) {
LAB_000b9120:
        pcVar2 = *(code **)(pcVar2 + 0x10);
        if (pcVar2 != (code *)0x0) {
LAB_000b9126:
          (*pcVar2)();
          return;
        }
      }
      goto LAB_000b9102;
    default:
      return;
    }
  } while( true );
}

