
void * GENERAL_NAME_get0_value(GENERAL_NAME *a,int *ptype)

{
  if (ptype != (int *)0x0) {
    *ptype = a->type;
  }
  switch(a->type) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
    return (a->d).ptr;
  default:
    return (void *)0x0;
  }
}

