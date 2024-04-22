
int BN_get_params(int which)

{
  int iVar1;
  
  if (which == 0) {
    return *DAT_0009cf94;
  }
  if (which == 1) {
    return DAT_0009cf94[1];
  }
  if (which == 2) {
    return DAT_0009cf94[2];
  }
  if (which == 3) {
    iVar1 = DAT_0009cf94[3];
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

