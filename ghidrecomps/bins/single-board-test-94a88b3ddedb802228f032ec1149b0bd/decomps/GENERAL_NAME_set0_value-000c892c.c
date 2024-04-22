
/* WARNING: Switch with 1 destination removed at 0x000c8930 : 9 cases all go to same destination */

void GENERAL_NAME_set0_value(GENERAL_NAME *a,int type,void *value)

{
  if ((uint)type < 9) {
    (a->d).ptr = (char *)value;
  }
  a->type = type;
  return;
}

