
/* WARNING: Switch with 1 destination removed at 0x000c8950 : 9 cases all go to same destination */

void * GENERAL_NAME_get0_value(GENERAL_NAME *a,int *ptype)

{
  if (ptype != (int *)0x0) {
    *ptype = a->type;
  }
  if (8 < (uint)a->type) {
    return (void *)0x0;
  }
  return (a->d).ptr;
}

