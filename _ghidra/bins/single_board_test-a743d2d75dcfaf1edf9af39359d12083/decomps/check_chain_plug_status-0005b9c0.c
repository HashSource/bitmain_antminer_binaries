
/* WARNING: Unknown calling convention */

_Bool check_chain_plug_status(void)

{
  undefined1 uVar1;
  _Bool _Var2;
  bitmain_sys_capability_t info;
  _Bool ret;
  
  get_system_capability(&info);
  if (g_user_chain == 0xff) {
    if ((Local_Config_Information->Test_Info).Bypass_Scan_Code_Gun == false) {
      if (info.board_num == 1) {
        uVar1 = gHashBoard_plug_in;
        if (info.board[0].board_id == 3) {
          gHashBoard_plug_in = false;
          uVar1 = gHashBoard_plug_in;
        }
      }
      else if (info.board_num == 0) {
        gHashBoard_plug_in = false;
        uVar1 = gHashBoard_plug_in;
      }
      else {
        gHashBoard_plug_in = true;
        uVar1 = gHashBoard_plug_in;
      }
    }
    else if (info.board_num == 0) {
      gHashBoard_plug_in = false;
      uVar1 = gHashBoard_plug_in;
    }
    else {
      _Var2 = check_specific_chain(0);
      if (((_Var2) || (_Var2 = check_specific_chain(1), _Var2)) ||
         (_Var2 = check_specific_chain(2), _Var2)) {
        gHashBoard_plug_in = true;
        uVar1 = gHashBoard_plug_in;
      }
      else {
        gHashBoard_plug_in = false;
        uVar1 = gHashBoard_plug_in;
      }
    }
  }
  else {
    uVar1 = check_specific_chain(g_user_chain);
  }
  return (_Bool)uVar1;
}

