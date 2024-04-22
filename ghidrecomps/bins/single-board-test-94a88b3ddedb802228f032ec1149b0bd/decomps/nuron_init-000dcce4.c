
undefined4 nuron_init(void)

{
  char **ppcVar1;
  char *pcVar2;
  undefined4 uVar3;
  DSO *dso;
  DSO_FUNC_TYPE pDVar4;
  
  ppcVar1 = DAT_000dcd6c;
  if (DAT_000dcd6c[2] == (char *)0x0) {
    pcVar2 = *DAT_000dcd6c;
    if (*DAT_000dcd6c == (char *)0x0) {
      pcVar2 = DAT_000dcd74;
    }
    dso = DSO_load((DSO *)0x0,pcVar2,(DSO_METHOD *)0x0,2);
    ppcVar1[2] = (char *)dso;
    if (dso == (DSO *)0x0) {
      pcVar2 = ppcVar1[1];
      if (pcVar2 == (char *)0x0) {
        pcVar2 = (char *)ERR_get_next_error_library();
        ppcVar1[1] = pcVar2;
      }
      ERR_put_error((int)pcVar2,0x66,0x68,DAT_000dcd70,0x8b);
      uVar3 = 0;
    }
    else {
      pDVar4 = DSO_bind_func(dso,DAT_000dcd78);
      ppcVar1[3] = (char *)pDVar4;
      if (pDVar4 == (DSO_FUNC_TYPE)0x0) {
        pcVar2 = ppcVar1[1];
        if (pcVar2 == (char *)0x0) {
          pcVar2 = (char *)ERR_get_next_error_library();
          ppcVar1[1] = pcVar2;
        }
        ERR_put_error((int)pcVar2,0x66,0x67,DAT_000dcd70,0x91);
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
    }
  }
  else {
    pcVar2 = DAT_000dcd6c[1];
    if (pcVar2 == (char *)0x0) {
      pcVar2 = (char *)ERR_get_next_error_library();
      ppcVar1[1] = pcVar2;
    }
    ERR_put_error((int)pcVar2,0x66,100,DAT_000dcd70,0x84);
    uVar3 = 0;
  }
  return uVar3;
}

