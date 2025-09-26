
void GENERAL_NAME_set0_value(GENERAL_NAME *a,int type,void *value)

{
  switch(type) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
    (a->d).ptr = (char *)value;
  }
  a->type = type;
  return;
}

