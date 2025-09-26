
long file_eof(int *param_1)

{
  int iVar1;
  long lVar2;
  
  if (*param_1 == 2) {
    return param_1[4];
  }
  if ((param_1[4] != 0) && (iVar1 = (**(code **)(param_1[4] + 8))(param_1[5]), iVar1 == 0)) {
    return 0;
  }
  lVar2 = BIO_ctrl((BIO *)param_1[3],2,0,(void *)0x0);
  return lVar2;
}

