
undefined4 get_domain_num(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = is_S9();
  if (iVar1 == 0) {
    iVar1 = is_S9i();
    if (iVar1 == 0) {
      iVar1 = is_S9_plus();
      if (iVar1 == 0) {
        iVar1 = is_T9();
        if (iVar1 == 0) {
          iVar1 = is_T9_plus();
          if (iVar1 == 0) {
            iVar1 = is_S9_Hydro();
            if (iVar1 == 0) {
              iVar1 = is_R4();
              if (iVar1 == 0) {
                uVar2 = 0x15;
              }
              else {
                uVar2 = 0x15;
              }
            }
            else {
              uVar2 = 0x12;
            }
          }
          else {
            uVar2 = 0x12;
          }
        }
        else {
          uVar2 = 0x15;
        }
      }
      else {
        uVar2 = 0x1c;
      }
    }
    else {
      uVar2 = 0x15;
    }
  }
  else {
    uVar2 = 0x15;
  }
  return uVar2;
}

