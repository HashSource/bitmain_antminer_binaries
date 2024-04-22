
char * UI_get0_result(UI *ui,int i)

{
  int iVar1;
  int *piVar2;
  
  if (i < 0) {
    ERR_put_error(0x28,0x6b,0x67,DAT_000d4b30,0x1ba);
    piVar2 = (int *)0x0;
  }
  else {
    iVar1 = sk_num(*(_STACK **)(ui + 4));
    if (i < iVar1) {
      piVar2 = (int *)sk_value(*(_STACK **)(ui + 4),i);
      if (piVar2 != (int *)0x0) {
        if (*piVar2 - 1U < 2) {
          piVar2 = (int *)piVar2[3];
        }
        else {
          piVar2 = (int *)0x0;
        }
      }
    }
    else {
      ERR_put_error(0x28,0x6b,0x66,DAT_000d4b30,0x1be);
      piVar2 = (int *)0x0;
    }
  }
  return (char *)piVar2;
}

