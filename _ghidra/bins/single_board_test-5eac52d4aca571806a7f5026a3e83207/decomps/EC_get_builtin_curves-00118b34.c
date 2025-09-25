
size_t EC_get_builtin_curves(EC_builtin_curve *r,size_t nitems)

{
  char *pcVar1;
  char **ppcVar2;
  int *piVar3;
  int *piVar4;
  
  if (nitems != 0 && r != (EC_builtin_curve *)0x0) {
    if (0x51 < nitems) {
      nitems = 0x52;
    }
    ppcVar2 = &r->comment;
    piVar3 = &curve_list;
    do {
      piVar4 = piVar3 + 4;
      pcVar1 = (char *)piVar3[3];
      ((EC_builtin_curve *)(ppcVar2 + -1))->nid = *piVar3;
      *ppcVar2 = pcVar1;
      ppcVar2 = ppcVar2 + 2;
      piVar3 = piVar4;
    } while (piVar4 != &curve_list + nitems * 4);
    return 0x52;
  }
  return 0x52;
}

